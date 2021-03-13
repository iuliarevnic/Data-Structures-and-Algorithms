#pragma once
#include "multiMap.h"
class MultiMapIterator
{
	friend class MultiMap;

private:
	//contains a reference of the container it iterates over
	const MultiMap& mm;
	KNode* cKey;
	VNode* cValue;
	/* representation specific for the iterator*/
	

	//Constructor receives a reference of the container.

	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

	MultiMapIterator(const MultiMap& map);

public:
	//sets the iterator to the first element of the container
	void first();
	//moves the iterator to the next element

	//throws exception if the iterator is not valid
	void next();
	//checks if the iterator is valid
	bool valid();
	//returns the value of the current element from the iterator

	// throws exception if the iterator is not valid
	TElem getCurrent();


};