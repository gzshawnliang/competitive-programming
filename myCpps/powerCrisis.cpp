/***********************************************************
 * @����:		151 - Power Crisis (AC)
 * @����:		Shawn 
 * @����ʱ��: 2017-11-19 20:13:16 
 * @�޸���:   Shawn 
 * @�޸�ʱ��: 2017-11-19 20:13:16 
 * @��ע:		Լɪ������
 * @��Ŀ��Դ�� https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=87
***********************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //ifstream fin("powerCrisis.in");
    //ofstream fout("powerCrisis.out");

    while (true)
    {
        int total;
        cin >> total;

        if (total == 0)
        {
            break;
        }

        int m = 0;
        while (true)
        {
            ++m;
            int nowPos = 0;
            vector<bool> a(total, true);
            bool ok = true;
            for (int i = total; i >= 2; --i)
            {
                //fout << nowPos + 1 << " ";
                a[nowPos] = false;
                if (nowPos == 12)
                {
                    ok = false;
                    break;
                }

                int myFind = 0, j = nowPos;
                while (true)
                {
                    j = (j + 1) % total;

                    if (a[j] == true)
                    {
                        ++myFind;
                    }
                    if (myFind == m)
                    {
                        nowPos = j;
                        break;
                    }
                }
            }

            if (ok == true)
            {
                break;
            }
        }

        cout << m << endl;
    }

    return 0;
}