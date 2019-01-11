#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

long CURR_INDEX=0;
ofstream fout("CTC2.in");

//输出棋盘
void outputBoard(vector<vector<char>> &chessBoardTemp)
{
    for (int i = 0; i <= 7; ++i)
    {
        for (int j = 0; j <= 7; ++j)
        {
            cout << chessBoardTemp[i][j];
            fout << chessBoardTemp[i][j];
        }
        cout << "\n";
        fout << "\n";
    }
    cout << "\n";
    fout << CURR_INDEX+1 << "\n";    
}

//产生0-7的随机数
int genRand()
{
    //要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
    return (rand() % (7 - 0 + 1)) + 0;
}

//随机放入棋子
void putChessPiece(vector<vector<char>> &chessBoardTemp, string pieceString)
{
    for (int i = 0; i <= pieceString.size() - 1; ++i)
    {
        int x = -1;
        int y = -1;
        do
        {
            x = genRand();
            y = genRand();
        } while (chessBoardTemp[x][y] != '.'); //循环查找空的棋盘格

        chessBoardTemp[x][y] = pieceString[i];
    }
}

int main()
{
    //freopen("bigdata.in2", "r", stdin);
    freopen("CTC.in", "w", stdout);
    srand(time(NULL));

    //棋盘数量
    int MAX_BOARD = (int)1e5;

    while (MAX_BOARD--)
    {
        CURR_INDEX++;

        //8x8棋盘
        vector<vector<char>> chessBoardTemp(8, vector<char>(8, '.'));

        //随机放入两个King（王）
        putChessPiece(chessBoardTemp, "Kk");

        //随机放入两个Knight（马）
        putChessPiece(chessBoardTemp, "Nn");

        //随机放入两个Queen（后）
        putChessPiece(chessBoardTemp, "Qq");

        //随机放入两个Bishop（象）
        putChessPiece(chessBoardTemp, "Bb");

        //随机放入两个Rook（车）
        putChessPiece(chessBoardTemp, "Rr");

        //随机放入Pawn（兵）
        putChessPiece(chessBoardTemp, "PPpp");

        outputBoard(chessBoardTemp);
    }

    //最后一个空8x8棋盘
    vector<vector<char>> chessBoardEmpty(8, vector<char>(8, '.'));
    outputBoard(chessBoardEmpty);

    fclose(stdout);
    return 0;
}