#include <cstdio>
#include <cstdlib>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void lower_find(vector<int> & v,int val)
{
    auto it1=lower_bound(v.begin(),v.end(),val);
    cout << "lower_bound val:" << val;
    if(it1==v.end())
    {
        cout << " no found" << endl;
    }
    else
    {
        cout <<" at:"<< it1-v.begin() << endl;
    }    
}

void upper_find(vector<int> & v,int val)
{
    auto it1=upper_bound(v.begin(),v.end(),val);
    cout << "upper_bound val:" << val;
    if(it1==v.end() )
    {
        cout << " no found" << endl;
    }
    else
    {
        cout <<" at:"<< it1-v.begin() << endl;
    }    
}

int main()
{
    vector<int> v1={1,2,2,3,4,4,4,4,5,7,8,9,9};

    lower_find(v1,4);
    upper_find(v1,4);

    lower_find(v1,6);
    upper_find(v1,6);

    lower_find(v1,15);
    upper_find(v1,15);

    lower_find(v1,-1);
    upper_find(v1,-1);

    return 0;
}