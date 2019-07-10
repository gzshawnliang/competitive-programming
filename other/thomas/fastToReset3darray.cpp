#include <bits/stdc++.h>

using namespace std;


// int test[205][205][205];
// int main2()
// {   
//     int t=1000;
//     int intSize1=205*205*205*sizeof(int);
//     int intSize2=sizeof(test);
//     int intSize3=sizeof(*test);
//     while (t--)
//     {
//         memset(test,-1, intSize1);     

//         cout <<test[0][0][0] << ' ';
//         cout <<test[204][204][204] << ' ';
//         test[0][0][0]=1;
//         test[204][204][204]=1;
//         cout <<test[0][0][0] << ' ';
//         cout <<test[204][204][204] << '\n';
//     }
    
//     return 0;
// }


int main()
{   
    int t=1000;
    int n=205;
    vector<vector<vector<int>>> test(n,vector<vector<int>>(n,vector<int>(n)));
    while (t--)
    {
        
        // vector<array<int,n>> test2(n);
        // vector<vector<array<int,n>>> test1(n);
        //vector<vector<array<int,n>>> test0(n,vector<array<int,n>>(n));
        vector<vector<int>> initVal(n,vector<int>(n));
        fill(test.begin(),test.end(),initVal);
        cout <<test[0][0][0] << ' ';
        test[0][0][0]=1;
        cout <<test[0][0][0] << '\n';

    }
    
    return 0;
}