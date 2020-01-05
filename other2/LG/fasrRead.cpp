#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int read()
{
    bool first = true;
    int ans = 0, _flag = 1;

    while (true)
    {
        char c = getchar();

        if (c == ' ' || c == '\n')
        {
            break;
        }
        else if (first == true && c == '-')
        {
            _flag = -1;
        }
        else
        {
            ans = ans * 10 + (c - '0') * _flag;
        }

        if (first == true)
        {
            first = false;
        }
    }

    return ans;
}

int main()
{
    int n = read();
    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        a[i] = read();
    }

    for (int i = 0; i <= n - 1; ++i)
    {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}