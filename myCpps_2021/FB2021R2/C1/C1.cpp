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
  public:
    void solve()
    {
        int T;
        cin >> T;
        for (int t = 1; t <= T; ++t)
        {
            int ansMax=0;
            int R,C,K;
            cin >> R >> C >> K;
            cin.ignore();
            vector<bitset<2000000>> a;
            for (int r = 1; r <= R; ++r)
            {
                bitset<2000000> temp;
                string s;
                cin >> s;
                int i=0;
                for(auto it=s.rbegin();it!=s.rend();++it,++i)
                {
                    if((*it)=='X')
                        temp[i]=1;
                }
                a.push_back(temp);
                if(r==K)
                    ansMax = temp.count();
                //cout << s;
            }

            int ans=ansMax;
            //up
            int step=0;
            vector<bitset<2000000>> a1=a;
            
            while (true)
            {
                bool hasChange=false;
                ++step;
                for (int r = 0; r+1 <= R-1; ++r)
                {
                    
                    bitset<2000000> b1=a1[r];
                    bitset<2000000> b2=a1[r+1];
                    bitset<2000000> newB1=b1 | b2;
                    bitset<2000000> newB2=b1 & b2;

                    if(newB1 !=b1 || newB2 != b2)
                        hasChange=true;

                    a1[r]=newB1;
                    a1[r+1]=newB2;
                }
               // cerr << step << ":" << ans <<"\n";
                if(hasChange==false)
                    break;
                
                if(a1[K-1].count()+step <ans)
                    ans =a1[K-1].count()+step;                
            }
            

            //down
            step=0;
            vector<bitset<2000000>> a2=a;
            while (true)            
            {
                bool hasChange=false;
                ++step;
                for (int r = R-1; r-1 >=0; --r)
                {
                    
                    bitset<2000000> b1=a2[r];
                    bitset<2000000> b2=a2[r-1];
                    bitset<2000000> newB1=b1 | b2;
                    bitset<2000000> newB2=b1 & b2;

                    if(newB1 !=b1 || newB2 != b2)
                        hasChange=true;

                    a2[r]=newB1;
                    a2[r-1]=newB2;
                }  
               // cerr << step << ":" << ans <<"\n";
                if(hasChange==false)
                    break;                    

                if(a2[K-1].count()+step <ans)
                    ans =a2[K-1].count()+step;
            }          


            cout << "Case #" << t << ": " << ans  << "\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C1.in", "r", stdin);
    freopen("C1.out", "w", stdout);
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