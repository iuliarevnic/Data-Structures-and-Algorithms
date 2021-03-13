#include "ShortTest.h"
#include "ExtendedTest.h"
#include "multiMap.h"
#include <iostream>
int main()
{
	testAll();
	testAllExtended();
	MultiMap mm;
	mm.add(1, 10);
	mm.add(1, 6);
	mm.add(2, 8);
	cout << mm.size() << endl;
	vector<TKey> keys = mm.keySet();
	for(int i=0;i<keys.size();i++)
		cout << keys[i] << endl;
	system("pause");
}