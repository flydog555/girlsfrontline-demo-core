//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <graphics.h>  
//#include <conio.h>  
//
//int main() {
//    // 初始化图形窗口  
//    initgraph(640, 480);
//
//    // 设置背景颜色  
//    setbkcolor(WHITE);
//    cleardevice();
//
//    // 主循环  
//    while (1) {
//        // 获取鼠标位置  
//        POINT mousePos;
//        GetCursorPos(&mousePos);
//        ScreenToClient(GetHWnd(), &mousePos);
//
//        // 清除之前的内容  
//        cleardevice();
//
//        // 绘制鼠标位置  
//        setcolor(RED);
//        circle(mousePos.x, mousePos.y, 5); // 绘制一个半径为5的红色圆圈表示鼠标位置  
//
//        // 显示鼠标坐标  
//        char buffer[50];
//        sprintf(buffer, "Mouse Position: (%d, %d)", mousePos.x, mousePos.y);
//        outtextxy(10, 10, buffer); // 在窗口左上角显示坐标  
//
//        // 检测退出条件  
//        if (_kbhit()) {
//            break; // 按下任意键退出  
//        }
//
//        // 延时以减少CPU占用  
//        Sleep(10);
//    }
//
//    // 关闭图形窗口  
//    closegraph();
//    return 0;
//}