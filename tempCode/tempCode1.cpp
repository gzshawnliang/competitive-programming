#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("tempCode.in");
ofstream fout("tempCode.out");

int main()
{
    int N; fin >> N;
    vector<int> A(N);
    for (int i = 0; i <= N - 1; ++i)
    {
        fin >> A[i];
    }

    bool sorted = false;
    while (sorted == false)
    {
        for (int i = 0; i <= N - 1; ++i)
        {
            if (i > 0) fout << ' ';
            fout << A[i];
        }
        fout << '\n';

        sorted = true;
        for (int i = 0; i <= N - 2; ++i)
        {
            if (A[i + 1] < A[i])
            {
                swap(A[i], A[i + 1]);
                sorted = false;
            }
        }
    }

    return 0;
}
