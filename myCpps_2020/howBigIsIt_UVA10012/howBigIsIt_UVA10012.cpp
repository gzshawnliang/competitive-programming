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
                for (int j = 0; j <= i - 1; ++j)
                {
                    double x = last[j] + sqrt(pow(r[i] + r[j], 2) - pow(r[i] - r[j], 2));
                    x = max(x, r[i]);

                    bool flag = true;
                    for (int k = 0; k <= i - 1 && flag == true; ++k)
                    {
                        if (j == k) continue;
                        if (x < last[k]) flag = false;

                        double d21 = pow(r[i] - r[k], 2) + pow(x - last[k], 2),
                               d22 = pow(r[i] + r[k], 2);
                        if (d21 < d22 && abs(d21 - d22) > eps)
                        {
                            flag = false;
                        }
                    }

                    if (flag == true)
                    {
                        last.push_back(x);
                        break;
                    }
                }
            }

            if (r[1] == 8)
            {
                for (int __s = 0; __s == 0; ++__s);
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
