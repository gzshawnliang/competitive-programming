/***********************************************************
 * @名称:		
 * @作者:      shawn 
 * @创建时间:  2018-09-09 20:20:00 
 * @修改人:    shawn 
 * @修改时间:  2018-09-09 20:20:00 
 * @备注:		
***********************************************************/
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
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void solve(long long a, long long b, long long c)
{
    long long derta = b * b - 4 * a * c;
    if (derta < 0)
    {
        cout << "Vaid.\n";
    }
    else if (derta == 0)
    {
        cout << "x1 = x2 = ";

        long long _gcd = gcd(abs(b), abs(2 * a));
        if ((a > 0 && b > 0) || (a < 0 && b < 0))
        {
            cout << '-';
        }

        cout << abs(b) / _gcd;
        if (abs(2 * a) / _gcd != 1)
        {
            cout << '/' << abs(2 * a) / _gcd; 
        }

        cout << '\n';
    }
    else
    {
        long long _max = 0, c = 1;
        while (c * c <= derta)
        {
            if (derta % (c * c) == 0)
            {
                _max = c;
            }

            ++c;
        }

        if (derta == _max * _max)
        {
            cout << "x1 = ";

            long long _gcd = gcd(abs(-1 * b + _max), abs(2 * a));
            if ((a > 0 && -1 * b + _max < 0) || (a < 0 && -1 * b + _max > 0))
            {
                cout << '-';
            }

            cout << abs(-1 * b + _max) / _gcd;
            if (abs(2 * a) / _gcd != 1)
            {
                cout << '/' << abs(2 * a) / _gcd; 
            }

            cout << "   x2 = ";

            _gcd = gcd(abs(-1 * b - _max), abs(2 * a));
            if ((a > 0 && -1 * b + _max < 0) || (a < 0 && -1 * b + _max > 0))
            {
                cout << '-';
            }

            cout << abs(-1 * b - _max) / _gcd;
            if (abs(2 * a) / _gcd != 1)
            {
                cout << '/' << abs(2 * a) / _gcd; 
            }

            cout << '\n';
        }
        else
        {
            derta /= _max * _max;

            cout << "x1 = ";

            cout << '(' << -1 * b << " + ";
            if (_max > 1) cout << _max << " * "; 
            cout << "sqrt(" << derta << ")) / " << 2 * a;

            cout << "   x2 = ";

            cout << '(' << -1 * b << " - ";
            if (_max > 1) cout << _max << " * "; 
            cout << "sqrt(" << derta << ")) / " << 2 * a << '\n';
        }
    }
}

int main()
{
    while (true)
    {
        long long a;
        long long b;
        long long c;
        cin >> a >> b >> c;

        if (a == 0)
        {
            break;
        }

        solve(a, b, c);

        cout << "\n\n";
    }
    
    return 0;
}