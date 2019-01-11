/***********************************************************
 * @名称:		dictionary10815 (AC)
 * @作者:		Shawn 
 * @创建时间: 2017-12-03 09:45:11 
 * @修改人:   Shawn 
 * @修改时间: 2017-12-03 09:45:11 
 * @备注:		set练习题
 * @题目来源： https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1756
***********************************************************/
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>


using namespace std;

int main()
{
    ifstream fin("dictionaryLOL.in");
    ofstream fout("dictionary.out");

    set<string> a;

    int length = 0;
    while (!fin.eof())
    {
        string temp;
        fin >> temp;
        if (temp == "")
        {
            break;
        }
        int lengthStr = temp.length();
        string ans = "";
        for (int i = 0; i <= lengthStr - 1; ++i)
        {
            char now = temp[i];
            if (now >= 'a' && now <= 'z')
            {
                ans += now;
            }
            else if (now >= 'A' && now <= 'Z')
            {
                ans += now - 'A' + 'a';
            }
            else if (ans != "")
            {
                ++length;
                a.insert(ans);
                //fout << "ans is " << ans << '\n';
                ans = "";
            }
        }
        if (ans != "")
        {
            ++length;
            a.insert(ans);
        }
    }

    for (auto pos = a.begin(); pos != a.end(); ++pos)
    {
        fout << *(pos) << '\n';
    }

    return 0;
}