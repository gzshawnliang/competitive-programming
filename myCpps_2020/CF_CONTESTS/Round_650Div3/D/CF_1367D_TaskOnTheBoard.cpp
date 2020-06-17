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

        int sizS = s.size();
        set<char> st;
        for (int i = 0; i <= sizS - 1; ++i)
        {
            st.insert(s[i]);
        }

        string stm = "";
        for (auto it = st.begin(); it != st.end(); ++it)
        {
            stm += *it;
        }

        for (int i = 0;)
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1367D_TaskOnTheBoard.in", "r", stdin);
    //freopen("CF_1367D_TaskOnTheBoard.out", "w", stdout);
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