#include <bits/stdc++.h>

using namespace std;

/*
1-
2-
1-2-
3-
1-3-
2-3-
1-2-3-
4-
1-4-
2-4-
1-2-4-
3-4-
1-3-4-
2-3-4-
1-2-3-4-
5-
1-5-
2-5-
1-2-5-
3-5-
1-3-5-
2-3-5-
1-2-3-5-
4-5-
1-4-5-
2-4-5-
1-2-4-5-
3-4-5-
1-3-4-5-
2-3-4-5-
1-2-3-4-5-
*/

void test()
{
    vector<int> a={1,2,3,4,5};
    for (int i = 0; i <= 32 - 1; ++i)
    {
        bitset<5> b(i);

        for (int j = 0; j <= 5 - 1; ++j)
        {
            if (b[j] == 1) cout << a[j];
        }
        cout << '\n';
    }
}

int main()
{
    //test();

     bitset<7> b(63);
     cout << b.to_string() << "\n";

    return 0;
}