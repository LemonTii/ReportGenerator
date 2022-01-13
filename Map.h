#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Record.h"

/*****************************************************************************
 *
 * Class         : Map
 *
 * Description   : A collection class for Records organized by given keys
 *
 *****************************************************************************/
template<class T>
class Map
{
  public:
    /*****************************************************************************
     *
     * Constructor   : Map
     *
     * Description   : Initializes an object of Map type
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    Map();

    /*****************************************************************************
     *
     * Destructor    : ~Map
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    ~Map();

    /*****************************************************************************
     *
     * Function      : add
     *
     * Description   : Adds a given Record to the given key
     *
     * Parameters    : INPUT => T         The key
     *                 INPUT => Record*   The value to add
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void add(T, Record*);

    /*****************************************************************************
     *
     * Function      : operator[]
     *
     * Description   : Allows user to index a key to obtain a value
     *
     * Parameters    : INPUT => T  The key
     *
     * Return Value  : Reference to the vector of Record* at the given key
     *
     *****************************************************************************/
    vector<Record*>&  operator[](T);

    /*****************************************************************************
     *
     * Function      : getKeys
     *
     * Description   : Returns all keys that exist in this map
     *
     * Parameters    : OUTPUT => vector<T>&   The vector to return all keys to
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void getKeys(vector<T>&);

  private:
    vector<T> keys;
    vector<vector<Record*>*> values;

    /*****************************************************************************
     *
     * Function      : keyToIndex
     *
     * Description   : Finds the index of where the key is located in the keys vector
     *
     * Parameters    : INPUT => T  The key
     *
     * Return Value  : Integer representing the index
     *
     *****************************************************************************/
    int keyToIndex(T);
};

template <class T>
Map<T>::Map()
{

}

template <class T>
Map<T>::~Map()
{
  int i = 0;

  for(i=0; i<values.size(); ++i)
  {
    delete values.at(i);
  }
}

template <class T>
vector<Record*>& Map<T>::operator[](T key)
{
  int index = keyToIndex(key);

  if(index < 0)
  {
    throw runtime_error("Index does not exist!");
  }

  return *(values.at(index));
}

template <class T>
void Map<T>::add(T key, Record* value)
{
  int index = keyToIndex(key);

  if(index < 0)
  {
    vector<Record*>* v = new vector<Record*>;
    v->push_back(value);

    keys.push_back(key);
    values.push_back(v);
  }
  else
  {
    values.at(index)->push_back(value);
  }
}

template <class T>
int Map<T>::keyToIndex(T key)
{
  int i = 0;

  for(i=0; i<keys.size(); ++i)
  {
    if(keys.at(i) == key)
    {
      return i;
    }
  }

  return -1;
}

template <class T>
void Map<T>::getKeys(vector<T>& k)
{
  k = keys;
}

#endif
