#include <cstdio>
#include <cmath>
#include <cstring>

const int maxn = 10000;
int pri[maxn], cnt, e[maxn];    //e记录每个素数的质数 
bool vis[maxn + 10];

void add_interger(int n, int d)    //乘以n的d次幂 
{
    for(int i = 0; i < cnt; ++i)
    {
        while(n % pri[i] == 0)
        {
            n /= pri[i];
            e[i] += d;
        }
        if(n == 1) return;
    }
}

void add_factorial(int n, int d)    //乘以(n!)的d次幂 
{
    for(int i = 2; i <= n; ++i)
        add_interger(i, d);
}

int main()
{
    //freopen("CAD.in", "r", stdin);      
    //freopen("CAD.out", "w", stdout);   
    
    int m = sqrt(maxn + 0.5);
    for(int i = 2; i <= m; ++i) if(!vis[i])
        for(int j = i*i; j <= maxn; j += i) vis[j] = true;
    cnt = 0;
    for(int i = 2; i < maxn; ++i) if(!vis[i]) pri[cnt++] = i;
    //for(int i = 0; i < 10; ++i) printf("%d\n", pri[i]);
    
    int p, q, r, s;
    while(scanf("%d%d%d%d", &p, &q, &r, &s) == 4)
    {
        memset(e, 0, sizeof(e));
        
        add_factorial(p, 1);
        add_factorial(q, -1);
        add_factorial(p-q, -1);
        add_factorial(r, -1);
        add_factorial(s, 1);
        add_factorial(r-s, 1);
        
        double ans = 1.0;
        for(int i = 0; i < cnt; ++i)
            ans *= pow(pri[i], e[i]);
            
        printf("%.5f\n", ans);
    }
    
    return 0;
}