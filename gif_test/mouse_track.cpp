//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <graphics.h>  
//#include <conio.h>  
//
//int main() {
//    // ��ʼ��ͼ�δ���  
//    initgraph(640, 480);
//
//    // ���ñ�����ɫ  
//    setbkcolor(WHITE);
//    cleardevice();
//
//    // ��ѭ��  
//    while (1) {
//        // ��ȡ���λ��  
//        POINT mousePos;
//        GetCursorPos(&mousePos);
//        ScreenToClient(GetHWnd(), &mousePos);
//
//        // ���֮ǰ������  
//        cleardevice();
//
//        // �������λ��  
//        setcolor(RED);
//        circle(mousePos.x, mousePos.y, 5); // ����һ���뾶Ϊ5�ĺ�ɫԲȦ��ʾ���λ��  
//
//        // ��ʾ�������  
//        char buffer[50];
//        sprintf(buffer, "Mouse Position: (%d, %d)", mousePos.x, mousePos.y);
//        outtextxy(10, 10, buffer); // �ڴ������Ͻ���ʾ����  
//
//        // ����˳�����  
//        if (_kbhit()) {
//            break; // ����������˳�  
//        }
//
//        // ��ʱ�Լ���CPUռ��  
//        Sleep(10);
//    }
//
//    // �ر�ͼ�δ���  
//    closegraph();
//    return 0;
//}