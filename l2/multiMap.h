#pragma once
#include<vector>
#include<utility>



using namespace std;


typedef int TKey;

typedef int TValue;

class MultiMapIterator;

typedef std::pair<TKey, TValue> TElem;
struct VNode {
	TValue info;
	VNode* next;
};
struct KNode {
	TKey k;
	VNode* firstValue;
	KNode* nextK;
};


class MultiMap

{

	friend class MultiMapIterator;

private:

	/* representation of the MultiMap */
	KNode* head;
	int length;


public:

	//constructor

	MultiMap();



	//adds a key value pair to the multimap

	void add(TKey c, TValue v);



	//removes a key value pair from the multimap

	//returns true if the pair was removed (if it was in the multimap) and false otherwise

	bool remove(TKey c, TValue v);



	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty

	vector<TValue> search(TKey c) const;


	//returns a vector with all the keys from the MultiMap
	vector<TKey> keySet() const;

	//returns the number of pairs from the multimap

	int size() const;



	//checks whether the multimap is empty

	bool isEmpty() const;



	//returns an iterator for the multimap

	MultiMapIterator iterator() const;



	//descturctor

	~MultiMap();





};



