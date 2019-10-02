#include <bits/stdc++.h>

using namespace std;

struct node
{
    int parent;
    int left;
    int right;
    int depth;
    string nodeType;
    vector<int> children;

    node()
    {
        parent = -1;
        left = -1;
        right = -1;
        depth = -1;
    }
};

int getDepth(const vector<node> & tree,int i)
{
    int d=0;
    while (tree[i].parent !=-1)
    {
        i=tree[i].parent;
        ++d;
    }
    return d;
    
}

void fillTree(vector<node> & tree, int i)
{

    if (tree[i].parent == -1)
    {
        tree[i].nodeType = "root";
        tree[i].depth = 0;
    }
    else
    {
        if(tree[i].depth<=0)
        {
            tree[i].depth=getDepth(tree,i);
        }
        //tree[i].depth = tree[tree[i].parent].depth + 1;
        if(tree[i].right>0)
            tree[tree[i].right].depth = tree[i].depth;

        if (tree[i].children.size() == 0)
        {
            tree[i].nodeType = "leaf";
        }
        else
        {
            tree[i].nodeType = "internal node";
        }
    }
    if (i == tree.size() - 1)
    {
        return;
    }
    fillTree(tree, i + 1);
}

void printTree(vector<node> & tree)
{
    int n = tree.size();
    for (int i = 0; i <= n - 1; ++i)
    {
        cout << "node " << i
             << ": parent = " << tree[i].parent
             << ", depth = " << tree[i].depth
             << ", " << tree[i].nodeType << ", [";
        int n1 = tree[i].children.size();
        for (int j = 0; j <= n1 - 1; ++j)
        {
            cout << tree[i].children[j];
            if (j != n1 - 1)
            {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
}

int main()
{
    //freopen("treeLCRS.in", "r", stdin);

    int n;
    cin >> n;
    int nodeCount = n;
    vector<node> tree(n);
    int root;
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
            tree[pNodeId].children.push_back(cNodeId);

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
        if(tree[pNodeId].parent==-1)
        {
            root=pNodeId;
        }
    }

    tree[root].nodeType = "root";
    tree[root].depth = 0;

    fillTree(tree, 0);

    printTree(tree);

    return 0;
}
