#include <algorithm>
#include <fstream>
#include <functional> //为了使用优先队列的greater
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("addAll.in", "r", stdin);
        freopen("addAll.out", "w", stdout);
        ios::sync_with_stdio(false);
    #endif

    while (true)
    {
        /*****************************************
         * 输入数据
        *****************************************/
        int total = 0;
        cin >> total;
        if (total == 0)
        {
            break;
        }

        //放入优先队列，小的数优先出来
        priority_queue<int, vector<int>, greater<int>> numbersQueue;
        for (int i = 0; i <= total - 1; ++i)
        {
            int temp;
            cin >> temp;
            numbersQueue.push(temp);
        }

        /*****************************************
         * 开始加法运算
        *****************************************/
        int totalCost = 0;
        while (true)
        {
            int num1 = numbersQueue.top();
            numbersQueue.pop();

            if (numbersQueue.empty())
            {
                //判断如果只有一个数就退出
                break;
            }

            int num2 = numbersQueue.top();
            numbersQueue.pop();

            //两个数相加的cost
            int currCost = num1 + num2;

            //输出测试过程
            //cout << num1 << "+" << num2 << "=" << currCost << "\n";

            //累计cost
            totalCost += currCost;

            if (numbersQueue.empty())
            {
                break;
            }
            else
            {
                //使用currCost替代num1，num2
                numbersQueue.push(currCost);
            }
        }
        cout << totalCost << "\n";
    }

    return 0;
}