/***********************************************************
 * @����:		11988 - Broken Keyboard (a.k.a. Beiju Text)
 * @����:		Shawn 
 * @����ʱ��: 2017-12-16 19:58:01 
 * @�޸���:   Shawn 
 * @�޸�ʱ��: 2017-12-16 19:58:01 
 * @��ע:		������ϰ�� -- ���� insert(a.begin(), sth.) �� puhs_front ������
 * @��Ŀ��Դ�� https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3139
***********************************************************/
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("beijuText.in");
    ofstream fout("beijuText.out");

    while (!(fin.eof()))
    {
        string temp = "";
        getline(fin, temp);
        if (temp == "")
        {
            break;
        }

        list<char> out;
        auto it = out.end();
        int size = temp.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            if (temp[i] == '[')
            {
                it = out.begin();
            }
            else if (temp[i] == ']')
            {
                it = out.end();
            }
            else
            {
                out.insert(it, temp[i]);
            }
        }

        for (auto i = out.begin(); i != out.end(); ++i)
        {
            fout << *i;
        }
        fout << '\n';
    }

    return 0;
}