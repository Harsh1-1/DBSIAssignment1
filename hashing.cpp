/********************************************************
FILE NAME : hashing.cpp
Description : Declaration of all functions 
********************************************************/

#include"Header.h"

/********************************************************************************
FUNCTION NAME : SplitTable
Return Type : size_t
Purpose : split bucket by adding a new bucket
*********************************************************************************/


size_t SplitTable(hashTable *Table)
{
	Table->table.push_back(Bucket());// add bucket
	Table->min_bucketCount += 1; // increment bucket count
	Table->table[Table->min_bucketCount-1].Mod = (Table->MaxModVal)*2; // double the mod value for that bucket
	Table->table[Table->p].Mod = (Table->MaxModVal)*2; // double the mod valuue for pointing bucket
	return SUCCESS;

}

/********************************************************************************
FUNCTION NAME : InsertRecord
Return Type : size_t
Purpose : Insert Record in hash Table
*********************************************************************************/

size_t InsertRecord(hashTable *Table, Record &temp)
{

	int hash = temp.data % Table->MaxModVal; // gets hash value
	
	#ifdef DEBUG 
	cout<<"Hash is :"<<hash<<'\t'<<"Table size : "<< Table->table.size()<<'\n';	
	#endif
	
	if (hash < Table->MaxModVal)
	{
		#ifdef DEBUG
		cout << "Index Exist in hash Table"<<'\n';
		#endif
		
		if (Table->table[hash].BucketSize - Table->table[hash].records.size() > 0) // if no overflow
		{
			#ifdef DEBUG
			cout<<"Data is"<<temp.data<<'\n';
			cout<<"Bucket Size : "<<Table->table[hash].BucketSize<<'\n';
			cout<<"Total Elements : "<<Table->table[hash].TotalElements<<'\n';
			cout << "Space for Elements in bucket"<<'\n';
			#endif
			
			Table->table[hash].records.push_back(temp); // psuh record
			Table->totalRecords++; // increment total record
			Table->table[hash].TotalElements++; // increment elemensts in buckets
			Table->table[hash].freeBlockIndex++; // increment position of free index
			return SUCCESS;
		}

		else
		{
			#ifdef DEBUG
			cout << "Element to be added in Overflow chain"<<'\n';
			cout<<"Data is "<<temp.data<<'\n';
			#endif
			
			Table->table[hash].overflow.push_back(temp);// add in overflow chain
			Table->table[hash].TotalElements++; // increment total elements
								
			size_t value = SplitTable(Table); // split table
			
			value = ReorganiseRecords(Table); // reorgainse elements in split bucket
		}

	}

	else
		return ERROR;

}

/********************************************************************************
FUNCTION NAME : insert
Return Type : void
Purpose : wrapper function containing insertRecord and CreateRecord function call
*********************************************************************************/

void insert(hashTable *Table,int data)
{
	Record record = CreateRecord(data); //create record
	size_t val = InsertRecord(Table, record); // insert the record
}

/*************************************************
FUNCTION NAME : ReorganiseRecords
Return Type : size_t
Purpose : orgainse records after bucket split

*************************************************/


size_t ReorganiseRecords(hashTable *Table)
{
	size_t pointer = Table->p; //get index of bucket to split

	if (pointer >= Table->table.size()) // if pointer > table size then error occured
		return ERROR;
	
	#ifdef DEBUG
	cout<<"Inside Reorganise"<<'\n';
	#endif
	
	vector<Record>elements(Table->table[pointer].records); // copy elements in a separate vector
	
	#ifdef DEBUG
	for(int i = 0;  i < elements.size();i++)
		cout<<"Element is : "<<elements[i].data<<'\t';
	#endif
	Table->table[pointer].records.erase(Table->table[pointer].records.begin(), Table->table[pointer].records.end());//erase element from bucket

	//check for elemennts in overflow bucket
	if (Table->table[pointer].overflow.size() == 0);

	else
	{
		int i = 0;
		while (i < Table->table[pointer].overflow.size())
		{
			elements.push_back(Table->table[pointer].overflow[i]);
			i++;
		}
	}
	Table->table[pointer].overflow.erase(Table->table[pointer].overflow.begin(), Table->table[pointer].overflow.end());// erase elemst from overflow chain

	//cout<<"Debug : split row  & Mod Val "<<Table->p<<'\t'<<Table->MaxModVal<<'\n';
		
	Table->table[pointer].TotalElements = 0;
	Table->table[pointer].freeBlockIndex = 0;

	#ifdef DEBUG
	for(int i =0 ; i< elements.size();i++)
	{
		cout<<"elements in vector : "<<elements[i].data<<'\t';
	}
	#endif

	size_t MOD = Table->table[pointer].Mod;

	#ifdef DEBUG
	cout<<"MOD value "<<MOD<<'\n';
	#endif
	
		
	Table->p = (Table->p + 1)%(Table->MaxModVal);	//increment split pointer 
	
	if(Table->p == 0)
		Table->MaxModVal *= 2; // increment table mod if value is reset
	
	for (int i = 0; i < elements.size(); i++)
	{
		size_t hash = elements[i].data % MOD; // calculate hash
		
		#ifdef DEBUG
		cout<<"Hash is "<<hash<<'\n';
		cout<<"Table size"<<elements.size()<<'\n';
		#endif
		
		if(hash > Table->table.size())
			return ERROR;
		
		else
		{
			
			if(Table->table[hash].BucketSize - Table->table[hash].records.size() > 0) // if no overflow
			{
				cout<<"Elements is "<<elements[i].data<<'\n';
				Table->table[hash].records.push_back(elements[i]);
				Table->table[hash].TotalElements++;
				Table->table[hash].freeBlockIndex++;
			}
			
			else
			{
				
				Table->table[hash].overflow.push_back(elements[i]);
				Table->table[hash].TotalElements++;
							
			}
	}

	}	
	return SUCCESS;

}
