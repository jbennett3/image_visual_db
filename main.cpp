#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"database.h"
#include<fstream>
#include<atomic>
using namespace std;
typedef  long int id_type;
std::atomic<id_type> current_id;

id_type get_next_id()
{
   return current_id.fetch_add(1);
}

int main()
{
    //EM_Write_Buffer test1;
    string names1 = "Camera1";
    string names2 = "Camera2";
    string names3 = "Camera3";

    vector<char>input1;
    vector<char>input2;
    vector<char>input3;

    long int test_time1 = get_next_id();

    long int test_time2 = get_next_id();

    long int test_time3 = get_next_id();

ImageDB Device;

Device.Put(test_time1,input1,"pular.jpg",names1);
Device.Get(test_time1);
Device.Put(test_time2,input2,"space.jpg",names2);
Device.Put(test_time3,input3,"space2.jpg",names3);
Device.Get(test_time1);
//Device.Delete(test_time1);
//Device.Get(test_time1);

return 0;
}
