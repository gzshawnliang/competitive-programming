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

using namespace std;

ifstream fin("citystate.in");
ofstream fout("citystate.out");

int main()
{
    int n; fin >> n;

    map<string, int> m;
    for (int i = 0; i <= n - 1; ++i)
    {
        string a, b; 
        fin >> a >> b;

        string c=a.substr(0,2);     //取出前两个字符，MIAMI->MI
        if(c!=b)
        {
            ++m[c + b];
        }
    }

    int total = 0;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        string now = it->first;

        /*后面两个字符和前面两个字符交换
         例如：MIFL->FLMI   
        */

        string swap;
        swap.push_back(now[2]);
        swap.push_back(now[3]);
        swap.push_back(now[0]);
        swap.push_back(now[1]);

        //查找交换之后是否存在
        if(m.count(swap)==1)
            total += m[swap] * m[now];
    }

    fout << total / 2 << '\n';

    return 0;
}