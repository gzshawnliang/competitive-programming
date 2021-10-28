/*
===========================================================
* @Name:        Tree traversal
* @Author:      Shawn
* @Create Time: 2020-08-03 19:05:25
* @Url:         https://en.wikipedia.org/wiki/Tree_traversal
* @Description: 
===========================================================
*/

#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class BinaryTreeTraversal
{
    vector<vector<int>> tree;

  public:
    BinaryTreeTraversal(vector<vector<int>> & treeData)
    {
        this->tree = treeData;
    }

    void preOrder(int p)
    {
        if (p > 0)
        {
            cout << setw(2) << p << " ";

            for (auto j : tree[p])
            {
                preOrder(j);
            }
        }
    }

    void inOrder(int  p)
    {
        if (p > 0)
        {
            if((int)tree[p].size()>0)
            {
                postOrder(tree[p][0]);
            }
            cout << setw(2) << p << " ";
            
            for (int i = 1,len=tree[p].size(); i <= len - 1; ++i)
            {
                postOrder(tree[p][i]);
            }
        }
    }

    void postOrder(int p)
    {
        if (p > 0)
        {
            for (auto j : tree[p])
            {
                postOrder(j);
            }

            cout << setw(2) << p << " ";
        }
    }
};

int main()
{

    //TreeNode

    /*
                      1 
                    /   \
                    2    3
                   / \  / \
                  4  5  6  7
                 / \    /
                 8  9  10
    */

    vector<vector<int>> tree(10 + 1);

    tree[1] = vector<int>{2, 3};
    tree[2] = vector<int>{4, 5};
    tree[4] = vector<int>{8, 9};
    tree[3] = vector<int>{6, 7};
    tree[6] = vector<int>{10};

    for (int __s = 0; __s == 0; ++__s)
        ;

    BinaryTreeTraversal biTree(tree);

    cout << setw(15) << "preOrder: ";
    biTree.preOrder(1);
    cout << "\n";

    cout << setw(15) << "inOrder: ";
    biTree.inOrder(1);
    cout << "\n";

    cout << setw(15) << "postOrder: ";
    biTree.postOrder(1);
    cout << "\n";
    return 0;
}