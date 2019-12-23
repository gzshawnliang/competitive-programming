#include <bits/stdc++.h>

using namespace std;

ifstream fin("checklist.in");
ofstream fout("checklist.out");

const int inf = INT_MAX / 4;

//vector<int> dp[1005][1005];

int disp2(pair<int, int> & a, pair<int, int> & b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
    int h, g; fin >> h >> g;

    pair<int, int> pinf = make_pair(inf, inf);
    vector<pair<int, int>> H(h + 1, pinf), G(g + 1, pinf);
    
    for (int i = 1; i <= h; ++i)
    {
        fin >> H[i].first >> H[i].second;
    }
    if (h == 1)
    {
        H.push_back(H[0]);
        ++h;
    }

    for (int i = 1; i <= g; ++i)
    {
        fin >> G[i].first >> G[i].second;
    }
    
    vector<vector<vector<int>>> dp(h + g + 5, vector<vector<int>>(h + 5, vector<int>(2, inf)));
    
    dp[1][1][0] = 0;

    for (int c = 2; c <= h + g; ++c)
    {
        for (int i = max(1, c - g); i <= c - 1 && i <= h; ++i)
        {
            if (c == 4 && i == 2)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            int j = c - i;
            
            // int k1= disp2(H[i - 1], H[i]);
            // int k2= disp2(G[j], H[i]);
            // int k3= disp2(H[i], G[j]);
            // int k4= disp2(G[j - 1], G[j]);
            // fout << k1 << " " << k2 << " " << k3 << " " << k4 <<  " j=" << j<< '\n' ;

            if (i > 1) dp[c][i][0] = min(dp[c][i][0], dp[c - 1][i - 1][0] + disp2(H[i - 1], H[i]));
            if (i > 1) dp[c][i][0] = min(dp[c][i][0], dp[c - 1][i - 1][1] + disp2(G[j], H[i]));

            dp[c][i][1] = min(dp[c][i][1], dp[c - 1][i][0] + disp2(H[i], G[j]));
            if (j > 1) dp[c][i][1] = min(dp[c][i][1], dp[c - 1][i][1] + disp2(G[j - 1], G[j]));


            // fout << "dp[" << c << "][" << i << "][" << 1 << "] = " << dp[c][i][0] << '\n';
            // fout << "dp[" << c << "][" << i << "][" << 1 << "] = " << dp[c][i][1] << '\n';
        }
    }

    for (int c = 1; c <= h + g; ++c)
    {
        for (int i = 1; i <= h; ++i)
        {
            for (int k = 0; k <= 1; ++k)
            {
                if (dp[c][i][k] < inf)
                {
                    fout << "dp[" << c << "][" << i << "][" << k << "] = " << dp[c][i][k] << '\n';
                }
            }
        }
    }

    fout << dp[h + g][h][0] << '\n';

    return 0;
}
