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
        bitset<8> b0("0011010");
        bitset<8> b2("0000010");
        bitset<8> b3("0001000");
        bitset<8> b4("0100000");
        cerr << (b0 & b2) << ", 是否包含b2\n";      //是否包含b2
        cerr << (b0 & b3) << ", 是否包含b3\n";      //是否包含b3
        cerr << (b0 & b4) << ", 是否包含b4\n";      //是否包含b4
        cerr << (b0 ^ b2) << ", 排除b2\n";      //排除b2

    }

    void solve()
    {
        string s;
        cin >> s;
        int len = s.length();
        map<char, int> m;
        int last = 0;
        for (int i = 0; i <= len - 1; ++i)
        {
            if (m.count(s[i]) == 0)
            {
                m[s[i]] = last;
                ++last;
            }
        }

        int n = m.size();
        vector<vector<int>> occ(n, vector<int>(n, 0));
        for (int i = 1; i <= len - 1; ++i)
        {
            char c1 = s[i - 1];
            char c2 = s[i];
            ++occ[m[c1]][m[c2]];
        }

        //2^n方案
        int total = (1 << n); //2^n
        vector<int> dp(total);
        dp[0] = 1;
        for (int m = 1; m <= total - 1; ++m)
        {
            bitset<20> b(m);
            //printStr(b);
            //cerr << "\n";
     
            int result = INT_MAX;
            for (int i = 0; i <= n - 1; ++i)
            {
                bitset<20> b1;
                b1.set(i);      
                
                if((b & b1) !=0)  //b集合包含b1集合
                {
                    // printStr(b1);
                    // cerr << "\n";

                    bitset<20> c1 = b ^ b1;     //b排除b1之后的结果
                    int ans = dp[c1.to_ulong()];

                    for (int j = 0; j <= n - 1; ++j)
                    {
                        bitset<20> b2;
                        b2.set(j);
                        if ((b & b2) != 0) //b集合包含b2集合
                        {
                            ans += occ[i][j];
                        }
                    }
                    result = min(result, ans);
                }
            }

            // cerr << "   ans=" <<ans << "\n";
            dp[m] = result;

        }
        cout << dp[total - 1] << "\n";

        //n!的阶乘方案

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
    sln1.solve2();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}