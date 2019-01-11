/***********************************************************
 * @����:		K Smallest Sums ����������
 * @����:		Shawn 
 * @����ʱ��: 2017-12-12 21:19:03 
 * @�޸���:   Shawn 
 * @�޸�ʱ��: 2017-12-12 21:19:03 
 * @��ע:		
 * @��Ŀ��Դ�� 
***********************************************************/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ofstream fout("KsmallSums.in");
    srand(time(NULL));
    vector<long> data;
    int n = 750;
    int n1 = n * n;
    long a = 1, b = 100000;

    while (data.size() <= n1 )
    {
        while (data.size() < n1 * 2)
        {
            int result = rand() % (b - a + 1) + a;
            data.push_back(result);
        }
        random_shuffle(data.begin(), data.end());
    }

    fout << n << '\n';
    int count = 1;
    int linecount = 0;
    for (auto i = data.begin(); i != data.end(); ++i)
    {
        fout << *i << " ";
        if (count % n == 0)
        {
            fout << '\n';
            linecount++;
            if(linecount==n)
            {
                break;
            }
        }
        ++count;
    }

    return 0;
}