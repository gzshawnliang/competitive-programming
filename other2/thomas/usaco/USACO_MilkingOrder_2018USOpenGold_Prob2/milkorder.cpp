/*
===========================================================
* @Name:           Problem 2. Milking Order 
* @Author:         Thomas
* @create Time:    2020/1/12 22:44:18
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=838&lang=zh
* @Description:    USACO 2018 US Open Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("milkorder.in");
ofstream fout("milkorder.out");

int N, M;

bool checkCircle(int x, vector<vector<int>> & obs)
{
    queue<int> q;
    vector<vector<int>> e(N + 1);
    vector<int> in(N + 1, 0);
    for (int i = 1; i <= x; ++i)
    {
        int size1 = obs[i].size();

        for (int j = 1; j <= size1 - 1; ++j)
        {
            ++in[obs[i][j]];
            e[obs[i][j-1]].push_back(obs[i][j]);
        }
    }

    vector<int> start;
    for (int i = 1; i <= N; ++i)
        if(in[i]==0)
            start.push_back(i);

    int size2 = start.size();
    if(size2==0)
        return false;

    for (int i = 0; i <= size2 - 1; ++i)
    {
        vector<int> visit(N + 1, 0);
        q.push(start[i]);
        visit[start[i]]=1;

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            int size3=e[curr].size();
            for (int j = 0; j <= size3 - 1; ++j)
            {
                if(visit[e[curr][j]]==0)
                {
                    q.push(e[curr][j]);
                    visit[e[curr][j]]=1;
                }
                else
                {
                    return false;
                }
                
            }
        }
    }

    //assert(1 == 1);
    return true;
}

vector<int> topologicalSorting(int x, vector<vector<int>> & obs)
{
    vector<int> ans;

    priority_queue<int, vector<int>, greater<int> >q;
    vector<vector<int>> e(N + 1);
    vector<int> in(N + 1, 0);
    for (int i = 1; i <= x; ++i)
    {
        int size1 = obs[i].size();

        for (int j = 1; j <= size1 - 1; ++j)
        {
            ++in[obs[i][j]];
            e[obs[i][j-1]].push_back(obs[i][j]);
        }
    }

    set<int> start;
    for (int i = 1; i <= N; ++i)
        if(in[i]==0)
            start.insert(i);

    auto it = start.begin();
    q.push(*it);

    while(!q.empty())
    {
        int curr=q.top();
        ans.push_back(curr);
        q.pop();

        int size3=e[curr].size();
        for (int j = 0; j <= size3 - 1; ++j)
            q.push(e[curr][j]);
    }

    //assert(1 == 1);
    return ans;
}




int main()
{
    fin >> N >> M;
    vector<vector<int>> obs(M + 1, vector<int>());
    for (int i = 1; i <= M; ++i)
    {
        int m;
        fin >> m;
        for (int j = 0; j <= m - 1; ++j)
        {
            int temp;
            fin >> temp;
            obs[i].push_back(temp);
        }
    }

    int l=1;
    int r=M;
    int x=M;
    while (l<r)
    {
        int m=(r+l)/2;
        bool ret = checkCircle(m, obs);
        if(ret)
        {
            x=m;
            l=m+1;

        }
        else
        {
            r=m;
        }
    }
    //cout << x << "\n";
    vector<int> ans=topologicalSorting(x,obs);
    int size4=ans.size()-1;
    for (auto i:ans)
    {
        cout << i << " ";
    }


    return 0;
}
