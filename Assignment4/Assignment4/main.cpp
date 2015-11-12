/***************************************************************************
 ****									****
 ****		main.cpp						****
 ****									****
 ****	    This file defines the high-level and misc. functions used	****
 ****	to play the game.						****
 ****									****
 ****	****	****	****	****	****	****	****	****	****
 ****									****
 ****	Version 2.0		2015 October 28		Joseph Phillips	****
 ****									****
 ***************************************************************************/


#include	<cstdlib>
#include	<iostream>
#include	<string>
#include	<sstream>
#include	<cctype>

using namespace	std;

#include	"Tokenizer.h"
#include	"Location.h"
#include	"LocationList.h"
#include	"LocationIterator.h"
#include	"Agent.h"
#include	"Game.h"

int	main	()
{
  string	filePath;

  cout << "Game description file path: ";
  getline(cin,filePath);

  Game		game(filePath);

  game.play();
  return(EXIT_SUCCESS);
}
