/***********************************************************
 * @名称:		递归实现全排列
 * @作者:		Thomas 
 * @创建时间: 2018-02-09 08:08:19 
 * @修改人:   Thomas
 * @修改时间: 2018-02-09 08:08:19 
 * @备注:		
 * @题目来源： 
***********************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
using namespace std;

string PermutationString;

void print_permutation(int n,string result)
{
    if(n>=PermutationString.size())
    {
        cout << result << "\n";
        return;
    }
    else if(n==0)
    {
        result.push_back(PermutationString[n]);   
        print_permutation(n+1,result);
    }
    else
    {
        for(int i=0;i<=result.size();++i)
        {
            string insertString = "";
            insertString.push_back(PermutationString[n]);

            string resultTemp=result;
            resultTemp.insert(i,insertString);
            //result.insert(i,insertString);
            print_permutation(n+1,resultTemp);
        }
    }
}

int main()
{
    PermutationString="ACBD";
    
    string result="";
    print_permutation(0,result);
    cout << endl;
    //system("pause");
    return 0;
}