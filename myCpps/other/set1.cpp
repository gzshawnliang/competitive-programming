#include <bits/stdc++.h>

using namespace std;

//ifstream fin("set1.in");
//ofstream fout("set1.out");

int main()
{
    set<double> set1;
    set1.insert(1.0);
    set1.insert(2);
    if(set1.count(1.00005)>0)
    {
        cout << "True" << '\n';
    }
    else
    {
        cout << "False" << '\n';
    }    
    set1.insert(1.00005);
    set1.insert(1.00005);
    set1.insert(1);

    if(set1.count(1.00005)>0)
    {
        cout << "True" << '\n';
    }
    else
    {
        cout << "False" << '\n';
    }
    

    return 0;
}
