#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
    vector<char> v;
    void printStr(const bitset<8> & b)
    {
        for (int index = 0; index <8; ++index)
            if(b[index]==1)
                cerr << v[index] ;  
    }
  public:
    void solve2()
    {
        bitset<8> b("0000010");
        for (int i = 0; i <= 7; ++i)
        {
            bitset<8> b2(1 << i);
            cerr << " " << b << "\n";
            cerr << "^" << b2 << "\n";
            cerr << "=" << (b^b2) << "\n";
            cerr << "\n\n";
        }
        cerr << "--------------------------\n\n";
        for (int i = 0; i <= 7; ++i)
        {
            bitset<8> b2(1 << i);
            cerr << " " << b << "\n";
            cerr << "&" << b2 << "\n";
            cerr << "=" << (b&b2) << "\n";
            cerr << "\n\n";
        }        
    }

    void solve()
    {
        string s;
        cin >> s;
        int len = s.length();
        map<char, int> m;
        map<int, char> m2;
        int last = 0;
        for (int i = 0; i <= len - 1; ++i)
        {
            if (m.count(s[i]) == 0)
            {
                m[s[i]] = last;
                m2[last]=s[i];
                ++last;
            }
        }
        int n = m.size();
        v=vector<char>(n);
        vector<vector<int>> occ(n, vector<int>(n, 0));

        for (int i = 0; i <= n - 1; ++i)
            v[i]=m2[i];
       
        for (int i = 1; i <= len - 1; ++i)
        {
            char c1 = s[i - 1];
            char c2 = s[i];
            ++occ[m[c1]][m[c2]];
            //v[i]=m2[i];
        }

        int total = (1 << n); //2^n
        vector<int> dp(total);
        dp[0] = 1;

        for (int mask = 1; mask <= total - 1; ++mask)
        {
            bitset<8> b(mask);
            printStr(b);
     

            cerr << "   " << b << "=" << b.to_ulong() << "\n";

            int result = INT_MAX;
            for (int i = 0; i <= n - 1; ++i)
            {
                bitset<8> b3((1 << i));
                if ((mask & (1 << i)) == 0)
                {
                    cerr << "   '" << v[i] << "' not existed,continue;" << "\n";
                    continue;
                }
               
                if ((mask & (1 << i)) != 0)     //包含第i个字符的情况
                {
                    cerr <<"\n";
                    cerr << "   " << "&" << b3 << "=" << (mask & (1 << i)) << " (" << v[i] <<")" <<"\n";
                    bitset<8> b2(mask ^ (1 << i));
                    cerr << "        ^" << b3 << "(1 << "<< i <<")" <<" ";
                    printStr(b3);                     
                    cerr << "\n";
                    cerr << "        =" << b2 << "(" << b2.to_ulong() << ") dp[" << b2.to_ulong() << "]=" << dp[mask ^ (1 << i)] << " ";
                    printStr(b2);
                    cerr << "\n";

                    int ans = dp[mask ^ (1 << i)];

                    for (int j = 0; j <= n - 1; ++j)
                    {
                        if ((mask & (1 << j)) != 0)     //包含第i个字符的情况
                        {
                            bitset<8> b4(mask & (1 << j));
                            cerr << "         " << b4 << ":";
                            printStr(b4);                 

                            cerr << "           occ[" << v[i] << "->" << v[j] << "]=" << occ[i][j] << " ";
                            ans += occ[i][j];
                            cerr << "ans=" << ans << "\n";
                        }
                        else
                        {
                            cerr << "\n";
                        }
                    }
                    result = min(result, ans);
                }
            }

            dp[mask] = result;
            cerr << "           dp[" << mask << "]=" << dp[mask] << "\n\n";
        }
        cout << dp[total - 1] << "\n";



        // for (int mask = 1; mask <= total - 1; ++mask)
        // {
        //     bitset<20> b(mask);
        //     cerr << b.to_string() << "=" << b.to_ulong() << "\n";

        //     int result = INT_MAX;
        //     for (int i = 0; i <= n - 1; ++i)
        //     {
        //         if ((mask & (1 << i)) != 0)
        //         {
        //             bitset<20> b3((1 << i));
        //             bitset<20> b2(mask ^ (1 << i));
        //             cerr << "         ^" << b3.to_string() << "\n";
        //             cerr << "         =" << b2.to_string() << "=" << b2.to_ulong() << "=dp[" << b2.to_ulong() << "]=" << dp[mask ^ (1 << i)] << "\n";

        //             int ans = dp[mask ^ (1 << i)];

        //             for (int j = 0; j <= n - 1; ++j)
        //             {
        //                 if ((mask & (1 << j)) != 0)
        //                 {
        //                     cerr << "           occ[" << i << "," << j << "]=" << occ[i][j] << " ";
        //                     ans += occ[i][j];
        //                     cerr << "ans=" << ans << "\n";
        //                 }
        //             }
        //             result = min(result, ans);
        //         }
        //     }

        //     dp[mask] = result;
        //     cerr << "           dp[" << mask << "]=" << dp[mask] << "\n";
        // }
        // cout << dp[total - 1] << "\n";

        // vector<int> v2;
        // for (int i = 0; i <= n - 1; ++i)
        //     v2.push_back(i);
        // int result = INT32_MAX;
        // do
        // {
        //     printVec(v2);
        //     cerr << "\n";
        //     int ans = 0;
        //     for (int i = 0; i <= n - 1; ++i)
        //     {
        //         for (int j = 0; j <= i; ++j)
        //         {
        //             if (occ[v2[i]][v2[j]] > 0)
        //             {
        //                 cerr << "       " <<v2[i] << "," << v2[j] << "=" << occ[v2[i]][v2[j]] << "\n";
        //                 ans += occ[v2[i]][v2[j]];
        //             }
        //         }
        //     }
        //     result = min(result, ans);
        //     cerr << "   ans=" <<ans << "\n";

        // } while ((next_permutation(v2.begin(), v2.end())));
        // cout << result + 1 << "\n";

        return;
    }

    void printVec(const vector<int> & v)
    {
        for(auto d:v)
            cerr << d << " ";
        
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}