
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100500;
int d[N], n;
int read(void)
{
    int x = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}
struct node
{
    int val, pos;
    bool operator<(const node & i) const
    {
        if (val == i.val)
            return pos < i.pos;
        return val < i.val;
    }
} p[N];
inline int low(int x)
{
    return x & -x;
}
int get(int x)
{
    int tmp = 0;
    for (; x; x -= low(x))
        tmp += d[x];
    return tmp;
}
void add(int x)
{
    for (; x <= n; x += low(x))
        d[x]++;
}
bool cmp(node i, node j)
{
    return i.pos < j.pos;
}
int main()
{

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    n = read();
    for (int i = 1; i <= n; i++)
        p[i] = (node){read(), i};
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
        p[i].val = i;
    sort(p + 1, p + n + 1, cmp);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        add(p[i].val);
        ans = max(ans, i - get(i));
    }
    printf("%d\n", ans);
    return 0;
}
/*
6
2 5 6 3 1 4

*/
