#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("differentDigits.in");
ofstream fout("differentDigits.out");

int main()
{
    vector<int> store(5001);
    store[0] = 0;
    for (int i = 1; i <= 5000; ++i)
    {
        vector<bool> dp(10, false);
        string now = to_string(i);
        int size = now.size();
        bool is = true;
        for (int j = 0; j <= size - 1; ++j)
        {
            if (dp[now[j] - '0'] == true)
            {
                is = false;
                break;
            }
            else
            {
                dp[now[j] - '0'] = true;
            }
        }
        store[i] = store[i - 1] + is;
    }

    while (true)
    {
        int n = 0, m;
        fin >> n >> m;
        if (n == 0)
        {
            break;
        }

        fout << store[m] - store[n - 1] << '\n';
    }
}
