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

long long checkMilk(long long & stoI, long long g, vector<store> & sto)
{
    int m = sto.size(), i = stoI;
    long long ans = 0;

    while (i <= m - 1 && g > 0)
    {
        if (sto[i].maxG >= g)
        {
            ans += g * sto[i].price;

            g = 0;
        }
        else
        {
            ans += sto[i].maxG * sto[i].price;      

            g -= sto[i].maxG;

            ++i;
        }
    }

    return ans;
}

long long sellMilk(long long & stoI, long long g, vector<store> & sto)
{
    int m = sto.size();

    while (stoI <= m - 1 && g > 0)
    {
        if (sto[stoI].maxG >= g)
        {
            sto[stoI].maxG -= g;
            g = 0;
        }
        else
        {
            g -= sto[stoI].maxG;
            sto[stoI].maxG = 0;

            ++stoI;
        }
    }
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
    sort(cow.begin(), cow.end(), greater<long long>());

    for (int i = 0; i <= m - 1; ++i)
    {
        fin >> sto[i].maxG >> sto[i].price;
    }
    sort(sto.begin(), sto.end());

    for (int i = 0; i <= r - 1; ++i)
    {
        fin >> nei[i];
    }
    sort(nei.begin(), nei.end());

    if (r < n)
    {
        long long temp = n - r;
        for (int c = 1; c <= temp; ++c)
        {
            nei.insert(nei.begin(), 0);
            ++r;
        }
    }
    else if (r > n)
    {
        long long temp = r - n;
        for (int c = 1; c <= temp; ++c)
        {
            nei.erase(nei.begin());
            --r;
        }
    }

    long long stoI = 0, ans = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        int stoRes = 0, neiRes = 0;

        if (stoI <= m - 1)
        {
            stoRes = checkMilk(stoI, cow[i], sto);
        }

        neiRes = nei[i];

        if (stoRes >= neiRes)
        {
            sellMilk(stoI, cow[i], sto);

            ans += stoRes;
        }
        else
        {
            ans += neiRes;
        }
    }

    fout << ans << '\n';

    return 0;
}
