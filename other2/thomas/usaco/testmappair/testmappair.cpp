#include <bits/stdc++.h>

using namespace std;

const int inf =INT_MAX /2;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);    
    freopen("testmappair.in", "r", stdin);
    freopen("testmappair.out", "w", stdout);


    //vector<pair<int,int>> a={{1,5},{3,6},{2,4},{4,6},{4,7},{2,9}};
    //vector<pair<int,int>> a={{2,9},{3,6}};
    int n,m;
    cin >> n>>m;
    vector<pair<int,int>> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        cin>>a[i].first;
        cin>>a[i].second;
        if(a[i].first>a[i].second)
            swap(a[i].first,a[i].second);
    }
  
    sort(a.begin(),a.end());

    // int k=1;
    // for (auto i:a)
    // {
    //     cout << "segment((" <<i.first<<"," << k << "),("<< i.second << "," << k <<"))\n";
    //     ++k;
    // }
    

    for (int i = 0; i <= m - 1; ++i)
    {
        int ans=0;
        int l,r;
        cin>>l;
        cin>>r;
        if(l>r)
            swap(l,r);
        auto posL=upper_bound(a.begin(),a.end(),make_pair(l,0));
        auto posR=upper_bound(a.begin(),a.end(),make_pair(r,0));

        for(;posL!=posR && posL !=a.end();++posL)
            if((*posL).second<=r)
                ++ans;

        cout << ans << "\n";
    }  

    cout.flush();
    return 0;
}



