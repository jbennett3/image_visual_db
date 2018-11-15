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
class ImageDB
{
public:
    void Put(long int,vector<char>&,string ,string );
    void Get(long int);
    void Delete(long int);
    private:
    EM_Write_Buffer buffer1;
    em_visual_db object;
};
