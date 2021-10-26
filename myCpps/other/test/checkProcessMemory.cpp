#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <psapi.h>

//#pragma comment(lib, "psapi.lib") 

using namespace std;


// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

void PrintCurrentProcessMemoryInfo()
{
    PROCESS_MEMORY_COUNTERS pmc;
    BOOL result = GetProcessMemoryInfo(GetCurrentProcess(),
                                   &pmc,
                                   sizeof( pmc ));
    if(result)
    {
        // printf( "\tWorkingSetSize: 0x%08X - %ukb\n",  pmc.WorkingSetSize,  pmc.WorkingSetSize / 1024);  
        // printf( "\tPeakWorkingSetSize: 0x%08X - %ukb\n",  pmc.PeakWorkingSetSize,  pmc.PeakWorkingSetSize / 1024);                  
        //printf( "\tPagefileUsage: 0x%08X - %ukb\n", pmc.PagefileUsage, pmc.PagefileUsage  / 1024 ); 
        //printf( "\tPeakPagefileUsage: 0x%08X - %ukb\n", pmc.PeakPagefileUsage, pmc.PeakPagefileUsage / 1024 );

        cout <<"\t当前使用的内存(WorkingSetSize): "<< pmc.WorkingSetSize / 1024 << "kb\n";
        cout <<"\t峰值使用的内存(PeakWorkingSetSize): "<< pmc.PeakWorkingSetSize / 1024 << "kb\n";
        cout <<"\t当前使用的页面文件(PagefileUsage): "<< pmc.PagefileUsage / 1024 << "kb\n";
        cout <<"\t峰值使用的页面文件(PeakPagefileUsage): "<< pmc.PeakPagefileUsage / 1024 << "kb\n";
        
        // printf( "\tQuotaPeakPagedPoolUsage: 0x%08X - %u\n", 
        //    pmc.QuotaPeakPagedPoolUsage ,  pmc.QuotaPeakPagedPoolUsage / 1024);
        // printf( "\tQuotaPagedPoolUsage: 0x%08X - %u\n", pmc.QuotaPagedPoolUsage, 
        //    pmc.QuotaPagedPoolUsage / 1024);
        // printf( "\tQuotaPeakNonPagedPoolUsage: 0x%08X - %u\n", 
        //    pmc.QuotaPeakNonPagedPoolUsage,pmc.QuotaPeakNonPagedPoolUsage / 1024 );
        // printf( "\tQuotaNonPagedPoolUsage: 0x%08X - %u\n",pmc.QuotaNonPagedPoolUsage , 
        //    pmc.QuotaNonPagedPoolUsage / 1024);

        //printf( "\tcb: 0x%08X - %u\n", pmc.cb , pmc.cb / 1024);         
    }


    
}

int main( void )
{

    vector<int> a(1e8,10);
    PrintCurrentProcessMemoryInfo();
    return 0;
}