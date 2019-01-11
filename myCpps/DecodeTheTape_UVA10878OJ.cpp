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


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    string in; getline(cin, in);
    in = "";
    while (in != "___________")
    {
        getline(cin, in);
        int res = 0, size = in.size(), base = 1;
        for (int i = size - 2; i >= 1; --i)
        {
            if (in[i] == 'o')
            {
                res += base;
            }

            if (in[i] == 'o' || in[i] == ' ')
            {
                base *= 2;
            }
        }

        char out = res;
        cout << out;
    }

   	cout.flush();
   	return 0;
}
