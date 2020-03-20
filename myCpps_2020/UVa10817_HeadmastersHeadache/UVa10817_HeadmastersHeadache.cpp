/*
===========================================================
* @Name:           UVa-10817 Headmaster's Headache
* @Author:         Shawn
* @create Time:    2020/3/20 21:46:25
* @url:            
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxS = 8, inf = INT_MAX / 4;

int hvtoi(vector<int> &a)
{
    int s = a.size(), bas = 1, ans = 0;
    for (int i = s - 1; i >= 0; --i)
    {
        ans += (bas * a[i]);
        bas *= 3;
    }

    return ans;
}

vector<int> hitov(int x, int s)
{
    vector<int> ans(s);
    for (int i = s - 1; i >= 0 && x > 0; --i)
    {
        ans[i] = (x % 3);
        x /= 3;
    }

    return ans;
}

void skpGetlin()
{
    string tmp; getline(cin, tmp);
}

void solve()
{
    vector<int> pow3(maxS + 1, 1);
    for (int i = 1; i <= maxS; ++i)
        pow3[i] = pow3[i - 1] * 3;
    
    while (true)
    {
        int s = 0, n = 0, m = 0; cin >> s >> n >> m;
        if (s + n + m == 0) break;

        skpGetlin();

        int iniC = 0;
        vector<int> iniA(s, 0);
        for (int c = 1; c <= n; ++c)
        {
            string inp; getline(cin, inp);

            stringstream inpin(inp);

            int pri; inpin >> pri;
            iniC += pri;

            int inpS = 0;
            while (inpin >> inpS)
            {
                iniA[inpS - 1] = min(2, iniA[inpS - 1] + 1);
            }
        }

        vector<int> f(pow3[s], inf);
            f[hvtoi(iniA)] = iniC;
        
        for (int c = 1; c <= m; ++c)
        {
            string inp; getline(cin, inp);

            stringstream inpin(inp);

            int pri; inpin >> pri;
            
            int inpS;
            vector<int> inpLisS;
            while (inpin >> inpS)
            {
                inpLisS.push_back(inpS);
            }

            for (int x = pow3[s] - 1; x >= 0; --x)
            {
                if (f[x] == inf) continue;

                vector<int> tmpX = hitov(x, s);
                
                for (int nowS:inpLisS)
                    tmpX[nowS - 1] = min(2, tmpX[nowS - 1] + 1);

                int tmpIntX = hvtoi(tmpX);
                f[tmpIntX] = min(f[tmpIntX], f[x] + pri);
            }
        }

        cout << f[pow3[s] - 1] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("UVa10817_HeadmastersHeadache.in", "r", stdin);
        freopen("UVa10817_HeadmastersHeadache.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}