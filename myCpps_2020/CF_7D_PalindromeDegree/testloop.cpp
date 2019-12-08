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

    //system("pause");
}