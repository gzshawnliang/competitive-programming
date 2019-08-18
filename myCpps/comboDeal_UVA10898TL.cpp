#include <bits/stdc++.h>

using namespace std;

ifstream fin("comboDeal_UVA10898.in");
ofstream fout("comboDeal_UVA10898.out");

const int inf = INT_MAX / 3;

struct combo
{
    string ec;
    int price;
};
combo _combo(string ec, int price)
{
    combo temp{ec, price}; return temp;
}

int main()
{
    int t = 0;
    while (true)
    {
        int ic = 0; fin >> ic;
        if (ic == 0) break;

        ++t;

        vector<combo> menu;
        for (int i = 0; i <= ic - 1; ++i)
        {
            int p; fin >> p;

            string s;
            for (int k = 1; k <= ic; ++k) s += '0';
            s[i] = '1';

            menu.push_back(_combo(s, p));
        }

        int cc; fin >> cc;
        for (int c = 1; c <= cc; ++c)
        {
            string s;
            for (int i = 0; i <= ic - 1; ++i)
            {
                char ch; fin >> ch;
                s += ch;
            }

            int p; fin >> p;

            menu.push_back(_combo(s, p));
        }

        int n = pow(10, ic);
        vector<int> dp(n, inf); dp[0] = 0;

        int size = menu.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            for (int j = 0; j <= n - 1; ++j)
            {
                bool ok = true;
                string now = to_string(j), last;
                while (now.size() < ic)
                {
                    now = '0' + now;
                }

                if (i == 3 && j == 1)
                {
                    for (int __s = 0; __s == 0; ++__s);
                }

                for (int k = 0; k <= ic - 1; ++k)
                {
                    if (now[k] < menu[i].ec[k])
                    {
                        ok = false;
                        break;
                    }
                    else
                    {
                        char ch = '0' + (now[k] - menu[i].ec[k]);
                        last += ch;
                    }
                }

                if (ok == true)
                {
                    dp[stoi(now)] = min(dp[stoi(now)], dp[stoi(last)] + menu[i].price);
                }
            }
        }

        int oc; fin >> oc;
        for (int c = 1; c <= oc; ++c)
        {
            string s;
            for (int i = 0; i <= ic - 1; ++i)
            {
                char ch; fin >> ch;
                s += ch;
            }

            fout << dp[stoi(s)] << '\n';
        }
    }

    return 0;
}
