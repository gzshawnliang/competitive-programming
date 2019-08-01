#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("stlDiscretization.in", "r", stdin);
    //freopen("bigdata.out", "w", stdout);

    /*
    2384632  34756437    38745673    234782364   2374863786  2734627364  4875634785  7234628734
    4        2           0           6           3           1           7           5
    */

    ll n, m;
    cin >> n;

    vector<ll> a(n);   //a[n]是即将被离散化的数组，
    vector<ll> b(n);   //b[n]离散化之后存储的值
    vector<ll> sub(n); //sub[n]用于排序去重后提供离散化后的值
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
        sub[i] = a[i]; //先赋值
    }

    sort(sub.begin(), sub.end());               //STL_SORT 排序
    auto it = unique(sub.begin(), sub.end());   //STL_UNQUE 去重，返回重复元素的第一个地址
    int size = std::distance(sub.begin(), it);
    sub.resize(size);                           //注意去重之后 需要resize，否则重复的项目放在后面没有消失
    

    //int size = sub.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        cout << sub[i] << "\t";
    }
    cout << '\n';

    for (int i = 0; i <= n - 1; ++i)
    {
        b[i] = lower_bound(sub.begin(), sub.end(), a[i]) - sub.begin();     //即b[i]为a[i]离散化后对应的值 STL_LOWER 查询。
    }
    b.resize(size);

    for (int i = 0; i <= size - 1; ++i)
    {
        cout << b[i] << "\t"; //输出离散化后的数。
    }

    cout << '\n';

    for (int i = 0; i <= size - 1; ++i)
    {
        m = sub[i];
        int x = lower_bound(sub.begin(), sub.end(), m) - sub.begin(); //知道离散前的值m，求离散后的值。 同样用lower查找。
        cout << m << "->" << b[x] << '\n';
    }
    

    // m = 38745673;
    // int x = lower_bound(sub.begin(), sub.end(), m) - sub.begin(); //知道离散前的值m，求离散后的值。 同样用lower查找。
    // cout << b[x];
    return 0;
}