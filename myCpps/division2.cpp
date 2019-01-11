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

ifstream fin("division2.in");
ofstream fout("division2.out");

vector<int> add(vector<int> a, vector<int> b)
{
    vector<int> big, small;
    if (a.size() > b.size())
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }

    int size0 = big.size() - small.size();
    for (int i = 1; i <= size0; ++i)
    {
        small.push_back(0);
    }

    vector<int> ans(big.size());
    int size1 = big.size();
    int in = 0;
    for (int i = 0; i <= size1 - 1; ++i)
    {
        int num = big[i] + small[i] + in;
        ans[i] = num % 10;
        num /= 10;
        in = num;
        if (i == size1 - 1 && num == 1)
        {
            ans.push_back(in);
        }
    }

    return ans;
}

vector<int> time(vector<int> a, vector<int> b)
{
    vector<int> big, small;
    if (a.size() > b.size())
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }

    vector<int> ans = {0};
    int size0 = small.size();
    for (int i = 0; i <= size0 - 1; ++i)
    {
        vector<int> temp = {0};
        for (int j = 1; j <= small[i]; ++j)
        {
            temp = add(temp, big);
        }
        for (int j = 1; j <= i; ++j)
        {
            temp.insert(temp.begin(), 0);
        }
        ans = add(ans, temp);
    }

    return ans;
}

bool compare(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
    {
        return true;
    }
    else if (a.size() < b.size())
    {
        return false;
    }
    else
    {
        int size0 = a.size();
        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (a[i] > b[i])
            {
                return true;
            }
            else if (a[i] < b[i])
            {
                return false;
            }
        }
    }

    return true;
}

vector<int> divide(vector<int> a, vector<int> b)
{
    int size0, size1 = b.size();

    vector<int> ans = {0};
    while (true)
    {
        vector<int> temp1, temp2;
        size0 = a.size();
        for (int i = 1; i <= size0 - size1; ++i)
        {
            temp1.push_back(0);
        }

        temp2 = temp1;
        temp2.push_back(1);

        for (int i = 0; i <= size1 - 1; ++i)
        {
            temp1.push_back(b[i]);
        }

        bool ok = false;
        for (int i = 1; i <= 9; ++i)
        {
            vector<int> temp3, temp4;
            temp3.push_back(i);
            temp4.push_back(i - 1);

            if (temp4.back() == 0)
            {
                break;
            }
            else if (compare(time(b, temp3), a) == true)
            {
                ans = add(ans, time(b, temp4));
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {0, 5, 6};
    vector<int> b = {7};

    vector<int> ans = divide(a, b);
    for (int i = ans.size() - 1; i >= 0; ++i)
    {
        fout << ans[i];
    }
    fout << '\n';

    return 0;
}

int main2()
{
    while (true)
    {
        vector<int> t;
        string inT = "";
        int a, b;

        fin >> inT >> a >> b;

        if (inT == "")
        {
            return 0;
        }

        for (int i = inT.size() - 1; i >= 0; --i)
        {
            t.push_back(inT[i] - '0');
        }

        fout << '(' << inT << '^' << a << "-1)/(" << inT << '^' << b << "-1) ";

        if (a < b || inT == "1")
        {
            fout << "is not an integer with less than 100 digits.\n";
            continue;
        }
        else if (a == b)
        {
            fout << "1\n";
            continue;
        }

        vector<int> first;
        vector<int> second = {1};

        for (int i = 1; i <= b; ++i)
        {
            second = time(second, t);
        }

        first = second;
        for (int i = 1; i <= a - b; ++i)
        {
            first = time(first, t);
        }

        int size0 = first.size(), size1 = second.size();

        if (first[0] == 0)
        {
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (i == size0 - 1 && first[i] == 1)
                {
                    first.erase(first.begin() + i);
                }
                else if (first[i] != 0)
                {
                    --first[i];
                    break;
                }
                else
                {
                    first[i] = 9;
                }
            }
        }
        else
        {
            --first[0];
        }

        if (second[0] == 0)
        {
            for (int i = 0; i <= size1 - 1; ++i)
            {
                if (i == size1 - 1 && second[i] == 1)
                {
                    second.erase(second.begin() + i);
                }
                else if (second[i] != 0)
                {
                    --second[i];
                    break;
                }
                else
                {
                    second[i] = 9;
                }
            }
        }
        else
        {
            --second[0];
        }

        // fout << "\t\t// ";

        // for (int i = first.size() - 1; i >= 0; --i)
        // {
        //     fout << first[i];
        // }

        // fout << "/";

        // for (int i = second.size() - 1; i >= 0; --i)
        // {
        //     fout << second[i];
        // }
        // fout << '\n';

        
    }
}