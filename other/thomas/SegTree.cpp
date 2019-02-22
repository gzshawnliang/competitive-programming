/***********************************************************
 * @Name:               SegTree
 * @Created by:         Thomas
 * @Create DateTime:    2019-01-09 20:14:07
 * @Modify by:          Thomas
 * @Modify DateTime:    2019-01-09 20:14:07
 * @Description:        
***********************************************************/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("SegTree.in");
ofstream fout("SegTree.out");

class SegTree
{
  private:
    /* data */
    int sourSize;
    vector<int> sour;
    vector<int> segTree;

    void iniSeqTree(int left, int right, int node)
    {
        if (left == right)
        {
            segTree[node] = sour[left];
            return;
        }
        int mid = (left + right) / 2;
        int nexLevLeft = node * 2;      //下层的左节点
        int nexLevRight = node * 2 + 1; //下层的右节点

        iniSeqTree(left, mid, nexLevLeft);
        iniSeqTree(mid + 1, right, nexLevRight);

        segTree[node] = min(segTree[nexLevLeft], segTree[nexLevRight]);
    }

  public:
    SegTree(const vector<int> & p_Sour)
    {
        sour = p_Sour;
        sourSize = sour.size();
        segTree.assign(sourSize * 4, 0);
        iniSeqTree(0, sourSize - 1, 1);
    }

    query(int left,int right)
    {
        
    }
};

int main()
{
    //code
    vector<int> vec1;
    while (true)
    {
        int n;
        fin >> n;
        if (!fin.good())
        {
            break;
        }
        vec1.push_back(n);
    }
    SegTree sTree(vec1);

    return 0;
}
