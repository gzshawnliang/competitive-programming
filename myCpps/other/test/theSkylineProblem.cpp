/*
===========================================================
 * @名称:		105 - The Skyline Problem
 * @作者:		Shawn 
 * @创建时间: 2018-05-28 10:42:08 
 * @修改人:   Shawn 
 * @修改时间: 2018-05-28 10:42:08 
 * @备注:		
 * @题目来源： http://uva.onlinejudge.org/external/1/105.pdf
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

using namespace std;

struct Building
{
    int left;
    int height;
    int right;

    Building(int l,int h,int r)
    {
        left=l;
        height =h;
        right =r;
    }

};


int main()
{
    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);                     
    
    freopen("theSkylineProblem.in", "r", stdin);      
    freopen("theSkylineProblem.out", "w", stdout);
    
    vector<Building> buildings;
    int maxRight=0;
    while(true)
    {
        int l=0;
        int h=0;
        int r=0;
        cin >>l>>h>>r;
        if(l==0)
        {
            break;
        }
        Building newBuilding(l,h,r);
        buildings.push_back(newBuilding);
        maxRight=max(maxRight,r);
    }

    if(!buildings.empty())
    {
        vector<int> skyline(maxRight,0);

        for(int i=0;i<=buildings.size()-1;++i)
        {
            for(int j=buildings[i].left;j<buildings[i].right;++j)
            {
                skyline[j]=max(skyline[j],buildings[i].height);
            }
            
        }        
        
        for(int i=1;i<=skyline.size()-1;++i)
        {
            if(skyline[i] != skyline[i-1])
            {
                cout<< i << " ";
                cout<< skyline[i] << " ";
            }
            
        }
        cout<< skyline.size() << " ";


        cout<< 0 << "\n";
    }

    cout.flush();

    fclose(stdin);
    fclose(stdout);
    return 0;
}