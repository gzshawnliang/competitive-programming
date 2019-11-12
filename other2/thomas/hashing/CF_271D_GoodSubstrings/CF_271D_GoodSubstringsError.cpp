#include <bits/stdc++.h>

using namespace std;

//const int MAX_NODE = (int)1e6*10;

const int MAX_NODE = (int)1e4; //最大节点数量
const int MAX_CHAR = 26;      //字符集的大小，小写字母a~z=26,Ascii所有字符128

int tr[MAX_NODE][MAX_CHAR]; //tr节点的子节点。i是节点唯一编号，j是字符编号(ascii码-'a')。tr[i][j]表示编号是i的节点，j字符指向的下一个结点编号(顺序)。i是按顺序编号，j是按字符编号（-'a'）。0代表没节点
int subStrNode[MAX_NODE]; // 第i个结点如果是那个开头的子串

int nodeIdx;                  //节点的编号，从1开始
bitset<MAX_NODE> vist = 0;    // 节点是否访问过dfs使用

bitset<27> isGood;

int badStringValue[MAX_NODE];


class trie
{
  private:

    int maxAccNumber;//the maximum acceptable number of bad characters in a good substring.

    int idx(char c)
    {
        return c - 'a';
    }

  public:
    int goodStrNumber;
    trie(int maxAccNumber)
    {
        this->maxAccNumber=maxAccNumber;

        clear();
    }

    void clear()
    {
        memset(tr, 0, sizeof(tr));
        memset(subStrNode, -1, sizeof(subStrNode));
        nodeIdx = 0;
        this->goodStrNumber=0;
    }

    void buildSingleString(const string & s)
    {
        int next = 0;
        int len = s.length();
        vector<int> lastIds;
        lastIds.push_back(next);
        
        for (int i = 0; i <= len - 1; ++i)
        {
            int c = idx(s[i]);
            vector<int> lastIds2;
            for (auto j : lastIds)
            {
                next = j;
                if (tr[next][c] == 0) // 如果没有，就添加结点
                {
                    ++nodeIdx;
                    tr[next][c] = nodeIdx;
                    lastIds2.push_back(nodeIdx);

                    if(next==0)
                    {
                        subStrNode[nodeIdx]=c;
                    }
                    else
                    {
                        subStrNode[nodeIdx]=subStrNode[next];
                    }
                    if(isGood[c]==0)    //bad string
                    {
                        ++badStringValue[nodeIdx];

                        if(badStringValue[c]<=maxAccNumber)
                        {
                            ++goodStrNumber;
                        }

                    }
                    else 
                    {
                        int currcol=subStrNode[nodeIdx];

                        ++goodStrNumber;
                    }
                }
                else
                {
                    lastIds2.push_back(tr[next][c]);
                }
            }
            lastIds.clear();
            lastIds.assign(lastIds2.begin(), lastIds2.end());
            lastIds.push_back(0);
        }
        cout <<"";
    }
};

int main()
{
    //Round#166(Div.2)D.GoodSubstrings
    freopen("Round#166(Div.2)D.GoodSubstrings.in", "r", stdin);      
    freopen("Round#166(Div.2)D.GoodSubstrings.out", "w", stdout);  
    string sourceStr;
    cin>>sourceStr;
    string goobBadStr;
    cin>>goobBadStr;
    int k;
    cin>>k;

    reverse(goobBadStr.begin(),goobBadStr.end());
    isGood = bitset<27>(goobBadStr);
    trie trie1(k);
    trie1.buildSingleString(sourceStr);
    cout << trie1.goodStrNumber <<'\n';
    return 0;
}
