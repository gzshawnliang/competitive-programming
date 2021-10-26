/***********************************************************
 * @名称:		快速cin
 * @作者:		Shawn 
 * @创建时间: 2017-11-21 21:51:55 
 * @修改人:   Shawn 
 * @修改时间: 2017-11-21 21:51:55 
 * @备注:		
 * @题目来源： 
 * http://www.hankcs.com/program/cpp/cin-tie-with-sync_with_stdio-acceleration-input-and-output.html
 * https://heavywatal.github.io/cxx/speed.html
 * http://chino.taipei/note-2016-0311C-的輸出入cin-cout和scanf-printf誰比較快？/
***********************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    clock_t tStart = clock();

    //1.601s
    // for(int i = 0; i < (int)1e7; i++){
    //     printf("%d\n",rand());
    // }

    //2.849s
    // std::ios_base::sync_with_stdio(false);            //关闭scanf/printf同步
    // std::cin.tie(NULL);                             //關閉cin/cout同步
    // for(int i = 0; i < (int)1e7; i++){
    //     cout <<rand()<< '\n';
    // }

    //关闭scanf/printf同步,
    //这个函数是一个“是否兼容stdio”的开关，
    //C++为了兼容C，保证程序在使用了std::printf和std::cout的时候不发生混乱，将输出流绑到了一起。
    ios_base::sync_with_stdio(false);       

    
    std::cin.tie(NULL);                     //关闭cin/cout同步
    
    freopen("bigdata.in2", "r", stdin);      
    freopen("bigdata.out", "w", stdout);     

    //7.869s
    int a = 0;
    for(int i = 0; i < (int)1e7; ++i){
        cin>>a;
        //scanf("%d\n",&a);
        //cout << a + 1 << '\n';
    }


    //4s
    // int a = 0;
    // for(int i = 0; i < (int)1e7; i++){
    //     scanf("%d\n",&a);
    //     printf("%d\n",a+1); //output a+1;
    // }
    //double totalExecTime=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    //printf("%f\n",totalExecTime);
    // int maxRow=0;
    // int a=0,b=0;
    //cin >>maxRow >> a >>b;

    // for(int i=0;i<=maxRow-1;++i) 
    // {
    //     int a1=0,a2=0;
    //     //scanf("%d\n",&a1,&a2);
    //     scanf("%d%d",&a1,&a2);
    //     printf("%d %d\n",a1,a2);
    //     //cin >> a1 >> a2;
    //     //cout << a1 << " " << a2 << '\n';
    // }
	// cout << maxRow << '\n';

    //cout << (double)(clock() - tStart)/CLOCKS_PER_SEC <<"s"<< endl;
    //measure-command {}
    
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
