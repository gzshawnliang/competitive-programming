#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

ofstream fout("citystate.out");
ifstream fin("citystate.in");


int main()
{
    multimap<string, int> mp;
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
            mp.insert(std::make_pair(pre + state,1));
        }
    }

    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        string city1 = it->first;
        string city2 = city1.substr(2,2) + city1.substr(0,2);

        auto ret = mp.equal_range(city2);

        for (auto it2=ret.first; it2!=ret.second; ++it2)
        {
            ++ans;     
        }
    }

    fout << ans / 2 << "\n";
    
    return 0;
}