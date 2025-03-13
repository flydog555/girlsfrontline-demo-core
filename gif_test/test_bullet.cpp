//#include <graphics.h>  
//#include <conio.h>  
//#include <math.h>  
//
//#define BULLET_SPEED 50 // 子弹速度  
//
//// 小人和子弹的图片路径  
//const char* bulletImagePath = "./bullet.png";
//
//// 子弹结构体  
//typedef struct {
//    int x, y; // 子弹位置  
//    int targetX, targetY; // 目标位置  
//    int active; // 子弹是否活跃  
//} Bullet;
//
//void fire(Bullet* bullet, int heroX, int heroY, int targetX, int targetY) {
//    bullet->x = heroX;
//    bullet->y = heroY;
//    bullet->targetX = targetX;
//    bullet->targetY = targetY;
//    bullet->active = 1; // 激活子弹  
//}
//
//void updateBullet(Bullet* bullet) {
//    if (bullet->active) {
//        // 计算子弹的方向  
//        int dx = bullet->targetX - bullet->x;
//        int dy = bullet->targetY - bullet->y;
//        double distance = sqrt(dx * dx + dy * dy);
//
//        // 如果子弹到达目标位置，停用子弹  
//        if (distance < BULLET_SPEED) {
//            bullet->active = 0;
//            return;
//        }
//
//        // 更新子弹位置  
//        bullet->x += (int)(BULLET_SPEED * (dx / distance));
//        bullet->y += (int)(BULLET_SPEED * (dy / distance));
//    }
//}
//
//int main() {
//    initgraph(1280, 720); // 初始化图形窗口  
//    IMAGE hero, bullet;
//    loadimage(&bullet, bulletImagePath,67,32); // 加载子弹图片    
//    Bullet bulletInstance = { 0 }; // 初始化子弹  
//
//    while (1) {
//        // 清屏  
//        cleardevice();
//
//        // 绘制小人  
//        //putimage(heroX, heroY, &hero);
//
//        // 获取鼠标位置  
//        POINT mousePos;
//        GetCursorPos(&mousePos);
//        ScreenToClient(GetHWnd(), &mousePos); // 转换为窗口坐标  
//
//        // 检测空格键发射子弹  
//        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
//            if (!bulletInstance.active) { // 只有在子弹未激活时才能发射  
//                fire(&bulletInstance, heroX, heroY, mousePos.x, mousePos.y);
//            }
//        }
//
//        // 更新子弹位置  
//        updateBullet(&bulletInstance);
//
//        // 绘制子弹  
//        if (bulletInstance.active) {
//            putimage(bulletInstance.x, bulletInstance.y, &bullet);
//        }
//
//        // 刷新屏幕  
//        Sleep(20); // 控制帧率  
//    }
//
//    closegraph(); // 关闭图形窗口  
//    return 0;
//}