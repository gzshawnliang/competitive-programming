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

ifstream fin("passwordSearch_UVA902.in");
ofstream fout("passwordSearch_UVA902.out");

int main()
{
    while (true)
    {
        int n = 0;
        fin >> n;
        if (n == 0) break;
        string text; fin >> text;

        int size = text.size(), ans_max = 0;
        string ans = "hi";
        map<string, int> file;

        for (int i = 0; i + n - 1 <= size - 1; ++i)
        {
            string temp = "";
            for (int j = i; j <= i + n - 1; ++j)
            {
                temp += text[j];
            }

            ++file[temp];
            if (ans_max < file[temp])
            {
                ans_max = file[temp];
                ans = temp;
            }
        }

        fout << ans << '\n';
    }

    return 0;
}