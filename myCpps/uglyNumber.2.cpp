/***********************************************************
 * @����:		UVA 136 - Ugly Numbers  
 * @���Shawnomas 
 * @����ʱ��: 2017-12-07 11:35:48 
 * @�޸��Shawnhomas 
 * @�޸�ʱ��: 2017-12-07 11:35:48 
 * @��ע:		
 * 1.set����Ψһ���ź����Ugly Number
 * 2.ʹ�õ���������set
 * 3.ע������������
 * 4.��1500��Ugly Numberʹ��long�洢�㹻\
 * 5.��ȷ�𰸣�The 1500'th ugly number is 859963392.
 * @��Ŀ��Դ�� https://uva.onlinejudge.org/external/1/136.pdf
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
    //ʹ��set�洢Ugly Number
    set<long> uglyNumberSet;

    //1��Ugly Number��ʼֵ
    uglyNumberSet.insert(1);

    //������Խ��
    ofstream fout("uglyNumber2.out");

    //����ѭ���Ĵ���
    int loopCount = 0;

    //��ǰλ�õ�ֵ
    long currValue = 0;

    //����set����ǰλ��,�ӵ�һ����ʼѭ�������
    //C++11��ʹ��auto
    //C++98ʹ��set<long>::iterator
    for (auto currPos = uglyNumberSet.begin(); currPos != uglyNumberSet.end(); ++currPos)
    {
        //ȡ����ǰλ�õ�ֵ
        currValue = *currPos;
        fout << currValue << "\n";
        
        //ѭ������
        ++loopCount;

        //ѭ������1500��֮���˳�ѭ�����������Զѭ����ȥ����Ϊset���ϵ�������Զ������end
        if (loopCount == 1500)
        {
            break;
        }

        //��ǰλ�õ�ֵ��2,3,5����Ugly Number�����洢��set
        uglyNumberSet.insert(currValue * 2);
        uglyNumberSet.insert(currValue * 3);
        uglyNumberSet.insert(currValue * 5);
    }

    //��ǰλ�õ�ֵ���ǵ�1500��ugly number
    cout << "The 1500'th ugly number is " << currValue << ".\n";

    return 0;
}