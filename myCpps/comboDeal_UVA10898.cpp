#include <bits/stdc++.h>

using namespace std;

ifstream fin("comboDeal_UVA10898.in");
ofstream fout("comboDeal_UVA10898.out");

const int inf = INT_MAX / 3;

struct combo
{
    int ec;
    int price;
};
combo _combo(int ec, int price)
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

            menu.push_back(_combo(stoi(s), p));
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

            menu.push_back(_combo(stoi(s), p));
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

            int n = stoi(s);
            vector<int> dp(n + 1, inf); dp[0] = 0;

            int size = menu.size();
            for (int i = 0; i <= size - 1; ++i)
            {
                int x = menu[i].ec;
                for (int now = x; now <= n; ++now)
                {
                    bool ok = true;
                    int tempX = x, tempNow = now;
                    while (tempX > 0 && tempNow > 0)
                    {
                        if (tempX % 10 > tempNow % 10)
                        {
                            ok = false;
                            break;
                        }

                        tempX /= 10; tempNow /= 10;
                    }

                    if (ok == true)
                    {
                        dp[now] = min(dp[now], dp[now - x] + menu[i].price);
                    }
                }
            }

            fout << dp[n] << '\n';
        }
    }

    return 0;
}
