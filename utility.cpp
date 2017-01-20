/********************************************************
FILE NAME : utility.cpp
Description : declaration of utiity function
********************************************************/

#include"Header.h"



/*************************************************
FUNCTION NAME : CreateRecord
Return Type : Record
Purpose : create Record

**************************************************/
Record CreateRecord(int data)
{
	Record temp ;
	temp.data = data;

	return temp;
}


/*************************************************
FUNCTION NAME : printHashTable
Return Type : void
Purpose : print table

**************************************************/
void printHashTable(hashTable *Table)
{
	int i = 0;
	
	cout<<"\n*************************\n";
	//cout<<"Table size"<<Table->table.size()<<'\n';
	while (i < Table->table.size())
	{

		cout << "Value of index :" << i<<'\n';
		cout<<"Data points : ";
		for (vector<Record>::iterator it = Table->table[i].records.begin(); it < Table->table[i].records.end(); it++)
		{
			cout << (*it).data << '\t';
		}
		cout<<'\n' << "Overflow chain : ";
		for (vector<Record>::iterator it = Table->table[i].overflow.begin(); it < Table->table[i].overflow.end(); it++)
		{
			cout << (*it).data << '\t';
		}
		cout << '\n';
		cout<<"\n*************************\n";
		i++;
	}
	cout<<'\n';
}
