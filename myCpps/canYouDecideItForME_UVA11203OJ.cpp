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


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        string text; cin >> text;
        
        bool showM = false, showE = false, flag = true;
        int size = text.size(), x = 0, y = 0, z = 0, temp = 0;

        for (int i = 0; i <= size - 1 && flag == true; ++i)
        {
            if (text[i] == '?')
            {
                ++temp;
            }
            else if (text[i] == 'M')
            {
                if (showE == true)
                {
                    flag = false;
                }

                showM = true;
                x = temp;

                temp = 0;
            }
            else if (text[i] == 'E')
            {
                showE = true;
                y = temp;

                temp = 0;
            }
            else
            {
                flag = false;
            }
        }
        z = temp;

        if (showM == false || showE == false || y < 1 || x < 1 || z - (y - 1) - x != 1)
        {
            flag = false;
        }

        if (flag == true)
        {
            cout << "theorem\n";
        }
        else
        {
            cout << "no-theorem\n";
        }
    }

   	cout.flush();
   	return 0;
}

