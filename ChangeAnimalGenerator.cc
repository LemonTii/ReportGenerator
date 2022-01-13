#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>

#include "ChangeAnimalGenerator.h"

ChangeAnimalGenerator::ChangeAnimalGenerator(CompareBehaviour<float>* c)
                      :ReportGenerator(), report(new ReportData<float>(c))
{

}

ChangeAnimalGenerator::~ChangeAnimalGenerator()
{
  delete report;
}

void ChangeAnimalGenerator::compute()
{
  int i = 0, j = 0, index = 0;
  int beforeTotal = 0, afterTotal = 0;
  int beforeYear = 2011, afterYear = 2016;
  vector<string> animals;
  vector<int> beforeData, afterData;
  vector<float> rowData;

  animalMap.getKeys(animals);
  for(i=0; i<animals.size(); ++i)
  {
    beforeData.push_back(0);
    afterData.push_back(0);
  }

  for(i=0; i<yearMap[beforeYear].size(); ++i)
  {
    if(yearMap[beforeYear].at(i)->getRegion() == "CAN")
    {
      index = indexOf(yearMap[beforeYear].at(i)->getAnimalType(), animals);
      if(index<0)
      {
        throw runtime_error("Internal error at ChangeAnimalGenerator!");
      }
      beforeData.at(index)+=yearMap[beforeYear].at(i)->getNumAnimals();
      beforeTotal+=yearMap[beforeYear].at(i)->getNumAnimals();
    }
  }

  for(i=0; i<yearMap[afterYear].size(); ++i)
  {
    if(yearMap[afterYear].at(i)->getRegion() == "CAN")
    {
      index = indexOf(yearMap[afterYear].at(i)->getAnimalType(), animals);
      if(index<0)
      {
        throw runtime_error("Internal error at ChangeAnimalGenerator!");
      }
      afterData.at(index)+=yearMap[afterYear].at(i)->getNumAnimals();
      afterTotal+=yearMap[afterYear].at(i)->getNumAnimals();
    }
  }

  for(i=0; i<animals.size(); ++i)
  {
    if(beforeTotal != 0 && afterTotal != 0)
    {
      rowData.push_back(((float)(beforeData.at(i) * 100))/beforeTotal);
      rowData.push_back(((float)(afterData.at(i) * 100))/afterTotal);
      rowData.push_back((((float)(afterData.at(i) * 100))/afterTotal) - (((float)(beforeData.at(i) * 100))/beforeTotal));
    }
    else
    {
      rowData.push_back(0);
      rowData.push_back(0);
      rowData.push_back(0);
    }

    formatData(animals.at(i), rowData);
    rowData.clear();
  }

  printReport(beforeYear, afterYear);
  report->clear();
}

void ChangeAnimalGenerator::formatData(string animal, vector<float>& rowData)
{
  int i = 0;
  stringstream ss;
  ss<<setfill(' ')<<setw(20)<<animal;

  for(i=0; i<rowData.size()-1; ++i)
  {
    ss<<fixed<<setprecision(1)<<setfill(' ')<<setw(10)<<rowData.at(i);
  }
  ss<<fixed<<setprecision(1)<<setfill(' ')<<setw(10)<<showpos<<rowData.at(rowData.size()-1);

  report->add(rowData.at(rowData.size()-1), ss.str());
}

void ChangeAnimalGenerator::printReport(int beforeYear, int afterYear)
{
  int i = 0;
  stringstream ss;
  ss<<setfill(' ')<<setw(50)<<"PERCENTAGE CHANGE OF ANIMALS (2011 - 2016)"<<endl
    <<setfill(' ')<<setw(50)<<"------------------------------------------"<<endl<<endl
    <<setfill(' ')<<setw(20)<<" "
    <<setfill(' ')<<setw(10)<<beforeYear
    <<setfill(' ')<<setw(10)<<afterYear
    <<setfill(' ')<<setw(10)<<"Change"<<endl<<endl
    <<*report;

  cout<<ss.str();

  ofstream outfile("ChangeAnimal.txt");
  if(!outfile)
  {
    throw runtime_error("File output error!");
  }
  outfile<<ss.str();
}

int ChangeAnimalGenerator::indexOf(string check, vector<string>& toCheck)
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
