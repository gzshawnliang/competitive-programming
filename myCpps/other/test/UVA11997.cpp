/***********************************************************
 * @����:		uva 11997 - K Smallest Sums
 * @����:		����ʥ 
 * @����ʱ��: 2017-12-10 21:27:36 
 * @�޸���:   ����ʥ 
 * @�޸�ʱ��: 2017-12-10 21:27:36 
 * @��ע:	    ���ȶ���\̰��
***********************************************************/
#include <algorithm>
#include <fstream>
#include <functional> //Ϊ��ʹ�����ȶ��е�greater
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

struct IntAtArray
{
    int value;
    int pos_1;
    int pos_2;
    bool operator<(const IntAtArray & newArrayInt2) const
    {
        return value > newArrayInt2.value;
    };
};


vector<int> mergeVector2(vector<int> &vec1, vector<int> &vec2)
{
    int total = vec1.size();
    priority_queue<int, vector<int>, greater<int> > mergeToQueue;
    for (int i = 0; i <= total - 1; ++i)
    {
        for (int j = 0; j <= total - 1; ++j)
        {
            mergeToQueue.push(vec1[i] + vec2[j]);
        }
    }
    vector<int> result;
    for (int i = 0; i <= total - 1; ++i)
    {
        result.push_back(mergeToQueue.top());
        mergeToQueue.pop();
    }
    return result;
}

vector<int> mergeVector(vector<int> &vec1, vector<int> &vec2)
{
    int total = vec1.size();
    priority_queue<IntAtArray> mergeToQueue;

    vector<int> result;

    for (int j = 0; j <= total - 1; ++j)
    {
        IntAtArray iniValue={vec1[j] + vec2[0],j,0};
        mergeToQueue.push(iniValue);
    }

    result.push_back(mergeToQueue.top().value);
    mergeToQueue.pop();

    int i=0;
    int j=1;
    do
    {
        IntAtArray tempValue={vec1[i] + vec2[j],i,j};
        mergeToQueue.push(tempValue);

        //��С�ĳ���.�ŵ�����
        IntAtArray smallestValue=mergeToQueue.top();
        result.push_back(smallestValue.value);
        mergeToQueue.pop();

        i=smallestValue.pos_1;
        j=smallestValue.pos_2+1;
    } while (result.size()<total);

    return result;
}

void solve()
{

    while (!cin.eof())
    {
        /*****************************************
         * ��������
        *****************************************/        
        int total = 0;
        cin >> total;
        if (total == 0)
        {
            return;
        }

        //priority_queue<int> numbersQueue;
        priority_queue<int, vector<int>, greater<int> > numbersQueue;
        vector<vector<int> > inputDataVec;
        for (int i = 0; i <= total - 1; ++i)
        {
            vector<int> vec1;
            for (int j = 0; j <= total - 1; ++j)
            {
                int n;
                cin >> n;
                vec1.push_back(n);
            }
            sort(vec1.begin(), vec1.end());
            inputDataVec.push_back(vec1);
        }
        
        /*****************************************
         * ʹ�üӷ��ϲ�����
        *****************************************/        
        vector<int> vec1 = inputDataVec[0];
        vector<int> vec2 = inputDataVec[1];
        vector<int> vecMerge=mergeVector(vec1, vec2);
        for (int i = 2; i <= total - 1; ++i)
        {
            vecMerge = mergeVector(inputDataVec[i], vecMerge);
        }
        for (int n = 0; n <= total - 1; ++n)
        {
            cout << vecMerge[n];
            if(n==total-1)
            {
                cout << '\n';
            }
            else
            {
                cout << ' ';
            }
        }
        
    }
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("KsmallSums.in", "r", stdin);
        freopen("KsmallSums.out", "w", stdout);
    #endif    

    ios::sync_with_stdio(false);
    std::cin.tie(0);    

    solve();

    cout.flush();       //��Ҫ,ʹ��flushˢ��cout����

    #ifndef ONLINE_JUDGE
        fclose(stdin);
        fclose(stdout);
    #elif _WIN32
        system("pause");
    #endif
    



    return 0;
}