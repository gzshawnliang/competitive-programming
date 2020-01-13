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
    vector<vector<int>> obs;

    void init(int n, int m)
    {
        this->N = n;
        this->M = m;
        vector<vector<int>> obs(M + 1, vector<int>());
        this->obs = obs;
    }

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

    bool checkCircle(int x)
    {
        queue<int> q;
        vector<set<int>> edge = createEdge(x);
        vector<int> visit(N + 1, 0);
        vector<int> in(N + 1, 0);

        for (int i = 1; i <= N; ++i)
        {
            for (auto it = edge[i].begin(); it != edge[i].end(); ++it)
            {
                ++in[*it];
            }
        }

        vector<int> noEmptyCount;
        for (int i = 1; i <= N; ++i)
            if (in[i] == 0)
            {
                q.push(i);
                visit[i] = 1;

                if (!edge[i].empty())
                    noEmptyCount.push_back(i);
            }

        if (noEmptyCount.empty())
            return false;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto j : edge[curr])
            {
                if (visit[j] == 0)
                {
                    --in[j];
                    if (in[j] == 0)
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
            if (in[i] > 0)
                return false;
        //assert(1 == 1);
        return true;
    }

    vector<int> topoSorting(int x)
    {
        vector<int> ans;

        priority_queue<int, vector<int>, greater<int>> q;
        vector<set<int>> edge = createEdge(x);
        vector<int> in(N + 1, 0);
        for (int i = 1; i <= N; ++i)
        {
            for (auto it = edge[i].begin(); it != edge[i].end(); ++it)
            {
                ++in[*it];
            }
        }

        for (int i = 1; i <= N; ++i)
            if (in[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int curr = q.top();
            ans.push_back(curr);
            q.pop();

            for (auto it = edge[curr].begin(); it != edge[curr].end(); ++it)
            {
                --in[*it];
                if (in[*it] == 0)
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
        init(n,m);

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

        int l = 1;
        int r = M;
        int x = 1;
        while (l < r)
        {
            int m = (r + l) / 2;
            bool ret = checkCircle(m);
            if (ret)
            {
                x = m;
                l = m;
            }
            else
            {
                r = m;
            }

            if (r - l == 1)
            {
                if (checkCircle(r))
                    x = r;
                else if (checkCircle(l))
                    x = l;

                break;
            }
        }

        vector<int> ans = topoSorting(x);
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
