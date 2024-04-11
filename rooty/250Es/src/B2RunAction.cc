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
/// \file B2RunAction.cc
/// \brief Implementation of the B2RunAction class

#include "B2RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
//#include "TTree.h"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2RunAction::B2RunAction()
 : G4UserRunAction()
{
  // set printing event number per each 100 events
  G4RunManager::GetRunManager()->SetPrintProgress(1000);
  auto man = G4GenericAnalysisManager::Instance();
  man->SetNtupleMerging(true);

  man->SetFirstNtupleId(1);

  // creating Ntuple to store informations about each fragment
  man->CreateNtuple("fNtuple","secondaries");
  man->CreateNtupleDColumn("ID");
  man->CreateNtupleDColumn("Z");
  man->CreateNtupleDColumn("A");
  man->CreateNtupleDColumn("N");
  man->CreateNtupleDColumn("E");
  man->CreateNtupleDColumn("Q");
  man->CreateNtupleDColumn("T");
  man->CreateNtupleSColumn("name");
  man->CreateNtupleSColumn("type");
  man->FinishNtuple();

  //creating Ntyple to store information about number of secondaries and heavier fragments
  man->CreateNtuple("Counter","Counter");
  man->CreateNtupleIColumn("fragments");
  man->CreateNtupleIColumn("electrons");
  man->CreateNtupleIColumn("pion0");
  man->CreateNtupleIColumn("pion+");
  man->CreateNtupleIColumn("pion-");
  man->CreateNtupleIColumn("kaon0");
  man->CreateNtupleIColumn("kaon+");
  man->CreateNtupleIColumn("kaon-");
  man->CreateNtupleIColumn("gammas");
  man->CreateNtupleIColumn("proton");
  man->CreateNtupleIColumn("neutron");
  man->CreateNtupleIColumn("alpha");
  man->CreateNtupleIColumn("deuteron");
  man->CreateNtupleIColumn("triton");
  man->CreateNtupleIColumn("He3");
  man->CreateNtupleIColumn("other");
  man->FinishNtuple();


  // fOutput = new TFile("output.root","RECREATE");
  // fNtuple = new TNtuple("fNtuple","info","Z:A:N:E:E/q:T");

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2RunAction::~B2RunAction()
{
  delete G4GenericAnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B2RunAction::BeginOfRunAction(const G4Run*)
{
  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  auto man = G4GenericAnalysisManager::Instance();

  G4String fileName = "B2.root";
  man->OpenFile(fileName);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B2RunAction::EndOfRunAction(const G4Run* )
{
  //G4cout << "Writing TNtuple (" << fNtuple->GetEntries() << ") into main" << G4endl;
  // for(int i=0; i<fNtuple->GetEntries(); i++){
  //
  // }
  auto man = G4GenericAnalysisManager::Instance();
  man->Write();
  man->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......