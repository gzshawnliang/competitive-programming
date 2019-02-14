
#include <bitset>
#include <iostream>
using namespace std;
int main()
{
    cout << "36的8进制:" << std::oct << 36 << endl;
    cout << "36的10进制" << std::dec << 36 << endl;
    cout << "36的16进制:" << std::hex << 16 << endl;
    cout << "36的2进制: " << bitset<8>(36) << endl;
    return 0;

}