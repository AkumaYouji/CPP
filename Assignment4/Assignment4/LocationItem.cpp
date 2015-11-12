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


LocationItem::LocationItem(Location*	newLocationPtr, LocationItem*	newPrev, LocationItem*	newNext
	) : location_(newLocationPtr), prev_(newPrev),next_(newNext)
	{}

LocationItem::~LocationItem()
{
	delete(location_);
	delete(prev_);
	delete(next_);
}

Location*	LocationItem::getLocationPtr() const 
{
	return(location_);
}

LocationItem*	LocationItem::getNext() const
{
	return(next_);
}

LocationItem*	LocationItem::getPrevious() const
{
	return(prev_);
}

void	LocationItem::setPrevious(LocationItem* newPrev)
{
	prev_ = newPrev;
}

void	LocationItem::setNext(LocationItem* newNext)
{
	next_ = newNext;
}