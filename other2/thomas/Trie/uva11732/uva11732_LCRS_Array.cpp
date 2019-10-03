#include <bits/stdc++.h>

using namespace std;

const int NIL = -1;

const int MAX_SIZE = 4000 * 1000 + 10;
//const int MAX_SIZE = 1000;              //设置小数组方便调试

class trie
{
    int lSon[MAX_SIZE];             // lSon[i]为第i个结点的左儿子编号
    int rSibling[MAX_SIZE];         // rSibling[i]为第i个结点的右兄弟编号
    char ch[MAX_SIZE];              // ch[i]为第i个结点上的字符
    long long totalSum[MAX_SIZE];   // totalSum[i]为第i个结点为根的子树包含的叶结点总数

    int nodeId;                     // 节点编号，自增长
    long long ans;                  // 答案

    public:

    void init()
    {
        // 初始时只有一个根结点
        nodeId = 0;
        lSon[0] = NIL;
        rSibling[0] = NIL;
        totalSum[0] = 0;
        ans = 0;
    }

    //第一种方法:边建树边统计>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    /**
     * 插入字符串s（包括最后的'\0'），沿途更新totalSum，顺便更新ans
     * @param  {string} s : 插入的字符串s
     */
    void insert(const string & s)
    {
        int len = s.length();
        int father = 0; //父节点节点,从根节点开始

        //需要循环到len的位置:'\0'
        for (int i = 0; i <= len; ++i)
        {
            int curr = NIL; //当前节点

            //从上层节点father第1个儿子开始找，不停的找右兄弟，直到没有右兄弟，rSibling=-1
            for (int j = lSon[father]; j != NIL; j = rSibling[j])
            {
                if (ch[j] == s[i])
                { 
                    // 找到了
                    ans += (totalSum[j] *2);
                    curr = j;
                }
                else
                {
                    ans += totalSum[j];
                }
                
            }
            
            //没找到字符s[i]，新建节点
            if (curr==NIL)
            {
                // 新建结点,进行唯一编号，自增长
                ++nodeId;
                curr = nodeId;

                rSibling[curr] = lSon[father];
                ch[curr] = s[i];
                lSon[curr] = NIL;
                totalSum[curr] = 0;

                lSon[father] = curr; // 替换上层节点的儿子为当前节点,插入到链表的首部
            }

            father = curr;          //当前节点设置成父节点，下次循环使用
            totalSum[father] +=1;  //儿子数量+1
        }
    }

    long long count()
    {
        return ans;
    }

    //第二种方法:先建树再统计>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    /**
     * 插入字符串s（包括最后的'\0'），沿途更新totalSum，不更新ans
     * @param  {string} s : 插入的字符串s
     */    
    void insert2(const string & s)
    {
        int len = s.length();

        int father = 0; //父节点节点
        int curr;       //当前节点
        ++totalSum[0];

        //需要循环到len的位置:'\0'
        for (int i = 0; i <= len; ++i)
        {
            // 找字符s[i]
            char si = s[i];
            bool found = false;

            //从上层节点father第1个儿子开始找，不停的找右兄弟，直到没有右兄弟，rSibling=-1
            for (curr = lSon[father]; curr != NIL; curr = rSibling[curr])
            {
                if (ch[curr] == si)
                { 
                    // 找到了
                    found = true;
                    break;
                }
            }

            //没找到新建节点
            if (!found)
            {
                // 新建结点,进行唯一编号，自增长
                ++nodeId;
                curr = nodeId;

                rSibling[curr] = lSon[father];
                ch[curr] = si;
                lSon[curr] = NIL;
                totalSum[curr] = 0;

                lSon[father] = curr; // 替换上层节点的儿子为当前节点,插入到链表的首部
            }

            totalSum[father] +=1;  //记录有多少儿子
            father = curr;
            
        }
    }

    // 统计LCP=u的所有单词两两的比较次数之和
    void dfs(int depth, int u)
    {
        if (lSon[u] == 0) // 叶结点
            ans += totalSum[u] * (totalSum[u] - 1) * depth;
        else
        {
            int sum = 0;
            for (int v = lSon[u]; v != NIL; v = rSibling[v])
                sum += totalSum[v] * (totalSum[u] - totalSum[v]); // 子树v中选一个串，其他子树中再选一个
            ans += sum / 2 * (2 * depth + 1);                     // 除以2是每种选法统计了两次
            for (int v = lSon[u]; v != NIL; v = rSibling[v])
                dfs(depth + 1, v);
        }
    }

    // 统计
    long long count2()
    {
        ans = 0;
        dfs(0, 0);
        return ans;
    }
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
};

trie trie1;     //数据量大使用全局变量

int main()
{
    freopen("uva11732.in", "r", stdin);
    int kase = 0;

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        trie1.init();
        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            trie1.insert(word);
        }
        ++kase;
        cout << "Case " << kase << ": " << trie1.count() << "\n";
    }
    return 0;
}