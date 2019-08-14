#include <bits/stdc++.h>

using namespace std;

//ifstream fin("LCS.in");
//ofstream fout("LCS.out");

int LCSRecursion(string & word1, string & word2, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    else if (word1[i - 1] == word2[j - 1])
    {
        return LCSRecursion(word1, word2, i - 1, j - 1) + 1;
    }
    else
    {

        return max(LCSRecursion(word1, word2, i - 1, j),
                   LCSRecursion(word1, word2, i, j - 1));
    }
}

int LCSDp(string & word1, string & word2, vector<vector<string>> & path)
{
    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    path.resize(n + 1, vector<string>(m + 1));

    // 初始化空字符串的情况
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 0;
    }

    for (int j = 1; j <= m; ++j)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = "↖";
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (dp[i - 1][j] >= dp[i][j - 1])
                {
                    path[i][j] = "↑";
                }
                else
                {
                    path[i][j] = "←";
                }
            }
        }
    }
    return dp[n][m];
}

void printLCS(vector<vector<string>> & path, string & word1, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (path[i][j] == "↖")
    {
        printLCS(path, word1, i - 1, j - 1);
        cout << word1[i - 1] << " ";
    }
    else if (path[i][j] == "↑")
    {
        printLCS(path, word1, i - 1, j);
    }
    else
    {
        printLCS(path, word1, i, j - 1);
    }
}

int main()
{
    string x = "ABCBDAB";
    string y = "BDCABA";
    vector<vector<string>> path;

    cout << setw(14) << "X: " << x << '\n';
    cout << setw(14) << "Y: " << y << '\n';
    cout << setw(14) << "LCSRecursion: " << LCSRecursion(x, y, x.length(), y.length()) << '\n';
    cout << setw(14) << "LCSDp: " << LCSDp(x, y, path) << '\n';

    cout << setw(14) << "LCS: ";
    printLCS(path, x, x.length(), y.length());


    //输出过程
    cout << "\n--------------------\n";
    
    cout << "  ";
    for (auto k:y)
        cout << k << " ";

    int k=0;
    for (auto i:path)
    {
        int l=0;
        if(k>0)
            cout << x[k-1] << " ";
        for (auto j:i)
        {
            if(l>0)
                cout << j << " ";

            ++l;
        }
        cout << '\n';
        ++k;
    }
    cout << "--------------------\n";
    cout << "完成" <<'\n';
    return 0;
}
