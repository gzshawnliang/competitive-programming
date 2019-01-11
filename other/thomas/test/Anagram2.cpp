#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;

bool compareString(const string &a, const string &b)
{
    int n=a.size();
    for (int i = 0; i <= n-1; ++i)
    {
        int tempA=0,tempB=0;
        bool changeA=false,changeB=false;
        if(a=="")
        {
            return false;
        }
        if(b=="")
        {
            return true;
        }
        if(a[i]>=97 && a[i]<=122)
        {
            tempA=a[i]-32;
            changeA=true;
        }
        else
        {
            tempA=a[i];
        }
        if(b[i]>=97 && b[i]<=122)
        {
            tempB=b[i]-32;
            changeB=true;
        }
        else
        {
            tempB=b[i];
        }

        if(tempA<tempB)
        {
            return true;
        }
        else if(tempB<tempA)
        {
            return false;
        }
        else if(tempA==tempB && changeA==true && changeB!=true)
        {
            return false;
        }
        else if(tempA==tempB && changeB==true && changeA!=true)
        {
            return true;
        }
        else
        {
            continue;
        }
    }
}


bool compareString2(const char &a, const char &b)
{
    int tempA = 0, tempB = 0;
    bool changeA = false, changeB = false;
    if (a >= 97 && a <= 122)
    {
        tempA = a - 32;
        changeA = true;
    }
    else
    {
        tempA = a;
    }
    if (b >= 97 && b <= 122)
    {
        tempB = b - 32;
        changeB = true;
    }
    else
    {
        tempB = b;
    }
    if (tempA < tempB)
    {
        return true;
    }
    else if (tempB < tempA)
    {
        return false;
    }
    else if (tempA == tempB && changeA == true && changeB != true)
    {
        return false;
    }
    else if (tempA == tempB && changeB == true && changeA != true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compareString3(const char &a, const char &b) {
    
    if(tolower(a) == tolower(b))
    {
        //如果字母一样，但大小写不同，大写放前面
        return a < b;
    }
    else
    {
        //如果字母不一样，不管大小写，按abcd..排序
        return tolower(a) < tolower(b);
    }
}

int main()
{
    ifstream fin("Anagram.in");
    ofstream fout("Anagram.out");
    int n=0;
    string s="";
    fin>>n;
    for(int i=0;i<n;++i)
    {
        fin >> s;
        sort(s.begin(), s.end(), compareString2);
        vector<string> ss;
        do
        {
            fout << s << "\n";
        } 
        while (next_permutation(s.begin(), s.end(),compareString2));
    }

    //system("pause");
    return 0;
}


