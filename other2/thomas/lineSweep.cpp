#include <bits/stdc++.h>

using namespace std;

ifstream fin("lineSweep.in");
ofstream fout("lineSweep.out");

//abcdefghijklmnopqrstuvwxyz0123456789
//ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789

class line
{
  public:
    double y_start; //y_start是y轴下顶点坐标
    double y_end;   //y_end是y轴的上顶点坐标
    double x;       //x轴的坐标
    int flag;       //标记，矩形左边是1，右边是-1

    bool operator<(const line & p) const
    {
        return x < p.x;
    }
};

class node
{
  public:
    int start;  //线段的起点
    int end;    //线段的终点
    int flag;   //标记，表示是否需要把这一段加入到面积的计算中
    double len; //长度
    node()
    {
        start = 0;
        end = 0;
        flag = 0;
        len = 0;
    }
};

class segTree
{
  private:
    vector<int> y_axis;

    void calcul(int i)
    {
        if (tree[i].flag >= 1) //如果标记为>=1，则长度等于这个线段的高度
            tree[i].len = y_axis[tree[i].end] - y_axis[tree[i].start];
        else if (tree[i].start + 1 == tree[i].end) //如果为叶子阶段，且标记为0，则长度置0
            tree[i].len = 0;
        else //如果不是叶子节点，那么此节点的长度就是子节点的长度之和
            tree[i].len = tree[2 * i].len + tree[2 * i + 1].len;
    }

  public:
    vector<node> tree;

    segTree(vector<int> & y_axis1)
    {
        y_axis = y_axis1;
        tree.assign(y_axis1.size() * 4, node());
    }

    void build(int i, int s, int e)
    {
        //建立线段树
        tree[i].start = s;
        tree[i].end = e;
        tree[i].flag = 0; //长度和标记默认为0
        tree[i].len = 0;  //长度和标记默认为0
        if (s + 1 == e)
            return;

        int mid = (s + e) / 2;
        build(2 * i, s, mid); //递归建树，直到叶节点位置，直到每一段都是最小单位
        build(2 * i + 1, mid, e);
    }

    void updata(int i, int s, int e, int flag)
    {
        if (tree[i].start > e || tree[i].end < s) //不符合条件
            return;

        if (tree[i].start >= s && tree[i].end <= e) //这个段在指定下标所在段之间
        {
            tree[i].flag += flag; //累加标记，1-1=0可以抵消标记
            calcul(i);            //计算这个一段的有效长度（能加入面积计算的长度）
            return;
        }
        updata(2 * i, s, e, flag); //如果这个段不在指定下标所在的段之间，就遍历子节点
        updata(2 * i + 1, s, e, flag);
        calcul(i);
    }
};

int main()
{
    int N;
    fin >> N;
    vector<line> lines(N * 2);  //竖线集合
    set<int> y_axisSet;         //Y坐标集合,使用set保证不重复
    int k = 0;
    for (int i = 0; i <= N - 1; ++i)
    {
        double  x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        
        y_axisSet.insert(y1);
        y_axisSet.insert(y2);

        int left = k;       //矩形左边竖线
        int right = k + 1;  //矩形右边竖线

        lines[left].flag = 1;
        lines[right].flag = -1;

        lines[left].x = x1;
        lines[right].x = x2;

        lines[left].y_start = y1;
        lines[right].y_start = y1;

        lines[left].y_end = y2;
        lines[right].y_end = y2;

        k += 2;
    }
    sort(lines.begin(), lines.end());   //按x左边到右排序lines

    //使用vector访问Y坐标集合快一些
    vector<int> y_axis(y_axisSet.begin(),y_axisSet.end());

    segTree segtree1(y_axis);
    segtree1.build(1, 0, y_axis.size() - 1);

    int totalArea = 0;
    
    //开始扫描线段
    for (int i = 0; i <= k - 1; ++i)
    {
        if ((size_t) i + 1 >= lines.size())  //最后一竖线不扫描
        {
            break;
        }

        //找到这条线的下顶点所表示的线段下标
        int startY = lower_bound(y_axis.begin(), y_axis.end(), lines[i].y_start) - y_axis.begin();

        //找到这条线的上顶点所表示的线段下标
        int endY = lower_bound(y_axis.begin(), y_axis.end(), lines[i].y_end) - y_axis.begin();

        //更新这个两个下标所对应的线段的状态，line[I].flag传入的是1或者-1
        segtree1.updata(1, startY, endY, lines[i].flag);

        //面积累加
        int currArea = segtree1.tree[1].len * (lines[i + 1].x - lines[i].x);
        cout << "h:" << segtree1.tree[1].len << ",w:" << lines[i + 1].x - lines[i].x << ",Area" << currArea << '\n';
        totalArea += currArea;
    }
    fout << totalArea << '\n';

    return 0;
}
