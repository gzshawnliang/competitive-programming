
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 8000 + 5;

struct TwoSAT {
    int n;
    vector<int> G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2], c;

    bool dfs(int x) {
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x] = true;
        S[c++] = x;
        for (int i = 0; i < G[x].size(); i++)
            if (!dfs(G[x][i])) return false;
        return true;
    }

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n*2; i++) G[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    bool solve() {
        for(int i = 0; i < n*2; i += 2)
            if(!mark[i] && !mark[i+1]) {
                c = 0;
                if(!dfs(i)) {
                    while(c > 0) mark[S[--c]] = false;
                    if(!dfs(i+1)) return false;
                }
            }
        return true;
    }
};

///////// 题目相关
#include<algorithm>

TwoSAT solver;
int n,m;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("SPO.IN", "r", stdin);
        //freopen("SPO.OUT", "w", stdout);
    #endif 
        
    while(~scanf("%d%d", &n,&m) ) {

        solver.init(n);
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            solver.G[a].push_back(b^1);
            solver.G[b].push_back(a^1);
        }

        if(!solver.solve()) printf("NIE\n");
        else for(int i = 0; i < 2*n; i++)
                if(solver.mark[i]) printf("%d\n",i+1);
    }
    return 0;
}

