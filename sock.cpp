#include <iostream>
using namespace std;

int main (int argC , char* argv[])
{
for (int i=0; i<12; i++)
{
    argv [i] = 'a';
}
for (int i=0; i<12; i++)
{
    cout<< "arg"<<i<<": "<<argv[i] <<endl;
}
return 0;
}