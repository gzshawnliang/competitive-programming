#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{     
    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);           
    
    int test = 0;
    while (true)
    {
        ++test;
        int b = 0, s = 0, minAge = INT_MAX;
        cin >> b >> s;

        if (b == 0)
        {
            break;
        }

        for (int i = 0; i <= b - 1; ++i)
        {
            int in; cin >> in;
            minAge = min(minAge, in);
        }

        for (int i = 0; i <= s - 1; ++i)
        {
            int useless; cin >> useless;
        }

        if (b <= s)
        {
            cout << "Case " << test << ": 0\n";
            continue;
        }

        cout << "Case " << test << ": " << b - s << ' ' << minAge << '\n';
    }
    cout.flush();
    return 0;
}