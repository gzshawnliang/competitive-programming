/***********************************************************
 * @����:		HDU 1466 ����ֱ�ߵĽ�����(dp)
 * @����:		Shawn 
 * @����ʱ��: 2017-11-14 20:37:35 
 * @�޸���:   Shawn 
 * @�޸�ʱ��: 2017-11-14 20:37:35 
 * @��ע:		����ƽ����n��ֱ��ȫ���Ľ�����
 * @��Ŀ��Դ�� http://acm.hdu.edu.cn/showproblem.php?pid=1466
***********************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("line.in");
    ofstream fout("line.out");

    int totalLine;
    fin >> totalLine;
    int max_count = totalLine * (totalLine - 1) / 2 + 2;
    vector<vector<bool> > dp(totalLine + 1, vector<bool>(max_count, false));

    dp[1][0] = true;

    for (int i = 2; i <= totalLine; ++i)
    {
        dp[i][0] = true;
        for (int j = 1; j < i; ++j)
        {
            for (int l = 0; l <= max_count - 1; ++l)
            {
                if (dp[j][l] == true)
                {
                    int result = (i - j) * j + l;
                    if (result >= max_count - 1)
                    {
                        continue;
                    }
                    else
                    {
                        dp[i][(i - j) * j + l] = true;
                    }
                    // cout << "ok : " << j << "    " << (i - j) * j + l << endl;
                }
            }
        }
    }

    for (int i = 0; i <= max_count - 1; ++i)
    {
        if (i == 0)
        {
            fout << 0;
        }
        else if (dp[totalLine][i] == true)
        {
            fout << " " << i;
        }
    }

    fout << endl;

    return 0;
}