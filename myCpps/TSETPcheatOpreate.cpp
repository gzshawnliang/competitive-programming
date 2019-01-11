#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("TSETP.out");
    ofstream write("TSETPcheat.cpp");

    write << "int main()" << '\n';
    write << "{" << '\n';
    write << "\tmultimap<int,string> result" << '\n';
    write << "\t{" << '\n';
    for (int i = 1; i <= 354; ++i)
    {
        string temp1, temp2 = "";
        getline(fin, temp1);
        int j = 0;
        while(true)
        {
            if (temp1[j] == ' ')
            {
                break;
            }
            else if (temp1[j] != '.')
            {
                temp2 += temp1[j];
            }
            ++j;
        }
        write << "\t\t{"  << temp2 << ",\"" << temp1 << "\"},\n";
    }
    write << "\t};" << '\n';
    write << "}" << '\n';

    return 0;
}