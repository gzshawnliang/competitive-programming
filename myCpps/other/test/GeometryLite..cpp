/*
计算几何
*/
/* 需要包含的头文件 */ 
#include <cmath > 
#include <algorithm>  
#include <iostream> 

using namespace std; 

/* 常用的常量定义 */ 
const double	INF		= 1E200;    
const double	EP		= 1E-10 ;
const int		MAXV	= 300 ;
const double	PI		= 3.14159265 ;
 
/* 基本几何结构 */ 

struct Point_I
{ 
	int x; 
	int y; 
	Point_I(int a=0, int b=0) //constructor 
	{
		 x=a; 
		 y=b;
	} 
}; 

struct Point 
{ 
	double x; 
	double y; 
	Point(double a=0.0, double b=0.0) //constructor 
	{
		 x=a; 
		 y=b;
	} 
}; 

struct Line           // 直线的解析方程 a*x+b*y+c=0  为统一表示，约定 a >= 0 
{ 
   double a; 
   double b; 
   double c; 
   Line(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;} 
};


struct LineSeg 
{ 
	Point s; 
	Point e; 
	LineSeg(Point a, Point b) { s=a; e=b;} 
	LineSeg() { } 
}; 
 
 
/**********************
 *                    * 
 *   点的基本运算       * 
 *                    * 
 **********************/ 
 
double dist(Point p1,Point p2)                // 返回两点之间欧氏距离 
{ 
	return (sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) ); 
} 
bool equal_point(Point p1,Point p2)           // 判断两个点是否重合  
{ 
	return ( (abs(p1.x-p2.x)<EP)&&(abs(p1.y-p2.y)<EP) ); 
} 

int main()
{
	Point_I a(1,2);
	Point b(1.0,2.0);
	return 0;
}

