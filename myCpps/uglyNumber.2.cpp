/***********************************************************
 * @名称:		UVA 136 - Ugly Numbers  
 * @作者:		Thomas 
 * @创建时间: 2017-12-07 11:35:48 
 * @修改人:   Thomas 
 * @修改时间: 2017-12-07 11:35:48 
 * @备注:		
 * 1.set保存唯一并排好序的Ugly Number
 * 2.使用迭代器遍历set
 * 3.注意输出结果测试
 * 4.第1500个Ugly Number使用long存储足够\
 * 5.正确答案：The 1500'th ugly number is 859963392.
 * @题目来源： https://uva.onlinejudge.org/external/1/136.pdf
***********************************************************/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //使用set存储Ugly Number
    set<long> uglyNumberSet;

    //1是Ugly Number初始值
    uglyNumberSet.insert(1);

    //输出测试结果
    ofstream fout("uglyNumber2.out");

    //计算循环的次数
    int loopCount = 0;

    //当前位置的值
    long currValue = 0;

    //遍历set：当前位置,从第一个开始循环到最后
    //C++11可使用auto
    //C++98使用set<long>::iterator
    for (auto currPos = uglyNumberSet.begin(); currPos != uglyNumberSet.end(); ++currPos)
    {
        //取出当前位置的值
        currValue = *currPos;
        fout << currValue << "\n";
        
        //循环计数
        ++loopCount;

        //循环到达1500次之后退出循环，否则会永远循环下去。因为set不断的扩大，永远到不了end
        if (loopCount == 1500)
        {
            break;
        }

        //当前位置的值乘2,3,5计算Ugly Number，并存储到set
        uglyNumberSet.insert(currValue * 2);
        uglyNumberSet.insert(currValue * 3);
        uglyNumberSet.insert(currValue * 5);
    }

    //当前位置的值就是第1500个ugly number
    cout << "The 1500'th ugly number is " << currValue << ".\n";

    return 0;
}