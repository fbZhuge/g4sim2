#include "run.hh"

MyRunAction::MyRunAction(){
  auto analysisManager = G4AnalysisManager::Instance();
  G4int verboseLevel=1; // [0..4]
  analysisManager->SetVerboseLevel(verboseLevel);

  analysisManager->CreateNtuple("Energy_Deposits","Edep");
  // analysisManager->CreateNtupleIColumn("ChamberNb");
  analysisManager->CreateNtupleDColumn("Edep_index0");
  analysisManager->CreateNtupleDColumn("Edep_index1");
  analysisManager->CreateNtupleDColumn("Edep_index2");
  analysisManager->CreateNtupleDColumn("Edep_index3");
  analysisManager->CreateNtupleDColumn("Edep_index4");
  analysisManager->CreateNtupleDColumn("Edep_index5");
  analysisManager->CreateNtupleDColumn("Edep_index6");
  analysisManager->CreateNtupleDColumn("Edep_index7");
  analysisManager->CreateNtupleDColumn("Edep_index8");
  analysisManager->CreateNtupleDColumn("Edep_index9");
  analysisManager->FinishNtuple();

  // analysisManager->CreateNtuple("Scoring", "Scoring");
  // analysisManager->CreateNtupleDColumn("EnergyDeposit");
  // analysisManager->FinishNtuple(1);
}

MyRunAction::~MyRunAction(){}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  // Get analysis manger
  auto analysisManager = G4AnalysisManager::Instance();

  // open an output file
  G4String filename = "myRootFile.root";
  analysisManager->OpenFile(filename);

  // G4int runID = run->GetRunID();
  // std::stringstream strRunID;
  // strRunID << runID;

  // man->OpenFile("output"+strRunID.str()+".root");
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();
}
