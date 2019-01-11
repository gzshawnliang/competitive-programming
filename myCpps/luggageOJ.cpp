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
    int totalTest;
    cin >> totalTest;
    string useless;
    getline(cin, useless);
    for (int c = 1; c <= totalTest; ++c)
    {
        string in;
        getline(cin, in);
        int sizeIN = in.size();
        int totalW = 0;

        vector<int> a;
        string temp;
        for (int i = 0; i <= sizeIN - 1; ++i)
        {
            if (in[i] == ' ')
            {
                a.push_back(stoi(temp));
                totalW += a.back();
                temp = "";
            }
            else
            {
                temp += in[i];
            }
        }

        a.push_back(stoi(temp));
        totalW += a.back();

        if (totalW % 2 != 0)
        {
            cout << "NO\n";
            continue;
        }

        totalW /= 2;

        set<int> store;
        store.insert(0);
        int size0 = a.size();

        for (int i = 0; i <= size0 - 1; ++i)
        {
            set<int> temp = store;
            int size1 = store.size();
            for (auto it = store.begin(); it != store.end(); ++it)
            {
                temp.insert(a[i] + *it);
            }

            store = temp;
        }

        bool ans = binary_search(store.begin(), store.end(), totalW);
        
        if (ans == true)
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
