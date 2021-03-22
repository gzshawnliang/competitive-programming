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
    const vector<vector<ill>> baseSqr = {{1, 0, 1}, {0, 2, 0}, {1, 0, 3}};

    int loopCount=0;

    //x,y在多大的正方形
    ill SqrLen(ill x, ill y)
    {
        ill max1 = max(x, y);
        ill r = 1;
        while (r <= max1)
            r *= 3;

        return r;
    }
    ill SqrLen2(ill x, ill y)
    {
        int i=0;
        ill max1 = max(x, y);
        ill r = 1;
        while (r <= max1)
        {
            r *= 3;
            ++i;
        }

        return i;
    }
    //在长度是n的正方形内，(0,y-x),(x,y)经过了多少个蓝色(大)正方形
    ill sumBlueSqrCnt(ill x, ill y, ill n)
    {
        if (x > y)
            swap(x, y);

        ill diff=y-x;
        return 0;
    }



    //在长度是n的正方形内，(0,y-x),(x,y)经过了多少个蓝色(大)正方形
    ill blueSqrCount(ill x, ill y, ill n)
    {
        ++loopCount;

        if (x > y)
            swap(x, y);

        if (n == 1)
            return 1;
        else if (n == 3)
            return baseSqr[x][y];

        //cout << "base:" << n << "\n";
        ill base = n/3;
        //ill baseNo = pow(3,base);

        ill x1, y1;

        if (y < base) //x<y<base,仅在第1个
        {
            return 1ll * blueSqrCount(x, y, base);
        }
        else if (x < base) //y>base
        {
            if (y < 2ll * base)
            {
                y1 = max(base - 1ll, 0ll);
                x1 = max(x - (y - y1), 0ll);

                return  blueSqrCount(x1, y1, base);
            }
            else
            {
                x1 = x;
                y1 = y - 2 * base;
                return  blueSqrCount(x1, y1, base);
            }
        }
        else if (y < 2ll * base) // 1* base <x<2*base ,穿越2个
        {
            x1 = x - base;
            y1 = y - base;
            ill diff = y - base + 1ll;
            ill x2 = x - diff;
            ill y2 = base - 1ll;
            ill r1 = blueSqrCount(x1, y1, base);
            ill r2 = blueSqrCount(x2, y2, base);
            return r1 + r2;
        }
        else if (x < 2 * base) // y>2*base
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
            x1 = x - base * 2;
            y1 = y - base * 2;
            ill r1 = blueSqrCount(x1, y1, base);    //第3个

            // ill diff = y - base * 2ll + 1ll;
            // ill x2 = x - diff;
            // ill y2 = base * 2ll - 1ll;
            // ill r2 = blueSqrCount(x2, y2, n);       //前两个

            ill diff = y - base * 2ll + 1ll;
            ill x2 = x - diff;
            ill y2 = base * 2ll - 1ll;

            x2 -=base;
            y2 -=base;

            ill r2 = 2ll*blueSqrCount(x2, y2, base);       //前两个
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
        // pair<int,int> p={18,20};
        // int l= SqrLen(p.first, p.second);
        // cout <<blueSqrCount(p.first, p.second, l) <<"\n";
        // return ;

        //baseSqr = {{1, 0, 1}, {0, 2, 0}, {1, 0, 3}};
        ill Q;
        cin >> Q;
        while (Q--)
        {
            ill d, x, y;
            cin >> d >> x >> y;

            // if(d==1000000000000000000ll && x==1000000000000000000ll && y==1000000000000000000ll )
            // {
            //     cout << 1000000000000000001ll<< "\n";
            //     continue;
            // }
            
            ill n = 0,r1=0,r2=0;
            // ill x=1;
            // ill y=7;
            // ill d=2;

            if (x > y)
                swap(x, y);
            if(x>0)
            {
                --x;
                --y;
                n= SqrLen(x, y);
                // cout << y-x << "\n";
                //cout << "SqrLen:" << n << "\n";
                r1 = blueSqrCount(x, y, n);
                ++x;
                ++y;
            }
            //cout << r1 << "\n";
            // cout << "loopCount1:" << loopCount << "\n";
            // cout << "SqrLen:" << n <<"\n";
            loopCount=0;

            x += d;
            y += d;
            n = SqrLen(x, y);
            r2 = blueSqrCount(x, y, n);
            //cout << "loopCount2:" << loopCount << "\n";
            cout << r2 - r1 << "\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("counttheCows.in", "r", stdin);
    //freopen("counttheCows.out", "w", stdout);
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