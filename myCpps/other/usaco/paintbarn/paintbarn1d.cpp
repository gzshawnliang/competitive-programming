#include <bits/stdc++.h>

using namespace std;

const int maxL=(int) 1e6+1;
int a[maxL];
int main()
{
    freopen("paintbarn1d.in", "r", stdin);
    freopen("paintbarn1d.out", "w", stdout);
    int n,k;
    cin >> n >> k;
    //vector<int> a(1e6+1,0);
    int maxX=0;
    int minX=INT_MAX;
    while (n--)
    {
        int x1, x2;
        cin >> x1 >> x2 ;
        ++a[x1];
        --a[x2+1];
        maxX=max(maxX,x2);
        minX=min(minX,x1);
    }

    int ans = 0;
    map<int,int> ans2;
    for (int i = minX; i <= maxX +1; ++i)
    {
            //cout << a[i] << "\n";
            ++ans2[a[i]];
            if (a[i] == k)
                ++ans;
            
            a[i+1] +=a[i];
    }
    // for(auto it=ans2.begin();it!=ans2.end();++it)
    // {
    //     if(it->second >1)
    //     {
    //         cout << it->first << ":" << it->second << "\n";
    //     }
    // }

    cout << ans << endl;
    
}