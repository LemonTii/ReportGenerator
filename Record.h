#ifndef RECORD_H
#define RECORD_H

#include <vector>

/*****************************************************************************
 *
 * Class         : Record
 *
 * Description   : Holds information of a record
 *
 *****************************************************************************/
class Record
{
  public:
    /*****************************************************************************
     *
     * Constructor   : Record
     *
     * Description   : Initializes an object of Record type
     *
     * Parameters    : INPUT => int     The year
     *                 INPUT => string  The region
     *                 INPUT => string  The subRegion
     *                 INPUT => string  The animalType
     *                 INPUT => int     The numFarms
     *                 INPUT => int     The numAnimals
     *
     * Return Value  : None
     *
     *****************************************************************************/
    Record(int, string, string, string, int, int);

    /*****************************************************************************
     *
     * Destructor    : ~Record
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    ~Record();

    /*****************************************************************************
     *
     * Function      : getYear
     *
     * Description   : Returns the year attribute
     *
     * Parameters    : None
     *
     * Return Value  : Integer representing the year
     *
     *****************************************************************************/
    int getYear();

    /*****************************************************************************
     *
     * Function      : getRegion
     *
     * Description   : Returns the region attribute
     *
     * Parameters    : None
     *
     * Return Value  : String representing the region
     *
     *****************************************************************************/
    string getRegion();

    /*****************************************************************************
     *
     * Function      : getSubRegion
     *
     * Description   : Returns the subRegion attribute
     *
     * Parameters    : None
     *
     * Return Value  : String representing the subRegion
     *
     *****************************************************************************/
    string getSubRegion();

    /*****************************************************************************
     *
     * Function      : getAnimalType
     *
     * Description   : Returns the animalType attribute
     *
     * Parameters    : None
     *
     * Return Value  : String representing the animalType
     *
     *****************************************************************************/
    string getAnimalType();

    /*****************************************************************************
     *
     * Function      : getNumFarms
     *
     * Description   : Returns the numFarms attribute
     *
     * Parameters    : None
     *
     * Return Value  : Integer representing the numFarms
     *
     *****************************************************************************/
    int getNumFarms();

    /*****************************************************************************
     *
     * Function      : getNumAnimals
     *
     * Description   : Returns the numAnimals attribute
     *
     * Parameters    : None
     *
     * Return Value  : Integer representing the numAnimals
     *
     *****************************************************************************/
    int getNumAnimals();

  private:
    int year;
    string region;
    string subRegion;
    string animalType;
    int numFarms;
    int numAnimals;
};

#endif
