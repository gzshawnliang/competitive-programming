#include <bits/stdc++.h>

using namespace std;

//const int MAX_NODE = (int)1e6*10;

const int MAX_NODE = (int)1e7; //最大节点数量
const int MAX_CHAR = 26;      //字符集的大小，小写字母a~z=26,Ascii所有字符128

//NOTE:数据量大的时候100万以上，vector初始化比固定数组慢
int tr[MAX_NODE][MAX_CHAR]; //tr节点的子节点。i是节点唯一编号，j是字符编号(ascii码-'a')。tr[i][j]表示编号是i的节点，j字符指向的下一个结点编号(顺序)。i是按顺序编号，j是按字符编号（-'a'）。0代表没节点

int WordCount[MAX_NODE]; // 第i个结点如果是字符串的最尾的字符，存储此字符串的数量

bitset<MAX_NODE> lastCharTag; // lastCharTag[i],第i个结点是否是字符串的最尾的字符
int nodeIdx;                  //节点的编号，从1开始
bitset<MAX_NODE> vist = 0;    // 节点是否访问过dfs使用

bitset<27> isGood;
int maxAccNumber;

/**在计算机科学中，trie，又称前缀树或字典树
 * 常见应用如下
 * 1 – Substring Check
 * 2 – Searching All Patterns
 * 3 – Longest Repeated Substring
 * 4 – Build Linear Time Suffix Array
 * 5 – Longest Common Substring
 * 6 – Longest Palindromic Substring
 */
class trie
{
  private:
    //vector<vector<int>> tr;
    //vector<vector<int>> * tr; //tr保存每个节点的子节点。tr[i][j]表示编号是i的节点，j字符指向的下一个结点编号(顺序)。i是按顺序编号，j是按字符编号（-'a'）。0代表没节点

    /**字符c的索引编号
     * 
     * @param  {char} c : 
     * @return {int}    : 
     */

    int idx(char c)
    {
        return c - 'a';
    }

  public:
    trie()
    {
        //this->MAX_CHAR = MAX_CHAR;
        //tr.clear();
        //tr.reserve(MAX_NODE);
        //tr.assign(MAX_NODE, vector<int>(MAX_CHAR));

        //tr.assign(MAX_NODE,{0});
        //int (*tr)[26] = new int[MAX_NODE][26];

        clear();
    }

    void clear()
    {
        memset(tr, 0, sizeof(tr));
        memset(WordCount, 0, sizeof(WordCount));
        lastCharTag.reset();
        nodeIdx = 0;
    }

    /*创建单个字符和子串的Trie*/
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
                }
                else
                {
                    lastIds2.push_back(tr[next][c]);
                }
                lastCharTag[tr[next][c]] = 1;
                ++WordCount[tr[next][c]];
            }
            //next = tr[next][c];
            lastIds.clear();
            lastIds.assign(lastIds2.begin(), lastIds2.end());
            lastIds.push_back(0);
        }
    }

    int travel()
    {
        int ans=0;
        
        for(int start=0;start<=25;++start)
        {
            if(tr[0][start] !=0)
            {
                int subStringCount=1;
                int currbadCharCount=0;

                if(isGood[start] == 0)
                {
                    ++currbadCharCount;
                }
                

                if(currbadCharCount<=maxAccNumber)
                {
                    dfsSubString(tr[0][start],subStringCount,currbadCharCount);
                    ans +=subStringCount;
                }
            }
        }
        return ans;
    }

    
    void dfsSubString(int currIdx, int & subStringCount,int currbadCharCount)
    {
        if(currbadCharCount>maxAccNumber)
        {
            return;
        }
        else
        {
            
            for(int c=0;c<=26-1;++c)
            {
                if(tr[currIdx][c] !=0)
                {
                    if(isGood[c] ==0)
                        ++currbadCharCount;
                    
                    if(currbadCharCount>maxAccNumber)
                    {
                        --currbadCharCount;
                        continue;
                    }

                    ++subStringCount;
                    dfsSubString(tr[currIdx][c],subStringCount,currbadCharCount);

                    if(isGood[c] == 0)
                        --currbadCharCount;
                }

            }
            
        }
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
    cin>>maxAccNumber;

    reverse(goobBadStr.begin(),goobBadStr.end());
    isGood = bitset<27>(goobBadStr);
    trie trie1;
    trie1.buildSingleString(sourceStr);
    cout << trie1.travel() <<'\n';
    return 0;
}
