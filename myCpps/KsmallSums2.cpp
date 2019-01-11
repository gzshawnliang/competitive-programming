/***********************************************************
 * @名称:		K Smallest Sums
 * @作者:		Shawn 
 * @创建时间: 2017-12-12 21:08:59 
 * @修改人:   Shawn 
 * @修改时间: 2017-12-12 21:08:59 
 * @备注:		难到爆炸的优先队列训练题
 * @题目来源： https://uva.onlinejudge.org/index.php
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


using namespace std;

struct num
{
    int v;
    int AP;
    int BP;
    bool operator<(const num &i) const
    {
        return v > i.v;
    };
};

int main()
{
    
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
        for (int i = 1; i <= k - 1; ++i)
        {
            vector<int> finalAns, A = a[i - 1], B = a[i];
            priority_queue<num> q;
            finalAns.push_back(A[0] + B[0]);
            int Ai = 0, Bi = 0;

            for (int j = 1; j <= k - 1; ++j)
            {
                num temp{A[j] + B[0], j, 0};
                q.push(temp);
            }
            num temp{A[Ai] + B[Bi + 1], Ai, Bi + 1};
            q.push(temp);

            while (finalAns.size() < k)
            {
                finalAns.push_back(q.top().v);
                Ai = q.top().AP;
                Bi = q.top().BP + 1;
                num temp{A[Ai] + B[Bi], Ai, Bi};
                q.push(temp);

                // priority_queue<num> outPut = q;
                // cout << finalAns.size() << " : ";
                // while (!(outPut.empty()))
                // {
                //     cout << outPut.top().v << " ";
                //     outPut.pop();
                // }
                // cout << '\n';

                q.pop();
            }

            a[i] = finalAns; 
            // int size = finalAns.size();
            // for (int h = 0; h <= size - 1; ++h)
            // {
            //     cout << finalAns[h] << " ";
            // }
            // cout << '\n';
        }

        for (int i = 0; i <= k - 1; ++i)
        {
            fout << a[k - 1][i];
            if (i != k - 1)
            {
                fout << " ";
            }
        }
        fout << '\n';
    }
    return 0;
}