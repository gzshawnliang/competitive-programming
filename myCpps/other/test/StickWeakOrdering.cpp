/*
===========================================================
 * @名称:		
 * @作者:	 Thomas    
 * @创建时间: 2018-03-19 20:39:30 
 * @修改人:   Thomas 
 * @修改时间: 2018-03-19 20:39:30 
 * @备注:    C++弱排序演示		
 * @题目来源： 
===========================================================
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <climits>
#include <map>

using namespace std;

struct point
{
    int x;
    int y;
};

bool operator<(const point &a, const point &b)
{
    if(a.x < b.x)
    {
        return true;
    } 
    else if(a.x == b.x)
    {
        if(a.y <b.y)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<point> pointVec1;

    pointVec1.push_back(point{2,2});
    pointVec1.push_back(point{1,2});
    pointVec1.push_back(point{1,4});
    //sort(pointVec1.begin(),pointVec1.end());

    set<point> pointSet1;
    //pointSet1.insert(point{2,2});
    
    pointSet1.insert(point{2,2});
    pointSet1.insert(point{1,2});
    //pointSet1.insert(point{1,4});

    map<point,string> pointMap1;
    pointMap1[point{2,2}]="ok";
    pointMap1[point{1,2}]="bad";
    pointMap1[point{1,2}]="ccc";

    cout << pointMap1[point{2,2}] << "\n";
    cout << pointMap1[point{1,2}] << "\n";

    return 0;
}