#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("Permutation.in");
ofstream fout("Permutation.out");

int main()
{
    int total;
    fin >> total;
    while (total--)
    {
        string str;
        fin >> str;
        sort(str.begin(), str.end());
        bool ok = false;
        do
        {
            fout << str << '\n';
        } while (next_permutation(str.begin(), str.end()) && ok == false);
        fout << '\n';
    }

    return 0;
}