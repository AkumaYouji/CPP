#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#include        "Location.h"

 Location::Location(const string& newName, const string& newDescription)
{
	Location::locationName_ = newName;
	Location::locationDescription_ = newDescription;
}

Location::~Location()
{
	cout << "Now destroying " << getName() << endl;
}
