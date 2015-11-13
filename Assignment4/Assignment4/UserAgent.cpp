#include        <cstdlib>
#include        <iostream>
#include        <string>
#include		<regex>

using namespace std;

#include        "Tokenizer.h"
#include        "Location.h"

#include        "LocationList.h"
#include        "LocationIterator.h"
#include        "Agent.h"
#include        "Game.h"

UserAgent::UserAgent(LocationList&	locationList
	) :
	  	Agent(locationList)
	  	{
	  	  cout << "Your name? ";
	  	  getline(cin,agentName_);
	  	}

UserAgent::~UserAgent()
{
	delete(&agentName_);
}

const string&	UserAgent::getName()const
{
	return(agentName_);
}

action_t	UserAgent::getAction(Game& game)
{
	regex left("(([g|G][o|O]?)? ?[leftLEFT]+)");
	regex right("(([g|G][o|O]?)? ?[rightRIGHT]+)");
	regex quit("[quitQUIT]+");
	action_t action;

	string	input;
	while (true)
	{
		cout << "Your choice (left/right/quit)? ";
		getline(cin, input);
		if (input.size() == 0)
		{
			cout << "I'm sorry?\n";
			continue;
		}
		else
		{
			if (regex_match(input, left)) {
				action = GO_LEFT_ACTION;
				break;
			}
			else if (regex_match(input, right)) {
				action = GO_RIGHT_ACTION;
				break;
			}
			else if (regex_match(input, quit)) {
				action = QUIT_ACTION;
				break;
			}
		}
	}
	return action;
}

