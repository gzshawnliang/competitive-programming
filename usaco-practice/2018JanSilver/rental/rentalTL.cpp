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

long long sell(bool &outS, int g, vector<store> & sto)
{
    int m = sto.size(), i = m - 1;
    long long ans = 0;

    while (g > 0)
    {
        if (i < 0)
        {
            outS = true;
            break;
        }
        else if (sto[i].Mg > g)
        {
            sto[i].Mg -= g;
            ans += g * sto[i].price;

            g = 0;
        }
        else
        {
            ans += sto[i].Mg * sto[i].price;
            
            g -= sto[i].Mg;
            sto[i].Mg = 0;

            --i;
        }
    }

    return ans;
}

long long check(int g, vector<store> & sto)
{
    int m = sto.size(), i = m - 1;
    long long ans = 0;

    while (g > 0 && i >= 0)
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

            --i;
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

    bool outS = false;
    int i = n - 1, j = r - 1;
    long long ans = 0;
    for (int c = 1; c <= n; ++c)
    {
        long long S = 0, N = 0;

        if (outS == false)
        {
            S = check(gal[i], sto);
        }
        if (j >= 0)
        {
            N = nei[j];
        }
        
        ans += max(S, N);

        if (S < N)
        {
            outS = false;
            --j;

            gal.erase(gal.begin());
            --i;
        }
        else
        {
            sell(outS, gal[i], sto);
            --i;
        }
    }

    fout << ans << '\n';

    return 0;
}
