#ifndef CHANGEANIMALGENERATOR_H
#define CHANGEANIMALGENERATOR_H

#include "CompareBehaviour.h"
#include "ReportGenerator.h"
#include "ReportData.h"
#include <sstream>

/*****************************************************************************
 *
 * Class         : ChangeAnimalGenerator
 *
 * Description   : Generates a Report Based on the % change in Animal per region
 *
 *****************************************************************************/
class ChangeAnimalGenerator: public ReportGenerator
{
  public:
    /*****************************************************************************
     *
     * Constructor   : ChangeAnimalGenerator
     *
     * Description   : Initializes an object of ChangeAnimalGenerator type
     *
     * Parameters    : INPUT => CompareBehaviour<float>*  The sorting order
     *
     * Return Value  : None
     *
     *****************************************************************************/
    ChangeAnimalGenerator(CompareBehaviour<float>*);

    /*****************************************************************************
     *
     * Destructor    : ~ChangeAnimalGenerator
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    virtual ~ChangeAnimalGenerator();

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
     * Function      : formatData
     *
     * Description   : Formats given data for the report
     *
     * Parameters    : INPUT => string*         Titles for each row
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
     * Parameters    : INPUT => int   The first year being compared in this report
     *                 INPUT => int   The second year being compared in this report
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void printReport(int, int);
};

#endif
