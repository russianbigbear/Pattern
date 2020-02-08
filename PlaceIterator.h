#ifndef _PLACEITERATOR
#define _PLACEITERATOR
#include "Platform.h"
#include <algorithm>

class PlaceIterator : public IIterator<PlacePlatform*>
{
private:
	Platform* collection;
	vector<int> current;

	PlacePlatform* LevelUp();

public:	
	PlaceIterator(Platform* source);

	bool HasNext();
	PlacePlatform* Next();
	vector<PlacePlatform*> SortCollection();
};
#endif