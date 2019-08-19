#include <bits/stdc++.h>

using namespace std;

//const int maxnode = (int)1e6*10;

const int maxnode = (int)1e2;   //最大节点数量
const int sigmaSize =26;        //字符集的大小，小写字母a~z=26,Ascii所有字符128

int tr[maxnode][sigmaSize];     //tr保存每个节点的子节点。tr[i][j]表示编号是i的节点，j字符指向的下一个结点编号(顺序)。i是按顺序编号，j是按字符编号（-'a'）。0代表没节点



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
  public:
    //int sigmaSize;          //字符集的大小，小写字母a~z=26,Ascii所有字符128
    //vector<vector<int>> tr; //tr保存每个节点的子节点。tr[i][j]表示编号是i的节点，j字符指向的下一个结点编号(顺序)。i是按顺序编号，j是按字符编号（-'a'）。0代表没节点
    
    bitset<maxnode> isEndChar;  // isEndChar[i],第i个结点是否是字符串的最尾的字符
    
    int nodeIdx;                //节点的编号，从1开始

    trie()
    {
        //this->sigmaSize = sigmaSize;
        // tr.clear();
        // tr.shrink_to_fit();
        // tr.assign(maxnode, vector<int>(sigmaSize, 0));
        memset(tr,0,sizeof(tr));
        nodeIdx = 0;
    }

    ~trie()
    {
    }
    
    /*插入字符串s*/
    void insert(const string & s)
    {
        int next = 0;
        int len=s.length();
        for (int i = 0; i <= len-1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0) // 如果没有，就添加结点
            {
                ++nodeIdx;
                tr[next][c] = nodeIdx;
            }
            next = tr[next][c];
        }
        isEndChar[next] = 1;
    }

    
    /*是否存在s字符串*/
    bool contains(const string & s)
    { 
        //查找字符串
        int next = 0;
        int len=s.length();
        for (int i = 0; i <= len-1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0)
                return 0;

            next = tr[next][c];
        }
        return isEndChar[next];
    }

    /*是否存在s开头的字符串*/
    bool containsPrefix(const string & s)
    { 
        //查找字符串前缀
        int next = 0;
        int len=s.length();
        for (int i = 0; i <= len-1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0)
                return 0;

            next = tr[next][c];
        }
        return true;
    }

    // todo
    /*移除字符串s*/
    void remove(const string & s)
    {

    }

  private:
    /**字符c的索引编号
     * 
     * @param  {char} c : 
     * @return {int}    : 
     */
    int idx(char c)
    {
        return c - 'a';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);                     //关闭cin/cout同步

    //大数据测试
    // freopen("Trie.in", "r", stdin);      
    // freopen("Trie.out", "w", stdout);     
    // trie trie1();
    // int n;
    // cin >> n ;
    // for (int i = 0; i <= n - 1; ++i)
    // {
    //     string s;
    //     cin >>s;
    //     trie1.insert(s);
    // }
    // int q;
    // cin >> q ;
    // for (int i = 0; i <= q - 1; ++i)
    // {
    //     string s;
    //     cin >>s;
    //     cout << trie1.contains(s) << '\n';
    // }

    //例子
    vector<string> a = {"abcd", "abd", "cdd", "efg", "hij", "hi"};
    trie trie1;
    int i = 0;
    for (auto s : a)
    {
        ++i;
        trie1.insert(s);
    }
    cout << trie1.contains("ab") << '\n';
    cout << trie1.containsPrefix("ab") << '\n';

    cout.flush();
    fclose(stdin);
    fclose(stdout);

    return 0;
}


int main_map()
{
    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);                     //关闭cin/cout同步

    freopen("Trie.in", "r", stdin);      
    freopen("map.out", "w", stdout); 
    std::map<string,int> map1;
    int n;
    cin >> n ;
    for (int i = 0; i <= n - 1; ++i)
    {
        string s;
        cin >>s;
        map1.insert(std::pair<string,int>(s,1));
    }
    int q;
    cin >> q ;
    for (int i = 0; i <= q - 1; ++i)
    {
        string s;
        cin >>s;
        auto it = map1.find(s);
        if (it != map1.end())
            cout << 1 << '\n';    
        else 
            cout << 0 << '\n';
    }   

    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0; 
}


