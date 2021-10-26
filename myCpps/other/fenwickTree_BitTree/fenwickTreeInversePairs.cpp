/*
树状数组求逆序对
*/
#include<bits/stdc++.h>

using namespace std;

class fenwickTree1index
{
    private:
    int n;
    int lowbit(int x)
    {
        return (x & (-x));
    }

    public:

    vector<int> s;

    fenwickTree1index(vector<int> & in)
    {
        n = in.size();
        s.assign(n+1, 0);
    }
    void print()
    {
        for (int i = 1; i <= n; ++i)
            cout << s[i] << " ";

        cout << "\n";
    }

    //更新操作，将第pos个位置的值加上delta
    void update(int pos, int delta)
    {
        for (int i = pos; i <= n; i += lowbit(i))
            s[i] += delta;
    }

    //查询操作，查询[1,pos]的和
    int query(int pos)
    {
        int ans = 0;

        for (int i = pos; i >= 1; i -= lowbit(i))
            ans += s[i];

        return ans;
    }

    //查询区间[i,j]的和
    int sum(int i, int j)
    {
        return query(j) - query(i - 1);
    }
};

class fenwickTree
{
    private:

    vector<int> a;
    vector<int> s;

    int lowbit(int x)
    {
        return x & (-x);
    }

    public:

    fenwickTree(vector<int> & in)
    {
        int n = in.size();

        a.assign(n, 0);
        s.assign(n + 1, 0);

        for (int i = 0; i <= n - 1; ++i)
        {
            update(i, in[i]);
        }
    }

    void update(int k, int delta)
    {
        ++k;

        a[k - 1] += delta;

        int n = s.size();

        for (int i = k; i <= n; i += lowbit(i))
        {
            s[i] += delta;
        }
    }

    int query(int k)
    {
        ++k;

        int ans = 0;

        for (int i = k; i >= 1; i -= lowbit(i))
        {
            ans += s[i];
        }

        return ans;
    }

    int sum(int i, int j)
    {
        return query(j) - query(i - 1);
    }
};

int main()
{
    //vector<int> b = {5, 3, 4, 2, 1};

    vector<int> b = {4, 2 ,1 ,5 ,3};
    vector<int> a(b.size(),0);

    fenwickTree1index tree(a);
    
    int ans=0;  //逆序对数量
    for (int i = 1; i <= (int)b.size() ; ++i)
    {
        tree.update(b[i-1],1);
        tree.print();
        cout << setw(10) << "query(" << b[i-1] << ")=" << tree.query(b[i-1]) << "\n";
        ans += i- tree.query(b[i-1]) ;
    }
    
    cout << ans << "\n";
    int i=(2 & (-2));
    cout << i << "\n";

    // tree.update(5,1);
    // cout << 1- tree.query(5) << '\n';

    // tree.update(3,1);
    // cout << 2- tree.query(3) << '\n';

    // tree.update(4,1);
    // cout << 3- tree.query(4) << '\n';


    // tree.update(2,1);
    // cout << 4- tree.query(2) << '\n';

    // tree.update(1,1);
    // cout << 5- tree.query(1) << '\n';

    return 0;
}