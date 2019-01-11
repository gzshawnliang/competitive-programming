#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define ll long long


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    map<string, bool> dictionary;
    string in;
    while (in != "#")
    {
        cin >> in;
        dictionary[in] = true;
    }

    getline(cin, in);

    string text = "", ans = "";
    getline(cin, text);

    int size = text.size(), maxCount = 0;

    for (int i = 0; i <= size - 1; ++i)
    {
        if (text[i] == ' ')
        {
            text[i] = '@';
        }
    }

    for (int k = 0; k <= 26; ++k)
    {
        for (int i = 0; i <= size - 1; ++i)
        {
            ++text[i];

            if (text[i] == '[')
            {
                text[i] -= 27;
            }
        }

        int count = 0;
        string temp = "";
        for (int i = 0; i <= size - 1; ++i)
        {
            if (text[i] == '@')
            {
                if (dictionary[temp] == true)
                {
                    ++count;
                }

                temp = "";
            }
            else
            {
                temp += text[i];
            }
        }

        if (maxCount < count)
        {
            maxCount = count;
            ans = text;
        }
    }

    for (int i = 0; i <= size - 1; ++i)
    {
        if (ans[i] == '@')
        {
            ans[i] = ' ';
        }
    }

    string fans, temp;
    stringstream scan(ans);
    while (scan >> temp)
    {
        if (fans.size() + temp.size() > 60)
        {
            cout << fans << endl;
            fans = temp;
        }
        else
        {
            if (fans.size() != 0)
            {
                fans += ' ';
            }
            
            fans += temp;
        }
    }
    cout << fans << '\n';

   	cout.flush();
   	return 0;
}
