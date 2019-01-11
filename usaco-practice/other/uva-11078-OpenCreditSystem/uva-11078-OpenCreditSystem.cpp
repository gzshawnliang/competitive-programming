#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
#include <string>
#include <cmath>
#include <cstdlib>      //srand
#include <ctime>        //time

#include <fstream>        

#include <Windows.h>        

using namespace std;

#define fast ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);

ofstream fout;
ifstream fin;

//要取得[a,b]的随机整数
int getRand(int a,int b)
{
    int c=b-a+1;
    return rand() % c + a;
}

void solve1()
{
    int T=0;
    fin >> T;
    while(T--)
    {
        vector<int> data;
        int n=0;
        fin >>n;
        if(n>0)
        {
            while(n--)
            {
                int temp;
                fin >> temp;
                data.push_back(temp);
            }
        }
        int count = data.size();
        int ans=data[0]-data[1];
        for(size_t i = 0; i <= count-1; ++i)
        {
            for(size_t j=i+1;j<=count-1;++j)
            {
                ans=max(ans,data[i]-data[j]);
            }
        }
        fout << ans << "\n";
    }
}

void solve2()
{
    int T=0;
    fin >> T;
    while(T--)
    {
        vector<int> data;
        int n=0;
        fin >>n;
        if(n>0)
        {
            while(n--)
            {
                int temp;
                fin >> temp;
                data.push_back(temp);
            }
        }
        int count = data.size();
        int ans=data[0] - data[1];
        int MAXAi=data[0];
        for(size_t j=1;j<=count-1;++j)
        {
            ans=max(ans,MAXAi-data[j]);
            MAXAi=max(data[j],MAXAi);
        }

        fout << ans << "\n";
    }
}

int main_ok()
{
    freopen("uva-11078-OpenCreditSystem.in", "r", stdin);
    freopen("uva-11078-OpenCreditSystem.out", "w", stdout);
    solve2();
    return 0;
}

int main()
{
    //int s;
    //cin >>s;

    // ios::sync_with_stdio(false); //关闭iostream与cstdio的scanf/printf同步
    // cin.tie(0);                  //關閉cin/cout同步
    
    //fast;

    srand((unsigned)time(NULL));
    
    fin.open("uva-11078-OpenCreditSystem.in");
    fout.open("uva-11078-OpenCreditSystem.out");
    //fin.tie(&fout);
    // fout.tie(0);

    // freopen("uva-11078-OpenCreditSystem.in", "r", stdin);
    // freopen("uva-11078-OpenCreditSystem.out", "w", stdout);

    //随机出现Wrong Answer (missing output file)
    // double a = 1.8;
    // int j=getRand(1,100);
    // if(j>10)
    // {
    //     //freopen("uva-11078-OpenCreditSystem.out", "w", stdout);
    //     fout.open("uva-11078-OpenCreditSystem.out");
    // }
    // else
    // {
    //     Sleep(1800);//暂停  S要大写
    //     return 0;
    // }
    //solve2();

    // //随机出现Wrong Answer (empty output file)
    // int i=getRand(1,100);
    // if(i>10)
    // {
    //     // 随机出现运行时错误
    //     if(getRand(1,100)<10)
    //     {
    //         Sleep(1800);//暂停  S要大写
    //         vector<int> ve1;
    //         ve1[10]=100;
    //     }
    // }   

    solve2();

    //fout.flush();
    
    // fclose(stdin);
    // fclose(stdout);

    //fin.close();
    //fout.close();

    return 0;
}