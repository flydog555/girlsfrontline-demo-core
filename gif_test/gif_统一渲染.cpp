//#define _CRT_SECURE_NO_WARNINGS 1
//#include <graphics.h> 
//#include <easyx.h>
//#include <conio.h>  
//#include <stdio.h>  
//#include <math.h>
//#include <windows.h>
//#pragma comment( lib, "MSIMG32.LIB")
//#pragma comment(lib,"winmm.lib")
//#define BULLET_SPEED 40 // �ӵ��ٶ�  
//
//void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
//IMAGE background;
//extern IMAGE buffer; // ȫ�ֻ�����  
//extern CRITICAL_SECTION cs; // ������  
//extern int sign; // ��ɫ״̬��־  
//extern int x;    // ��ɫX����  
//extern int y;    // ��ɫY����  
//extern int* psign; // ָ���ɫ״̬��־��ָ��  
//extern int* px;    // ָ���ɫX�����ָ��  
//extern int* py;    // ָ���ɫY�����ָ��   
//
//const char* frames1[] = {
//    "./hk416_images_right/hk416mod_move_25_000.png",
//    "./hk416_images_right/hk416mod_move_25_001.png",
//    "./hk416_images_right/hk416mod_move_25_002.png",
//    "./hk416_images_right/hk416mod_move_25_003.png",
//    "./hk416_images_right/hk416mod_move_25_004.png",
//    "./hk416_images_right/hk416mod_move_25_005.png",
//    "./hk416_images_right/hk416mod_move_25_006.png",
//    "./hk416_images_right/hk416mod_move_25_007.png",
//    "./hk416_images_right/hk416mod_move_25_008.png",
//    "./hk416_images_right/hk416mod_move_25_009.png",
//    "./hk416_images_right/hk416mod_move_25_010.png",
//    "./hk416_images_right/hk416mod_move_25_011.png",
//    "./hk416_images_right/hk416mod_move_25_012.png",
//    "./hk416_images_right/hk416mod_move_25_013.png",
//    "./hk416_images_right/hk416mod_move_25_014.png",
//    "./hk416_images_right/hk416mod_move_25_015.png",
//    "./hk416_images_right/hk416mod_move_25_016.png",
//    "./hk416_images_right/hk416mod_move_25_017.png",
//    "./hk416_images_right/hk416mod_move_25_018.png",
//    "./hk416_images_right/hk416mod_move_25_019.png",
//    "./hk416_images_right/hk416mod_move_25_020.png",
//    "./hk416_images_right/hk416mod_move_25_021.png",
//    "./hk416_images_right/hk416mod_move_25_022.png",
//    "./hk416_images_right/hk416mod_move_25_023.png"
//};
//const char* frames2[] = {
//    "./hk416_images_right/hk416mod_wait_25_001.png",
//    "./hk416_images_right/hk416mod_wait_25_002.png",
//    "./hk416_images_right/hk416mod_wait_25_003.png",
//    "./hk416_images_right/hk416mod_wait_25_004.png",
//    "./hk416_images_right/hk416mod_wait_25_005.png",
//    "./hk416_images_right/hk416mod_wait_25_006.png",
//    "./hk416_images_right/hk416mod_wait_25_007.png",
//    "./hk416_images_right/hk416mod_wait_25_008.png",
//    "./hk416_images_right/hk416mod_wait_25_009.png",
//    "./hk416_images_right/hk416mod_wait_25_010.png",
//    "./hk416_images_right/hk416mod_wait_25_011.png",
//    "./hk416_images_right/hk416mod_wait_25_012.png",
//    "./hk416_images_right/hk416mod_wait_25_013.png",
//    "./hk416_images_right/hk416mod_wait_25_014.png",
//    "./hk416_images_right/hk416mod_wait_25_015.png",
//    "./hk416_images_right/hk416mod_wait_25_016.png",
//    "./hk416_images_right/hk416mod_wait_25_017.png",
//    "./hk416_images_right/hk416mod_wait_25_018.png",
//    "./hk416_images_right/hk416mod_wait_25_019.png",
//    "./hk416_images_right/hk416mod_wait_25_020.png",
//    "./hk416_images_right/hk416mod_wait_25_021.png",
//    "./hk416_images_right/hk416mod_wait_25_022.png",
//    "./hk416_images_right/hk416mod_wait_25_023.png",
//    "./hk416_images_right/hk416mod_wait_25_024.png",
//    "./hk416_images_right/hk416mod_wait_25_025.png",
//    "./hk416_images_right/hk416mod_wait_25_026.png",
//    "./hk416_images_right/hk416mod_wait_25_027.png",
//    "./hk416_images_right/hk416mod_wait_25_028.png",
//    "./hk416_images_right/hk416mod_wait_25_029.png",
//    "./hk416_images_right/hk416mod_wait_25_030.png",
//    "./hk416_images_right/hk416mod_wait_25_031.png",
//    "./hk416_images_right/hk416mod_wait_25_032.png",
//    "./hk416_images_right/hk416mod_wait_25_033.png",
//    "./hk416_images_right/hk416mod_wait_25_034.png",
//    "./hk416_images_right/hk416mod_wait_25_035.png",
//    "./hk416_images_right/hk416mod_wait_25_036.png",
//    "./hk416_images_right/hk416mod_wait_25_037.png",
//    "./hk416_images_right/hk416mod_wait_25_038.png",
//    "./hk416_images_right/hk416mod_wait_25_039.png",
//    "./hk416_images_right/hk416mod_wait_25_040.png",
//    "./hk416_images_right/hk416mod_wait_25_041.png",
//    "./hk416_images_right/hk416mod_wait_25_042.png",
//    "./hk416_images_right/hk416mod_wait_25_043.png",
//    "./hk416_images_right/hk416mod_wait_25_044.png",
//    "./hk416_images_right/hk416mod_wait_25_045.png",
//    "./hk416_images_right/hk416mod_wait_25_046.png",
//    "./hk416_images_right/hk416mod_wait_25_047.png",
//    "./hk416_images_right/hk416mod_wait_25_048.png",
//    "./hk416_images_right/hk416mod_wait_25_049.png",
//    "./hk416_images_right/hk416mod_wait_25_050.png",
//    "./hk416_images_right/hk416mod_wait_25_051.png",
//    "./hk416_images_right/hk416mod_wait_25_052.png",
//    "./hk416_images_right/hk416mod_wait_25_053.png"
//};
//const char* frames1_left[] =
//{
//    "./hk416_images_left/hk416mod_move_25_000.png",
//    "./hk416_images_left/hk416mod_move_25_001.png",
//    "./hk416_images_left/hk416mod_move_25_002.png",
//    "./hk416_images_left/hk416mod_move_25_003.png",
//    "./hk416_images_left/hk416mod_move_25_004.png",
//    "./hk416_images_left/hk416mod_move_25_005.png",
//    "./hk416_images_left/hk416mod_move_25_006.png",
//    "./hk416_images_left/hk416mod_move_25_007.png",
//    "./hk416_images_left/hk416mod_move_25_008.png",
//    "./hk416_images_left/hk416mod_move_25_009.png",
//    "./hk416_images_left/hk416mod_move_25_010.png",
//    "./hk416_images_left/hk416mod_move_25_011.png",
//    "./hk416_images_left/hk416mod_move_25_012.png",
//    "./hk416_images_left/hk416mod_move_25_013.png",
//    "./hk416_images_left/hk416mod_move_25_014.png",
//    "./hk416_images_left/hk416mod_move_25_015.png",
//    "./hk416_images_left/hk416mod_move_25_016.png",
//    "./hk416_images_left/hk416mod_move_25_017.png",
//    "./hk416_images_left/hk416mod_move_25_018.png",
//    "./hk416_images_left/hk416mod_move_25_019.png",
//    "./hk416_images_left/hk416mod_move_25_020.png",
//    "./hk416_images_left/hk416mod_move_25_021.png",
//    "./hk416_images_left/hk416mod_move_25_022.png",
//    "./hk416_images_left/hk416mod_move_25_023.png"
//};
//const char* frames2_left[] =
//{
//    "./hk416_images_left/hk416mod_wait_25_001.png",
//    "./hk416_images_left/hk416mod_wait_25_002.png",
//    "./hk416_images_left/hk416mod_wait_25_003.png",
//    "./hk416_images_left/hk416mod_wait_25_004.png",
//    "./hk416_images_left/hk416mod_wait_25_005.png",
//    "./hk416_images_left/hk416mod_wait_25_006.png",
//    "./hk416_images_left/hk416mod_wait_25_007.png",
//    "./hk416_images_left/hk416mod_wait_25_008.png",
//    "./hk416_images_left/hk416mod_wait_25_009.png",
//    "./hk416_images_left/hk416mod_wait_25_010.png",
//    "./hk416_images_left/hk416mod_wait_25_011.png",
//    "./hk416_images_left/hk416mod_wait_25_012.png",
//    "./hk416_images_left/hk416mod_wait_25_013.png",
//    "./hk416_images_left/hk416mod_wait_25_014.png",
//    "./hk416_images_left/hk416mod_wait_25_015.png",
//    "./hk416_images_left/hk416mod_wait_25_016.png",
//    "./hk416_images_left/hk416mod_wait_25_017.png",
//    "./hk416_images_left/hk416mod_wait_25_018.png",
//    "./hk416_images_left/hk416mod_wait_25_019.png",
//    "./hk416_images_left/hk416mod_wait_25_020.png",
//    "./hk416_images_left/hk416mod_wait_25_021.png",
//    "./hk416_images_left/hk416mod_wait_25_022.png",
//    "./hk416_images_left/hk416mod_wait_25_023.png",
//    "./hk416_images_left/hk416mod_wait_25_024.png",
//    "./hk416_images_left/hk416mod_wait_25_025.png",
//    "./hk416_images_left/hk416mod_wait_25_026.png",
//    "./hk416_images_left/hk416mod_wait_25_027.png",
//    "./hk416_images_left/hk416mod_wait_25_028.png",
//    "./hk416_images_left/hk416mod_wait_25_029.png",
//    "./hk416_images_left/hk416mod_wait_25_030.png",
//    "./hk416_images_left/hk416mod_wait_25_031.png",
//    "./hk416_images_left/hk416mod_wait_25_032.png",
//    "./hk416_images_left/hk416mod_wait_25_033.png",
//    "./hk416_images_left/hk416mod_wait_25_034.png",
//    "./hk416_images_left/hk416mod_wait_25_035.png",
//    "./hk416_images_left/hk416mod_wait_25_036.png",
//    "./hk416_images_left/hk416mod_wait_25_037.png",
//    "./hk416_images_left/hk416mod_wait_25_038.png",
//    "./hk416_images_left/hk416mod_wait_25_039.png",
//    "./hk416_images_left/hk416mod_wait_25_040.png",
//    "./hk416_images_left/hk416mod_wait_25_041.png",
//    "./hk416_images_left/hk416mod_wait_25_042.png",
//    "./hk416_images_left/hk416mod_wait_25_043.png",
//    "./hk416_images_left/hk416mod_wait_25_044.png",
//    "./hk416_images_left/hk416mod_wait_25_045.png",
//    "./hk416_images_left/hk416mod_wait_25_046.png",
//    "./hk416_images_left/hk416mod_wait_25_047.png",
//    "./hk416_images_left/hk416mod_wait_25_048.png",
//    "./hk416_images_left/hk416mod_wait_25_049.png",
//    "./hk416_images_left/hk416mod_wait_25_050.png",
//    "./hk416_images_left/hk416mod_wait_25_051.png",
//    "./hk416_images_left/hk416mod_wait_25_052.png",
//    "./hk416_images_left/hk416mod_wait_25_053.png"
//};
//
//
//int frameCount1 = sizeof(frames1) / sizeof(frames1[0]); // ����֡��  
//int frameCount2 = sizeof(frames2) / sizeof(frames2[0]); // ����֡�� 
//int frameCount1_left = sizeof(frames1_left) / sizeof(frames1_left[0]);
//int frameCount2_left = sizeof(frames2_left) / sizeof(frames2_left[0]);
////int frameCount2 = 20;
//
////int x = 100;
////int y = 100;
////int*px = &x;
////int*py = &y;
////int sign = 0;
////int* psign= &sign;
////int* mx;
////int* my;
//
//typedef struct {
//    int x, y; // �ӵ�λ��  
//    int targetX, targetY; // Ŀ��λ��  
//    int active; // �ӵ��Ƿ��Ծ  
//} Bullet;
//
//Bullet bulletInstance; // �ӵ�ʵ��   
//
//
//void playAnimation(const char* frames[], int frameCount, int a, int s, IMAGE* buffer) {
//    for (int i = 0; i < frameCount; i++) {
//        EnterCriticalSection(&cs);
//        if (*psign != a) {
//            break;
//        }
//
//        IMAGE img;
//        loadimage(&img, frames[i]); // ���ص�ǰ֡ͼ��  
//
//        // ���������  
//        cleardevice();
//
//        // ����ǰ֡���Ƶ�������  
//        transparentimage3(buffer, *px, *py, &img); // ����ǰ֡���Ƶ�������  
//
//        // �����������ݻ��Ƶ���Ļ��  
//        //putimage(0, 0, buffer);
//        LeaveCriticalSection(&cs);
//        Sleep(20); // ���Ʋ����ٶȣ����Ը�����Ҫ����  
//    }
//}
//
//void keymove() {
//    while (true) {
//        *psign = 0;
//        // ������״̬  
//        if (GetAsyncKeyState('W') < 0) {
//            *py -= 10;
//            *psign = 1;
//        }
//        if (GetAsyncKeyState('S') < 0) {
//            *py += 10;
//            *psign = 1;
//        }
//        if (GetAsyncKeyState('A') < 0) {
//            *px -= 10;
//            *psign = 2;
//        }
//        if (GetAsyncKeyState('D') < 0) {
//            *px += 10;
//            *psign = 1;
//        }
//
//        // �߽���  
//        if (*px < 0) *px = 0;
//        if (*px > 1280 - 100) *px = 1280 - 100;
//        if (*py < 0) *py = 0;
//        if (*py > 720 - 100) *py = 720 - 100; // ����֡�߶�Ϊ100  
//
//        Sleep(50); // ����ˢ��Ƶ�ʣ����Ը�����Ҫ����  
//    }
//}
//
//void mouse_track() {
//    BeginBatchDraw(); // ��ʼ��������  
//
//    while (true) { // �����������  
//        EnterCriticalSection(&cs);
//        POINT mousePos;
//        GetCursorPos(&mousePos); // ��ȡ���λ��  
//        ScreenToClient(GetHWnd(), &mousePos); // ת��Ϊ�ͻ�������  
//
//        // ���������  
//        cleardevice();
//
//        // ���Ʊ���  
//        IMAGE background;
//        loadimage(&background, "����.png", 1280, 720);
//        putimage(0, 0, &background);
//
//        // �������λ��  
//        setcolor(RED);
//        circle(mousePos.x, mousePos.y, 10); // �������ԲȦ  
//        setlinecolor(RED);
//        setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
//        line(mousePos.x, mousePos.y, *px + 170, *py + 170); // ��������  
//
//        // ��������������ʾ����Ļ  
//        //putimage(0, 0, &buffer); // �����������ݻ��Ƶ���Ļ  
//
//        // ����ǰ�������ݱ��浽������  
//        getimage(&buffer, 0, 0, 1280, 720);
//        LeaveCriticalSection(&cs);
//        Sleep(10); // ����ˢ���ٶ�  
//    }
//
//    EndBatchDraw(); // ������������  
//}
//
//void HK416run() {
//    EnterCriticalSection(&cs); // ����  
//    if (*psign == 1) {
//        playAnimation(frames1, frameCount1, *psign, 1, &buffer);
//    }
//    else if (*psign == 2) {
//        playAnimation(frames1_left, frameCount1_left, *psign, 1, &buffer);
//    }
//    else if (*psign == 0) {
//        playAnimation(frames2, frameCount2, *psign, 1, &buffer);
//    }
//    LeaveCriticalSection(&cs); // ����  
//    Sleep(1);
//}
//
//void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg) {
//    HDC dstDC = GetImageHDC(dstimg);
//    HDC srcDC = GetImageHDC(srcimg);
//    int w = srcimg->getwidth();
//    int h = srcimg->getheight();
//    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
//    AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
//}
//
//void fire_move(Bullet* bullet, int heroX, int heroY, int targetX, int targetY) {
//    bullet->x = heroX;
//    bullet->y = heroY;
//    bullet->targetX = targetX;
//    bullet->targetY = targetY;
//    bullet->active = 1; // �����ӵ�  
//}
//
//void updateBullet(Bullet* bullet) {
//    if (bullet->active) {
//        // �����ӵ��ķ���  
//        int dx = bullet->targetX - bullet->x;
//        int dy = bullet->targetY - bullet->y;
//        double distance = sqrt(dx * dx + dy * dy);
//
//        // ����ӵ�����Ŀ��λ�ã�ͣ���ӵ�  
//        if (distance < BULLET_SPEED) {
//            bullet->active = 0;
//            return;
//        }
//        // �����ӵ�λ��  
//        bullet->x += (int)(BULLET_SPEED * (dx / distance));
//        bullet->y += (int)(BULLET_SPEED * (dy / distance));
//    }
//}
//
//void fire() {
//    IMAGE bulletImage;
//    loadimage(&bulletImage, "./bullet.png", 67, 32); // �����ӵ�ͼƬ    
//    bulletInstance.active = 0; // ��ʼ���ӵ�Ϊ����Ծ  
//
//    while (1) {
//        EnterCriticalSection(&cs); // ����  
//        // ��ȡ���λ��  
//        POINT mousePos;
//        GetCursorPos(&mousePos);
//        ScreenToClient(GetHWnd(), &mousePos); // ת��Ϊ��������  
//
//        // ��������������ӵ�  
//        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
//            if (!bulletInstance.active) { // ֻ�����ӵ�δ����ʱ���ܷ���  
//                fire_move(&bulletInstance, *px + 170, *py + 170, mousePos.x, mousePos.y);
//            }
//        }
//
//        // �����ӵ�λ��  
//        updateBullet(&bulletInstance);
//
//        // ���������  
//        cleardevice();
//
//        // �����ӵ���������  
//        if (bulletInstance.active) {
//            putimage(bulletInstance.x, bulletInstance.y, &bulletImage);
//        }
//
//        // ��������������ʾ����Ļ  
//        //putimage(0, 0, &buffer); // �������ѡ����ͳһ��Ⱦ���߳��д���  
//
//        LeaveCriticalSection(&cs); // ����  
//        Sleep(20); // ����֡��  
//    }
//}
