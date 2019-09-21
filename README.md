# BuildAndTest.ps1 功能

**快捷键**

F5，运行并调试

F8，仅规编不运行

F11，常规编译运行，如存在out和ok文件则自动比较

F10，常规编译运行，使用Dev-C++模式弹出窗口，好处是可以在弹出dos窗口进行cin输入

CTL+F11，编译运行,如存在out和ok文件则自动比较
运行时候，使用文件重定向到标准in/out，检测in文件规则如下：
* #1）c++文件移除拓展名cpp +.in
* #2）c++文件移除拓展名移除OJ后缀 +.in
* #3）Input.in
* #4）Input.txt
* #5）input.in
* #6）input.txt
* #out文件=in文件名移除拓展名.out

检测不到就不重新定向

Shift+F11，目录对比out文件

Ctl+Alt+F11，编译，运行使用全部in文件（当前目录）进行测试，每个in文件运行一次