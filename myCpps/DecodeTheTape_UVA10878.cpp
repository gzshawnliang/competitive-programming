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
#include <stack>

using namespace std;

ifstream fin("DecodeTheTape_UVA10878.in");
ofstream fout("DecodeTheTape_UVA10878.out");

int main()
{
    string in; getline(fin, in);
    in = "";
    while (in != "___________")
    {
        getline(fin, in);
        int res = 0, size = in.size(), base = 1;
        for (int i = size - 2; i >= 1; --i)
        {
            if (in[i] == 'o')
            {
                res += base;
            }

            if (in[i] == 'o' || in[i] == ' ')
            {
                base *= 2;
            }
        }

        char out = res;
        fout << out;
    }

    return 0;
}