#include <bits/stdc++.h>

using namespace std;

// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.
const int MAXS = 500;

// 最大字符数，如全是小写英文字符则是26
const int MAXC = 26;

/**
 * AC自动机模板，实现多模式匹配
 */
class AhoCorasick
{
  private:
    //多个匹配模式字符（字符串数组）
    vector<string> P;

    // 输出功能
    // Bit i in this mask is one if the word with index i
    // appears when the machine enters this state.
    vector<int> out;

    // 失配转移功能，不匹配的时候转移到那个位置
    vector<int> fail;

    // 正常转移功能(Trie) 简单的使用 _goto[][] 二维数组,成功匹配之后应该转移到哪一个状态
    vector<vector<int>> _goto;

    void init(const vector<string> & p)
    {
        P = p;

        // Initialize all values in output function as 0.
        out.assign(MAXS, 0);

        // 全部初始值是 -1.
        _goto.assign(MAXS, vector<int>(MAXC + 1, -1));

        // FAILURE FUNCTION IS IMPLEMENTED USING fail[]
        // Initialize values in fail function
        fail.assign(MAXS, -1);
    }

    // Returns the next state the machine will transition to using goto
    // and failure functions.
    // currentState - The current state of the machine. Must be between
    //                0 and the number of states - 1, inclusive.
    // nextInput - The next character that enters into the machine.
    int findNextState(int currentState, char nextInput)
    {
        int answer = currentState;
        int ch = nextInput - 'a';

        // If goto is not defined, use failure function
        while (_goto[answer][ch] == -1)
            answer = fail[answer];

        return _goto[answer][ch];
    }

  public:
    /**
         * 构造函数 
         * 
         * @param  {vector<string>} p : 需要查找的字符串数组
         */
    AhoCorasick(const vector<string> & p)
    {
        init(p);
        buildMatchingMachine();
    }

    // Builds the string matching machine.
    // arr -   array of words. The index of each keyword is important:
    //         "out[state] & (1 << i)" is > 0 if we just found word[i]
    //         in the text.
    // Returns the number of nodes that the built machine has.
    // nodes are numbered 0 up to the return value - 1, inclusive.

    /**建立字符串匹配机器
     * 
     * @return {int}  : 返回_goto匹配机拥有的节点数量
     */
    int buildMatchingMachine()
    {
        int k = P.size();

        // 初始节点是0
        int nodeId = 0;

        // 字母索引
        // a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25


        // 创建goto函数
        // 和创建Trie数组一样
        for (int i = 0; i <= k - 1; ++i)
        {
            string word = P[i];
            int currentState = 0;

            // Insert all characters of current word in arr[]
            int wordLen = word.size();

            //空字符串不查找，不处理
            if (wordLen == 0)
                continue;

            for (int j = 0; j <= wordLen - 1; ++j)
            {
                int ch = word[j] - 'a';

                // 创建节点，++nodeId 按顺序编号
                if (_goto[currentState][ch] == -1)
                {
                    ++nodeId;
                    _goto[currentState][ch] = nodeId;
                }

                currentState = _goto[currentState][ch];
            }

            // Add current word in output function
            out[currentState] |= (1 << i);
        }

        // For all characters which don't have an edge from
        // root (or state 0) in Trie, add a goto edge to state
        // 0 itself
        for (int ch = 0; ch < MAXC; ++ch)
            if (_goto[0][ch] == -1)
                _goto[0][ch] = 0;


        // 计算失配数组需要宽度遍历_goto数组(Trie)
        queue<int> q;   // 使用队列

        // Iterate over every possible input
        for (int ch = 0; ch < MAXC; ++ch)
        {
            // All nodes of depth 1 have failure function value
            // as 0. For example, in above diagram we move to 0
            // from states 1 and 3.
            if (_goto[0][ch] != 0)
            {
                fail[_goto[0][ch]] = 0;
                q.push(_goto[0][ch]);
            }
        }

        // Now queue has states 1 and 3
        while (q.size())
        {
            // Remove the front nowNodeId from queue
            int nowNodeId = q.front();
            q.pop();

            // For the removed nowNodeId, find failure function for
            // all those characters for which goto function is
            // not defined.
            for (int ch = 0; ch <= MAXC; ++ch)
            {
                // If goto function is defined for character 'ch'
                // and 'nowNodeId'
                if (_goto[nowNodeId][ch] != -1)
                {
                    // Find failure nowNodeId of removed nowNodeId
                    int failure = fail[nowNodeId];

                    // Find the deepest node labeled by proper
                    // suffix of string from root to current
                    // nowNodeId.
                    while (_goto[failure][ch] == -1)
                        failure = fail[failure];

                    failure = _goto[failure][ch];
                    fail[_goto[nowNodeId][ch]] = failure;

                    // Merge output values
                    out[_goto[nowNodeId][ch]] |= out[failure];

                    // Insert the next level node (of Trie) in Queue
                    q.push(_goto[nowNodeId][ch]);
                }
            }
        }

        return nodeId;
    }

    /**
     * 查找单词
     * @param  {string} text            : 【输入】源字符串
     * @return {vector<pair<int,int>>}  :  匹配结果(多个)，pair<i,j>第i个字符在第j个位置匹配
    */
    vector<pair<int, int>> searchWords(const string & text)
    {

        // Preprocess patterns.
        // Build machine with goto, failure and output functions
        vector<pair<int, int>> result;

        // Initialize current state
        int currentState = 0;

        // Traverse the text through the nuilt machine to find
        // all occurrences of words in arr[]
        for (unsigned int i = 0; i < text.size(); ++i)
        {
            currentState = findNextState(currentState, text[i]);

            // If match not found, move to next state
            if (out[currentState] == 0)
                continue;

            // Match found, print all matching words of P[]
            // using output function.
            int pLen = P.size();
            for (int j = 0; j <= pLen - 1; ++j)
            {
                if (out[currentState] & (1 << j))
                {
                    result.push_back(make_pair(j, i - P[j].size() + 1));
                    // cout << "Word " << P[j] << " appears from "
                    //      << i - P[j].size() + 1 << " to " << i << endl;
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<string> P = {"she", "his", "he", "her"};
    string T = "sheishere";

    AhoCorasick ac(P);

    auto result = ac.searchWords(T);

    if (!result.empty())
    {
        for (auto i : result)
        {
            cout << "Word "
                 << P[i.first]
                 << " appears from "
                 << i.second
                 << " to "
                 << i.second + P[i.first].size() - 1
                 << '\n';
        }
    }
    else
    {
        cout << "find nothing" << '\n';
    }

    return 0;
}
