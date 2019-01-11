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


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0;
        cin >> n;
        if (n == 0) break;
        string text; cin >> text;

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

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}
