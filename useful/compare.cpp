#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

ifstream fin;

int main()
{
    vector<string> a;
    fin.open("compare.in1");
    while (fin.eof() == false)
    {
        string in;
        getline(fin, in);
        a.push_back(in);
    }

    fin.close();

    fin.open("compare.in2");
    int i = 0;
    while (fin.eof() == false)
    {
        string in;
        getline(fin, in);
        if (a[i] != in)
        {
            cout << red << "line " << i + 1 << ":\n";
            cout << yellow << a[i] << blue << " <--> " << yellow << in << '\n';
        }
        else if (true)
        {
            cout << green << "line " << i + 1 << ":\n";
            cout << white << a[i] << green << " ==== " << white << in << '\n';
        }

        ++i;
    }

    fin.close();

    string sjakhfksajfhjsakhf; cin >> sjakhfksajfhjsakhf;
    return 0;
}