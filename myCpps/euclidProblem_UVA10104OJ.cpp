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


int gdc_plus(int a, int b, int & x, int & y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;

        return a;
    }
    else
    {
        int res = gdc_plus(b, a % b, x, y);
        
        int temp = x;
        x = y;
        y = temp - a / b * y;

        return res;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int a = 0, b = 0, x = 0, y = 0;
        cin >> a >> b;
        if (a + b == 0) break;

        int ans = gdc_plus(a, b, x, y);
        
        cout << x << ' ' << y << ' ' << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
