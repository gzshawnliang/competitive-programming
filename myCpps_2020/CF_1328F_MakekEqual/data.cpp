// #include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
// #include "MyRandom.h"

// using namespace std;

// int main()
// {
//     ofstream fout;            //note:文件流
//     random rdNum;             //note:随机数

//         fout.open("CF_1328F_MakekEqual.in");

//         //***************************
//         //在此处写入测试数据
//         //***************************
//         int n = rdNum.GetRand(1, 2e1);
//         int k = rdNum.GetRand(1, 1e1);
//         if(k>n)
//             swap(k,n);

//         fout << n << " " << k << "\n";

//         for (int i = 1; i <= n ; ++i)
//         {            
//             fout << rdNum.GetRand(1, 1e1) << " ";
//         }
//         fout << "\n";

//         fout.close();

//     return 0;
// }


#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

int main()
{
    const int FileCount = 100; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open(to_string(fileId) + ".in");

        //***************************
        //在此处写入测试数据
        //***************************
        int n = rdNum.GetRand(1, 3e1);
        int k = rdNum.GetRand(1, 2e1);
        if(k>n)
            swap(k,n);

        fout << n << " " << k << "\n";

        for (int i = 1; i <= n ; ++i)
        {            
            fout << rdNum.GetRand(1, 1e1) << " ";
        }
        fout << "\n";


        fout.close();
    }

    return 0;
}
