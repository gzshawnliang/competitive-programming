#include <bits/stdc++.h>

using namespace std;

int main()
{
    string bit_string = "00000000000001110000000000";
    bitset<32> b3(bit_string);

    cout << b3.to_string() << '\n';
    unsigned long a = b3.to_ulong();

    cout << hex << a << endl;
    return 0;
}
