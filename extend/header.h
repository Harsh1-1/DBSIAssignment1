#ifndef _HEADER_
#define _HEADER_

#include<stdio.h>
#include<iostream>
#include<vector>
#include<bitset>

using namespace std;


const int NUM_RECORDS = 10;
const int MSB_VALUES = 20;
const int MAIN_MEMEORY_SIZE = 1024;
const int TOTAL_BITS = 20;


struct record
{
int data;
bitset<20> data_bits; //please note data_bits[0] will give lsb and data_bits[19] will give msb, data_bits[18] is 2nd msb 
};

struct bucket
{

 	vector<record> recordinbucket;  //record to be strored
	int itemcount;     //no. of items stored till now in bucket, just to calculate no. of free space
	int local_depth;    //local depth of bucket
	int ifoverfow;      //for checking if this bucket is overflowed // will help in rehashing 0 means no overflow 1 for overflow
	int indexoffreeslot; // index of next free slot.
	int max_bucket_size;//max bucket size
	struct bucket *overflow;  // for a pointer to overflow bucket
	bucket():recordinbucket(NUM_RECORDS),itemcount(0),localdepth(0),indexoffreeslot(0),max_bucket_size(NUM_RECORDS),ifoverfow(0),overflow(NULL){}  //setting records to be 10 via constructor
};


struct hash_table_entry{
	bitset<MSB_VALUES> formsb; //just for storing the msb value (address enteries) // no .of bits to be read can be checked via global depth
	//char formsb[MSB_VALUES];
	//int read_bytes_in_formsb; //no. of bits to be read to check
	int bucket_number;  // bucket number to which this hash table entry is pointing to
	//bucket b; //bucket to which hash table entry in pointing to 
	hash_table_entry():bucket_number(0){}

};

struct main_memory
{
	vector<hash_table_entry> hte; //collection of hash table entry
	int Maximum_Size; // max size of mainmemory
	int current_size; // current size of main memory
	main_memory(): Maximum_Size(MAIN_MEMEORY_SIZE),current_size(1),hte(MAIN_MEMEORY_SIZE){}; // only 1024 addresses can be stored in main memory
};

struct secondary_memory
{
	int global_depth;
	int overflow_pointer;
	int total_records;
	int next_free_bucket;
	
	vector<hash_table_entry> extendedhte; //extended hash table enteries
	vector<bucket> bucketfordata;
	vector<bucket> bucketforoverfow;


	secondary_memory(): global_depth(0),overflow_pointer(0),total_records(0),extendedhte(9000),bucketfordata(10000),bucketforoverfow(10000),next_free_bucket(0){}
};


#endif
