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

Agent::Agent(LocationList&	locationList
	) :
	iterator_(locationList)
	{ }

Agent::~Agent()
{
	delete(&iterator_);
}

void Agent::goBack()
{
	iterator_.goBack();
}

void Agent::goForward()
{
	iterator_.goForward();
}

const string&	Agent::getLocationName() const
{
	Location* curLocPtr = iterator_.getLocationPtr();

	return(curLocPtr->getName());
}

const string&	Agent::getLocationDescription() const
{
	Location* curLocPtr = iterator_.getLocationPtr();
	
	return(curLocPtr->getDescription());
}

