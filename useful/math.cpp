#include <bits/stdc++.h>

using namespace std;

//ifstream fin("math.in");
//ofstream fout("math.out");

int calBracketPos_next(int pos, string & s)
{
    int n = s.size();

    ++pos;
    while (pos <= n - 1 && s[pos] == '#')
    {
        ++pos;
    }

    return pos;
}

void calBracketPos(string s, vector<int> & bracketPos)
{
    int n = s.size();

    for (int i = 0; i <= n - 1; ++i)
    {
        if (s[i] != '(' && s[i] != ')')
        {
            s[i] = '#';
        }

        bracketPos[i] = -1;
    }

    while (true)
    {
        bool left = false;
        for (int i = 0; i <= n - 2; ++i)
        {
            int nextPos = calBracketPos_next(i, s);

            if (bracketPos[nextPos] >= 0)
            {
                continue;
            }

            if (s[i] == '(' && s[nextPos] == ')')
            {
                s[i] = '#'; s[nextPos] = '#';

                bracketPos[i] = nextPos;
                bracketPos[nextPos] = i;

                left = true;
            }
        }

        if (left == false)
        {
            break;
        }
    }
}

string join(string a, string b)
{
    int sizeA = a.size(), sizeB = b.size(); 
    string ans = "";

    for (int i = 0; i <= sizeA - 1; ++i)
    {
        ans += a[i];
    }

    for (int i = 0; i <= sizeB - 1; ++i)
    {
        ans += b[i];
    }

    return ans;
}

string sub(int i, int j, string & s)
{
    return s.substr(i, j - i + 1);
}

string timeMonomial(string a, string b) // a +&, b +&
{
    int sizeA = a.size(), sizeB = b.size(); 

    string aK = "", bK = "", ans = "";

    for (int i = 0; i <= sizeA - 1; ++i)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            aK += a[i];
        }
        else
        {
            ans += a[i];
        }
    }
    if (aK == "" || aK == "+")
    {
        aK = "1";
    }
    else if (aK == "-")
    {
        aK = "-1";
    }

    for (int i = 0; i <= sizeB - 1; ++i)
    {
        if (b[i] >= '0' && b[i] <= '9')
        {
            bK += b[i];
        }
        else
        {
            ans += b[i];
        }
    }
    if (bK == "" || bK == "+")
    {
        bK = "1";
    }
    else if (bK == "-")
    {
        bK = "-1";
    }

    sort(ans.begin(), ans.end());

    return join(to_string(stoi(aK) * stoi(bK)), ans);
}

string timePolynomial(string a, string b) // a +&, b +&
{
    
}

string simplify(string s)
{
    char last = 'n';

    if (s[0] != '-')
    {
        s.insert(s.begin(), '+');
        last = '+';
    }
    else
    {
        last = '-';
    }

    int n = s.size(), _count;
    map<string, int> m;

    string temp1 = "";
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '+' || s[i] == '-' || i == n)
        {
            string temp2 = "", temp3 = "";

            int sizeT1 = temp1.size();
            for (int j = 0; j <= sizeT1 - 1; ++j)
            {
                if (temp1[j] >= '0' && temp1[j] <= '9')
                {
                    temp2 += temp1[j];
                }
                else
                {
                    temp3 += temp1[j];
                }
            }

            int sizeT2 = temp2.size();
            if (sizeT1 == sizeT2)
            {
                if (last == '+')
                {
                    _count += stoi(temp2);
                }
                else
                {
                    _count -= stoi(temp2);
                }
            }
            else
            {
                if (sizeT2 == 0) 
                {
                    temp2 = '1';
                }

                if (last == '+')
                {
                    m[temp3] += stoi(temp2);
                }
                else
                {
                    m[temp3] -= stoi(temp2);
                }
            }

            temp1 = "";
            if (i != n)
            {
                last = s[i];
            }
        }
        else
        {
            temp1 += s[i];
        }
    }

    string ans = to_string(_count);
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (it->second > 0)
        {
            ans += '+';
        }

        if (it->second == 0)
        {
            continue; 
        }
        else if (abs(it->second) != 1)
        {
            ans = join(ans, to_string(it->second));
        }
        else if (it->second == -1)
        {
            ans += '-';
        }

        ans = join(ans, it->first);
    }

    return ans;
}

int main()
{
    while (true)
    {
        // string s;
    
        // //cin >> s;
        // s = "(1 + 2)*(5 + 6)";

        // int n = s.size();

        // for (int i = 0; i <= n - 1; ++i)
        // {
        //     if (s[i] == ' ')
        //     {
        //         s.erase(s.begin() + i);

        //         --i; --n;
        //     }
        // }

        cout << timeMonomial("5ac", "c") << '\n';

        break;
    }
    
    return 0;
}
