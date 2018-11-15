#ifndef EM_STORAGE_H
#define EM_STORAGE_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "em_visual_db.h"
#include<fstream>
#include<unordered_map>
using namespace std;

class EM_storage
{
    public:
        void store_buffer(em_visual_db&persisting);
        void find_entry(long int);
        unordered_map<long int,string>store_map;
        string file_path;
        void get_entry_store(long int);
        void delete_entry(long int);

};

#endif // EM_STORAGE_H
