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
    long long Mg;
    long long price;

    bool operator < (const store & temp) const
    {
        return price < temp.price;
    }
};

long long _max(int g, vector<store> & sto)
{
    int m = sto.size();
    long long ans = 0;

    for (int i = m - 1; i >= 0 && g > 0; --i)
    {
        if (sto[i].Mg > g)
        {
            ans += g * sto[i].price;
            g = 0;
        }
        else
        {
            ans += sto[i].Mg * sto[i].price;
            g -= sto[i].Mg;
        }
    }

    return ans;
}

int main()
{
    int n, m, r; fin >> n >> m >> r;
    vector<long long>  gal(n),  //gallons 
                       nei(r);  //neighbors
    vector<store>      sto(m);  //stores  

    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> gal[i];
    }
    sort(gal.begin(), gal.end());

    for (int i = 0; i <= m - 1; ++i)
    {
        fin >> sto[i].Mg >> sto[i].price;
    }
    sort(sto.begin(), sto.end());

    for (int i = 0; i <= r - 1; ++i)
    {
        fin >> nei[i];
    }
    sort(nei.begin(), nei.end());

    long long ans = 0;
    for (int milk = 0; milk <= n; ++milk)
    {
        long long totalMilk = 0, totalMoneyMilk = 0, totalMoneyRental = 0;

        for (int i = n - 1; i >= n - 1 - milk + 1; --i)
        {
            totalMilk += gal[i];
        }
        totalMoneyMilk = _max(totalMilk, sto);

        for (int i = r - 1; i >= max(r - 1 - (n - milk) + 1, 0); --i)
        {
            totalMoneyRental += nei[i];
        }

        ans = max(ans, totalMoneyMilk + totalMoneyRental);
    }

    fout << ans << '\n';

    return 0;
}
