#include <stdio.h>  
#include <Windows.h>  
#include <process.h>  
#include <graphics.h>  
#include <conio.h>  

extern void keymove();
extern void HK416run(IMAGE* buffer);
extern void mouse_track(IMAGE* buffer);
extern void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
extern void fire();
extern void play(IMAGE* buffer);
extern void draw_background(IMAGE* buffer);
extern void draw_ui(IMAGE* buffer);

CRITICAL_SECTION cs;

/* 线程函数声明 */
void Thread1(void*);
void Thread2(void*);
void Thread3(void*);
void Thread4(void*);
void Thread5(void*);
void Thread6(void*);
void Thread7(void*);

/* 线程句柄 */
HANDLE h1, h2, h3, h4, h5, h6, h7;

/* 线程共享内存 */
volatile int i = 0;
IMAGE buffer;

/* 事件句柄 */
HANDLE events[7]; // 用于线程之间的同步  

/* 主线程 */
int main() {
    initgraph(1280, 720);
    getimage(&buffer, 0, 0, 1280, 720); // 创建与窗口大小相同的图像  

    // 创建事件对象，用于控制线程执行顺序  
    for (int j = 0; j < 7; j++) {
        events[j] = CreateEvent(NULL, FALSE, FALSE, NULL); // 自动复位事件  
        if (events[j] == NULL) {
            printf("CreateEvent failed (%d)\n", GetLastError());
            return 1;
        }
    }

    /* 创建线程 */
    h1 = (HANDLE)_beginthread(Thread1, 0, NULL); // 线程1  
    h2 = (HANDLE)_beginthread(Thread2, 0, NULL); // 线程2  
    h3 = (HANDLE)_beginthread(Thread3, 0, NULL); // 线程3  
    h4 = (HANDLE)_beginthread(Thread4, 0, NULL); // 线程4  
    h5 = (HANDLE)_beginthread(Thread5, 0, NULL); // 线程5  
    h6 = (HANDLE)_beginthread(Thread6, 0, NULL); // 线程6  
    h7 = (HANDLE)_beginthread(Thread7, 0, NULL); // 线程7  

    // 首先设置第一个事件，启动线程1  
    SetEvent(events[0]);

    // 等待所有线程结束  
    WaitForSingleObject(h1, INFINITE); // 等待线程1结束  
    WaitForSingleObject(h2, INFINITE); // 等待线程2结束  
    WaitForSingleObject(h3, INFINITE); // 等待线程3结束  
    WaitForSingleObject(h4, INFINITE); // 等待线程4结束  
    WaitForSingleObject(h5, INFINITE); // 等待线程5结束  
    WaitForSingleObject(h6, INFINITE); // 等待线程6结束  
    WaitForSingleObject(h7, INFINITE); // 等待线程7结束  

    closegraph();

    // 关闭事件句柄  
    //for (int j = 0; j < 7; j++) {
    //    CloseHandle(events[j]); // 关闭事件  
    //}

    printf("主线程结束\n");
    return 0;
}

void Thread1(void* arg)  // 线程1：检测键盘输入  
{
    keymove();
    SetEvent(events[1]); // 完成后触发线程2  
}

void Thread2(void* arg)  // 线程2：小人动画  
{
    while (1)
    {
        WaitForSingleObject(events[1], INFINITE); // 等待线程1完成  
        HK416run(&buffer); // 在缓冲区上绘制小人动画  
        SetEvent(events[2]); // 完成后触发线程3  
        Sleep(1);
    }
}

void Thread3(void* arg)  // 线程3：鼠标追踪及准心显示  
{
    WaitForSingleObject(events[2], INFINITE); // 等待线程2完成  
    mouse_track(&buffer);
    SetEvent(events[3]); // 完成后触发线程4  
}

void Thread4(void* arg)  // 线程4：开火动画  
{
    while (1)
    {
        WaitForSingleObject(events[3], INFINITE); // 等待线程3完成  
        fire();
        SetEvent(events[4]); // 完成后触发线程5  
        Sleep(100); // 控制开火速度  
    }
}

void Thread5(void* arg)  // 线程5：敌方移动  
{
    while (1)
    {
        WaitForSingleObject(events[4], INFINITE); // 等待线程4完成  
        play(&buffer);
        SetEvent(events[5]); // 完成后触发线程6  
    }
}

void Thread6(void* arg)  // 线程6：背景显示  
{
    WaitForSingleObject(events[5], INFINITE); // 等待线程5完成  
    draw_background(&buffer);
    SetEvent(events[6]); // 完成后触发线程7  
}

void Thread7(void* arg)  // 线程7：UI显示  
{
    WaitForSingleObject(events[6], INFINITE); // 等待线程6完成  
    draw_ui(&buffer);
}