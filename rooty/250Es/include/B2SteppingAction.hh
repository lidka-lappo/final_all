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
/// copy from \file B1SteppingAction.hh
/// \brief Definition of the B2SteppingAction class

#ifndef B2SteppingAction_h
#define B2SteppingAction_h 1

#include "G4UserSteppingAction.hh"

#include "globals.hh"
#include "G4GenericAnalysisManager.hh"

class B2EventAction;

class G4LogicalVolume;
class G4SteppingManager;

/// Stepping action class
/// 

class B2SteppingAction : public G4UserSteppingAction
{
  public:
    B2SteppingAction(B2EventAction* eventAction);
    virtual ~B2SteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    B2EventAction*  fEventAction;
    G4LogicalVolume* fScoringVolume;
    G4SteppingManager* fManager;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
