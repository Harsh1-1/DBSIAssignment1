#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


const int NUM_RECORDS 10;
const int MSB_VALUES = 24;
const int MAIN_MEMEORY_ENTRIES = 1024;


struct Record
{
	int data;//data to be stored
	bitset<32>binary_data; // binary rep of hash value of data
	string binary_data;//hash for comparing
};

struct bucket
{
	
 	vector<Record> record;  //record to be strored
	int itemcount;     //no. of items stored till now in bucket, just to calculate no. of free space
	int localdepth;    //local depth of bucket
	int indexofreeslot; // index of next free slot.
	int max_bucket_size;//max bucket size
	struct bucket *overflow;  // for a pointer to overflow bucket
	bucket():record(NUM_RECORDS),itemcount(0),localdepth(0),indexofreeslot(0),max_bucket_size(NUM_RECORDS){};  //setting records to be 10 via constructor
};


struct hash_table_entry{
	char formsb[MSB_VALUES]; //just for storing the msb value (address enteries)
	int read_bytes_in_formsb; 
	int bucket_number;  // bucket number to which this hash table entry is pointing to
	hash_table_entry():read_bytes_in_formsb(0),bucket_number(0){}

};

struct main_memory
{
	vector<hash_table_entry> hte;
	main_memory():hte(MAIN_MEMORY_ENTRIES){}; // only 1024 addresses can be stored in main memory
};

struct secondary_memory
{

};



int main(int argc, char *argv[])
{

	return 0;
}
