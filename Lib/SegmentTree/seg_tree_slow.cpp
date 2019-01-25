#include<bits/stdc++.h>

using namespace std;

class node
{
    int l;
    int r;
    int sum;
};

class segTree
{
    private:

    vector<int> a;

    vector<node> tree;

    void build()
    {
        
    }

    public:

    segTree(vector<int> & in)
    {
        a = in;
        
        //build segTree
        build();
    }

    void update(int i, int delta)
    {
        a[i] = a[i] + delta;
    }

    int querySum(int i, int j)
    {
        int ans = 0;
        for (int k = i; k <= j; ++k)
        {
            ans += a[k];
        }

        return ans;
    }
};

int main()
{
    vector<int> a = {6,16,2,13,20,11,14,14,13,6};

    segTree segTree1(a);

    segTree1.update(2, 5);

    cout << segTree1.querySum(2, 4) << '\n';

    return 0;
}