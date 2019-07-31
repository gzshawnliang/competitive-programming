#include <bits/stdc++.h>

using namespace std;

ifstream fin("maps.in");
ofstream fout("maps.out");

const int inf = INT_MAX / 2;

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
    int last;

    bool operator<(const line & temp) const
    {
        return x < temp.x;
    }
};
line _line(int x, int y1, int y2, int last)
{
    line temp{x, y1, y2, last}; return temp;
}

int main()
{
    int n; fin >> n;

    vector<rect> a_t(n);
    set<double> _set;
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a_t[i].x1 >> a_t[i].y1 >> a_t[i].x2 >> a_t[i].y2;
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
        l.push_back(_line(a[i].x1, a[i].y1, a[i].y2, a[i].x2 - a[i].x1));
        l.push_back(_line(a[i].x2, a[i].y1, a[i].y2, 0));
    }
    sort(l.begin(), l.end());

    int sizeL = l.size();
    vector<int> minH(itod.size() + 1, inf), maxH(itod.size() + 1, -1);
    for (int i = 0; i <= sizeL - 1; ++i)
    {
        for (int x = l[i].x; x <= l[i].x + l[i].last; ++x)
        {
            minH[x] = min(minH[x], l[i].y1);
            maxH[x] = max(maxH[x], l[i].y2);
        }
    }

    double ans = 0, lastH = 0.0, lastX = 0.0;
    for (int i = 0; i <= sizeL - 1; ++i)
    {
        int x = l[i].x;
        double nowH = itod[maxH[x]] - itod[minH[x]], nowX = itod[l[i].x];

        if (i > 0)
        {
            ans += (min(nowH, lastH) * (nowX - lastX));
        }

        lastH = nowH; lastX = nowX;
    }

    fout << ans << '\n';

    return 0;
}
