/*
===========================================================
* @Name:        Tree traversal
* @Author:      Thomas
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

class TreeNode
{
  public:
    int id;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int i)
    {
        this->id = i;
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode * insertLeft(int leftId)
    {
        //TreeNode leftNode(leftId);
        this->left = new TreeNode(leftId);
        return this->left;
    }

    TreeNode * insertRight(int rightId)
    {
        //TreeNode rightNode(rightId);
        this->right = new TreeNode(rightId);
        return this->right;
    }
};

class BinaryTreeTraversal
{
  public:
    void preOrder(TreeNode * p)
    {
        if (p != NULL)
        {
            cout << setw(2) << p->id << " ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }

    void inOrder(TreeNode * p)
    {
        if (p != NULL)
        {
            inOrder(p->left);
            cout << setw(2) << p->id << " ";
            inOrder(p->right);
        }
    }

    void postOrder(TreeNode * p)
    {
        if (p != NULL)
        {
            postOrder(p->left);
            postOrder(p->right);
            cout << setw(2) << p->id << " ";
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

    TreeNode root(1);
    TreeNode * node2 = root.insertLeft(2);
    TreeNode * node3 = root.insertRight(3);

    TreeNode * node4 = node2->insertLeft(4);
    TreeNode * node5 = node2->insertRight(5);

    TreeNode * node8 = node4->insertLeft(8);
    TreeNode * node9 = node4->insertRight(9);

    TreeNode * node6 = node3->insertLeft(6);
    TreeNode * node7 = node3->insertRight(7);

    TreeNode * node10 = node6->insertLeft(10);

    for (int __s = 0; __s == 0; ++__s);

    BinaryTreeTraversal biTree;

    cout << setw(15) << "preOrder: ";
    biTree.preOrder(&root);
    cout << "\n";

    cout << setw(15) << "inOrder: ";
    biTree.inOrder(&root);
    cout << "\n";

    cout << setw(15) << "postOrder: ";
    biTree.postOrder(&root);
    cout << "\n";
    return 0;
}