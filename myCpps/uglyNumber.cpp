#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>


using namespace std;

int main()
{
    //ofstream fout("uglyNumber.out");

    int length = 1500;
    set<long long> a;
    long long index = 1;
    a.insert(index);
    for (int i = 1; i <= length; ++i)
    {
        a.insert(index * 2);
        a.insert(index * 3);
        a.insert(index * 5);

        auto it = a.begin();
        advance(it, i);
        index = *it;
    }

    auto it = a.begin();
    advance(it, length - 1);
    cout << "The 1500'th ugly number is " << *it << ".\n";

    return 0;
}