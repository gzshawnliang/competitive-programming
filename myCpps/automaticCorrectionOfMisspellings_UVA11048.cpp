#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream fin("automaticCorrectionOfMisspellings_UVA11048.in");
ofstream fout("automaticCorrectionOfMisspellings_UVA11048.out");

bool check(string & a, string & b)
{
    int sizeA = a.size(), sizeB = b.size();
    if (abs(sizeA - sizeB) == 1)
    {
        string tempA, tempB;
        if (sizeA > sizeB)
        {
            tempA = b;
            tempB = a;
        }
        else
        {
            tempA = a;
            tempB = b;
        }
        
        int size = max(sizeA, sizeB);
        for (int i = 0; i <= size - 1; ++i)
        {
            string temp = tempB;
            temp.erase(temp.begin() + i);

            if (tempA == temp)
            {
                return true;
            }
        }

        return false;
    }
    else if (sizeA == sizeB)
    {
        bool flag = false;
        for (int i = 0; i <= sizeA - 1; ++i)
        {
            if (a[i] != b[i])
            {
                if (flag == true)
                {
                    return false;
                }

                if (i != sizeA - 1)
                {
                    if (a[i] == b[i + 1] && a[i + 1] == b[i])
                    {
                        ++i;
                    }
                }

                flag = true;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n; fin >> n;
    map<string, bool> dictionary_map;
    vector<string> dictionary_vec(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> dictionary_vec[i];
        dictionary_map[dictionary_vec[i]] = true;
    }

    int q; fin >> q;
    for (int c = 1; c <= q; ++c)
    {
        string s; fin >> s;
        fout << s << ' ';

        if (dictionary_map[s] == true)
        {
            fout << "is correct\n";
            continue;
        }

        bool flag = true;
        for (int i = 0; i <= n - 1 && flag == true; ++i)
        {
            string now = dictionary_vec[i];

            if (check(s, now) == true)
            {
                fout << "is a misspelling of " << now << '\n';
                flag = false;
            }
        }

        if (flag == true)
        {
            fout << "is unknown\n";
        }
    }

    return 0;
}