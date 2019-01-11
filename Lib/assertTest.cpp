//#define NDEBUG
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //code
    // C++11 style further ahead
    auto m = std::map<int, std::string>{{1, "Ann"}};
    m[1] = "Ben0";
    //assert(m.at(1) == "1Ben");
    
    assert(false);
    
    m = std::map<int, std::string>{{1, "Ann"}};
    m.insert({1,"Ben"});
    assert(m.at(1) == "Ann"); 
    
    return 0;
}
