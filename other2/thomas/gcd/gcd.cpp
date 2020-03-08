#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int myGCD(vector<int> & a)
{
    int gcd=0;
    int n=a.size();
    for (int i = 0; i <= n - 1; ++i)
    {
        gcd=__gcd(gcd,a[i]);
    }
    return gcd;
}

void solve()
{
    // cout << __gcd(0,0) << '\n';
    // cout << __gcd(0,4) << '\n';
    // cout << __gcd(4,0) << '\n';
    // cout << __gcd(4,2) << '\n';
    // cout << __gcd(4,2) << '\n';

    int t = 3 * 5 * 7 * 11 * 13 * 17 * 19 ;
    vector<int> a={t/3,t/5,t/7,t/11,t/13,t/17,t/19};
    //vector<int> a={t/3,t/5};

    cout << myGCD(a) << '\n';
    cout << 7 * 11 * 13 * 17 * 19  << "\n";
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //freopen("gcd.in", "r", stdin);
        //freopen("gcd.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}