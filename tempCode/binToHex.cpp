#include <bits/stdc++.h>

using namespace std;

string binToHex(string bit_string)
{
    //string bit_string = "00000000000001110000000000";
    bitset<256> b3(bit_string);
    //cout << b3.to_string() << '\n';
    unsigned long a = b3.to_ulong();
    
    string result;
    stringstream ss;

    ss << hex << a;
    ss >> result;
    return result;
}

string hexToBin(string hex_string)
{
    string result;
    stringstream ss;
    
    for (int i = 0; i <= hex_string.size() - 1; ++i)
    {
         switch(hex_string[i])
         {
             case '0': ss<<"0000"; break;
             case '1': ss<<"0001"; break;
             case '2': ss<<"0010"; break;
             case '3': ss<<"0011"; break;
             case '4': ss<<"0100"; break;
             case '5': ss<<"0101"; break;
             case '6': ss<<"0110"; break;
             case '7': ss<<"0111"; break;
             case '8': ss<<"1000"; break;
             case '9': ss<<"1001"; break;
             case 'A': ss<<"1010"; break;
             case 'B': ss<<"1011"; break;
             case 'C': ss<<"1100"; break;
             case 'D': ss<<"1101"; break;
             case 'E': ss<<"1110"; break;
             case 'F': ss<<"1111"; break;
             case 'a': ss<<"1010"; break;
             case 'b': ss<<"1011"; break;
             case 'c': ss<<"1100"; break;
             case 'd': ss<<"1101"; break;
             case 'e': ss<<"1110"; break;
             case 'f': ss<<"1111"; break;
             default:  ss<<"nInvalid hexadecimal digit "<<hex_string[i];
         }        
    }

    ss >> result;
    return result;
}

int main()
{
    string source="00000000000001110000000000";
    string result = binToHex(source);
    cout << source << " -> " << result << "\n";


    source="65b2";
    result = hexToBin(source);
    cout << source << " -> " << result << "\n";
    int n;
    cin >> n;
    cout << n;
    return 0;
}
