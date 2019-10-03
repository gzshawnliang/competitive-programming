#include <bits/stdc++.h>

using namespace std;

struct node
{
    char ch;       //结点上的字符
    int parent;    //指向父节点
    int lSon;      //指向左儿子
    int rSibling;  //指向右边的兄弟节点
    long long sum; //表示有多少个儿子(该结点为根的子树包含的叶结点总数)
};

const int NIL = -1;

const int MAX_SIZE = 4000 * 1000 + 10;  //数组最大节点
//const int MAX_SIZE = 1000;              //设置小数组用于调试

node tree[MAX_SIZE];      //trie数组节点

class trie
{
    //vector<node> tree;     //trie数组节点,数据量大使用固定数值并放入全局变量
    int nodeId; //节点编号，自增长

  public:
    long long ans; //答案

    void init()
    {
        //tree.assign(MAX_SIZE,node());  //trie数组节点,数据量大使用固定数值并放入全局变量，使用全局内存区

        nodeId = 0;
        tree[nodeId].parent = NIL;
        tree[nodeId].lSon = NIL;
        tree[nodeId].rSibling = NIL;
        tree[nodeId].sum = 0;
        ans = 0;
    }

    /**边建树边统计
     * 插入字符串s（包括最后的'\0'），沿途更新totalSum，顺便更新ans
     * @param  {string} s : 插入的字符串s
     */
    void insert(const string & s)
    {
        int len = s.size();
        int father = 0; //父节点节点,从根节点开始

        //需要循环到len的位置:'\0'
        for (int i = 0; i <= len; ++i)
        {
            int curr = NIL; //当前节点

            //从上层节点father第1个儿子开始找，不停的找右兄弟，直到没有右兄弟，rSibling=-1
            for (int j = tree[father].lSon; j != NIL; j = tree[j].rSibling)
            {
                if (tree[j].ch == s[i])
                {
                    // 找到了
                    ans += (tree[j].sum *2);
                    curr =j;
                }
                else
                {
                    ans += tree[j].sum;
                }
            }

            //没找到字符s[i]，新建节点
            if (curr==NIL)
            {
                // 新建结点,进行唯一编号，自增长
                ++nodeId;
                curr = nodeId;
                tree[curr].parent = father;                 //设置父节点(暂时无用)
                tree[curr].rSibling = tree[father].lSon;    //上层节点的左儿子就是右兄弟
                tree[curr].ch = s[i];                       //当前节点字符是s[i]
                tree[curr].lSon = NIL;                      //新建的节点暂时无左儿子
                tree[curr].sum = 0;                         //新建的节点暂时儿子数量是0

                tree[father].lSon = curr;                   //替换父节点的左儿子为当前节点
            }

            father = curr;                                  //当前节点设置成父节点，下次循环使用
            tree[father].sum += 1;                          //儿子数量+1
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
        trie1.init();
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
