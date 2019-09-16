#include <bits/stdc++.h>

using namespace std;

ifstream fin("Abnormal89s_UVA11888.in");
ofstream fout("Abnormal89s_UVA11888.out");

class KMP
{
  private:
    string P;
    vector<int> next;   //next[j]表示当P[j] != T[i] 时候，j要回到那个位置(长度为j的字符串最长公共前后缀的值)
    int m;              //m = length of P

    void build(const string & P)
    { 
        //调用kmpSearch()之前调用此函数

        //初始化变量
        this->P = P;
        m = P.length();
        next.assign(m+1,0);

        int j = 0;
        int k = -1;

        next[0] = -1; // 起始值，-1代表移动i
        while (j <= m-1)
        { 
            //使用字符串P预处理数组next
            while (k >= 0 && P[j] != P[k])
                k = next[k]; // 如果不同，使用next数组重设k值,直到相同或-1（开始指针的位置）
            
            ++j;
            ++k;        //如果一样，两个指针都往右移动next[j+1]==k+1
            next[j] = k;
        }
    } 

  public:
    KMP(const string & P1)
    {
        build(P1);
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
        int n = T.length();
        vector<int> v;

        // 类似build，但这次是T字符串
        int i = 0;
        int j = 0; // 匹配的起始值
        while (i <= n-1)
        { 
            //T字符串从头到尾搜寻
            while (j >= 0 && T[i] != P[j])
                j = next[j]; // 在j的位置不同，用next数组重新设置j
            
            //如果相同，同时移动i,j
            i++;
            j++; 
            if (j == m)
            {   //j移动到m的位置时，此刻已经是匹配的了匹配位置是i-j
                v.push_back(i - j);
                j = next[j];        //重新设置j，为下次寻找匹配做准备
            }
        }
        return v;
    }

    vector<int> kmpSearch(const string & T,const string & P)
    {
        build(P);
        return kmpSearch(T);
    }    
};

int main()
{
    int t;
    fin >> t;
    while (t--)
    {
        string s;
        string r;
        fin>>s;
        r=s;
        reverse(r.begin(),r.end());
        KMP kmp1(r);
        string T=s+s;
        vector<int> v = kmp1.kmpSearch(T);
        if(v.size()==0)
        {
            fout << "simple" << '\n';
        }
        else if(v.size()==2 && v[0]==0 && v[1]==s.length())
        {
            fout << "palindrome" << '\n';
        }
        else
        {
            fout << "alindrome" << '\n';
        }
        
    }

    return 0;
}
