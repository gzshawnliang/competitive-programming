#include <bits/stdc++.h>

using namespace std;

ifstream fin("QueriesI.in");
ofstream fout("QueriesI.out");

struct node
{
    int _l;
    int _r;
    int v;
};

node _node(int _l, int _r, int v)
{
    node temp{_l, _r, v};
    return temp;
};

class SegTree
{
  private:
    int sizeA;           //原数组的大小
    vector<int> a;       //原数组
    vector<int> segTree; //线段树的数组
    vector<node> segTreeAns;

    void build1(int l, int r, int i)
    {
        if (l == r)
        {
            segTree[i] = a[l];
            return;
        }

        int m = (l + r) / 2;

        build1(l, m, i * 2);
        build1(m + 1, r, i * 2 + 1);

        segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
    }

    void build2(int l, int r, int i)
    {
        if (l == r)
        {
            segTreeAns[i] = _node(l, r, a[l]);
            return;
        }

        int m = (l + r) / 2;

        build2(l, m, i * 2);
        build2(m + 1, r, i * 2 + 1);

        int temp = query1(segTreeAns[i * 2]._l, segTreeAns[i * 2 + 1]._r);
        int _max = max(segTreeAns[i * 2].v, max(segTreeAns[i * 2 + 1].v, temp));

        if (i == 1)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        if (_max == segTreeAns[i * 2].v)
        {
            segTreeAns[i] = segTreeAns[i * 2];
        }
        else if (_max == segTreeAns[i * 2 + 1].v)
        {
            segTreeAns[i] = segTreeAns[i * 2 + 1];
        }
        else
        {
            segTreeAns[i] = _node(segTreeAns[i * 2]._l, segTreeAns[i * 2 + 1]._r, temp);
        }
    }

    int Pquery1(int l, int r, int i, int nowLeft, int nowRight)
    {
        if (nowRight < l || r < nowLeft)
        {
            return 0;
        }
        if (nowLeft >= l && nowRight <= r)
        {
            return segTree[i];
        }

        int m = (nowLeft + nowRight) / 2;

        return Pquery1(l, r, i * 2, nowLeft, m) + Pquery1(l, r, i * 2 + 1, m + 1, nowRight);
    }

    void Pquery2(int l, int r, int i, int nowLeft, int nowRight, vector<node> & path)
    {
        if (nowRight < l || r < nowLeft)
        {
            return;
        }
        if (nowLeft >= l && nowRight <= r)
        {
            path.push_back(segTreeAns[i]);
            return;
        }

        int m = (nowLeft + nowRight) / 2;

        Pquery2(l, r, i * 2, nowLeft, m, path);
        Pquery2(l, r, i * 2 + 1, m + 1, nowRight, path);
    }

  public:
    SegTree(const vector<int> & p_Sour)
    {
        a = p_Sour;
        sizeA = a.size();
        segTree.assign(sizeA * 4, INT_MIN);
        segTreeAns.assign(sizeA * 4, _node(-1, -1, 0));

        build1(0, sizeA - 1, 1);
        build2(0, sizeA - 1, 1);
    }

    int query1(int l, int r)
    {
        return Pquery1(l, r, 1, 0, sizeA - 1);
    }

    int query2(int l, int r)
    {
        vector<node> path;
        Pquery2(l, r, 1, 0, sizeA - 1, path);

        int ans = 0, sizeP = path.size();
        for (int i = 0; i <= sizeP - 1; ++i)
        {
            for (int j = i; j <= sizeP - 1; ++j)
            {
                ans = max(ans, query1(path[i]._l, path[j]._r));
            }
        }

        return ans;
    }
};

int main()
{
    while (true)
    {
        int n = 0;
        fin >> n;
        if (n == 0) break;

        vector<int> a(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        SegTree tree(a);

        int m;
        fin >> m;
        for (int c = 1; c <= m; ++c)
        {
            int x, y;
            fin >> x >> y;
            --x;
            --y;

            fout << tree.query2(x, y) << '\n';
        }
    }

    return 0;
}
