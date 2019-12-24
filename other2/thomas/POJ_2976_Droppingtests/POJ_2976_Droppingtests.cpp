#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool cmp(double x, double y) 
{ 
    return x > y; 
}

bool check(double mid) {
  int s = 0;
  for (int i = 1; i <= n; ++i) 
    c[i] = a[i] - mid * b[i];
  sort(c + 1, c + n + 1, cmp);
  for (int i = 1; i <= n - k + 1; ++i) 
    s += c[i];
    
  return s > 0;
}

void solve()
{
    while (true)
    {
        int n=0;
        int k=0;
        cin >>n >> k;

        vector<pair<int,int>> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {   
            cin >> a[i].first;
        }
        for (int i = 0; i <= n - 1; ++i)
        {   
            cin >> a[i].second;
        }        

        if(n==0 && k==0)        
            break;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("POJ_2976_Droppingtests.in", "r", stdin);
        //freopen("POJ_2976_Droppingtests.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}