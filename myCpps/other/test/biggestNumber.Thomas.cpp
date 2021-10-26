#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<queue>

using namespace std;

ifstream fin("biggestNumber.in");
ofstream fout("biggestNumber.out");

bool compare(string & string1, string & string2)
{
    int sizeA = string1.size(), sizeB = string2.size();
    if (sizeA == sizeB)
    {
        for (int i = 0; i <= sizeA - 1; ++i)
        {
            if (string1[i] != string2[i])
            {
                return string1[i] < string2[i];
            }
        }

        return true;
    }
    else
    {
        return sizeA < sizeB;
    }
}

bool g(int y, int x, int r, int c)
{
    return y >= 0 && y <= r - 1 && x >= 0 && x <= c - 1;
}

int deep(int nowY, int nowX, int r, int c, vector<vector<char>> & a, int count, vector<vector<bool>> path)
{
    if (g(nowY, nowX, r, c) == false)
    {
        return count;
    }
    else if (a[nowY][nowX] == '#' || path[nowY][nowX] == true)
    {
         return count;
    }
    else
    {
        path[nowY][nowX] = true;
        int maxDeepness = 0;
        maxDeepness = max(maxDeepness, deep(nowY + 1, nowX, r, c, a, count + 1, path));
        maxDeepness = max(maxDeepness, deep(nowY - 1, nowX, r, c, a, count + 1, path));
        maxDeepness = max(maxDeepness, deep(nowY, nowX + 1, r, c, a, count + 1, path));
        maxDeepness = max(maxDeepness, deep(nowY, nowX - 1, r, c, a, count + 1, path));

        return maxDeepness;
    }
}

int getMaxDeep(int nowY, int nowX, int r, int c, vector<vector<char>> & a, vector<vector<bool>> path)
{
    int count=0;
    queue<pair<int,int>> currQ;
    pair<int,int> nowNode(nowY,nowX);
    currQ.push(nowNode);
    path[nowY][nowX]=true;

	while(!currQ.empty())
	{
		nowNode = currQ.front();
		currQ.pop();

        int y1=nowNode.first + 1;
        int x1= nowNode.second;
        if (g(y1, x1, r, c) == true && a[y1][x1] != '#' && !path[y1][x1])
        {
            count++;
            path[y1][x1]=true;
            
            pair<int,int> nextNode(y1,x1);
            currQ.push(nextNode);
        }

        y1=nowNode.first - 1;
        x1= nowNode.second;
        if (g(y1, x1, r, c) == true && a[y1][x1] != '#' && !path[y1][x1])
        {
            count++;
            path[y1][x1]=true;
            
            pair<int,int> nextNode(y1,x1);
            currQ.push(nextNode);
        }

        y1=nowNode.first;
        x1= nowNode.second+1;
        if (g(y1, x1, r, c) == true && a[y1][x1] != '#' && !path[y1][x1])
        {
            count++;
            path[y1][x1]=true;
            
            pair<int,int> nextNode(y1,x1);
            currQ.push(nextNode);
        }  

        y1=nowNode.first;
        x1= nowNode.second-1;
        if (g(y1, x1, r, c) == true && a[y1][x1] != '#' && !path[y1][x1])
        {
            count++;
            path[y1][x1]=true;
            
            pair<int,int> nextNode(y1,x1);
            currQ.push(nextNode);
        }                

	}
    return count;
}


string ans;
void solve(int nowY, int nowX, int r, int c, vector<vector<char>> & a, string s, vector<vector<bool>> path)
{
    //vector<vector<bool>> temp(r, vector<bool>(c, false));
    
    if (g(nowY, nowX, r, c) == false)
    {
        if (compare(ans, s) == true)
        {
            ans = s;
            return;
        }
    }
    else if (a[nowY][nowX] == '#' || path[nowY][nowX] == true)
    {
        if (compare(ans, s) == true)
        {
            ans = s;
            return;
        }
    }
    else 
    {
        // vector<vector<bool>> temp= path;
        // int maxRemainDeep=deep(nowY, nowX, r, c, a, 0, temp);
        
        // if (s.size() + maxRemainDeep < ans.size())
        // {
        //     //fout << s.size() << ":" << maxDeep << ":" << ans.size() << '\n';
        //     //fout << s << '\n';
        //     return;
        // }
        // else
        // {
            

            //fout << s << '\n';
            
            int maxRemainDeep=getMaxDeep(nowY, nowX, r, c, a, path);
            //int maxRemainDeep=deep(nowY, nowX, r, c, a, 0, path);

            if (s.size() + maxRemainDeep < ans.size())
            {
                return;
            }            

            s += a[nowY][nowX];
            path[nowY][nowX] = true;

            solve(nowY + 1, nowX, r, c, a, s, path);
            solve(nowY - 1, nowX, r, c, a, s, path);
            solve(nowY, nowX + 1, r, c, a, s, path);
            solve(nowY, nowX - 1, r, c, a, s, path);
        //}
    }

}

int main_2()
{
    while (true)
    {
        ans = "0";
        int r = 0, c = 0;

        fin >> r >> c;

        if (r == 0)
        {
            break;
        }

        vector<vector<char>> a(r, vector<char>(c));
        vector<vector<bool>> path(r, vector<bool>(c, false));
        for (int y = 0; y <= r - 1; ++y)
        {
            for (int x = 0; x <= c - 1; ++x)
            {
                fin >> a[y][x];
            }
        }

        fout << getMaxDeep(1, 1, r, c, a, path) << '\n';
    }
}

int main()
{
    while (true)
    {
        ans = "0";
        int r = 0, c = 0;

        fin >> r >> c;

        if (r == 0)
        {
            break;
        }

        vector<vector<char>> a(r, vector<char>(c));
        vector<vector<bool>> path(r, vector<bool>(c, false));
        for (int y = 0; y <= r - 1; ++y)
        {
            for (int x = 0; x <= c - 1; ++x)
            {
                fin >> a[y][x];
            }
        }



        for (int y = 0; y <= r - 1; ++y)
        {
            for (int x = 0; x <= c - 1; ++x)
            {
                if (a[y][x] != '#')
                {
                    solve(y, x, r, c, a, "", path);
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}