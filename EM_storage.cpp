#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<unordered_map>
#include<algorithm>
#include"em_visual_db.h"
#include"EM_Write_Buffer.h"
#include"EM_storage.h"
#include<fstream>
#include<iterator>
#include<string.h>
#include<istream>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<iterator>
void EM_storage::store_buffer(em_visual_db &persisting)
{
  string file_name = persisting.get_name();
  long int entry_time = persisting.determine_time();
  vector<char>temp(persisting.get_vector());
  file_path="C:\\Users\\Justin\\Desktop\\"+file_name+".txt";
  store_map[entry_time]=file_path;
  std::ofstream outFile(file_name+".txt",std::ios::binary);
    for (const auto &e :temp)
    {outFile << e;}
  std::ofstream(file_name+".BMP", std::ios::binary) << std::ifstream(file_name+".txt", std::ios::binary).rdbuf();
}

void EM_storage::get_entry_store(long int time)
{
 unordered_map<long int,string>::iterator itr;
if (store_map.find(time) == store_map.end())

        {
            cout <<"entry"<<time<< " does not exist \n\n";
        }
    else
    {
    cout << "Found entry :"<<time<<" in storage"<<endl;

    for (itr = store_map.begin(); itr != store_map.end(); itr++)
    {
       cout << "time_stamp"<<itr->first << "  " <<"entry "<< itr->second << endl;
    }
    /*string line;
  ifstream myfile (file_path,std::ios::binary);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else
  {cout << "Unable to open file";}*/

}

}
void EM_storage::delete_entry(long int time_entry)
{
    store_map.erase(time_entry);
    cout<<"Entry has been deleted"<<endl;

}

