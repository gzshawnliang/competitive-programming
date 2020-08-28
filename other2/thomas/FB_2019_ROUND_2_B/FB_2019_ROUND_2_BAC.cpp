// Bitstrings as a Service
// Solution by Jacob Plachta

#define DEBUG 0

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int, int>

#define Fox(i, n) for (i = 0; i < n; i++)
#define Fox1(i, n) for (i = 1; i <= n; i++)
#define FoxI(i, a, b) for (i = a; i <= b; i++)
#define FoxR(i, n) for (i = (n)-1; i >= 0; i--)
#define FoxR1(i, n) for (i = n; i > 0; i--)
#define FoxRI(i, a, b) for (i = b; i >= a; i--)
#define Foxen(i, s) for (i = s.begin(); i != s.end(); i++)
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(), (s).end()
#define Fill(s, v) memset(s, v, sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template <typename T>
T Abs(T x)
{
    return (x < 0 ? -x : x);
}
template <typename T>
T Sqr(T x) { return (x * x); }
string plural(string s) { return (Sz(s) && s[Sz(s) - 1] == 'x' ? s + "en" : s + "s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);


#if LOCAL_DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar
#endif

bool Read(int & x)
{
    char c, r = 0, n = 0;
    x = 0;
    for (;;)
    {
        c = GETCHAR();
        if ((c < 0) && (!r))
            return (0);
        if ((c == '-') && (!r))
            n = 1;
        else if ((c >= '0') && (c <= '9'))
            x = x * 10 + c - '0', r = 1;
        else if (r)
            break;
    }
    if (n)
        x = -x;
    return (1);
}

#define LIM 30

int N, M, K;
int comp[LIM], sz[LIM], val[LIM];
vector<int> con[LIM];
int dyn[LIM][LIM];

void rec(int i)
{
    if (comp[i] >= 0)
        return;
    comp[i] = K;
    sz[K]++;
    int j;
    Fox(j, Sz(con[i]))
        rec(con[i][j]);
}

int main()
{
    #ifdef LOCAL_DEBUG
        freopen("FB_2019_ROUND_2_B.in", "r", stdin);
        //freopen("FB_2019_ROUND_2_B.out", "w", stdout);
    #endif

    // vars
    int T, t;
    int i, j;
    // testcase loop
    Read(T);
    Fox1(t, T)
    {
        // init
        Fox(i, N)
            con[i]
                .clear();
        // input, and create graph of bit equalities
        Read(N), Read(M);
        while (M--)
        {
            Read(i), Read(j), i--, j--;
            while (j > i)
            {
                con[i].pb(j);
                con[j].pb(i);
                i++, j--;
            }
        }
        // find all components of equal bits
        K = 0;
        Fill(sz, 0);
        Fill(comp, -1);
        Fox(i, N) if (comp[i] < 0)
        {
            rec(i);
            K++;
        }
        // DP on component value assignments
        Fill(dyn, -1);
        dyn[0][0] = 0;
        Fox(i, K)
            Fox(j, N) if (dyn[i][j] >= 0)
                dyn[i + 1][j] = dyn[i + 1][j + sz[i]] = j;
        // trace back to assign values to components
        Fox(i, N + 1)
        {
            if (dyn[K][j = N / 2 + i] >= 0)
                break;
            if (dyn[K][j = N / 2 - i] >= 0)
                break;
        }
        FoxR1(i, K)
        {
            val[i - 1] = (dyn[i][j] == j ? 0 : 1);
            j = dyn[i][j];
        }
        // output
        printf("Case #%d: ", t);
        Fox(i, N)
            printf("%d", val[comp[i]]);
        printf("\n");
    }
    return (0);
}