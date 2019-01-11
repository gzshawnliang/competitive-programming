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

ifstream fin("TSETP.in");
ofstream fout("TSETP.out");
void solve1()
{
    double temp1, temp2;
    fin >> temp1 >> temp2;
    int start = round(temp1 * 100), end = round(temp2 * 100);
    fout << fixed << setprecision(2);
    for (int nowNum = start; nowNum <= end; nowNum += 1)
    {
        for (int c = nowNum / 3; c <= nowNum; ++c)
        {
            for (int b = (nowNum - c) / 2 + 1; b <= c; ++b)
            {
                int a = nowNum - b - c;
                if (nowNum * 10000 == a * b * c)
                {
                    fout << nowNum / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
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
    fin >> start >> end;
    fout << fixed << setprecision(2);
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
                    fout << nowNum2 << " = " << a2 << " + " << b2 << " + " << c2 << " = " << a2 << " * " << b2 << " * " << c2 << "\n";
                }
                if (a2 * b2 * c2 == nowNum && a2 + b2 + c2 == nowNum )
                {
                    if (nowNum2 == 5.85)
                    {
                        fout << "BAD:" << nowNum2 << " = " << a2 << " + " << b2 << " + " << c2 << " = " << a2 << " * " << b2 << " * " << c2 << "\n";
                    }
                }
            }
        }
    }
}

void solve3()
{
    double temp1, temp2;
    fin >> temp1 >> temp2;
    int start = round(temp1 * 100), end = round(temp2 * 100);
    fout << fixed << setprecision(2);
    for (int nowNum = start; nowNum <= end; ++nowNum)
    {
        for (int a = 1; a <= nowNum / 3; ++a)
        {
            for (int b = a; b <= nowNum / 2; ++b)
            {
                int c = nowNum * 10000 / (a * b);
                if ((a + b + c) * 10000 == a * b * c && a + b + c == nowNum && b <= c)
                {
                    fout << nowNum / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
                }
            }
        }
    }
}

void solve4()
{
    double temp1, temp2;
    fin >> temp1 >> temp2;
    int start = round(temp1 * 100), end = round(temp2 * 100);
    fout << fixed << setprecision(2);
    for (int nowNum = start; nowNum <= end; ++nowNum)
    {
        int nowNumBig=nowNum*1e4;
        for (int a = 1; a * a * a <= nowNumBig; ++a)
        {
            for (int b = a; a * b * b <= nowNumBig; ++b)
            {
                int c = nowNumBig / (a * b);
                if(b > c)
                {
                    break;
                }
                if ((a + b + c) * 1e4 == a * b * c && a + b + c == nowNum)
                {
                    fout << nowNum / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
                }
            }
        }
    }
}

void solve5()
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
                //fout << (a + b + c) / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
            }
        }
    }

    sort(out.begin(), out.end());

    while (true)
    {
        double temp1, temp2;
        fin >> temp1 >> temp2;

        if (fin.eof() == true)
        {
            break;
        }

        int start = round(temp1 * 100), end = round(temp2 * 100);
        fout << fixed << setprecision(2);

        int size = out.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            int a = out[i].a;
            int b = out[i].b;
            int c = out[i].c;

            if (a + b + c >= start && a + b + c <= end)
            {
                fout << (a + b + c) / 100.0 << " = " << a / 100.0 << " + " << b / 100.0 << " + " << c / 100.0 << " = " << a / 100.0 << " * " << b / 100.0 << " * " << c / 100.0 << "\n";
            }
        }
    }
    
}

int main()
{   
    solve5();
    return 0;
}