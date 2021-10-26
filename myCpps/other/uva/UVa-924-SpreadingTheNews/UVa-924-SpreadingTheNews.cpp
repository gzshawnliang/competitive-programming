#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("UVa-924-SpreadingTheNews.in", "r", stdin);
    freopen("UVa-924-SpreadingTheNews.out", "w", stdout);

    int E;
    cin >> E;

    vector<vector<int>> friends(E);
    for (int i = 0; i <= E - 1; ++i)
    {
        friends[i].clear();
        int n;
        cin >> n;
        while (n--)
        {
            int temp;
            cin >> temp;
            friends[i].push_back(temp);
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        vector<int> dp(E, 0);
        vector<bool> isUsed(E, false);
        vector<int> maxDailyBoomSize(E + 1, 0);
        isUsed[x] = true;
        queue<int> Q;
        Q.push(x);
        while (!Q.empty())
        {
            x = Q.front();
            Q.pop();
            if (friends[x].size() > 0)
            {
                for (unsigned int j = 0; j <= friends[x].size() - 1; ++j)
                {
                    int i = friends[x][j];
                    if (isUsed[i] == false)
                    {
                        isUsed[i] = true;
                        Q.push(i);
                        dp[i] = dp[x] + 1;
                        ++maxDailyBoomSize[dp[i]];
                    }
                }
            }
        }

        int M = 0, D=0;
        for (int i = 1; i <= E; ++i)
        {
            if (maxDailyBoomSize[i] > M)
            {
                M = maxDailyBoomSize[i];
                D = i;
            }
        }

        if (M > 0)
            cout << M << " " << D << "\n";
        else
            cout << "0\n";
    }

    return 0;
}
