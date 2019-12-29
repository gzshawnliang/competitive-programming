#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int n, L, sum = 0;
int w[N], x[N], d[N];
struct Node
{
    int pos, w;
} a[N];
bool check(int md)
{
    int S = 0;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
        if (x[i] + d[i] * md <= 0)
            c1++;
        else if (x[i] + d[i] * md >= L)
            c2++;
    for (int i = 1; i <= c1; i++)
        S += a[i].w;
    for (int i = 1; i <= c2; i++)
        S += a[n - i + 1].w;
    return S * 2 >= sum;
}
bool cmp(Node a, Node b)
{
    return a.pos < b.pos;
}
int p1[N], p2[N];
int main()
{
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    scanf("%d%d", &n, &L);
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &w[i], &x[i], &d[i]);
        sum += w[i];
        if (d[i] == 1)
            p1[++c1] = x[i];
        else
            p2[++c2] = x[i];
        a[i] = (Node){x[i], w[i]};
    }
    sort(a + 1, a + n + 1, cmp);
    sort(p1 + 1, p1 + c1 + 1);
    sort(p2 + 1, p2 + c2 + 1);
    int l = 0, r = L, T;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            T = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    long long ans = 0;
    for (int i = 1; i <= c1; i++)
    {
        l = lower_bound(p2 + 1, p2 + c2 + 1, p1[i]) - p2;
        r = upper_bound(p2 + 1, p2 + c2 + 1, p1[i] + 2 * T) - p2 - 1;
        ans += r - l + 1;
    }
    printf("%lld", ans);
    return 0;
}