/***************************************************************************
 ****									****
 ****		Agent.h							****
 ****									****
 ****	    This file declares class(es) that implement the		****
 ****	functionality of agents in a game.				****
 ****									****
 ****	****	****	****	****	****	****	****	****	****
 ****									****
 ****	Version 1.0		2015 October 28		Joseph Phillips	****
 ****									****
 ***************************************************************************/

//  PURPOSE:  To represent the actions that the user can take.
typedef	enum	{
		  GO_LEFT_ACTION,
		  GO_RIGHT_ACTION,
		  QUIT_ACTION
		}
		action_t;


class		Game;


class		Agent
{
  //  I.  Member variables:
  //  PURPOSE:  To keep track of where the Agent is in the LocationList.
  LocationIterator		iterator_;


public :
  //  PURPOSE:  To initialize '*this' Agent to go through the Location
  //	instances of 'locationList'.  No return value.
  Agent				(LocationList&	locationList
				) :
				iterator_(locationList)
				{ }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  	value.
  virtual
  ~Agent			()
				{ }

  //  V.  Accessors:
  //  PURPOSE:  To return the name of '*this' Agent.  No parameters.
  virtual
  const string&	getName		()
				const
				= 0;

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc. work of class:
  //  PURPOSE:  To return the action that '*this' Agent chooses.  No
  //	parameters.
  virtual
  action_t	getAction	(Game&		game
  				)
				= 0;

  //  PURPOSE:  To take the action of going back.  No parameters.  No return
  //	value.
  void		goBack		()
  {
    iterator_.goBack();
  }
	
  //  PURPOSE:  To take the action of going forward.  No parameters.  No return
  //	value.
  void		goForward	();

  //  PURPOSE:  To return the name of the Location of '*this' Agent.  No
  //	parameters.
  const string&	getLocationName	()
				const;

  //  PURPOSE:  To return the description of the Location of '*this' Agent.  No
  //	parameters.
  const string&	getLocationDescription
				()
				const;
};



class	UserAgent : public Agent
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the name of the agent.
  string			agentName_;

public :
  //  PURPOSE:  To initialize '*this' Agent to go through the Location
  //	instances of 'locationList'.  Also, asks the user for their name.
  //	No return value.
	UserAgent(LocationList&	locationList
		);// :
			//	Agent(locationList)
			//	{
				  //  MOVE THIS TO CPP FILE!
			//	  cout >> "Your name? ";
			//	  getline(cin,agentName_);
			//	}

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  	value.
  ~UserAgent			();

  //  V.  Accessors:
  //  PURPOSE:  To return the name of '*this' Agent.  No parameters.
  const string&	getName		()
				const;

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc. work of class:
  //  PURPOSE:  To tell the user the name and description of the Location
  //  	where they are, get their action, and return the corresponding
  //	action_t value.  The parameter 'game' is ignored for now.
  action_t	getAction	(Game&		game
  				);

};


class		AutonomousAgent
{

public :
  //  PURPOSE:  To initialize '*this' Agent to go through the Location
  //	instances of 'locationList'.  No return value.
  AutonomousAgent		(LocationList&	locationList
				);

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //  	value.
  ~AutonomousAgent		();

  //  V.  Accessors:
  //  PURPOSE:  To return the name of '*this' Agent.  No parameters.
  const string&	getName		()
				const;
  //  Implement with:
  //  static string	name__("Mr. Blue Demon");
  //
  //  return(name__);
  //  Of course, you may change the name if you want.  Nothing obscene, please.


  //  VI.  Mutators:

  //  VII.  Methods that do main and misc. work of class:
  //  PURPOSE:  To tell the user the name and description of the Location
  //  	where they are, get their action, and return the corresponding
  //	action_t value.  The parameter 'game' is ignored for now.
  action_t	getAction	(Game&		game
				);
  //  Implement with:
  //  if  ( (rand() % 2) == 0 )
  //  {
  //    cout << getName() << " chooses to go left." << endl;
  //    return(GO_LEFT_ACTION);
  //  }
  //  else
  //  {
  //    cout << getName() << " chooses to go right." << endl;
  //    return(GO_RIGHT_ACTION);
  //  }
};
