#include "myHit.hh"
#include "G4UnitsTable.hh"
#include <fstream>

G4ThreadLocal G4Allocator<myHit>* myHitAllocator = nullptr;

myHit::myHit()
{}


myHit::~myHit() {}


G4bool myHit::operator==(const myHit& right) const
{
  return ( this == &right ) ? true : false;
}


void myHit::Draw()
{
}


void myHit::Print()
{
  G4cout
     << "  chamberNb: " << std::setw(7) << fChamberNb
     << "  Edep: "       << std::setw(7) << G4BestUnit(fEdep,"Energy")
     << G4endl;
}
