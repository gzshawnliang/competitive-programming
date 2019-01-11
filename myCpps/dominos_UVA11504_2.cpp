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
#include <stack>

using namespace std;

ifstream fin("dominos_UVA11504.in");
ofstream fout("dominos_UVA11504.out");

struct in
{
    int first;
    int second;
};

vector<in> input;
int finalAnswer;

void tarjan(int u, int n, int & index, vector<int> & dfn, vector<int> & low, vector<bool> & inStack, vector<vector<bool>> & a, stack<int> & stk)
{
    ++index;
    dfn[u] = index; low[u] = index;
    stk.push(u); inStack[u] = true;
    
    int ans = 0;
    for (int v = 1; v <= n; ++v)
    {
        if (a[u][v] == true)
        {
            if (dfn[v] == -1)
            {
                tarjan(v, n, index, dfn, low, inStack, a, stk);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v] == true)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    if (dfn[u] == low[u])
    {
        vector<bool> inGroup(n + 1, false);
        int t;

        vector<int> temp;
        //vector<int> temp2(n,-1);
        do
        {
            t = stk.top();

            temp.push_back(t);
            
            //temp2[t]=0;

            inStack[t] = false;
            inGroup[t] = true;

            stk.pop();
        }
        while (t != u);

        bool ok = true;
        // int size = input.size();
        // for (int i = 0; i <= size - 1; ++i)
        // {
        //     if (inGroup[input[i].first] == false && inGroup[input[i].second] == true)
        //     {
        //         ok = false;
        //         break;
        //     }
        // }
        int size = temp.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(a[j][temp[i]]==true && inGroup[input[i].first] == false)
                {
                    ok = false;
                    break;
                }
            }
        }        

        if (ok == true)
        {
            ++finalAnswer;
        }



    }
}

int main()
{
    double totalTime=0;

    int testCase; fin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int n, m; fin >> n >> m;
        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));
        input.clear();
        finalAnswer = 0;
         
        for (int k = 1; k <= m; ++k)
        {
            int u, v; fin >> u >> v;
            a[u][v] = true;

            in temp{u, v};
            input.push_back(temp);
        }
        
        int zero = 0;
        vector<int> dfn(n + 1, -1), low(n + 1, -1);
        vector<bool> inStack(n + 1, false);
        stack<int> stk;
        vector<vector<int>> res;
        for (int i = 1; i <= n; ++i)
        {
            if (dfn[i] == -1)
            {
                tarjan(i, n, zero, dfn, low, inStack, a, stk);
            }
        }

        fout << finalAnswer << '\n';
    }

    return 0;
}