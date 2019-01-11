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

ifstream fin("fibonacci.in");
ofstream fout("fibonacci.out");

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

int main()
{
    // vector<int> a = {0,1};
    // vector<int> b = {0,9,9};
    // vector<int> ans = add(a, b);

    // int size = ans.size();
    // for (int i = size - 1; i >= 0; --i)
    // {
    //     fout << ans[i];
    // }
    // fout << '\n';

    vector< vector<int> > fibonacci;
    vector<int> temp1 = {0};
    vector<int> temp2 = {1};
    fibonacci.push_back(temp1);
    fibonacci.push_back(temp2);

    for (int i = 2; i <= 5001; ++i)
    {
        vector<int> temp = add(fibonacci[i - 1], fibonacci[i - 2]);
        fibonacci.push_back(temp);
    }

    while (true)
    {
        int f = -1;
        fin >> f;
        if (f == -1)
        {
            break;
        }
        fout << "The Fibonacci number for " << f << " is ";
        vector<int> temp = fibonacci[f];
        int size = temp.size();
        for (int i = size - 1; i >= 0; --i)
        {
            fout << temp[i];
        }
        fout << '\n';
    }

    return 0;
}