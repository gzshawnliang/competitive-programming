/*
===========================================================
 * @名称:		D. Good Substrings
 * @作者:		Shawn 
 * @创建时间: 2019-10-09 16:38:22 
 * @修改人:   Shawn
 * @修改时间: 2019-10-09 16:38:22 
 * @备注:		AC:Time 186 ms,Memory 229000 KB
 * @题目来源： https://codeforces.com/contest/271/problem/D
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1500*1500+100; //最大节点数量
const int MAX_CHAR = 26;            //字符集的大小，小写字母a~z=26,Ascii所有字符128

class trie
{

  private:

    int tr[MAX_NODE][MAX_CHAR];         //tr节点的子节点。i是节点唯一编号，j是字符编号(ascii码-'a')。tr[i][j]表示编号是i的节点，j字符指向的下一个结点编号(顺序)。i是按顺序编号，j是按字符编号（-'a'）。0代表没节点
    int nodeIdx;                        //节点的编号，从1开始

    int maxAccBadChar;                  //the maximum acceptable number of bad characters in a good substring.

    int idx(char c)
    {
        return c - 'a';
    }

  public:
    bitset<27> isGood;
    int totalGoodSub;

    void init(int maxAccNumber)
    {
        this->maxAccBadChar = maxAccNumber;

        clear();
    }

    void clear()
    {
        memset(tr, 0, sizeof(tr));
        nodeIdx = 0;
        this->totalGoodSub = 0;
    }

    void buildSubStringTrie(const string & s)
    {
        int len = s.length();

        for (int i = 0; i <= len - 1; ++i)
        {
            int next = 0;
            int badCout = 0;
            for (int j = 0; i + j <= len - 1; ++j)
            {
                int c = idx(s[i + j]);

                if (isGood[c] == 0) //bad char
                {
                    ++badCout;
                }
                if (badCout > maxAccBadChar)
                {
                    break;
                }

                if (tr[next][c] == 0) // 如果没有，就添加结点
                {
                    ++nodeIdx;
                    tr[next][c] = nodeIdx;

                    ++(this->totalGoodSub); //节点的数量就是子串的数量
                }

                next = tr[next][c];
            }
        }
    }
};

trie trie1;     //数据量大，放入全局内存区

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_271D_GoodSubstrings.in", "r", stdin);
        freopen("CF_271D_GoodSubstrings.out", "w", stdout);
    #endif
    string sourceStr;
    cin >> sourceStr;
    string goobBadStr;
    cin >> goobBadStr;
    int k;
    cin >> k;

    reverse(goobBadStr.begin(), goobBadStr.end());
    trie1.init(k);
    trie1.isGood = bitset<27>(goobBadStr);
    trie1.buildSubStringTrie(sourceStr);
    cout << trie1.totalGoodSub << '\n';
    return 0;
}
