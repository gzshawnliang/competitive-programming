#include <bits/stdc++.h>  //includes everything, supported in CF, usaco, not POJ
#include "MyRandom.h"

using namespace std;

string GenRandString(random & rdNum)
{
    int len = rdNum.GetRand(2, 20);
    string s = "";
    for (int j = 0; j <= len - 1; ++j)
    {
        int n = rdNum.GetRand(0, 25);
        char a = 'a' + n;
        s.push_back(a);
    }
    return s;
}

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;            //note:文件流
    random rdNum;             //note:随机数

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        fout.open("Trie.in");

        //***************************
        //在此处写入测试数据
        //***************************
        int testCase = (int)1e6;
        fout << testCase <<'\n';

        int queryCase = testCase/30;
        int qc=queryCase;
        vector<int> rd1;
        while (qc--)
        {
           rd1.push_back(rdNum.GetRand(1,testCase));
        }
        
        vector<string> queryString;
        for (int i = 0; i <= testCase - 1; ++i)
        {
            string s=GenRandString(rdNum);
            fout << s << "\n";

            for(int j:rd1)     
            {
                if(i==j)
                {
                    queryString.push_back(s);
                }
            }
        }

        fout << queryString.size() * 2 << '\n';
        for(auto s:queryString)     
        {
            fout << s << "\n";
            fout << GenRandString(rdNum) << "\n";
        }
        fout.close();
    }

    return 0;
}
