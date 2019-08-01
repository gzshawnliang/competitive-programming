/***********************************************************
 * @名称:		快速cin/cout
 * @作者:		Thomas 
 * @创建时间: 2017-11-21 21:51:55 
 * @修改人:   Thomas 
 * @修改时间: 2017-11-21 21:51:55 
 * @备注:		
 * @题目来源： 
 * http://www.hankcs.com/program/cpp/cin-tie-with-sync_with_stdio-acceleration-input-and-output.html
 * https://heavywatal.github.io/cxx/speed.html
 * http://chino.taipei/note-2016-0311C-的輸出入cin-cout和scanf-printf誰比較快？/
***********************************************************/
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    //关闭scanf/printf同步,
    //这个函数是一个“是否兼容stdio”的开关，
    //C++为了兼容C，保证程序在使用了std::printf
    //和std::cout的时候不发生混乱，将输出流绑到了一起。
    ios_base::sync_with_stdio(false);       

    //在默认的情况下cin绑定的是cout，
    //每次执行 << 操作符的时候都要调用flush，这样会增加IO负担。
    //以下关闭cin/cout同步
    std::cin.tie(NULL);                     
    
    freopen("bigdata.in2", "r", stdin);      
    freopen("bigdata.out", "w", stdout);     

    //数据集超大造成 cin TLE的情况
    int a = 0;
    for(int i = 0; i < (int)1e7; ++i){
        cin>>a;
    }

    //完成一定要执行flush刷新缓存
    cout.flush();

    //关闭输入输出流定向
    fclose(stdin);
    fclose(stdout);
    return 0;
}
