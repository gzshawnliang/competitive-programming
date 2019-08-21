#include <bits/stdc++.h>

using namespace std;

//const int MAX_NODE = (int)1e6*10;

const int MAX_NODE = (int)1e6*10; //最大节点数量
const int MAX_CHAR = 26;       //字符集的大小，小写字母a~z=26,Ascii所有字符128

//todo:数据量大的时候100万以上，vector初始化比固定数组慢，原因未知
int tr[MAX_NODE][MAX_CHAR]; //tr节点的子节点。i是节点唯一编号，j是字符编号(ascii码-'a')。tr[i][j]表示编号是i的节点，j字符指向的下一个结点编号(顺序)。i是按顺序编号，j是按字符编号（-'a'）。0代表没节点

int WordCount[MAX_NODE]; // 第i个结点如果是字符串的最尾的字符，存储此字符串的数量

bitset<MAX_NODE> lastCharTag; // lastCharTag[i],第i个结点是否是字符串的最尾的字符
int nodeIdx;                  //节点的编号，从1开始
bitset<MAX_NODE> vist = 0;    // 节点是否访问过dfs使用

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

    void dfsChildren(int currIdx, int & result)
    {
        if (lastCharTag[currIdx] == 1)
        {
            result += WordCount[currIdx];
        }

        for (int i = 0; i <= MAX_CHAR - 1; ++i)
        {
            int next = tr[currIdx][i];
            if (next > 0 && vist[next] == 0)
            {
                vist[next] = 1;
                dfsChildren(next, result);
            }
        }
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

        memset(tr, 0, sizeof(tr));
        memset(WordCount, 0, sizeof(WordCount));
        lastCharTag.reset();
        nodeIdx = 0;
    }


    /*插入字符串s*/
    void insert(const string & s)
    {
        int next = 0;
        int len = s.length();
        for (int i = 0; i <= len - 1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0) // 如果没有，就添加结点
            {
                ++nodeIdx;
                tr[next][c] = nodeIdx;
            }
            next = tr[next][c];
        }
        lastCharTag[next] = 1;
        ++WordCount[next];
    }

    // todo
    /*建立单个字符的trie，包含子串*/
    void buildSingleString(const string & s)
    {
        int next = 0;
        int len = s.length();
        for (int i = 0; i <= len - 1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0) // 如果没有，就添加结点
            {
                //孩子
                ++nodeIdx;
                tr[next][c] = nodeIdx;
                lastCharTag[next] = 1;  //所有子串都做标记
                ++WordCount[next];

                //兄弟
                int brother=next+1;
                ++nodeIdx;
                tr[brother][c] = nodeIdx;
                lastCharTag[brother] = 1;  //所有子串都做标记
                ++WordCount[brother];

            }
            next = tr[next][c];
        }
    }

    /*是否存在s字符串*/
    bool exists(const string & s)
    {
        //查找字符串
        int next = 0;
        int len = s.length();
        for (int i = 0; i <= len - 1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0)
                return 0;

            next = tr[next][c];
        }
        return lastCharTag[next];
    }

    int count(const string & s)
    {
        //查找字符串
        int next = 0;
        int len = s.length();
        for (int i = 0; i <= len - 1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0)
                return 0;

            next = tr[next][c];
        }

        if (lastCharTag[next] == 1)
            return WordCount[next];
        else
            return 0;
    }

    /*是否存在s开头的字符串*/
    bool existsPrefix(const string & s)
    {
        //查找字符串前缀
        int next = 0;
        int len = s.length();
        for (int i = 0; i <= len - 1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0)
                return 0;

            next = tr[next][c];
        }
        return true;
    }

    /**计算包含前缀s所以字符串的个数
     * 
     * @param  {string} s : 
     * @return {int}      : 
     */
    int countPrefix(const string & s)
    {
        int next = 0;
        int len = s.length();
        for (int i = 0; i <= len - 1; ++i)
        {
            int c = idx(s[i]);
            if (tr[next][c] == 0)
                return 0;

            next = tr[next][c];
        }
        vist.reset();
        int result = 0;
        dfsChildren(next, result);
        return result;
    }

    // todo
    /*移除字符串s*/
    void remove(const string & s)
    {
    }
};

/**1000000 个字符串，66666个查询性能：1.61s
 * 
 * @return {int}  : 
 */
int main_trie_bigData()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); //关闭cin/cout同步

    //大数据测试
    freopen("Trie.in", "r", stdin);
    freopen("Trie.out", "w", stdout);
    trie trie1;
    int n;
    cin >> n;
    for (int i = 0; i <= n - 1; ++i)
    {
        string s;
        cin >> s;
        trie1.insert(s);
    }
    int q;
    cin >> q;
    for (int i = 0; i <= q - 1; ++i)
    {
        string s;
        cin >> s;
        cout << trie1.exists(s) << '\n';
    }

    cout.flush();
    fclose(stdin);
    fclose(stdout);

    return 0;
}

/**1000000 个字符串，66666个查询性能：4.15s
 * 
 * @return {int}  : 
 */
int main_map_bigData()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); //关闭cin/cout同步

    freopen("Trie.in", "r", stdin);
    freopen("map.out", "w", stdout);
    std::map<string, int> map1;
    int n;
    cin >> n;
    for (int i = 0; i <= n - 1; ++i)
    {
        string s;
        cin >> s;
        map1.insert(std::pair<string, int>(s, 1));
    }
    int q;
    cin >> q;
    for (int i = 0; i <= q - 1; ++i)
    {
        string s;
        cin >> s;
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

/**小数据测试案例
 * 
 * @return {int}  : 
 */
int main()
{
    //例子
    vector<string> a = {"abcd", "abd", "ab", "cdd", "efg", "hij", "hi", "cdd"};
    trie trie1;

    trie1.buildSingleString("abc");

    // int i = 0;
    // for (auto s : a)
    // {
    //     ++i;
    //     trie1.insert(s);
    // }
    // cout << trie1.exists("ab") << '\n';
    // cout << trie1.existsPrefix("ab") << '\n';
    // cout << trie1.count("cdd") << '\n';
    // cout << trie1.countPrefix("ab") << '\n';

    return 0;
}
