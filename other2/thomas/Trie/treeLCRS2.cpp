#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

const int NIL = -1;     //不存在的点

/*
正常的树
                   A
                 //|\ \
               / / | \  \
              B C  D  E  F
              |   /|\   / \
              G  H I J K   L


左孩子右兄弟树
            A
           /
          /
         /
        B -> C -> D -> E -> F
       /         /         /
      G         H->I->J   K->L
*/

struct node
{
    int parent;
    int left;
    int right;
    node()
    {
        parent = NIL;
        left = NIL;
        right = NIL;
    }
};

class LCRS
{
    vector<node> tree;

    public:

    
    /**
     * 获取深度
     * @param  {int} u : 当前节点编号
     * @return {int}   : 深度
     */
    int getDepth(int u)
    {
        int d=0;
        while (tree[u].parent != NIL)
        {
            u=tree[u].parent;       //获取父亲
            ++d;
        }
        return d;
    }

    /**
     * 获取节点类型
     * @param  {int} u   : 当前节点编号
     * @return {string}  :节点类型： root,leaf,internal node
     */
    string getType(int u)
    {
        if(tree[u].parent==NIL)
        {
            return "root";
        }
        else if(tree[u].left==NIL)
        {
            return "leaf";
        }
        else 
        {
            return "internal node";
        }
    }
    /**
     * 获取子节点
     * @param  {int} u        : 当前节点编号
     * @return {vector<int>}  : 子节点数组
     */
    vector<int> getChildren(int u)
    {
        vector<int> children;
        int c=tree[u].left;
        while (c!=NIL)
        {
            children.push_back(c);
            c=tree[c].right;    //获取右兄弟，右兄弟也是子节点
        }
        return children;
    }

    
    /**
     * 填充树
     */
    void fillTree()
    {
        int n;
        cin >> n;
        int nodeCount = n;
        tree.assign(n, node());
        while (nodeCount--)
        {
            int pNodeId;
            cin >> pNodeId;
            int k;
            cin >> k;
            int i = 0;
            int preId = 0;

            while (k--)
            {
                int cNodeId;
                cin >> cNodeId;

                tree[cNodeId].parent = pNodeId;

                if (i == 0)
                {
                    tree[pNodeId].left = cNodeId;
                }
                else
                {
                    tree[preId].right = cNodeId;
                }
                preId = cNodeId;
                ++i;
            }
        }
    }

    /**
     * 打印树
     */
    void printTree()
    {
        int size1=tree.size();
        for (int i = 0; i <= size1 - 1; ++i)
        {
            cout << "node " << i
            << ": parent = " << tree[i].parent
            << ", depth = " << getDepth(i)
            << ", " << getType(i) << ", [";

            vector<int> children = getChildren(i);
            int n1 = children.size();
            for (int j = 0; j <= n1 - 1; ++j)
            {
                cout << children[j];
                if (j != n1 - 1)
                {
                    cout << ", ";
                }
            }            
            cout << "]\n";
        }
    }    
};



int main()
{
    //freopen("treeLCRS.in", "r", stdin);
    LCRS lcrsTree;
    lcrsTree.fillTree();
    lcrsTree.printTree();

    return 0;
}
