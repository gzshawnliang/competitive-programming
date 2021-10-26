#include <bits/stdc++.h>

using namespace std;

ifstream fin("primeNumber.in");
ofstream fout("primeNumber.out");

const int N = 1e6;
bitset<N+1> IsPrimeNumber;

void InitPrimeNumber()
{

    IsPrimeNumber.set();  //把所有二进制位都置为1
    IsPrimeNumber[0] = 0;
    IsPrimeNumber[1] = 0;
    // for (int i = 2; i <= N; ++i)
    //     IsPrimeNumber[i] = 1;

    for (int i = 2; i <= N / 2; ++i)
        IsPrimeNumber[i * 2] = 0;

    int p = 2;
    while (p * p <= N)
    {
        p = p + 1;
        while (IsPrimeNumber[p] == 0)
            p++;

        int t = p * p;
        int s = 2 * p;
        while (t <= N)
        {
            IsPrimeNumber[t] = 0;
            t = t + s;
        }
    }
}

int main()
{
    InitPrimeNumber();
    
    int newLIne=10; //每10个换行
    int j=0;

    ofstream outfile("primeNumber.out", ios::out);
    
    int len=to_string(N).length();

    for (int i = 2; i <= N; i++)
    {
        if (IsPrimeNumber[i] == 1)
        {
            outfile << setw(len-1) << std::left << i << " ";
            ++j;

            if(j % newLIne ==0)
            {
                outfile << '\n';
            }
        }
    }
    return 0;
}
