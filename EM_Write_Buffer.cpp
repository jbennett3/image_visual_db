
#include "EM_Write_Buffer.h"
#include<iostream>
#include<string>
#include<vector>
#include "em_visual_db.h"
#include<fstream>
#include"EM_storage.h"
#include<algorithm>
using namespace std;

 void EM_Write_Buffer::Entries(em_visual_db & new_entry)
{
 if(Buffer.size()<2)
 {
   Buffer.push_back(new_entry);
 }
 else
 {
     //Buffer[0].tombstone_tag = 1;
     data_store.store_buffer(Buffer[0]);
     Buffer[0] = new_entry;
     sort(Buffer.begin(),Buffer.end());
 }

}


void EM_Write_Buffer::get_entry_buffer(long int timer)
{
    int found;
    for(int i =0;i<Buffer.size();i++)
    {
        if(timer==Buffer[i].determine_time())
        {
             found = 1;
        }
    }
    if(found==1)
    {
     cout<<"entery was with:  "<<timer<<" found in buffer"<<endl;
    }
    else
    {
        cout<<"not found in the buffer"<<endl;
        data_store.get_entry_store(timer);
    }
}
int EM_Write_Buffer::mark_entry(long int time )
{
    int i;
    int result = 0;
    for(i =0;i<Buffer.size();i++)
    {
       if(Buffer[i].determine_time() == time)
       {
           Buffer[i].tombstone_tag = 1;
           result = 1;
           return result;
       }
    }

    return result;
}
void EM_Write_Buffer::delete_entry(long int tag)
{
    int result_tag = mark_entry(tag);
    if(result_tag==1)
    {
        data_store.delete_entry(tag);
    }
    data_store.delete_entry(tag);
}

