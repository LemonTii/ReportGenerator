#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control()
{
  reportGen.push_back(new RegionAnimalGenerator(new DescBehaviour<float>()));
  reportGen.push_back(new ChangeAnimalGenerator(new AscBehaviour<float>()));
  reportGen.push_back(new SubWithHorseGenerator(new DescBehaviour<int>()));
}

Control::~Control()
{
  int i = 0;

  for(i=0; i<reportGen.size(); ++i)
  {
    delete reportGen.at(i);
  }
}

void Control::init(string filename)
{
  ReportGenerator::load(filename);
}

void Control::launch()
{
  View v;
  int choice = -1;

  try
  {
    init("farms.dat");
  }
  catch(runtime_error& error)
  {
    cout<<endl<< "Exception "<< error.what()<<endl;
    cout<<"Make sure you have farms.dat file inside the same directory before running!!"<<endl;
    exit(1);
  }

  while (choice != 0)
  {
    v.showMenu(choice);

    if(choice != 0)
    {
      try
      {
        reportGen.at(choice - 1)->compute();
      }
      catch(runtime_error& error)
      {
        cout<<endl<<"Exception "<<error.what()<<endl;
        exit(1);
      }
    }
  }

  ReportGenerator::cleanup();
}
