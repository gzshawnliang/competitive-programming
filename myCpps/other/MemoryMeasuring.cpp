/*
===========================================================
 * @名称:		测量程序运行占用的内存
 * @作者:		Thomas 
 * @创建时间: 2019-10-18 16:48:52 
 * @修改人:   Thomas
 * @修改时间: 2019-10-18 16:48:52 
 * @备注:		
 * @题目来源： 
===========================================================
*/
#include <bits/stdc++.h>

#ifdef _WIN32
#include <windows.h>
#include<Psapi.h>
#endif

using namespace std;

//ifstream fin("MemoryMeasuring.in");
//ofstream fout("MemoryMeasuring.out");

int main()
{
    const int imax=1e6;
    vector<int> a(imax,100);

    #ifdef _WIN32
        HANDLE handle = GetCurrentProcess();
        PROCESS_MEMORY_COUNTERS pmc;
        GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
        cerr << "Peak WorkingSet    :" << pmc.PeakWorkingSetSize/1024 << "kb\n";  
        cerr << "Peak PagefileUsage :" << pmc.PeakPagefileUsage/1024 << "kb\n";  
    #endif    

    return 0;
}
