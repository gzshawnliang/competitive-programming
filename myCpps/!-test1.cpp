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

// hello

int main()
{
    //test cpp
    ifstream fin("!-test1.in");
    ofstream fout("!-test1.out");

    int finLOL;
    fin >> finLOL;
    fout << finLOL << '\n';

    if (finLOL == 0)
    {
        fout << "whee~\n";
        return 0;
    }

    return 0;
}