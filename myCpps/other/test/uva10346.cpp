/*
===========================================================
 * @����:		10346 - Peter's Smokes 
 * @���Shawnomas 
 * @����ʱ��: 2018-03-26 09:32:19 
 * @�޸��Shawnhomas
 * @�޸�ʱ��: 2018-03-26 09:32:19 
 * @��ע:		
 * @��Ŀ��Դ�� http://uva.onlinejudge.org/external/103/10346.pdf
===========================================================
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long int n, i;
    #ifndef ONLINE_JUDGE
        freopen("uva10346.in", "r", stdin);      
        freopen("uva10346.out", "w", stdout);       
    #endif
    
    while (cin>>n>>i)
    {
        int last = 0;
        int total = n;
        do
        {
            last = n / i;
            n = n - last * i+last;
            total += last;
        } 
        while (last > 0);
        cout<< total<<"\n";
    }

    #ifndef ONLINE_JUDGE
        fclose(stdin);
        fclose(stdout);    
    #endif
    return 0;
}