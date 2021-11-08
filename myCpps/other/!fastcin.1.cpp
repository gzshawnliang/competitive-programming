/***********************************************************
 * @����:		����cin/cout
 * @���Shawnomas 
 * @����ʱ��: 2017-11-21 21:51:55 
 * @�޸��Shawnhomas 
 * @�޸�ʱ��: 2017-11-21 21:51:55 
 * @��ע:		
 * @��Ŀ��Դ�� 
 * http://www.hankcs.com/program/cpp/cin-tie-with-sync_with_stdio-acceleration-input-and-output.html
 * https://heavywatal.github.io/cxx/speed.html
 * http://chino.taipei/note-2016-0311C-��ݔ����cin-cout��scanf-printf�l���^�죿/
***********************************************************/
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    //�ر�scanf/printfͬ��,
    //���������һ�����Ƿ����stdio���Ŀ��أ�
    //C++Ϊ�˼���C����֤������ʹ����std::printf
    //��std::cout��ʱ�򲻷������ң������������һ��
    ios_base::sync_with_stdio(false);       

    //��Ĭ�ϵ������cin�󶨵���cout��
    //ÿ��ִ�� << ��������ʱ��Ҫ����flush������������IO������
    //���¹ر�cin/coutͬ��
    std::cin.tie(NULL);                     
    
    freopen("bigdata.in2", "r", stdin);      
    freopen("bigdata.out", "w", stdout);     

    //���ݼ�������� cin TLE�����
    int a = 0;
    for(int i = 0; i < (int)1e7; ++i){
        cin>>a;
    }

    //���һ��Ҫִ��flushˢ�»���
    cout.flush();

    //�ر��������������
    fclose(stdin);
    fclose(stdout);
    return 0;
}
