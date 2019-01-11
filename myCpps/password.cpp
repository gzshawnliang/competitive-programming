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

ifstream fin("password.in");
ofstream fout("password.out");

int main()
{
    int total;
    fin >> total;
    for (int i = 1; i <= total; ++i)
    {
        int k;
        fin >> k;

        vector<vector<char>> list0(6,vector<char>(5));
        for (int y = 0; y <= 5; ++y)
        {
            for (int x = 0; x <= 4; ++x)
            {
                fin >> list0[y][x];
            }
        }

        vector<vector<char>> list1(6,vector<char>(5));
        for (int y = 0; y <= 5; ++y)
        {
            for (int x = 0; x <= 4; ++x)
            {
                fin >> list1[y][x];
            }
        }

        vector<set<char>> repeats(5);
        for (int x = 0; x <= 4; ++x)
        {
            vector<bool> dp(26,false);
            for (int y = 0; y <= 5; ++y)
            {
                dp[list0[y][x] - 'A'] = true;
            }
            for (int y = 0; y <= 5; ++y)
            {
                if (dp[list1[y][x] - 'A'] == true)
                {
                    repeats[x].insert(list1[y][x]);
                }
            }
        }

        vector<int> nums;
        nums.push_back(1);
        for (int x = 4; x >= 0; --x)
        {
            nums.push_back(nums.back() * repeats[x].size());
        }
        if (nums.back() * repeats[0].size() < k)
        {
            fout << "NO\n";
        }
        else
        {
            int left = k - 1;
            for (int i = 4; i >= 0; --i)
            {
                if (repeats[4 - i].size() == 1)
                {
                    fout << *(repeats[4 - i].begin());
                    left %= nums[i];
                    continue;
                }
                else if (left / nums[i] >= repeats[4 - i].size())
                {
                    fout << "NO";
                    break;
                }
                auto it = repeats[4 - i].begin();
                advance(it, left / nums[i]);
                char nowChar = *it;
                fout << nowChar;
                left %= nums[i];
            }
            fout << '\n';
        }
    }

    return 0;
}