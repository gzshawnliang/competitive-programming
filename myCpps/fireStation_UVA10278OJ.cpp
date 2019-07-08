#include <bits/stdc++.h>

using namespace std;


const int inf = INT_MAX / 2;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        if (t > 1) cout << '\n';

        int fn, in; cin >> fn >> in;

        vector<bool> isStation(in + 1, false);
        vector<vector<int>> d(in + 1, vector<int>(in + 1, inf)),
                            g(in + 1);

        for (int c = 1; c <= fn; ++c)
        {
            int u; cin >> u;
            isStation[u] = true;
        }

        string tempIn = "";
        getline(cin, tempIn);

        while (true)
        {
            getline(cin, tempIn);
            if (tempIn == "") break;

            istringstream inTempIn(tempIn);

            int u, v, l; inTempIn >> u >> v >> l;

            d[u][v] = min(d[u][v], l); d[v][u] = d[u][v];
            g[u].push_back(v); g[v].push_back(u);
        }


        if (in == 1)
        {
            cout << "1\n";
            continue;
        }


        for (int i = 1; i <= in; ++i)
        {
            d[i][i] = 0;
        }

        for (int k = 1; k <= in; ++k)
        {
            for (int u = 1; u <= in; ++u)
            {
                for (int v = 1; v <= in; ++v)
                {
                    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
                }
            }
        }

        vector<int> minDis(in + 1, inf);
        for (int u = 1; u <= in; ++u)
        {
            if (isStation[u] == true)
            {
                for (int v = 1; v <= in; ++v)
                {
                    minDis[v] = min(minDis[v], d[u][v]);
                }
            }
        }

        int nowMaxMinDis = 0;
        for (int i = 1; i <= in; ++i)
        {
            nowMaxMinDis = max(nowMaxMinDis, minDis[i]);
        }

        int bestMaxMinDis = nowMaxMinDis, bestI = 0;
        for (int u = 1; u <= in; ++u)
        {
            if (isStation[u] == true) continue;

            int tempMaxMinDis = -inf;
            for (int v = 1; v <= in; ++v)
            {
                tempMaxMinDis = max(tempMaxMinDis, min(d[u][v], minDis[v]));
            }

            if (tempMaxMinDis < bestMaxMinDis)
            {
                bestMaxMinDis = tempMaxMinDis;
                bestI = u;
            }
        }

        cout << max(bestI, 1) << '\n';
    }

   	cout.flush();
   	return 0;
}

