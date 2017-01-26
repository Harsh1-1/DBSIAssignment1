#include "header.h"

main_memory mm;   // main memory only instance
secondary_memory sm; // secondary memory instance

record create_record(int);
void insert(int data);
hash_table_entry hasher(record r, int global_depth);

int main(int agrc, char *argv[])
{
	for(int i = 0; i <11;i++)
		insert(i);
return 0;
}


//for creating a new record
record create_record(int number)
{
record r; 
r.data = number;
r.data_bits  = bitset<TOTAL_BITS>(number);

return r; //returned newly create record
}


//for hashing a record
hash_table_entry hasher(record r, int global_depth)
{
hash_table_entry hash_entry;
for(int i=0;i<global_depth;i++)
{
	hash_entry.formsb[global_depth - i] = r.data_bits[20 - i];
}
hash_entry.bucket_number = (int)(hash_entry.formsb.to_ulong());

return hash_entry;
}

//for inserting data
void insert(int data)
{

record new_record = create_record(data);
hash_table_entry hash_t_entry= hasher(new_record, sm.global_depth);
if(sm.bucketfordata[hash_t_entry.bucket_number].itemcount < NUM_RECORDS) //NUM_RECORDS = 10
{
	sm.bucketfordata[ hash_t_entry.bucket_number ].recordinbucket[ sm.bucketfordata[hash_t_entry.bucket_number].indexoffreeslot ] = new_record;
	sm.bucketfordata[hash_t_entry.bucket_number].indexoffreeslot = sm.bucketfordata[hash_t_entry.bucket_number].indexoffreeslot + 1;
	sm.bucketfordata[hash_t_entry.bucket_number].itemcount = sm.bucketfordata[hash_t_entry.bucket_number].itemcount + 1;
	sm.total_records = sm.total_records + 1;

}
else if(sm.bucketfordata[hash_t_entry.bucket_number].itemcount == NUM_RECORDS) //This is overflow now decide what you need to do
{
//just for testing
//cout<<"here";
	if(sm.bucketfordata[hash_t_entry.bucket_number].local_depth < sm.global_depth)
	{
		//do local split
	}
	else // that means local and global depth are equal
	{
		//do directory split
	}

}
else if()
//just for testing
//cout<<"bucket_number:"<<hash_t_entry.bucket_number<<endl<<"indexoffreeslot:"<<sm.bucketfordata[hash_t_entry.bucket_number].indexoffreeslot<<"itemcount:"<<endl<<sm.bucketfordata[hash_t_entry.bucket_number].itemcount<<endl<<"total_records:"<<sm.total_records<<endl;

}