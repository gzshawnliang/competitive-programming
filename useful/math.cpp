#include <bits/stdc++.h>

using namespace std;

//ifstream fin("math.in");
//ofstream fout("math.out");

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

string simplify(string s)
{
    int n = s.size();
    for (int i = 0; i <= n - 1; ++i)
    {
        if (s[i] == ' ')
        {
            s.erase(s.begin() + i);
            --i; --n;
        }
    }

    char last = 'n';

    if (s[0] != '-')
    {
        s.insert(s.begin(), '+');
        last = '+';
        ++n;
    }
    else
    {
        last = '-';
    }

    int _count = 0;
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

string timeMonomial(string a, string b) // a +&, b +&
{
    int sizeA = a.size(), sizeB = b.size(); 

    string aK = "", bK = "", ans = "";

    for (int i = 0; i <= sizeA - 1; ++i)
    {
        if ((a[i] >= '0' && a[i] <= '9') || a[i] == '+' || a[i] == '-')
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
        if ((b[i] >= '0' && b[i] <= '9') || b[i] == '+' || b[i] == '-')
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
    a = simplify(a);
    b = simplify(b);

    char last;

    int nA = a.size();
    string tempA = "";
    vector<string> _a;

    if (a[0] != '-')
    {
        last = '+';
    }
    else
    {
        last = '-';
    }

    for (int i = 0; i <= nA; ++i)
    {
        if (a[i] == '+' || a[i] == '-' || i == nA)
        {
            if (last == '-') tempA.insert(tempA.begin(), last);
            _a.push_back(tempA);
            tempA = "";

            last = a[i];
        }
        else
        {
            tempA += a[i];
        }
    }

    int nB = b.size();
    string tempB = "";
    vector<string> _b;

    if (b[0] != '-')
    {
        last = '+';
    }
    else
    {
        last = '-';
    }

    for (int i = 0; i <= nB; ++i)
    {
        if (b[i] == '+' || b[i] == '-' || i == nB)
        {
            if (last == '-') tempB.insert(tempB.begin(), last);
            _b.push_back(tempB);
            tempB = "";

            last = b[i];
        }
        else
        {
            tempB += b[i];
        }
    }

    string ans = "";
    int sizeA = _a.size(), sizeB = _b.size();

    for (int i = 0; i <= sizeA - 1; ++i)
    {
        for (int j = 0; j <= sizeB - 1; ++j)
        {
            string now = timeMonomial(_a[i], _b[j]);

            if (now[0] != '+' && now[0] != '-' && ans != "")
            {
                ans += '+';
            }
            ans += now;
        }
    }

    ans = simplify(ans);

    return ans;
}

int main()
{
    cout << "\n\n";
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

        string s = "1";

        for (int c = 1; c <= 5; ++c)
        {
            s = timePolynomial("ab + ac + bc", s);
            cout << s << '\n';
        }

        break;
    }
    cout << '\n';
    
    return 0;
}
