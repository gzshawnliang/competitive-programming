#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 10010;
const int MAXB = 22;
const int INF = 1e9 + 7;
const double eps = 1e-10;
int N, M, T = INF, Cases = 0;
bool isroot[MAXN];
int x, y, z, root;
vector<int> edge[MAXN];
int depth[MAXN], father[MAXN][MAXB], heavy[MAXN][MAXB];
bool visited[MAXN];
void dfs(int x, int d)
{
    depth[x] = d;
    visited[x] = true;
    for (vector<int>::iterator it = edge[x].begin(); it != edge[x].end(); it++)
        if (!visited[*it])
            dfs(*it, d + 1);
}
void lcabinarylifting(int n)
{
    for (int j = 1; j < MAXB; j++)
        for (int i = 1; i <= n; i++)
            if (~father[i][j - 1])
            {
                father[i][j] = father[father[i][j - 1]][j - 1];
                //heavy[i][j] = max(heavy[i][j-1],heavy[heavy[i][j-1]][j-1]);
            }
}
int findlca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int b = MAXB - 1; b >= 0; b--)
        if (depth[father[u][b]] >= depth[v])
            u = father[u][b];
    if (u == v)
        return u;
    for (int b = MAXB - 1; b >= 0; b--)
        if (father[u][b] != father[v][b])
            u = father[u][b], v = father[v][b];
    return father[u][0];
}
int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//

    #ifndef ONLINE_JUDGE
        freopen("POJ1330.in", "r", stdin);
        freopen("POJ1330.out", "w", stdout);
    #endif

    scanf("%d", &T);
    while (T-- && ~(scanf("%d", &N)))
    {
        memset(isroot, true, sizeof(isroot));
        memset(father, 0xff, sizeof(father));
        //memset(heavy,0,sizeof(heavy));
        for (int i = 0; i <= N; i++)
            edge[i].clear();
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d", &x, &y);
            isroot[y] = false;
            edge[x].push_back(y);
            father[y][0] = x;
        }
        for (int i = 1; i <= N; i++)
            if (isroot[i])
                root = i;
        memset(visited, false, sizeof(visited));
        dfs(root, 1);
        lcabinarylifting(N);
        scanf("%d%d", &x, &y);
        z = findlca(x, y);
        printf("%d\n", z);
    }
    return 0;
}