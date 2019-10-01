#include <bits/stdc++.h>

using namespace std;

ifstream fin("blobsInTheBoard_UVA11391.in");
ofstream fout("blobsInTheBoard_UVA11391.out");

using ll = long long;

const ll maxC = 16;

ll vtoi(vector<vector<ll>> & a)
{
    ll ny = a.size(), nx = a[0].size(), ans = 0;
    for (ll y = 0; y <= ny - 1; ++y)
    {
        for (ll x = 0; x <= nx - 1; ++x)
        {
            if (a[y][x] == 1)
            {
                ll c = y * nx + x;

                ans += (1 << c);
                --c;
            }
        }
    }

    return ans;
}

vector<vector<ll>> itov(ll x, ll ny, ll nx)
{
    ll c = ny * nx - 1;
    bitset<maxC> b(x);

    vector<vector<ll>> a(ny, vector<ll>(nx, 0));
    for (ll i = 0; i <= c; ++i)
    {
        a[i / nx][i % nx] = b[i];
    }

    return a;
}

bool inside(ll y, ll x, ll ny, ll nx)
{
    return y >= 0 && y <= ny - 1 && x >= 0 && x <= nx - 1;
}

ll get(ll x, ll pos)
{
    return (x & (1 << pos)) > 0;
}

void to1(ll & x, ll pos)
{
    x |= (1 << pos);
}

void to0(ll & x, ll pos)
{
    x &= ~(1 << pos);
}

int main2()
{
    int nowX = 192, ny = 3, nx = 3;
    vector<vector<ll>> now = itov(nowX, ny, nx);
    for (ll y = 0; y <= ny - 1; ++y)
    {
        for (ll x = 0; x <= nx - 1; ++x)
        {
            fout << now[y][x];
        }
        fout << '\n';
    }

    return 0;
}

int main()
{
    vector<ll> py = {-1, -1, 0, 1, 1, 1, 0, -1},
                px = {0, 1, 1, 1, 0, -1, -1, -1};

    ll tcc; fin >> tcc;
    for (ll t = 1; t <= tcc; ++t)
    {
        ll ny, nx, nb; fin >> ny >> nx >> nb;
        vector<vector<ll>> s(ny, vector<ll>(nx, 0));
        for (ll c = 1; c <= nb; ++c)
        {
            ll y, x; fin >> y >> x;
            --y; --x;
            s[y][x] = 1;
        }

        ll c = ny * nx, s_i = vtoi(s);
        vector<ll> dp((1 << c), 0); dp[s_i] = 1;
        vector<ll> now, next; now.push_back(s_i);

        for (ll cb = nb; cb > 1; --cb)
        {
            vector<ll> next_exist((1 << c), 0);

            ll size = now.size();
            for (ll i = 0; i <= size - 1; ++i)
            {
                ll nowX = now[i];

                if (dp[nowX] > 0)
                {
                    for (ll y = 0; y <= ny - 1; ++y)
                    {
                        for (ll x = 0; x <= nx - 1; ++x)
                        {
                            if (get(nowX, y * nx + x) == 1)
                            {
                                for (ll p = 0; p <= 8 - 1; ++p)
                                {
                                    ll sty = y + py[p], stx = x + px[p],
                                        ty = y + py[p] * 2, tx = x + px[p] * 2;

                                    if (inside(sty, stx, ny, nx) == true && inside(ty, tx, ny, nx) == true)
                                    {
                                        if (get(nowX, sty * nx + stx) == 1 && get(nowX, ty * nx + tx) == 0)
                                        {
                                            ll nextX = nowX;
                                            to0(nextX, y * nx + x); to0(nextX, sty * nx + stx); to1(nextX, ty * nx + tx);

                                            dp[nextX] += dp[nowX];
                                            if (next_exist[nextX] == 0)
                                            {
                                                next.push_back(nextX);
                                                next_exist[nextX] = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            now = next;
            next.clear();
        }

        // for (ll nowX = 0; nowX <= (1 << c) - 1; ++nowX)
        // {
        //     if (dp[nowX] > 0)
        //     {
        //         vector<vector<ll>> now = itov(nowX, ny, nx);
        //         for (ll y = 0; y <= ny - 1; ++y)
        //         {
        //             for (ll x = 0; x <= nx - 1; ++x)
        //             {
        //                 fout << now[y][x];
        //             }
        //             fout << '\n';
        //         }
        //         fout << dp[nowX] << '\n';
        //     }
        // }

        ll ans = 0;
        for (ll i = 0; i <= c; ++i)
        {
            ll nowX = (1 << i);
            if (nowX > (1 << c) - 1) break;

            ans += dp[nowX];
        }

        fout << "Case " << t << ": " << ans << '\n';
    }

    return 0;
}
