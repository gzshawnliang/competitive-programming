#include <bits/stdc++.h>

using namespace std;

//abcdefghijklmnopqrstuvwxyz0123456789
//ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789

// ifstream fin("lineSweep.in");
// ofstream fout("lineSweep.out");

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

  public:
    vector<double> y_axis;
    vector<node> tree;

    void calcul(int i)
    {
        if (tree[i].flag >= 1) //如果标记为>=1，则长度等于这个线段的高度
            tree[i].len = y_axis[tree[i].end] - y_axis[tree[i].start];
        else if (tree[i].start + 1 == tree[i].end) //如果为叶子阶段，且标记为0，则长度置0
            tree[i].len = 0;
        else //如果不是叶子节点，那么此节点的长度就是子节点的长度之和
            tree[i].len = tree[2 * i].len + tree[2 * i + 1].len;
    }

    segTree(vector<double> & y_axis1)
    {
        y_axis = y_axis1;
        tree.resize(y_axis1.size() * 4);
        tree.assign(y_axis1.size() * 4, node());
    }

    void build(int i, int s, int e)
    {
        //建立线段树
        tree[i].start = s;
        tree[i].end = e;
        tree[i].flag = 0; //长度和标记默认为0
        tree[i].len = 0;  //长度和标记默认为0

        //到达叶子节点
        if (s + 1 == e || s == e)
            return;

        int mid = (s + e) / 2;
        build(2 * i, s, mid); //递归建树，直到叶节点位置，直到每一段都是最小单位
        build(2 * i + 1, mid, e);
    }

    void updata(int i, int s, int e, int flag)
    {
        if (i > tree.size())
        {
            return;
        }
        if (tree[i].start == 0 && tree[i].end == 0)
        {
            return;
        }

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
    freopen("lineSweep.in", "r", stdin);
    freopen("lineSweep.out", "w", stdout);

    cout << fixed << setprecision(2);

    int caseT = 0;
    while (true)
    {
        int N = 0;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        ++caseT;
        //cout << caseT << "_____________________________"<<N<<"\n";
        vector<line> lines(N * 2); //竖线集合
        set<double> y_axisSet;     //Y坐标集合,使用set保证不重复
        int k = 0;
        for (int i = 0; i <= N - 1; ++i)
        {
            double x1, y1, x2, y2;
            //cin >> x1 >> y1 >> x2 >> y2;
            double s1, t1, s2, t2;
            cin >> s1 >> t1 >> s2 >> t2;

            x1 = min(s1, s2);
            y1 = min(t1, t2);
            x2 = max(s1, s2);
            y2 = max(t1, t2);

            y_axisSet.insert(y1);
            y_axisSet.insert(y2);

            int left = k;      //矩形左边竖线
            int right = k + 1; //矩形右边竖线

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
        sort(lines.begin(), lines.end()); //按x左边到右排序lines

        //使用vector访问Y坐标集合快一些
        vector<double> y_axis(y_axisSet.begin(), y_axisSet.end());

        //segTree * segTree1 = new segTree(y_axis);
        segTree segTree1(y_axis);

        segTree1.build(1, 0, y_axis.size() - 1);

        double totalArea = 0;

        //开始扫描线段
        for (int i = 0; i <= k - 1; ++i)
        {
            //找到这条线的下顶点所表示的线段下标
            int startY = lower_bound(y_axis.begin(), y_axis.end(), lines[i].y_start) - y_axis.begin();

            //找到这条线的上顶点所表示的线段下标
            int endY = lower_bound(y_axis.begin(), y_axis.end(), lines[i].y_end) - y_axis.begin();

            //更新这个两个下标所对应的线段的状态，line[I].flag传入的是1或者-1
            segTree1.updata(1, startY, endY, lines[i].flag);

            if ((size_t)i + 1 >= lines.size()) //最后一竖线不扫描
            {
                break;
            }
            //计算面积
            double h = segTree1.tree[1].len;
            double w = (lines[i + 1].x - lines[i].x);
            double currArea = h * w;

            totalArea += currArea; //面积累加
        }
        //delete segTree1;
        cout << "Test case #" << caseT << '\n';
        cout << "Total explored area: " << totalArea << "\n\n";
    }

    return 0;
}