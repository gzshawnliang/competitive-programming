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

using namespace std;

ifstream fin("immediateDecodability_UVA644.in");
ofstream fout("immediateDecodability_UVA644.out");

int main()
{
    int T = 1;
    vector<string> a;
    while (true)
    {
        string in = "-";
        fin >> in;

        if (in == "-")
        {
            break;
        }
        else if (in == "9")
        {
            sort(a.begin(), a.end());

            bool flag = true;
            int size0 = a.size();
            map<string, bool> _map;

            for (int i = 0; i <= size0 - 1 && flag == true; ++i)
            {
                int size1 = a[i].size();
                string temp = "";

                for (int j = 0; j <= size1 - 1 && flag == true; ++j)
                {
                    temp += a[i][j];

                    if (_map[temp] == true)
                    {
                        flag = false;
                    }
                }

                _map[a[i]] = true;
            }

            if (flag == true)
            {
                fout << "Set " << T << " is immediately decodable\n";
            }
            else
            {
                fout << "Set " << T << " is not immediately decodable\n";
            }

            ++T;
            a.clear();
        }
        else
        {
            a.push_back(in);
        }
    }

    return 0;
}