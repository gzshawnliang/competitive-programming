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

//***************************************
const string CPPfile = "NEW_maximumSum_UVA108"; //*
//***************************************

ifstream fin(CPPfile + ".cpp");
ofstream fout(CPPfile + "OJ.cpp");

bool _isAlpha(char a)
{
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

int main()
{
    bool findMain = false;
    bool fastDone = false;
    while (true)
    {
        string in = "I am Shawn.";
        getline(fin, in);
        int size = in.size();

        if (findMain == true && fastDone == false)
        {
            fout << in << '\n';
            fout << "\tios_base::sync_with_stdio(false);\n\tstd::cin.tie(NULL);\n";
            fastDone = true;
            continue;
        }

        if (in == "I am Shawn.")
        {
            break;
        }
        else if (in == "")
        {
            fout << '\n';
            continue;
        }
        else if (in == "int main()")
        {
            findMain = true;
            fout << "int main()\n";
            continue;
        }
        else if (size >= 9)
        {
            int i = 0, SPACEcount = 0, TABcount = 0;
            while (in[i] == ' ' || in[i] == '\t')
            {
                ++i;
                if (in[i] == ' ')
                {
                    ++SPACEcount;
                }
                else
                {
                    ++TABcount;
                }
            }

            string front = "";
            for (int j = i; j <= size - 1; ++j)
            {
                front.push_back(in[j]);
            }

            if (front == "return 0;")
            {
                for (int c = 1; c <= SPACEcount; ++c)
                {
                    fout << ' ';
                }
                for (int c = 1; c <= TABcount; ++c)
                {
                    fout << '\t';
                }

                fout << "cout.flush();\n";

                for (int c = 1; c <= SPACEcount; ++c)
                {
                    fout << ' ';
                }
                for (int c = 1; c <= TABcount; ++c)
                {
                    fout << '\t';
                }

                fout << "return 0;\n";
                continue;
            }
        }

        if (size >= 8)
        {
            string front = "";

            int i = 0;
            while (in[i] == ' ' || in[i] == '\t')
            {
                ++i;
            }

            front.push_back(in[i]);
            front.push_back(in[i + 1]);
            front.push_back(in[i + 2]);
            front.push_back(in[i + 3]);
            front.push_back(in[i + 4]);
            front.push_back(in[i + 5]);
            front.push_back(in[i + 6]);
            front.push_back(in[i + 7]);

            if (front == "ifstream" || front == "ofstream")
            {
                continue;
            }
        }
        if (size >= 2)
        {
            int i = 0;
            while (in[i] == ' ' || in[i] == '\t')
            {
                ++i;
            }

            if (i <= size - 2)
            {
                if (in[i] == '/' && in[i + 1] == '/')
                {
                    continue;
                }
            }
        }
        if (size > 2)

        for (int i = 0; i <= size - 5; ++i)
        {
            string temp;
            temp.push_back(in[i]);
            temp.push_back(in[i + 1]);
            temp.push_back(in[i + 2]);
            if ((temp == "fin" && _isAlpha(in[i + 3]) == false) || (temp == "fou" && in[i + 3] == 't' && _isAlpha(in[i + 4]) == false))
            {
                in[i] = 'c';
            }
        }

        fout << in << '\n';
    }
    
    return 0;
}