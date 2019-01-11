#include <algorithm>
#include <fstream>
#include <functional> //Ϊ��ʹ�����ȶ��е�greater
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
         * ��������
        *****************************************/
        int total = 0;
        cin >> total;
        if (total == 0)
        {
            break;
        }

        //�������ȶ��У�С�������ȳ���
        priority_queue<int, vector<int>, greater<int>> numbersQueue;
        for (int i = 0; i <= total - 1; ++i)
        {
            int temp;
            cin >> temp;
            numbersQueue.push(temp);
        }

        /*****************************************
         * ��ʼ�ӷ�����
        *****************************************/
        int totalCost = 0;
        while (true)
        {
            int num1 = numbersQueue.top();
            numbersQueue.pop();

            if (numbersQueue.empty())
            {
                //�ж����ֻ��һ�������˳�
                break;
            }

            int num2 = numbersQueue.top();
            numbersQueue.pop();

            //��������ӵ�cost
            int currCost = num1 + num2;

            //������Թ���
            //cout << num1 << "+" << num2 << "=" << currCost << "\n";

            //�ۼ�cost
            totalCost += currCost;

            if (numbersQueue.empty())
            {
                break;
            }
            else
            {
                //ʹ��currCost���num1��num2
                numbersQueue.push(currCost);
            }
        }
        cout << totalCost << "\n";
    }

    return 0;
}