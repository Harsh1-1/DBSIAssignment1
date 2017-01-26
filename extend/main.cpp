#ifndef _HEADER_
#define _HEADER_

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


const int NUM_RECORDS 10;
const int MSB_VALUES = 24;
const int MAIN_MEMEORY_ENTRIES = 1024;
const int TOTAL_BITS = 32


struct bucket
{
	
 	vector<int> record;  //record to be strored
	int itemcount;     //no. of items stored till now in bucket, just to calculate no. of free space
	int localdepth;    //local depth of bucket
	int indexofreeslot; // index of next free slot.
	int max_bucket_size;//max bucket size
	struct bucket *overflow;  // for a pointer to overflow bucket
	bucket():record(NUM_RECORDS),itemcount(0),localdepth(0),indexofreeslot(0),max_bucket_size(NUM_RECORDS){}  //setting records to be 10 via constructor
};


struct hash_table_entry{
	char formsb[MSB_VALUES]; //just for storing the msb value (address enteries)
	int read_bytes_in_formsb; 
	//int bucket_number;  // bucket number to which this hash table entry is pointing to
	bucket b; //bucket to which hash table entry in pointing to 
	hash_table_entry():read_bytes_in_formsb(0),bucket_number(0){}

};

struct Main_Memory
{
	vector<hash_table_entry> hte; //collection of hash table entry
	int Maximum_Size; // max size of mainmemory
	int current_size; // current size of main memory
	main_memory(): Maximum_Size(Maximum_Size),current_size(0){}; // only 1024 addresses can be stored in main memory
};

struct secondary_memory
{
	Main_memory memory;  
	int global_depth;
	int overflow_pointer;
	int total_records;
	
	secondary_memory(): memory(),global_depth(0),overflow_pointer(0),total_records(0){}
};


#endif