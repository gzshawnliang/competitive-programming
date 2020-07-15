#include <bits/stdc++.h>

using namespace std;

//ifstream fin("lis.in");
//ofstream fout("lis.out");

/* 正常LIS DP 算法
时间复杂度为O(n^2)。
 */

int lengthOfLISDp(vector<int> & nums)
{
    int len = nums.size();

    if (len == 0)
        return 0;

    vector<int> length(len, 1);

    int ans = 1;
    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                length[i] = max(length[i], length[j] + 1);
            }
        }
        ans = max(ans, length[i]);
    }
    return ans;
}

/*Sweep Line 算法
该算法主要是维护了一个已经访问过的最长的递增序列，当新的数来临时，
找到序列中第一个比该数大的数进行替换，如果都比该数小，则将该数放
到递增子序列的末尾，递增子序列长度加一。所以外层遍历时间复杂度是
O(n),而由于递增子序列已经递增有序，所以找到第一个比该数大的数可
以用二分查找，时间复杂度是 O(log(n))
*/
int lengthOfLISLineSweep(vector<int> & nums)
{
    int len = nums.size();

    if (len == 0)
        return 0;

    vector<int> result(len);

    int ans = 0;
    for (int x : nums)
    {
        int i = 0, j = ans;
        while (i != j)
        {
            int m = (i + j) / 2;
            if (result[m] < x)
            {
                i = m + 1;
            }
            else
            {
                j = m;
            }
        }

        result[i] = x;
        if (i == ans)
        {
            ++ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> test{6, 2, 5, 1, 7, 4, 8, 3};
    // vector<vector<int>> dp;
    // int i =dp.at(0).at(0);

    cout << lengthOfLISDp(test) << '\n';
    cout << lengthOfLISLineSweep(test) << '\n';

    return 0;
}
