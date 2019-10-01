#include <bits/stdc++.h>

using namespace std;

ifstream fin("howBigIsIt_UVA10012.in");
ofstream fout("howBigIsIt_UVA10012.out");

const double inf = (double)(INT_MAX) / 2.0, eps = 1e-9;

int main()
{
    fout << fixed << setprecision(3);

    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        int n; fin >> n;
        
        vector<double> r(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> r[i];
        }
        sort(r.begin(), r.end());

        double ans = inf;
        do
        {
            vector<double> last; last.push_back(r[0]);

            for (int i = 1; i <= n - 1; ++i)
            {
                double left = max(last.back(), r[i]), right = inf;
                while (true)
                {
                    if (left < right && abs(left - right) < eps)
                    {
                        break;
                    }

                    double m = (left + right) / 2.0;

                    bool flag = true;
                    for (int j = 0; j <= i - 1 && flag == true; ++j)
                    {
                        if (pow(m - last[j], 2) + pow(r[i] - r[j], 2) < pow(r[i] + r[j], 2))
                        {
                            flag = false;
                        }
                    }

                    if (flag == true)
                    {
                        right = m;
                    }
                    else
                    {
                        left = m;
                    }
                }

                last.push_back(left);
            }

            double res = 0.0;
            for (int i = 0; i <= n - 1; ++i)
            {
                res = max(res, last[i] + r[i]);
            }

            ans = min(ans, res);
        }
        while (next_permutation(r.begin(), r.end()));

        fout << ans << '\n';
    }

    return 0;
}
