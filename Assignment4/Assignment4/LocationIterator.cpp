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

LocationIterator::LocationIterator(LocationList&		newList
) :
	list_(newList),
	itemPtr_(newList.getFirstPtr())
{ }

LocationIterator::~LocationIterator()
{
	delete(&list_);
	delete(itemPtr_);
}

Location*	LocationIterator::getLocationPtr() const
{
	return(itemPtr_->getLocationPtr());
}

void LocationIterator::goBack()
{
	itemPtr_ = itemPtr_->getPrevious();
	 
}

void LocationIterator::goForward()
{
	itemPtr_ = itemPtr_->getNext();

}