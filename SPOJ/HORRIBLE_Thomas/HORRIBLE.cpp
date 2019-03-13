#include <bits/stdc++.h>

using namespace std;

ifstream fin("HORRIBLE.in");
ofstream fout("HORRIBLE.out");

struct node
{
    long long v;
    long long flag;
};

node _node(long long v, long long flag)
{
    node temp{v, flag};
    return temp;
};

class segTree
{
  private:
    long long sizeA;
    vector<long long> a;
    vector<node> _segTree;

    long long query(long long l, long long r, long long i, long long nowLeft, long long nowRight)
    {
        if (nowRight < l || nowLeft > r)
        {
            return 0;
        }
        if (nowLeft == nowRight)
        {
            _segTree[i].v += _segTree[i].flag;
            _segTree[i].flag = 0;

            return _segTree[i].v;
        }
        
        if(_segTree[i].flag !=0)
        {
            _segTree[i].v += ((nowRight - nowLeft + 1) * _segTree[i].flag);
            if(l !=r)
            {
                _segTree[i * 2].flag += _segTree[i].flag;
                _segTree[i * 2 + 1].flag += _segTree[i].flag;
            }
            _segTree[i].flag = 0;
        }

        if (nowLeft >=l && nowRight <=r)
        {
            return _segTree[i].v;
        }        

        // if (nowLeft >= l && nowRight <= r)
        // {
        //     return _segTree[i].v;
        // }

        long long m = (nowLeft + nowRight) / 2;

        return query(l, r, i * 2, nowLeft, m) + query(l, r, i * 2 + 1, m + 1, nowRight);
    }

    void update(long long l, long long r, long long v, long long i, long long nowLeft, long long nowRight)
    {
        if(_segTree[i].flag !=0)
        {
            _segTree[i].v += ((nowRight - nowLeft + 1) * _segTree[i].flag);
            if(l !=r)
            {
                _segTree[i * 2].flag += _segTree[i].flag;
                _segTree[i * 2 + 1].flag += _segTree[i].flag;
            }
            _segTree[i].flag = 0;
        }

        if (r < nowLeft || l > nowRight)
        {
            return;
        }

        if (nowLeft >= l && nowRight <= r)
        {
            _segTree[i].flag += v;
            // if (left != right)
            // {
            //     _segTree[i * 2].flag += v;
            //     _segTree[i * 2 + 1].flag += v;
            // }            
            return;
        }        

        if (nowLeft == nowRight)
        {
            _segTree[i].v += v;
            return;
        }


        long long m = (nowLeft + nowRight) / 2;

        update(l, r, v, i * 2, nowLeft, m);
        update(l, r, v, i * 2 + 1, m + 1, nowRight);
        _segTree[i].v = _segTree[i * 2].v + _segTree[i * 2+1].v;
    }

  public:
    segTree(const vector<long long> & p_Sour)
    {
        a = p_Sour;
        sizeA = a.size();
        _segTree.assign(sizeA * 4, _node(0, 0));
    }

    long long query(long long l, long long r)
    {
        return query(l, r, 1, 0, sizeA - 1);
    }

    void update(long long l, long long r, long long v)
    {
        update(l, r, v, 1, 0, sizeA - 1);
    }
};

int main()
{
    long long testCase; fin >> testCase;
    for (long long t = 1; t <= testCase; ++t)
    {
        long long n = 0, m = 0;
        fin >> n >> m;
        if (n + m == 0)
            break;

        vector<long long> a(n, 0);
        segTree tree(a);

        for (long long c = 1; c <= m; ++c)
        {
            bool command; fin >> command;

            if (command == 0)
            {
                long long l, r, v; fin >> l >> r >> v;
                tree.update(l - 1, r - 1, v);
            }
            else
            {
                long long l, r; fin >> l >> r;

                long long ans = tree.query(l - 1, r - 1);
                fout << ans << '\n';
            }
        }
    }

    return 0;
}
