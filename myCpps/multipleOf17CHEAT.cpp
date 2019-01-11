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

ifstream fin("multipleOf17.in");
ofstream fout("multipleOf17.out");

struct sint
{
    vector<int> v;

    sint()
    {
        //默认构造函数
    }

    sint(long long i)
    {
        //从string构造数据
        this->read(std::to_string(i));
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

        if ((*this) == newbigInt)
        {
            vector<int> temp = {0};
            result.v = temp;
            return result;
        }

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

    string toString()
    {
        string ans = "";
        int size = this->v.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            ans += this->v[i] + '0';
        }

        return ans;
    }

    sint operator/(const sint &newbigInt)
    {
        sint result(0);
        sint a = *(this);
        sint b = newbigInt;
        
        int tens = a.v.size() - b.v.size();
        while (a >= b)
        {
            sint temp0 = b;
            sint temp1(1);
            sint ten(10);
            for (int i = 1; i <= tens; ++i)
            {
                temp0.v.push_back(0);
                temp1.v.push_back(0);
            }
            while (a >= temp0)
            {
                result = result + temp1;
                a = a - temp0;
            }
            --tens;
        }

        return result;
    }

    sint operator%(const sint &newbigInt)
    {
        return (*this) - ((*this) / newbigInt) * newbigInt;
    }

    void read(string s)
    {
        int size = s.size();
        this->v.clear();
        for (int i = 0; i <= size - 1; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                this->v.push_back(s[i] - '0');
            }
        }
    }    

    sint pow(const int times)
    {
        int n = times;
        sint result(1);
        sint nowNum = *this; 
        while (n > 0)
        {
            if (n & 1)  //判断奇偶，等同于 n % 2 == 1;      
            {
                result = result * nowNum;
            }
            nowNum = nowNum * nowNum;

            n >>= 1;    //等同于 n /= 2;
        }

        return result;
    }
};

int main()
{
    sint n17(17);
    sint n0(0);

    while (true)
    {
        string in;
        fin >> in;

        if (in == "0")
        {
            break;
        }

        sint n(in);

        if (n % n17 == n0)
        {
            fout << 1 << '\n';
        }
        else
        {
            fout << 0 << '\n';
        }
    }
}