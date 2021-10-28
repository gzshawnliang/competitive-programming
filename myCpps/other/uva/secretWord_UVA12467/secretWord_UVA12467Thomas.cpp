#include <bits/stdc++.h>

using namespace std;

ifstream fin("secretWord_UVA12467Shawn.in");
ofstream fout("secretWord_UVA12467Shawn.out");


class KMP
{
  private:
    string P;
    vector<int> next;   //next[j]表示当P[j] != T[i] 时候，j要回到那个位置(长度为j的字符串最长公共前后缀的值),也就是前缀和后缀公共部分的最大长度
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

    bool kmpIsExist(const string & T)
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
                return true;
                j = next[j];        //重新设置j，为下次寻找匹配做准备
            }
        }
        return false;
    }

    bool kmpIsExist(const string & T,const string & P)
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
    int tcc; fin >> tcc;
    for (int c = 1; c <= tcc; ++c)
    {
        string s; fin >> s;
        int sizeS = s.size();

        int l = 1, r = sizeS;
        while (l <= r)
        {
            int m = (l + r) / 2;

            string t = s.substr(0, m); 
            reverse(t.begin(), t.end());
            int sizeT = t.size();
            KMP kmp;
            bool flag = kmp.kmpIsExist(s,t);
            if (flag == true)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        string ans = s.substr(0, l - 1);
        reverse(ans.begin(), ans.end());

        fout << ans << '\n';
    }

    return 0;
}

