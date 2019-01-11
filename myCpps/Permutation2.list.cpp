#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>


using namespace std;

ifstream fin("Permutation2.in");
ofstream fout("Permutation2.out");

void solve(string str, string out)
{
    if (str.size() == 0)
    {
        fout << out << '\n';
    }
    else
    {   
        int size1 = str.size();
        int size2 = out.size();
        for (int i = 0; i <= size2; ++i)
        {
            string temp1 = str, temp2 = out;
            temp2.insert(temp2.begin() + i, temp1[0]);
            temp1.erase(temp1.begin());
            solve(temp1, temp2);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    bool hi = false;
    string str = "";
    while (fin >> str)
    {
        string out = "";
        //fin >> str;
        // if (!(fin >> str))
        // {
        //     break;
        // }
        // else
        if (hi)
        {
            fout << '\n';
        }

        solve(str, out);

        hi = true;
    }
    fout.flush();
    return 0;
}