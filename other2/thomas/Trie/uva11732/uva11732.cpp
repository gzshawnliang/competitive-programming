#include <bits/stdc++.h>

using namespace std;

//ifstream fin("uva11732.in");
//ofstream fout("uva11732.out");

const int maxnode = 4000 * 1000 + 10;
//const int maxnode = 1000; //for debug

struct trie
{
    int son[maxnode];       //son[i]为第i个结点的左儿子编号
    int right[maxnode];     // right[i]为第i个结点的右兄弟编号
    char ch[maxnode];       // ch[i]为第i个结点上的字符
    int totalSum[maxnode];       // totalSum[i]为第i个结点为根的子树包含的叶结点总数
    int nodeId;             // 节点编号，自增长
    long long ans;              // 答案
    void init()
    {
        // 初始时只有一个根结点
        nodeId = 0;
        son[0] = 0;
        right[0] = 0;
        totalSum[0] = 0;        
        ans=0;
        
        //memset(son, -1, sizeof(son));  
        // memset(right, -1, sizeof(right));  
    } 

    // 插入字符串s（包括最后的'\0'），沿途更新tot
    void insert(const string & s)
    {
        int len = s.length();

        int father = 0;     //父节点节点
        int curr;           //当前节点
        ++totalSum[0];
        for (int i = 0; i <= len; ++i)
        {
            // 找字符s[i]
            char si = s[i];
            bool found = false;

            //从上层节点father第1个儿子开始找，不停的找右兄弟，直到没有右兄弟，right=-1
            for (curr = son[father]; curr != 0; curr = right[curr])
            {
                if (ch[curr] ==si)
                { // 找到了
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                // 新建结点,进行唯一编号，自增长
                ++nodeId;
                curr = nodeId;

                right[curr] = son[father];
                ch[curr] = si;
                totalSum[curr] = 0;
                son[curr] = 0;

                son[father] = curr; // 替换上层节点的儿子为当前节点,插入到链表的首部
            }

            father = curr;
            ++totalSum[father];
        }
    }

    // 统计LCP=u的所有单词两两的比较次数之和
    void dfs(int depth, int u)
    {
        if (son[u] == 0) // 叶结点
            ans += totalSum[u] * (totalSum[u] - 1) * depth;
        else
        {
            int sum = 0;
            for (int v = son[u]; v != 0; v = right[v])
                sum += totalSum[v] * (totalSum[u] - totalSum[v]); // 子树v中选一个串，其他子树中再选一个
            ans += sum / 2 * (2 * depth + 1);      // 除以2是每种选法统计了两次
            for (int v = son[u]; v != 0; v = right[v])
                dfs(depth + 1, v);
        }
    }

    // 统计
    long long count()
    {
        ans = 0;
        dfs(0, 0);
        return ans;
    }
};

trie trie1;

int main()
{
    freopen("uva11732.in", "r", stdin);      
    //freopen("uva11732.out", "w", stdout);      
    int kase = 0;
    
    while (true)
    {
        int n;
        cin >> n;
        if(n ==0)
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