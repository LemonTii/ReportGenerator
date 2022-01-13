#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>

#include "SubWithHorseGenerator.h"

SubWithHorseGenerator::SubWithHorseGenerator(CompareBehaviour<int>* c)
                      :ReportGenerator(), report(new ReportData<int>(c))
{

}

SubWithHorseGenerator::~SubWithHorseGenerator()
{
  delete report;
}

void SubWithHorseGenerator::compute()
{
  int oIndex = 0, iIndex = 0, largest = 0;
  int year = 2016;
  string animal = "Horses-Ponies";
  int i = 0, j = 0;
  vector<vector<string>*> subR;
  vector<vector<int>*> totals;
  vector<string> regions;

  regionMap.getKeys(regions);
  for(i=0; i<regions.size(); ++i)
  {
    vector<int>* v = new vector<int>();
    vector<string>* u = new vector<string>();
    totals.push_back(v);
    subR.push_back(u);
  }

  for(i=0; i<animalMap[animal].size(); ++i)
  {
    if(animalMap[animal].at(i)->getYear() == year && animalMap[animal].at(i)->getRegion() != "CAN" && animalMap[animal].at(i)->getSubRegion() != "All")
    {
      oIndex = indexOf(animalMap[animal].at(i)->getRegion(), regions);
      if(oIndex<0)
      {
        throw runtime_error("Internal error at SubWithHorseGenerator!");
      }
      iIndex = indexOf(animalMap[animal].at(i)->getSubRegion(), *(subR.at(oIndex)));

      if(iIndex>=0)
      {
        totals.at(oIndex)->at(iIndex)+=animalMap[animal].at(i)->getNumAnimals();
      }
      else
      {
        subR.at(oIndex)->push_back(animalMap[animal].at(i)->getSubRegion());
        totals.at(oIndex)->push_back(animalMap[animal].at(i)->getNumAnimals());
      }
    }
  }

  for(i=0; i<regions.size(); ++i)
  {
    largest = 0, iIndex = 0;

    if(regions.at(i) != "CAN")
    {
      for(j=0; j<totals.at(i)->size(); ++j)
      {
        if(largest<totals.at(i)->at(j))
        {
          largest = totals.at(i)->at(j);
          iIndex = j;
        }
      }

      if(largest == 0)
      {
        formatData(regions.at(i), " ", largest);
      }
      else
      {
        formatData(regions.at(i), subR.at(i)->at(iIndex), largest);
      }
    }
  }

  printReport();

  for(i=0; i<regions.size(); ++i)
  {
    delete totals.at(i);
    delete subR.at(i);
  }
  report->clear();
}

void SubWithHorseGenerator::formatData(string region, string subRegion, int total)
{
  int i = 0;
  stringstream ss;
  ss<<setfill(' ')<<setw(5)<<region
    <<setfill(' ')<<setw(30)<<subRegion
    <<setfill(' ')<<setw(10)<<total;

  report->add(total, ss.str());
}

void SubWithHorseGenerator::printReport()
{
  int i = 0;
  stringstream ss;
  ss<<setfill(' ')<<setw(25)<<"SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016"<<endl
    <<setfill(' ')<<setw(25)<<"----------------------------------------------------"<<endl<<endl
    <<*report;

  cout<<ss.str();

  ofstream outfile("SubWithHorse.txt");
  if(!outfile)
  {
    throw runtime_error("File output error!");
  }
  outfile<<ss.str();
}

int SubWithHorseGenerator::indexOf(string check, vector<string>& toCheck)
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
