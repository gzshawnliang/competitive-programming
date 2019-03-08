#include <bits/stdc++.h>

using namespace std;

ifstream fin("KGSS.in");
ofstream fout("KGSS.out");

struct _0831
{
    int F;
    int S;
};

class SegTree
{
  private:
    int sizeA;            //原数组的大小
    vector<int> a;        //原数组
    vector<int> segTreeF; //线段树的数组
    vector<int> segTreeS;

    void build(int l, int r, int i)
    {
        if (l == r)
        {
            segTreeF[i] = a[l];
            segTreeS[i] = INT_MIN;

            return;
        }

        int m = (l + r) / 2;

        build(l, m, i * 2);
        build(m + 1, r, i * 2 + 1);

        vector<int> s;
        s.push_back(segTreeF[i * 2]);
        s.push_back(segTreeF[i * 2 + 1]);
        s.push_back(segTreeS[i * 2]);
        s.push_back(segTreeS[i * 2 + 1]);

        sort(s.begin(), s.end());

        segTreeF[i] = s[3];
        segTreeS[i] = s[2];
    }

    _0831 query(int l, int r, int i, int nowLeft, int nowRight)
    {
        if (nowRight < l || r < nowLeft)
        {
            _0831 temp{INT_MIN, INT_MIN};
            return temp;
        }
        if (nowLeft >= l && nowRight <= r)
        {
            _0831 temp{segTreeF[i], segTreeS[i]};
            return temp;
        }

        int m = (nowLeft + nowRight) / 2;

        vector<int> s;

        _0831 _l, _r;
        _l = query(l, r, i * 2, nowLeft, m);
        _r = query(l, r, i * 2 + 1, m + 1, nowRight);

        s.push_back(_l.F);
        s.push_back(_l.S);
        s.push_back(_r.F);
        s.push_back(_r.S);

        sort(s.begin(), s.end());

        _0831 ans{s[3], s[2]};

        return ans;
    }

    void update(int pos, int _new, int i, int nowLeft, int nowRight)
    {
        if (pos < nowLeft || pos > nowRight)
        {
            return;
        }
        if (nowLeft == nowRight)
        {
            segTreeF[i] = _new;
            return;
        }

        int m = (nowLeft + nowRight) / 2;

        update(pos, _new, i * 2, nowLeft, m);
        update(pos, _new, i * 2 + 1, m + 1, nowRight);

        vector<int> s;
        s.push_back(segTreeF[i * 2]);
        s.push_back(segTreeF[i * 2 + 1]);
        s.push_back(segTreeS[i * 2]);
        s.push_back(segTreeS[i * 2 + 1]);

        sort(s.begin(), s.end());

        segTreeF[i] = s[3];
        segTreeS[i] = s[2];
    }

  public:
    SegTree(const vector<int> & p_Sour)
    {
        a = p_Sour;
        sizeA = a.size();
        segTreeF.assign(sizeA * 4, INT_MIN);
        segTreeS.assign(sizeA * 4, INT_MIN);

        build(0, sizeA - 1, 1);
    }

    int query(int l, int r)
    {
        _0831 temp = query(l, r, 1, 0, sizeA - 1);
        return temp.F + temp.S;
    }

    void update(int index, int newVal)
    {
        update(index, newVal, 1, 0, sizeA - 1);
    }
};

int main()
{
    while (true)
    {
        int n = -1;
        fin >> n;
        if (n == -1)
            break;

        vector<int> a(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        SegTree tree(a);

        int m;
        fin >> m;
        for (int i = 1; i <= m; ++i)
        {
            char c;
            fin >> c;
            int liang, xiao;
            fin >> liang >> xiao;
            if (c == 'Q')
            {
                fout << tree.query(liang - 1, xiao - 1) << '\n';
            }
            else if (c == 'U')
            {
                tree.update(liang - 1, xiao);
            }
        }
    }

    return 0;
}
