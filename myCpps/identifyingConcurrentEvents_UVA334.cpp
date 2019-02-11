#include <bits/stdc++.h>

using namespace std;

ifstream fin("identifyingConcurrentEvents_UVA334.in");
ofstream fout("identifyingConcurrentEvents_UVA334.out");

const int N = 300, MAX = INT_MAX / 2;

string join(string a, string b)
{
    int sizeA = a.size(), sizeB = b.size(); 
    string ans = "";

    for (int i = 0; i <= sizeA - 1; ++i)
    {
        ans += a[i];
    }

    for (int i = 0; i <= sizeB - 1; ++i)
    {
        ans += b[i];
    }

    return ans;
}

int main()
{
    int _case = 0;
    while (true)
    {
        int n = 0; fin >> n;
        if (n == 0) break;

        ++_case;

        int t = 0;
        vector<string> i_s(N, "");
        map<string, int> s_i;
        vector<vector<int>> d(N, vector<int>(N, MAX));

        for (int c = 1; c <= n; ++c)
        {
            int e; fin >> e;

            int last = -1;
            for (int k = 1; k <= e; ++k)
            {
                string temp; fin >> temp;

                if (s_i.count(temp) == 0)
                {
                    i_s[t] = temp;
                    s_i[temp] = t;
                    ++t;
                }
                
                if (k > 1)
                {
                    d[last][s_i[temp]] = 1;
                }

                last = s_i[temp];
            }
        }

        for (int u = 0; u <= t - 1; ++u)
        {
            d[u][u] = 0;
        }

        int m; fin >> m;
        for (int c = 1; c <= m; ++c)
        {
            string u, v; fin >> u >> v;

            d[s_i[u]][s_i[v]] = 1;
            //d[s_i[v]][s_i[u]] = 1;
        }

        for (int k = 0; k <= t - 1; ++k)
        {
            for (int u = 0; u <= t - 1; ++u)
            {
                for (int v = 0; v <= t - 1; ++v)
                {
                    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
                }
            }
        }
       

        int ans = 0;
        vector<string> out;

        for (int u = 0; u <= t - 1; ++u)
        {
            for (int v = u + 1; v <= t - 1; ++v)
            {
                if (d[u][v] == MAX && d[v][u] == MAX)
                {
                    ++ans;

                    //fout << i_s[u] << "->" << i_s[v] << ": " << d[u][v] << '\n';
                    //fout << i_s[v] << ' ' << i_s[u] << ": " << d[v][u] << '\n';

                    if (ans <= 2)
                    {
                        out.push_back(join(i_s[u], join("," ,i_s[v])));
                    }
                }
            }
        }

        if (ans > 0)
        {
            fout << "Case " << _case << ", " << ans << " concurrent events:\n";
            int size = out.size();
            for (int i = 0; i <= size - 1; ++i)
            {
                fout << '(' << out[i] << ") ";
            }
            fout << '\n';
        }
        else
        {
            fout << "Case " << _case << ", no concurrent events.\n";
        }
    }

    return 0;
}
