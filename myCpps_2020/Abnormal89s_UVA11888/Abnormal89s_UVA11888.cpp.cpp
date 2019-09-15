#include <bits/stdc++.h>

using namespace std;

ifstream fin("Abnormal89s_UVA11888.cpp.in");
ofstream fout("Abnormal89s_UVA11888.cpp.out");

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
    int tcc; fin >> tcc;
    for (int t = 1; t <= tcc; ++t)
    {
        string s; fin >> s;
        int sizeS = s.size();

        if (sizeS == 1)
        {
            fout << "palindrome\n";
            continue;
        }

        int l = 1, r = sizeS;
        while (l <= r)
        {
            int m = (l + r) / 2;

            string target = s.substr(0, m); reverse(target.begin(), target.end());
            string tempS = s.substr(m - 1, sizeS - m + 1);
            int sizeTempS = tempS.size();

            int _i = 0, _j = -1;
            vector<int> next(m + 1, 0); next[0] = -1;
            while (_i <= m - 1)
            {
                while (_j >= 0 && target[_i] != target[_j])
                {
                    _j = next[_j];
                }

                ++_i; ++_j;
                next[_i] = _j;
            }


            bool flag = false;
            int i = 0, j = 0;
            while (i <= sizeTempS - 1)
            {
                while (j >= 0 && tempS[i] != target[j])
                {
                    j = next[j];
                }
                
                ++i; ++j;
                if (j == m)
                {
                    flag = true;
                    j = next[j];

                    break;
                }
            }

            if (flag == true)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        string nowS = s.substr(0, r), rNowS = nowS;
        reverse(rNowS.begin(), rNowS.end());
        
        if (isPalindrome(s) == true)
        {
            if (isPalindrome(nowS) == true)
            {
                
                fout << "alindrome\n";
            }
            else
            {
                fout << "palindrome\n";
            }
        }
        else
        {
            string leftS;

            if (sizeS >= r + 1)
            {
                if (s[r] == s[r + 1])
                {
                    leftS = s.substr(2 * r - 1, sizeS - 2 * r);
                }
                else
                {
                    leftS = s.substr(2 * r - 1, sizeS - 2 * r + 1);
                }
            }
            else
            {
                leftS = s.substr(2 * r - 1, sizeS - 2 * r + 1);
            }

            if (isPalindrome(leftS) == true)
            {
                fout << "alindrome\n";
            }
            else
            {
                fout << "simple\n";
            }
        }
    }

    return 0;
}
