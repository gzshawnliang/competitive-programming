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

ifstream fin("helpingFillBates.in");
ofstream fout("helpingFillBates.out");

struct store
{
    int start;
    int end;
};

int main()
{
    string a;
    fin >> a;

    int size0 = a.size(),count0 = 0;
    fin >> count0;
    for (int c = 1; c <= count0; ++c)
    {
        string in;
        fin >> in;

        bool ok = true;
        int size1 = in.size(), i1 = 0, last = 0, lastPos = -1;
        for (int i0 = 0; i0 <= size1 - 1; ++i0)
        {
            string temp = "";
            temp.push_back(in[i0]);

            int result = a.find(temp, last);

            if (i0 == size1 - 1)
            {
                if (result != string::npos)
                {
                    lastPos = result;
                }
            }

            if (last == 0)
            {
                last = result + 1;
            }
            else if (result == string::npos)
            {
                ok = false;
                break;
            }
            else if (result < last)
            {
                ok = false;
                break;
            }
            else
            {
                last = result + 1;
            }
        }

        if (ok == true)
        {
            fout << "Matched " << a.find(in[0]) << ' ' << lastPos << '\n';
        }
        else
        {
            fout << "Not matched\n";
        }
    }

    return 0;
}