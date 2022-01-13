#ifndef REGIONANIMALGENERATOR_H
#define REGIONANIMALGENERATOR_H

#include "CompareBehaviour.h"
#include "ReportGenerator.h"
#include "ReportData.h"
#include <sstream>

/*****************************************************************************
 *
 * Class         : RegionAnimalGenerator
 *
 * Description   : Generates a report based on the % farms hosting certain
 *                 types of animals for a given region
 *
 *****************************************************************************/
class RegionAnimalGenerator: public ReportGenerator
{
  public:
    /*****************************************************************************
     *
     * Constructor   : RegionAnimalGenerator
     *
     * Description   : Initializes an object of RegionAnimalGenerator type
     *
     * Parameters    : INPUT => CompareBehaviour<float>*  The sorting order
     *
     * Return Value  : None
     *
     *****************************************************************************/
    RegionAnimalGenerator(CompareBehaviour<float>*);

    /*****************************************************************************
     *
     * Destructor    : ~RegionAnimalGenerator
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    virtual ~RegionAnimalGenerator();

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
    ReportData<float>* report;

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
     * Function      : resetVector
     *
     * Description   : Returns a vector with all of its elements set to 0
     *                 without changing size
     *
     * Parameters    : OUTPUT => vector<float>&  The vector to set all values to 0
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void resetVector(vector<float>&);

    /*****************************************************************************
     *
     * Function      : formatData
     *
     * Description   : Formats given data for the report
     *
     * Parameters    : INPUT => string          Titles for each row
     *                 INPUT => vector<float>&  The computed numbers organized
     *                                          into its respective columns
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void formatData(string, vector<float>&);

    /*****************************************************************************
     *
     * Function      : printReport
     *
     * Description   : Prints the report to the terminal and saves it to a file
     *
     * Parameters    : INPUT => vector<string>&   The animals for each column
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void printReport(vector<string>&);
};

#endif
