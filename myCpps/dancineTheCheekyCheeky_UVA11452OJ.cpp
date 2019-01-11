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

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        string a, loop; cin >> a;
        int size = a.size(), miss, start;

        if (size % 3 == 0)
        {
            start = size / 3;
        }
        else
        {
            start = size / 3 + 1;
        }
        
        for (int s = start; s <= size / 2; ++s)
        {
            string temp1 = a.substr(0, s), temp2 = a.substr(s, s);
            if (temp1 == temp2)
            {
                miss = size - s * 2;
                loop = temp1;
                break;
            }
        }

        int _count = 8, sizeL = loop.size();
        for (int i = miss; _count > 0; ++i)
        {
            i %= sizeL;

            cout << loop[i];
            --_count;
        }

        cout << "...\n";
    }

   	cout.flush();
   	return 0;
}
