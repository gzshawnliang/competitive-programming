#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



int main()
{
    vector<int> v1={3,4,2,1,77,4,234,43,26,34,7};

    int max_v = *max_element(v1.begin(),v1.end());
    int min_v = *min_element(v1.begin(),v1.end());
    cout << max_v << " " << min_v <<  "\n";

    return 0;
}