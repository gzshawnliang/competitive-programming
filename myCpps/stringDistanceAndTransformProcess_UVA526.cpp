#include <bits/stdc++.h>

using namespace std;

ifstream fin("stringDistanceAndTransformProcess_UVA526.in");
ofstream fout("stringDistanceAndTransformProcess_UVA526.out");

const int inf = INT_MAX / 2;

struct node
{
    int operation;
    int pos;
    char ch; // if (pos == 3)

    int lastI;
    int lastJ;
};
node _node(int operation, int pos, char ch, int lastI, int lastJ)
{
    node temp{operation, pos, ch, lastI, lastJ}; return temp;
}

int main()
{
    vector<string> operationNames = 
    {
        "~",
        "Insert",
        "Delete",
        "Replace"
    };

    bool first = true;
    while (true)
    {
        string a = "", b = "";
        getline(fin, a); getline(fin, b);
        if (fin.good() == false) break;
        
        int sizeA = a.size(), sizeB = b.size();

        if (first == true)
        {
            first = false;
        }
        else
        {
            fout << '\n';
        }

        a = ' ' + a; b = ' ' + b;
            vector<vector<int>> dp(sizeA + 1, vector<int>(sizeB + 1, inf)); dp[0][0] = 0;
                vector<vector<int>> posAdd(sizeA + 1, vector<int>(sizeB + 1, 0));
                    node _null{-1, -1, '~', -1, -1};
                    vector<vector<node>> f(sizeA + 1, vector<node>(sizeB + 1, _null)); f[0][0] = _node(0, -1, '~', -1, -1);
                    
        for (int i = 1; i <= sizeA; ++i)
        {
            dp[i][0] = i;
            posAdd[i][0] = -1 * i;
            f[i][0] = _node(2, i, '~', i - 1, 0);
        }

        for (int j = 1; j <= sizeB; ++j)
        {
            dp[0][j] = j;
            posAdd[0][j] = j;
            f[0][j] = _node(1, j, b[j], 0, j - 1);
        }
        
        for (int i = 1; i <= sizeA; ++i)
        {
            for (int j = 1; j <= sizeB; ++j)
            {
                int lastI = - 1, lastJ = - 1;
                if (a[i] == b[j])
                {
                    lastI = i - 1; lastJ = j - 1;

                    dp[i][j] = dp[lastI][lastJ];
                    posAdd[i][j] = posAdd[lastI][lastJ];
                    f[i][j] = _node(0, -1, '~', lastI, lastJ);
                }
                else
                {
                    if (dp[i][j] > dp[i][j - 1] + 1 && j + posAdd[i][j - 1] >= 1)
                    {
                        lastI = i; lastJ = j - 1;

                        dp[i][j] = dp[lastI][lastJ] + 1;
                        posAdd[i][j] = posAdd[lastI][lastJ] + 1;
                        f[i][j] = _node(1, i + 1 + posAdd[lastI][lastJ], b[j], lastI, lastJ);
                    }
                    
                    if (dp[i][j] > dp[i - 1][j] + 1 && i + posAdd[i - 1][j] >= 1)
                    {
                        lastI = i - 1; lastJ = j;

                        dp[i][j] = dp[lastI][lastJ] + 1;
                        posAdd[i][j] = posAdd[lastI][lastJ] - 1;
                        f[i][j] = _node(2, i + posAdd[lastI][lastJ], '~', lastI, lastJ);
                    }

                    if (dp[i][j] > dp[i - 1][j - 1] + 1 && i + posAdd[i - 1][j] >= 1)
                    {
                        lastI = i - 1; lastJ = j - 1;

                        dp[i][j] = dp[lastI][lastJ] + 1;
                        posAdd[i][j] = posAdd[lastI][lastJ];
                        f[i][j] = _node(3, i + posAdd[lastI][lastJ], b[j], lastI, lastJ);
                    }
                }
            }
        }

        fout << dp[sizeA][sizeB] << '\n';

        int nowI = sizeA, nowJ = sizeB;
        vector<string> ans;
        for (int c = dp[sizeA][sizeB]; c >= 1; --c)
        {
            if (f[nowI][nowJ].operation > 0)
            {
                string res;
                res += operationNames[f[nowI][nowJ].operation];
                res += ' ';
                res += to_string(f[nowI][nowJ].pos);

                if (f[nowI][nowJ].operation != 2)
                {
                    res += ',';
                    res += f[nowI][nowJ].ch;
                }

                ans.push_back(res);
            }
            else
            {
                ++c;
            }

            int tempI = nowI;
            nowI = f[nowI][nowJ].lastI; nowJ = f[tempI][nowJ].lastJ;
        }

        for (int i = dp[sizeA][sizeB] - 1; i >= 0; --i)
        {
            fout << dp[sizeA][sizeB] - i << ' ' << ans[i] << '\n';
        }
    }

    return 0;
}
