#include <bits/stdc++.h>

using namespace std;

/*
    二维dp压缩使用的位运算
*/
class bitOperator
{
    int Cols =4;
    
    public:
    bitOperator(int maxCols)
    {
        Cols = maxCols;
    }

    /**
     * 返回第i行第j列是0还是1
     * @param  {int} i : 第i行
     * @param  {int} j : 第j列
     * @param  {int} m : 数值
     * @return {int}   : 0或1
     */
    int get(int i, int j, int m)
    {
        return ((1 << (i * Cols + j)) & m) != 0;
    }

    /**
     * 反转第i行第j列的值，0变1,1变0
     * @param  {int} i : 第i行
     * @param  {int} j : 第j列
     * @param  {int} m : 数值
     */
    void flip(int i, int j, int & m)
    {
        m ^= (1 << (i * Cols + j));
        
    }

    /**
     * 设置第i行第j列的值是1
     * @param  {int} i : 第i行
     * @param  {int} j : 第j列
     * @param  {int} m : 数值
     */
    void set1(int i, int j, int & m)
    {
        m |= (1 << (i * Cols + j));
        
    }

    /**
     * 设置第i行第j列的值是0
     * @param  {int} i : 第i行
     * @param  {int} j : 第j列
     * @param  {int} m : 数值
     */
    void set0(int i, int j, int & m)
    {
        m &= ~(1 << (i * Cols + j));
        
    }

    /**
     * 输出m代表的二维阵列
     * @param  {int} m : 只读
     */
    void printArray(const int & m)
    {
        for (int i = 0; i <= 4 - 1; ++i)
        {
            cout << setw(11);
            for (int j = 0; j <= 4 - 1; ++j)
            {
                cout << get(i, j, m) << " ";
            }
            cout << '\n';
        }
    }

    /**
     * 输出m代表的二进制
     * @param  {int} m : 只读
     */
    void printBin(const int & m)
    {
        cout << setw(6) << m << " -> " << bitset<16>(m).to_string() << '\n';    
    }

};


int main()
{
    bitOperator bitOp(4);
    int k = 1 << 16;
    cout << k << "\n";

    int m = 785;
    bitOp.printBin(m);
    bitOp.printArray(m);

    bitOp.set0(1, 0, m);
    bitOp.printBin(m);
    bitOp.printArray(m);

    return 0;
}


int main3()
{

    int a =1 << 3;
    cout << setw(6) << a << " -> "  << bitset<16>(a).to_string() << '\n'; 

    return 0;
}
