//#include <graphics.h>  
//#include <windows.h>  
//#include <process.h>  
//#include <stdio.h>  
//
//// ȫ�ֱ���  
//
//IMAGE buffer; // ȫ�ֻ�����  
//CRITICAL_SECTION cs; // ������  
//int sign; // ��ɫ״̬��־  
//int x;    // ��ɫX����  
//int y;    // ��ɫY����  
//int* psign = &sign; // ָ���ɫ״̬��־��ָ��  
//int* px = &x;       // ָ���ɫX�����ָ��  
//int* py = &y;       // ָ���ɫY�����ָ��  
//
//
//extern void keymove();
//extern void HK416run();
//extern void mouse_track();
//extern void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
//extern void fire();
//
//// �̺߳�������  
//void Thread1(void* arg); // ��������  
//void Thread2(void* arg); // С�˶���  
//void Thread3(void* arg); // ���׷��  
//void Thread4(void* arg); // ���𶯻�  
//void Thread5(void* arg); // ͳһ��Ⱦ  
//
//// �߳̾��  
//HANDLE h1, h2, h3, h4, h5;
//
//// �߳�1����������  
//void Thread1(void* arg) {
//    keymove();
//}
//
//// �߳�2��С�˶���  
//void Thread2(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // ����  
//        HK416run(); // �ڻ������ϻ���С�˶���  
//        LeaveCriticalSection(&cs); // ����  
//        Sleep(10);
//    }
//}
//
//// �߳�3�����׷��  
//void Thread3(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // ����  
//        mouse_track(); // �ڻ������ϻ������׷��  
//        LeaveCriticalSection(&cs); // ����  
//        Sleep(10);
//    }
//}
//
//// �߳�4�����𶯻�  
//void Thread4(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // ����  
//        fire(); // �ڻ������ϻ��ƿ��𶯻�  
//        LeaveCriticalSection(&cs); // ����  
//        Sleep(10);
//    }
//}
//
//// �߳�5��ͳһ��Ⱦ  
//void Thread5(void* arg) {
//    while (1) {
//        EnterCriticalSection(&cs); // ����  
//        putimage(0, 0, &buffer); // ��������������ʾ����Ļ  
//        LeaveCriticalSection(&cs); // ����  
//        Sleep(10); // ����ˢ��Ƶ��  
//    }
//}
//
//int main() {
//    // ��ʼ��ͼ�δ���  
//    initgraph(1280, 720);
//    getimage(&buffer, 0, 0, 1280, 720); // �����봰�ڴ�С��ͬ��ͼ��  
//
//    // ��ʼ��������  
//    InitializeCriticalSection(&cs);
//
//    // �����߳�  
//    h1 = (HANDLE)_beginthread(Thread1, 0, NULL); // �߳�1����������  
//    h2 = (HANDLE)_beginthread(Thread2, 0, NULL); // �߳�2��С�˶���  
//    h3 = (HANDLE)_beginthread(Thread3, 0, NULL); // �߳�3�����׷��  
//    h4 = (HANDLE)_beginthread(Thread4, 0, NULL); // �߳�4�����𶯻�  
//    h5 = (HANDLE)_beginthread(Thread5, 0, NULL); // �߳�5��ͳһ��Ⱦ  
//
//    // �ȴ��߳̽���  
//    WaitForSingleObject(h1, INFINITE);
//    WaitForSingleObject(h2, INFINITE);
//    WaitForSingleObject(h3, INFINITE);
//    WaitForSingleObject(h4, INFINITE);
//    WaitForSingleObject(h5, INFINITE);
//
//    // ɾ��������  
//    DeleteCriticalSection(&cs);
//
//    // �ر�ͼ�δ���  
//    closegraph();
//    printf("���߳̽���\n");
//    return 0;
//}