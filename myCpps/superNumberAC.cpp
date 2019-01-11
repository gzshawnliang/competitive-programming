#include <cstdio>

int n, m, A[35];

bool judge(int cnt) {
    long long tmp = 0;
    for (int i = 0; i < cnt; ++i) {
        tmp = tmp * 10 + A[i];
        if (i == 18)
            tmp %= cnt;
    }

    return tmp % cnt;
}

bool DFS(int cur) {
    if (cur == m)
        return true;

    for (int i = cur ? 0 : 1; i < 10; ++i) {
        A[cur] = i;
        if ((cur < n - 1 || !judge(cur + 1)) && DFS(cur + 1))
            return true;
    }

    return false;
}

int main() 
{
    freopen("superNumber.in", "r", stdin);      
    freopen("superNumber.out2", "w", stdout); 

    int T, cnt = 0;
    scanf("%d", &T);
    while (T--) {
        printf("Case %d: ", ++cnt);
        scanf("%d%d", &n, &m);
        if (DFS(0)) {
            for (int i = 0; i < m; ++i)
                printf("%d", A[i]);
            puts("");
        }
        else
            puts("-1");
    }

    fclose(stdin);
    fclose(stdout);    

    return 0;
}