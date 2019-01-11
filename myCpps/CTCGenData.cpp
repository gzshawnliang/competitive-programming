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

//�������
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

//����0-7�������
int genRand()
{
    //Ҫȡ��[a,b]�����������ʹ��(rand() % (b-a+1))+ a;
    return (rand() % (7 - 0 + 1)) + 0;
}

//�����������
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
        } while (chessBoardTemp[x][y] != '.'); //ѭ�����ҿյ����̸�

        chessBoardTemp[x][y] = pieceString[i];
    }
}

int main()
{
    //freopen("bigdata.in2", "r", stdin);
    freopen("CTC.in", "w", stdout);
    srand(time(NULL));

    //��������
    int MAX_BOARD = (int)1e5;

    while (MAX_BOARD--)
    {
        CURR_INDEX++;

        //8x8����
        vector<vector<char>> chessBoardTemp(8, vector<char>(8, '.'));

        //�����������King������
        putChessPiece(chessBoardTemp, "Kk");

        //�����������Knight����
        putChessPiece(chessBoardTemp, "Nn");

        //�����������Queen����
        putChessPiece(chessBoardTemp, "Qq");

        //�����������Bishop����
        putChessPiece(chessBoardTemp, "Bb");

        //�����������Rook������
        putChessPiece(chessBoardTemp, "Rr");

        //�������Pawn������
        putChessPiece(chessBoardTemp, "PPpp");

        outputBoard(chessBoardTemp);
    }

    //���һ����8x8����
    vector<vector<char>> chessBoardEmpty(8, vector<char>(8, '.'));
    outputBoard(chessBoardEmpty);

    fclose(stdout);
    return 0;
}