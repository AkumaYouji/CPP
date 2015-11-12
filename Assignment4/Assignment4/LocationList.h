class	LocationItem
{
public :
  //  PURPOSE:  To initialize '*this' to note that 'newLocationPtr' is the
  //	address of the Location instance it is supposed to hold, 'newPrev'
  //	is the address of the previous LocationItem instance in the linked
  //	list, and 'newNext' is the address of the previous LocationItem
  //	instance in the linked list.  '*this' becomes the owner of the Location
  //	at 'newLocationPtr', and so therefore must 'delete()' it.  No return
  //	value.
  LocationItem	(Location*	newLocationPtr,
		 LocationItem*	newPrev,
		 LocationItem*	newNext
		);

  //  PURPOSE:  To release the resources of '*this'.  No parameter.  No return
  //	value.
  ~LocationItem	();

  //  V.  Accessors:
  //  PURPOSE:  To return the address of the Location instance.
  Location*	getLocationPtr	()
				const;

  //  PURPOSE:  To return the address of the next LocationItem in a list.
  LocationItem*	getNext		()
				const;

  //  PURPOSE:  To return the address of the previous LocationItem in a list.
  LocationItem*	getPrevious	()
				const;

  //  VI.  Mutators:
  //  PURPOSE:  To note that 'newPrev' is now comes before '*this'.  No return
  //	value.
  void		setPrevious	(LocationItem*	newPrev
				);

  //  PURPOSE:  To note that 'newNext' is now comes after '*this'.  No return
  //	value.
  void		setNext		(LocationItem*	newNext
				);
};


class	LocationList
{
public :
  //  PURPOSE:  To initialize '*this' to an empty list.  No parameters.  No
  //  	return value.
  LocationList			();

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  	value.
  ~LocationList			();

  //  V.  Accessors:
  //  PURPOSE:  To return the address of the first item in '*this' list.
  LocationItem*	getFirstPtr	()
				const;

  //  PURPOSE:  To return the address of the last item in '*this' list.
  LocationItem*	getLastPtr	()
				const;

  //  PURPOSE:  To return the count of the number of location instances in
  //	'*this' list.
  int		getCount	()
				const;

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc. work of class:
  //  PURPOSE:  To place 'newLocPtr' at the end of '*this' list and increments
  //	the count of items.  No return value.
  void		addBack		(Location*	newLocPtr
				);
};
