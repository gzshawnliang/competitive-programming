#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void ioRedirect(string fileName)
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //submit OJ in stdin,debug in local file
    #ifndef ONLINE_JUDGE
        freopen((fileName + ".in").c_str(), "r", stdin);
        freopen((fileName + ".out").c_str(), "r", stdin);
    #endif      
}

void solve()
{
    // int N;
    // cin >> N;
    // for (int __s = 0; __s == 0; ++__s);
    // bitset<100001> b1(1);
    // bitset<100001> b2(2);
    for (int i = 1; i <= 1000 ; ++i)
    {
        bitset<10> b2(i);        
        cout << b2.to_string() << "\n";
    }
    

}

int main()
{
    //IO Redirection to .in and .out file
    //ioRedirect("milkvisits33");
    solve();

    cout.flush();
    return 0;
}