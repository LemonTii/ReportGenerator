#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

/*****************************************************************************
 *
 * Class         : CompareBehaviour
 *
 * Description   : Holds information of how two variable types should be compared
 *
 *****************************************************************************/
template<class T>
class CompareBehaviour
{
  public:

    /*****************************************************************************
     *
     * Constructor   : CompareBehaviour
     *
     * Description   : Initializes an object of CompareBehaviour type
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    CompareBehaviour();

    /*****************************************************************************
     *
     * Function      : compare
     *
     * Description   : Compares the two given variables
     *
     * Parameters    : INPUT => T   Variable to compare
     *                 INPUT => T   Variable to compare
     *
     * Return Value  : boolean returning true if the given variables are in the
     *                 correct order, false otherwise
     *
     *****************************************************************************/
    virtual bool compare(T, T) = 0;
};

/*****************************************************************************
 *
 * Class         : AscBehaviour
 *
 * Description   : Holds information of how two variable types should be
 *                 compared for it to be in ascending order
 *
 *****************************************************************************/
template<class U>
class AscBehaviour : public CompareBehaviour<U>
{
  public:

    /*****************************************************************************
     *
     * Constructor   : AscBehaviour
     *
     * Description   : Initializes an object of AscBehaviour type
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    AscBehaviour();

    /*****************************************************************************
     *
     * Function      : compare
     *
     * Description   : Compares the two given variables
     *
     * Parameters    : INPUT => U   Variable to compare
     *                 INPUT => U   Variable to compare
     *
     * Return Value  : boolean returning true if the first variable is less
     *                 than the second, false otherwise
     *
     *****************************************************************************/
    virtual bool compare(U, U);
};

/*****************************************************************************
 *
 * Class         : DescBehaviour
 *
 * Description   : Holds information of how two variable types should be
 *                 compared for it to be in descending order
 *
 *****************************************************************************/
template<class V>
class DescBehaviour : public CompareBehaviour<V>
{
  public:

    /*****************************************************************************
     *
     * Constructor   : DescBehaviour
     *
     * Description   : Initializes an object of DescBehaviour type
     *
     * Parameters    : None
     *
     * Return Value  : None
     *
     *****************************************************************************/
    DescBehaviour();

    /*****************************************************************************
     *
     * Function      : compare
     *
     * Description   : Compares the two given variables
     *
     * Parameters    : INPUT => V   Variable to compare
     *                 INPUT => V   Variable to compare
     *
     * Return Value  : boolean returning true if the first variable is greater
     *                 than the second, false otherwise
     *
     *****************************************************************************/
    virtual bool compare(V, V);
};


template<class T>
CompareBehaviour<T>::CompareBehaviour()
{

}

template<class T>
AscBehaviour<T>::AscBehaviour()
{

}

template<class T>
DescBehaviour<T>::DescBehaviour()
{

}

template<class T>
bool AscBehaviour<T>::compare(T inKey, T addKey)
{
  if(inKey < addKey)
  {
    return true;
  }
  return false;
}

template<class T>
bool DescBehaviour<T>::compare(T inKey, T addKey)
{
  if(inKey > addKey)
  {
    return true;
  }
  return false;
}

#endif
