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

using namespace std;

ifstream fin("histoeryGrading.in");
ofstream fout("histoeryGrading.out");

vector<int> turn(vector<int> in)
{
    int size = in.size();
    vector<int> ans(size);
    for (int i = 0; i <= size - 1; ++i)
    {
        ans[in[i] - 1] = i + 1;
    }

    return ans;
}

int main()
{
    int lastIn = -1;
    fin >> lastIn;

    while (true)
    {
        int n = lastIn;

        if (n == -1)
        {
            break;
        }

        vector<int> correct(n);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> correct[i];
        }

        correct = turn(correct);

        vector<int> compare(n + 1);
        for (int i = 0; i <= n - 1; ++i)
        {
            compare[correct[i]] = i;
        }

        string useless;
        getline(fin, useless);
        while (true)
        {
            string temp0 = "";
            vector<int> a;
            getline(fin, temp0);

            int size0 = temp0.size();

            if (size0 <= 2)
            {
                if (temp0 == "")
                {
                    lastIn = -1;
                }
                else
                {
                    lastIn = stoi(temp0);
                }

                break;
            }
            else
            {
                string temp1 = "";
                for (int i = 0; i <= size0 - 1; ++i)
                {
                    if (temp0[i] == ' ')
                    {
                        if (temp1 != "")
                        {
                            a.push_back(stoi(temp1));
                            temp1 = "";
                        }
                    }
                    else
                    {
                        temp1 += temp0[i];
                    }
                }

                if (temp1 != "")
                {
                    a.push_back(stoi(temp1));
                }

                a = turn(a);

                vector<int> dp(n);
                for (int i = 0; i <= n - 1; ++i)
                {
                    dp[i] = 1;
                    for (int j = 0; j <= i - 1; ++j)
                    {
                        if (compare[a[j]] < compare[a[i]])
                        {
                            dp[i] = max(dp[i], dp[j] + 1);
                        }
                    }
                }

                auto it = max_element(dp.begin(), dp.end());

                fout << *it << '\n';
            }
        }    
    }

    return 0;
}