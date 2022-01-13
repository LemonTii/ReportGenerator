#include <iostream>
using namespace std;
#include <string>
#include <fstream>

#include "ReportGenerator.h"

vector<Record*> ReportGenerator::records;
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;

ReportGenerator::ReportGenerator()
{

}

ReportGenerator::~ReportGenerator()
{

}

void ReportGenerator::load(string filename)
{
  ifstream infile(filename);

  if (!infile)
  {
    throw runtime_error("Could not read file!");
  }

  int year;
  string region;
  string subRegion;
  string animalType;
  int numFarms;
  int numAnimals;
  Record* r;

  while(infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals)
  {
    r = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
    records.push_back(r);
    yearMap.add(year, r);
    regionMap.add(region, r);
    animalMap.add(animalType, r);
  }
}

void ReportGenerator::cleanup()
{
  int i = 0;

  for(i=0; i<records.size(); ++i)
  {
    delete records.at(i);
  }
}
