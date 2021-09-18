#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v={3,5,7,8,10,12,14,15,15,15,18,19};
    auto low=std::equal_range  (v.begin(), v.end(), 15); 
    // if(low==v.end())
    // {
    //     cout << "no found" << "\n";
    // }
    // else
    // {
    //     cout << "found" << "\n";
    // }

    int i=100;
    for(;;)
    {
        --i;
        if(i==0)
        {
            break;
        }
    }

    return 0;
}