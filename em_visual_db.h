#ifndef EM_VISUAL_DB_H
#define EM_VISUAL_DB_H
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class em_visual_db
{
public:
        string set_name(string);
        string get_name(){return (visual_db_name);}
        long int determine_time()const {return time_Stamp;}
        vector<char>get_vector(){return data_input;}
        string get_file_name(){return entry_file;}
        void put(long int,vector<char>&,string name_data,string object_name);
        long int time_Stamp;
        string visual_db_name;
        vector<char>data_input;
        string entry_file;
        const em_visual_db &operator=(const em_visual_db &);
        int tombstone_tag=0;
};
bool operator<(const em_visual_db &t1, const em_visual_db &t2);
#endif // EM_VISUAL_DB_H

