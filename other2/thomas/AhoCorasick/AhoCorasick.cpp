#include <bits/stdc++.h>

using namespace std;


// Max number of states in the matching machine. 
// Should be equal to the sum of the length of all keywords. 
const int MAXS = 500; 
  
// Maximum number of characters in input alphabet 
const int MAXC = 26; 
  
// OUTPUT FUNCTION IS IMPLEMENTED USING out[] 
// Bit i in this mask is one if the word with index i 
// appears when the machine enters this state. 
//int out[MAXS]; 
//vector<int> out;
  
// FAILURE FUNCTION IS IMPLEMENTED USING f[] 
//int f[MAXS]; 
//vector<int> f;
  
// GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][] 
//int g[MAXS][MAXC]; 
//vector<vector<int>> g;

/**
 * AC自动机模板
 */
class AhoCorasick
{
    private:
        //匹配模式（多个）
        vector<string> P;
        
        // OUTPUT FUNCTION IS IMPLEMENTED USING out[] 
        // Bit i in this mask is one if the word with index i 
        // appears when the machine enters this state. 
        vector<int> out;  
        
        // FAILURE FUNCTION IS IMPLEMENTED USING f[]         
        vector<int> f;

        // GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][] 
        vector<vector<int>> g;

    public:
        AhoCorasick(const vector<string> & p)
        {
            P=p;

            // Initialize all values in output function as 0.
            out.assign(MAXS, 0);

            // Initialize all values in goto function as -1.
            g.assign(MAXS, vector<int>(MAXC + 1, -1));  

            // FAILURE FUNCTION IS IMPLEMENTED USING f[] 
            // Initialize values in fail function 
    
            f.assign(MAXS,-1);

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
            //g.assign(MAXS, vector<int>(MAXC + 1, -1));

            // Initially, we just have the 0 state
            int states = 1;

            // Construct values for goto function, i.e., fill g[][]
            // This is same as building a Trie for arr[]
            for (int i = 0; i <= k - 1; ++i)
            {
                string word = P[i];
                int currentState = 0;

                // Insert all characters of current word in arr[]
                for (int j = 0; j <= word.size() - 1; ++j)
                {
                    int ch = word[j] - 'a';

                    // Allocate a new node (create a new state) if a
                    // node for ch doesn't exist.
                    if (g[currentState][ch] == -1)
                        g[currentState][ch] = states++;

                    currentState = g[currentState][ch];
                }

                // Add current word in output function
                out[currentState] |= (1 << i);
            }

            // For all characters which don't have an edge from
            // root (or state 0) in Trie, add a goto edge to state
            // 0 itself
            for (int ch = 0; ch < MAXC; ++ch)
                if (g[0][ch] == -1)
                    g[0][ch] = 0;

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
                if (g[0][ch] != 0)
                {
                    f[g[0][ch]] = 0;
                    q.push(g[0][ch]);
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
                    if (g[state][ch] != -1)
                    {
                        // Find failure state of removed state
                        int failure = f[state];

                        // Find the deepest node labeled by proper
                        // suffix of string from root to current
                        // state.
                        while (g[failure][ch] == -1)
                            failure = f[failure];

                        failure = g[failure][ch];
                        f[g[state][ch]] = failure;

                        // Merge output values
                        out[g[state][ch]] |= out[failure];

                        // Insert the next level node (of Trie) in Queue
                        q.push(g[state][ch]);
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
            while (g[answer][ch] == -1)
                answer = f[answer];

            return g[answer][ch];
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
                for (int j = 0; j <= P.size() - 1; ++j)
                {
                    if (out[currentState] & (1 << j))
                    {
                        cout << "Word " << P[j] << " appears from "
                             << i - P[j].size() + 1 << " to " << i << endl;
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

    
    vector<string> P = {"aba", "bab"}; 
    string T = "ababababac"; 

    AhoCorasick ac(P);
    ac.searchWords(T);

    return 0;
}
