#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

ifstream fin("criticalLinks_UVA796.in");
ofstream fout("criticalLinks_UVA796.out");

bool check(int p, int q, int n, vector<vector<bool>> & a)
{
    stack<int> s; s.push(p);
    vector<bool> visit(n + 1, false);
    while (!(s.empty()))
    {
        int t = s.top();
        bool _find = false;
        for (int i = 0; i <= n - 1; ++i)
        {
            if (t == p && i == q)
            {
                // do nothing
                continue;
            }
            else if (a[t][i] == true && visit[i] == false)
            {
                if (i == q)
                {
                    return true;
                }

                visit[i] = true;
                _find = true;
                s.push(i);
            }
        }

        if (_find == false)
        {
            s.pop();
        }
    }

    return false;
}

int main()
{
    bool tF = true;
    while (true)
    {
        if (tF == false)
        {
            fout << '\n';
        }
        tF = true;

        int n = -1;
        fin >> n;
        if (n == 0)
        {
            fout << "0 critical links\n\n";
            continue;
        }
        else if (n == -1)
        {
            break;
        }

        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));

        string useless;
        getline(fin, useless);

        for (int c = 1; c <= n; ++c)
        {
            string in;
            getline(fin, in);
            int size0 = in.size(), first = -1;
            string temp = "";
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (in[i] == ' ')
                {
                    if (first == -1)
                    {
                        first = stoi(temp);
                        ++i;
                        while (in[i] != ' ')
                        {
                            ++i;
                        }
                    }
                    else
                    {
                        int j = stoi(temp);
                        a[first][j] = true;
                        a[j][first] = true;
                    }

                    temp = "";
                }
                else
                {
                    temp += in[i];
                }
            }

            if (temp != "")
            {
                int j = stoi(temp);
                a[first][j] = true;
                a[j][first] = true;
            }
        }

        int total = 0;
        vector<string> out;
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                if (a[i][j] == true)
                {
                    if (check(i, j, n, a) == false)
                    {
                        ++total;
                        string temp = to_string(i) + " - " + to_string(j);
                        out.push_back(temp);
                    }
                }
            }
        }

        fout << total << " critical links\n";
        for (int i = 0; i <= total - 1; ++i)
        {
            fout << out[i] << '\n';
        }

        fout << '\n';
    }

    return 0;
}