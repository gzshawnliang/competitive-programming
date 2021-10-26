#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
const ull p = 3;

ull normal_calculate()
{
    ull pow = 1;
    ull hashcode = 0;
    for (int i = 1; i <= 5; ++i)
    {
        hashcode += p * pow;
        pow *= p;
    }
    return hashcode;
}

ull horner_calculate()
{
    ull hashcode = 0;
    for (int i = 1; i <= 5; ++i)
        hashcode = p * (hashcode + 1);

    return hashcode;
}

ull hashCode(const string & s)
{
    int len = s.length();
    ull hashValue = 0;
    for (int i = 0; i <= len-1; ++i)
    {
        cout << p << "*" << hashValue << "+" << (int)s[i];
        hashValue = p * hashValue + s[i];
        cout << "=" << hashValue << "\n" ;
    }
    
    return hashValue;
}

int main()
{
    cout << normal_calculate() << "\n";
    cout << horner_calculate() << "\n";

    cout << hashCode("dcba") << "\n";

    return 0;
}
