#include <bits/stdc++.h>

using namespace std;

void test()
{
    vector<int> a={1,2,3,4,5};
    for (int i = 1; i < 32; ++i)
    {
        bitset<5> b(i); 
        cout << i << ":" << b.to_string() ;
        // for (int j = 0; j <= 4; ++j)
        //   if (b[j] == 1)
        //     cout << a[j] << "-";

        cout << "\n";
    }

}

int main()
{
    test();

    return 0;
}
