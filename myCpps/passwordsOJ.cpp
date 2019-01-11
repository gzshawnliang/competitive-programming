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

void solve(vector<string> & dictionary, string nowRule, int nowPos, string ans)
{
    int Dsize = dictionary.size();
    int Rsize = nowRule.size();
    if (nowPos == Rsize)
    {
        cout << ans << '\n';
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
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (true)
    {
        int Dsize = 0;
        cin >> Dsize;
        if (Dsize == 0)
        {
            break;
        }
        cout << "--\n";
        vector<string> dictionary(Dsize);
        for (int i = 0; i <= Dsize - 1; ++i)
        {
            cin >> dictionary[i];
        }
        int Rtotal;
        cin >> Rtotal;
        for (int i = 1; i <= Rtotal; ++i)
        {
            string nowRule;
            cin >> nowRule;
            solve(dictionary, nowRule, 0, "");
        }
    }

    cout.flush();

    return 0;
}