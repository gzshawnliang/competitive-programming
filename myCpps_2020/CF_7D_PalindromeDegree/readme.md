# C++性能对比 单个for-loop VS 多个for-loop 
***
代码一
```c++
int i;
for (i = 0; i < exchanges; i++)
{
    // some code
    // some more code
    // even more code
}
```
代码二
```c++
int i;
for (i = 0; i < exchanges; i++)
{
    // some code
}

for (i = 0; i < exchanges; i++)
{
    // some more code
}

for (i = 0; i < exchanges; i++)
{
    // even more code
}
```

理论上代码一和代码二计算量是一样，单经常代码二慢一倍，为什么？

测试代码
```c++
#include <time.h>
#include <iostream>
using namespace std;
#define TOGETHER 1;
int main(){

    int size = 10000;
    int *data = new int[size];

    clock_t start = clock();

    for (int i = 0; i < 1000000; i++)
    {
        #ifdef TOGETHER
                //10.114s
                for (int c = 0; c < size; c++){
                    data[c] *= 10;
                    data[c] += 7;
                    data[c] &= 15;
                }
        #else
                //20.695s
                for (int c = 0; c < size; c++){
                    data[c] *= 10;
                }
                for (int c = 0; c < size; c++){
                    data[c] += 7;
                }
                for (int c = 0; c < size; c++){
                    data[c] &= 15;
                }
        #endif
    }

    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
```
>机器配置：

|名称                  | 配置        |备注          |
|:---------------------|:----------|:------------|
|CPU|i3-7100U||
|RAM|4GB RAM||
|OS|Windows Server 2019 Datacenter<br/> ESXi 6.7.0 Update 3 (Build 14320388)|建立在Exsi上 的虚拟机|
|c++|GCC 9.2.0 (Rev2, Built by MSYS2 project)  ||
|编译参数|-std=gnu++11 -O2 -Wall -lstdc++fs -lm ||

以上代码执行测试结果如下
- 1个循环9.671s
- 3个循环20.062s

参考
<https://stackoverflow.com/questions/13866962/what-is-the-overhead-in-splitting-a-for-loop-into-multiple-for-loops-if-the-tot>
