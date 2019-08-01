#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


ofstream fout("getRooked.out");

int getChar()
{
    return (rand() % (2-1+1))+ 1;     
}

int main()
{
    srand((unsigned)time(NULL));  
    const int maxCase=1000;
    for(int i=1;i<=maxCase;++i)
    {
        fout << "4\n";
        for(int k=1;k<=4;++k)
        {
            for(int j=1;j<=4;++j)
            {
                if(getChar()==1)
                {
                    fout << ".";
                }
                else
                {
                    fout << "X";
                }
            }
            fout << "\n";
        }

    }
    return 0;
}