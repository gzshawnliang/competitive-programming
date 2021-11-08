/***********************************************************
 * @����:		������⣬���ز���ģ��
 * @���Shawnomas 
 * @����ʱ��: 2017-11-16 21:23:21 
 * @�޸��Shawnhomas 
 * @�޸�ʱ��: 2017-11-24 07:38:58
 * @��ע:		
 * @��Ŀ��Դ�� 
***********************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

void pauseMe()
{
    #ifdef _WIN32
        //Windows�µ���ʹ����ͣ����
        system("pause");
    #else
        //Linux�µ�����ͣ
        cout << "Press ENTER key to continue...";
        cin.clear();
        cin.get(); 
    #endif    
}

void solve()
{
    /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    �����㷨����
    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    // string cins = "";
    // vector<string> vec1;
    // int i = 0;
    // while (!cin.eof())
    // {

    //     string s1 = "";
    //     cin >> s1;

    //     if(s1.size()>0)
    //     {
    //         vec1.push_back(s1);
            
    //     }
    //     vec1.push_back(s1);
    //     ++i;
    // }

    //�������
    // int i2=1000;
    // cout << vec1[i2] << endl;

    //c++ 11��׼
    // vector<vector<int>> vec2;
    // vector<int> vec3;
    // vec3.push_back(34);
    // vec2.push_back(vec3);

    //SET����        
    set<int> set1;

    set1.insert(10);
    set1.insert(100);
    set1.insert(50);
    set1.insert(20);
    set1.insert(40);
    set1.insert(10);
    
    set<int>::iterator it=set1.end();
    advance(it, -3);
    //++it;       
    cout << *it << '\n';
    //cout <<set1[3] << endl;
    //cout<<*(--set1.end())<<endl;
    
    cout << 15893 % 10000 << '\n';
    //cout << s << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    #ifndef DEBUG
        //F11
        //���¶����׼iostream(cin/cout)���ļ�
        freopen("oj_template.in", "r", stdin);
        freopen("oj_template.out", "w", stdout);
    #endif        
#endif

#ifdef CODE_STATISTICS
    //CRL+ F11 
    //����ʼʱ��
    clock_t tStart = clock();
#endif

    solve();


#ifndef ONLINE_JUDGE
    #ifndef DEBUG
        //F11
        fclose(stdin);
        fclose(stdout);
    #endif        
#endif

#ifdef CODE_STATISTICS
    //CRL+ F11 
    //�����������ʱ��
    cout << "The Program has completed running after " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " seconds\n";
    pauseMe();
#endif

#ifdef DEBUG
    //F5
    pauseMe();
#endif

    return 0;
}