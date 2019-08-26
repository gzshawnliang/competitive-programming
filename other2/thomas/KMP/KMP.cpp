#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100010;

/**
 * 暴力（朴素）计算字符串匹配
 * @param  {string} T     : 【输入】源字符串
 * @param  {string} P     : 【输入】匹配模式
 * @return {vector<int>}  : 【返回】匹配的起始位置，字符串索引从0开始，如果没有匹配，返回空的数组
 */
vector<int> match(const string & T, const string & P)
{
    vector<int> v;
    int n = T.length();
    int m = P.length();
    for (int i = 0; i + m <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (T[i + j] != P[j])
                break;

            if (j == m - 1)
                v.push_back(i);
        }
    }
    return v;
}

class KMP
{
  private:
    string P;
    vector<int> b;  // b = back table
    int m;          // m = length of P

    void build()
    { // call this before calling kmpSearch()
        int i = 0, j = -1;
        b[0] = -1; // starting values
        while (i < m)
        { // pre-process the pattern string P
            while (j >= 0 && P[i] != P[j])
                j = b[j]; // if different, reset j using b
            
            i++;
            j++;      // if same, advance both pointers
            b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
        }
    } // in the example of P = "SEVENTY SEVEN" above

  public:
    KMP(const string & P1)
    {
        this->P = P1;
        m = P.length();
        b.assign(m+1,0);
        build();
    }
    ~KMP()
    {
        b.clear();
    }

    vector<int> kmpSearch(const string & T)
    {
        int n=T.length();          // n = length of T
        vector<int> v;

        // this is similar as kmpPreprocess(), but on string T
        int i = 0, j = 0; // starting values
        while (i < n)
        { // search through string T
            while (j >= 0 && T[i] != P[j])
                j = b[j]; // if different, reset j using b
            i++;
            j++; // if same, advance both pointers
            if (j == m)
            { // a match found when j == m
                v.push_back(i - j);
                //printf("P is found at index %d in T\n", i - j);
                j = b[j]; // prepare j for the next possible match
            }
        }
        return v;
    }
};

int main()
{
    string T = "AABAACAADAABAABA";
    string P = "AABA";
    vector<int> v = match(T, P);

    cout << "暴力:";
    for (auto a : v)
    {
        cout << " "<< a ;
    }
    //cout << "\n-----------------------\n";
    cout << "\n";

    v.clear();
    KMP kmp1(P);
    v = kmp1.kmpSearch(T);
    cout << "KMP:";
    for (auto a : v)
    {
        cout  << " "<< a ;
    }

    return 0;
}
