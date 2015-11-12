/***************************************************************************
 ****									****
 ****		Game.h							****
 ****									****
 ****	    This file declares a class that represents a game.		****
 ****									****
 ****	****	****	****	****	****	****	****	****	****
 ****									****
 ****	Version 2.0		2015 October 28		Joseph Phillips	****
 ****									****
 ***************************************************************************/

//  PURPOSE:  To tell the number of players.
const int	NUM_PLAYERS	= 2;


class	Game
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the Location instances of '*this' Game.
  LocationList			locationList_;

  //  PURPOSE:  To hold pointers to the players.
  Agent*			playerPtrArray_[NUM_PLAYERS];

  //  II.  Disallowed auto-generated methods:
  //  No default constructor:
  Game				();

  //  No copy constructor:
  Game				(const Game&	source
				);

protected :
  //  III.  Protected methods:
  //  PURPOSE:  To add location '*newLocPtr' to the end of 'locationList_'.
  //  	No return value.
  void		addLocation	(Location*	newLocPtr
				)
				{
				  locationList_.addBack(newLocPtr);
				}

  //  PURPOSE:  To read the rest of a Location description from 'tokenizer'
  //	(given that the 'LOCATION_TOKEN' has already be read), and place it
  //	in '*this' Game.  No return value.
  void		parseRestOfLocation
				(Tokenizer&	tokenizer
				);

  //  PURPOSE:  To read the list of locations from 'tokenizer' and place them
  //	in '*this' Game.  No return value.
  void		parseLocationList
				(Tokenizer&	tokenizer
				);

  //  PURPOSE:  To read the definitions of a game from 'tokenizer'.  No return
  //  	value.
  void		parseGame	(Tokenizer&	tokenizer
				);

  //  PURPOSE:  To return an 'action_t' value the represents the desired action
  //  	of the user.  No parameters.
  action_t	getAction	();

public :
  //  IV.  Constructor(s), assignment op(s), factory(s), and destructor:
  //  PURPOSE:  To read the definition of a game from 'filename'.  No return
  //  	value.
  Game				(const string&	filename
				);

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return 
  //  	value.
  ~Game				();

  //  PURPOSE:  To have the user play '*this' game.  No parameters.  No return
  //  	value.
  void		play		();

};
