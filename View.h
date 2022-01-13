#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/*****************************************************************************
 *
 * Class         : View
 *
 * Description   : Controls the user interface of the program
 *
 *****************************************************************************/
class View
{
  public:
    /*****************************************************************************
     *
     * Function      : showMenu
     *
     * Description   : shows available options and returns the user's choice
     *
     * Parameters    : OUTPUT => int&   The int containing user's choice
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void showMenu(int&);
};

#endif
