#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <set>
#include <bitset>
using namespace std;

int main()
{
    bitset<10> v1;              //����10λ��bitset����
    v1 = 8;                     //��v1��ֵΪ8
    bitset<10> v2(v1);          //��ʼ������v1��ͬ
    bitset<10> v3 = v2;         //��ֵ��=v2
    
    // ���������������ұߵ�Ϊ��һλ���������μ�1
    v1[1] = 1;//��v1�ĵ�һλ��Ϊ1
    //v1.set(1);

    cout << "v1=" << v1 << endl;//�ö����Ƶ���ʽ���v1
    cout << "v2=" << v2 << endl;
    cout << "v3=" << v3 << endl;
    
    for (int i = (int)(v1.size()) - 1; i >= 0; --i)//һλһλ�����
        cout << v1[i];
    cout << endl;
    
    cout << "any() --- \t" << v1.any() << endl;
    cout << "count() --- \t" << v1.count() << endl;
    cout << "flip --- \t" << v1.flip() << endl;
    cout << "none() --- \t" << v1.none() << endl;
    
    //���������÷�����

    return 0;
}