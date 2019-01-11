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

ifstream fin("self-describingSequence.in");
ofstream fout("self-describingSequence.out");

int getItem2(vector<int> & a, int pos)
{

    int value=pos;
    auto it=lower_bound(a.begin(), a.end(), value); 
    while((*it)>value)
    {
        --it;
    }
    return it-a.begin();
}

int getItem3(vector<int> & a, int pos)
{
    if (pos == 1)
    {
        return 1;
    }
    else if (pos > a.back())
    {
        return a.size() - 1;
    }
    int lbound = 0, rbound = a.size() - 1;
    while (rbound - lbound > 1)
    {
        int mid = (rbound + lbound) / 2;
        if (a[mid] > pos)
        {
            rbound = mid;
        }
        else if (a[mid] < pos)
        {
            lbound = mid;
        }
        else
        {
            return mid;
        }
    }

    if (a[rbound] == pos)
    {
        return rbound;
    }
    else
    {
        return lbound;
    }
}

int main()
{
    vector<int> a = {-1, 1, 2, 4};
    int pos = 5;
    int nowNum = 4;
    //const int max=673370;                  //673365;
    while (true)
    {
        if (a.back() > (int)2e9)
        {
            break;
        }

        a.push_back(pos + 1);

        pos += getItem2(a, nowNum);
        ++nowNum;
    }

    for (int i = 1; i <= a.size(); ++i)
    {
        fout << a[i] << '\n';
    }
    fout << "--\n";

    while (true)
    {  
        int in = 0;
        fin >> in;

        if (in == 0)
        {
            break;
        }
        
        fout << getItem2(a, in) << '\n';
    }

    return 0;
}