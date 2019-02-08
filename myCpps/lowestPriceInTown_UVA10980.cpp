#include <bits/stdc++.h>

using namespace std;

ifstream fin("lowestPriceInTown_UVA10980.in");
ofstream fout("lowestPriceInTown_UVA10980.out");

const int maxK = 200;

struct scheme
{
    int n;
    int p;

    bool operator<(const scheme & temp) const
    {
       if (n != temp.n)
       {
            return n < temp.n;
       }
       else
       {
            return p < temp.p;
       }
    }
};

int round_double(double number)
{
    return (number > 0.0) ? floor(number + 0.5) : ceil(number - 0.5);
}

int main()
{
    fout << fixed << setprecision(2);

    int t = 0;
    while (true)
    {
        ++t;

        int m = -1;
        double tempIn1 = 0.0;

        fin >> tempIn1 >> m;
        int u = round_double(tempIn1 * 100.0);

        if (m == -1)  break;

        ++m;

        vector<scheme> s(m);
        for (int i = 0; i <= m - 2; ++i)
        {
            double tempIn2;

            fin >> s[i].n >> tempIn2;
            s[i].p = round_double(tempIn2 * 100.0);
        }
        s[m - 1].n = 1; s[m - 1].p = u;

        sort(s.begin(), s.end());

        for (int i = 1; i <= m - 1; ++i)
        {
            while (s[i].n == s[i - 1].n && i <= m - 1)
            {
                s.erase(s.begin() + i);
                --m;
            }
        }


        string in;
        getline(fin, in); getline(fin, in);

        int sizeI = in.size();
        string temp = "";
        vector<int> a;

        for (int i = 0; i <= sizeI; ++i)
        {
            if (in[i] == ' ' || i == sizeI)
            {
                a.push_back(stoi(temp));

                temp = "";
            }
            else
            {
                temp += in[i];
            }
        }


        int sizeA = a.size();
        int sizeS = s.size();
        vector<vector<int>> dp(sizeS, vector<int>(maxK + 1, INT_MAX));

        for (int i = 0; i <= sizeS - 1; ++i)
        {
            for (int j = 0; j <= maxK; ++j)
            {
                dp[i][j] = min(dp[i][j], j * u);

                if (i == 0)
                {
                    if (j >= s[i].n && j % s[i].n == 0)
                    {
                        dp[i][j] = min(dp[i][j], (j / s[i].n) * s[i].p);
                    }
                }
                else
                {
                    for (int c = 0; c * s[i].n <= j; ++c)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - c * s[i].n] + c * s[i].p);
                    }
                }
            }
        }

        fout << "Case " << t << ":\n";
        for (int _i = 0; _i <= sizeA - 1; ++_i)
        {
            int k = a[_i], ans = INT_MAX;

            for (int j = k; j <= maxK; ++j)
            {
                ans = min(ans, dp[sizeS - 1][j]);
            }
       
            fout << "Buy " << k << " for $" << (double)ans / 100.0 << '\n';
        }
    }

    return 0;
}
