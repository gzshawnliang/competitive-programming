#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
#endif

    map<string, int> f;
    int n;
    string s;

    cin >> n;
    int totalAns = n * (n - 1) / 2; //总共对数

    for (int i = 1; i <= n; i++)
    {
        vector<string> a(6);
        for (int j = 1; j <= 5; j++)
            cin >> a[j];

        sort(a.begin() + 1, a.end()); //从小到大排序

        int ans = 0;
        for (int i = 1; i < 32; ++i)
        {
            //二进制枚举出所有情况
            bitset<5> b(i);

            int cnt = 0;
            string s = "";
            for (int j = 1; j <= 5; ++j)
            {
                if (b[j - 1] == 1)
                {
                    ++cnt;
                    s += a[j] + "|";
                } //将选出的口味用“？”连接出来
            }

            if (cnt % 2 == 0)
                ans -= f[s]; //偶数个则减去
            else
                ans += f[s]; //奇数个则累加

            ++f[s];
        }
        totalAns -= ans; //减去和谐的，容斥
    }

    for (auto it : f)
        cout << std::left << setw(15) << it.first << " " << it.second << "\n";

    cout << totalAns;
    return 0;
}

int main2()
{
#ifndef ONLINE_JUDGE
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
#endif

    map<string, int> f;
    int n;
    string s;

    cin >> n;
    int totalAns = n * (n - 1) / 2; //总共对数

    for (int i = 1; i <= n; i++)
    {
        vector<string> a(6);
        for (int j = 1; j <= 5; j++)
            cin >> a[j];

        sort(a.begin() + 1, a.end()); //从小到大排序

        int ans = 0;
        for (int i = 1; i < 32; ++i)
        {
            //二进制枚举出所有情况
            int cnt = 0;
            string s = "";
            for (int j = 1; j <= 5; ++j)
            {
                if (i & (1 << (j - 1)))
                {
                    ++cnt;
                    s += "?" + a[j];
                } //将选出的口味用“？”连接出来
            }

            if (cnt % 2 == 0)
                ans -= f[s]; //偶数个则减去
            else
                ans += f[s]; //奇数个则累加

            ++f[s];
        }
        totalAns -= ans; //减去和谐的，容斥
    }

    for (auto it : f)
    {
        cout << std::left << setw(15) << it.first << " " << it.second << "\n";
    }

    cout << totalAns;
    return 0;
}

// int main3()
// {

//     for (int j = 1; j <= 5 ; ++j)
//     {
//         int r=(1<<(j-1));
//         cout << "1<<("<< j <<"-1)=1<<("<< j-1 <<") "  << r << "\n";
//     }
//     cout << "\n";
//     for (int i = 1; i <= 32-1 ; ++i)
//     {
//         for (int j = 1; j <= 5 ; ++j)
//         {
//             int r=(1<<(j-1));
//             //cout << "1<<(j-1) " << r <<
//             cout << setw(2) << i << " & "<< setw(2) << r << setw(8) << (i & r) <<  "\n";
//         }
//     }

//     return 0;
// }

int main4()
{

    for (int i = 1; i <= 32 - 1; ++i)
    {
        bitset<5> b(i);
        cout << setw(2) << i << setw(6) << b.to_string() << "\n";
        cout << "---------"
             << "\n";
        for (int j = 1; j <= 5; ++j)
        {
            int r = (1 << (j - 1));
            bitset<5> c(r);
            cout << setw(2) << j << setw(6) << c.to_string() << "\n";
        }
        cout << "\n";
    }

    return 0;
}

int main33()
{
    vector<int> a = {1, 2, 3, 4, 5};

    for (int i = 0; i <= 5 - 1; ++i)
    {
        cout << a[i] << "-\n";

        for (int k = 0; k <= 5 - 1; ++k)
        {
            if (k != i)
            {
                cout << a[k] << "-";
            }
        }
        cout << "\n";
    }

    for (int i = 0; i <= 5 - 1; ++i)
    {
        for (int j = i + 1; j <= 5 - 1; ++j)
        {
            cout << a[i] << "-" << a[j] << "-\n";
            for (int k = 0; k <= 5 - 1; ++k)
            {
                if (k != i && k != j)
                {
                    cout << a[k] << "-";
                }
            }
            cout << "\n";
        }
    }

    for (int k = 0; k <= 5 - 1; ++k)
    {
        cout << a[k] << "-";
    }
    cout << "\n";

    cout << "-----------------\n";

    for (int i = 1; i < 32; ++i)
    {
        //二进制枚举出所有情况
        string s = "";
        for (int k = 1; k <= 5; ++k)
        {
            if (i & (1 << (k - 1)))
            {
                cout << a[k - 1] << "-";
            }
        }
        cout << "\n";
    }

    return 0;
}