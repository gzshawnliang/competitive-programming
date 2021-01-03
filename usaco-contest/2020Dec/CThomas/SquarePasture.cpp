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
const int INF = INT_MAX / 2;

#define x first
#define y second

class solution
{
  private:
    vector<pair<int, int>> cows;
    int n;
    int repeat;
    int sum()
    {
        sort(cows.begin(), cows.end());
        int curAns = 0;
        for (int a = 0; a <= n - 1; ++a)
        {
            set<int> ySet; //在a+1...b-1之间的牛Y坐标，使用set自动排序
            for (int b = a + 1; b <= n - 1; ++b)
            {
                if (b - 1 != a)                 //相邻的牛不放进去
                    ySet.insert(cows[b - 1].y); //放入上一个牛

                int squareLen = cows[b].x - cows[a].x;  //正方形的长度;
                int top = max(cows[a].y, cows[b].y);    //最小矩形顶部
                int bottom = min(cows[a].y, cows[b].y); //最小矩形底部

                int lo = top - squareLen;               //正方形移动区域（最底）
                int hi = bottom + squareLen;            //正方形移动区域（最高）
                
                if (lo > bottom) //竖的长方形
                {
                    continue;
                }
                else if (lo == bottom) //a:b正好组成正方形
                {
                    ++repeat;
                    ++curAns;
                    cerr << a << ":" << b << ":" << curAns << "\n";
                    continue;
                }

                //初始化正方形 x: [cows[a].x,cows[b].x] , y:[lo,lo+sqrLen]
                vector<int> yVec(ySet.begin(), ySet.end());
                int yLen = yVec.size();

                if (yLen == 0) //a,b之间Y坐标上没有牛
                {
                    ++curAns;
                    cerr << a << ":" << b << ":" << curAns << "\n";
                    continue;
                }

                vector<int> yLowVec;   //在正方形内，低于hi的牛,存放y坐标
                vector<int> yHightVec; //在正方形内，高于top的牛，存放y坐标

                for (auto it = yVec.begin(); it != yVec.end(); ++it)
                {
                    int currY = (*it);
                    if (currY >= lo && currY < bottom)
                        yLowVec.push_back(currY);

                    if (currY > top && currY <= hi)
                        yHightVec.push_back(currY);
                }

                if (yLowVec.size() == 0 && yHightVec.size() == 0) //在正方形内没有牛
                {
                    ++curAns;
                    cerr << a << ":" << b << ":" << curAns << "\n";
                    continue;
                }

                //向上移动正方形，使得每次下边界有牛消失或上边界有牛进入，或者两个同时有
                //在ySetLow和ySetHight跳跃
                auto lowCow = yLowVec.begin();
                auto higCow = yHightVec.begin();

                //判断正方形上下边是否有牛，旋转90度会重复
                auto checkRepeat=[&]()
                {
                    if (lowCow != yLowVec.end() && (*lowCow) - lo == 0) //最底低边是否有牛
                        ++repeat;
                    else if (lo == bottom)                                  //最底低已经达到hi
                        ++repeat;                    
                };
                
                checkRepeat();

                while (true)
                {
                    ++curAns;

                    int downDist = lowCow == yLowVec.end() ? INF : (*lowCow) - lo;  //底部指针离最近的牛的距离
                    int upDist = higCow == yHightVec.end() ? INF : (*higCow) - top; //顶部部指针离最近的牛的距离

                    if (downDist == INF && upDist == INF)
                    {
                        break;
                    }
                    else
                    {
                        //按最小移动
                        lo +=min(downDist + 1,upDist);
                        if (downDist + 1 < upDist)  //下面牛消失，上面牛无进入
                        {
                            ++lowCow;           
                        }
                        else if (downDist + 1 == upDist)    //下面牛消失同时上面牛进入
                        {
                            ++lowCow;
                            ++higCow;

                            //判断正方形上下边是否有牛，旋转90度会重复
                            checkRepeat();
                        }
                        else                                //下面牛无消失，上面牛进入
                        {
                            ++higCow;

                            //判断正方形上下边是否有牛，旋转90度会重复
                            checkRepeat();
                        }
                    }
                    top = lo + squareLen;   //同时移动top
                }

                cerr << a << ":" << b << ":" << curAns << "\n";
            }
        }
        return curAns;
    }

  public:
    void solve()
    {
        cin >> n;

        int ans = n + 1;
        cows = vector<pair<int, int>>(n);
        for (int i = 0; i <= n - 1; ++i)
            cin >> cows[i].x >> cows[i].y;
        ans += sum();

        //转90度
        for (int i = 0; i <= n - 1; ++i)
            swap(cows[i].x, cows[i].y);
        ans += sum();
        
        assert(repeat % 2 == 0);
        cout << ans - repeat / 2 << "\n";
        
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("SquarePasture.in", "r", stdin);
    //freopen("SquarePasture.out", "w", stdout);
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