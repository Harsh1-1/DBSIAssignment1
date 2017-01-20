#include"Header.h"

int main()
{
	hashTable Table(2);

	int arr[] = { 1,2,3,5,8,13,21,34,55 };
	
	for (int i = 0; i < 9; i++)
	{	insert(&Table, arr[i]);
		cout<<"Array Value :" <<arr[i]<<'\n';
		printHashTable(&Table);
	}
}

