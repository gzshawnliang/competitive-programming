#include <bits/stdc++.h>

using namespace std;


const int n = 40, inf = INT_MAX / 2;
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

int solve(int start, int end, vector<bool> & visit, vector<char> & computer, vector<vector<int>> & a)
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

        for (int v = 0; v <= 37; ++v)
        {
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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        bool _end = true;
        int total = 0;
        vector<vector<int>> a(n, vector<int>(n, 0));


        while (true)
        {
            string in = "";
            getline(cin, in);

            if (in == "") break;

            _end = false;

            a[trans1('s')][trans1(in[0])] = (in[1] - '0');
            total += (in[1] - '0');

            for (int i = 3; in[i] != ';'; ++i)
            {
                a[trans1(in[0])][trans1(in[i])] = inf;
                
                a[trans1(in[i])][trans1('e')] = 1;
            }
        }

        if (_end == true) break;

        int ans = 0;
        vector<bool> visit(n, false);
        vector<char> computer(n, '_');

        while (true)
        {
            int res = solve(trans1('s'), trans1('e'), visit, computer, a);
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
            cout << "!\n";
        }
        else
        {
            for (int i = 0; i <= 9; ++i)
            {
                cout << computer[i];
            }
            cout << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

