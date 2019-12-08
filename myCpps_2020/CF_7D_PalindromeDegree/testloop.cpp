/*
===========================================================
 * @名称:		c++循环拆分合并性能问题
 * @作者:		Thomas 
 * @创建时间: 2019-12-08 12:17:50 
 * @修改人:   Shawn 
 * @修改时间: 2019-12-08 12:17:50 
 * @备注:		
 * @题目来源： https://stackoverflow.com/questions/13866962/what-is-the-overhead-in-splitting-a-for-loop-into-multiple-for-loops-if-the-tot
===========================================================
*/
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