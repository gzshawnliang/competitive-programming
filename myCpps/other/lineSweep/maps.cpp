#include <bits/stdc++.h>

using namespace std;

ifstream fin("lineSweep.in");
ofstream fout("maps.out");

const int inf = INT_MAX / 2;

const int maxP = 4000;

class rect
{
  public:
    double x1;
    double y1;
    double x2;
    double y2;
};

class line
{
  public:
    int x;
    int y1;
    int y2;

    bool operator<(const line & temp) const
    {
        return x < temp.x;
    }
};
line _line(int x, int y1, int y2)
{
    line temp{x, y1, y2}; return temp;
}

int main()
{
    fout << fixed << setprecision(2);

    int t = 0;
    while (true)
    {
        int n = 0; fin >> n;
        if (n == 0) break;

        ++t;

        vector<rect> a_t(n);
        set<double> _set;
        for (int i = 0; i <= n - 1; ++i)
        {
            double t1, t2, t3, t4; fin >> t1 >> t2 >> t3 >> t4;
            a_t[i].x1 = min(t1, t3);
            a_t[i].y1 = min(t2, t4);
            a_t[i].x2 = max(t1, t3);
            a_t[i].y2 = max(t2, t4);

            _set.insert(a_t[i].x1);
            _set.insert(a_t[i].y1);
            _set.insert(a_t[i].x2);
            _set.insert(a_t[i].y2);
        }

        int _i = 0;
        vector<double> itod;
        map<double, int> dtoi;
        for (auto it = _set.begin(); it != _set.end(); ++it)
        {
            double x = *it;

            itod.push_back(x);
            dtoi[x] = _i;
            ++_i;
        }

        vector<rect> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            a[i].x1 = dtoi[a_t[i].x1];
            a[i].y1 = dtoi[a_t[i].y1];
            a[i].x2 = dtoi[a_t[i].x2];
            a[i].y2 = dtoi[a_t[i].y2];
        }

        vector<line> l;
        for (int i = 0; i <= n - 1; ++i)
        {
            l.push_back(_line(a[i].x1, a[i].y1, a[i].y2));
            l.push_back(_line(a[i].x2, a[i].y1, a[i].y2));
        }
        sort(l.begin(), l.end());

        int sizeL = l.size();
        vector<double> h(sizeL, 0.0);
        
        for (int i = 0; i <= sizeL - 2; ++i)
        {
            int nowX = l[i].x, nextX = l[i + 1].x;

            if (nowX == nextX) continue;

            //thisH.assign(maxP,0);
            vector<int> thisH(maxP, 0);
            
            for (int j = 0; j <= n - 1; ++j)
            {
                if (a[j].x1 <= nowX && nextX <= a[j].x2)
                {
                    for (int y = a[j].y1; y <= a[j].y2 - 1; ++y)
                    {
                        //cout << y << "," << thisH.size() << "\n";
                        thisH[y] = 1;
                    }
                }
            }

            //cout << "------------------\n";

            for (int y = 0; y <= maxP - 1; ++y)
            {
                if (thisH[y] == 1)
                {
                    // if(i==0 && y==399)
                    //     cout <<i << "," << y << "," << itod.size() << "\n";

                    h[i] += (itod[y + 1] - itod[y]);
                }
            }
        }

        double ans = 0;
        for (int i = 0; i <= sizeL - 2; ++i)
        {
            int nowX = l[i].x, nextX = l[i + 1].x;

            ans += (h[i] * (itod[nextX] - itod[nowX]));
        }

        //ans = (int)(ans * 100.0 + 0.5) / 100.0;

        fout << "Test case #" << t << '\n';
        fout << "Total explored area: " << ans << "\n\n";

    }
    return 0;
}
