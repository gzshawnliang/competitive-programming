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
    ill sumCompleteBlueSqrCnt(ill diff, ill n)
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
            return 3ll * sumCompleteBlueSqrCnt(diff, n);
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

            return sumCompleteBlueSqrCnt(y1 - x1, n);
        }
        else        //情况五：等同情况一，穿过4号格子，处理办法：等同于在1号格子对角线或者对角线的下部
        {
            return sumCompleteBlueSqrCnt(diff % n, n);
        }
    }



    //在长度是n的正方形内，(0,y-x),(x,y)经过了多少个蓝色(大)正方形
    ill blueSqrCount(ill x, ill y, ill n)
    {
        ///++loopCount;

        if (x > y)
            swap(x, y);

        if (n == 1)
            return 1ll;
        else if (n == 3ll)
            return baseSqr[x][y];

        //cout << "base:" << n << "\n";
        ill base = n/3ll;
        //ill baseNo = pow(3,base);

        ill x1, y1;

        if (y < base) //x<y<base,仅在第1个
        {
            return blueSqrCount(x, y, base);
        }
        else if (x < base) //y>base
        {
            if(y-x<base)
            {
                y1 = base - 1ll;
                x1 = x - (y - y1);

                return  blueSqrCount(x1, y1, base);

            }
            else if(y-x==base)
            {
                return 0ll;
            }
            else if (y-x > base && y < 2ll * base)
            {
                // y1 = max(base - 1ll, 0ll);
                // x1 = max(x - (y - y1), 0ll);

                // return  blueSqrCount(x1, y1, base);
                return 0ll;
            }
            else
            {
                x1 = x;
                y1 = y - 2ll * base;
                return  blueSqrCount(x1, y1, base);
            }
        }
        else if (y < 2ll * base) // 1* base <x<2*base ,到达第2个
        {
            x1 = x - base;
            y1 = y - base;
            ill r1 = blueSqrCount(x1, y1, base);
            
            // ill diff = y - base + 1ll;
            // ill x2 = x - diff;
            // ill y2 = base - 1ll;
            // ill r2 = blueSqrCount(x2, y2, base);
            ill r2 = sumCompleteBlueSqrCnt(y-x,base);
            return r1 + r2;
        }
        else if (x < 2ll * base) // y>2*base
        {
            if ((y - x) == base) //在空白处正对角线上
            {
                return 0;
            }
            else if ((y - x) < base) //在空白处正对角线上面,穿过1,3
            {
                ill diff = y - base + 1ll;
                x1 = x - diff;
                y1 = y - diff;
                return 2ll * blueSqrCount(x1, y1, n);
            }
            else
            {
                ill diff = x - (base - 1ll);
                x1 = x - diff;
                y1 = y - diff;
                return blueSqrCount(x1, y1, n);
            }
        }
        else // y>2*base && x>2 * base  穿越3个
        {
            x1 = x - base * 2ll;
            y1 = y - base * 2ll;
            ill r1 = blueSqrCount(x1, y1, base);    //第3个

            ill r2 = 2ll* sumCompleteBlueSqrCnt(y1-x1,base);    //前两个

            //cout << base << "\n";
            return r1 + r2;
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
                // cout << y-x << "\n";
                //cout << "sqrLen:" << n << "\n";
                r1 = blueSqrCount(x-1ll, y-1ll, n);

                //cerr << SqrLen2(x-1ll, y-1ll)  << "," << n << "," << x-1ll<< ","<<y-1ll <<"," << r1 << "," << (ill)pow(3,38) << "\n";
            }
            //cout << r1 << "\n";
            // cout << "loopCount1:" << loopCount << "\n";
            // cout << "sqrLen:" << n <<"\n";

            n = sqrLen(x+d, y+d);
            r2 = blueSqrCount(x+d, y+d, n);
            //cerr << SqrLen2(x+d, y+d) << "," << n << "," << x+d << ","<<y+d <<"," << r2 << "," << (ill)pow(3,37) <<  "\n";
            //cout << "loopCount2:" << loopCount << "\n";
            // cout << r1 << "\n";
            // cout << r2 << "\n";
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
    //auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    // cerr << "Execution time: "
    //      << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
    //      << " ms\n";
#endif

    return 0;
}