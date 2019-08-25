#include <bits/stdc++.h>

using namespace std;

ifstream fin("freeParentheses_UVA1238.in");
ofstream fout("freeParentheses_UVA1238.out");

const int N = 3000;

void solve(int i, int openC, int sum, vector<int> & isPositive, vector<int> & a, set<int> & res, vector<vector<vector<int>>> & dp)
{
    int n = a.size();

    if (dp[i][openC][sum + N]) return;
    
    if (i == n - 1)
    {
        res.insert(sum);
        return;
    }
    
    int add = a[i + 1] * isPositive[i + 1] * ((openC % 2 == 0) ? 1 : -1);

    if (isPositive[i + 1] == -1) solve(i + 1, openC + 1, sum + add, isPositive, a, res, dp);
    if (openC > 0)               solve(i + 1, openC - 1, sum + add, isPositive, a, res, dp);
                                 solve(i + 1, openC,     sum + add, isPositive, a, res, dp);

    dp[i][openC][sum + N] = 1;
}

int main()
{
    while (true)
    {
        string s = ""; getline(fin, s);
        if (s == "") break;

        s = "+ " + s;

        vector<int> isPositive, a;
        istringstream intputS(s);
        while (true)
        {
            char ch = '_'; string n_s = ""; intputS >> ch >> n_s;
            if (n_s == "") break;

            if (ch == '+') isPositive.push_back(1);
            else isPositive.push_back(-1);
            
            if (ch == '+') a.push_back(stoi(n_s));
            else a.push_back(stoi(n_s));
        }

        int n = a.size();
        set<int> res;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(N * 2 + 1, 0)));
        solve(0, 0, a[0], isPositive, a, res, dp);

        fout << res.size() << '\n';
    }

    return 0;
}
