#include <bits/stdc++.h>

using namespace std;

ifstream fin("softwareAllocation_UVA259.in");
ofstream fout("softwareAllocation_UVA259.out");

const int n = 40;
const string trans2 = "sABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789e";

int trans1(char ch)
{
    if (ch == 's')
    {
        return (1 - 1);
    }
    else if (ch == 'e')
    {
        return 37;
    }
    else if ('A' <= ch && ch <= 'Z')
    {
        return (ch - 'A') + 1;
    }
    else
    {
        return (ch - '0') + 27;
    }
}

int solve(int start, int end, vector<bool> & visit, vector<char> & computer, vector<vector<int>> & a, vector<vector<int>> & g)
{
    int n = a.size() - 1;

    queue<int> q;
    vector<int> f(n + 1, -1);

    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == end)
        {
            int _min = INT_MAX;

            int now = end;
            while (now != start)
            {
                _min = min(_min, a[f[now]][now]);

                if ('0' <= trans2[now] && trans2[now] <= '9')
                {
                    computer[(trans2[now] - '0')] = trans2[f[now]];
                }

                now = f[now];
            }

            now = end;
            while (now != start)
            {
                a[now][f[now]] += _min;
                a[f[now]][now] -= _min;

                now = f[now];
            }

            return _min;
        }

        int size = g[u].size();
        for (int i = 0; i <= size - 1; ++i)
        {
            int v = g[u][i];

            if (a[u][v] <= 0 || visit[v] == true) continue;

            visit[v] = true;
            f[v] = u;
            q.push(v);
        }
    }

    return -1;
}

int main()
{
    while (true)
    {
        bool _end = true;
        int total = 0;
        vector<vector<int>> a(n, vector<int>(n, 0)), g(n);

        // fout << trans1('s') << ' ' << trans1('e');
        // for (char ch = 'A'; ch <= 'Z'; ++ch) fout << ' ' << trans1(ch);
        // for (char ch = '0'; ch <= '9'; ++ch) fout << ' ' << trans1(ch);
        // fout << '\n'; break;

        while (true)
        {
            string in = "";
            getline(fin, in);

            if (in == "") break;

            _end = false;

            a[trans1('s')][trans1(in[0])] = (in[1] - '0');
            g[trans1('s')].push_back(trans1(in[0]));
            total += (in[1] - '0');

            for (int i = 3; in[i] != ';'; ++i)
            {
                if (a[trans1(in[0])][trans1(in[i])] == 0) g[trans1(in[0])].push_back(trans1(in[i]));
                a[trans1(in[0])][trans1(in[i])] = 1;
                
                if (a[trans1(in[i])][trans1('e')] == 0) g[trans1(in[i])].push_back(trans1('e'));
                a[trans1(in[i])][trans1('e')] = 1;
            }
        }

        if (_end == true) break;

        int ans = 0;
        vector<bool> visit(n, false);
        vector<char> computer(n, '_');

        while (true)
        {
            int res = solve(trans1('s'), trans1('e'), visit, computer, a, g);
            if (res == -1)
            {
                break;
            }

            ans += res;

            for (int i = 1; i <= n; ++i)
            {
                visit[i] = false;
            }
        }

        if (ans < total)
        {
            fout << "!\n";
        }
        else
        {
            for (int i = 0; i <= 9; ++i)
            {
                fout << computer[i];
            }
            fout << '\n';
        }
    }

    return 0;
}
