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
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

bool done = false;

char checkType(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'l'; // lowercase
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return 'c'; // capitalize
    }
    else if (c >= '0' && c <= '9')
    {
        return 'n'; // number
    }
    else
    {
        return 'u'; // unknow
    }
}

int getNumber(int & i, string & s)
{
    int size = s.size();
    string temp = "";

    while (true)
    {
        if (i == size) break;
        else if (checkType(s[i]) != 'n')
        {
            --i;
            break;
        }

        temp += s[i];

        ++i;
    }

    return stoi(temp);
}

void breakPart(int _time, string & material, map<string, int> & element)
{
    int size = material.size();
    string temp = "";

    for (int i = 0; i <= size - 1; ++i)
    {
        if (checkType(material[i]) == 'n')
        {
            element[temp] += _time * getNumber(i, material);

            temp = "";
        }
        else
        {
            temp += material[i];
        }
    }
}

void mapOut(map<string, int> & m)
{
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ' ' << it->second << '\n';
    }
}

bool checkEqu(string & equ)
{
    equ += '+';

    bool mode = 0, first = true;
    int size = equ.size(), _time = 1;
    string temp = "";
    map<string, int> leftElement, rightElement;
    vector<string> left, right;

    for (int i = 0; i <= size - 1; ++i)
    {
        if (checkType(equ[i]) == 'n' && first == true)
        {
            _time = equ[i] - '0';
            first = false;
        }
        else if (equ[i] == '+' || equ[i] == '-')
        {
            if (mode == 0)
            {
                left.push_back(temp);
                breakPart(_time, temp, leftElement);
            }
            else
            {
                right.push_back(temp);
                breakPart(_time, temp, rightElement);
            }
            temp = "";
            _time = 1;

            if (equ[i] == '-')
            {
                mode = 1;
            }

            first = true;
        }
        else
        {
            temp += equ[i];
            first = false;
        }
    }

    equ.erase(--equ.end());

    if (leftElement.size() != rightElement.size())
    {
        return false;
    }

    for (auto itL = leftElement.begin(), itR = rightElement.begin(); itL != leftElement.end() && itR != rightElement.end(); ++itL, ++itR)
    {
        if (itL->second != itR ->second || itL->first != itR ->first)
        {
            return false;
        }
    }

    return true;
}

void equOut(string & equ)
{
    bool first = true;
    int size = equ.size();

    for (int i = 0; i <= size - 1; ++i)
    {
        if (checkType(equ[i]) == 'n' && first == true)
        {
            first = false;
            cout << green << equ[i];
        }
        else if (equ[i] == '-')
        {
            cout << blue << " == ";
            first = true;
        }
        else if (equ[i] == '+')
        {
            cout << blue << " + ";
            first = true;
        }
        else if (equ[i] == '1')
        {
            if (i == size - 1)
            {

            }
            else if (checkType(equ[i + 1]) != 'n')
            {

            }
            else
            {
                cout << yellow << equ[i];
                first = false;
            }
        }
        else
        {
            cout << yellow << equ[i];
            first = false;
        }
    }
}

void solve(int c, vector<int> & data, vector<int> & insertPos, string & equ)
{
    if (done == true) return;

    int size = data.size();

    if (c <= size)
    {
        for (int i = 1; i <= 6; ++i)
        {
            int temp = data[c];
            data[c] = i;

            solve(c + 1, data, insertPos, equ);

            data[c] = temp;
        }
    }
    else
    {
        string temp = equ;
        for (int i = 0; i <= size - 1; ++i)
        {
            equ.insert(insertPos[i] + i, to_string(data[i]));
        }

        done = checkEqu(equ);

        if (done == true)
        {
            equOut(equ);
            cout << '\n';
        }

        equ = temp;
    }
}

int _main()
{
    string equ, tempEqu1;

    //getline(cin, equ);
    equ = "KCl + O2 - KClO3 + Cl2";

    cout << checkEqu(equ) << '\n';

    string sjakhfksajfhjsakhf; cin >> sjakhfksajfhjsakhf;
    return 0;
}

int main()
{
    while (true)
    {
        done = false;

        cout << white;
        string equ, tempEqu1;

        getline(cin, equ);
        //equ = "CaH4P2O8 + NaHCO3 - CaHPO4 + Na2HPO4 + CO2 + H2O";

        if (equ == "break") break;

        tempEqu1 = "";

        int size = equ.size(), totalCount = 2;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (equ[i] != ' ')
            {
                if (equ[i] == '+')
                {
                    ++totalCount;
                }
                tempEqu1 += equ[i];
            }
        }
        equ = tempEqu1;
        size = equ.size();

        bool meet = false;
        for (int i = 0; i <= equ.size() - 1; ++i)
        {
            if (checkType(equ[i]) == 'l')
            {
                continue;
            }
            else if (checkType(equ[i]) == 'n')
            {
                meet = false;
            }
            else if (equ[i] == '+' || equ[i] == '-')
            {
                if (checkType(equ[i - 1]) != 'n')
                {
                    equ.insert(i, "1");
                    meet = false;
                }
            }
            else if (meet == true)
            {
                equ.insert(i, "1");
                meet = false;
            }
            else
            {
                meet = true;
            }
        }

        if (checkType(equ.back()) != 'n')
        {
            equ.push_back('1');
        }

        size = equ.size();

        vector<int> insertPos(1, 0);
        for (int i = 1; i <= size - 2; ++i)
        {
            if (equ[i] == '+' || equ[i] == '-')
            {
                insertPos.push_back(i + 1);
            }
        }

        vector<int> data(totalCount, 0);
        solve(0, data, insertPos, equ);

        if (done == false)
        {
            cout << "NotFound\n";
        }
    }

    // string sjakhfksajfhjsakhf; cin >> sjakhfksajfhjsakhf;

    return 0;
}