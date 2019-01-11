#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("primeLand_UVA516.in");
ofstream fout("primeLand_UVA516.out");

struct prime
{
    long long a;
    long long k;
};

long long _pow(long long a, long long k)
{
    long long ans = 1;
    for (long long c = 1; c <= k; ++c)
    {
        ans *= a;
    }

    return ans;
}

int main()
{
    while (true)
    {
        string in = "";
        getline(fin, in);
        if (in == "0" || in == "") break;

        if (in == "2 3")
        {
            cout << "";
        }

        long long size0 = in.size(), last = -1, n = 1;
        string temp0 = "";
        for (long long i = 0; i <= size0 - 1; ++i)
        {
            if (in[i] == ' ')
            {
                if (last == -1)
                {
                    last = stoi(temp0);
                }
                else
                {
                    n *= _pow(last, stoi(temp0));
                    last = -1;
                }

                temp0 = "";
            }
            else
            {
                temp0 += in[i];
            }
        }
        n *= _pow(last, stoi(temp0));
        --n;

        vector<prime> ans;
        for (long long i = 2; i * i <= n; i += 2)
        {
            long long c = 0;
            while (n % i == 0)
            {
                ++c;
                n /= i;
            }

            if (c > 0)
            {
                prime temp1{i, c};
                ans.push_back(temp1);
            }

            if (i == 2)
            {
                i = 1;
            }
        }

        if (n > 1)
        {
            prime temp1{n, 1};
            ans.push_back(temp1);
        }

        long long size1 = ans.size();
        for (long long i = size1 - 1; i >= 0; --i)
        {
            if (i < size1 - 1) fout << ' ';
            fout << ans[i].a << ' ' << ans[i].k;
        }
        fout << '\n';
    }

    return 0;
}