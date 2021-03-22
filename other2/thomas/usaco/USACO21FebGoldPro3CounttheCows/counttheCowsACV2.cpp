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

    //x,y在多大的正方形
    ill SqrLen(ill x, ill y)
    {
        ill max1 = max(x, y);
        ill r = 1ll;
        while (r <= max1)
            r *= 3ll;

        return r;
    }
    ill SqrLen2(ill x, ill y)
    {
        int i=0;
        ill max1 = max(x, y);
        ill r = 1ll;
        while (r <= max1)
        {
            r *= 3ll;
            ++i;
        }

        return i;
    }
    //在长度是n的正方形内，(0,diff) 开始的对角线，经过了多少个蓝色正方形
    ill sumBlueSqrCnt(ill diff, ill n)
    {
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
        if (diff < n) //x<y<n,仅在第1个
        {
            return 3ll * sumBlueSqrCnt(diff, n);
        }
        else if (diff < 2ll*n) //y>n
        {
            if(diff==n)
            {
                return 0ll;
            }
            else 
            {
                ill x1 = (2ll * n - diff);
                ill y1 = 0ll;
                if(x1>y1)
                    swap(y1,x1);
                
                return sumBlueSqrCnt(y1-x1, n);
            }

        }
        else
        {
            //return sumBlueSqrCnt(diff % n, n);
            return sumBlueSqrCnt(diff -2ll* n, n);
        }
    }



    //在长度是n的正方形内，(0,y-x),(x,y)经过了多少个蓝色(大)正方形
    ill blueSqrCount(ill x, ill y, ill n)
    {
        ///++loopCount;

        if (n == 1)
            return 1ll;
        else if (n == 3ll)
            return baseSqr[x][y];

        if (x > y)
            swap(x, y);            

        //cout << "base:" << n << "\n";
        ill base = n/3ll;
        //ill baseNo = pow(3,base);
        ill diff=y-x;

        if(diff<base)
        {
            ill cnt = sumBlueSqrCnt(diff,base);

            if (y < base) //x<y<base,仅在第1个
            {
                return blueSqrCount(x, y, base);
            }
            else if (x < base) //y>base
            {
                return cnt;
            }
            else if(y < 2ll * base)
            {
                 return cnt + blueSqrCount(x - base, y - base, base);
            }
            else if(x < 2ll * base)
            {
                 return cnt * 2ll;
            }       
            else 
            {
                return cnt * 2ll + blueSqrCount(x -2ll* base, y - 2ll* base, base);;
            }     
        }
        else if (diff==base)
        {
            return 0ll;
        }
        else if (diff <2ll*base)
        {
            if (y < 2ll * base)
                return 0;
            else if (x >= base)
                return sumBlueSqrCnt(2ll * base - diff, base);
            else 
                return blueSqrCount(x, y - 2ll * base, base);
        }
        else
        {
            return blueSqrCount(x, y - 2ll * base, base);
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
    void solve3()
    {
        pair<ill,ill> p={1000000000000000000 ,1000000000000000000 };
        if(p.first > p.second)
            swap(p.first,p.second);
            
        ill n=SqrLen(p.first,p.second);

        cout << sumBlueSqrCnt(p.second-p.first,n);
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
            
            ill n = 0ll,r1=0ll,r2=0ll;
            // ill x=1;
            // ill y=7;
            // ill d=2;

            if (x > y)
                swap(x, y);
            if(x>0)
            {
                n= SqrLen(x-1ll, y-1ll);
                // cout << y-x << "\n";
                //cout << "SqrLen:" << n << "\n";
                r1 = blueSqrCount(x-1ll, y-1ll, n);

                //cerr << SqrLen2(x-1ll, y-1ll)  << "," << n << "," << x-1ll<< ","<<y-1ll <<"," << r1 << "," << (ill)pow(3,38) << "\n";
            }
            //cout << r1 << "\n";
            // cout << "loopCount1:" << loopCount << "\n";
            // cout << "SqrLen:" << n <<"\n";

            n = SqrLen(x+d, y+d);
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