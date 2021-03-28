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
    //左上角3x3最基础的正方形，对角线包含蓝色正方形的个数
    const vector<vector<ill>> baseSqr = {{1ll, 0ll, 1ll}, {0ll, 2ll, 0ll}, {1ll, 0ll, 3ll}};

    //int loopCount=0;

    //对角线(0,y-x)->(x,y)在多大3^i的正方形？
    ill sqrLen(ill x, ill y)
    {
        ill max1 = max(x, y);
        ill r = 1ll;
        while (r <= max1)
            r *= 3ll;

        return r;
    }

    //在长度是n的正方形内，(0,diff) 开始的对角线，在n长度的正方形经过了多少个蓝色格子
    ill fullSqrBlueCnt(ill diff, ill n)
    {
        //情况一：
        if(n==1ll)
        {
            return 1ll;
        }
        else if(n==3ll)
        {
            if(diff==0ll)
                return 3ll;
            else if(diff==1)
                return 0ll;
            else if(diff==2)
                return 1ll;
        }   
        
        n /=3ll;
        if (diff < n)   //情况二：x<y<n,穿过1,3,5
        {
            return 3ll * fullSqrBlueCnt(diff, n);
        }
        else if(diff==n)    //情况三：穿过空白格子
        {
            return 0ll;
        }        
        else if (diff < 2*n) //情况四：穿过4号格子
        {
            ill x1 = (2ll * n - diff);
            ill y1 = 0ll;
            if (x1 > y1)
                swap(y1, x1);

            return fullSqrBlueCnt(y1 - x1, n);
        }
        else        //情况五：等同情况一，穿过4号格子，处理办法：等同于在1号格子对角线或者对角线的下部
        {
            return fullSqrBlueCnt(diff % n, n);
        }
    }

    //在长度是n的正方形内，线段(0,y-x)->(x,y)经过了多少个蓝色格子
    ill sum(ill x, ill y, ill n)
    {
        if (x > y)
            swap(x, y);

        if (n == 1)
            return 1ll;
        else if (n == 3ll)
            return baseSqr[x][y];

        ill topLeftSquareLen = n / 3ll; //左上角正方形大小3^(i-1)

        if (y < topLeftSquareLen) //图一
        {
            return sum(x, y, topLeftSquareLen);
        }
        else if (x < topLeftSquareLen) 
        {
            if (y < x+ topLeftSquareLen) //图二
            {
                return fullSqrBlueCnt(y-x, topLeftSquareLen);
            }
            else if (y >= x + topLeftSquareLen && y < 2ll * topLeftSquareLen) //图三
            {
                return 0ll;
            }
            else  //图五  ,y >= 2ll * topLeftSquareLen
            {
                return sum(x, y%topLeftSquareLen, topLeftSquareLen);
            }

        }
        else if (y == x + topLeftSquareLen) //图四
        {
            return 0ll;
        }
        else if (x < 2ll*topLeftSquareLen) 
        {
            if (y < 2ll * topLeftSquareLen) //图六 
            {
                return fullSqrBlueCnt(y-x, topLeftSquareLen) + sum(x%topLeftSquareLen, y%topLeftSquareLen, topLeftSquareLen);
            }
            else if (y < x + topLeftSquareLen) //图七
            {
                return 2ll*fullSqrBlueCnt(y-x, topLeftSquareLen);
            }
            else  //图八  
            {
                ill y1=2ll*topLeftSquareLen;
                ill x1=x-(y-y1);
                y1 %=topLeftSquareLen;
                x1 %=topLeftSquareLen;
                if(x1>y1)
                    swap(x1,y1);
                
                return fullSqrBlueCnt(y1-x1, topLeftSquareLen);
                
            }
        }
        else        //图九
        {
            return 2ll*fullSqrBlueCnt(y-x, topLeftSquareLen)+sum(x%topLeftSquareLen, y%topLeftSquareLen, topLeftSquareLen);
        }
    }

  public:
    void genData()
    {
        ill N = 1000;
        for (ill x = 0; x <= N - 1; ++x)
        {
            for (ill y = 0; y <= N - 1; ++y)
            {
                ill r = 1;
                bool tag = false;
                while (r <= N)
                {
                    ill xR = (x / r) % 3;
                    ill yR = (y / r) % 3;
                    r = r * 3;

                    if (xR == yR)
                    {
                        continue;
                    }
                    else if (xR % 2 == 0 && yR % 2 == 0)
                    {
                        continue;
                    }
                    else
                    {
                        tag = true;
                        break;
                    }
                }
                if (tag)
                    cout << ' ';
                else
                    cout << 'x';
            }
            cout << "\n";
        }
    }
    void solve()
    {
        ill Q;
        cin >> Q;
        while (Q--)
        {
            ill d, x, y;
            cin >> d >> x >> y;
            ill n = 0ll,r1=0ll,r2=0ll;

            if (x > y)
                swap(x, y);
            if(x>0)
            {
                n= sqrLen(x-1ll, y-1ll);
                r1 = sum(x-1ll, y-1ll, n);
            }
            n = sqrLen(x+d, y+d);
            r2 = sum(x+d, y+d, n);
            cout << r2 - r1 << "\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("counttheCows.in", "r", stdin);
    freopen("counttheCows.out", "w", stdout);
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
