#include        <cstdlib>
#include        <iostream>
#include        <string>

using namespace std;

#include        "Tokenizer.h"
#include        "Location.h"

#include        "LocationList.h"
#include        "LocationIterator.h"
#include        "Agent.h"
#include        "Game.h"

LocationList::LocationList()
{
	startPtr_ = NULL;
	endPtr_ = NULL;
	length_ = 0;
}

LocationList::~LocationList()
{
	delete(startPtr_);
	delete(endPtr_);
	delete(&length_);
}

LocationItem*	LocationList::getFirstPtr() const
{
	return(startPtr_);
}

LocationItem*	LocationList::getLastPtr() const
{
	return(endPtr_);
}

int	LocationList::getCount() const
{
	return(length_);
}

void LocationList::addBack(Location* newLocPtr)
{
	LocationItem* newLocItemPtr = new LocationItem(newLocPtr);
	LocationItem* temp;

	if (length_ == 0)//if its the first item in the list set up the loopback
	{
		startPtr_ = newLocItemPtr;
		endPtr_ = newLocItemPtr;
		
		//set startPtr's next and previous
		startPtr_->setNext(endPtr_);
		startPtr_->setPrevious(endPtr_);
		
		//set endPtr's next and previous
		endPtr_->setNext(startPtr_);
		endPtr_->setPrevious(startPtr_);
	} else { 
		//save the old end to update refereneces 
		temp = endPtr_;
		
		//asign the new itemlist to the end
		endPtr_ = newLocItemPtr;
		
	//set the previous endPtr_'s next to the new end
		temp->setNext(endPtr_);

		//establish a looped link with the end and beginning and link it to previous
		endPtr_->setNext(startPtr_);
		endPtr_->setPrevious(temp);
	}
	


	length_++;
}