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
  private:
    vector<pair<int,int>> setX;
    vector<pair<int,int>> setY;   

    bool checkSquare(const pair<int,int> & a, const pair<int,int> & b)
    {
        int x=abs(a.first-b.first);
        int y=abs(a.second-b.second);
        if(x==y)
        {
            return true;
        }
        else 
        {

        }
    }


  public:
    void solve()
    {
        int N;
        cin >> N;

        for (int i = 1; i <= N; ++i)
        {
            int x,y;
            cin >> x >> y;
            setX.push_back({x,y});
            setY.push_back({x,y});
        }

        sort(setX.begin(),setX.end());
        sort(setY.begin(),setY.end(), [](const pair<int,int> & a, const pair<int,int> & b) -> bool
        { 
            return a.second < b.second; 
        });
        int ans-0;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = i+1; j <= N; ++j)
            {
                if(checkSquare(setX[i],setX[j]))
                {
                    ++ans;
                }
            }
        }
        cout << ans << "\n";
        cerr << "OK";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C.in", "r", stdin);
    //freopen("C.out", "w", stdout);
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