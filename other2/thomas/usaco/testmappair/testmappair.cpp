#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    freopen("testmappair.in", "r", stdin);
    freopen("testmappair.out", "w", stdout);

    //vector<pair<int,int>> a={{1,5},{3,6},{2,4},{4,6},{4,7},{2,9}};
    //vector<pair<int,int>> a={{2,9},{3,6}};
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i].first;
        cin >> a[i].second;
        if (a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
    }

    sort(a.begin(), a.end());

    /*---------------------------------------------
    使用GeoGebra命令划线
    Execute({
    "Segment((0,1),(4,1))",
    "Segment((0,2),(13,2))",
    "Segment((0,3),(14,3))",
    "Segment((0,4),(18,4))",
    "Segment((1,5),(4,5))",
    "Segment((1,6),(14,6))",
    "Segment((3,7),(12,7))",
    "Segment((5,8),(17,8))",
    "Segment((5,9),(20,9))",
    "Segment((6,10),(19,10))",
    "Segment((6,11),(20,11))",
    "Segment((7,12),(14,12))",
    "Segment((8,13),(13,13))",
    "Segment((8,14),(13,14))",
    "Segment((8,15),(20,15))",
    "Segment((10,16),(20,16))",
    "Segment((11,17),(17,17))",
    "Segment((12,18),(17,18))",
    "Segment((14,19),(20,19))",
    "Segment((15,20),(19,20))"
    })
    */

    // int k=1;
    // cout << "Execute({\n";
    // for (auto i:a)
    // {
    //     cout << "\"Segment((" <<i.first<<"," << k << "),("<< i.second << "," << k <<"))\"";
    //     ++k;

    //     if(k<=a.size())
    //         cout << ",\n";
    // }
    // cout << "\n})\n";

    for (int i = 0; i <= m - 1; ++i)
    {
        int ans = 0;
        int l, r;
        cin >> l;
        cin >> r;
        if (l > r)
            swap(l, r);
        auto posL = upper_bound(a.begin(), a.end(), make_pair(l, 0));
        auto posR = upper_bound(a.begin(), a.end(), make_pair(r, 0));

        for (; posL != posR && posL != a.end(); ++posL)
            if ((*posL).second <= r)
                ++ans;

        cout << ans << "\n";
    }

    cout.flush();
    return 0;
}
