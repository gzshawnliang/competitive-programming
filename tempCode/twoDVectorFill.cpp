#include <bits/stdc++.h>

using namespace std;

//ifstream fin("twoDVectorFill.in");
//ofstream fout("twoDVectorFill.out");



int main2()
{
    //code
    vector<vector<int>> v(100, vector<int>(10, 0));
    std::fill(v.begin(), v.end(), vector<int>(19, 5));
    return 0;
}

void createVector()
{
    clock_t startT;
    clock_t endT;
    double cpu_time_used;  
    startT = clock();
    vector<vector<vector<bool>>> dp(150, vector<vector<bool>>(1001, vector<bool>(15, true)));
    //vector<vector<bool>> dp(150,vector<bool>(1001,true));
    endT = clock();
    cpu_time_used = ((double)(endT - startT));
    cout << "CPU time create 150x1001x15 vector = " << cpu_time_used << endl;
    dp.clear();
    dp.shrink_to_fit();
}

void createFixArray()
{
    clock_t startT;
    clock_t endT;
    double cpu_time_used;
    startT = clock();
    bool dp2[150][1001][15];
    memset(dp2, true, sizeof(dp2));
    endT = clock();
    cpu_time_used = ((double)(endT - startT));
    cout << "CPU time create 150x1001x15 fix array :" << cpu_time_used << endl;
}

int main()
{
    createVector();
    //createFixArray();
    clock_t startT;
    clock_t endT;
    double cpu_time_used;
    startT = clock();
    bool dp2[150][1001][15];
    memset(dp2, true, sizeof(dp2));
    endT = clock();
    cpu_time_used = ((double)(endT - startT));
    cout << "CPU time create 150x1001x15 fix array :" << cpu_time_used << endl;
        
    return 0;
}