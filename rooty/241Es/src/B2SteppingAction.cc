//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// copy of \file B1SteppingAction.cc
/// \brief Implementation of the B2SteppingAction class

#include "B2SteppingAction.hh"
#include "B2EventAction.hh"
#include "B2bDetectorConstruction.hh"

#include "G4Step.hh"    //  from track/src
#include "G4SteppingVerbose.hh"
#include "G4SteppingManager.hh"
#include "G4ParticleChange.hh"
#include "G4VParticleChange.hh"
#include "G4StepStatus.hh"    // Include from 'tracking'
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4UnitsTable.hh"
class G4VProcess;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2SteppingAction::B2SteppingAction(B2EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2SteppingAction::~B2SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B2SteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fScoringVolume) {
    const B2bDetectorConstruction* detectorConstruction
      = static_cast<const B2bDetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();
  }

  // get volume of the current step
  G4LogicalVolume* log_volume
    = step->GetPreStepPoint()->GetPhysicalVolume()->GetLogicalVolume();
  //  alternative access to logical volume
  //    = step->GetPreStepPoint()->GetTouchableHandle()
  //      ->GetVolume()->GetLogicalVolume();

  // collect energy deposited in this step
  G4double edepStep = step->GetTotalEnergyDeposit();

  //
  // two possibilities here: we either have zero energy, or we're leaving the target;
  // in both cases, we want to know what's happening
  //
  G4Track* track = step->GetTrack();
  G4double particle_mass = step->GetPostStepPoint()->GetMass();
  G4double particle_charge = step->GetPostStepPoint()->GetCharge();
  G4Material* G4MaterialBefore = step->GetPreStepPoint()->GetMaterial();
  G4Material* G4MaterialAfter = step->GetPostStepPoint()->GetMaterial();
  const G4VProcess* G4ProcessAfter = step->GetPostStepPoint()->GetProcessDefinedStep();
  const G4VProcess* G4ProcessBefore = step->GetPreStepPoint()->GetProcessDefinedStep();
 //G4cout<<" Proces name: " <<G4ProcessAfter->GetProcessName()<<G4endl;
  if(G4MaterialBefore->GetName() == "G4_Galactic") return;
  // select antiprotons

  // if (abs(particle_mass - 938.) > 1. && abs(particle_charge -130) > 5) return;
  // if (particle_charge > 0) return;

   //G4cout << "++ B2Stepping action: investigating antiproton" << G4endl;
   //G4cout << "++ Energy deposited : " << edepStep << G4endl;
   //G4cout << "++ Process after    : " << G4ProcessAfter->GetProcessName() << G4endl;
   //G4cout << "++ Particle    : " << track->GetDefinition()->GetParticleName() << G4endl;
   //G4cout << "++ Particle         : " << particle_mass << ", q=" << particle_charge << G4endl;


  //
  G4VPhysicalVolume* ph_volume
    = step->GetPreStepPoint()->GetPhysicalVolume();

  // where are we?
  G4ThreeVector position = step->GetPostStepPoint()->GetPosition();
  G4ThreeVector momentum = step->GetPostStepPoint()->GetMomentum();
  G4ThreeVector p_direction = step->GetPostStepPoint()->GetMomentumDirection();
  G4double time = step->GetPostStepPoint()->GetLocalTime();

  // G4cout << "++ Position : " << position[0] << "," << position[1] << "," << position[2] << G4endl;

  //  need this as a fourvector for the B-field call
  double fourvect[4];
  fourvect[0] = position[0];
  fourvect[1] = position[1];
  fourvect[2] = position[2];
  fourvect[3] = time;
  
  // collect energy deposited in this step
  G4double eResidual = step->GetPostStepPoint()->GetKineticEnergy();

  // G4cout << "++ Energy after step :" << eResidual << G4endl;
  
  // should return B ... need to check that manager and detector field exist...
  // G4double Bfield[6];
  // G4FieldManager *pFieldMgr = log_volume->GetFieldManager();
  // G4bool doesFieldExist = log_volume->GetFieldManager()->DoesFieldExist();
  //   G4Field *pDetField = log_volume->GetFieldManager()->GetDetectorField();
  // log_volume->GetFieldManager()->GetDetectorField()->GetFieldValue(fourvect, Bfield);

  //   G4cout << G4endl
  //   << "++ B2SteppingAction ++++++++++++++++" << G4endl
  //   << " +++++++ going from " <<  G4MaterialBefore->GetName() << " to " << G4MaterialAfter->GetName() << G4endl
  //   << "+++++++++++++++++++++" << G4endl;
  
  // alternatively, we're still in the target, but BOOM!
  auto man = G4GenericAnalysisManager::Instance();
  // const std::vector<const G4Track*>* fSecondaries = step->GetSecondaryInCurrentStep();
  const G4TrackVector* fSecondaries = step->GetSecondary();

  
  ////if (eResidual <= 1.E-6) {
    //   G4cout
    // << G4endl
    // << "------------------------------------------------------------" << G4endl
    // << "antiproton annihilating in target at " << position << " with energy " << eResidual << G4endl
    // << " going from " << G4MaterialBefore->GetName() << " to " << G4MaterialAfter->GetName() << G4endl
    // << "     energy deposit of step to here= " << edepStep << G4endl
    // << " ; m = " << particle_charge*particle_mass << G4endl
    // << "------------------------------------------------------------" << G4endl;

    // can we access the secondaries yet?
    //
    //  higher up, we had declared:
    //   const G4VProcess* G4ProcessAfter = step->GetPostStepPoint()->GetProcessDefinedStep();
    //   const G4VProcess* G4ProcessBefore = step->GetPreStepPoint()->GetProcessDefinedStep();

    // G4cout << G4endl;
    // G4cout << " B2SteppingAction >>PostStepDoIt (process by process): "
    //      << "   Process Name Before = "
    //      << G4ProcessBefore->GetProcessName()
    //      << "   Process Name After = "
    //      << G4ProcessAfter->GetProcessName() << G4endl;

    if ( G4ProcessAfter->GetProcessName() =="hFritiofCaptureAtRest") {
  //  if (( G4ProcessAfter->GetProcessName() =="msc") || (G4ProcessAfter->GetProcessName()=="hFritiofCaptureAtRest")) {
   // if ( G4ProcessAfter->GetProcessName() =="G4ChargeExchangeProcess") {
    //if ( G4ProcessAfter->GetProcessName() =="G4QCaptureAtRest") {
      // G4cout << "Actual annihilation" << G4endl;

      // we are thus after the annihilation has happened, and the secondaries are known
      // and would want to call G4SteppingVerbose::StepInfo(), which fills all the variables needed
      // by calling CopyState(), which is actually defined in G4VSteppingVerbose, and requires
      // access to the G4SteppingManager* fManager->GetfN2ndariesAtRestDoIt();
      // G4cout << " Number of secondaries " << nb2ndaries << G4endl; //(original code)
      // G4cout << "Annihilation position " << position[0] << "," << position[1]<< "," << position[2]<< G4endl;
      fEventAction->UpdateAnnihilation();
      G4int fNFragments = 0;
      G4int felectrons = 0;
      G4int fpion0 = 0;
      G4int fpionp = 0;
      G4int fpionm = 0;
      G4int fkaon0 = 0;
      G4int fkaonp = 0;
      G4int fkaonm = 0;
      G4int fgamma = 0;
      G4int fproton = 0;
      G4int fneutron = 0;
      G4int falpha = 0;
      G4int fdeuteron = 0;
      G4int ftriton = 0;
      G4int fHe3 = 0;
      G4int fother = 0;
      for (size_t lp=0; lp<fSecondaries->size(); lp++) {
  //    nb2ndaries++;i
  
  G4String name = fSecondaries->at(lp)->GetDefinition()->GetParticleName();
  G4String type = fSecondaries->at(lp)->GetDefinition()->GetParticleType();
//  G4cout<<name<<", ";
  G4double Q = fSecondaries->at(lp)->GetDefinition()->GetPDGCharge();
  G4double E = fSecondaries->at(lp)->GetKineticEnergy();
  G4double T = fSecondaries->at(lp)->GetDefinition()->GetPDGLifeTime();
  G4double ID = fSecondaries->at(lp)->GetDefinition()->GetPDGEncoding();
  man->FillNtupleDColumn(1, 0, ID); //particle ID
  if(type == "nucleus" && Q!=0){
    fNFragments++;
    if(name == "alpha")
    {
      falpha++;
    }
    if(name == "He3")
    {
      fHe3++;
    }
    if(name == "deuteron")
    {
      fdeuteron++;
    }
    if(name == "triton")
    {
      ftriton++;
    }
    G4double Z = fSecondaries->at(lp)->GetDefinition()->GetAtomicNumber();
    G4double A = fSecondaries->at(lp)->GetDefinition()->GetAtomicMass();
    G4double N = A-Z;
    
    man->FillNtupleDColumn(1, 1, Z); //Z
    man->FillNtupleDColumn(1, 2, A); //A
    man->FillNtupleDColumn(1, 3, N); // N = A - Z
  }
  else if(name == "e-"){
    felectrons++;
    man->FillNtupleDColumn(1, 1, -1); //Z
    man->FillNtupleDColumn(1, 2, 0); //A
    man->FillNtupleDColumn(1, 3, 0); // N = A - Z
  }
  else if(name == "proton"){
    fproton++;
    man->FillNtupleDColumn(1, 1, 1); //Z
    man->FillNtupleDColumn(1, 2, 1); //A
    man->FillNtupleDColumn(1, 3, 0); // N = A - Z
  }
  else if(name == "neutron"){
    fneutron++;
    man->FillNtupleDColumn(1, 1, 0); //Z
    man->FillNtupleDColumn(1, 2, 1); //A
    man->FillNtupleDColumn(1, 3, 1); // N = A - Z
  }
  else if(type == "meson")
  {
    if(name == "pi0")
    {
      fpion0++;
    }
    else if(name == "pi+")
    {
      fpionp++;
    }
    else if(name == "pi-")
    {
      fpionm++;
    }
    else if(name == "kaon0" || name == "kaon0S" ||name == "kaon0L")
    {
      fkaon0++;
    }
    else if(name == "kaon+")
    {
      fkaonp++;
    }
    else if(name == "kaon-")
    {
      fkaonm++;
    }
    man->FillNtupleDColumn(1, 1, 0); //Z
    man->FillNtupleDColumn(1, 2, 0); //A
    man->FillNtupleDColumn(1, 3, 0); // N = A - Z
  }
  else if (name == "gamma" || name == "opticalphoton")
  {
    fgamma++;
    man->FillNtupleDColumn(1, 1, 0); //Z
    man->FillNtupleDColumn(1, 2, 0); //A
    man->FillNtupleDColumn(1, 3, 0); // N = A - Z
  }
  else
  {
    //G4cout<<name<<G4endl;
    fother++;
    man->FillNtupleDColumn(1, 1, 0); //Z
    man->FillNtupleDColumn(1, 2, 0); //A
    man->FillNtupleDColumn(1, 3, 0); // N = A - Z
  }
 
  man->FillNtupleDColumn(1, 4, E); //E
  man->FillNtupleDColumn(1, 5, Q); //Q
  man->FillNtupleDColumn(1, 6, T); // T
  man->FillNtupleSColumn(1, 7, name); //name
  man->FillNtupleSColumn(1, 8, type); //type
  man->AddNtupleRow(1);
  }
//  G4cout<<G4endl;
      man->FillNtupleIColumn(2, 0, fNFragments);
      man->FillNtupleIColumn(2, 1, felectrons);
      man->FillNtupleIColumn(2, 2, fpion0);
      man->FillNtupleIColumn(2, 3, fpionp);
      man->FillNtupleIColumn(2, 4, fpionm);
      man->FillNtupleIColumn(2, 5, fkaon0);
      man->FillNtupleIColumn(2, 6, fkaonp);
      man->FillNtupleIColumn(2, 7, fkaonm);
      man->FillNtupleIColumn(2, 8, fgamma);
      man->FillNtupleIColumn(2, 9, fproton);
      man->FillNtupleIColumn(2, 10, fneutron);
      man->FillNtupleIColumn(2, 11, falpha);
      man->FillNtupleIColumn(2, 12, fdeuteron);
      man->FillNtupleIColumn(2, 13, ftriton);
      man->FillNtupleIColumn(2, 14, fHe3);
      man->FillNtupleIColumn(2, 15, fother);
      man->AddNtupleRow(2);
          
      // G4cout << " Number of secondaries: " << Fsecondaries->size() << G4endl;
      /*************************************************************/
  
    }

    // G4int GetNumberOfSecondaries() const;
    // return;
  //} // end of residual if statement

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
