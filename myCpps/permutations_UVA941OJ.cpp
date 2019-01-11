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


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<long long> f(21); f[0] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        f[i] = f[i - 1] * i;
    }

    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        long long n;
        string s;
        cin >> s >> n;

        sort(s.begin(), s.end());

        int size = s.size();

        for (int i = size - 1; i >= 0; --i)
        {
            long long pos = n / f[i], count = 0;
            for (int j = 0; j <= size - 1; ++j)
            {
                if (s[j] != 0)
                {
                    if (count == pos)
                    {
                        cout << s[j];
                        s[j] = 0;

                        break;
                    }
                    else
                    {
                        ++count;
                    }
                }
            }

            n %= f[i];
        }

        cout << '\n';
    }

   	cout.flush();
   	return 0;
}
