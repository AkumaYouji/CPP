#include <cstdlib>
#include <iostream>

//  PURPOSE:  To hold one 'Data' object.
class	Location
{
	std::string		locationName_;

	std::string		locationDescription_;

	
public:
	Location(const std::string& newName, const std::string& newDescription);
	~Location();
	const std::string& getName() const { return(locationName_); }

	const std::string& getDescription() const { return(locationDescription_); }
	
	
	
	private:
		//	II.  Constructor and destructor:
		Location();
		//had to comment out because it was making my public constructor inaccessable
		//Location( const Location& source_var);

};
