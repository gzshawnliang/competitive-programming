#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

class KMPShawn
{
  public:
    vector<int> next;
    string P;
    KMPShawn(string & P)
    {
        this->P = P;
        createNext();
    }

    void createNext()
    {
        int sizeT = P.length();
        next.assign(sizeT, 0);
        int _i = 1, _j = 0;
        next[0] = 0;
        while (_i <= sizeT - 1)
        {
            while (_j > 0 && P[_i] != P[_j])
            {
                if (_j > 0)
                    _j = next[_j - 1];

                if (_j == -1)
                    break;
            }

            if (P[_i] == P[_j])
                next[_i] = _j + 1;

            ++_i;
            ++_j;
        }
    }

    bool KmpExistSearch(string & T)
    {
        int sizeS = T.length();
        int sizeT = P.length();

        int i = 0, j = 0;
        while (i <= sizeS - 1)
        {
            if (T[i] != P[j])
            {
                if (j == 0)
                {
                    ++i;
                }
                else
                {
                    j = next[j - 1];
                }
            }
            else
            {
                if (j == sizeT - 1)
                {
                    return true;
                }
                else
                {
                    ++i;
                    ++j;
                }
            }
        }

        return false;
    }
};

class KMPGood
{
  private:
    string P;
    vector<int> next; //next[j]表示当P[j] != T[i] 时候，j要回到那个位置(长度为j的字符串最长公共前后缀的值)
    int m;            //m = length of P

    void build(const string & P)
    {
        //调用kmpSearch()之前调用此函数

        //初始化变量
        this->P = P;
        m = P.length();
        next.assign(m + 1, 0);

        int j = 0;
        int k = -1;

        next[0] = -1; // 起始值，-1代表移动i
        while (j <= m - 1)
        {
            //使用字符串P预处理数组next
            while (k >= 0 && P[j] != P[k])
                k = next[k]; // 如果不同，使用next数组重设k值,直到相同或-1（开始指针的位置）

            ++j;
            ++k; //如果一样，两个指针都往右移动next[j+1]==k+1
            next[j] = k;
        }
    }

  public:
    KMPGood(const string & P1)
    {
        build(P1);
    }

    KMPGood()
    {
        next.clear();
    }

    ~KMPGood()
    {
        next.clear();
    }

    bool kmpIsExist(const string & T)
    {
        int n = T.length();
        vector<int> v;

        // 类似build，但这次是T字符串
        int i = 0;
        int j = 0; // 匹配的起始值
        while (i <= n - 1)
        {
            //T字符串从头到尾搜寻
            while (j >= 0 && T[i] != P[j])
                j = next[j]; // 在j的位置不同，用next数组重新设置j

            //如果相同，同时移动i,j
            i++;
            j++;
            if (j == m)
            { //j移动到m的位置时，此刻已经是匹配的了匹配位置是i-j
                return true;
                j = next[j]; //重新设置j，为下次寻找匹配做准备
            }
        }
        return false;
    }

    bool kmpIsExist(const string & T, const string & P)
    {
        build(P);
        return kmpIsExist(T);
    }

    vector<int> kmpSearch(const string & T)
    {
        int n = T.length();
        vector<int> v;

        // 类似build，但这次是T字符串
        int i = 0;
        int j = 0; // 匹配的起始值
        while (i <= n - 1)
        {
            //T字符串从头到尾搜寻
            while (j >= 0 && T[i] != P[j])
                j = next[j]; // 在j的位置不同，用next数组重新设置j

            //如果相同，同时移动i,j
            i++;
            j++;
            if (j == m)
            { //j移动到m的位置时，此刻已经是匹配的了匹配位置是i-j
                v.push_back(i - j);
                j = next[j]; //重新设置j，为下次寻找匹配做准备
            }
        }
        return v;
    }

    vector<int> kmpSearch(const string & T, const string & P)
    {
        build(P);
        return kmpSearch(T);
    }
};

int main2()
{
    ofstream fout;  //note:文件流
    ofstream fout2; //note:文件流
    random rdNum;   //note:随机数

    fout.open("kmpTest.out");
    fout2.open("kmpTest2.out");
    vector<string> v = {"bbry", "tbbr"};
    int sCount = 10000000;
    string p = "tbbry";
    KMPGood KMPGood1(p);
    KMPShawn KMPShawn(p);

    while (sCount--)
    {
        string T = "";
        int len = rdNum.GetRand(1, 100);
        while (len--)
        {
            T.push_back('a' + rdNum.GetRand(0, 25));
        }
        bool result1 = KMPGood1.kmpIsExist(T);
        bool result2 = KMPShawn.KmpExistSearch(T);

        if (result1 != result2)
            fout << T << endl;

        if (result1)
            fout2 << T << '\n';
    }

    fout.close();
    fout2.close();

    return 0;
}


int main()
{
    string T="krfxmjtbbbrywsrndqengumtgnbmpvzdsjw";
    string P="tbbry";
    KMPGood KMPGood1(P);
    KMPShawn KMPShawn(P);
    cout << boolalpha  <<"good:" << KMPGood1.kmpIsExist(T) << '\n';
    cout << boolalpha  <<"good:" << KMPShawn.KmpExistSearch(T) << '\n';
    return 0;
}