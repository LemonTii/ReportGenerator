#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <vector>
#include <iterator>
#include "CompareBehaviour.h"

/*****************************************************************************
 *
 * Class         : ReportData
 *
 * Description   : Holds information of Reports
 *
 *****************************************************************************/
template<class T>
class ReportData
{
  /*****************************************************************************
   *
   * Function      : operator<<
   *
   * Description   : Insertion operator for ReportData types into ostream
   *
   * Parameters    : OUTPUT => ostream&         The ostream to insert to
   *                 INPUT  => ReportData<U>&   The ReportData being inserted
   *
   * Return Value  : ostream reference to the ostream that the function added to
   *
   *****************************************************************************/
  template <class U>
  friend ostream& operator<<(ostream&, const ReportData<U>&);

  /*****************************************************************************
   *
   * Class         : ReportRow
   *
   * Description   : Holds information of one row of a Report
   *
   *****************************************************************************/
  template<class V>
  class ReportRow
  {
    public:
      /*****************************************************************************
       *
       * Constructor   : ReportRow
       *
       * Description   : Initializes an object of ReportRow type
       *
       * Parameters    : INPUT => V         The key used to sort the rows
       *                 INPUT => string    The actual row of the report
       *
       * Return Value  : None
       *
       *****************************************************************************/
      ReportRow(V k, string r)
      :key(k), report(r)
      {

      }

      V key;
      string report;
  };

  public:
    /*****************************************************************************
     *
     * Constructor   : ReportData
     *
     * Description   : Initializes an object of ReportData type
     *
     * Parameters    : INPUT => CompareBehaviour<T>*  Behaviour class of how
     *                                                the rows should be ordered
     *
     * Return Value  : None
     *
     *****************************************************************************/
    ReportData(CompareBehaviour<T>*);

    /*****************************************************************************
     *
     * Destructor    : ~ReportData
     *
     * Description   : Frees all associated memory
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    ~ReportData();

    /*****************************************************************************
     *
     * Function      : add
     *
     * Description   : Adds the given report into its correct place based on given key
     *
     * Parameters    : INPUT => T       Key to use when finding its location
     *                 INPUT => string  row of the report to add
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void add(T key, string row);

    /*****************************************************************************
     *
     * Function      : clear
     *
     * Description   : Clears all reports made within this class
     *
     * Parameters    : None
     *
     * Return Value  : void
     *
     *****************************************************************************/
    void clear();

  private:
    vector<ReportRow<T>*> reports;
    CompareBehaviour<T>* behaviour;
};


template<class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c)
                :behaviour(c)
{

}

template<class T>
ReportData<T>::~ReportData()
{
  int i = 0;

  clear();

  delete behaviour;
}

template<class T>
void ReportData<T>::clear()
{
  int i = 0;

  for(i=0; i<reports.size(); ++i)
  {
    delete reports.at(i);
  }
  reports.clear();
}

template<class T>
void ReportData<T>::add(T key, string row)
{
  ReportRow<T>* r = new ReportRow<T>(key, row);

  typename vector<ReportRow<T>*>::iterator itr;

  for (itr = reports.begin(); itr != reports.end(); ++itr)
  {
    if (!(behaviour->compare((*itr)->key, r->key)))
    {
      reports.insert(itr, r);
      return;
    }
  }

  reports.push_back(r);
}

template<class T>
ostream& operator<<(ostream& output, const ReportData<T>& data)
{
  for (int i=0; i<data.reports.size(); ++i)
  {
    output<<data.reports.at(i)->report<<endl;
  }

  return output;
}

#endif
