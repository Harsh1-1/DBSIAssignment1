#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct bucket
{
	
 std::vector<int> record;  //record to be strored
bucket():record(10){};  //setting records to be 10 via constructor
int itemcount;     //no. of items stored till now in bucket, just to calculate no. of free space
int localdepth;    //local depth of bucket
int indexofreeslot; // index of next free slot.

struct bucket *overflow;  // for a pointer to overflow bucket
};


struct hash_table_entry{
char formsb[24]; //just for storing the msb value (address enteries)
int read_bytes_in_formsb; 
int bucket_number;  // bucket number to which this hash table entry is pointing to
};

struct main_memory
{
std::vector<hash_table_entry> hte;
main_memory():hte(1024){}; // only 1024 addresses can be stored in main memory
};

struct secondary_memory
{

};



int main(int argc, char *argv[])
{

	return 0;
}