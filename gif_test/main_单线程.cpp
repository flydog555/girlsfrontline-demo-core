//#include <stdio.h>
//#include <Windows.h>
//#include <process.h>
//#include <graphics.h>  
//#include <conio.h>  
//
//extern void keymove();
//extern void HK416run(IMAGE* buffer);
//extern void mouse_track(IMAGE* buffer);
//extern void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
//extern void fire();
//extern void play(IMAGE* buffer);
//extern void draw_background(IMAGE* buffer);
//extern void draw_ui(IMAGE* buffer);
//
//
//IMAGE buffer;
//
//
//
///* ���߳� */
//int main()
//{
//	initgraph(1280, 720);
//	getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��
//	while (1)
//	{
//		keymove();
//		draw_background(&buffer);
//		mouse_track(&buffer);
//		HK416run(&buffer);
//		fire();
//		play(&buffer);
//	}
//	
//
//
//	
//	closegraph();
//	printf("���߳̽���\n");
//	return 0;
//}


//void Thread1(void* arg)  //�߳�1������������
//{
//	while (1)
//	{
//		EnterCriticalSection(&cs);
//		keymove();
//		LeaveCriticalSection(&cs);
//	}
//
//
//}
//
//void Thread2(void* arg)  //�߳�2��С�˶���
//{
//	//IMAGE buffer;
//	//getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��  
//	while (1)
//	{
//		EnterCriticalSection(&cs); // ����  
//		HK416run(&buffer); // �ڻ������ϻ���С�˶���  
//
//		//Sleep(1);
//		LeaveCriticalSection(&cs); // ���� 
//	}
//
//}
//
//void Thread3(void* arg)  //�߳�3�����׷�ټ�׼����ʾ
//{
//	//IMAGE buffer;
//	//getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��
//	//EnterCriticalSection(&cs);
//	while (1)
//	{
//		EnterCriticalSection(&cs);
//		mouse_track(&buffer);
//		LeaveCriticalSection(&cs);
//	}
//
//	//LeaveCriticalSection(&cs);
//}
//
//void Thread4(void* arg)  //�߳�4�����𶯻�
//{
//	//EnterCriticalSection(&cs);
//	while (1)
//	{
//		EnterCriticalSection(&cs);
//		fire();
//		LeaveCriticalSection(&cs);
//	}
//	//LeaveCriticalSection(&cs);
//	//Sleep(100);
//
//}
//void Thread5(void* arg)  //�߳�5���з��ƶ�
//{
//	while (1)
//	{
//		EnterCriticalSection(&cs);
//		play(&buffer);
//		LeaveCriticalSection(&cs);
//	}
//
//}
//
//void Thread6(void* arg)  //�߳�6��������ʾ
//{
//	while (1)
//	{
//		EnterCriticalSection(&cs);
//		draw_background(&buffer);
//		LeaveCriticalSection(&cs);
//	}
//
//}
//
//void Thread7(void* arg)  //�߳�7��ui��ʾ
//{
//	//draw_ui(&buffer);
//}


