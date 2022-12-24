#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(const G4String& name,
                                         const G4String& hitsCollectionName) : G4VSensitiveDetector(name)
{
  collectionName.insert(hitsCollectionName);
}

MySensitiveDetector::~MySensitiveDetector(){}

void MySensitiveDetector::Initialize(G4HCofThisEvent* hce)
{
}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory*)
{
  G4double edep = aStep->GetTotalEnergyDeposit();
  if (edep==0.) return false;

  myHit* newHit = new myHit();
  G4int Chamber_Number = aStep->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber();

  G4int index=Chamber_Number%100;
  Set_Energy(index, edep);
  G4int Track_ID = aStep->GetTrack()->GetTrackID();



  newHit->SetTrackID(Track_ID);
  newHit->SetChamberNb(Chamber_Number);
  newHit->SetEdep(edep);
  newHit->SetPos (aStep->GetPostStepPoint()->GetPosition());

  auto analysisManager = G4AnalysisManager::Instance();
  // analysisManager->FillNtupleIColumn(0, Chamber_Number);
  analysisManager->FillNtupleDColumn(0, Get_Energy(0));
  analysisManager->FillNtupleDColumn(1, Get_Energy(1));
  analysisManager->FillNtupleDColumn(2, Get_Energy(2));
  analysisManager->FillNtupleDColumn(3, Get_Energy(3));
  analysisManager->FillNtupleDColumn(4, Get_Energy(4));
  analysisManager->FillNtupleDColumn(5, Get_Energy(5));
  analysisManager->FillNtupleDColumn(6, Get_Energy(6));
  analysisManager->FillNtupleDColumn(7, Get_Energy(7));
  analysisManager->FillNtupleDColumn(8, Get_Energy(8));
  analysisManager->FillNtupleDColumn(9, Get_Energy(9));
  analysisManager->AddNtupleRow();

  newHit->Print();
  return true;
}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{
}

void MySensitiveDetector::Set_Energy(G4int index, G4double energy){
  fEnergy_dist[index] += energy;
}

G4double MySensitiveDetector::Get_Energy(G4int index){
  return fEnergy_dist[index];
}
