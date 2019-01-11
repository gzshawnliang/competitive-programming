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

using namespace std;

//设置并且标记杀伤范围
void setAttackRange(vector<vector<int>> & chessboard,int x,int y)
{
    //右下( 1, 1)
    //左下(-1, 1)
    //左上(-1,-1)
    //右上( 1,-1)
    vector<int> pos1={1,1,-1,1,-1,-1,1,-1};

    for(int i=0;i<=pos1.size()-1;i=i+2)
    {
        int x1=x+pos1[i];
        int y1=y+pos1[i+1]; 

        if(x1<=8 && x1>=1 && y1<=8 && y1>=1)
        {
            do
            {
                if(chessboard[x1][y1]==0)
                {
                    //标记成-1是攻击范围
                    chessboard[x1][y1]=-1;
                }
                x1=x1+pos1[i];
                y1=y1+pos1[i+1];
            }
            while (x1<=8 && x1>=1 && y1<=8 && y1>=1);        
        }        
    }
}

bool CheckIs8Queen(string & queenPos)
{
    vector<vector<int>> chessboard(10, vector<int>(10, 0));

    for(int i=0;i<=queenPos.size()-1;++i)
    {
        int x=queenPos[i]-'0';
        int y=i+1;

        if(chessboard[x][y]==0)             //0代表能放皇后
        {
            //放皇后
            chessboard[x][y]=1;
            
            //设置并且标记杀伤范围
            setAttackRange(chessboard,x,y);
        }
        else
        {
            //不能放皇后，返回false
            return false;
        }
            
              
    }
    return true;
}


int main()
{
    //皇后的位置，每个数字代表皇后的位置
    //12345678
    //  1 2 3 4 5 6 7 8
    //1 Q| | | | | | | |
    //2  |Q| | | | | | |
    //3  | |Q| | | | | |
    //4  | | |Q| | | | |
    //5  | | | |Q| | | |
    //6  | | | | |Q| | |
    //7  | | | | | |Q| |
    //8  | | | | | | |Q|

    //15863724
    //  1 2 3 4 5 6 7 8
    //1 Q| | | | | | | |
    //2  | | | | | |Q| |
    //3  | | | |Q| | | |
    //4  | | | | | | |Q|
    //5  |Q| | | | | | |
    //6  | | |Q| | | | |
    //7  | | | | |Q| | |
    //8  | |Q| | | | | |    

    string strQueen = "12345678";

    int totalCount=0;       //8皇后的总数

    //全排列字符串
    do
    {
        if(CheckIs8Queen(strQueen))
        {
            ++totalCount;
            cout << strQueen << '\n';
        }
    } 
    while (next_permutation(strQueen.begin(), strQueen.end()));

    cout << "totalCount:" << totalCount << '\n';

    return 0;
}