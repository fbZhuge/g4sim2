#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "myHit.hh"
#include <vector>


class MySensitiveDetector : public G4VSensitiveDetector{
public:
  MySensitiveDetector(const G4String& name,
                      const G4String& hitsCollectionName);
  ~MySensitiveDetector() override;

  void   Initialize(G4HCofThisEvent* hitCollection) override;
  G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
  void   EndOfEvent(G4HCofThisEvent* hitCollection) override;

  void Set_Energy(G4int index, G4double energy);
  G4double Get_Energy(G4int index);

private:
  myHitsCollection* fHitsCollection = nullptr;
  G4double fEnergy_dist[10]={0};

};
#endif
