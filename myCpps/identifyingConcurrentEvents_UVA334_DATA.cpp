#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

ofstream fout("identifyingConcurrentEvents_UVA334.in");

int main()
{
    random rdNum;             //note:随机数


    int N = rdNum.GetRand(1, 5);
    fout << N << "\n";
    vector<int> temp = rdNum.GetUniqueRand(1,N);
    
    for (int i = 0; i <= N - 1; ++i)
    {
        //vector<int> temp=rdNum.GetUniqueRand(1,N1);
        fout << temp[i] << " ";
        
        for (int j = 0; j <= temp[i] - 1; ++j)
        {
            fout << "e" << rdNum.GetRand(1, N*2) << " ";
        }

        fout << "\n";
    }
    fout << 1 << "\n";
    fout << "e" << rdNum.GetRand(1, N) << " " << "e" << rdNum.GetRand(1, N) << "\n";

    fout << 0 << "\n";

    
    fout.close();

    return 0;
}
