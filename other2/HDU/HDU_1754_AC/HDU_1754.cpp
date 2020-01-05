/*---------------------------------------------
*   日期：2015-03-24
*   作者：SJF0115
*   题目: 1754.I Hate It
*   来源：HDU
*   网址：http://acm.hdu.edu.cn/showproblem.php?pid=1754
*   结果：AC
*   博客：
-----------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define Max 200001

struct IntervalTreeNode{
    int left,right,mid;
    int weight;
};

IntervalTreeNode interval[3*Max];

// 把当前结点的信息更新到父结点
void PushUp(int num){
    // 左右子节点的最大值作为父节点的值
    interval[num].weight = max(interval[2*num].weight,interval[2*num+1].weight);
}

// 创建线段树
void Create(int left,int right,int num,int w[]){
    interval[num].left = left;
    interval[num].right = right;
    interval[num].mid = left + (right - left) / 2;
    // 叶子节点
    if(left == right){
        interval[num].weight = w[left-1];
        return;
    }//if
    Create(left,interval[num].mid,2*num,w);
    Create(interval[num].mid+1,right,2*num+1,w);
    // 把当前结点的信息更新到父结点
    PushUp(num);
}
// 表示第pos个学生的成绩改为score
void Update(int pos,int score,int left,int right,int num){
    // 叶子节点
    if(left == right){
        interval[num].weight = score;
        return;
    }//if
    // 左子区间
    int mid = interval[num].mid;
    if(pos <= mid){
        Update(pos,score,left,mid,2*num);
    }//if
    // 右子区间
    else{
        Update(pos,score,mid+1,right,2*num+1);
    }
    // 子节点修改同时修改父节点
    PushUp(num);
}
// 查询区间[start,end]
int Query(int left,int right,int num){
    if(interval[num].left == left && interval[num].right == right){
        return interval[num].weight;
    }//if
    if(right <= interval[num].mid){
        return Query(left,right,2*num);
    }//if
    else if(left > interval[num].mid){
        return Query(left,right,2*num+1);
    }//if
    else{
        return max(Query(left,interval[num].mid,2*num),Query(interval[num].mid+1,right,2*num+1));
    }//else
}


int main(){

    freopen("HDU_1754.in", "r", stdin);      
    freopen("HDU_1754.out", "w", stdout);  

    int N,M,a,b;
    char op[2];
    int score[Max];
    while(scanf("%d %d",&N,&M) != EOF){
        // 学生
        for(int i = 0;i < N;++i){
            scanf("%d",&score[i]);
        }//for
        // 创建线段树
        Create(1,N,1,score);
        // 操作
        for(int i = 0;i < M;++i){
            scanf("%s %d %d",op,&a,&b);
            if(op[0] == 'Q'){
                cout<<Query(a,b,1)<<endl;
            }//if
            else if(op[0] == 'U'){
                Update(a,b,1,N,1);
            }//if
        }
    }//while
    return 0;
}