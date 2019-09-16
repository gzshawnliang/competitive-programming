#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main()
{
	initgraph(640, 480);

    string text = "Simon is dog.";

    RECT r = {0, 0, 639, 479};
	drawtext(_T("Hello World"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


    while (true);

	// 关闭图形窗口
	closegraph();
}