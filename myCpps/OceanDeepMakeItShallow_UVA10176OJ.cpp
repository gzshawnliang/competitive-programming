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


const int m = 131071;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        char temp = '-';
        cin >> temp;
        if (temp == '-') break;

        string in = "";
        in.push_back(temp);
        while (temp != '#')
        {
            cin >> temp;
            in.push_back(temp);
        }
        
        long long size0 = in.size() - 1, ans = 0, base = 1;
        for (int i = size0 - 1; i >= 0; --i)
        {
            ans += (in[i] - '0') * base;
            ans %= m;

            base *= 2;
            base %= m;
        }

        if (ans % m == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

   	cout.flush();
   	return 0;
}
