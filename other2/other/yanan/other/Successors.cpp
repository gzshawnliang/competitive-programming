#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>
//#include <windows.h>

using namespace std;

int Max = 0, total = 0,Time=1;
vector<vector<int> > OBoard;
// ifstream  cin("Successors.in");
// ofstream cout("Successors.out");

bool overflow(int OFx, int OFy)
{
    if (OFx < 0 || OFx > 7 || OFy < 0 || OFy > 7)
    {
        return false;
    }
    return true;
}

void slant(vector<vector<int> > &temp, int x, int y)
{
    int Tx = x, Ty = y;
    while (true)
    {
        if (overflow(Tx + 1, Ty + 1) == true)
        {
            temp[Tx + 1][Ty + 1] = -1;
            Tx += 1;
            Ty += 1;
        }
        else
        {
            break;
        }
    }
    Tx = x;
    Ty = y;
    while (true)
    {
        if (overflow(Tx - 1, Ty - 1) == true)
        {
            temp[Tx - 1][Ty - 1] = -1;
            Tx -= 1;
            Ty -= 1;
        }
        else
        {
            break;
        }
    }
    Tx = x;
    Ty = y;
    while (true)
    {
        if (overflow(Tx - 1, Ty + 1) == true)
        {
            temp[Tx - 1][Ty + 1] = -1;
            Tx -= 1;
            Ty += 1;
        }
        else
        {
            break;
        }
    }
    Tx = x;
    Ty = y;
    while (true)
    {
        if (overflow(Tx + 1, Ty - 1) == true)
        {
            temp[Tx + 1][Ty - 1] = -1;
            Tx += 1;
            Ty -= 1;
        }
        else
        {
            break;
        }
    }
}

void caculate(vector<vector<int> > & CBoard, int CColumn)
{
    bool yes = false;
    for (int i = 0; i < 8; ++i)
    {
        if (CBoard[i][CColumn] != -1)
        {
            yes = true;
            break;
        }
    }
    if (yes == false)
    {
        return;
    }
    else
    {
        if (CColumn == 8)
        {
            for (int i = 0; i < 8; ++i)
            {
                for (int h = 0; h < 8; ++h)
                {
                    if (CBoard[i][h] == 0)
                    {
                        total += OBoard[i][h];
                    }
                }
            }
            if (Max < total)
            {
                Max = total;
            }
            total = 0;
            return;
        }
        else
        {
            for (int row = 0; row < 8; ++row)
            {
                if (CBoard[row][CColumn] != 0 && CBoard[row][CColumn] != -1)
                {
                    vector<vector<int> > temp = CBoard;
                    temp[row][CColumn] = 0;
                    for (int i = 0; i < 8; ++i)
                    {
                        if (i == row && i == CColumn)
                        {
                            continue;
                        }
                        else if (i == row)
                        {
                            temp[row][i] = -1;
                        }
                        else if (i == CColumn)
                        {
                            temp[i][CColumn] = -1;
                        }
                        else if (i != row && i != CColumn)
                        {
                            temp[row][i] = -1;
                            temp[i][CColumn] = -1;
                        }
                    }
                    slant(temp, row, CColumn);
                    caculate(temp, CColumn + 1);
                }
            }
        }
    }
}

int main()
{
    ifstream cin("Successors.in");
    ofstream cout("Successors.out");    
    int n;
    cin >> n;
    while (n > 0)
    {
        --n;
        Max=0;
        vector<vector<int> > board(8,vector<int> (8));
        for (int i = 0; i < 8; ++i)
        {
            for (int h = 0; h < 8; ++h)
            {
                int temp;
                cin >> temp;
                board[i][h] = temp;
            }
        }
        OBoard = board;
        caculate(board, 0);
        cout << Max << endl;
    }
    //system("pause");
    return 0;
}

// void caculate2(vector<vector<int> > & CBoard, int CColumn)
// {
//     bool yes = false;
//     for (int i = 0; i < 8; ++i)
//     {
//         if (CBoard[i][CColumn] != 0)
//         {
//             yes = true;
//             break;
//         }
//     }
//     if (yes == false)
//     {
//         return;
//     }
//     else
//     {
//         if (CColumn == 8)
//         {
//             cout<<Time<<endl;
//             ++Time;
//             for (int i = 0; i < 8; ++i)
//             {
//                 for (int h = 0; h < 8; ++h)
//                 {
//                     cout<<CBoard[i][h];
//                     // if (CBoard[i][h] == 0)
//                     // {
//                     //     //total += OBoard[i][h];
//                     // }
//                 }
//                 cout<<endl;
//             }
//             cout<<endl<<endl<<endl;
//             // if (Max < total)
//             // {
//             //     Max = total;
//             // }
//             //total = 0;
//             return;
//         }
//         else
//         {
//             for (int row = 0; row < 8; ++row)
//             {
//                 if (CBoard[row][CColumn] != 0 && CBoard[row][CColumn] != 1)
//                 {
//                     vector<vector<int> > temp = CBoard;
//                     temp[row][CColumn] = 1;
//                     for (int i = 0; i < 8; ++i)
//                     {
//                         if (i == row && i == CColumn)
//                         {
//                             continue;
//                         }
//                         else if (i == row)
//                         {
//                             temp[row][i] = 0;
//                         }
//                         else if (i == CColumn)
//                         {
//                             temp[i][CColumn] = 0;
//                         }
//                         else if (i != row && i != CColumn)
//                         {
//                             temp[row][i] = 0;
//                             temp[i][CColumn] = 0;
//                         }
//                     }
//                     slant(temp, row, CColumn);
//                     caculate2(temp, CColumn + 1);
//                 }
//             }
//         }
//     }
// }