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
    const vector<vector<int>> baseSqr = {{1, 0, 1}, {0, 2, 0}, {1, 0, 3}};

    //x,y在多大的正方形
    int SqrLen(int x,int y)
    {
        int max1=max(x,y);
        int r=1;
        while (r<max1)
        {
            r=r*3;
        }
        return r;
    }

    //在长度是n的正方形内，(0,y-x),(x,y)经过了多少个蓝色正方形
    int blueSqrCount(int x,int y,int n)
    {
        if(n==3)
        {
            
        }
        int base=n/3;
        if(y<base)
            return baseSqr[x][y];

    }

  public:
    void genData()
    {
        int N=1000;
        for (int x = 0; x <= N-1; ++x)
        {
            for (int y = 0; y <= N-1; ++y)
            {
                int r=1;
                bool tag=false;
                while (r<=N)
                {
                    int xR=(x / r) % 3;
                    int yR=(y / r) % 3;
                    r = r*3;

                    if(xR == yR)
                    {
                        continue;
                    }
                    else if(xR % 2 == 0 && yR % 2 == 0)
                    {
                        continue;
                    }
                    else 
                    {
                        tag=true;
                        break;
                    }
                }
                if(tag)
                    cout<<' ';
                else 
                    cout<<'x';
                
            }
            cout<<"\n";
        }
    }


    void solve()
    {
        //baseSqr = {{1, 0, 1}, {0, 2, 0}, {1, 0, 3}};

        int x=0;
        int y=2;
        if(x>y)
            swap(x,y);
        cout << y-x << "\n";

        cout << SqrLen(x,y) << "\n";
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("counttheCows.in", "r", stdin);
    //freopen("counttheCows.out", "w", stdout);
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