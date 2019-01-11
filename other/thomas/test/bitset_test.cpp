#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <set>
#include <bitset>
using namespace std;

int main()
{
    bitset<10> v1;              //定义10位的bitset变量
    v1 = 8;                     //将v1赋值为8
    bitset<10> v2(v1);          //初始化，与v1相同
    bitset<10> v3 = v2;         //赋值，=v2
    
    // 从右往左数，最右边的为第一位，向左依次加1
    v1[1] = 1;//将v1的第一位置为1
    //v1.set(1);

    cout << "v1=" << v1 << endl;//用二进制的形式输出v1
    cout << "v2=" << v2 << endl;
    cout << "v3=" << v3 << endl;
    
    for (int i = (int)(v1.size()) - 1; i >= 0; --i)//一位一位的输出
        cout << v1[i];
    cout << endl;
    
    cout << "any() --- \t" << v1.any() << endl;
    cout << "count() --- \t" << v1.count() << endl;
    cout << "flip --- \t" << v1.flip() << endl;
    cout << "none() --- \t" << v1.none() << endl;
    
    //其他函数用法相似

    return 0;
}