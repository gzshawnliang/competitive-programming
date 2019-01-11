/***********************************************************
 * @名称:		K Smallest Sums (overtime)
 * @作者:		Shawn 
 * @创建时间: 2017-12-12 21:18:35 
 * @修改人:   Shawn 
 * @修改时间: 2017-12-12 21:18:35 
 * @备注:		
 * @题目来源： 
***********************************************************/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    //clock_t tStart = clock();
    ifstream fin("KsmallSums.in");
    ofstream fout("KsmallSums.out");

    while (!(fin.eof()))
    {
        int k = 0;
        fin >> k;
        if (k == 0)
        {
            break;
        }
        vector<vector<int>> a;
        for (int i = 0; i <= k - 1; ++i)
        {
            vector<int> temp(k);
            for (int j = 0; j <= k - 1; ++j)
            {
                fin >> temp[j];
            }
            sort(temp.begin(), temp.end());
            a.push_back(temp);
        }

        //cout << "Read Data completed after " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " seconds\n";
        //tStart = clock();

        for (int i = 1; i <= k - 1; ++i)
        {
            priority_queue<int, vector<int>, greater<int>> temp;
            for (int j = 0; j <= k - 1; ++j)
            {
                for (int m = 0; m <= k - 1; ++m)
                {
                    temp.push(a[i - 1][j] + a[i][m]);
                }
            }
            for (int j = 0; j <= k - 1; ++j)
            {
                a[i][j] = temp.top();
                temp.pop();
            }
        }
        //cout << "Calculate Data completed after " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " seconds\n";
        //tStart = clock();

        for (int i = 0; i <= k - 1; ++i)
        {
            fout << a[k - 1][i];
            if (i != k - 1)
            {
                fout << " ";
            }
        }
        fout << '\n';
        //cout << "Cout Data completed after " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " seconds\n";
    }

    return 0;
}