//#include <graphics.h>  
//#include <conio.h>  
//#include <math.h>  
//
//#define BULLET_SPEED 50 // �ӵ��ٶ�  
//
//// С�˺��ӵ���ͼƬ·��  
//const char* bulletImagePath = "./bullet.png";
//
//// �ӵ��ṹ��  
//typedef struct {
//    int x, y; // �ӵ�λ��  
//    int targetX, targetY; // Ŀ��λ��  
//    int active; // �ӵ��Ƿ��Ծ  
//} Bullet;
//
//void fire(Bullet* bullet, int heroX, int heroY, int targetX, int targetY) {
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
//
//        // �����ӵ�λ��  
//        bullet->x += (int)(BULLET_SPEED * (dx / distance));
//        bullet->y += (int)(BULLET_SPEED * (dy / distance));
//    }
//}
//
//int main() {
//    initgraph(1280, 720); // ��ʼ��ͼ�δ���  
//    IMAGE hero, bullet;
//    loadimage(&bullet, bulletImagePath,67,32); // �����ӵ�ͼƬ    
//    Bullet bulletInstance = { 0 }; // ��ʼ���ӵ�  
//
//    while (1) {
//        // ����  
//        cleardevice();
//
//        // ����С��  
//        //putimage(heroX, heroY, &hero);
//
//        // ��ȡ���λ��  
//        POINT mousePos;
//        GetCursorPos(&mousePos);
//        ScreenToClient(GetHWnd(), &mousePos); // ת��Ϊ��������  
//
//        // ���ո�������ӵ�  
//        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
//            if (!bulletInstance.active) { // ֻ�����ӵ�δ����ʱ���ܷ���  
//                fire(&bulletInstance, heroX, heroY, mousePos.x, mousePos.y);
//            }
//        }
//
//        // �����ӵ�λ��  
//        updateBullet(&bulletInstance);
//
//        // �����ӵ�  
//        if (bulletInstance.active) {
//            putimage(bulletInstance.x, bulletInstance.y, &bullet);
//        }
//
//        // ˢ����Ļ  
//        Sleep(20); // ����֡��  
//    }
//
//    closegraph(); // �ر�ͼ�δ���  
//    return 0;
//}