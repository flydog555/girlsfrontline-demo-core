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



/* 主线程 */
int main()
{
	initgraph(1280, 720);
	getimage(&buffer, 0, 0, 1280, 720); // 创建与窗口大小相同的图像
	//setwritemode(R2_XORPEN); // 设置画笔模式为异或模式
	

	/* 创建线程 */
	h1 = (HANDLE)_beginthread(Thread1, 0, NULL);//线程1
	h2 = (HANDLE)_beginthread(Thread2, 0, NULL);//线程2
	h3 = (HANDLE)_beginthread(Thread3, 0, NULL);//线程3
	h4 = (HANDLE)_beginthread(Thread4, 0, NULL);//线程4
	h5 = (HANDLE)_beginthread(Thread5, 0, NULL);//线程5
	h6 = (HANDLE)_beginthread(Thread6, 0, NULL);//线程6
	h7 = (HANDLE)_beginthread(Thread7, 0, NULL);//线程7

	WaitForSingleObject(h1, INFINITE);//等待线程1结束
	WaitForSingleObject(h2, INFINITE);//等待线程2结束
	WaitForSingleObject(h3, INFINITE);//等待线程3结束
	WaitForSingleObject(h4, INFINITE);//等待线程4结束
	WaitForSingleObject(h5, INFINITE);
	WaitForSingleObject(h6, INFINITE);
	WaitForSingleObject(h7, INFINITE);

	DeleteCriticalSection(&cs);
	closegraph();
	printf("主线程结束\n");
	return 0;
}


void Thread1(void* arg)  //线程1：检测键盘输入
{
	while (1)
	{
		//EnterCriticalSection(&cs);
		keymove();
		//LeaveCriticalSection(&cs);
	}
	
	 
}

void Thread2(void* arg)  //线程2：小人动画
{
	//IMAGE buffer;
	//getimage(&buffer, 0, 0, 1280, 720); // 创建与窗口大小相同的图像  
	while (1)
	{
		//EnterCriticalSection(&cs); // 加锁  
		HK416run(&buffer); // 在缓冲区上绘制小人动画  
		  
		//Sleep(1);
		//LeaveCriticalSection(&cs); // 解锁 
	}

}

void Thread3(void* arg)  //线程3：鼠标追踪及准心显示
{
	//IMAGE buffer;
	//getimage(&buffer, 0, 0, 1280, 720); // 创建与窗口大小相同的图像
	//EnterCriticalSection(&cs);
	//while (1)
	//{
	//	//EnterCriticalSection(&cs);
	//	mouse_track(&buffer);
	//	//LeaveCriticalSection(&cs);
	//}
	mouse_track(&buffer);
	
	//LeaveCriticalSection(&cs);
}

void Thread4(void* arg)  //线程4：开火动画
{
	//EnterCriticalSection(&cs);
	while (1)
	{
		//EnterCriticalSection(&cs);
		fire();
		//LeaveCriticalSection(&cs);
	}
	//LeaveCriticalSection(&cs);
	//Sleep(100);
	
 }
void Thread5(void* arg)  //线程5：敌方移动
{	
	while (1)
	{
		//EnterCriticalSection(&cs);
		play(&buffer);
		//LeaveCriticalSection(&cs);
	}
	
}

void Thread6(void* arg)  //线程6：背景显示
{
	while (1)
	{
		//EnterCriticalSection(&cs);
		draw_background(&buffer);
		//LeaveCriticalSection(&cs);
	}
	
}

void Thread7(void* arg)  //线程7：ui显示
{
	while (1)
	{
		draw_ui(&buffer);
	}
	
}


