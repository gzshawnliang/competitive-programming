#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct point
{
    int x;
    int y;
    point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
};

int main2()
{
    auto sortByX = [](point &a, point &b) {
        return a.x < b.x;
    };

    auto printerVec = [](vector<point> &v) {
        for (auto e : v)
        {
            cout << "(" << e.x << "," << e.y << ") ";
        }
        cout << "\n";
    };

    auto sortByY = [](point &a, point &b) {
        return a.y < b.y;
    };

    vector<point> vec1 = {point(1, 2), point(2, 3), point(3, 6), point(1, 0), point(5, 1)};
    cout << "before sort:";
    printerVec(vec1);
    sort(vec1.begin(), vec1.end(), [](point &a, point &b) {
        return a.y < b.y;
    });
    cout << "after sort:";
    printerVec(vec1);

    return 0;
}

int main()
{
    int i = 100;int j = 200;
    auto f1 =[i,j](int x,int y) mutable
    {
        ++x;
        ++y;
        ++i;
        ++j;
    }; 
    f1(2, 3);
    cout << i << "," << j << "\n";
    
    // Call function
    int num1 = [](int a, int b){ return a + b; }(1, 2);
    
    // Call function
    [](){ cout << "Hello World!" << endl; }();

    return 0;
}
