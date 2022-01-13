#ifndef CONTROL_H
#define CONTROL_H

#include "RegionAnimalGenerator.h"
#include "ChangeAnimalGenerator.h"
#include "SubWithHorseGenerator.h"
#include "ReportGenerator.h"
#include "View.h"
#include <vector>

/*****************************************************************************
 *
 * Class         : Control
 *
 * Description   : Holds information of the control flow and initialization
 *
 *****************************************************************************/
class Control
{
  public:
    /*****************************************************************************
     *
     * Constructor   : Control
     *
     * Description   : Initializes an object of Control type
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    Control();

    /*****************************************************************************
     *
     * Destructor    : ~Control
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    ~Control();

    /*****************************************************************************
     *
     * Function      : launch
     *
     * Description   : Starts the application
     *
     * Parameters    : None
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void launch();

  private:
    vector<ReportGenerator*> reportGen;

    /*****************************************************************************
     *
     * Function      : init
     *
     * Description   : Initializes all data to be used by the application
     *
     * Parameters    : INPUT => string   The name of the file to use when
     *                                   initializing the data
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void init(string);
};

#endif
