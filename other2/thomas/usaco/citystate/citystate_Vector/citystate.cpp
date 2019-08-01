#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

ofstream fout("citystate.out");
ifstream fin("citystate.in");

int main()
{
    vector<string> citySet;
    int N = 0;
    fin >> N;
    for (int i = 0; i <= N - 1; ++i)
    {
        string city;
        string state;
        fin >>  city >> state;

        string pre=city.substr(0, 2);

        if(pre != state)
        {
            citySet.push_back(pre + state);
        }
    }

    sort(citySet.begin(),citySet.end());

    int ans = 0;
    for (auto it = citySet.begin(); it != citySet.end(); ++it)
    {
        string city1 = *it;
        string city2 = city1.substr(2,2) + city1.substr(0,2);

        auto ret = equal_range(citySet.begin(),citySet.end(), city2);
        if(ret.first==ret.second)
        {
            continue;
        }
        for (auto it2=ret.first; it2!=ret.second; ++it2)
        {
            ++ans;     
        }
    }

    fout << ans / 2 << "\n";
    
    return 0;
}