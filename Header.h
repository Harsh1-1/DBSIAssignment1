/********************************************************
FILE NAME : Header.h
Description : Declaration of all structures and Functions
********************************************************/
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
#include<vector>

using namespace std;

//Number of Records in a bucket
#define MAXSIZE 2

// Return status
#define OVERFLOW 1
#define SUCCESS 0
#define ERROR -1
#define MODVALUE 2

/*****************************************
Structure Name : Record
Purpose : Structure of Record
******************************************/
 struct Record
{
	int data;
};

/******************************************
Structure Name : Bucket
Purpose : collection of Records

*******************************************/
 struct Bucket
{
	vector<Record>records; // data structure to hold records
	size_t BucketSize;	// Bucket Size
	size_t TotalElements; // total records in bucket
	size_t freeBlockIndex; // index of free block
	size_t Mod;	// Mod value of Bucket
	vector<Record>overflow; // structure to hold overflow records

	Bucket() : records(0),BucketSize(MAXSIZE), TotalElements(0), freeBlockIndex(0), Mod(MODVALUE) {} // constructor with initialization
};

/******************************************
Structure Name : hashTable
Purpose : collection of buckets

*******************************************/
 struct hashTable
{
	vector<Bucket>table; // collection of buckets

	size_t min_bucketCount; // buckets in table	
	size_t MaxModVal; // Hash value of Table
	size_t p;	// split pointer pointing to bucket to split
	size_t totalRecords;// total records in table

	hashTable(size_t bucketTotal) : min_bucketCount(bucketTotal), MaxModVal(MODVALUE), p(0), totalRecords(0) {
		table.push_back(Bucket()); table.push_back(Bucket());	
	}

};

/************************************************
FUNCTION DEFINITIONS USED IN PROGRAM
*************************************************/

/*************************************************
FUNCTION NAME : ReorganiseRecords
Return Type : size_t
Purpose : orgainse records after bucket split

*************************************************/
size_t ReorganiseRecords(hashTable *Table);

/********************************************************************************
FUNCTION NAME : insert
Return Type : void
Purpose : wrapper function containing insertRecord and CreateRecord function call
*********************************************************************************/

void insert(hashTable* table, int);

/*************************************************
FUNCTION NAME : printHashTable
Return Type : void
Purpose : print table
****************************************************/

void printHashTable(hashTable *Table);

/*************************************************
FUNCTION NAME : CreateRecord
Return Type : Record
Purpose : create Record

**************************************************/
Record CreateRecord(int);


#endif 
