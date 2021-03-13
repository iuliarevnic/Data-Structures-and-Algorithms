#include "multiMap.h"
#include "multiMapIterator.h"
//constructor
MultiMap::MultiMap() { this->length = 0; this->head = NULL; }
//adds a key value pair to the multimap
void MultiMap::add(TKey c, TValue v)
{
	KNode* currentNode = this->head;
	while (currentNode != NULL && currentNode->k != c)
		currentNode = currentNode->nextK;
	if (currentNode != NULL)
	{
		VNode *newNode = new VNode;
		newNode->info = v;
		newNode->next = currentNode->firstValue;
		currentNode->firstValue = newNode;

		this->length++;
	}
	else
	{
		KNode* newNode = new KNode;
		newNode->k = c;
		newNode->nextK = this->head;
		VNode* valueNode = new VNode;
		valueNode->info = v;
		valueNode->next = NULL;
		newNode->firstValue = valueNode;
		head = newNode;
		this->length++;

	}
}//O(n)
//removes a key value pair from the multimap

//returns true if the pair was removed (if it was in the multimap) and false otherwise
bool MultiMap::remove(TKey c, TValue v)
{
	KNode* currentNode = this->head;
	KNode* prevNode = NULL;
	while (currentNode != NULL && currentNode->k != c){
		prevNode = currentNode;
		currentNode = currentNode->nextK;
}
	if (currentNode == NULL)
		return false;
	else
	{
		VNode* currentValue = currentNode->firstValue;
		VNode* prevValue = NULL;
		while (currentValue != NULL && currentValue->info!=v)
		{
			prevValue = currentValue;
			currentValue = currentValue->next;
		}
		if (currentValue == NULL)
			return false;
		else
		{
			//deci sa sterg valoarea si daca e goala lista sa sterg nodul, sa verific daca e primul nod(head)
			if (prevValue != NULL) {
				prevValue->next = currentValue->next;
				currentValue->next = NULL;
			}
			else {
				currentNode->firstValue = currentNode->firstValue->next;
			}
			if (currentNode->firstValue == NULL)
			{
					if (prevNode != NULL) {
						prevNode->nextK = currentNode->nextK;
						currentNode->nextK = NULL;
					}
					else
					{
						this->head = this->head->nextK;
					}
			}
			
			this->length--;
			return true;
		}
	}
}//O(m), where m is the total number of elements
//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
vector<TValue> MultiMap::search(TKey c) const
{
	KNode* currentNode = this->head;
	vector<TValue> myVector;
	while (currentNode != NULL && currentNode->k != c)
		currentNode = currentNode->nextK;
	if (currentNode == NULL)
		return myVector;
	else
	{
		VNode* currentValue=currentNode->firstValue;
		while (currentValue != NULL)
		{
			myVector.push_back(currentValue->info);
			currentValue = currentValue->next;
		}
		return myVector;


	}
}//O(n), where n is the number of nodes plus the maximum number of values in one node
//returns the number of pairs from the multimap
int MultiMap::size() const
{
	return this->length;
}//theta(1)
//checks whether the multimap is empty
bool MultiMap::isEmpty() const
{
	if (size() == 0)
		return true;
	else
		return false;
}//theta(1)
//returns an iterator for the multimap
MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator(*this);
}//theta(1)
//descturctor
MultiMap::~MultiMap()
{
	KNode* currentKey = this->head;
	while (currentKey != NULL)
	{
		VNode* currentValue = currentKey->firstValue;
		while (currentValue != NULL)
		{
			VNode* auxiliary = currentValue;
			currentValue = currentValue->next;
			delete auxiliary;
			
		}
		KNode* auxiliaryKey = currentKey;
		currentKey = currentKey->nextK;
		delete auxiliaryKey;
		
	}
}//O(n), n sum of keys and values

 //returns a vector with all the keys from the MultiMap
vector<TKey> MultiMap::keySet() const
{
	vector<TKey> keys;
	KNode* currentKey = this->head;
	while (currentKey != NULL)
	{
		keys.push_back(currentKey->k);
		currentKey = currentKey->nextK;
	}
	return keys;
}//O(n) where n is number of keys