#include <bits/stdc++.h>

using namespace std;
using ll = long long; 


const ll inf = LLONG_MAX / 2;

class node
{
  public:
    ll sum;
    ll ans;
    ll al;
    ll ar;

    node(ll tsum, ll tans, ll tal, ll tar)
    {
        sum = tsum;
        ans = tans;
        al = tal;
        ar = tar;
    }
    node()
    {
        sum = inf;
        ans = inf;
        al = inf;
        ar = inf;
    }
};
node _node(ll tsum, ll tans, ll tal, ll tar)
{
    node temp{tsum, tans, tal, tar}; return temp;
}

class SegTree
{
  private: //--------------------------------------------------

    ll sizeA;
    vector<ll> a;
    vector<node> segTree;

    void fill(ll p)
    {
        node nl = segTree[p * 2],
             nr = segTree[p * 2 + 1];
        
        segTree[p].sum = nl.sum + nr.sum;
        segTree[p].ans = max(max(nl.ans, nr.ans), nl.ar + nr.al);
        segTree[p].al = max(nl.al, nl.sum + nr.al);
        segTree[p].ar = max(nr.ar, nr.sum + nl.ar);
    }

    node merge(node na, node nb)
    {
        node res;
        res.sum = na.sum + nb.sum;
        res.ans = max(max(na.ans, nb.ans), na.ar + nb.al);
        res.al = max(na.al, na.sum + nb.al);
        res.ar = max(nb.ar, nb.sum + na.ar);

        return res;
    }

    void build(ll p, ll l, ll r)
    {
        if (l == r)
        {
            segTree[p].sum = a[l];
            segTree[p].ans = a[l];
            segTree[p].al = a[l];
            segTree[p].ar = a[l];

            return;
        }

        ll mid = (l + r) / 2;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);

        fill(p);
    }

    node Pquery(ll sl, ll sr, ll p, ll l, ll r)
    {
        if (sr < l || sl > r)
        {
            return _node(0, -1 * inf, -1 * inf, -1 * inf);
        }
        else if (sl <= l && sr >= r)
        {
            return segTree[p];
        }

        ll mid = (l + r) / 2;

        if(sr <= mid)
        {
            node temp = Pquery(sl, sr, p * 2, l, mid);
            return temp;
        }
        else if (sl > mid)
        {
            node temp = Pquery(sl, sr, p * 2 + 1, mid + 1, r);
            return temp;
        }
        else
        {   
            node temp = merge(Pquery(sl, sr, p * 2, l, mid), Pquery(sl, sr, p * 2 + 1, mid + 1, r));
            return temp;
        }
    }

    void Pupdate(ll i, ll x, ll p, ll l, ll r)
    {
        if (i < l || i > r)
        {
            return;
        }
        else if (i == l && i == r)
        {
            segTree[p].sum = x;
            segTree[p].ans = x;
            segTree[p].al = x;
            segTree[p].ar = x;

            return;
        }

        ll mid = (l + r) / 2;
        Pupdate(i, x, p * 2, l, mid);
        Pupdate(i, x, p * 2 + 1, mid + 1, r);

        if (p == 1)
        {
            for (int __s = 0; __s == 0; ++__s);
        }

        fill(p);
    }

  public: //--------------------------------------------------

    SegTree(const vector<long long> in)
    {
        a = in;
        sizeA = a.size() - 1;
        segTree.assign(sizeA * 4, _node(-1 * inf, -1 * inf, -1 * inf, -1 * inf));

        build(1, 1, sizeA);
    }

    node query(ll sl, ll sr)
    {
        return Pquery(sl, sr, 1, 1, sizeA);
    }

    void update(ll i, ll x)
    {
        Pupdate(i, x, 1, 1, sizeA);
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n + 1, inf);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    SegTree tree(a);

    ll m; cin >> m;
    for (ll c = 1; c <= m; ++c)
    {
        ll t, x, y; cin >> t >> x >> y;

        if (t == 0)
        {
            tree.update(x, y);
        }
        else
        {
            cout << tree.query(x, y).ans << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

