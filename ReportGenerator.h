#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include "Record.h"
#include "Map.h"

/*****************************************************************************
 *
 * Class         : ReportGenerator
 *
 * Description   : Holds information of generating reports with given data
 *
 *****************************************************************************/
class ReportGenerator
{
  public:
    /*****************************************************************************
     *
     * Constructor   : ReportGenerator
     *
     * Description   : Initializes an object of ReportGenerator type
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    ReportGenerator();

    /*****************************************************************************
     *
     * Destructor    : ~ReportGenerator
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    virtual ~ReportGenerator();

    /*****************************************************************************
     *
     * Function      : cleanup
     *
     * Description   : Frees all memory associated with the data used
     *
     * Parameters    : None
     *
     * Return Value  : void
     *
     *****************************************************************************/
    static void cleanup();

    /*****************************************************************************
     *
     * Function      : load
     *
     * Description   : Loads and creates all data given from the file
     *
     * Parameters    : INPUT => string  The name of the file
     *
     * Return Value  : void
     *
     *****************************************************************************/
    static void load(string filename);

    /*****************************************************************************
     *
     * Function      : compute
     *
     * Description   : Computes all required data for the report
     *
     * Parameters    : None
     *
     * Return Value  : void
     *
     *****************************************************************************/
    virtual void compute() = 0;

  protected:
    static vector<Record*> records;
    static Map<int> yearMap;
    static Map<string> regionMap;
    static Map<string> animalMap;

};

#endif
