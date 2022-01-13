#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>

#include "RegionAnimalGenerator.h"

RegionAnimalGenerator::RegionAnimalGenerator(CompareBehaviour<float>* c)
                      :ReportGenerator(), report(new ReportData<float>(c))
{

}

RegionAnimalGenerator::~RegionAnimalGenerator()
{
  delete report;
}

void RegionAnimalGenerator::compute()
{
  int i = 0, j = 0, index = 0;
  vector<int> denominators;
  vector<float> rowData;
  vector<string> regions;
  vector<string> animals;
  int overallTotal = 0, total = 0;

  regionMap.getKeys(regions);
  animalMap.getKeys(animals);

  for(i=0; i<animals.size(); ++i)
  {
    rowData.push_back(0);
    for(j=0; j<animalMap[animals.at(i)].size(); ++j)
    {
      if(animalMap[animals.at(i)].at(j)->getYear() == 2016 && animalMap[animals.at(i)].at(j)->getRegion() != "CAN" && animalMap[animals.at(i)].at(j)->getSubRegion() == "All")
      {
        total+=animalMap[animals.at(i)].at(j)->getNumFarms();
      }
    }
    denominators.push_back(total);
    overallTotal += total;
    total = 0;
  }
  rowData.push_back(0);
  denominators.push_back(overallTotal);

  for(i=0; i<regions.size(); ++i)
  {
    total = 0;
    if(regions.at(i) != "CAN")
    {
      for(j=0; j<regionMap[regions.at(i)].size(); ++j)
      {
        if(regionMap[regions.at(i)].at(j)->getYear() == 2016 && regionMap[regions.at(i)].at(j)->getSubRegion() == "All")
        {
          total+=regionMap[regions.at(i)].at(j)->getNumFarms();
          index = indexOf(regionMap[regions.at(i)].at(j)->getAnimalType(), animals);

          if(index<0)
          {
            throw runtime_error("Internal error at RegionAnimalGenerator!");
          }
          rowData.at(index)+=regionMap[regions.at(i)].at(j)->getNumFarms();
        }
      }
      rowData.at(rowData.size()-1) += total;

      for(j=0; j<rowData.size(); ++j)
      {
        if(denominators.at(j) != 0)
        {
          rowData.at(j) /= denominators.at(j);
          rowData.at(j) *= 100;
        }
      }

      formatData(regions.at(i), rowData);

      resetVector(rowData);
    }
  }

  printReport(animals);
  report->clear();
}

void RegionAnimalGenerator::formatData(string region, vector<float>& rowData)
{
  int i = 0;
  stringstream ss;
  ss<<region<<" ";

  for(i=0; i<rowData.size(); ++i)
  {
    ss<<fixed<<setprecision(1)<<setfill(' ')<<setw(20)<<rowData.at(i);
  }

  report->add(rowData.at(rowData.size()-1), ss.str());
}

void RegionAnimalGenerator::printReport(vector<string>& animals)
{
  int i = 0;
  stringstream ss;
  ss<<setfill(' ')<<setw((animals.size()*20)/2)<<"PERCENTAGE OF FARMS BY REGION IN 2016"<<endl
    <<setfill(' ')<<setw((animals.size()*20)/2)<<"--------------------------------------"<<endl<<endl
    <<"   ";
  for(i=0; i<animals.size(); ++i)
  {
    ss<<setfill(' ')<<setw(20)<<animals.at(i);
  }
  ss<<setfill(' ')<<setw(20)<<"Total"<<endl<<endl;

  ss<<*report;

  cout<<ss.str();

  ofstream outfile("RegionAnimal.txt");
  if(!outfile)
  {
    throw runtime_error("File output error!");
  }
  outfile<<ss.str();
}

int RegionAnimalGenerator::indexOf(string check, vector<string>& toCheck)
{
  int i = 0;

  for(i=0; i<toCheck.size(); ++i)
  {
    if(toCheck.at(i) == check)
    {
      return i;
    }
  }

  return -1;
}

void RegionAnimalGenerator::resetVector(vector<float>& v)
{
  int i = 0;
  for(i=0; i<v.size(); ++i)
  {
    v.at(i) = 0;
  }
}
