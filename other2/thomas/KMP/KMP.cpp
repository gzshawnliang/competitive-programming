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
    vector<int> next;  //next[j]表示当P[j] != T[i] 时候，j要回到那个位置
    int m;          // m = length of P

    void build()
    { 
        //调用kmpSearch()之前调用此函数
        int j = 0;
        int k = -1;

        next[0] = -1; // 起始值，-1代表移动i
        while (j <= m-1)
        { // pre-process the pattern string P
            while (k >= 0 && P[j] != P[k])
                k = next[k]; // if different, reset k using b
            
            ++j;
            ++k;      // if same, advance both pointers
            next[j] = k; // observe j = 8, 9, 10, 11, 12 with k = 0, 1, 2, 3, 4
        }
    } // in the example of P = "SEVENTY SEVEN" above

  public:
    KMP(const string & P1)
    {
        this->P = P1;
        m = P.length();
        next.assign(m+1,0);
        build();
    }

    KMP()
    {
        next.clear();
    }

    ~KMP()
    {
        next.clear();
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
                j = next[j]; // if different, reset j using b
            i++;
            j++; // if same, advance both pointers
            if (j == m)
            { // a match found when j == m
                v.push_back(i - j);
                //printf("P is found at index %d in T\n", i - j);
                j = next[j]; // prepare j for the next possible match
            }
        }
        return v;
    }

    vector<int> kmpSearch(const string & T,const string & P)
    {
        this->P = P;
        m = P.length();
        next.assign(m+1,0);
        build();
        return kmpSearch(T);
    }    
};

void printVec(const vector<int> & v)
{
    for (auto a : v)
    {
        cout  << " "<< a ;
    }
    cout << "\n";
}

int main()
{
    string T = "AABAACAADAABAABA";
    string P = "AABA";

    vector<int> v = match(T, P);
    cout << "暴力:";
    printVec(v);

    v.clear();
    KMP kmp1(P);
    v = kmp1.kmpSearch(T);
    cout << "KMP:";
    printVec(v);

    cout << "暴力:";    
    cout << "KMP2:";
    KMP kmp2;
    v = kmp2.kmpSearch(T,P);
    printVec(v);

    return 0;
}
