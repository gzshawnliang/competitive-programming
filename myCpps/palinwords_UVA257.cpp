#include <bits/stdc++.h>

using namespace std;

ifstream fin("palinwords_UVA257.in");
ofstream fout("palinwords_UVA257.out");

bool isPalindrome(string & s)
{
    int n = s.size();
    for (int l = 0, r = n - 1; l <= r; ++l, --r)
    {
        if (s[l] != s[r]) return false;
    }
    return true;
}

bool isSame(string & a, string & b)
{
    int sizeA = a.size(), sizeB = b.size();
    if (sizeA < sizeB)
    {
        for (int i = 0; i + sizeA - 1 <= sizeB - 1; ++i)
        {
            if (a == b.substr(i, sizeA)) return true;
        }
        return false;
    }
    else
    {
        for (int i = 0; i + sizeB - 1 <= sizeA - 1; ++i)
        {
            if (b == a.substr(i, sizeB)) return true;
        }
        return false;
    }
}

int main()
{
    while (true)
    {
        string s = ""; fin >> s;
        if (s == "") break;

        int n = s.size();
        set<string> p_s;
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int len = 3; i + len - 1 <= n - 1 && len <= 4; ++len)
            {
                string now = s.substr(i, len);
                if (isPalindrome(now) == true) p_s.insert(now);
            }
        }

        vector<string> p;
        for (auto it = p_s.begin(); it != p_s.end(); ++it)
        {
            p.push_back(*it);
        }

        bool isPalinword = false;
        int size = p.size();
        for (int i = 0; i <= size - 1 && isPalinword == false; ++i)
        {
            for (int j = i + 1; j <= size -  1 && isPalinword == false; ++j)
            {
                if (isSame(p[i], p[j]) == false)
                {
                    isPalinword = true;
                }
            }
        }

        if (isPalinword == true)
        {
            fout << s << '\n';
        }
    }

    return 0;
}
