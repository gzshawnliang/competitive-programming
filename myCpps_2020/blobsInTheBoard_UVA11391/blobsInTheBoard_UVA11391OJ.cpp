#include <bits/stdc++.h>

using namespace std;


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

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<ll> py = {-1, -1, 0, 1, 1, 1, 0, -1},
                px = {0, 1, 1, 1, 0, -1, -1, -1};

    ll tcc; cin >> tcc;
    for (ll t = 1; t <= tcc; ++t)
    {
        ll ny, nx, nb; cin >> ny >> nx >> nb;
        vector<vector<ll>> s(ny, vector<ll>(nx, 0));
        for (ll c = 1; c <= nb; ++c)
        {
            ll y, x; cin >> y >> x;
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
                    vector<vector<ll>> now = itov(nowX, ny, nx);
                    for (ll y = 0; y <= ny - 1; ++y)
                    {
                        for (ll x = 0; x <= nx - 1; ++x)
                        {
                            if (now[y][x] == 1)
                            {
                                for (ll p = 0; p <= 8 - 1; ++p)
                                {
                                    ll sty = y + py[p], stx = x + px[p],
                                        ty = y + py[p] * 2, tx = x + px[p] * 2;

                                    if (inside(sty, stx, ny, nx) == true && inside(ty, tx, ny, nx) == true)
                                    {
                                        if (now[sty][stx] == 1 && now[ty][tx] == 0)
                                        {
                                            now[y][x] = 0; now[sty][stx] = 0; now[ty][tx] = 1;

                                            ll now_i = vtoi(now);
                                            dp[now_i] += dp[nowX];
                                            if (next_exist[now_i] == 0)
                                            {
                                                next.push_back(now_i);
                                                next_exist[now_i] = 1;
                                            }

                                            now[y][x] = 1; now[sty][stx] = 1; now[ty][tx] = 0;
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


        ll ans = 0;
        for (ll i = 0; i <= c; ++i)
        {
            ll nowX = (1 << i);
            if (nowX > (1 << c) - 1) break;

            ans += dp[nowX];
        }

        cout << "Case " << t << ": " << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

