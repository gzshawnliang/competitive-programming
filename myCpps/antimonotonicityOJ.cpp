#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);   

    int totalTest;
    cin >> totalTest;
    for (int c = 0; c <= totalTest - 1; ++c)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << "1\n";
            continue;
        }

        vector<int> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
        }

        int i = 0, count = 1;
        int last;
        bool lastID;
        while (i <= n - 2)
        {
            bool end0;

            end0 = false;
            while (true)
            {
                if (i <= n - 2)
                {
                    if (a[i] > a[i + 1])
                    {
                        break;
                    }
                    ++i;
                }
                else
                {
                    end0 = true;
                    break;
                }
            }

            if (end0 == true)
            {
                break;
            }
            else
            {
                ++count;
            }

            end0 = false;
            while (true)
            {
                if (i <= n - 2)
                {
                    if (a[i] < a[i + 1])
                    {
                        break;
                    }
                    ++i;
                }
                else
                {
                    end0 = true;
                    break;
                }
            }

            last = a[i];
            lastID = false;

            if (end0 == true)
            {
                break;
            }
            else
            {
                ++count;
            }
        }

        cout << count << '\n';
    }

    cout.flush();
    return 0;
}