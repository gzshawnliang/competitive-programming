#include <bits/stdc++.h>

using namespace std;


// Max number of states in the matching machine. 
// Should be equal to the sum of the length of all keywords. 
const int MAXS = 500; 
  
// 最大字符数，如全是小写英文字符则是26
const int MAXC = 26; 
  
/**
 * AC自动机模板
 */
class AhoCorasick
{
    private:
        //字符数组，匹配模式（多个）
        vector<string> P;
        
        // 输出函数 OUTPUT FUNCTION IS IMPLEMENTED USING out[] 
        // Bit i in this mask is one if the word with index i 
        // appears when the machine enters this state. 
        vector<int> out;  
        
        // 失配函数 FAILURE FUNCTION IS IMPLEMENTED USING f[]         
        vector<int> f;

        // 转移函数(Trie) 简单的使用 _goto[][] 二维数组
        vector<vector<int>> _goto;

    public:
        //匹配结果(多个)，第i个字符在第j个位置匹配
        vector<pair<int,int>> result;

        AhoCorasick(const vector<string> & p)
        {
            P=p;

            // Initialize all values in output function as 0.
            out.assign(MAXS, 0);

            // Initialize all values in goto function as -1.
            _goto.assign(MAXS, vector<int>(MAXC + 1, -1));  

            // FAILURE FUNCTION IS IMPLEMENTED USING f[] 
            // Initialize values in fail function 
    
            f.assign(MAXS,-1);
            result.clear();

            buildMatchingMachine();
        }

        // Builds the string matching machine.
        // arr -   array of words. The index of each keyword is important:
        //         "out[state] & (1 << i)" is > 0 if we just found word[i]
        //         in the text.
        // Returns the number of states that the built machine has.
        // States are numbered 0 up to the return value - 1, inclusive.
        int buildMatchingMachine()
        {
            int k = P.size();

            // Initialize all values in output function as 0.
            //out.assign(MAXS, 0);

            // Initialize all values in goto function as -1.
            //_goto.assign(MAXS, vector<int>(MAXC + 1, -1));

            // Initially, we just have the 0 state
            int states = 1;

            // Construct values for goto function, i.e., fill _goto[][]
            // This is same as building a Trie for arr[]
            for (int i = 0; i <= k - 1; ++i)
            {
                string word = P[i];
                int currentState = 0;

                // Insert all characters of current word in arr[]
                int wordLen = word.size();

                //空字符串不处理
                if (wordLen == 0)
                    continue;

                for (int j = 0; j <= wordLen - 1; ++j)
                {
                    int ch = word[j] - 'a';

                    // Allocate a new node (create a new state) if a
                    // node for ch doesn't exist.
                    if (_goto[currentState][ch] == -1)
                        _goto[currentState][ch] = states++;

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

            // Now, let's build the failure function

            // FAILURE FUNCTION IS IMPLEMENTED USING f[]
            // Initialize values in fail function
            //vector<int> f(MAXS,-1);
            //f.assign(MAXS,-1);

            // Failure function is computed in breadth first order
            // using a queue
            queue<int> q;

            // Iterate over every possible input
            for (int ch = 0; ch < MAXC; ++ch)
            {
                // All nodes of depth 1 have failure function value
                // as 0. For example, in above diagram we move to 0
                // from states 1 and 3.
                if (_goto[0][ch] != 0)
                {
                    f[_goto[0][ch]] = 0;
                    q.push(_goto[0][ch]);
                }
            }

            // Now queue has states 1 and 3
            while (q.size())
            {
                // Remove the front state from queue
                int state = q.front();
                q.pop();

                // For the removed state, find failure function for
                // all those characters for which goto function is
                // not defined.
                for (int ch = 0; ch <= MAXC; ++ch)
                {
                    // If goto function is defined for character 'ch'
                    // and 'state'
                    if (_goto[state][ch] != -1)
                    {
                        // Find failure state of removed state
                        int failure = f[state];

                        // Find the deepest node labeled by proper
                        // suffix of string from root to current
                        // state.
                        while (_goto[failure][ch] == -1)
                            failure = f[failure];

                        failure = _goto[failure][ch];
                        f[_goto[state][ch]] = failure;

                        // Merge output values
                        out[_goto[state][ch]] |= out[failure];

                        // Insert the next level node (of Trie) in Queue
                        q.push(_goto[state][ch]);
                    }
                }
            }

            return states;
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
                answer = f[answer];

            return _goto[answer][ch];
        }

        void searchWords(const string & text)
        {
            // Preprocess patterns.
            // Build machine with goto, failure and output functions
            
            

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
                        result.push_back(make_pair(j,i - P[j].size() + 1));
                        // cout << "Word " << P[j] << " appears from "
                        //      << i - P[j].size() + 1 << " to " << i << endl;
                    }
                }
            }
        }
};


int main()
{
    //string T = "ahishers";
    //vector<string> P = {"he", "she", "hers", "his"};
    // Word his appears from 1 to 3
    // Word he appears from 4 to 5
    // Word she appears from 3 to 5
    // Word hers appears from 4 to 7    

    
    vector<string> P = {"she", "his", "he", "hers",""}; 
    string T = "sheishere"; 

    AhoCorasick ac(P);
    ac.searchWords(T);

    if (!ac.result.empty())
    {
        for (auto i : ac.result)
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