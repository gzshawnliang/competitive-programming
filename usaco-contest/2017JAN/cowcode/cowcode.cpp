#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("cowcode.in");
ofstream fout("cowcode.out");

int main()
{
    long long n;
    string s;

    fin >> s >> n;

    int size = s.size();

    while (n > size)
    {
        long long temp = size;
        while (n > temp)
        {
            temp *= 2;
        }
        temp /= 2;

        n -= (temp + 1);
        if (n == 0)
        {
            n = temp;
        }
    }

    fout << s[n - 1] << '\n';

    return 0;
}