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
/// \file PhysicsList.cc
/// \brief Implementation of the PhysicsList class
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "PhysicsList.hh"

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#include "G4HadronElasticPhysicsHP.hh"
#include "G4HadronElasticPhysicsXS.hh"

#include "G4HadronPhysicsFTFP_BERT_HP.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4HadronPhysicsQGSP_BIC_AllHP.hh"
#include "G4HadronPhysicsQGSP_FTFP_BERT.hh" //
#include "G4HadronInelasticQBBC.hh"
#include "G4HadronPhysicsINCLXX.hh"

#include "G4IonElasticPhysics.hh"
#include "G4IonPhysicsXS.hh"
#include "G4IonQMDPhysics.hh"
#include "G4IonPhysicsPHP.hh"
#include "G4IonINCLXXPhysics.hh"

#include "G4DecayPhysics.hh" //all
#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4IonPhysics.hh"
#include "G4StoppingPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4NeutronTrackingCut.hh"


#include "GammaNuclearPhysics.hh"

// particles

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BosonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::PhysicsList()
:G4VModularPhysicsList()
{
  G4int ver = 0;  
  G4cout << "<<< Geant4 Physics List simulation engine: QGSP_FTFP_BERT"<<G4endl;
  G4cout <<G4endl;

  defaultCutValue = 0.7*CLHEP::mm;  
  SetVerboseLevel(ver);

  // EM Physics
  RegisterPhysics( new G4EmStandardPhysics(ver) );  //nessecaire
  // Synchroton Radiation & GN Physics
  RegisterPhysics( new G4EmExtraPhysics(ver) ); //mod 24

  // Decays
  RegisterPhysics( new G4DecayPhysics(ver) ); //mod 23

  // Stopping Physics
   RegisterPhysics( new G4StoppingPhysics(ver) ); //nessecaire

  //gamma
   RegisterPhysics( new GammaNuclearPhysics("gamma")); //mod 21

  // Neutron tracking cut
  RegisterPhysics( new G4NeutronTrackingCut(ver));  //mod 20



//mod1
    //Hadron Elastic scattering
   RegisterPhysics( new G4HadronElasticPhysics(ver) ); 
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsQGSP_FTFP_BERT(ver)); 
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 

  //mod2
   /*// Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsHP(ver));
  // Hadron Physics
    RegisterPhysics( new G4HadronPhysicsQGSP_FTFP_BERT(ver)); 
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

    //mod3
 /*  // Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsXS(ver));
  // Hadron Physics
    RegisterPhysics( new G4HadronPhysicsQGSP_FTFP_BERT(ver)); 
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 
*/
  /////////////////////////////////////////////////

  //mod4
 /* // Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysics(ver) ); 
  // Hadron Physics
    RegisterPhysics( new G4HadronPhysicsINCLXX(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

  //mod5
  /*// Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsHP(ver));
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsINCLXX(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 
*/
    //mod6
 /*  // Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsXS(ver));
  // Hadron Physics
  RegisterPhysics( new G4HadronPhysicsINCLXX(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 
*/

    /////////////////////////////////////////////////

  //mod7
  /*// Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysics(ver) ); 
  // Hadron Physics
    RegisterPhysics( new G4HadronInelasticQBBC(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

  //mod8
   /*// Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsHP(ver));
  // Hadron Physics
    RegisterPhysics( new G4HadronInelasticQBBC(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

    //mod9
   /*// Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsXS(ver));
  // Hadron Physics
    RegisterPhysics( new G4HadronInelasticQBBC(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

////////////////////////////////////////////////////////////////////


  //mod10
  /*// Hadron Elastic scattering
   RegisterPhysics( new G4HadronElasticPhysics(ver) ); 
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsQGSP_BIC_HP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 
*/
  //mod11
  /* // Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsHP(ver));
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsFTFP_BERT_HP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 8?

    //mod12
   // Hadron Elastic scattering
   /* RegisterPhysics( new G4HadronElasticPhysicsXS(ver));
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsFTFP_BERT_HP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 

*/

  ////////////////////////////////////////////////////////////////////


  //mod13
 /* // Hadron Elastic scattering
   RegisterPhysics( new G4HadronElasticPhysics(ver) ); 
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsQGSP_BIC_HP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

  //mod14
   /*// Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsHP(ver));
  // Hadron Physics
RegisterPhysics( new G4HadronPhysicsQGSP_BIC_HP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

    //mod15
   /*// Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsXS(ver));
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsQGSP_BIC_HP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */


  ////////////////////////////////////////////////////////////////////


  //mod16
  // Hadron Elastic scattering
  /* RegisterPhysics( new G4HadronElasticPhysics(ver) ); 
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsQGSP_BIC_AllHP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

  //mod17
  /* // Hadron Elastic scattering
    RegisterPhysics( new G4HadronElasticPhysicsHP(ver));
  // Hadron Physics
  RegisterPhysics( new G4HadronPhysicsQGSP_BIC_AllHP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); */

    //mod18
   // Hadron Elastic scattering
   /* RegisterPhysics( new G4HadronElasticPhysicsXS(ver));
  // Hadron Physics
   RegisterPhysics( new G4HadronPhysicsQGSP_BIC_AllHP(ver));
    // Ion Physics
  RegisterPhysics( new G4IonPhysics(ver)); 

*/
/////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////
  // Hadron Elastic scattering
  //
  //RegisterPhysics( new G4HadronElasticPhysics(ver) );
  //RegisterPhysics( new G4HadronElasticPhysicsHP(ver));
  //RegisterPhysics( new G4HadronElasticPhysicsXS(ver));  

  // Hadron Inelastic physics
  //
 //RegisterPhysics( new G4HadronPhysicsQGSP_FTFP_BERT(ver)); //1, 2, 3 
 // RegisterPhysics( new G4HadronPhysicsFTFP_BERT_HP(ver)); //10, 11, 12//G4NucleiProperties::GetNuclearMass: Wrong values for A = 0 and Z = 50
  //RegisterPhysics( new G4HadronPhysicsQGSP_BIC_HP(ver)); //13, 14, 15G4NucleiProperties::GetNuclearMass: Wrong values for A = 0 and Z = 50
//RegisterPhysics( new G4HadronPhysicsQGSP_BIC_AllHP(ver)); //16, 17, 18 //not  working 
 // RegisterPhysics( new G4HadronInelasticQBBC(ver)); //7, 8, 9 
 // RegisterPhysics( new G4HadronPhysicsINCLXX(ver));//4, 5, 6



    // Ion Physics
 // RegisterPhysics( new G4IonPhysics(ver)); //1 - 18

// Ion Elastic scattering
  //RegisterPhysics( new G4IonElasticPhysics(ver));
  
  // Ion Inelastic physics
   //RegisterPhysics( new G4IonPhysicsXS(ver));
//RegisterPhysics( new G4IonPhysicsPHP(ver)); // cannot use without G4TENDL dataset
   //RegisterPhysics( new G4IonQMDPhysics(ver));
 // RegisterPhysics( new G4IonINCLXXPhysics(ver));




}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::~PhysicsList()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::ConstructParticle()
{
  G4BosonConstructor  pBosonConstructor;
  pBosonConstructor.ConstructParticle();

  G4LeptonConstructor pLeptonConstructor;
  pLeptonConstructor.ConstructParticle();

  G4MesonConstructor pMesonConstructor;
  pMesonConstructor.ConstructParticle();

  G4BaryonConstructor pBaryonConstructor;
  pBaryonConstructor.ConstructParticle();

  G4IonConstructor pIonConstructor;
  pIonConstructor.ConstructParticle();

  G4ShortLivedConstructor pShortLivedConstructor;
  pShortLivedConstructor.ConstructParticle();  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::SetCuts()
{
   SetCutValue(0, "proton");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
