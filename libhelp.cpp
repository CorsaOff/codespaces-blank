#include <iostream>
#include "libhelp.h"
using namespace std;
void gethelp ()
{
    const char* author_ptr = std::getenv ("Author");
    const char* version_ptr = std::getenv ("Version");\
    std::string Author = "";
    std::string Version = "";
    if (author_ptr)
    {
        // cout << "Author";
        Author = author_ptr;
    }
    else
    {
        cerr << "Автор не установлен";
    }
    if (version_ptr)
    {
        // cout << "Version";
        Version = version_ptr;
    }
    else
    {
        cerr << "Версия не опеределенна";
    }
    cout << "Author: " <<  Author << "\n" << "Version: " << Version << "\n";
}