#include <bits/stdc++.h>

using namespace std;

struct suffixInfo
{
    int id;
    string suffixStr;
    bool operator<( const suffixInfo & b)
    {
        return suffixStr < b.suffixStr;
    }    
};

void printVector(const vector<int> & a)
{
    for(auto i:a)
        cout << i << " ";
    cout << "\n";
}

void createSuffixArray(const string & s,vector<int> & SA,vector<int> & rank)
{
    vector<suffixInfo> suffixVector(s.length());

    int len = s.length();

    for (int i = 0; i <= len - 1; ++i)
    {
        suffixVector[i].suffixStr=s.substr(i,len-i);
        suffixVector[i].id=i;
    }
    sort(suffixVector.begin(),suffixVector.end());

    for (int i = 0; i <= len - 1; ++i)
    {
        SA[i]=suffixVector[i].id;
        rank[SA[i]] = i;            
    }    

}


int main()
{
    string s="BANANA";
    //string s="heheheda";
    
    vector<int> SA(s.length());         //后缀数组：SA[i]表示第i小的后缀在原串中的起始位置
    vector<int> rank(s.length());       //名次数组：第i原字符串的缀在SA[i]的排名为rank[i]，rank[SA[i]]=i
    vector<int> height(s.length());     //高度数组：是一个一维数组，保存了相邻两个后缀的最长公共前缀（Longest Common Prefix，LCP）长度
    createSuffixArray(s,SA,rank);

    printVector(SA);
    printVector(rank);
        

    return 0;
}
