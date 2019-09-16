#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(string & s)
{
    int sizeS = s.size();
    for (int i = 0, j = sizeS - 1; i <= j; ++i, --j)
    {
        if (s[i] != s[j]) return false;
    }

    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int tcc; cin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        string s; cin >> s;

        string target = s; reverse(target.begin(), target.end());
        s += s;
        int sizeS = s.size(), sizeT = target.size();

        int _i = 0, _j = -1;
        vector<int> next(sizeT + 1, 0); next[0] = -1;
        while (_i <= sizeT - 1)
        {
            while (_j >= 0 && target[_i] != target[_j])
            {
                _j = next[_j];
            }

            ++_i; ++_j;
            next[_i] = _j;
        }

        int i = 0, j = 0, posC = 0;
        vector<int> isPos(sizeS, 0);
        while (i <= sizeS - 1)
        {
            while (j >= 0 && s[i] != target[j])
            {
                j = next[j];
            }
            
            ++i; ++j;
            if (j == sizeT)
            {
                ++posC;
                isPos[i - sizeT] = 1;
                j = next[j];
            }
        }

        if (posC == 0)
        {
            cout << "simple\n";
        }
        else if (posC == 2 && isPos[0] == true && isPos[sizeT] == true)
        {
            cout << "palindrome\n";
        }
        else
        {
            cout << "alindrome\n";
        }
    }

   	cout.flush();
   	return 0;
}

