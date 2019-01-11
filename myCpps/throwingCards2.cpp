/***********************************************************
 * @����:   UVA 10940 	Throwing cards away II		
 * @����:		Shawn 
 * @����ʱ��: 2018-03-10 21:07:44 
 * @�޸���:   Shawn 
 * @�޸�ʱ��: 2018-03-10 21:07:44 
 * @��ע:	  �ⷨ���������ݴ�1��50�򣬱������֮���ҹ��ɡ�
 * �����о�Լɪ�����⡶������ѧ��,һ����Լɪ��ⷨ
 * int main()  
{  
    int n, tmp, cnt, ans;  
    while (scanf("%d", &n), n)  
    {  
        cnt = 0;  
        for (tmp = n; tmp; tmp >>= 1) 
            ++cnt;  
            
        ans = (n - (1 << (cnt - 1))) << 1;  
        printf("%d\n", ans ? ans : n);  
    }  
    return 0;  
}  
 * @��Ŀ��Դ�� http://uva.onlinejudge.org/external/109/10940.pdf
***********************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

ifstream fin("throwingCards.in");
ofstream fout("throwingCards.out");

int main()
{
    vector<int> times;
    int temp = 1;
    for (int i = 0; i <= 19; ++i)
    {
        times.push_back(temp);
        temp *= 2;
    }

    while (true)
    {
        int n;
        fin >> n;

        if (n == 0)
        {
            break;
        }

        for (int i = 19; i >= 0; --i)
        {
            if (n > times[i])
            {
                fout << (n - times[i]) * 2 << '\n';
                break;
            }
            else if (n == times[i])
            {
                fout << n << '\n';
                break;
            }
        }
    }

    return 0;
}