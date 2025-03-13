#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h> 
#include <easyx.h>
#include <conio.h>  
#include <stdio.h>  
#include <math.h>
#pragma comment( lib, "MSIMG32.LIB")
#pragma comment(lib,"winmm.lib")

void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
IMAGE background;

const char* frames_run[] = {
    "./hk416_images_right/hk416mod_move_25_000.png",
    "./hk416_images_right/hk416mod_move_25_001.png",
    "./hk416_images_right/hk416mod_move_25_002.png",
    "./hk416_images_right/hk416mod_move_25_003.png",
    "./hk416_images_right/hk416mod_move_25_004.png",
    "./hk416_images_right/hk416mod_move_25_005.png",
    "./hk416_images_right/hk416mod_move_25_006.png",
    "./hk416_images_right/hk416mod_move_25_007.png",
    "./hk416_images_right/hk416mod_move_25_008.png",
    "./hk416_images_right/hk416mod_move_25_009.png",
    "./hk416_images_right/hk416mod_move_25_010.png",
    "./hk416_images_right/hk416mod_move_25_011.png",
    "./hk416_images_right/hk416mod_move_25_012.png",
    "./hk416_images_right/hk416mod_move_25_013.png",
    "./hk416_images_right/hk416mod_move_25_014.png",
    "./hk416_images_right/hk416mod_move_25_015.png",
    "./hk416_images_right/hk416mod_move_25_016.png",
    "./hk416_images_right/hk416mod_move_25_017.png",
    "./hk416_images_right/hk416mod_move_25_018.png",
    "./hk416_images_right/hk416mod_move_25_019.png",
    "./hk416_images_right/hk416mod_move_25_020.png",
    "./hk416_images_right/hk416mod_move_25_021.png",
    "./hk416_images_right/hk416mod_move_25_022.png",
    "./hk416_images_right/hk416mod_move_25_023.png"
};
const char* frames_wait[] = {
    "./hk416_images_right/hk416mod_wait_25_001.png",
    "./hk416_images_right/hk416mod_wait_25_002.png",
    "./hk416_images_right/hk416mod_wait_25_003.png",
    "./hk416_images_right/hk416mod_wait_25_004.png",
    "./hk416_images_right/hk416mod_wait_25_005.png",
    "./hk416_images_right/hk416mod_wait_25_006.png",
    "./hk416_images_right/hk416mod_wait_25_007.png",
    "./hk416_images_right/hk416mod_wait_25_008.png",
    "./hk416_images_right/hk416mod_wait_25_009.png",
    "./hk416_images_right/hk416mod_wait_25_010.png",
    "./hk416_images_right/hk416mod_wait_25_011.png",
    "./hk416_images_right/hk416mod_wait_25_012.png",
    "./hk416_images_right/hk416mod_wait_25_013.png",
    "./hk416_images_right/hk416mod_wait_25_014.png",
    "./hk416_images_right/hk416mod_wait_25_015.png",
    "./hk416_images_right/hk416mod_wait_25_016.png",
    "./hk416_images_right/hk416mod_wait_25_017.png",
    "./hk416_images_right/hk416mod_wait_25_018.png",
    "./hk416_images_right/hk416mod_wait_25_019.png",
    "./hk416_images_right/hk416mod_wait_25_020.png",
    "./hk416_images_right/hk416mod_wait_25_021.png",
    "./hk416_images_right/hk416mod_wait_25_022.png",
    "./hk416_images_right/hk416mod_wait_25_023.png",
    "./hk416_images_right/hk416mod_wait_25_024.png",
    "./hk416_images_right/hk416mod_wait_25_025.png",
    "./hk416_images_right/hk416mod_wait_25_026.png",
    "./hk416_images_right/hk416mod_wait_25_027.png",
    "./hk416_images_right/hk416mod_wait_25_028.png",
    "./hk416_images_right/hk416mod_wait_25_029.png",
    "./hk416_images_right/hk416mod_wait_25_030.png",
    "./hk416_images_right/hk416mod_wait_25_031.png",
    "./hk416_images_right/hk416mod_wait_25_032.png",
    "./hk416_images_right/hk416mod_wait_25_033.png",
    "./hk416_images_right/hk416mod_wait_25_034.png",
    "./hk416_images_right/hk416mod_wait_25_035.png",
    "./hk416_images_right/hk416mod_wait_25_036.png",
    "./hk416_images_right/hk416mod_wait_25_037.png",
    "./hk416_images_right/hk416mod_wait_25_038.png",
    "./hk416_images_right/hk416mod_wait_25_039.png",
    "./hk416_images_right/hk416mod_wait_25_040.png",
    "./hk416_images_right/hk416mod_wait_25_041.png",
    "./hk416_images_right/hk416mod_wait_25_042.png",
    "./hk416_images_right/hk416mod_wait_25_043.png",
    "./hk416_images_right/hk416mod_wait_25_044.png",
    "./hk416_images_right/hk416mod_wait_25_045.png",
    "./hk416_images_right/hk416mod_wait_25_046.png",
    "./hk416_images_right/hk416mod_wait_25_047.png",
    "./hk416_images_right/hk416mod_wait_25_048.png",
    "./hk416_images_right/hk416mod_wait_25_049.png",
    "./hk416_images_right/hk416mod_wait_25_050.png",
    "./hk416_images_right/hk416mod_wait_25_051.png",
    "./hk416_images_right/hk416mod_wait_25_052.png",
    "./hk416_images_right/hk416mod_wait_25_053.png"
};
const char* frames_run_left[] =
{
    "./hk416_images_left/hk416mod_move_25_000.png",
    "./hk416_images_left/hk416mod_move_25_001.png",
    "./hk416_images_left/hk416mod_move_25_002.png",
    "./hk416_images_left/hk416mod_move_25_003.png",
    "./hk416_images_left/hk416mod_move_25_004.png",
    "./hk416_images_left/hk416mod_move_25_005.png",
    "./hk416_images_left/hk416mod_move_25_006.png",
    "./hk416_images_left/hk416mod_move_25_007.png",
    "./hk416_images_left/hk416mod_move_25_008.png",
    "./hk416_images_left/hk416mod_move_25_009.png",
    "./hk416_images_left/hk416mod_move_25_010.png",
    "./hk416_images_left/hk416mod_move_25_011.png",
    "./hk416_images_left/hk416mod_move_25_012.png",
    "./hk416_images_left/hk416mod_move_25_013.png",
    "./hk416_images_left/hk416mod_move_25_014.png",
    "./hk416_images_left/hk416mod_move_25_015.png",
    "./hk416_images_left/hk416mod_move_25_016.png",
    "./hk416_images_left/hk416mod_move_25_017.png",
    "./hk416_images_left/hk416mod_move_25_018.png",
    "./hk416_images_left/hk416mod_move_25_019.png",
    "./hk416_images_left/hk416mod_move_25_020.png",
    "./hk416_images_left/hk416mod_move_25_021.png",
    "./hk416_images_left/hk416mod_move_25_022.png",
    "./hk416_images_left/hk416mod_move_25_023.png"
};
const char* frames_wait_left[] =
{
    "./hk416_images_left/hk416mod_wait_25_001.png",
    "./hk416_images_left/hk416mod_wait_25_002.png",
    "./hk416_images_left/hk416mod_wait_25_003.png",
    "./hk416_images_left/hk416mod_wait_25_004.png",
    "./hk416_images_left/hk416mod_wait_25_005.png",
    "./hk416_images_left/hk416mod_wait_25_006.png",
    "./hk416_images_left/hk416mod_wait_25_007.png",
    "./hk416_images_left/hk416mod_wait_25_008.png",
    "./hk416_images_left/hk416mod_wait_25_009.png",
    "./hk416_images_left/hk416mod_wait_25_010.png",
    "./hk416_images_left/hk416mod_wait_25_011.png",
    "./hk416_images_left/hk416mod_wait_25_012.png",
    "./hk416_images_left/hk416mod_wait_25_013.png",
    "./hk416_images_left/hk416mod_wait_25_014.png",
    "./hk416_images_left/hk416mod_wait_25_015.png",
    "./hk416_images_left/hk416mod_wait_25_016.png",
    "./hk416_images_left/hk416mod_wait_25_017.png",
    "./hk416_images_left/hk416mod_wait_25_018.png",
    "./hk416_images_left/hk416mod_wait_25_019.png",
    "./hk416_images_left/hk416mod_wait_25_020.png",
    "./hk416_images_left/hk416mod_wait_25_021.png",
    "./hk416_images_left/hk416mod_wait_25_022.png",
    "./hk416_images_left/hk416mod_wait_25_023.png",
    "./hk416_images_left/hk416mod_wait_25_024.png",
    "./hk416_images_left/hk416mod_wait_25_025.png",
    "./hk416_images_left/hk416mod_wait_25_026.png",
    "./hk416_images_left/hk416mod_wait_25_027.png",
    "./hk416_images_left/hk416mod_wait_25_028.png",
    "./hk416_images_left/hk416mod_wait_25_029.png",
    "./hk416_images_left/hk416mod_wait_25_030.png",
    "./hk416_images_left/hk416mod_wait_25_031.png",
    "./hk416_images_left/hk416mod_wait_25_032.png",
    "./hk416_images_left/hk416mod_wait_25_033.png",
    "./hk416_images_left/hk416mod_wait_25_034.png",
    "./hk416_images_left/hk416mod_wait_25_035.png",
    "./hk416_images_left/hk416mod_wait_25_036.png",
    "./hk416_images_left/hk416mod_wait_25_037.png",
    "./hk416_images_left/hk416mod_wait_25_038.png",
    "./hk416_images_left/hk416mod_wait_25_039.png",
    "./hk416_images_left/hk416mod_wait_25_040.png",
    "./hk416_images_left/hk416mod_wait_25_041.png",
    "./hk416_images_left/hk416mod_wait_25_042.png",
    "./hk416_images_left/hk416mod_wait_25_043.png",
    "./hk416_images_left/hk416mod_wait_25_044.png",
    "./hk416_images_left/hk416mod_wait_25_045.png",
    "./hk416_images_left/hk416mod_wait_25_046.png",
    "./hk416_images_left/hk416mod_wait_25_047.png",
    "./hk416_images_left/hk416mod_wait_25_048.png",
    "./hk416_images_left/hk416mod_wait_25_049.png",
    "./hk416_images_left/hk416mod_wait_25_050.png",
    "./hk416_images_left/hk416mod_wait_25_051.png",
    "./hk416_images_left/hk416mod_wait_25_052.png",
    "./hk416_images_left/hk416mod_wait_25_053.png"
};
const char* frames_fire[] =
{
    "./hk416_fire/hk416mod_attack_25_000.png",
    "./hk416_fire/hk416mod_attack_25_001.png",
    "./hk416_fire/hk416mod_attack_25_002.png",
    "./hk416_fire/hk416mod_attack_25_003.png",
    "./hk416_fire/hk416mod_attack_25_004.png",
    "./hk416_fire/hk416mod_attack_25_005.png",
    "./hk416_fire/hk416mod_attack_25_006.png",
    "./hk416_fire/hk416mod_attack_25_007.png",
    "./hk416_fire/hk416mod_attack_25_008.png",
    "./hk416_fire/hk416mod_attack_25_009.png",            
    "./hk416_fire/hk416mod_attack_25_010.png",
    "./hk416_fire/hk416mod_attack_25_011.png",
    "./hk416_fire/hk416mod_attack_25_012.png",
    "./hk416_fire/hk416mod_attack_25_013.png",
    "./hk416_fire/hk416mod_attack_25_014.png",
    "./hk416_fire/hk416mod_attack_25_015.png",
    "./hk416_fire/hk416mod_attack_25_016.png",
    "./hk416_fire/hk416mod_attack_25_017.png",
    "./hk416_fire/hk416mod_attack_25_018.png",
    "./hk416_fire/hk416mod_attack_25_019.png",
    "./hk416_fire/hk416mod_attack_25_020.png",
    "./hk416_fire/hk416mod_attack_25_021.png",
    "./hk416_fire/hk416mod_attack_25_022.png",
    "./hk416_fire/hk416mod_attack_25_023.png",
    "./hk416_fire/hk416mod_attack_25_024.png",
    "./hk416_fire/hk416mod_attack_25_025.png",
    "./hk416_fire/hk416mod_attack_25_026.png",
    "./hk416_fire/hk416mod_attack_25_027.png",
    "./hk416_fire/hk416mod_attack_25_028.png",
    "./hk416_fire/hk416mod_attack_25_029.png",
    "./hk416_fire/hk416mod_attack_25_030.png",
    "./hk416_fire/hk416mod_attack_25_031.png",
    "./hk416_fire/hk416mod_attack_25_032.png",
    "./hk416_fire/hk416mod_attack_25_033.png",
    
};
const char* frames_fire_left[] =
{
    "./hk416_fire_left/hk416mod_attack_25_000.png",
    "./hk416_fire_left/hk416mod_attack_25_001.png",
    "./hk416_fire_left/hk416mod_attack_25_002.png",
    "./hk416_fire_left/hk416mod_attack_25_003.png",
    "./hk416_fire_left/hk416mod_attack_25_004.png",
    "./hk416_fire_left/hk416mod_attack_25_005.png",
    "./hk416_fire_left/hk416mod_attack_25_006.png",
    "./hk416_fire_left/hk416mod_attack_25_007.png",
    "./hk416_fire_left/hk416mod_attack_25_008.png",
    "./hk416_fire_left/hk416mod_attack_25_009.png",
    "./hk416_fire_left/hk416mod_attack_25_010.png",
    "./hk416_fire_left/hk416mod_attack_25_011.png",
    "./hk416_fire_left/hk416mod_attack_25_012.png",
    "./hk416_fire_left/hk416mod_attack_25_013.png",
    "./hk416_fire_left/hk416mod_attack_25_014.png",
    "./hk416_fire_left/hk416mod_attack_25_015.png",
    "./hk416_fire_left/hk416mod_attack_25_016.png",
    "./hk416_fire_left/hk416mod_attack_25_017.png",
    "./hk416_fire_left/hk416mod_attack_25_018.png",
    "./hk416_fire_left/hk416mod_attack_25_019.png",
    "./hk416_fire_left/hk416mod_attack_25_020.png",
    "./hk416_fire_left/hk416mod_attack_25_021.png",
    "./hk416_fire_left/hk416mod_attack_25_022.png",
    "./hk416_fire_left/hk416mod_attack_25_023.png",
    "./hk416_fire_left/hk416mod_attack_25_024.png",
    "./hk416_fire_left/hk416mod_attack_25_025.png",
    "./hk416_fire_left/hk416mod_attack_25_026.png",
    "./hk416_fire_left/hk416mod_attack_25_027.png",
    "./hk416_fire_left/hk416mod_attack_25_028.png",
    "./hk416_fire_left/hk416mod_attack_25_029.png",
    "./hk416_fire_left/hk416mod_attack_25_030.png",
    "./hk416_fire_left/hk416mod_attack_25_031.png",
    "./hk416_fire_left/hk416mod_attack_25_032.png",
    "./hk416_fire_left/hk416mod_attack_25_033.png"
};
const char* golyat_move[] =
{
    "./golyat_move/golyat_move_25_000.png",
    "./golyat_move/golyat_move_25_001.png",
    "./golyat_move/golyat_move_25_002.png", 
    "./golyat_move/golyat_move_25_003.png",
    "./golyat_move/golyat_move_25_004.png",
    "./golyat_move/golyat_move_25_005.png",
    "./golyat_move/golyat_move_25_006.png",
    "./golyat_move/golyat_move_25_007.png",
    "./golyat_move/golyat_move_25_008.png",
    "./golyat_move/golyat_move_25_009.png",
    "./golyat_move/golyat_move_25_010.png",
    "./golyat_move/golyat_move_25_011.png",
    "./golyat_move/golyat_move_25_012.png",
    "./golyat_move/golyat_move_25_013.png",
    "./golyat_move/golyat_move_25_014.png",
    "./golyat_move/golyat_move_25_015.png",
    "./golyat_move/golyat_move_25_016.png",
    "./golyat_move/golyat_move_25_017.png",
    "./golyat_move/golyat_move_25_018.png",
    "./golyat_move/golyat_move_25_019.png",
    "./golyat_move/golyat_move_25_020.png",
    "./golyat_move/golyat_move_25_021.png",
    "./golyat_move/golyat_move_25_022.png",
    "./golyat_move/golyat_move_25_023.png"
};
const char* golyat_die[] =
{
    "./golyat_die/golyat_die_25_000.png",
    "./golyat_die/golyat_die_25_001.png",
    "./golyat_die/golyat_die_25_002.png",
    "./golyat_die/golyat_die_25_003.png",
    "./golyat_die/golyat_die_25_004.png",
    "./golyat_die/golyat_die_25_005.png",
    "./golyat_die/golyat_die_25_006.png",
    "./golyat_die/golyat_die_25_007.png",
    "./golyat_die/golyat_die_25_008.png",
    "./golyat_die/golyat_die_25_009.png",
    "./golyat_die/golyat_die_25_010.png",
    "./golyat_die/golyat_die_25_011.png",
    "./golyat_die/golyat_die_25_012.png",
    "./golyat_die/golyat_die_25_013.png",
    "./golyat_die/golyat_die_25_014.png",
    "./golyat_die/golyat_die_25_015.png",
    "./golyat_die/golyat_die_25_016.png",
    "./golyat_die/golyat_die_25_017.png",
    "./golyat_die/golyat_die_25_018.png",
    "./golyat_die/golyat_die_25_019.png",
    "./golyat_die/golyat_die_25_020.png",
    "./golyat_die/golyat_die_25_021.png",
    "./golyat_die/golyat_die_25_022.png",
    "./golyat_die/golyat_die_25_023.png"
};

int frameCount1 = sizeof(frames_run) / sizeof(frames_run[0]); // 计算帧数  
int frameCount2 = sizeof(frames_wait) / sizeof(frames_wait[0]); 
int frameCount1_left = sizeof(frames_run_left) / sizeof(frames_run_left[0]);
int frameCount2_left = sizeof(frames_wait_left) / sizeof(frames_wait_left[0]);
int frameCount_fire = sizeof(frames_fire) / sizeof(frames_fire[0]);
int frameCount_fire_left = sizeof(frames_fire_left) / sizeof(frames_fire_left[0]);
int frameCount_golyat_move = sizeof(golyat_move) / sizeof(golyat_move[0]);
int frameCount_golyat_die = sizeof(golyat_die) / sizeof(golyat_die[0]);

int x = 100;
int y = 100;
int Dx = rand() % (1180 - 100 + 1) + 100;
int Dy = rand() % (621) + 100;
int*px = &x;
int*py = &y;
int sign = 0;
int* psign= &sign;
int mx;
int my;
int* pmx=&mx;
int* pmy=&my;
int* dpx=&Dx;//敌人的实时位置x
int* dpy=&Dy;//敌人的实时位置y
int* bpy=&x;//子弹的实时位置y
int* bpx=&y;//子弹的实时位置x
int killed_number = 0;
char killed_number_display[20];
int lv = 0;
char lv_display[20];

void drawProgressBar(int x, int y, int progress, int total) 
{
    // 计算进度条的宽度  
    int barWidth = 800; // 进度条的总宽度  
    int barHeight = 30; // 进度条的高度  
    int filledWidth = (progress * barWidth) / total; // 已填充的宽度  

    // 设置进度条的背景颜色  
    setfillcolor(WHITE);
    setlinecolor(WHITE);
    setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
    bar(x, y, x + barWidth, y + barHeight); // 绘制背景框  

    // 绘制已填充的进度部分  
    setfillcolor(GREEN);
    setlinecolor(GREEN);
    setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
    bar(x, y, x + filledWidth, y + barHeight); // 绘制进度条  

    // 显示进度百分比  
    //char buffer[20];
    //sprintf(buffer, "进度：%d%%", (progress * 100) / total);
    //settextcolor(BLACK);
    //outtextxy(200, 110, buffer); // 在进度条上方显示进度  
}

void draw_ui(IMAGE* buffer)
{
    settextstyle(35, 0, "黑体");
    while (1)
    {
        if (killed_number * 100 - lv * 1000 == 1000)
        {
            lv++;
        }
        drawProgressBar(240, 10, killed_number * 100 - lv * 1000, 1000);
        sprintf(killed_number_display, "%d", killed_number * 100);
        sprintf(lv_display, "%d", lv);
        setbkmode(TRANSPARENT);
        setcolor(WHITE);
        outtextxy(640, 50, killed_number_display);
        outtextxy(240, 50, lv_display);
        Sleep(20);
    }
}

void draw_background(IMAGE* buffer)
{
        BeginBatchDraw();
        //cleardevice();
        loadimage(&background, "树林.png", 1280, 720);
        putimage(0, 0, &background);
        Sleep(1000/60);
        EndBatchDraw();
}

void playAnimation(const char* frames[], int frameCount, int a, int s, IMAGE* buffer)
{
    IMAGE img;
    for (int i = 0; i < frameCount; i++)
    {
        if (*psign != a)
        {
            //printf("break\n");
            break;
        }
        //BeginBatchDraw();
        loadimage(&img, frames[i]); // 加载当前帧图像  
        transparentimage3(NULL, *px, *py, &img);
        
        if (i != frameCount - 1)
        {
            Sleep(20); // 控制播放速度，可以根据需要调整
        }
        //EndBatchDraw();
        //Sleep(20);
    }
}

void playAnimation_enemy(const char* frames[], int frameCount)
{
    for (int i = 0; i < frameCount; i++)
    {
        IMAGE img;
        loadimage(&img, frames[i]); // 加载当前帧图像  
        transparentimage3(NULL, *dpx, *dpy, &img);
        if (i != frameCount - 1)
        {
            Sleep(20); // 控制播放速度，可以根据需要调整
        }
        //Sleep(20); // 控制播放速度，可以根据需要调整  
    }
}

void keymove()
{
    *psign = 0;
    if ( *pmx < *px) // 检查是否鼠标在小人左侧
    {
        *psign = 10;
    }
    if ( *pmx > *px) // 检查是否鼠标在小人右侧
    {
        *psign = 11;
    }
    // 检测键盘状态  
    if (GetAsyncKeyState('W') < 0) // 使用字符常量代替VK_W 
    {
        *py -= 10;
        //printf("W\n");
        *psign = 1;
    }
            
    if (GetAsyncKeyState('S') < 0) // 使用字符常量代替VK_S  
    {
        *py += 10;
        //printf("S\n");
        *psign = 1;
    }
  
    if (GetAsyncKeyState('A') < 0) // 使用字符常量代替VK_A  
    {
        *px -= 10;
        //printf("A\n");
        *psign = 2;
    }
  
    if (GetAsyncKeyState('D') < 0) // 使用字符常量代替VK_D  
    {
        *px += 10;
        //printf("D\n");
        *psign = 1;
    }
        
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && *pmx > *px) // 检查是否为鼠标左键按下且鼠标在小人右侧
    {
        *psign = 3;
    }
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && *pmx < *px) // 检查是否为鼠标左键按下且鼠标在小人左侧
    {
        *psign = 4;
    }

    // 边界检查
    if (*px < -100)
    {
        *px = -100;
    }

    if (*px > 1280-260)
    {
        *px = 1280-260;
    }

    if (*py < -100)
    {
        *py = -100;
    }

    if (*py > 720-270 )
    {
        *py = 720-270 ; // 假设帧高度为100
    }
        
    Sleep(50); // 控制刷新频率，可以根据需要调整
}

void HK416run(IMAGE* buffer)
{
    //cleardevice(); // 清除屏幕 
    if (*psign == 1)
    {
        playAnimation(frames_run, frameCount1, *psign, 1, buffer);
    }
    else if (*psign == 2)
    {
        playAnimation(frames_run_left, frameCount1_left, *psign, 1, buffer);
    }
    else if (*psign == 11)
    {
        playAnimation(frames_wait, frameCount2, *psign, 1, buffer);
    }
    else if (*psign == 10)
    {
        playAnimation(frames_wait_left, frameCount2, *psign, 1, buffer);
    }
    else if (*psign == 3)
    {
        playAnimation(frames_fire, frameCount_fire, *psign, 1, buffer);
    }
    else if (*psign == 4)
    {
        playAnimation(frames_fire_left, frameCount_fire_left, *psign, 1, buffer);
    }
    
    Sleep(1);

}

void mouse_track(IMAGE* buffer)
{
    while (1)
    {
        //BeginBatchDraw();
        POINT mousePos;
        GetCursorPos(&mousePos);
        ScreenToClient(GetHWnd(), &mousePos);
        //cleardevice();
        // 清除之前的内容  
        //loadimage(&background, "树林.png",1280,720);
        //putimage(0, 0, &background);
        // 绘制鼠标位置  
        setcolor(RED);
        setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
        circle(mousePos.x, mousePos.y, 20);
        setlinecolor(RED);
        setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
        line(mousePos.x, mousePos.y, *px + 170, *py + 170);
        *pmx = mousePos.x;
        *pmy = mousePos.y;
        // 将缓冲区内容显示到屏幕  
        //putimage(0, 0, buffer);
        Sleep(20);
        //EndBatchDraw();
    }
    

}

void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
    HDC dstDC = GetImageHDC(dstimg);
    HDC srcDC = GetImageHDC(srcimg);
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}


#define BULLET_SPEED 60 // 子弹速度  

// 开火部分  
typedef struct {
    int x, y; // 子弹位置  
    int targetX, targetY; // 目标位置  
    int active; // 子弹是否活跃  
} Bullet;

void fire_move(Bullet* bullet, int heroX, int heroY, int targetX, int targetY) {
    bullet->x = heroX;
    bullet->y = heroY;
    bullet->targetX = targetX;
    bullet->targetY = targetY;
    bullet->active = 1; // 激活子弹  
}

void updateBullet(Bullet* bullet) {
    if (bullet->active) {
        // 计算子弹的方向  
        int dx = bullet->targetX - bullet->x;
        int dy = bullet->targetY - bullet->y;
        double distance = sqrt(dx * dx + dy * dy);

        // 如果子弹到达目标位置，停用子弹  
        if (distance < BULLET_SPEED) {
            bullet->active = 0;
            return;
        }
        // 更新子弹位置  
        bullet->x += (int)(BULLET_SPEED * (dx / distance));
        bullet->y += (int)(BULLET_SPEED * (dy / distance));
        bpx = &bullet->x;
        bpy = &bullet->y;
    }
}

void fire() { 
    IMAGE bullet;
    loadimage(&bullet, "./bullet.png", 21, 21); // 加载子弹图片    
    Bullet bulletInstance = { 0 }; // 初始化子弹  
    
    while (1) {
        
        // 清屏  
        //cleardevice();
        // 获取鼠标位置  
        POINT mousePos;
        GetCursorPos(&mousePos);
        ScreenToClient(GetHWnd(), &mousePos); // 转换为窗口坐标  
        // 检测鼠标左键发射子弹  
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) 
        {
            if (!bulletInstance.active) // 只有在子弹未激活时才能发射
            {   
                fire_move(&bulletInstance, *px+170, *py+170, mousePos.x, mousePos.y);
            }
        }
        // 更新子弹位置  
        updateBullet(&bulletInstance);
        // 绘制子弹  
        if (bulletInstance.active) 
        {
            transparentimage3(NULL, bulletInstance.x, bulletInstance.y, &bullet);
        }
        else
        {
            break;
        }
          
        Sleep(20); // 控制帧率  
        
    }
}

//敌方单位
#define ENEMY_SPEED 30 // 速度
typedef struct {
    int x, y; // 子弹位置  
    int targetX, targetY; // 目标位置  
    int active; // 子弹是否活跃  
} enemy;

void enemy_move(enemy* enemy, int heroX, int heroY, int targetX, int targetY) {
    enemy->x = heroX;
    enemy->y = heroY;
    enemy->targetX = targetX;
    enemy->targetY = targetY;
    enemy->active = 1; // 敌人是否存活  
}

void updateEnemy(enemy* enemy) {
    if (enemy->active) {
        // 计算子弹的方向  
        int dx = enemy->targetX - enemy->x;
        int dy = enemy->targetY - enemy->y;
        double distance = sqrt(dx * dx + dy * dy);

        // 如果敌人接触到人物  
        if (distance < ENEMY_SPEED) {
            enemy->active = 0;
            printf("Killed\n");
            return;
        }

        //子弹打中敌人后
        if (*bpx>=*dpx && *bpx <= *dpx+340 && *bpy>=*dpy && *bpy <= *dpy+340)
        {
            //printf("hit\n");
            enemy->active = 0;
            //outtextxy(*dpx, *bpy, "Killed");
            //playAnimation_enemy(golyat_die, frameCount_golyat_die);
            //*dpx = 500;
            //*dpy = 500;
            //*bpx = 0;
            //*bpy = 0;
        }
        
        // 更新敌人位置  
        enemy->x += (int)(ENEMY_SPEED * (dx / distance));
        enemy->y += (int)(ENEMY_SPEED * (dy / distance));
        dpx = &enemy->x;
        dpy = &enemy->y;
        //printf("%d %d\n", *dpx, *dpy);
    }
}


void play(IMAGE* buffer)
{
    enemy enemyInstance = { 0 };
    *dpx = rand() % (1180 - 100 + 1) + 100;
    *dpy = rand() % (621) + 100;
    while (1)
    {
        enemy_move(&enemyInstance, *dpx, *dpy, *px, *py);
        updateEnemy(&enemyInstance); 
        if (enemyInstance.active) 
        {
            playAnimation_enemy(golyat_move, frameCount_golyat_move);
        }
        else
        {
            playAnimation_enemy(golyat_die, frameCount_golyat_die);
           /* *dpx = 500;
            *dpy = 500;*/
            //enemy enemyInstance = { 0 };
            killed_number++;
            break;
        }
        Sleep(2);
    }
    
}