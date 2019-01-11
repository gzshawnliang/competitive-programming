#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        int n = 0;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        vector<long long> a = {1, 1};
        for (int i = 3; i <= n + 1; ++i)
        {
            vector<long long> temp = {1};
            for (int j = 1; j <= i - 2; ++j)
            {
                temp.push_back(a[j - 1] + a[j]);
            }
            temp.push_back(1);

            a = temp;
        }

        for (int i = 0; i <= n; ++i)
        {
            if (i == 0)
            {
                cout << a[i] << "a^" << n;
            }
            else
            {
                cout << " + ";
                if (i == n)
                {
                    cout << a[i] << "b^" << n;
                    
                }
                else
                {
                    cout << a[i] << "a^" << n - i << " * b^" << i;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}