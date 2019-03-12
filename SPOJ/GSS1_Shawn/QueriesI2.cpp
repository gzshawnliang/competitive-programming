#include <bits/stdc++.h>

using namespace std;

ifstream fin("QueriesI.in");
ofstream fout("QueriesI.out");

const long long INF = -15008;

class node
{
  public:
    long long sum;
    long long ans;
    long long Al;
    long long Ar;

    node(long long Tsum, long long Tans, long long Tleft, long long Tright)
    {
        sum = Tsum;
        ans = Tans;
        Al = Tleft;
        Ar = Tright;
    }
    node()
    {
        sum = INF;
        ans = INF;
        Al = INF;
        Ar = INF;
    }
};

node _node(long long Tsum, long long Tans, long long Tleft, long long Tright)
{
    node resNode(Tsum, Tans, Tleft, Tright);
    return resNode;
}

class SegTree
{
  private:
    long long sizeA;
    vector<long long> a;
    vector<node> segTree;

    void Pfill(long long pos)
    {
        node a = segTree[pos * 2];
        node b = segTree[pos * 2 + 1];

        segTree[pos].sum = a.sum + b.sum;
        segTree[pos].Al = max(a.Al, a.sum + b.Al);
        segTree[pos].Ar = max(b.Ar, b.sum + a.Ar);
        segTree[pos].ans = max(max(a.ans, b.ans), a.Ar + b.Al);
    }

    node Pmerge(node a, node b)
    {
        node resNode;

        resNode.sum = a.sum + b.sum;
        resNode.Al = max(a.Al, a.sum + b.Al);
        resNode.Ar = max(b.Ar, b.sum + a.Ar);
        resNode.ans = max(max(a.ans, b.ans), a.Ar + b.Al);

        return resNode;
    }

    void Pbuild(long long l, long long r, long long p)
    {
        if (l == r)
        {
            segTree[p].sum = a[l];
            segTree[p].ans = a[l];
            segTree[p].Al = a[l];
            segTree[p].Ar = a[l];

            return;
        }

        long long mid = (l + r) / 2;
        Pbuild(l, mid, p * 2);
        Pbuild(mid + 1, r, p * 2 + 1);

        Pfill(p);
    }

    node Pquery(long long Sl, long long Sr, long long p, long long l, long long r)
    {
        if (l > Sr || r < Sl)
        {
            return _node(INF, INF, INF, INF);
        }
        else if (l >= Sl && r <= Sr)
        {
            return segTree[p];
        }

        long long mid = (l + r) / 2;

        if(Sr <= mid)
        {
            return Pquery(Sl, Sr, p * 2, l, mid);
        }
        else if (Sl > mid)
        {
            return Pquery(Sl, Sr, p * 2 + 1, mid + 1, r);
        }
        else
        {
            return Pmerge(Pquery(Sl, Sr, p * 2, l, mid), Pquery(Sl, Sr, p * 2 + 1, mid + 1, r));
        }
    }

  public:
    SegTree(const vector<long long> in)
    {
        a = in;
        sizeA = a.size();
        segTree.assign(sizeA * 4, _node(INF, INF, INF, INF));

        Pbuild(0, sizeA - 1, 1);
    }

    node query(long long Sl, long long Sr)
    {
        return Pquery(Sl, Sr, 1, 0, sizeA - 1);
    }
};

main()
{
    while (true)
    {
        long long n = 0;
        fin >> n;
        if (n == 0)
            break;

        vector<long long> a(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];
        }

        SegTree tree(a);

        long long m;
        fin >> m;
        for (int c = 1; c <= m; ++c)
        {
            long long x, y;
            fin >> x >> y;
            --x;
            --y;

            fout << tree.query(x, y).ans << '\n';
        }
    }

    return 0;
}
