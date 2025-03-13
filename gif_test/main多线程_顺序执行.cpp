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

/* �¼���� */
HANDLE events[7]; // �����߳�֮���ͬ��  

/* ���߳� */
int main() {
    initgraph(1280, 720);
    getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��  

    // �����¼��������ڿ����߳�ִ��˳��  
    for (int j = 0; j < 7; j++) {
        events[j] = CreateEvent(NULL, FALSE, FALSE, NULL); // �Զ���λ�¼�  
        if (events[j] == NULL) {
            printf("CreateEvent failed (%d)\n", GetLastError());
            return 1;
        }
    }

    /* �����߳� */
    h1 = (HANDLE)_beginthread(Thread1, 0, NULL); // �߳�1  
    h2 = (HANDLE)_beginthread(Thread2, 0, NULL); // �߳�2  
    h3 = (HANDLE)_beginthread(Thread3, 0, NULL); // �߳�3  
    h4 = (HANDLE)_beginthread(Thread4, 0, NULL); // �߳�4  
    h5 = (HANDLE)_beginthread(Thread5, 0, NULL); // �߳�5  
    h6 = (HANDLE)_beginthread(Thread6, 0, NULL); // �߳�6  
    h7 = (HANDLE)_beginthread(Thread7, 0, NULL); // �߳�7  

    // �������õ�һ���¼��������߳�1  
    SetEvent(events[0]);

    // �ȴ������߳̽���  
    WaitForSingleObject(h1, INFINITE); // �ȴ��߳�1����  
    WaitForSingleObject(h2, INFINITE); // �ȴ��߳�2����  
    WaitForSingleObject(h3, INFINITE); // �ȴ��߳�3����  
    WaitForSingleObject(h4, INFINITE); // �ȴ��߳�4����  
    WaitForSingleObject(h5, INFINITE); // �ȴ��߳�5����  
    WaitForSingleObject(h6, INFINITE); // �ȴ��߳�6����  
    WaitForSingleObject(h7, INFINITE); // �ȴ��߳�7����  

    closegraph();

    // �ر��¼����  
    //for (int j = 0; j < 7; j++) {
    //    CloseHandle(events[j]); // �ر��¼�  
    //}

    printf("���߳̽���\n");
    return 0;
}

void Thread1(void* arg)  // �߳�1������������  
{
    keymove();
    SetEvent(events[1]); // ��ɺ󴥷��߳�2  
}

void Thread2(void* arg)  // �߳�2��С�˶���  
{
    while (1)
    {
        WaitForSingleObject(events[1], INFINITE); // �ȴ��߳�1���  
        HK416run(&buffer); // �ڻ������ϻ���С�˶���  
        SetEvent(events[2]); // ��ɺ󴥷��߳�3  
        Sleep(1);
    }
}

void Thread3(void* arg)  // �߳�3�����׷�ټ�׼����ʾ  
{
    WaitForSingleObject(events[2], INFINITE); // �ȴ��߳�2���  
    mouse_track(&buffer);
    SetEvent(events[3]); // ��ɺ󴥷��߳�4  
}

void Thread4(void* arg)  // �߳�4�����𶯻�  
{
    while (1)
    {
        WaitForSingleObject(events[3], INFINITE); // �ȴ��߳�3���  
        fire();
        SetEvent(events[4]); // ��ɺ󴥷��߳�5  
        Sleep(100); // ���ƿ����ٶ�  
    }
}

void Thread5(void* arg)  // �߳�5���з��ƶ�  
{
    while (1)
    {
        WaitForSingleObject(events[4], INFINITE); // �ȴ��߳�4���  
        play(&buffer);
        SetEvent(events[5]); // ��ɺ󴥷��߳�6  
    }
}

void Thread6(void* arg)  // �߳�6��������ʾ  
{
    WaitForSingleObject(events[5], INFINITE); // �ȴ��߳�5���  
    draw_background(&buffer);
    SetEvent(events[6]); // ��ɺ󴥷��߳�7  
}

void Thread7(void* arg)  // �߳�7��UI��ʾ  
{
    WaitForSingleObject(events[6], INFINITE); // �ȴ��߳�6���  
    draw_ui(&buffer);
}