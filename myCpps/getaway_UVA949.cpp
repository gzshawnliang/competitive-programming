#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("getaway_UVA949.in");
ofstream fout("getaway_UVA949.out");

struct Timer
{

  private:
    time_point<high_resolution_clock> m_begin;
        
  public:
    Timer() : m_begin(high_resolution_clock::now()) {}

    
    void reset() 
    { 
        m_begin = high_resolution_clock::now(); 
    }

    //默认输出秒(浮点数)
    double elapsed() const
    {
        return elapsed_seconds_double();
    }

    //毫秒
    long long elapsed_milli() const
    {
        return duration_cast<chrono::milliseconds>(high_resolution_clock::now() - m_begin).count();
    }

    //微秒
    long long elapsed_micro() const
    {
        return duration_cast<chrono::microseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //纳秒
    long long elapsed_nano() const
    {
        return duration_cast<chrono::nanoseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //秒
    long long elapsed_seconds() const
    {
        return duration_cast<chrono::seconds>(high_resolution_clock::now() - m_begin).count();
    }

    //默认输出秒(浮点数)
    double elapsed_seconds_double() const
    {
        return (double)elapsed_milli() / 1000.0;
    }

    //分
    long long elapsed_minutes() const
    {
        return duration_cast<chrono::minutes>(high_resolution_clock::now() - m_begin).count();
    }
    //时
    long long elapsed_hours() const
    {
        return duration_cast<chrono::hours>(high_resolution_clock::now() - m_begin).count();
    }
};


struct segment
{
    int t;
    int num;
};

segment _segment(int t, int num)
{
    segment temp{t, num}; return temp;
}

bool g0(int x, int y, int nx, int ny)
{
    return x >= 0 && x <= nx - 1 && y >= 0 && y <= ny - 1;
}

bool g1(int num, int nx, int ny)
{
    return num >= 0 && num <= nx * ny - 1;
}

int turn(int x, int y, int nx, int ny)
{
    return y * nx + x;
}

int main()
{
    vector<int> xP = {-1, 1, 0, 0},
                yP = {0, 0, -1, 1};

    while (true)
    {
        Timer time1;
        int nx = 0, ny = 0; fin >> nx >> ny;
        if (nx + ny == 0) break;

        vector<int> numP = {-nx, -1, nx, 1};

        vector<vector<bool>> a(nx * ny, vector<bool>(nx * ny, false));
        for (int y = 0; y <= ny - 1; ++y)
        {
            for (int x = 0; x <= nx - 1; ++x)
            {
                for (int p = 0; p <= 3; ++p)
                {
                    int nextX = x + xP[p],
                        nextY = y + yP[p];

                    if (g0(nextX, nextY, nx, ny) == true)
                    {
                        a[turn(x, y, nx, ny)][turn(nextX, nextY, nx, ny)] = true;
                    }
                }
            }
        }

        int r; fin >> r;
        for (int c = 1; c <= r; ++c)
        {
            int x1, y1, x2, y2; fin >> x1 >> y1 >> x2 >> y2;
            a[turn(x1, y1, nx, ny)][turn(x2, y2, nx, ny)] = false;
        }

        int m; fin >> m;
        vector<int> pass(nx * ny * 100, -1);
        for (int c = 1; c <= m; ++c)
        {
            int t, x, y; fin >> t >> x >> y;

            pass[t] = turn(x, y, nx, ny);
        }

        queue<segment> q; q.push(_segment(0, turn(0, 0, nx, ny)));
        vector<bool> visit(nx * ny, false);

        cout << nx << "," << ny << ":";

        int ans = -1;
        while (q.empty() == false && ans == -1)
        {
            segment now = q.front(); q.pop();

            if (now.num == turn(nx - 1, ny - 1, nx, ny))
            {
                ans = now.t;
                break;
            }

            visit[now.num] = true;
            
            for (int p = 0; p <= 3; ++p)
            {
                segment next;
                next.t = now.t + 1;
                next.num = now.num + numP[p];

                if (g1(next.num, nx, ny) == false)
                {
                    continue;
                }
                else if (a[now.num][next.num] == false)
                {
                    continue;
                }
                else if (visit[next.num] == true)
                {
                    continue;
                }
                else if (pass[next.t] == next.num)
                {
                    continue;
                }
                
                q.push(next);
            }

            if (pass[now.t + 1] != now.num)
            {
                q.push(_segment(now.t + 1, now.num));
            }
        }

        cout << ans << ",time:" << time1.elapsed() << '\n';
        fout << ans << '\n';
    }

    return 0;
}
