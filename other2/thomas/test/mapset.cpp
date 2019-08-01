#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

bool Set_IsExist(const multiset<string> & mset1,const string & value)
{
    if(mset1.find(value) ==mset1.end())
        return false;
    
    return true;

}

int main()
{
    multiset<string> mset1={"abc","def","ghi","abc","jkl"};

    //判断元素是否存在
    cout << Set_IsExist(mset1,"abc0") << "\n";

    //查找元素范围
    auto ret = mset1.equal_range("abc");

    if(ret.first==ret.second)
    {
        cout << "no found" << "\n";
    }
    else
    {
        for (auto it2=ret.first; it2!=ret.second; ++it2)
        {
            cout  << "found:" << distance(mset1.begin(),it2) << ":" << *it2 << "\n";
        }
    }


    return 0;
}