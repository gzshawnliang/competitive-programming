#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("rental.in");
ofstream fout("rental.out");

struct store
{
    long long maxG;
    long long price;

    bool operator < (const store & temp) const
    {
        return price > temp.price;
    }
};

long long checkMilk(bool mode, long long & stoI, long long g1, long long g2, vector<store> & sto)
{
    int m = sto.size(), i = stoI;
    long long ans = 0;

    while (i <= m - 1 && g1 > 0)
    {
        if (sto[i].maxG >= g1)
        {
            ans += g1 * sto[i].price;

            if (i <= m - 2 && mode == 0)
            {
                ans -= checkMilk(1, stoI, g2, g2, sto);

                sto[i].maxG -= g1;

                ans += checkMilk(1, stoI, g2, g2, sto);

                sto[i].maxG += g1;
            }

            g1 = 0;
        }
        else
        {
            ans += sto[i].maxG * sto[i].price;

            if (i <= m - 2 && mode == 0)
            {
                sto[i].maxG -= sto[i].maxG;

                ans *= 2;
                ans -= checkMilk(1, stoI, g2, g2, sto);

                sto[i].maxG += sto[i].maxG;
            }

            g1 -= sto[i].maxG;

            ++i;
        }
    }

    return ans;
}

long long sellMilk(long long & stoI, long long g, vector<store> & sto)
{
    int m = sto.size();
    long long ans = 0;

    while (stoI <= m - 1 && g > 0)
    {
        if (sto[stoI].maxG >= g)
        {
            ans += g * sto[stoI].price;

            sto[stoI].maxG -= g;
            g = 0;
        }
        else
        {
            ans += sto[stoI].maxG * sto[stoI].price;

            g -= sto[stoI].maxG;
            sto[stoI].maxG = 0;

            ++stoI;
        }
    }

    return ans;
}

int main()
{
    long long n, m, r; fin >> n >> m >> r;
    vector<long long>  cow(n),  //gallons 
                       nei(r);  //neighbors
    vector<store>      sto(m);  //stores  

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> cow[i];
    }
    sort(cow.begin(), cow.end());

    for (int i = 0; i <= m - 1; ++i)
    {
        fin >> sto[i].maxG >> sto[i].price;
    }
    sort(sto.begin(), sto.end());

    for (int i = 0; i <= r - 1; ++i)
    {
        fin >> nei[i];
    }
    sort(nei.begin(), nei.end(), greater<long long>());

    long long stoI = 0, neiI = 0, ans = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        long long resSto = 0, resNei = 0;
        if (stoI <= m - 1)
        {
            if (i <= n - 2)
            {
                resSto = checkMilk(0, stoI, cow[i], cow[i + 1], sto);
            }
            else
            {
                resSto = checkMilk(0, stoI, cow[i], 0, sto);
            }
        }
        
        if (neiI <= r - 1)
        {
            resNei = nei[neiI];
        }

        if (resSto + resNei == 0)
        {
            break;
        }
        else if (resSto >= resNei)
        {
            ans += sellMilk(stoI, cow[i], sto);
        }
        else
        {
            ++neiI;

            ans += resNei;
        }
    }

    fout << ans << '\n';

    return 0;
}
