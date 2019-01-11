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


int solve(vector<int> res)
{
    int size = res.size();
    int maxProduce = -999999;
    for (int i = 1; i <= size - 1; ++i)
    {
        for (int j = 0; j <= i - 1; ++j)
        {
            maxProduce = max(maxProduce, res[i] / res[j]);
        }
    }

    return maxProduce;
}

int main()
{
    while (true)
    {
        vector<int> a;
        int maxProduce = -999999;

        while (true)
        {
            int in = -1000000;
            cin >> in;

            if (in == -1000000)
            {
                return 0;
            }
            else if (in == -999999)
            {
                break;
            }
            else if (in == 0)
            {
                maxProduce = 0;
            }

            a.push_back(in);
        }

        a.push_back(0);
        int size = a.size();

        vector<int> temp{1};
        int count = 1;

        for (int i = 0; i <= size - 1; ++i)
        {
            if (a[i] == 0)
            {
                if (temp.size() > 1)
                {
                    maxProduce = max(maxProduce, solve(temp));

                    temp.clear();
                    temp.push_back(1);
                    count = 1;
                }
            }
            else
            {
                count *= a[i];
                temp.push_back(count);
            }
        }

        cout << maxProduce << '\n';
    }

    return 0;
}
