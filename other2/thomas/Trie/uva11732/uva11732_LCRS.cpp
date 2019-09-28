#include <bits/stdc++.h>

using namespace std;

const int maxn = 4000 * 1000 + 10;
//const int maxn = 1000;

struct node
{
    char ch;    //结点上的字符
    int son;    //指向儿子
    int right;  //指向右边的兄弟节点
    int sum;    //表示有多少个儿子
};

node nodes[maxn]; //trie数组节点

struct trie
{
    //node nodes[maxn];     //trie数组节点
    //vector<node> nodes;     //trie数组节点,数据量大使用固定数值并放入全局变量

    int nodeId;             //节点编号，自增长
    long long ans;          //答案

    void init()
    {
        //nodes.assign(maxn,node());  //trie数组节点,数据量大使用固定数值并放入全局变量，使用全局内存区

        nodeId = 0;
        nodes[nodeId].son = 0;
        nodes[nodeId].right = 0;
        nodes[nodeId].sum = 0;
        ans = 0;
    }

/*
    正常的树
                   A
                 //|\ \
               / / | \  \
              B C  D  E  F
              |   /|\   / \
              G  H I J K   L

    左孩子右兄弟树LCRS
            A
           /
          /
         /
        B -> C -> D -> E -> F
       /         /         /
      G         H->I->J   K->L
*/

    void insert(const string & s)
    {

        int len = s.length();

        int father = 0;         //父节点节点
        int curr;               //当前节点
        for (int i = 0; i <= len; ++i)
        {
            // 找字符s[i]
            char si = s[i];
            bool found = false;  //是否发现字符s[i]

            //从上层节点father第1个儿子开始找，不停的找右兄弟，直到没有右兄弟，right=-1
            for (curr = nodes[father].son; curr != 0; curr = nodes[curr].right)
            {
                if (nodes[curr].ch == si)
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

                nodes[curr].right = nodes[father].son;  //上层节点的儿子就是右兄弟
                nodes[curr].ch = si;                    //当前节点字符是s[i]
                nodes[curr].sum = 0;
                nodes[curr].son = 0;

                nodes[father].son = curr;               //替换上层节点的儿子为当前节点
            }

            ans += (nodes[father].sum + nodes[curr].sum);
            if (i == len)
                nodes[curr].sum += 1; //特判结尾 Trie中不会进入结尾字符,需特判统计

            nodes[father].sum += 1; //记录有多少儿子
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