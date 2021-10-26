/*
===========================================================
 * @名称:       The left-child, right-sibling representation (LCRS)
 * @作者:		Thomas 
 * @创建时间:   2019-09-23 21:49:55 
 * @修改人:     Shawn 
 * @修改时间:   2019-09-23 21:49:55 
 * @备注:		
 * @题目来源： 
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

//ifstream fin("1.in");
//ofstream fout("1.out");

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
    char c;
    vector<node * > children;
    node(char p_c)
    {
        this->c=p_c;
    }
};

struct node2
{
    char c;
    vector<int> children;
    node2(char p_c)
    {
        this->c=p_c;
    }
};

struct LCRS
{
    char c;
    LCRS * leftChild;          //左孩子
    LCRS * rightSibling;       //右兄弟
    LCRS * father;             //上父亲
    LCRS(char p_c)
    {
        this->c = p_c;
    }
};

/*
    正常的树
                   A
                 //|\ \
               / / | \  \
              B C  D  E  F
              |   /|\   / \
              G  H I J K   L
*/                  
node createTree()
{
    node root('A');

    node B('B');
    node C('C');
    node D('D');
    node E('E');
    node F('F');
    
    node G('G');
    node H('H');
    node I('I');
    node J('J');
    node K('K');
    node L('L');

    root.children.push_back(&B);
    root.children.push_back(&C);
    root.children.push_back(&D);
    root.children.push_back(&E);
    root.children.push_back(&F);

    B.children.push_back(&G);

    D.children.push_back(&H);
    D.children.push_back(&I);
    D.children.push_back(&J);

    F.children.push_back(&K);
    F.children.push_back(&L);
    return root;
}

/*
    正常的树
                   A
                 //|\ \
               / / | \  \
              B C  D  E  F
              |   /|\   / \
              G  H I J K   L
*/  

void createTree2(vector<node2> & tree)
{
    node2 root('A'); tree[0]=root;
    node2 B('B'); tree[1]=B;
    node2 C('C'); tree[2]=C;
    node2 D('D'); tree[3]=D;
    node2 E('E'); tree[4]=E;
    node2 F('F'); tree[5]=F;

    tree[0].children.push_back(1);
    tree[0].children.push_back(2);
    tree[0].children.push_back(3);
    tree[0].children.push_back(4);
    tree[0].children.push_back(5);
    
    
    node2 G('G');tree[6]=G;
    node2 H('H');tree[7]=H;
    node2 I('I');tree[8]=I;
    node2 J('J');tree[9]=J;
    node2 K('K');tree[10]=K;
    node2 L('L');tree[11]=L;

    //B
    tree[1].children.push_back(6);
    
    //D
    tree[3].children.push_back(7);
    tree[3].children.push_back(8);
    tree[3].children.push_back(9);

    //F
    tree[5].children.push_back(10);
    tree[5].children.push_back(11);
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
LCRS createLCRSTree()
{

    LCRS root('A');

    LCRS B('B');
    LCRS C('C');
    LCRS D('D');
    LCRS E('E');
    LCRS F('F');
    
    LCRS G('G');
    LCRS H('H');
    LCRS I('I');
    LCRS J('J');
    LCRS K('K');
    LCRS L('L');

    root.leftChild = &B;
    B.leftChild = &G;
    B.rightSibling = &C;
    C.rightSibling = &D;
    D.rightSibling = &E;
    D.leftChild = &H;
    E.rightSibling = &F;
    F.leftChild = &K;
    H.rightSibling = &I;
    I.rightSibling = &J;
    K.rightSibling = &L;
    return root;
}

int main()
{
    node root1= createTree();
    vector<node2> tree(26,node2('\0'));
    createTree2(tree);

    LCRS root2= createLCRSTree();

    if(root2.rightSibling==nullptr)
    {
        cout << "OK\n";
    }
    else
    {
        cout << "NO\n";
    }
    
    return 0;
}
