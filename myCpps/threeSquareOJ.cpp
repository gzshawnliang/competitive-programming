#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total;
    cin >> total;
    for (int t = 1; t <= total; ++t)
    {
        int k;
        cin >> k;
        int maxLoop = sqrt(k);
        bool ok = false;
        for (int a = 0; a <= maxLoop && ok == false; ++a)
        {
            for (int b = a; b <= maxLoop && ok == false; ++b)
            {
                if (0)
                {
                    for (int c = b; c <= maxLoop && ok == false; ++c)
                    {
                        if (a * a + b * b + c * c == k)
                        {
                            cout << a << ' ' << b << ' ' << c << '\n';
                            ok = true;
                        }
                    }
                }
                else
                {
                    int c = k - a * a - b * b;
                    int temp = sqrt(c);
                    if (temp * temp == c)
                    {
                        cout << a << ' ' << b << ' ' << temp << '\n';
                        ok = true;
                    }
                }
            }
        }
        if (ok == false)
        {
            cout << "-1\n";
        }
    }

    cout.flush();

    return 0;
}