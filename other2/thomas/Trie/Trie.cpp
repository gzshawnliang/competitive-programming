#include <bits/stdc++.h>

using namespace std;

//const int maxnode = (int)1e6*10;

const int maxnode = (int)1e2;

int tr[maxnode][26];        //tr[i][j] 表示结点 i 的 j 字符指向的下一个结点

class trie
{
  public:
    int sigmaSize;          //字符集的大小，小写字母a~z=26,Ascii所有字符128
    //vector<vector<int>> tr; //tr[i][j] 表示结点 i 的 j 字符指向的下一个结点
    
    bitset<maxnode> exist;  // 该结点结尾的字符串是否存在
    int cnt;

    trie(int sigmaSize)
    {
        this->sigmaSize = sigmaSize;
        // tr.clear();
        // tr.shrink_to_fit();
        // tr.assign(maxnode, vector<int>(sigmaSize, 0));
        memset(tr,0,sizeof(tr));
        cnt = 0;
    }

    
    /**插入字符串s
     * 
     * @param  {string} s : 
     */
    void insert(const string & s)
    {
        int p = 0;
        int len=s.length();
        for (int i = 0; i <= len-1; ++i)
        {
            int c = idx(s[i]);
            if (tr[p][c] == 0) // 如果没有，就添加结点
            {
                ++cnt;
                tr[p][c] = cnt;
            }
            p = tr[p][c];
        }
        exist[p] = 1;
    }

    
    /**是否存在s字符串
     * 
     * @param  {string} s : 
     * @return {bool}     : 
     */
    bool contains(const string & s)
    { 
        //查找字符串
        int p = 0;
        int len=s.length();
        for (int i = 0; i <= len-1; ++i)
        {
            int c = idx(s[i]);
            if (tr[p][c] == 0)
                return 0;

            p = tr[p][c];
        }
        return exist[p];
    }

    /**是否存在s开头的字符串
     * 
     * @param  {string} s : 
     * @return {bool}     : 
     */
    bool containsPrefix(const string & s)
    { 
        //查找字符串前缀
        int p = 0;
        int len=s.length();
        for (int i = 0; i <= len-1; ++i)
        {
            int c = idx(s[i]);
            if (tr[p][c] == 0)
                return 0;

            p = tr[p][c];
        }
        return true;
    }

    // todo
    /**移除字符串s
     * 
     * @param  {string} s : 
     */
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
    // trie trie1(26);
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
    vector<string> a = {"a", "to", "tea", "ted", "ten", "i", "in", "inn"};
    trie trie1(26);
    int i = 0;
    for (auto s : a)
    {
        ++i;
        trie1.insert(s);
    }
    cout << trie1.contains("te") << '\n';
    cout << trie1.containsPrefix("te") << '\n';

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


