#include<bits/stdc++.h>
#include "MyRandom.h"

using namespace std;

struct Node
{
    int v;
    int flag;
};

Node _Node(int v, int flag)
{
    Node temp{v, flag};
    return temp;
};

class SegTree
{
  private:
    int sizeA;
    vector<int> a;
    vector<Node> _segTree;

    int query(int l, int r, int i, int nowLeft, int nowRight)
    {
        if (nowRight < l || nowLeft > r)
        {
            return 0;
        }
        
        if(_segTree[i].flag !=0)
        {
            _segTree[i].v += ((nowRight - nowLeft + 1) * _segTree[i].flag);
            if(nowLeft != nowRight)
            {
                _segTree[i * 2].flag += _segTree[i].flag;
                _segTree[i * 2 + 1].flag += _segTree[i].flag;
            }
            _segTree[i].flag = 0;
        }

        if (nowLeft >=l && nowRight <=r)
        {
            return _segTree[i].v;
        }        

        int m = (nowLeft + nowRight) / 2;

        return query(l, r, i * 2, nowLeft, m) + query(l, r, i * 2 + 1, m + 1, nowRight);
    }

    void update(int l, int r, int v, int i, int nowLeft, int nowRight)
    {
        if(_segTree[i].flag !=0)
        {
            _segTree[i].v += ((nowRight - nowLeft + 1) * _segTree[i].flag);
            if(nowLeft != nowRight)
            {
                _segTree[i * 2].flag += _segTree[i].flag;
                _segTree[i * 2 + 1].flag += _segTree[i].flag;
            }
            _segTree[i].flag = 0;
        }

        if (r < nowLeft || l > nowRight)
        {
            return;
        }

        if (nowLeft >= l && nowRight <= r)
        {
            _segTree[i].v += v*(nowRight - nowLeft + 1);
            
            if (nowLeft != nowRight)
            {
                _segTree[i * 2].flag += v;
                _segTree[i * 2 + 1].flag += v;
            }            
            return;
        }        

        int m = (nowLeft + nowRight) / 2;

        update(l, r, v, i * 2, nowLeft, m);
        update(l, r, v, i * 2 + 1, m + 1, nowRight);
        _segTree[i].v = _segTree[i * 2].v + _segTree[i * 2+1].v;
    }

  public:
    SegTree(const vector<int> & p_Sour)
    {
        a = p_Sour;
        sizeA = a.size();
        _segTree.assign(sizeA * 4, _Node(0, 0));
        for (int i = 0; i <= sizeA - 1; ++i)
            update(i, i, a[i]);
    }

    int query(int l, int r)
    {
        return query(l, r, 1, 0, sizeA - 1);
    }

    void update(int l, int r, int v)
    {
        update(l, r, v, 1, 0, sizeA - 1);
    }
};

int main()
{
    vector<int> a = {6,16,2,13,20,11,14,14,13,6};

    SegTree segTree1(a);

    segTree1.update(3, 5, 10);
    cout << segTree1.query(2, 5) << '\n';


    segTree1.update(1, 5, 10);
    cout << segTree1.query(2, 5) << '\n';

    segTree1.update(5, 8, 10);
    cout << segTree1.query(2, 4) << '\n';


    segTree1.update(1, 7, 10);
    cout << segTree1.query(2, 7) << '\n';            

    return 0;
}


