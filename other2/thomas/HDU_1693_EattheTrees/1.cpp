#include <cstdio>
#include <cstring>
#include <iostream>
#define mov(x) (1 << (x))
#define MX 13

using namespace std;

typedef long long ll;

int mp[MX][MX];
int n, m;
ll f[MX][MX][mov(MX)];

void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &mp[i][j]);

    // for (int i = 0; i <= n + 1; i++)
    //     mp[i][0] = mp[i][m + 1] = 0;

    // for (int i = 0; i <= m + 1; i++)
    //     mp[0][i] = mp[n + 1][i] = 0;
}

ll work()
{
    f[1][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < mov(m + 1); k++)
            {
                if (mp[i][j + 1])
                {
                    if (mp[i][j + 2] && mp[i + 1][j + 1] && !(k & mov(j)) && !(k & mov(j + 1)))
                        f[i][j + 1][(k | mov(j)) | mov(j + 1)] += f[i][j][k];
                    if (mp[i + 1][j + 1] && (k & mov(j)) && !(k & mov(j + 1)))
                        f[i][j + 1][k] += f[i][j][k];
                    if (mp[i][j + 2] && (k & mov(j)) && !(k & mov(j + 1)))
                        f[i][j + 1][(k ^ mov(j)) | mov(j + 1)] += f[i][j][k];
                    if (mp[i + 1][j + 1] && !(k & mov(j)) && (k & mov(j + 1)))
                        f[i][j + 1][(k | mov(j)) ^ mov(j + 1)] += f[i][j][k];
                    if (mp[i][j + 2] && !(k & mov(j)) && (k & mov(j + 1)))
                        f[i][j + 1][k] += f[i][j][k];
                    if ((k & mov(j)) && (k & mov(j + 1)))
                        f[i][j + 1][(k ^ mov(j)) ^ mov(j + 1)] += f[i][j][k];
                }
                else
                    f[i][j + 1][k] += f[i][j][k];
            }
        }
        for (int k = 0; k < mov(m + 1); k++)
            f[i + 1][0][(k << 1) & (mov(m + 1) - 1)] += f[i][m][k];
    }
    return f[n][m][0];
}

void init()
{
    memset(f, 0, sizeof(f));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("HDU_1693_EattheTrees.in", "r", stdin);
        //freopen("HDU_1693_EattheTrees.out", "w", stdout);
    #endif 

    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        input();
        init();
        printf("Case %d: There are %lld ways to eat the trees.\n", i, work());
    }
    return 0;
}
