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


    vector<vector<char>> g;
    const vector<pair<int, int>> dxy = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int R, C;

    void printG()
    {

        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
                cout << g[r][c] << " ";

            cout << "\n";
        }
        cout <<endl;
    }
    
    //# 表示不能放灯
    void setForbidden()
    {
        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
            {
                // if (g[r][c] == '0')
                // {
                //     for (auto p : dxy)
                //     {
                //         int r2 = r + p.first;
                //         int c2 = c + p.second;

                //         if (g[r2][c2] == '-')
                //             g[r2][c2] = '#';
                //     }
                // }
                // else if (g[r][c] == '1')
                // {
                //     vector<pair<int,int>> p2;
                //     int cnt=0;
                //     for (auto p : dxy)
                //     {
                //         int r2 = r + p.first;
                //         int c2 = c + p.second;

                //         if (g[r2][c2] == '-')
                //             p2.push_back({r2,c2});
                //         else if (g[r2][c2] == 'L')
                //             ++cnt;
                //     }
                //     if(cnt==1)
                //     {
                //         for (auto p : p2)
                //         {
                //             g[p.first][p.second] = '#';
                //         }
                //     }
                // }       
                if(isdigit(g[r][c]))
                {
                    int num=(int)(g[r][c]-'0');
                    vector<pair<int,int>> p2;
                    int cnt=0;
                    for (auto p : dxy)
                    {
                        int r2 = r + p.first;
                        int c2 = c + p.second;

                        if (g[r2][c2] == '-')
                            p2.push_back({r2,c2});
                        else if (g[r2][c2] == 'L')
                            ++cnt;
                    }
                    if(cnt==num)
                    {
                        for (auto p : p2)
                        {
                            g[p.first][p.second] = '#';
                        }
                    }                    
                }
            }
        }
    }

    bool checkCanLight(char c)
    {
        if(c=='-' || c=='.' || c=='#')
            return true;
        return false;
    }

    //.代表光照到的地方,设置灯
    void setLight(pair<int,int> currPoint)
    {
        int r = currPoint.row;
        int c = currPoint.col;
        g[r][c] = 'L';
        ++c;
        while (r <= C && checkCanLight(g[r][c]))
        {
            g[r][c] = '.';
            ++c;
        }
        c = currPoint.col;
        --c;
        while (c > 0 && checkCanLight(g[r][c]))
        {
            g[r][c] = '.';
            --c;
        }

        ++r;
        c = currPoint.col;
        while (r <= R && checkCanLight(g[r][c]))
        {
            g[r][c] = '.';
            ++r;
        }

        r = currPoint.row;
        --r;
        while (r > 0 && checkCanLight(g[r][c]))
        {
            g[r][c] = '.';
            --r;
        }
    }

    //找出 # 不能放灯的地方，尝试放灯
    void findSingleForbidden()
    {
        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
            {
                if (g[r][c] == '#')
                {
                    int cntForbid=0;
                    int lastR=r,lastC=c;
                    for (int r1 = r-1; r1>=1; --r1)
                    {
                        if (g[r1][c] == '-')
                        {
                            ++cntForbid;
                            lastR=r1;
                        }
                        else if(isdigit(g[r1][c]) || g[r1][c]=='*')
                            break;
                    }
                    for (int r1 = r+1; r1<=R; ++r1)
                    {
                        if (g[r1][c] == '-')
                        {
                            ++cntForbid;
                            lastR=r1;
                        }
                        else if(isdigit(g[r1][c]) || g[r1][c]=='*')
                            break;
                    }
                    if(cntForbid>1)
                        continue;

                    for (int c1 = c-1; c1>=1; --c1)
                    {
                        if (g[r][c1] == '-')
                        {
                            ++cntForbid;
                            lastC=c1;
                        }
                        else if(isdigit(g[r][c1]) || g[r][c1]=='*')
                            break;
                    }
                    for (int c1 = c+1; c1<=R; ++c1)
                    {
                        if (g[r][c1] == '-')
                        {
                            ++cntForbid;
                            lastC=c1;
                        }
                        else if(isdigit(g[r][c1]) || g[r][c1]=='*')
                            break;
                    }

                    if(cntForbid>1)
                        continue;                    


                    if(cntForbid==1)
                    {
                        setLight({lastR,lastC});
                    }
                    else if(cntForbid==0)
                    {
                        continue;
                    }
                }
            }
        }        
    }

    void findSingleDark()
    {
        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
            {
                if (g[r][c] == '-')
                {
                    int cnt=0;
                    for (auto p : dxy)
                    {
                        int r2 = r + p.first;
                        int c2 = c + p.second;

                        if (g[r2][c2] == '.' || g[r2][c2] == '*' || g[r2][c2] == '$' || isdigit(g[r2][c2]))
                        {
                            ++cnt;
                        }
                    }
                    if (cnt==4)  
                    {
                        setLight({r,c});
                    }                    
                }
            }
        }        
    }

    bool checkWin()
    {
        for (int r = 1; r <= R; ++r)
        {
            for (int c = 1; c <= C; ++c)
            {
                if (g[r][c] == '-' || g[r][c] == '#')
                {
                    return false;
                }
            }
        }
        return true;
    }

  public:
    void solve()
    {
        cin >> R >> C;
        g = vector<vector<char>>(R + 2, vector<char>(C + 2, '$'));

        for (int r = 1; r <= R; ++r)
            for (int c = 1; c <= C; ++c)
                cin >> g[r][c];

        

        queue<pair<int,int>> q;
        
        auto fillQ= [&](int totalLight)
        {
            for (int r = 1; r <= R; ++r)
            {
                for (int c = 1; c <= C; ++c)
                {
                    int cnt=0;
                    if (isdigit(g[r][c]) && (g[r][c] -'0' == totalLight))
                    {
                        vector<pair<int,int>> v;
                        for (auto p : dxy)
                        {
                            int r2 = r + p.first;
                            int c2 = c + p.second;

                            if (g[r2][c2] == '-')
                            {
                                v.push_back({r2,c2});
                            }
                            else if (g[r2][c2] == 'L')  //已经有灯
                            {
                                ++cnt;
                            }
                        }
                        if((int)v.size()+cnt==totalLight)
                        {
                            for(auto p:v)
                                q.push(p);
                        }
                    }
                }
            }
        };      
        int icount=100;
        while(checkWin()==false && (icount--))
        {
            // if(!(icount--))
            //     break;

            setForbidden();

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
        
            findSingleForbidden();
            findSingleDark();
            
            printG();
        }
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("test2.in", "r", stdin);
    //freopen("testSolve3.out", "w", stdout);
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