/***************************************************************************
 ****									****
 ****		Game.cpp						****
 ****									****
 ****	    This file defines a class that represents a game.		****
 ****									****
 ****	****	****	****	****	****	****	****	****	****
 ****									****
 ****	Version 1.0		2015 October 28		Joseph Phillips	****
 ****									****
 ***************************************************************************/

#include	<cstdlib>
#include	<iostream>
#include	<string>

using namespace std;

#include	"Tokenizer.h"
#include	"Location.h"
#include	"LocationList.h"
#include	"LocationIterator.h"
#include	"Agent.h"
#include	"Game.h"

#define		GAME_TOKEN		"game"
#define		LOCATION_LIST_TOKEN	"locationList"
#define		LOCATION_TOKEN		"location"
#define		BEGIN_DESCRIPTION	"("
#define		END_DESCRIPTION		")"
#define		ITEM_SEPARATOR		","


//  PURPOSE:  To consume token 'token' from 'tokenizer', or to complain to the
//	user that it was not given and 'exit()' the program returning
//  	'EXIT_FAILURE'.  No return value.
void		consumeToken	(const char*	tokenCPtr,
				 Tokenizer&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Consume 'tokenCPtr' from 'tokenizer':
  if  ( !tokenizer.didReadToken(tokenCPtr) )
  {
    cerr << "Expected " << tokenCPtr
	 << " at " << tokenizer.currentLocationStr()
	 << endl;
    exit(EXIT_FAILURE);
  }

  //  III.  Finished:
}


//  PURPOSE:  To consume a string from 'tokenizer' and place it in 'str', or to
//	complain to the user that it was not given and 'exit()' the program
//	returning 'EXIT_FAILURE'.  No return value.
void		consumeString	(string&	str,
				 Tokenizer&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Consume 'tokenCPtr' from 'tokenizer':
  if  ( !tokenizer.didReadString(str) )
  {
    cerr << "Expected a quoted string at " << tokenizer.currentLocationStr()
	 << endl;
    exit(EXIT_FAILURE);
  }

  //  III.  Finished:
}


//  PURPOSE:  To read the rest of a Location description from 'tokenizer'
//	(given that the 'LOCATION_TOKEN' has already be read), and place it
//	in '*this' Game.  No return value.
void		Game::parseRestOfLocation
				(Tokenizer&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Parse rest of Location:
  string	name;
  string	description;

  consumeToken(BEGIN_DESCRIPTION,tokenizer);
  consumeString(name,tokenizer);
  consumeToken(ITEM_SEPARATOR,tokenizer);
  consumeString(description,tokenizer);
  consumeToken(END_DESCRIPTION,tokenizer);
  addLocation(new Location(name,description));

  //  III.  Finished:
}


//  PURPOSE:  To read the list of locations from 'tokenizer' and place them in
//	'*this' Game.  No return value.
void		Game::parseLocationList
				(Tokenizer&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Location list game:
  consumeToken(LOCATION_LIST_TOKEN,tokenizer);
  consumeToken(BEGIN_DESCRIPTION,tokenizer);

  while  ( tokenizer.didReadToken(LOCATION_TOKEN) )
    parseRestOfLocation(tokenizer);

  consumeToken(END_DESCRIPTION,tokenizer);

  //  III.  Finished:
}


//  PURPOSE:  To read the definitions of a game from 'tokenizer'.  No return
//	value.
void		Game::parseGame	(Tokenizer&	tokenizer
				)
{
  //  I.  Application validity check:

  //  II.  Parse game:
  consumeToken(GAME_TOKEN,tokenizer);
  consumeToken(BEGIN_DESCRIPTION,tokenizer);
  parseLocationList(tokenizer);
  consumeToken(END_DESCRIPTION,tokenizer);

  //  III.  Finished:
}


//  PURPOSE:  To read the definition of a game from 'filename'.  No return
//  	value.
Game::Game			(const string&	filename
				)
{
  //  I.  Application validity check:

  //  II.  Attempt to parse game definition:
  //  II.A.  Initialize 'locationList_':
  Tokenizer	tokenizer(filename);

  parseGame(tokenizer);

  //  II.B.  Initialize 'playerPtrArray_':
  playerPtrArray_[0]	= new UserAgent(locationList_);
  playerPtrArray_[1]	= new AutonomousAgent(locationList_);

  //  III.  Finished:
}


//  PURPOSE:  To release the resources of '*this'.  No parameters.  No return 
//  	value.
Game::~Game		()
{
  //  I.  Application validity check:

  //  II.  Release resources:
  for  (int i = NUM_PLAYERS-1;  i >= 0;  i--)
    delete(playerPtrArray_[i]);

  //  III.  Finished:
}


//  PURPOSE:  To have the user play '*this' game.  No parameters.  No return
//  	value.
void	Game::play	()
{
  //  I.  Application validity check:

  //  II.  Play game:
  bool	shouldPlay	= true;

  cout << endl;

  while  ( shouldPlay )
  {

    for  (int i = 0;  (i < NUM_PLAYERS) && shouldPlay;  i++)
    {
      Agent*	playerPtr	= playerPtrArray_[i];

      switch  ( playerPtr->getAction(*this) )
      {
      case GO_LEFT_ACTION :
      	playerPtr->goBack();
	cout << playerPtr->getName() << " is now at "
	     << playerPtr->getLocationName() << endl
	     << endl;
	break;

      case GO_RIGHT_ACTION :
      	playerPtr->goForward();
	cout << playerPtr->getName() << " is now at "
	     << playerPtr->getLocationName() << endl
	     << endl;
	break;

      case QUIT_ACTION :
	shouldPlay = false;
	break;
      }

    }

  }

  //  III.  Finished:
}
