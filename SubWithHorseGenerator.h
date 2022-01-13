#ifndef SUBWITHHORSEGENERATOR_H
#define SUBWITHHORSEGENERATOR_H

#include "CompareBehaviour.h"
#include "ReportGenerator.h"
#include "ReportData.h"
#include <sstream>

/*****************************************************************************
 *
 * Class         : SubWithHorseGenerator
 *
 * Description   : Generates a report based on subregions with the highest
 *                 numbers of horses and ponies per region
 *
 *****************************************************************************/
class SubWithHorseGenerator: public ReportGenerator
{
  public:
    /*****************************************************************************
     *
     * Constructor   : SubWithHorseGenerator
     *
     * Description   : Initializes an object of SubWithHorseGenerator type
     *
     * Parameters    : INPUT => CompareBehaviour<int>*  The sorting order
     *
     * Return Value  : None
     *
     *****************************************************************************/
    SubWithHorseGenerator(CompareBehaviour<int>*);

    /*****************************************************************************
     *
     * Destructor    : ~SubWithHorseGenerator
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    virtual ~SubWithHorseGenerator();

    /*****************************************************************************
     *
     * Function      : compute
     *
     * Description   : Computes all required data for this report
     *
     * Parameters    : None
     *
     * Return Value  : void
     *
     *****************************************************************************/
    virtual void compute();

  private:
    ReportData<int>* report;

    /*****************************************************************************
     *
     * Function      : indexOf
     *
     * Description   : Returns the index of where the given string is located
     *                 in the given vector
     *
     * Parameters    : INPUT => string            The string to search for
     *                 INPUT => vector<string>&   The vector to search in
     *
     * Return Value  : Integer representing the index
     *
     *****************************************************************************/
    int indexOf(string, vector<string>&);

    /*****************************************************************************
     *
     * Function      : formatData
     *
     * Description   : Formats given data for the report
     *
     * Parameters    : INPUT => string  The region
     *                 INPUT => string  The subregion
     *                 INPUT => int     The total number of horses and ponies
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void formatData(string, string, int);

    /*****************************************************************************
     *
     * Function      : printReport
     *
     * Description   : Prints the report to the terminal and saves it to a file
     *
     * Parameters    : None
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void printReport();
};

#endif
