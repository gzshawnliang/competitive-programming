#include <bits/stdc++.h>

using namespace std;

struct suffixInfo
{
    int id;
    string suffixStr;
    bool operator<(const suffixInfo & b)
    {
        return suffixStr < b.suffixStr;
    }
};

void printVector(const vector<int> & a)
{
    for (auto i : a)
        cout << i << " ";
    cout << "\n";
}

void createSuffixArray(const string & s, vector<int> & SA, vector<int> & rank, vector<int> & height)
{
    vector<suffixInfo> suffixVector(s.length());

    int len = s.length();

    for (int i = 0; i <= len - 1; ++i)
    {
        suffixVector[i].suffixStr = s.substr(i, len - i);
        suffixVector[i].id = i;
    }
    sort(suffixVector.begin(), suffixVector.end());

    height[0] = 0;
    for (int i = 0; i <= len - 1; ++i)
    {
        SA[i] = suffixVector[i].id;
        rank[SA[i]] = i;
    }

    //设置height数组
    int k = 0;
    for (int i = 0; i <= len - 1; ++i)
    {
        if (k > 0)
            --k;
        if (rank[i] == 0)
        {
            height[0] = 0;
        }
        else
        {
            int j = SA[rank[i] - 1];
            while (s[i + k] == s[j + k])
                ++k;
            height[rank[i]] = k;
        }
    }
}

int main()
{
    string s = "BANANA";
    //string s="heheheda";

    vector<int> SA(s.length());     //后缀数组：SA[i]表示第i小的后缀在原串中的起始位置
    vector<int> rank(s.length());   //名次数组：第i原字符串的缀在SA[i]的排名为rank[i]，rank[SA[i]]=i
    vector<int> height(s.length()); //高度数组：是一个一维数组，保存了相邻两个后缀的最长公共前缀（Longest Common Prefix，LCP）长度，height[i]定义为sa[i－1]和sa[i]的最长公共前缀（Longest Common Prefix, LCP）长度

    createSuffixArray(s, SA, rank, height);
    cout << std::left;
    cout << setw(8) << "SA: ";
    printVector(SA);

    cout << setw(8) << "rank: ";
    printVector(rank);

    cout << setw(8) << "height: ";
    printVector(height);

    return 0;
}
