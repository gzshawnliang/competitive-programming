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

ifstream fin("camelTrading_UVA10700.in");
ofstream fout("camelTrading_UVA10700.out");

int main()
{
    int testCase;
    fin >> testCase;
    string useless_XD;
    getline(fin, useless_XD);
    for (int t = 1; t <= testCase; ++t)
    {
        string in = "";
        getline(fin, in);

        if (in == "")
        {
            break;
        }

        int size0 = in.size();
        vector<int> a;
        vector<bool> b;
        string temp0 = "";
        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (in[i] == '+' || in[i] == '*')
            {
                a.push_back(stoi(temp0));
                temp0 = "";
                b.push_back(in[i] == '+');
            }
            else
            {
                temp0+= in[i];
            }
        }
        a.push_back(stoi(temp0));

        vector<long long> sum0, sum1;
        int size1 = a.size();
        long long maxAns = 1, minAns = 0, temp1 = a[0];

        for (int i = 0; i <= size1 - 2; ++i)
        {
            if (b[i] == false)
            {
                sum0.push_back(temp1);
                temp1 = a[i + 1];
            }
            else
            {
                temp1 += a[i + 1];
            }
        }
        sum0.push_back(temp1);

        int sizeSum0 = sum0.size();
        for (int i = 0; i <= sizeSum0 - 1; ++i)
        {
            maxAns *= sum0[i];
        }

        temp1 = a[0];
        for (int i = 0; i <= size1 - 2; ++i)
        {
            if (b[i] == true)
            {
                sum1.push_back(temp1);
                temp1 = a[i + 1];
            }
            else
            {
                temp1 *= a[i + 1];
            }
        }
        sum1.push_back(temp1);

        int sizeSum1 = sum1.size();
        for (int i = 0; i <= sizeSum1 - 1; ++i)
        {
            minAns += sum1[i];
        }

        fout << "The maximum and minimum are " << maxAns << " and " << minAns << ".\n";
    }

    return 0;
}