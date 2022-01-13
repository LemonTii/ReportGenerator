#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Record::Record(int y, string r, string s, string a, int nf, int na)
      :year(y), region(r), subRegion(s), animalType(a), numFarms(nf), numAnimals(na)
{
  //create report generators
}

Record::~Record()
{
  //delete report generators
}

int Record::getYear()
{
  return year;
}

string Record::getRegion()
{
  return region;
}

string Record::getSubRegion()
{
  return subRegion;
}

string Record::getAnimalType()
{
  return animalType;
}

int Record::getNumFarms()
{
  return numFarms;
}

int Record::getNumAnimals()
{
  return numAnimals;
}
