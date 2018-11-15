#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include"em_visual_db.h"
#include"EM_Write_Buffer.h"
#include"EM_storage.h"
#include<fstream>
#include<atomic>
#include"database.h"
void ImageDB::Put(long int time_input,vector<char>& data_image,string name_data,string object_name)
{
  object.put(time_input,data_image,name_data,object_name);
  buffer1.Entries(object);
}
void ImageDB::Get(long int time_object)
{
    buffer1.get_entry_buffer(time_object);
}
void ImageDB::Delete(long int entry_time)
{
  buffer1.delete_entry(entry_time);
}
