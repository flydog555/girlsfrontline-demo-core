//#include <graphics.h>  
//#include <windows.h>  
//#include <process.h>  
//#include <stdio.h>  
//
//// 全局变量  
//
//IMAGE buffer; // 全局缓冲区  
//CRITICAL_SECTION cs; // 互斥锁  
//int sign; // 角色状态标志  
//int x;    // 角色X坐标  
//int y;    // 角色Y坐标  
//int* psign = &sign; // 指向角色状态标志的指针  
//int* px = &x;       // 指向角色X坐标的指针  
//int* py = &y;       // 指向角色Y坐标的指针  
//
//
//extern void keymove();
//extern void HK416run();
//extern void mouse_track();
//extern void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
//extern void fire();
//
//// 线程函数声明  
//void Thread1(void* arg); // 键盘输入  
//void Thread2(void* arg); // 小人动画  
//void Thread3(void* arg); // 鼠标追踪  
//void Thread4(void* arg); // 开火动画  
//void Thread5(void* arg); // 统一渲染  
//
//// 线程句柄  
//HANDLE h1, h2, h3, h4, h5;
//
//// 线程1：键盘输入  
//void Thread1(void* arg) {
//    keymove();
//}
//
//// 线程2：小人动画  
//void Thread2(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // 加锁  
//        HK416run(); // 在缓冲区上绘制小人动画  
//        LeaveCriticalSection(&cs); // 解锁  
//        Sleep(10);
//    }
//}
//
//// 线程3：鼠标追踪  
//void Thread3(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // 加锁  
//        mouse_track(); // 在缓冲区上绘制鼠标追踪  
//        LeaveCriticalSection(&cs); // 解锁  
//        Sleep(10);
//    }
//}
//
//// 线程4：开火动画  
//void Thread4(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // 加锁  
//        fire(); // 在缓冲区上绘制开火动画  
//        LeaveCriticalSection(&cs); // 解锁  
//        Sleep(10);
//    }
//}
//
//// 线程5：统一渲染  
//void Thread5(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // 加锁  
//        putimage(0, 0, &buffer); // 将缓冲区内容显示到屏幕  
//        LeaveCriticalSection(&cs); // 解锁  
//        Sleep(10); // 控制刷新频率  
//    }
//}
//
//int main() {
//    // 初始化图形窗口  
//    initgraph(1280, 720);
//    getimage(&buffer, 0, 0, 1280, 720); // 创建与窗口大小相同的图像  
//
//    // 初始化互斥锁  
//    InitializeCriticalSection(&cs);
//
//    // 创建线程  
//    h1 = (HANDLE)_beginthread(Thread1, 0, NULL); // 线程1：键盘输入  
//    h2 = (HANDLE)_beginthread(Thread2, 0, NULL); // 线程2：小人动画  
//    h3 = (HANDLE)_beginthread(Thread3, 0, NULL); // 线程3：鼠标追踪  
//    h4 = (HANDLE)_beginthread(Thread4, 0, NULL); // 线程4：开火动画  
//    h5 = (HANDLE)_beginthread(Thread5, 0, NULL); // 线程5：统一渲染  
//
//    // 等待线程结束  
//    WaitForSingleObject(h1, INFINITE);
//    WaitForSingleObject(h2, INFINITE);
//    WaitForSingleObject(h3, INFINITE);
//    WaitForSingleObject(h4, INFINITE);
//    WaitForSingleObject(h5, INFINITE);
//
//    // 删除互斥锁  
//    DeleteCriticalSection(&cs);
//
//    // 关闭图形窗口  
//    closegraph();
//    printf("主线程结束\n");
//    return 0;
//}