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

const int INF=INT_MAX;

class SegTree
{
  private:
    int sourSize;           //原数组的大小
    vector<int> sour;       //原数组
    vector<int> segTree;    //线段树的数组

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

    int query(int left,int right,int node,int nodeLeft,int nodeRight)
    {
        //两个区间不重叠
        if(nodeRight < left || right < nodeLeft )
        {
            return INF;
        }
        
        //查询的区间包含节点的区间
        if(nodeLeft >= left && nodeRight <= right )
        {
            return segTree[node];
        }

        //查分两个区间计算合并结果
        int mid = (nodeLeft + nodeRight) / 2;
        int r1 = query(left,right,node*2,nodeLeft,mid);
        int r2 = query(left,right,node*2+1,mid+1,nodeRight);
        return min(r1,r2);
    }

    int update(int index,int newVal,int node,int nodeLeft,int nodeRight)
    {
        //index不在区间内
        if(index > nodeRight || index < nodeLeft )
        {
            return INF;
        }
        
        //已经是叶节点
        if(nodeLeft == nodeRight )
        {
            sour[index] = newVal;
            segTree[node] = newVal;
            return newVal;
        }

        //查分两个区间计算合并结果
        int mid = (nodeLeft + nodeRight) / 2;
        int r1 = update(index,newVal,node*2,nodeLeft,mid);
        int r2 = update(index,newVal,node*2+1,mid+1,nodeRight);
        segTree[node]=min(r1,r2);
        return segTree[node];
    }

  public:
    SegTree(const vector<int> & p_Sour)
    {
        sour = p_Sour;
        sourSize = sour.size();
        segTree.assign(sourSize * 4, INF);
        
        iniSeqTree(0, sourSize - 1, 1);
    }

    int query(int left,int right)
    {
        return query(left,right,1,0,sourSize-1);
    }

    int update(int index,int newVal)
    {
        return update(index,newVal,1,0,sourSize-1);
    }    

    void printSource()
    {
        for(auto i:sour)
            cout << i << " ";
        cout << "\n";
    }
};

vector<int> readData()
{
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
    return vec1;    
}

int main()
{
    vector<int> vec1=readData();
    SegTree sTree(vec1);
    
    cout << "1~3:" << sTree.query(1,3) << "\n"; 
    cout << "2~5:" << sTree.query(2,5) << "\n"; 
    cout << "3~4:" << sTree.query(3,4) << "\n"; 
    cout << "2~8:" << sTree.query(2,8) << "\n"; 
    cout << "5~9:" << sTree.query(5,6) << "\n"; 

    sTree.update(6,4);
    cout << "sur:" ;
    sTree.printSource();
    cout << "5~9:" << sTree.query(5,6) << "\n"; 

    return 0;
}
