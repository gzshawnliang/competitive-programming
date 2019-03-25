#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

//ifstream fin("inttoD.in");
//ofstream fout("inttoD.out");

int main()
{
    double d;
    int a=5;
    d=a;
    d=d/3;
    // int dp[10000][10000];
    // int size2=sizeof(dp)/sizeof(dp[0][0]);
    // cout << sizeof(dp) << "\n";
    // cout << sizeof(dp[0][0]) << "\n";

    string data[] = {"\u250C\u2500\u2500\u2500\u2500\u2500\u2510", "\u2502Hello\u2502", "\u2514\u2500\u2500\u2500\u2500\u2500\u2518"};
    for (auto s : data)
    {
        cout<<s<< "\n";
    }
    return 0;
}

