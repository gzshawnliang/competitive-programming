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


int main()
{

    int T=10;
    vector<int> s2(10,8);
    s2[10]=40;
    // for(size_t j = 0; j < T; ++j)
    // {
    //     int k = T, i = -1;

    //     vector<int> s(k);
    
    //     while (i <= k - 1)
    //     {
    //         ++i;
    //         s[i] = T;
    //     }
    //     cout << j << '\n';
    // }
    
    cout << "OK" << "\n";
    //cout << s2[10] << '\n';

    return 0;
}

int main2()
{

    int T=10;

    
    for(size_t j = 0; j < T; ++j)
    {
        int k = T, i = 0;

        vector<int> s(k);
       
        while (i <= k - 1)
        {
            
            s[i] = T;
            ++i;
        }        
        cout << j << '\n';
    }
    

    cout << T << '\n';

    return 0;
}