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

ifstream fin("passwords.in");
ofstream fout("passwords.out");

void solve(vector<string> dictionary, string nowRule, int nowPos, string ans)
{
    int Dsize = dictionary.size();
    int Rsize = nowRule.size();
    if (nowPos == Rsize)
    {
        fout << ans << '\n';
    }
    else if (nowRule[nowPos] == '0')
    {
        for (int i = 0; i <= 9; ++i)
        {
            char temp = i + '0';
            solve(dictionary, nowRule, nowPos + 1, ans + temp);
        }
    }
    else
    {
        for (int i = 0; i <= Dsize - 1; ++i)
        {
            solve(dictionary, nowRule, nowPos + 1, ans + dictionary[i]);
        }
    }
}

int main()
{
    while (true)
    {
        
        int Dsize = 0;
        fin >> Dsize;
        if (Dsize == 0)
        {
            return 0;
        }
        fout << "--\n";
        vector<string> dictionary(Dsize);
        for (int i = 0; i <= Dsize - 1; ++i)
        {
            fin >> dictionary[i];
        }
        int Rtotal;
        fin >> Rtotal;
        for (int i = 1; i <= Rtotal; ++i)
        {
            string nowRule;
            fin >> nowRule;
            solve(dictionary, nowRule, 0, "");
        }
    }
}