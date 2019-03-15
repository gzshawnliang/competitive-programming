#include "MyRandom.h"
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int caseCout;
    cin >> caseCout;
    random rdNum;
    while (caseCout--)
    {
        cout << rdNum.GetRand(1, 100) * rdNum.GetRand(1, 100) << "\n";

    }
    //cout << rdNum.GetRand(1, 100) / rdNum.GetRand(0, 0) << "\n";
    return 0;
}
