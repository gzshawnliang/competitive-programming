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



int solve()
{

    int T=10;
    vector<int> s2(10,8);
    cout << "OK" << '\n';
    cout << s2[10] << '\n';
    s2[10]=40;
    
    return 0;
}

int main()
{
    solve();
    return 0;
}

int main2()
{

    int T=10;

    
    for(size_t j = 0; j < T; ++j)
    {
        int k = T, i = -1;

        vector<int> s(k);
       
        while (i <= k - 1)
        {
            ++i;
            s[i] = T;
            
        }        
        cout << j << '\n';
    }
    

    cout << T << '\n';

    return 0;
}