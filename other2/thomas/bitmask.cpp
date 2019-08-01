#include <bits/stdc++.h>

using namespace std;


//判断一个数字x二进制下第i位是不是等于1。
bool getMask(int x,int i)
{
    return (x & (1 << (i-1))) >0;
}

//将一个数字x二进制下第i位更改成1。
void setMask(int & x,int i)
{
    //x = x | (1 << (i - 1));
    x |= (1 << (i - 1));
}

//把一个数字二进制下最靠右的第一个1去掉。
void removeMask(int & x)
{
    //x = x & (x - 1);
    x &= (x - 1);
}

int main()
{
    int x=18;
    int i=5;

    //十进制18的二进制是 10010
    string binary = bitset<8>(x).to_string(); //to binary
    cout <<binary <<'\n';

    // //十进制1的二进制是1
    // cout <<bitset<8>(1).to_string() <<'\n';

    //  cout <<bitset<8>(1<<(i-1)).to_string() <<'\n';
    //  cout <<bitset<8>(x & (1<<(i-1))).to_string() <<'\n';

    cout << getMask(x,i) <<'\n';

    setMask(x,4);
    cout << bitset<8>(x).to_string() <<'\n';

    removeMask(x);
    cout << bitset<8>(x).to_string() <<'\n';



    return 0;
}
