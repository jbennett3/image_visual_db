#include "em_visual_db.h"
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
using namespace std;

string em_visual_db::set_name(string in_name)
{
    visual_db_name = in_name;
    return visual_db_name;
}

void em_visual_db::put(long int time,vector<char>&info,string name_data,string object_name)
{
    time_Stamp = time;
    data_input = info;
    entry_file = name_data;
    visual_db_name = set_name(object_name);

   std::ifstream input_file;
   input_file.open(entry_file, std::ios::binary);
   input_file.seekg(0, std::ios::end);
   size_t filesize=input_file.tellg();
   input_file.seekg(0, std::ios::beg);
   data_input.resize(filesize/sizeof(char));
   input_file.read((char *)data_input.data(), filesize);
   cout<<visual_db_name<<" has "<<data_input.size()<<" bytes"<<endl;

}

bool operator <(const em_visual_db &t1 , const em_visual_db &t2)
{
    return t1.determine_time()<t2.determine_time();
}
const em_visual_db &em_visual_db::operator=(const em_visual_db &ri)
{
 time_Stamp = ri.time_Stamp;
 visual_db_name = ri.visual_db_name;
 data_input = ri.data_input;
 entry_file = ri.entry_file;
 return *this;
}

