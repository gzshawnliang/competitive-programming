#include <bits/stdc++.h>

using namespace std;

const int NIL=-1;

const int MAX_SIZE = 4001 * 1000 + 100;

struct node
{
    char ch;                //结点上的字符
    int parent;             //指向父节点
    int lSon;               //指向左儿子
    int rSibling;           //指向右边的兄弟节点
    long long sum;          //表示有多少个儿子
};

const int maxn = 4000 * 1000 + 10;

node tree[maxn];            //trie数组节点

class trie
{
    //vector<node> tree;     //trie数组节点,数据量大使用固定数值并放入全局变量

    int nodeId;             //节点编号，自增长

    public:
    long long ans;          //答案

    trie()
    {
        //tree.assign(maxn,node());  //trie数组节点,数据量大使用固定数值并放入全局变量，使用全局内存区

        nodeId = 0;
        tree[nodeId].parent = NIL;
        tree[nodeId].lSon = NIL;
        tree[nodeId].rSibling = NIL;
        tree[nodeId].sum = 0;
        ans = 0;
    }

    void insert(const string & s)
    {
        int len = s.size();
        
        int father = 0;         //父节点节点
        int curr;               //当前节点

        //从上层节点father第1个儿子开始找，不停的找右兄弟，直到没有右兄弟，right=-1
        for (int i = 0; i <= len ; ++i)
        {
            
            char si = s[i];         //  找字符s[i]
            bool found = false;     //  是否发现字符s[i]

            for (curr = tree[father].lSon; curr != NIL; curr=tree[curr].rSibling)
            {
                if (tree[curr].ch == si)
                {
                    // 找到了
                    found = true;
                    break;
                }                                
            }
            if (!found)
            {
                // 新建结点,进行唯一编号，自增长
                ++nodeId;
                curr = nodeId;
                tree[curr].parent = father;
                tree[curr].rSibling = tree[father].lSon;    //上层节点的儿子就是右兄弟
                tree[curr].ch = si;                         //当前节点字符是s[i]
                tree[curr].sum = 0;
                tree[curr].lSon = NIL;                      //暂时无左儿子

                tree[father].lSon = curr;               //替换上层节点的儿子为当前节点
            }

            ans += (tree[father].sum + tree[curr].sum);
            if (i == len)
                tree[curr].sum += 1; //特判结尾 Trie中不会进入结尾字符,需特判统计

            tree[father].sum += 1; //记录有多少儿子
            father = curr;

        }
    }
};

int main()
{
    freopen("uva11732.in", "r", stdin);
    int cas = 0;
    int i;

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        trie trie1;
        for (i = 1; i <= n; ++i)
        {
            string s;
            cin >> s;
            trie1.insert(s);
        }
        ++cas;
        cout << "Case " << cas << ": ";
        cout << trie1.ans << endl;
    }    

    return 0;
}
