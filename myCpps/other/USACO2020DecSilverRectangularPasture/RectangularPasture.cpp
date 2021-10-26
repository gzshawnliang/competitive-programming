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
using Point = pair<int, int>;

class solution
{

  public:
    void solve()
    {
        int N;
        cin >> N;

        //cowCnt[i][j]表示[0,0] - [i,j]区域内的奶牛数
        vector<vector<int>> cowCnt = vector<vector<int>>(N, vector<int>(N, 0));

        vector<Point> P(N);
        for (int i = 0; i <= N - 1; ++i)
        {
            int x, y;
            cin >> x >> y;
            P[i] = make_pair(x, y);
        }

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>离散化,坐标0 ~ (N-1)
        sort(P.begin(), P.end());
        for (int i = 0; i <= N - 1; ++i)
            P[i].first = i ;

        sort(P.begin(), P.end(), [](const Point & p, const Point & q) 
        {
            return p.second < q.second;
        });

        for (int i = 0; i <= N - 1; ++i)
            P[i].second = i;
        
        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>前缀和
        for (int i = 0; i <= N - 1; ++i)
            cowCnt[P[i].first][P[i].second] = 1;      //如当前x,y坐标下有牛，cowCnt[x][y]=1;

        for (int y = 1; y <= N - 1; ++y)
            cowCnt[0][y] += cowCnt[0][y-1];

        for (int x = 1; x <= N - 1; ++x)
            cowCnt[x][0] += cowCnt[x-1][0];

        //[0,0] - [i,j]区域内的奶牛数
        for (int x = 1; x <= N-1; ++x)
            for (int y = 1; y <= N-1; ++y)
                cowCnt[x][y] += (cowCnt[x - 1][y] + cowCnt[x][y - 1] - cowCnt[x - 1][y - 1]);

        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        //O(1)计算[x1,y1] - [x2,y2]区域内的牛数
        auto getAreaCnt = [&](int x1, int y1, int x2, int y2)
        {
            if(x1>0 && y1>0)
                return cowCnt[x2][y2] - cowCnt[x2][y1 - 1] - cowCnt[x1 - 1][y2] + cowCnt[x1 - 1][y1 - 1];
            else if(x1==0 && y1>0)
                return cowCnt[x2][y2] - cowCnt[x2][y1 - 1];
            else if(x1>0 && y1==0)
                return cowCnt[x2][y2] - cowCnt[x1-1][y2];                
            else 
                return cowCnt[x2][y2];
        };

        ill answer = 0;

        for (int i = 0; i <= N - 1; ++i)
        {
            for (int j = i; j <= N - 1; ++j)
            {
                int x1 = min(P[i].first, P[j].first);
                int x2 = max(P[i].first, P[j].first);
                answer += getAreaCnt(0, i, x1, j) * getAreaCnt(x2, i, N - 1, j);        //第i行~j行之间，牛的子集数量
            }
        }
        cout << answer + 1 << "\n";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("RectangularPasture.in", "r", stdin);
    //freopen("RectangularPasture.out", "w", stdout);
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