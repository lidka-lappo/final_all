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
/// \file B2bDetectorConstruction.cc
/// \brief Implementation of the B2bDetectorConstruction class
 
#include "B2bDetectorConstruction.hh"
#include "B2bDetectorMessenger.hh"
#include "B2TrackerSD.hh"

// BBBBBBBBBBBBBBBBBBb
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "G4Mag_UsualEqRhs.hh"
// BBBBBBBBBBBBBBBBBBb

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SDManager.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4GlobalMagFieldMessenger.hh"
#include "G4AutoDelete.hh"

#include "G4GeometryTolerance.hh"
#include "G4GeometryManager.hh"

#include "G4UserLimits.hh"

// BBBBBBBBBBBBBBBBBBBBBB
#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4GenericMessenger.hh"
// BBBBBBBBBBBBBBBBBBBBBB

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// BBBBBBBBBBBBBBBBBBBBBB
//*G4ThreadLocal G4GlobalMagFieldMessenger* B2bDetectorConstruction::fMagFieldMessenger = 0;
// G4ThreadLocal B2MagneticField* B2bDetectorConstruction::fMagneticField = 0;
// G4ThreadLocal G4FieldManager* B2bDetectorConstruction::fFieldMgr = 0;
// BBBBBBBBBBBBBBBBBBBBBB
 

B2bDetectorConstruction::B2bDetectorConstruction()
:G4VUserDetectorConstruction(),
 fWorldLV(NULL), 
 fLogicTarget(NULL), 
 // fLogicDegrader(NULL),
 // fLogicDetector(NULL), 
 // fLogicChamber(NULL), fLogicBeamTube(NULL),
// BBBBBBBBBBBBBBBBBBBBBB
// fMagneticLogical(nullptr),
// BBBBBBBBBBBBBBBBBBBBBB
 fTargetMaterial(NULL), fWorldMaterial(NULL),// fChamberMaterial(NULL), 
 fVacuumMaterial(NULL), //fDetectorMaterial(NULL),
 fStepLimit(NULL), fMessenger(NULL),
 fCheckOverlaps(true),fScoringVolume(0)
{
  fMessenger = new B2bDetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
B2bDetectorConstruction::~B2bDetectorConstruction()
{
  delete fStepLimit;
  delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
G4VPhysicalVolume* B2bDetectorConstruction::Construct()
{
  // Define materials
  DefineMaterials();

  // Define volumes
  return DefineVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B2bDetectorConstruction::DefineMaterials()
{
  // Material definition 

  G4NistManager* nistManager = G4NistManager::Instance();

  // Vacum (for the beam tube) defined using NIST Manager
  fVacuumMaterial = nistManager->FindOrBuildMaterial("G4_Galactic");
  
  // Air defined using NIST Manager
  fWorldMaterial  = nistManager->FindOrBuildMaterial("G4_AIR");

  G4String name;                     // a=mass of a mole;
  G4double a, z, density;            // z=mean number of protons;
  G4int iz, n;                       // iz=nb of protons  in an isotope;
  // n=nb of nucleons in an isotope;
  G4int ncomponents;
  G4double fractionmass, abundance;
  G4State state;
  G4double temp, pressure;

  // define an Element from isotopes, by relative abundance

    G4Isotope* target_isotope = new G4Isotope("255Es", iz=99 , n=255 , a=255.090273504*g/mole);
    G4Element* target_element  = new G4Element("pure 255Es", "255Es", ncomponents=1);
    target_element->AddIsotope(target_isotope, abundance= 100.*perCent);

    density = 8.84  * g/cm3;
    //fTargetMaterial  = new G4Material(name="255Es_material", density, ncomponents=1);

    fTargetMaterial  = new G4Material(name="255Es_material", density, ncomponents=1, state = kStateGas);
    fTargetMaterial->AddElement (target_element , fractionmass= 100*perCent);

//   I127

// define an Element from isotopes, by relative abundance
/*
    G4Isotope* I127_isotope = new G4Isotope("I127", iz=53, n=127, a=127*g/mole);
    G4Element* I127_element  = new G4Element("pure I127", "I_127", ncomponents=1);
    I127_element->AddIsotope(I127_isotope, abundance= 100.*perCent);

    density = 4.94 * g/cm3;
    fTargetMaterial  = new G4Material(name="I127_material", density, ncomponents=1);
    fTargetMaterial->AddElement (I127_element , fractionmass= 100*perCent);
*/

  //   F19

// define an Element from isotopes, by relative abundance
/*
    G4Isotope* F19_isotope = new G4Isotope("F19", iz=9, n=19, a=19*g/mole);
    G4Element* F19_element  = new G4Element("pure F19", "F19", ncomponents=1);
    F19_element->AddIsotope(F19_isotope, abundance= 100.*perCent);

    density = 4.94 * g/cm3;
    fTargetMaterial  = new G4Material(name="F19_material", density, ncomponents=1);
    fTargetMaterial->AddElement (F19_element , fractionmass= 100*perCent);
*/
//Au197

// define an Element from isotopes, by relative abundance
/*
    G4Isotope* Au197_isotope = new G4Isotope("Au197", iz=79, n=197, a=197*g/mole);
    G4Element* Au197_element  = new G4Element("pure Au197", "Au197", ncomponents=1);
    Au197_element->AddIsotope(Au197_isotope, abundance= 100.*perCent);

    density = 19.300 * g/cm3;
    fTargetMaterial  = new G4Material(name="Au197_material", density, ncomponents=1);
    fTargetMaterial->AddElement (Au197_element , fractionmass= 100*perCent);
*/


//La139

// define an Element from isotopes, by relative abundance
/*
    G4Isotope* La139_isotope = new G4Isotope("La139", iz=57, n=139, a=139*g/mole);
    G4Element* La139_element  = new G4Element("pure La139", "La139", ncomponents=1);
    La139_element->AddIsotope(La139_isotope, abundance= 100.*perCent);

    density = 6.162 * g/cm3;
    fTargetMaterial  = new G4Material(name="La139_material", density, ncomponents=1);
    fTargetMaterial->AddElement (La139_element , fractionmass= 100*perCent);

*/
// H_1

/*
    G4Isotope* H1_isotope = new G4Isotope("H1", iz=1, n=1, a=1*g/mole);
    G4Element* H1_element  = new G4Element("pure H1", "H_1", ncomponents=1);
    H1_element->AddIsotope(H1_isotope, abundance= 100.*perCent);
    density = 0.125 * g/cm3;
    //density = 0.0001785 *g/cm3;
    fTargetMaterial  = new G4Material(name="H1_material", density, ncomponents=1);
    fTargetMaterial->AddElement (H1_element , fractionmass= 100*perCent);
*/




// He_3

/*
    G4Isotope* He3_isotope = new G4Isotope("He3", iz=2, n=3, a=3*g/mole);
    G4Element* He3_element  = new G4Element("pure He3", "He_3", ncomponents=1);
    He3_element->AddIsotope(He3_isotope, abundance= 100.*perCent);
    density = 0.125 * g/cm3;
    //density = 0.0001785 *g/cm3;
    fTargetMaterial  = new G4Material(name="He3_material", density, ncomponents=1);
    fTargetMaterial->AddElement (He3_element , fractionmass= 100*perCent);
*/
//   Th_232

// define an Element from isotopes, by relative abundance
/*
    G4Isotope* Th232_isotope = new G4Isotope("Th232", iz=90, n=232, a=232*g/mole);
    G4Element* Th232_element  = new G4Element("pure Th232", "Th_232", ncomponents=1);
    Th232_element->AddIsotope(Th232_isotope, abundance= 100.*perCent);

    density = 19.84 * g/cm3;
    fTargetMaterial  = new G4Material(name="Th232_material", density, ncomponents=1);
    fTargetMaterial->AddElement (Th232_element , fractionmass= 100*perCent);
*/
//   Pu_244

// define an Element from isotopes, by relative abundance
/*
    G4Isotope* Pu244_isotope = new G4Isotope("Pu244", iz=94, n=244, a=244*g/mole);
    G4Element* Pu244_element  = new G4Element("pure Pu244", "Th_232", ncomponents=1);
    Pu244_element->AddIsotope(Pu244_isotope, abundance= 100.*perCent);

    density = 11.72 * g/cm3;
    fTargetMaterial  = new G4Material(name="Pu244_material", density, ncomponents=1);
    fTargetMaterial->AddElement (Pu244_element , fractionmass= 100*perCent);
*/

// U238
/*
    G4Isotope* U238_isotope = new G4Isotope("U238", iz=92, n=238, a=238*g/mole);
    G4Element* U238_element  = new G4Element("pure U238", "U_238", ncomponents=1);
    U238_element->AddIsotope(U238_isotope, abundance= 100.*perCent);

    density = 19.1 * g/cm3;
    fTargetMaterial  = new G4Material(name="U238_material", density, ncomponents=1);
    fTargetMaterial->AddElement (U238_element , fractionmass= 100*perCent);
*/

// Pb208
/*
    G4Isotope* Pb208_isotope = new G4Isotope("Pb208", iz=82, n=208, a=208*g/mole);
    G4Element* Pb208_element  = new G4Element("pure Pb208", "Pb_208", ncomponents=1);
    Pb208_element->AddIsotope(Pb208_isotope, abundance= 100.*perCent);

    density = 11.29 * g/cm3;
    fTargetMaterial  = new G4Material(name="Pb208_material", density, ncomponents=1);
    fTargetMaterial->AddElement (Pb208_element , fractionmass= 100*perCent);
/8,
// Sn112
/*
    G4Isotope* Sn112_isotope = new G4Isotope("Sn112", iz=50, n=112, a=7.31*g/cm3);
    G4Element* Sn112_element  = new G4Element("pure Sn112", "Sn_112", ncomponents=1);
    Sn112_element->AddIsotope(Sn112_isotope, abundance= 100.*perCent);

    density = 7.31 * g/cm3;
    fTargetMaterial  = new G4Material(name="Sn112_material", density, ncomponents=1);
    fTargetMaterial->AddElement (Sn112_element , fractionmass= 100*perCent);
*/
// B10
/*
    G4Isotope* B10_isotope = new G4Isotope("B10", iz=5, n=10, a=10.013*g/mole);
    G4Element* B10_element  = new G4Element("pure B10", "B_10", ncomponents=1);
    B10_element->AddIsotope(B10_isotope, abundance= 100.*perCent);

    density = 2.34 * g/cm3;
    fTargetMaterial  = new G4Material(name="B10_material", density, ncomponents=1);
    fTargetMaterial->AddElement (B10_element , fractionmass= 100*perCent);
*/
//--------------------------------------

  // Print materials
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// define B-field volumes as part of general definition of volumes in DefineVolumes()

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B2bDetectorConstruction::DefineVolumes()
{
  // Sizes of the principal geometrical components (solids)  
// ==========================================================

  
  G4double targetWidth =   500*nm;    // 500 nm thickness of the target foil
  G4double targetDistance  = 1*mm;     // Distant to the Target
  
  
// ==========================================================
  G4double worldLength = 1.3 * 2*(targetDistance+targetWidth);
                       
  // Definitions of Solids, Logical Volumes, Physical Volumes
  // =================== World =========================

  G4GeometryManager::GetInstance()->SetWorldMaximumExtent(worldLength);

  G4cout << "Computed tolerance = "
         << G4GeometryTolerance::GetInstance()->GetSurfaceTolerance()/mm
         << " mm" << G4endl;

  G4Box* worldS
    = new G4Box("world",                                    //its name
                worldLength/2,worldLength/2,worldLength/2); //its size
  G4cout << " World extends from " << -worldLength/2 << " to " << worldLength/2 << G4endl;

//  fMagneticLogical
//    = new G4LogicalVolume(magneticVolume, fVacuumMaterial, "magneticLogical");

//  G4LogicalVolume* worldLV
    fWorldLV
    = new G4LogicalVolume(
                 worldS,              //its solid
                 fVacuumMaterial,      //its material = vacuum
                 "World");            //its name
  
  //  Must place the World Physical volume unrotated at (0,0,0).
  // 
  G4VPhysicalVolume* worldPV
    = new G4PVPlacement(
                 0,               // no rotation
                 G4ThreeVector(), // at (0,0,0)
//                 worldLV,         // its logical volume
                 fWorldLV,         // its logical volume
                 "World",         // its name
                 0,               // its mother  volume
                 false,           // no boolean operations
                 0,               // copy number
                 fCheckOverlaps); // checking overlaps 
// *********************************************************
// =================== Big Sphere  ========================= few cms with few mms hole inside
// *********************************************************
  G4VSolid* targetS = new G4Sphere("target", targetDistance, targetDistance+targetWidth, 0.*deg,360.*deg, 0.*deg,360.*deg);
  // G4VSolid* targetS = new G4Box("target", 0.5*mm, 0.5*mm, 0.5*targetWidth);
  G4cout << " The sphere has outer radius " << targetDistance+targetWidth << " and inner " << targetDistance << "(is " << targetWidth << " thick)" << G4endl;

  fLogicTarget
    = new G4LogicalVolume(
			  targetS,              //its solid
			  fTargetMaterial,      //its material = vacuum
			  "Target");            //its name
  
  G4double maxTargetStep = 10*um;  // 10 um steps
  fStepLimit = new G4UserLimits(maxTargetStep);
  fLogicTarget->SetUserLimits(fStepLimit);
  
  
  G4VPhysicalVolume* targetPV
    = new G4PVPlacement(
                 0,               // no rotation
                 G4ThreeVector(0, 0, 0), // at (0,0,0) for box position is (0,0,targetDistance)
//                 worldLV,         // its logical volume
                 fLogicTarget,         // its logical volume
                 "Target",         // its name
                 fWorldLV,               // its mother  volume
                 false,           // no boolean operations
                 0,               // copy number
                 fCheckOverlaps); // checking overlaps

  
  // Visualization attributes
  G4VisAttributes* boxVisAtt= new G4VisAttributes(G4Colour(1.0,1.0,1.0));
  fWorldLV   ->SetVisAttributes(boxVisAtt);  

  G4VisAttributes* targetVis = new G4VisAttributes(G4Colour(0.0,0.0,1.0));
  fLogicTarget ->SetVisAttributes(targetVis);
  // Always return the physical world

  return worldPV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B2bDetectorConstruction::SetTargetMaterial(G4String materialName)
{
  G4NistManager* nistManager = G4NistManager::Instance();

  G4Material* pttoMaterial =
              nistManager->FindOrBuildMaterial(materialName);

  if (fTargetMaterial != pttoMaterial) {
     if ( pttoMaterial ) {
        fTargetMaterial = pttoMaterial;
        if (fLogicTarget) fLogicTarget->SetMaterial(fTargetMaterial);
        G4cout
          << G4endl 
          << "----> The target is made of " << materialName << G4endl;
     } else {
        G4cout
          << G4endl 
          << "-->  WARNING from SetTargetMaterial : "
          << materialName << " not found" << G4endl;
     }
  }
}
 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void B2bDetectorConstruction::SetMaxStep(G4double maxStep)
{
  if ((fStepLimit)&&(maxStep>0.)) fStepLimit->SetMaxAllowedStep(maxStep);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
