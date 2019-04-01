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

// int main()
// {
//     double d;
//     int a=5;
//     d=a;
//     d=d/3;
//     // int dp[10000][10000];
//     // int size2=sizeof(dp)/sizeof(dp[0][0]);
//     // cout << sizeof(dp) << "\n";
//     // cout << sizeof(dp[0][0]) << "\n";

//     string data[] = {"\u250C\u2500\u2500\u2500\u2500\u2500\u2510", "\u2502Hello\u2502", "\u2514\u2500\u2500\u2500\u2500\u2500\u2518"};
//     for (auto s : data)
//     {
//         cout<<s<< "\n";
//     }


    
//     return 0;
// }

/***************************************************************
* A program to show how to test the state of a stream *
***************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a line of integers and eof at the end: " << endl;
    while (cin >> n)
    {
        cout << n * 2 << " ";
    }
    return 0;
}