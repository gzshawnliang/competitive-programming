#include <bits/stdc++.h>

using namespace std;


const int N = 52;

int turn(char ch)
{
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    else                        return ch - 'A' + 26;
}

bool sovle(int i, string & s)
{
    int k = s.size() - 2;
    for (int j = i + 1; j <= k; ++j, --k)
    {
        if (s[j] != s[k])
        {
            return false;
        }
    }

    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        string s = ""; cin >> s;
        if (s == "") break;

        int size = s.size();
        vector<vector<int>> a(N);
        for (int i = 0; i <= size - 1; ++i)
        {
            a[turn(s[i])].push_back(i);
        }

        int size_a_back = a[turn(s[size - 1])].size(), ans = -1;
        for (int p = 0; p <= size_a_back - 1; ++p)
        {
            int i = a[turn(s[size - 1])][p]; ans = i;

            if (sovle(i, s) == true)
            {
                break;
            }
        }

        string temp = s.substr(0, ans); reverse(temp.begin(), temp.end());

        cout << s + temp << '\n';
    }

   	cout.flush();
   	return 0;
}

