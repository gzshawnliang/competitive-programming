#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int L = 20001, R = 0;
    vector<int> a(20001, 0);

    while (true)
    {
        int l = 0, h = 0, r = 0; cin >> l >> h >> r;

        l *= 2; r *= 2;

        if (l == r)
        {
            break;
        }

        for (int i = l; i <= r; ++i)
        {
            a[i] = max(a[i], h);
        }

        L = min(L, l);
        R = max(R, r);
    }

    ++R;

    bool first = false;
    int i = L;

    while (i <= R)
    {
        if (first == true) cout << ' ';
        first = true;

        if (a[i] < a[i - 1])
        {
            cout << (i - 1) / 2;
        }
        else
        {
            cout << i / 2;
        }

        cout << ' ' << a[i];

        int now = a[i];
        while (i <= R && a[i] == now)
        {
            ++i;
        }
    }

    cout << '\n';

   	cout.flush();
   	return 0;
}

