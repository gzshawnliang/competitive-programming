/*
-------------------------------------------------------------------
* @Name:           1374D Zero Remainder Array
* @Author:         Shawn
* @Create Time:    2020/6/28 22:35:16  (UTC+08:00)
* @Url:            https://codeforces.com/gym/1374/problem/D
* @File:           CF_1374D_ZeroRemainderArray.cpp
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
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

class solution
{
  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, k; cin >> n >> k;
            multiset<ill> st;
            for (ill i = 0; i <= n - 1; ++i)
            {
                ill tmp; cin >> tmp; tmp %= k;
                st.insert(tmp);
            }

            while (true)
            {
                if (st.empty() == false)
                {
                    if (*st.begin() == 0)
                    {
                        st.erase(st.begin());
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            ill ans = 0, x = 0;
            n = st.size();
            for (ill c = 1; c <= n; ++c)
            {
                ill fnd = k - x;

                if (x == 0)
                {
                    x = (x + 1) % k;
                    ++ans;

                    fnd = k - x;
                }

                bool flg = false;
                auto it = st.lower_bound(fnd);
                if (it != st.end())
                {
                    if (*it == fnd)
                    {
                        flg = true;
                        st.erase(it);
                    }
                }
                
                if (flg == false)
                {
                    it = st.upper_bound(fnd);
                    
                    if (it == st.begin())
                    {
                        it = st.end(); --it;

                        ans += (fnd - *it + k) % k;
                        x = (x + fnd - *it + k) % k;
                        st.erase(it);
                    }
                    else
                    {
                        --it;

                        ans += (fnd - *it);
                        x += (fnd - *it);
                        st.erase(it);
                    }
                }

                x = (x + 1) % k;
                ++ans;
            }

            cout << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1374D_ZeroRemainderArray.in", "r", stdin);
    freopen("CF_1374D_ZeroRemainderArray.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}