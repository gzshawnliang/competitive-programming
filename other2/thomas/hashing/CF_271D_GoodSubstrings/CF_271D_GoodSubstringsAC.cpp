#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

const int MAXN = 1505;
const unsigned long long mod = 1000000007, seed = 13331;
unsigned long long hashCode[MAXN];
unsigned long long ex[MAXN];
int n;
char a[MAXN];
char g[MAXN];
int s[MAXN];
int k;
map<long long, bool> u;

int main()
{
    scanf("%s", a + 1);
    n = strlen(a + 1);
    scanf("%s", g + 1);
    scanf("%d", &k);
    for (int i = 1; i <= n; i++)
    {
        if (g[a[i] - 'a' + 1] == '0')
            s[i] = s[i - 1] + 1;
        else
            s[i] = s[i - 1];
    }
    ex[0] = 1;
    for (int i = 1; i <= n; i++)
        ex[i] = ex[i - 1] * seed;
        
    for (int i = 1; i <= n; i++)
        hashCode[i] = (hashCode[i - 1] * seed + a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            if (s[j] - s[i - 1] <= k)
            {
                long long t = (hashCode[j] - hashCode[i - 1] * ex[j - i + 1]);
                if (!u.count(t))
                {
                    u[t] = true;
                    ans++;
                }
            }
        }
    cout << ans << endl;

    return 0;
}