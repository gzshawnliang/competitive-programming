#include <bits/stdc++.h>

using namespace std;

using ll=long long;

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");



struct lifeguard
{
    ll l;
    ll r;
};

int main()
{
    ll N;
    fin >> N;
    vector<lifeguard> a(N);
    for (ll i = 0; i <= N - 1; ++i)
    {
        fin>>a[i].l>>a[i].r;
    }

    sort(a.begin(), a.end(), [](lifeguard a, lifeguard b) 
    {
        return a.l < b.l;
    });

    ll total=0;
    lifeguard mergeGuard=a[0];
    for (ll i = 1; i <= N - 1; ++i)
    {
        if(mergeGuard.r>=a[i].l)
        {
            mergeGuard.r=max(a[i].r,mergeGuard.r);
        }
        else
        {
            total +=(mergeGuard.r-mergeGuard.l);    
            mergeGuard=a[i];
        }
    }
    total +=(mergeGuard.r-mergeGuard.l);

    ll minTime=(ll)INT_MAX;
    ll l=a[0].l;
    ll r=a[0].r;
    for (ll i = 0; i <= N - 2; ++i)
    {
        if(l>a[i+1].l)
            a[i+1].l=l;

        if(l<=a[i+1].l)
        {
            if(r>a[i+1].l)
            {
                if(r <a[i+1].r)
                {
                    minTime=a[i+1].l-l;
                    l=a[i].r;
                    r=a[i+1].r;
                }
                else
                {
                    minTime =0;
                }
                
            }
            else
            {
                minTime = min(r - l, minTime);
                l=a[i+1].l;
                r=a[i+1].r;
            }
        }
       

        if(minTime==0)
            break;
        
    }
    fout << total-minTime << "\n";
    return 0;
}
