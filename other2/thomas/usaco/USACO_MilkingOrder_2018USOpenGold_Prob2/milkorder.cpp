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

class solution
{

  private:
    int N, M;
    vector<vector<int>> obs; //观察数据

    //从观察数据创建边
    vector<set<int>> createEdge(int x)
    {
        vector<set<int>> edge(N + 1);
        for (int i = 1; i <= x; ++i)
        {
            int size1 = obs[i].size();
            for (int j = 1; j <= size1 - 1; ++j)
                edge[obs[i][j - 1]].insert(obs[i][j]);
        }
        return edge;
    }

    //检查是否存在环
    bool checkCircle(int x)
    {
        queue<int> q;
        vector<set<int>> edge = createEdge(x);
        vector<int> visit(N + 1, 0);
        vector<int> inDegree(N + 1, 0);

        for (int i = 1; i <= N; ++i)
            for (auto it = edge[i].begin(); it != edge[i].end(); ++it)
                ++inDegree[*it];

        vector<int> connectedCow;       //入度为0并且有出度(有连接)的牛，有些是无入度和出度的牛
        for (int i = 1; i <= N; ++i)
            if (inDegree[i] == 0)
            {
                q.push(i);
                visit[i] = 1;

                if (!edge[i].empty())
                    connectedCow.push_back(i);
            }
        
        if (connectedCow.empty())       //存在环的情况
            return false;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto j : edge[curr])
            {
                if (visit[j] == 0)
                {
                    --inDegree[j];
                    if (inDegree[j] == 0)
                    {
                        q.push(j);
                        visit[j] = 1;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        for (int i = 1; i <= N; ++i)
            if (inDegree[i] > 0)        //存在环的情况
                return false;
        //assert(1 == 1);
        return true;
    }

    //拓扑排序
    vector<int> topoSorting(int x)
    {
        vector<int> ans;

        priority_queue<int, vector<int>, greater<int>> q;
        vector<set<int>> edge = createEdge(x);
        vector<int> inDegree(N + 1, 0);

        for (int i = 1; i <= N; ++i)
            for (auto it = edge[i].begin(); it != edge[i].end(); ++it)
                ++inDegree[*it];

        for (int i = 1; i <= N; ++i)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int curr = q.top();
            ans.push_back(curr);
            q.pop();

            for (auto it = edge[curr].begin(); it != edge[curr].end(); ++it)
            {
                --inDegree[*it];
                if (inDegree[*it] == 0)
                    q.push(*it);
            }
        }

        //assert(1 == 1);
        return ans;
    }

  public:
    void solve()
    {
        int n, m;
        fin >> n >> m;

        this->N = n;
        this->M = m;
        vector<vector<int>> observationData(M + 1, vector<int>());
        this->obs = observationData;

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

        int l = 0;
        int r = M+1;
        int maxX = 1;
        while (l < r - 1)
        {
            int m = (r + l) / 2;
            bool ret = checkCircle(m);
            if (ret)
            {
                maxX = m;
                l = m;
            }
            else
            {
                r = m;
            }
        }

        vector<int> ans = topoSorting(maxX);
        int id = 0;
        int size4 = ans.size();
        for (auto i : ans)
        {
            fout << i;
            if (id < size4 - 1)
                fout << " ";

            ++id;
        }
    }
};

int main()
{
    solution slu;
    slu.solve();

    return 0;
}
