#include <bits/stdc++.h>

using namespace std;

const int direction[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
bool visit[4][4] = {0};

int NumOfVowel(string &a)
{
    int N = 0;
    for (int i = 0; i < 4; ++i)
        if (a[i] == 'A' || a[i] == 'E' || a[i] == 'I' ||
            a[i] == 'O' || a[i] == 'U' || a[i] == 'Y')
            ++N;
    return N;
}

void DFS(int i, int j, char board[][4],string &Word, vector<string> &PigEwu)
{
    Word.push_back(board[i][j]);

    if (Word.size() == 4) {
        
        if (NumOfVowel(Word) == 2)
        {
            PigEwu.push_back(Word);
            cout << Word << "-OK\n";
        }
        else
        {
            cout << Word << "\n";
        }
        
        Word.pop_back();
        return;
    }

    visit[i][j] = 1;
    for (int x = 0; x < 8; ++x) {
        int nxt_i = i + direction[x][0];
        int nxt_j = j + direction[x][1];
        if (nxt_i < 0 || nxt_i == 4 || nxt_j < 0 || nxt_j == 4) continue;

        if (visit[nxt_i][nxt_j] == 0)
            DFS(nxt_i, nxt_j, board, Word, PigEwu);
    }
    visit[i][j] = 0;
    Word.pop_back();
}


int main()
{
    #ifndef ONLINE_JUDGE    
        freopen("uva604.in", "r", stdin);
        //freopen("uva604.out", "w", stdout);
    #endif 

    ios::sync_with_stdio(false);
    int Case = 0;
    while (++Case) {
        char board1[4][4], board2[4][4];
        vector<string> PigEwu1, PigEwu2, Ans;
        string Word;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                cin >> board1[i][j];
            for (int j = 0; j < 4; ++j)
                cin >> board2[i][j];
        }
        if (board1[0][0] == '#') return 0;

        // 兩個board分別DFS找出所有可能答案
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                DFS(i, j, board1, Word, PigEwu1);
                DFS(i, j, board2, Word, PigEwu2);
            }
        }
        // 再將PigEwu1和PigEwu2交集
        for (string &a : PigEwu1)
            for (string &b : PigEwu2)
                if (a == b)
                    Ans.push_back(a);

        sort(Ans.begin(), Ans.end());

        if (Case != 1) cout << endl;

        if (Ans.empty()) cout << "There are no common words for this pair of boggle boards." << endl;
        else {
            cout << Ans[0] << endl;
            for (int i = 1; i < Ans.size(); ++i)
                if (Ans[i] != Ans[i-1])
                    cout << Ans[i] << endl;
        }
    }
}


