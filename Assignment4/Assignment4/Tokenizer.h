/***************************************************************************
 ****									****
 ****		Tokenizer.h						****
 ****									****
 ****	    This file declares a very simple tokenizing class.		****
 ****									****
 ****	****	****	****	****	****	****	****	****	****
 ****									****
 ****	Version 1.0		2015 October 26		Joseph Phillips	****
 ****									****
 ***************************************************************************/

const int	MAX_STACK_LEN		= 1024;

class		Tokenizer
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the path of the file.
  string	filePath_;

  //  PURPOSE:  To point to input stream.
  ifstream*	inputPtr_;

  //  PURPOSE:  To hold the most recently read line.
  string	currentLine_;

  //  PURPOSE:  To hold the index of where to read next in 'currentLine_'.
  unsigned long	currentLineIndex_;

  //  PURPOSE:  To keep track of the current line number.
  unsigned long	lineNum_;

  //  PURPOSE:  To tell whether or not '*this' is at the end of the file.
  bool		isAtEof_;

  //  PURPOSE:  To keep track of pushed chars.
  char		stack_[MAX_STACK_LEN];

  //  PURPOSE:  To be the index of the most recently pushed char on the stack,
  //  	or '-1' if the stack is empty.
  int		stackIndex_;

  //  II.  Disallowed auto-generated methods:
  //  No default constructor:
  Tokenizer			();

  //  No copy constructor:
  Tokenizer			(const Tokenizer&	source
				);

  //  No copy assignment op:
  Tokenizer&	operator=	(const Tokenizer&	source
				);

protected :
  //  III.  Protected methods:
  //  PURPOSE:  To return the current char.  No parameters.
  char		currentC	();

  //  PURPOSE:  To attempt to advance to the next char.  No parameters.
  //	Returns 'true' if did advance to next char or 'false' otherwise
  //	(e.g. because already at end).
  bool		didAdvanceC	();

public :
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  //  PURPOSE:  To initialize '*this' to attempt to read from the file with
  //	path 'newFilePath'.  No return value.
  Tokenizer			(const string&		newFilePath
				);

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //	value.
  ~Tokenizer			();

  //  V.  Accessors:
  //  PURPOSE:  To return the path of the file.  No parameters.
  const string&	getFilePath	()
				const
				throw()
				{ return(filePath_); }

  //  PURPOSE: To return the current line number.
  unsigned long	getLineNum	()
				const
				throw()
				{ return(lineNum_); }

  //  PURPOSE:  To tell whether or not '*this' is at the end of the file.
  bool		getIsAtEnd	()
				const
				throw()
				{ return(isAtEof_); }

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc work of class:
  //  PURPOSE:  To read the token 'tokenStr' from the input stream.  Either
  //	reads and consumes it and returns 'true', or returns 'false'.
  bool		didReadToken	(const string&	tokenStr
				);

  //  PURPOSE:  To read a quoted string from the input stream.  Either
  //	reads and consumes it or outputs an error message and 'exit()'s
  //	program with value 'EXIT_FAILURE'.  Returns read string
  bool		didReadString	(string&	str
				);

  //  PURPOSE:  To read an integer from the input stream.  Either
  //	reads and consumes it or outputs an error message and 'exit()'s
  //	program with value 'EXIT_FAILURE'.  Returns read string
  int		readInt		(const string&	tokenStr
				);

  //  PURPOSE:  To return a string description of the current location in
  //	'*this' input file path.
  string	currentLocationStr
				()
				const;

};
