#include <bits/stdc++.h>
#define rint register int
using namespace std;
typedef long long ll;
const int a[3][3] = {{1, 0, 1}, {0, 2, 0}, {1, 0, 3}};
int q;
ll d, x, y, ans;
ll calc(ll x, ll n)
{
    if (n == 1)
        return 1;
    if (n == 3)
    {
        if (x == 0)
            return 3;
        else if (x == 1)
            return 0;
        else
            return 1;
    }
    n /= 3;
    if (x < n)
        return 3ll * calc(x, n);
    else if (x == n)
        return 0;
    else if (x < 2ll * n)
        return calc(2ll * n - x, n);
    else
        return calc(x - 2ll * n, n);
}
ll query(ll x, ll y, ll n)
{
    if (n == 3)
        return a[x][y];
    if (x > y)
        swap(x, y);
    ll val = y - x;
    n /= 3ll;
    if (val < n)
    {
        ll tmp = calc(val, n);
        if (y < n)
            return query(x, y, n);
        if (x < n)
            return tmp;
        if (y < 2ll * n)
            return tmp + query(x - n, y - n, n);
        if (x < 2ll * n)
            return tmp * 2ll;
        else
            return tmp * 2ll + query(x - 2ll * n, y - 2ll * n, n);
    }
    else if (val == n)
        return 0;
    else if (val < 2ll * n)
    {
        if (y < 2ll * n)
            return 0;
        if (x >= n)
            return calc(2ll * n - val, n);
        return query(x, y - 2ll * n, n);
    }
    else
        return query(x, y - 2ll * n, n);
}
ll Query(ll x, ll y)
{
    if (x < 0 || y < 0)
        return 0;
    if (x > y)
        swap(x, y);
    ll dif = y - x, val = 3ll;
    while (val <= y)
        val *= 3ll;
    return query(x, y, val);
}
int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%lld%lld%lld", &d, &x, &y);
        cout << Query(x + d, y + d) - Query(x - 1, y - 1) << endl;
    }
    return 0;
}