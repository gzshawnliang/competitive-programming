#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{

    // int cnt=0;
    // int total=1<<10;

    // for (int i = 0; i <= total - 1; ++i)
    // {   
    //     bitset<10> b(i);
    //     bitset<10> b1(i<<1);
    //     bitset<10> b2(i<<2);
    //     if ((i & (i << 1)) == 0 && (i & (i << 2)) == 0)
    //     {
    //         cout << b.to_string() << "\n";
    //         // cout << b1.to_string() << " ";
    //         // cout << b2.to_string() << ":ok\n";
    //         ++cnt;
    //     }
    //     // else
    //     // {
    //     //     cout << b.to_string() << " ";
    //     //     cout << b1.to_string() << " ";
    //     //     cout << b2.to_string() << ":bad\n";
    //     // }
        
    // }
    // cout << cnt;   


    bitset<10> b1("010100");
    bitset<10> b2("001110");

    cout << (b1 & b2).to_string() ;
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //freopen("3.in", "r", stdin);
        //freopen("3.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}
