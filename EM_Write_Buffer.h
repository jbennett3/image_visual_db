#ifndef EM_WRITE_BUFFER_H
#define EM_WRITE_BUFFER_H
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"EM_storage.h"
#include "em_visual_db.h"
using namespace std;
class EM_Write_Buffer
{
    public:
    void Entries( em_visual_db &new_entry);
    void sort_buffer(vector<em_visual_db> &);
    vector<em_visual_db>Buffer;
    void get_entry_buffer(long int);
    int mark_entry(long int);
    void delete_entry(long int);
    EM_storage data_store;
};

#endif // EM_WRITE_BUFFER_H
