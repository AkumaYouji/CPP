class	LocationIterator
{
  //  I.  Member variables:
  //  PURPOSE:  To refer to the list over which we will iterate.
  LocationList&			list_;

  //  PURPOSE:  To point to the current LocationItem.
  LocationItem*			itemPtr_;

public :
  //  PURPOSE:  To initialize '*this' to remember that it iterates over list
  //	'newList', and to start at 'getFirstPtr()' of list 'newList'.  No
  //	return value.
	LocationIterator(LocationList&		newList);

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  	value.
  ~LocationIterator();
				

  //  V.  Accessors:

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc work of class:
  //  PURPOSE:  To return a pointer to the current Location, or 'NULL' if the
  //  	list is empty.  No parameters.
  Location*	getLocationPtr()
	  const;
  


  //  PURPOSE:  To make '*this' iterator go back.  Wraps around to end if
  //	already at the beginning.  Takes no action if the list is empty.
  //	No return value.
  void		goBack		();

  //  PURPOSE:  To make '*this' iterator go forward.  Wraps around to 
  //	beginning if already at the end.  Takes no action if the list is empty.
  //	No return value.
  void		goForward	();
};
