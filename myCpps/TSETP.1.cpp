#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

// ifstream cin("TSETP.in");
// ofstream cout("TSETP.out");
void solve1()
{
    double temp1, temp2;
    cin >> temp1 >> temp2;
    int start = round(temp1 * 100), end = round(temp2 * 100);
    cout << fixed << setprecision(2);
    for (int nowNum = start; nowNum <= end; nowNum += 1)
    {
        for (int c = nowNum / 3; c <= nowNum; ++c)
        {
            for (int b = (nowNum - c) / 2 + 1; b <= c; ++b)
            {
                int a = nowNum - b - c;
                if (nowNum * 10000 == a * b * c)
                {
                    cout << nowNum / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
                    //c = nowNum + 1;
                    //break;
                }
            }
        }
    }
}

double r(double a)
{
    return round(a * 100) / 100;
}

void solve2()
{
    double start, end;
    cin >> start >> end;
    cout << fixed << setprecision(2);
    for (double nowNum = start; nowNum <= end; nowNum += 0.01)
    {
        for (double a = 0.01; a <= nowNum / 3; a += 0.01)
        {
            for (double b = a; b <= nowNum; b += 0.01)
            {
                double c = (nowNum / a) / b;
                double a2 = r(a);
                double b2 = r(b);
                double c2 = r(c);
                double nowNum2 = r(nowNum);
                if (a2 + b2 + c2 == a2 * b2 * c2 && a2 * b2 * c2 == nowNum2 && b2 <= c2)
                {
                    cout << nowNum2 << " = " << a2 << " + " << b2 << " + " << c2 << " = " << a2 << " * " << b2 << " * " << c2 << "\n";
                }
                if (a2 * b2 * c2 == nowNum && a2 + b2 + c2 == nowNum)
                {
                    if (nowNum2 == 5.85)
                    {
                        cout << "BAD:" << nowNum2 << " = " << a2 << " + " << b2 << " + " << c2 << " = " << a2 << " * " << b2 << " * " << c2 << "\n";
                    }
                }
            }
        }
    }
}

void solve3()
{
    double temp1, temp2;
    cin >> temp1 >> temp2;
    int start = round(temp1 * 100), end = round(temp2 * 100);
    cout << fixed << setprecision(2);
    for (int nowNum = start; nowNum <= end; ++nowNum)
    {
        for (int a = 1; a <= nowNum / 3; ++a)
        {
            for (int b = a; b <= nowNum / 2; ++b)
            {
                int c = nowNum * 10000 / (a * b);
                if ((a + b + c) * 10000 == a * b * c && a + b + c == nowNum && b <= c)
                {
                    cout << nowNum / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
                }
            }
        }
    }
}

void solve4()
{
    while (true)
    {
        double temp1 = 0, temp2 = 0;
        cin >> temp1 >> temp2;
        if (cin.eof() || temp1 == 0 || temp2 == 0)
        {
            break;
        }

        int start = round(temp1 * 100), end = round(temp2 * 100);
        cout << fixed << setprecision(2);
        for (int nowNum = start; nowNum <= end; ++nowNum)
        {
            int nowNumBig = nowNum * 1e4;
            for (int a = 1; a * a * a <= nowNumBig; ++a)
            {
                for (int b = a; a * b * b <= nowNumBig; ++b)
                {
                    int c = nowNumBig / (a * b);
                    if (b > c)
                    {
                        break;
                    }
                    if ((a + b + c) * 1e4 == a * b * c && a + b + c == nowNum)
                    {
                        cout << nowNum / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
                    }
                }
            }
        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("TSETP.in", "r", stdin);
    freopen("TSETP.out3", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve4();

    cout.flush();

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}