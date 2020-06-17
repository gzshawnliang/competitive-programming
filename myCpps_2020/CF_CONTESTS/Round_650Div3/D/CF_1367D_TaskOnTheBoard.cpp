/*
===========================================================
* @Name:           1367D Task On The Board
* @Author:         Shawn
* @create Time:    2020/6/16 22:35:38
* @url:            https://codeforces.com/gym/1367/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

void solve()
{
    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        string s; cin >> s;

        int m; cin >> m;
        vector<int> b(m, 0);
        for (int i = 0; i <= m - 1; ++i) cin >> b[i];

        sort(s.begin(), s.end(), greater<char>());

        int sizS = s.size();
        string dic = ""; dic += s[0];
        vector<int> cntC('z' + 1, 0); ++cntC[s[0]];
        for (int i = 1; i <= sizS - 1; ++i)
        {
            if (s[i] != s[i - 1]) dic += s[i];
            ++cntC[s[i]];
        }

        int sizD = dic.size();
        for (int c = 1; c <= sizS - sizD; ++c)
        {
            dic.push_back(s.back());
        }

        int indD = 0;
        vector<char> t(m, '-');
        for (int c = 1; c <= m; ++c)
        {
            vector<int> pos;
            for (int i = 0; i <= m - 1; ++i)
                if (b[i] == 0 && t[i] == '-')
                    pos.push_back(i);

            int sizP = pos.size();
            while (cntC[dic[indD]] < sizP) ++indD;

            for (int k:pos) t[k] = dic[indD];
            ++indD;

            for (int i = 0; i <= m - 1; ++i)
            {
                for (int k:pos)
                {
                    b[i] -= abs(k - i);
                }
            }
        }

        for (char ch:t) cout << ch;
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1367D_TaskOnTheBoard.in", "r", stdin);
    freopen("CF_1367D_TaskOnTheBoard.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}