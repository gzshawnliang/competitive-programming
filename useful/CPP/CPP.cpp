#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "ConsoleColor.h"
#include "Windows.h"

using namespace std;

ofstream fout("CPPrun.cpp");

string change(string s)
{
    int size = s.size();

    for (int i = 0; i <= size - 1 - 3; i += 3)
    {
        string now = "";
        now.push_back(s[i + 0]);
        now.push_back(s[i + 1]);
        now.push_back(s[i + 2]);
        
        if (now == "cin")
        {
            s[i + 0] = 'f';
        }
    }

    for (int i = 0; i <= size - 1 - 4; i += 4)
    {
        string now = "";
        now.push_back(s[i + 0]);
        now.push_back(s[i + 1]);
        now.push_back(s[i + 2]);
        now.push_back(s[i + 3]);

        if (now == "cout")
        {
            s[i + 0] = 'f';
        }
    }

    return s;
}

int main()
{
    vector<string> code;
    while (true)
    {
        string in = "";
        getline(cin, in);

        if (in == "#done")
        {
            break;
        }
        else
        {
            code.push_back(in);
        }
    }

    cout << green << "\nProssessing...\n\n";

    int size = code.size();

    fout << "#include <fstream>\n";
    for (int i = 0; i <= size - 1; ++i)
    {
        fout << change(code[i]) << '\n';

        if (code[i] == "using namespace std;")
        {
            fout << "ifstream fin(\"CPPrun.in\");\n";
            fout << "ofstream fout(\"CPPrun.out\");\n";
        }
    }

    cout << green << "\nDONE\n\n";

    fout.close();

    //system("CPPrun.exe");

    fout.open("CPPrun.in");

    

    cout << yellow << "\nInput...\n\n" << white;

    while (true)
    {
        string in = "";
        getline(cin, in);

        if (in == "#done")
        {
            break;
        }
        else
        {
            fout << in << '\n';
        }
    }

    cout << yellow << "\nOutput...\n\n" << white;

    return 0;
}
