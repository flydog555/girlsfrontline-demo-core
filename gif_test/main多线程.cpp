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

/* �̺߳������� */
void Thread1(void*);
void Thread2(void*);
void Thread3(void*);
void Thread4(void*); 
void Thread5(void*);
void Thread6(void*);
void Thread7(void*);

/* �߳̾�� */
HANDLE h1, h2, h3, h4, h5, h6, h7;

/* �̹߳����ڴ� */
volatile int i = 0;
IMAGE buffer;



/* ���߳� */
int main()
{
	initgraph(1280, 720);
	getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��
	//setwritemode(R2_XORPEN); // ���û���ģʽΪ���ģʽ
	

	/* �����߳� */
	h1 = (HANDLE)_beginthread(Thread1, 0, NULL);//�߳�1
	h2 = (HANDLE)_beginthread(Thread2, 0, NULL);//�߳�2
	h3 = (HANDLE)_beginthread(Thread3, 0, NULL);//�߳�3
	h4 = (HANDLE)_beginthread(Thread4, 0, NULL);//�߳�4
	h5 = (HANDLE)_beginthread(Thread5, 0, NULL);//�߳�5
	h6 = (HANDLE)_beginthread(Thread6, 0, NULL);//�߳�6
	h7 = (HANDLE)_beginthread(Thread7, 0, NULL);//�߳�7

	WaitForSingleObject(h1, INFINITE);//�ȴ��߳�1����
	WaitForSingleObject(h2, INFINITE);//�ȴ��߳�2����
	WaitForSingleObject(h3, INFINITE);//�ȴ��߳�3����
	WaitForSingleObject(h4, INFINITE);//�ȴ��߳�4����
	WaitForSingleObject(h5, INFINITE);
	WaitForSingleObject(h6, INFINITE);
	WaitForSingleObject(h7, INFINITE);

	DeleteCriticalSection(&cs);
	closegraph();
	printf("���߳̽���\n");
	return 0;
}


void Thread1(void* arg)  //�߳�1������������
{
	while (1)
	{
		//EnterCriticalSection(&cs);
		keymove();
		//LeaveCriticalSection(&cs);
	}
	
	 
}

void Thread2(void* arg)  //�߳�2��С�˶���
{
	//IMAGE buffer;
	//getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��  
	while (1)
	{
		//EnterCriticalSection(&cs); // ����  
		HK416run(&buffer); // �ڻ������ϻ���С�˶���  
		  
		//Sleep(1);
		//LeaveCriticalSection(&cs); // ���� 
	}

}

void Thread3(void* arg)  //�߳�3�����׷�ټ�׼����ʾ
{
	//IMAGE buffer;
	//getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��
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

void Thread4(void* arg)  //�߳�4�����𶯻�
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
void Thread5(void* arg)  //�߳�5���з��ƶ�
{	
	while (1)
	{
		//EnterCriticalSection(&cs);
		play(&buffer);
		//LeaveCriticalSection(&cs);
	}
	
}

void Thread6(void* arg)  //�߳�6��������ʾ
{
	while (1)
	{
		//EnterCriticalSection(&cs);
		draw_background(&buffer);
		//LeaveCriticalSection(&cs);
	}
	
}

void Thread7(void* arg)  //�߳�7��ui��ʾ
{
	while (1)
	{
		draw_ui(&buffer);
	}
	
}


