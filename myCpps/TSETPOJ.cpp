#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    struct nums
    {
        int a;
        int b;
        int c;
        int sum() const
        {
            return a + b + c;
        }
        bool operator < (const nums &temp) const
        {
            if (sum() != temp.sum())
            {
                return sum() < temp.sum();
            }
            else if (a != temp.a)
            {
                return a < temp.a;
            }
            else if (b != temp.b)
            {
                return b < temp.b;
            }
            else
            {
                return c < temp.c;
            }
        }
    };

    vector<nums> out;

    for (int a = 1; 3 * a <= 25599; ++a)
    {
        for (int b = a; a + 2 * b <= 25599; ++b)
        {
            if (a * b == 10000)
            {
                continue;
            }
            if ((10000 * (a + b) % (a * b - 10000)) != 0)
            {
                continue;
            }
            int c = (10000 * (a + b)) / (a * b - 10000);
            if (c >= b)
            {
                nums temp{a, b, c};
                out.push_back(temp);
                //cout << (a + b + c) / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
            }
        }
    }

    sort(out.begin(), out.end());

    //while (true)
    //{
        double temp1 = -1.0, temp2 = -1.0;
        cin >> temp1 >> temp2;

        // if (cin.eof() == true || temp1 == -1.0 || temp2 == -1.0)
        // {
        //     break;
        // }

        int start = round(temp1 * 100), end = round(temp2 * 100);
        cout << fixed << setprecision(2);

        int size = out.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            int a = out[i].a;
            int b = out[i].b;
            int c = out[i].c;

            if (a + b + c >= start && a + b + c <= end)
            {
                cout << (a + b + c) / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
            }
        }
    //}
    
}

int main()
{   
    solve();
    return 0;
}