#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    clock_t tStart = clock();
    srand (time(NULL));
    ifstream fin("testFinFout.in");
    ofstream fio("testFinFout.in");
    ofstream fout("testFinFout.out");

    freopen("testFinFout.out", "w", stdout); 

    int total = (int)1e7 * 1;
    fio << total << '\n';

    //printf("%d\n",total);

    for (int i = 1; i <= total; ++i)
    {
       fio << rand() << '\n';
        //printf("%d\n",rand());
    }

    // int n;
    // fin >> n;
    // for (int i = 1; i <= n; ++i)
    // {
    //     int temp;
    //     fin >> temp;
    //     fout << temp << " ";
    //     if (i % 10 == 0)
    //     {
    //         fout << endl;
    //     }
    // }
    // fout << endl;

   fio << (double)(clock() - tStart)/CLOCKS_PER_SEC <<"s"<< '\n';

    //printf("%ds\n",(double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}