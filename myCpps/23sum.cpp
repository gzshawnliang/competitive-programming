#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("23sum.in");
ofstream fout("23sum.out");

int o(int a, int b, int v)
{
    if (v == 0)
    {
        return a + b;
    }
    else if (v == 1)
    {
        return a - b;
    }
    else if (v == 2)
    {
        return a * b;
    }
}

char p(int v)
{
    if (v == 0)
    {
        return '+';
    }
    else if (v == 1)
    {
        return '-';
    }
    else if (v == 2)
    {
        return '*';
    }
}

int main()
{
    while (true)
    {
        vector<int> a(5);
        int total = 0;
        for (int i = 0; i <= 4; ++i)
        {
            fin >> a[i];
            total += a[i];
        }

        if (total == 0)
        {
            break;
        }

        sort(a.begin(), a.end());
        bool ok = false;
        do
        {
            for (int p1 = 0; p1 <= 2 && ok == false; ++p1)
            {
                for (int p2 = 0; p2 <= 2 && ok == false; ++p2)
                {
                    for (int p3 = 0; p3 <= 2 && ok == false; ++p3)
                    {
                        for (int p4 = 0; p4 <= 2 && ok == false; ++p4)
                        {
                            //int ans1 = o(o(o(o(a[0], a[1], p1), a[2], p2), a[3], p3), a[4], p4);
                            long ans1 = o(a[0],a[1], p1);
                            ans1 = o(ans1,a[2], p2);
                            ans1 = o(ans1,a[3], p3);
                            ans1 = o(ans1,a[4], p4);
                            //int ans2 = o(o(o(a[0], a[1], p1), a[2], p2), o(a[3], a[4], p3), p4);
                            if (ans1 == 23)
                            {
                                ok = true;
                                fout << a[0] << p(p1) << a[1] << p(p2) << a[2] << p(p3) << a[3] << p(p4) << a[4] << '\n';
                                break;
                            }
                        }
                    }
                }
            }
        } while (next_permutation(a.begin(), a.end()) && ok == false);

        if (ok == true)
        {
            fout << "Possible\n";
        }
        else
        {
            fout << "Impossible\n";
        }
    }

    return 0;
}