/***************************************************************************
 ****									****
 ****		Tokenizer.cpp						****
 ****									****
 ****	    This file defines a very simple tokenizing class.		****
 ****									****
 ****	****	****	****	****	****	****	****	****	****
 ****									****
 ****	Version 1.0		2015 October 26		Joseph Phillips	****
 ****									****
 ***************************************************************************/

#include	<cstdlib>
#include	<iostream>
#include	<fstream>
#include	<string>
#include	<sstream>
#include	<cctype>

using namespace	std;

#include	"Tokenizer.h"

const char	QUOTE_CHAR	= (char)34;

//  PURPOSE:  To return the current char.  No parameters.
char		Tokenizer::currentC
				()
{
  //  I.  Application validity check:

  //  II.  Attempt to read:
  if  ( stackIndex_ >= 0 )
    return(stack_[stackIndex_]);

  if  ( (currentLineIndex_ >= currentLine_.length())  &&  !didAdvanceC() )
    return('\0');

  //  III.  Finished:
  return(currentLine_[currentLineIndex_]);
}


//  PURPOSE:  To attempt to advance to the next char.  No parameters.
//	Returns 'true' if did advance to next char or 'false' otherwise
//	(e.g. because already at end).
bool		Tokenizer::didAdvanceC
				()
{
  //  I.  Application validity check:
  if  ( getIsAtEnd() )
    return(false);

  //  II.  Attempt to read:
  if  ( stackIndex_ >= 0 )
  {
    stackIndex_--;
    return(true);
  }

  currentLineIndex_++;

  while  ( currentLineIndex_ >= currentLine_.length() )
  {
    if  ( getline(*inputPtr_,currentLine_) )
    {
      currentLineIndex_	= 0;
      lineNum_++;
    }
    else
    {
      isAtEof_	= true;
      return(false);
    }
  }

  //  III.  Finished:
  return(true);
}


//  PURPOSE:  To initialize '*this' to attempt to read from the file with
//	path 'newFilePath'.  No return value.
Tokenizer::Tokenizer		(const string&		newFilePath
				) :
				filePath_(newFilePath),
				inputPtr_(NULL),
				currentLine_(""),
				currentLineIndex_(0),
				lineNum_(0),
				isAtEof_(false),
				stackIndex_(-1)
{
  //  I.  Application validity check:

  //  II.  Attempt to initialize member vars:
  //  II.A.  Attempt to initialize 'inputPtr_':
  inputPtr_ = new ifstream(getFilePath().c_str(),std::ifstream::in);

  if  ( !inputPtr_->is_open() )
  {
    cerr << "Error openning " << getFilePath() << endl;
    exit(EXIT_FAILURE);
  }

  //  III.  Finished:
}


//  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
//	value.
Tokenizer::~Tokenizer		()
{
  //  I.  Application validity check:

  //  II.   Release resources:
  delete(inputPtr_);

  //  III.  Finished:
}


//  PURPOSE:  To read the token 'tokenStr' from the input stream.  Either
//	reads and consumes it and returns 'true', or returns 'false'.
bool		Tokenizer::didReadToken
				(const string&	tokenStr
				)
{
  //  I.  Application validity check:

  //  II.   Attempt to read 'tokenStr':
  char	c;

  //  II.A.  Fast-forward past any spaces:
  while  ( isspace(currentC()) )
    if  ( !didAdvanceC() )
      return(false);

  if  ( getIsAtEnd() )
    return(false);


  //  II.B.  Read chars from file to see if agree with 'tokenStr':
  int		tokenIndex;
  string	readChars("");

  for  ( tokenIndex = 0;
	 tokenIndex < tokenStr.length();
	 tokenIndex++, didAdvanceC()
       )
  {
    if  ( getIsAtEnd() )
      return(false);

    char	c	 = currentC();

    readChars		+= c;

    if  (c != tokenStr[tokenIndex])
    {
      for  (int i = readChars.length()-1;  i >= 0;  i--)
	stack_[++stackIndex_] = readChars[i];

      return(false);
    }
  }

  //  III.  Finished:
  return(true);
}


//  PURPOSE:  To read a quoted string from the input stream.  Either
//	reads and consumes it or outputs an error message and 'exit()'s
//	program with value 'EXIT_FAILURE'.  Returns read string
bool		Tokenizer::didReadString
				(string&	str
				)
{
  //  I.  Application validity check:

  //  II.   Attempt to read 'str':
  char	c;

  //  II.A.  Fast-forward past any spaces:
  for  (c = currentC();  isspace(c);  didAdvanceC());

  if  ( getIsAtEnd() )
    return(false);


  //  II.B.  Read string:
  string	readChars("");

  //  II.B.1.  Read beginning quote:
  if  ( (currentC() != QUOTE_CHAR)  ||  !didAdvanceC() )
    return(false);

  str.clear();

  while  ( (c = currentC()) != QUOTE_CHAR )
  {
    if  ( getIsAtEnd() )
      return(false);

    str += c;

    if  ( !didAdvanceC() )
    {
      for  (int i = readChars.length()-1;  i >= 0;  i--)
	stack_[++stackIndex_] = readChars[i];

      stack_[++stackIndex_]	= QUOTE_CHAR;
      return(false);
    }
  }

  didAdvanceC();	// Go past second quote

  //  III.  Finished:
  return(true);
}


//  PURPOSE:  To read an integer from the input stream.  Either
//	reads and consumes it or outputs an error message and 'exit()'s
//	program with value 'EXIT_FAILURE'.  Returns read string
//int		Tokenizer::readInt
//				(const string&	tokenStr
//				)
//{
//}


//  PURPOSE:  To return a string description of the current location in
//	'*this' input file path.
string		Tokenizer::currentLocationStr
				()
				const
{
  //  I.  Application validity check:

  //  II.  Compose response:
  stringstream	ss;

  ss << "line " << getLineNum() << " of " << getFilePath();

  //  III.  Finished:
  return(ss.str());
}
