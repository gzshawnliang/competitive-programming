#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRand(int a,int b)
{
    if(b>=RAND_MAX)
    {
        double result = (double)b * ((double)rand()/(double)(RAND_MAX+1));
        return (int)result;
    }
    return (rand() % (b-a+1))+ a;
}

int main()
{
    srand(time(NULL));

    int testFileCount=200;
    while(testFileCount--)
    {
        string inFileName = to_string(testFileCount+1) + ".in";
        freopen(inFileName.c_str(), "w", stdout);

        int T=testFileCount+1;
        cout << T <<"\n";
        while(T--)
        {
            int n=getRand(2,100000);
            cout << n <<"\n";
            while(n--)
            {
                cout << getRand(0,150000*2)-150000 <<"\n";
                //cout << getRand(5,100) <<"\n";
            }

        }
    }


    return 0;
}
