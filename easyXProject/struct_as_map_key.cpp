#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct point
{
    int x;
    int y;
};

bool operator<(const point &a, const point &b)
{
    return a.x + a.y < b.x + b.y;
}

int main()
{
    map<point, bool> map1;
    point point0;
    point0.x=100;
    point0.y=200;
    cout << "out:" << (map1[point0] == 1) << endl;
    cout << map1.size() << endl;

    point point1;
    point1.x=100;
    point1.y=200;
    map1[point1]=true;
    cout << map1.size() << endl;

    point point2;
    point2.x=120;
    point2.y=300;
    map1[point2]=true;
    cout << map1.size() << endl;

    point point3;
    point3.x=150;
    point3.y=250;
    map1[point3]=true;
    cout << map1.size() << endl;

    point point4;
    point4.x=200;
    point4.y=400;
    map1[point4]=true;        
    cout << map1.size() << endl;

#ifdef CODE_STATISTICS
    cout << "Press ENTER key to continue...";
    cin.clear();
    cin.get();
#endif
    return 0;
}