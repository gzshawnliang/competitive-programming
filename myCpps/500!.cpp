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

ifstream fin("500!.in");
ofstream fout("500!.out");

struct sint
{
    vector<int> v;

    bool operator<(const sint &newbigInt)
    {
        int size0 = v.size();
        int size1 = newbigInt.v.size();
        if (size0 != size1)
        {
            return size0 < size1;
        }
        else
        {
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (v[i] != newbigInt.v[i])
                {
                    return v[i] < newbigInt.v[i];
                }
            }
        }
        return false;
    }

    bool operator>(const sint &newbigInt)
    {
        int size0 = v.size();
        int size1 = newbigInt.v.size();
        if (size0 != size1)
        {
            return size0 > size1;
        }
        else
        {
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (v[i] != newbigInt.v[i])
                {
                    return v[i] > newbigInt.v[i];
                }
            }
        }
        return false;
    }

    bool operator<=(const sint &newbigInt)
    {
        return !((*this) > newbigInt);
    }

    bool operator>=(const sint &newbigInt)
    {
        return !((*this) < newbigInt);
    }

    bool operator==(const sint &newbigInt)
    {
        int size0 = v.size();
        int size1 = newbigInt.v.size();
        if (size0 != size1)
        {
            return false;
        }
        else
        {
            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (v[i] != newbigInt.v[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    sint operator+(const sint &newbigInt)
    {
        sint result;

        vector<int> big, small;
        if (v.size() > newbigInt.v.size())
        {
            big = v;
            small = newbigInt.v;
        }
        else
        {
            small = v;
            big = newbigInt.v;
        }

        int size0 = big.size();
        int size1 = small.size();
        vector<int> ans(size0);
        
        for (int i = 1; i <= size0 - size1; ++i)
        {
            small.insert(small.begin(), 0);
        }

        int last = 0;
        for (int i = size0 - 1; i >= 0; --i)
        {
            int nowNum = last + big[i] + small[i];
            ans[i] = nowNum % 10;
            last = nowNum >= 10;

            if (i == 0 && last == 1)
            {
                ans.insert(ans.begin(), 1);
            }
        }

        result.v = ans;

        return result;
    }  

    sint operator-(const sint &newbigInt)
    {
        sint result;

        vector<int> big, small;
        if (v.size() >= newbigInt.v.size())
        {
            big = v;
            small = newbigInt.v;
        }
        else
        {
            small = v;
            big = newbigInt.v;
        }

        int size0 = big.size();
        int size1 = small.size();
        vector<int> ans(size0);
        
        for (int i = 1; i <= size0 - size1; ++i)
        {
            small.insert(small.begin(), 0);
        }

        int last = 0;
        for (int i = size0 - 1; i >= 0; --i)
        {
            if (last == 1)
            {
                --big[i];
            }
            if (big[i] < small[i])
            {
                last = 1;
                big[i] += 10;
            }
            else
            {
                last = 0;
            }

            ans[i] = big[i] - small[i];
        }

        while(ans[0] == 0)
        {
            ans.erase(ans.begin());
        }

        result.v = ans;

        return result;
    }
    
    sint operator*(const sint &newbigInt)
    {
        sint result;

        vector<int> big, small;
        if (v.size() > newbigInt.v.size())
        {
            big = v;
            small = newbigInt.v;
        }
        else
        {
            small = v;
            big = newbigInt.v;
        }

        int size0 = big.size();
        int size1 = small.size();

        vector<int> empty = {0};
        result.v = empty;
        sint temp0(big);

        for (int i = size1 - 1; i >= 0; --i)
        {
            sint temp1(empty);
            for (int c = 1; c <= small[i]; ++c)
            {
                temp1 = temp1 + temp0;
            }
            for (int c = 1; c <= size1 - i - 1; ++c)
            {
                temp1.v.push_back(0);
            }
            result = result + temp1;
        }

        return result;
    }

    string to_string()
    {
        string ans = "";
        int size = this->v.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            ans += this->v[i] + '0';
        }

        return ans;
    }

    void read(string s)
    {
        int size = s.size();
        this->v.clear();
        for (int i = 0; i <= size - 1; ++i)
        {
            this->v.push_back(s[i] - '0');
        }
    }    

 
    // sint operator+=(const sint &newbigInt)
    // {
    //     return *(this) + newbigInt;
    // }

    // sint operator-=(const sint &newbigInt)
    // {
    //     return *(this) - newbigInt;
    // }

    // sint operator*=(const sint &newbigInt)
    // {
    //     return *(this) * newbigInt;
    // }

    sint pow(const sint &newbigInt)
    {
        sint whe0, whe1, result;
        whe0.read("1");
        whe1 = *this;
        result.read("1");

        for (sint i = whe0; i <= newbigInt; i = i + whe0)
        {
            result = whe1 * result;
        }

        return result;
    }

    sint()
    {
        //默认构造函数
    }

    sint(string s)
    {
        //从string构造数据
        this->read(s);
    }

    sint(vector<int> & s)
    {
        //从vector<int>构造数据
        this->v=s;
    }
};

int main()
{
    vector<string> store = {"1"};
    sint ans("1");
    sint nowTimes("1");
    sint one("1");
    for (int i = 1; i <= 1000; ++i)
    {
        ans = ans * nowTimes;
        string temp = ans.to_string();
        nowTimes = nowTimes + one;
        store.push_back(temp);
    }

    while (true)
    {
        int in = -1;
        fin >> in;

        if (in == -1)
        {
            break;
        }

        fout << in << "!\n" << store[in] << '\n';
    }
    
    return 0;
}