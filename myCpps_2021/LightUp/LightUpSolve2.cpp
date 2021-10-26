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

#define row first;
#define col second;

class solution
{

    class point
    {
      public:
        int r;
        int c;
        set<pair<int, int>> availablePoint;

        point(int r1, int c1)
        {
            r = r1;
            c = c1;
        }
    };

    vector<vector<int>> g;
    const vector<pair<int, int>> dxy = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int R, C;

    void printG()
    {

        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
            {
                if (g[r][c] >= 0)
                    cout << g[r][c] << " ";
                else if (g[r][c] == 5)
                    cout << "*" << " ";
                else if (g[r][c] == -2)
                    cout << "-" << " ";
                else if (g[r][c] == -7)
                    cout << "." << " ";                    
                else if (g[r][c] == -8)
                    cout << "L" << " ";
                else if (g[r][c] == -9)
                    cout << "#"
                         << " ";
            }
            cout << "\n";
        }
        cout <<endl;
    }

  public:
    void solve()
    {
        cin >> R >> C;
        g = vector<vector<int>>(R + 2, vector<int>(C + 2, 9));

        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
            {
                char c1;
                cin >> c1;
                if (c1 == '-')
                    g[r][c] = -2;
                else if (c1 == '*')
                    g[r][c] = 5;
                else
                    g[r][c] = (int)(c1 - '0');
            }
        }

        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
            {
                if (g[r][c] == 0)
                {
                    for (auto p : dxy)
                    {
                        int r2 = r + p.first;
                        int c2 = c + p.second;

                        if (g[r2][c2] == -2)
                            g[r2][c2] = -9;
                    }
                    //return;
                }
            }
        }
        queue<pair<int,int>> q;
        
        auto fillQ= [&](int totalLight)
        {
            for (int r = 1; r <= R; ++r)
            {
                for (int c = 1; c <= C; ++c)
                {
                    int cnt=0;
                    if (g[r][c] == totalLight)
                    {
                        vector<pair<int,int>> v;
                        for (auto p : dxy)
                        {
                            int r2 = r + p.first;
                            int c2 = c + p.second;

                            if (g[r2][c2] == -2)
                            {
                                v.push_back({r2,c2});
                            }
                            else if (g[r2][c2] == -8)
                            {
                                ++cnt;
                            }
                        }
                        if((int)v.size()==totalLight || (int)v.size()+cnt==totalLight)
                        {
                            for(auto p:v)
                                q.push(p);
                        }
                    }
                }
            }
        };      

        auto setLight=[&](pair<int,int> currPoint)
        {
            int r=currPoint.row;
            int c=currPoint.col;
            g[r][c]=-8;
            ++c;
            while (r<=C && g[r][c]<0)
            {
                g[r][c]=-7;
                ++c;
            }
            c=currPoint.col;
            --c;
            while (c>0 && g[r][c]<0)
            {
                g[r][c]=-7;
                --c;
            }            

            ++r;
            c=currPoint.col;
            while (r<=R && g[r][c]<0)
            {
                g[r][c]=-7;
                ++r;
            }     
            
            r=currPoint.row;
            --r;
            while (r>0 && g[r][c]<0)
            {
                g[r][c]=-7;
                --r;
            }
        };
        
        printG();
        for (int i = 1; i <= 4; ++i)
            fillQ(i);

        while (!q.empty())
        {
            while (!q.empty())
            {
                auto currPoint = q.front();
                q.pop();

                setLight(currPoint);
                printG();
            }
            for (int i = 1; i <= 4; ++i)
                fillQ(i);
        }
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("test2.in", "r", stdin);
    //freopen("test1.out", "w", stdout);
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