#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> v1;
string const s="ABCDEFGHIJKLMNOP";

void genData(string temp,int n)
{
    if(n==s.size())
    {
        return;
    }
    else
    {
        if(!temp.empty())
        {
            v1.push_back(temp);
            genData(temp,n+1);
        }

        temp +=s[n];
        v1.push_back(temp);

        genData(temp,n+1);
    }
}

int main()
{
    string temp="";

    genData(temp,0);

    cout<< v1.size()<< "\n";

    // for(int i=0;i<=v1.size()-1;++i)
    // {
    //     cout<< v1[i]<< "\n";
    // }
    double a = 1.5;

    return 0;
}