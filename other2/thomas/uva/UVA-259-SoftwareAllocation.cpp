#include <bits/stdc++.h>

using namespace std;

ifstream fin("UVA-259-SoftwareAllocation.in");
ofstream fout("UVA-259-SoftwareAllocation.out");

const string node = "!ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789#";
const int INF = INT_MAX / 2;
const int n = 39;


int bfs(int s, int t, vector<int> & parent, const vector<vector<int>> & a)
{
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 1; next <= n; ++next)
        {
            if (parent[next] == -1 && a[cur][next] > 0 && cur != next)
            {
                parent[next] = cur;
                int new_flow = min(flow, a[cur][next]);
                if (next == t)
                {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow_EdmondsKarp(int s, int t, vector<vector<int>> & a,vector<char> & computer)
{
    int flow = 0;

    while (true)
    {
        vector<int> parent(n + 1, -1);
        int new_flow = bfs(s, t, parent, a);
        if (new_flow == 0)
        {
            break;
        }
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            a[prev][cur] -= new_flow;
            a[cur][prev] += new_flow;

            if(a[prev][cur]>0 && isalpha(node[prev]) && isdigit(node[cur]))
            {
                computer[node[cur]-'0']=node[prev];
                cout << node[prev] << "-" << node[cur] << "\n";
            }
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    while (true)
    {
        int start = 0;
        int target = node.size() - 1;
        int total = 0;
        vector<vector<int>> a(n, vector<int>(n, 0));
        vector<char> computer(10, '_');
        while (true)
        {
            string in = "";
            getline(fin, in);

            if (in == "")
            {
                //当前案例输入结束 开始处理
                int ans = maxflow_EdmondsKarp(start, target, a,computer);
                if (ans == total)
                {
                    for (int i = 0; i <= computer.size()-1; ++i)
                    {
                        fout << computer[i];
                    }
                    fout << "\n";
                }
                else
                {
                    fout << "!" << "\n";
                }

                vector<vector<int>> a2(n, vector<int>(n, 0));
                vector<char> computer2(10, '_');
                total = 0;
                
                a=a2;
                computer=computer2;

                if(fin.eof())
                {
                    return 0;
                }

                continue;
            }
            int num = in[1] - '0';
            a[start][in[0] - 'A' + 1] = num;
            total += num;

            int i = 3;
            while (in[i] != ';')
            {
                a[in[0] - 'A' + 1][in[i] - '0' + 27] = INF;
                a[in[i] - '0' + 27][target] = 1;
                ++i;
            }

        }
    }

    return 0;
}
