#include <bits/stdc++.h>

using namespace std;

//ifstream fin("memset.in");
//ofstream fout("memset.out");

int main()
{
    int data[10];  
    memset(data, 0, sizeof(data));    // right  
    memset(data, -1, sizeof(data));    // right  
    memset(data, 1, sizeof(data));      // wrong, data[x] would be 0x0101 instead of 1  

    fill(data,data+10,1);

    return 0;
}
