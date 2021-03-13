#include "multiMapIterator.h"
#include "multiMap.h"
MultiMapIterator::MultiMapIterator(const MultiMap& multiMap):mm(multiMap)
{
	this->cKey = multiMap.head;
	if (this->cKey != NULL)
		this->cValue = this->cKey->firstValue;
}//theta(1)
void MultiMapIterator::first()
{
	this->cKey = this->mm.head;
	if (this->cKey != NULL)
		this->cValue = this->cKey->firstValue;

}//theta(1)
void MultiMapIterator::next()
{
	if (valid())
	{
		this->cValue = this->cValue->next;
		if (this->cValue == NULL)
		{
			this->cKey = this->cKey->nextK;
			if(this->cKey!=NULL)
				this->cValue = this->cKey->firstValue;
		}
	}
	else
		throw;
}//theta(1)
bool MultiMapIterator::valid()
{
	if (this->cKey == NULL)
		return false;
	else
		return true;
}//theta(1)
TElem MultiMapIterator::getCurrent()
{
	if (!valid())
		throw;
	TKey k = this->cKey->k;
	TValue v = this->cValue->info;
	TElem e;
	e.first = k;
	e.second = v;
	return e;

}