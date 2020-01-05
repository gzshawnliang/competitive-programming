#include <bits/stdc++.h>

using namespace std;

ifstream fin("IHateIt_1754.in");
ofstream fout("IHateIt_1754.out");

class SegTree
{
  private:
    int sizeA;           //原数组的大小
    vector<int> a;       //原数组
    vector<int> segTree; //线段树的数组

    void build(int l, int r, int i)
    {
        if (i > sizeA * 4 - 1)
            return;

        if (l == r)
        {
            segTree[i] = a[l];
            return;
        }

        int m = (l + r) / 2;

        build(l, m, i * 2);
        build(m + 1, r, i * 2 + 1);

        segTree[i] = max(segTree[i * 2], segTree[i * 2 + 1]);
    }

    int query(int l, int r, int i, int nowLeft, int nowRight)
    {
        if (nowRight < l || r < nowLeft)
        {
            return INT_MIN;
        }
        if (nowLeft >= l && nowRight <= r)
        {
            return segTree[i];
        }

        int m = (nowLeft + nowRight) / 2;

        return max(query(l, r, i * 2, nowLeft, m), query(l, r, i * 2 + 1, m + 1, nowRight));
    }

    void update(int pos, int _new, int i, int nowLeft, int nowRight)
    {
        if (pos < nowLeft || pos > nowRight)
        {
            return;
        }        

        if (nowLeft == nowRight)
        {
            a[pos] = _new;
            segTree[i] = _new;
            return;
        }

        int m = (nowLeft + nowRight) / 2;
        update(pos, _new, i * 2, nowLeft, m);
        update(pos, _new, i * 2 + 1, m + 1, nowRight);
        //segTree[i] = max(update(pos, _new, i * 2, nowLeft, m), update(pos, _new, i * 2 + 1, m + 1, nowRight));
        segTree[i] = max(segTree[i*2],segTree[i*2+1]);
    }

  public:
    SegTree(const vector<int> & p_Sour)
    {
        a = p_Sour;
        sizeA = a.size();
        segTree.assign(sizeA * 4, INT_MIN);

        build(0, sizeA-1, 1);
    }

    int query(int l, int r)
    {
        return query(l, r, 1, 0, sizeA-1);
    }

    void update(int index, int newVal)
    {
        update(index, newVal, 1, 0, sizeA-1);
    }
};

int main()
{
    while (true)
    {
        int n = 0, m = 0;
        fin >> n >> m;
        if (n + m == 0)
            break;

        vector<int> a(n);

        for (int i = 0; i <= n-1; ++i)
        {
            fin >> a[i];
        }

        SegTree tree(a);
        
        for (int c = 1; c <= m; ++c)
        {
            char ch;
            int _i, _j;
            fin >> ch >> _i >> _j;

            if (ch == 'Q')
            {
                fout << tree.query(_i-1, _j-1) << '\n';
            }
            else
            {
                tree.update(_i-1, _j);
            }
        }
    }

    return 0;
}
