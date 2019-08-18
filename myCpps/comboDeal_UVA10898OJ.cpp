#include <bits/stdc++.h>

using namespace std;


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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int t = 0;
    while (true)
    {
        int ic = 0; cin >> ic;
        if (ic == 0) break;

        ++t;

        vector<combo> menu;
        for (int i = 0; i <= ic - 1; ++i)
        {
            int p; cin >> p;

            string s;
            for (int k = 1; k <= ic; ++k) s += '0';
            s[i] = '1';

            menu.push_back(_combo(stoi(s), p));
        }

        int cc; cin >> cc;
        for (int c = 1; c <= cc; ++c)
        {
            string s;
            for (int i = 0; i <= ic - 1; ++i)
            {
                char ch; cin >> ch;
                s += ch;
            }

            int p; cin >> p;

            menu.push_back(_combo(stoi(s), p));
        }

        int oc; cin >> oc;
        for (int c = 1; c <= oc; ++c)
        {
            string s;
            for (int i = 0; i <= ic - 1; ++i)
            {
                char ch; cin >> ch;
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

            cout << dp[n] << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

