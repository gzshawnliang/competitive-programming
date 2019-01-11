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

ifstream fin("MBR.in");
ofstream fout("MBR.out");

int main()
{
    int k, a, b;
    while (fin >> k >> a >> b)
    {
        int nowNum = a * b, count = 1;
        while (nowNum != a)
        {
            nowNum = nowNum % k * b + nowNum / k;
            ++count;
        }

        fout << count << '\n';
    }

    return 0;
}