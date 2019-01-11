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


int gdc_plus(int a, int b, int & p, int & q)
{
    if (b == 0)
    {
        p = 1;
        q = 0;

        return a;
    }
    else
    {
        int res = gdc_plus(b, a % b, p, q);
        
        int temp = p;
        p = q;
        q = temp - a / b * q;

        return res;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int x, k; cin >> x >> k;

        int a = x / k, b = (int)ceil(double(x) / double(k)), p = 0, q = 0;
        int res = gdc_plus(a, b, p, q);

        cout << p * x / res << ' ' << q * x / res << '\n';
    }

   	cout.flush();
   	return 0;
}
