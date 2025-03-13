//#include <graphics.h>  
//#include <conio.h>  
//#include <stdio.h>  
//
//int sss = 0;
//
//void playAnimation(const char* frames[], int frameCount,int x,int y,int s) {
//    int sign = 0;
//    while (1) { // 无限循环，直到手动退出  
//        for (int i = 0; i < frameCount; i++) {
//            IMAGE img;
//            loadimage(&img, frames[i]); // 加载当前帧图像  
//            putimage(x, y, &img); // 显示当前帧  
//            Sleep(20); // 控制播放速度，可以根据需要调整  
//            
//            ExMessage msg;
//            if (s == 1)
//            {
//                if (peekmessage(&msg, EM_MOUSE))
//                {
//                    switch (msg.message)
//                    {
//                    case WM_LBUTTONDOWN:
//                        if (msg.x >= 100 && msg.x <= 100 + 340 && msg.y >= 100 && msg.y <= 100 + 340)//1键区域
//                        {
//                            sign = 1;
//                            sss = 1;
//                        }
//                        break;
//                    default:
//                        break;
//                    }
//                }
//            }
//            else
//            {
//                if (peekmessage(&msg, EM_MOUSE))
//                {
//                    switch (msg.message)
//                    {
//                    case WM_LBUTTONDOWN:
//                        if (msg.x >= 100 && msg.x <= 100 + 340 && msg.y >= 100 && msg.y <= 100 + 340)//1键区域
//                        {
//                            sign = 2;
//                            sss = 2;
//                        }
//                        break;
//                    default:
//                        break;
//                    }
//                }
//            }
//            
//            if (sign != 0)
//            {
//                break;
//            }
//        }
//        if (sign !=0)
//        {
//            break;
//        }
//    }
//}
//
//int main() {
//    // 初始化图形窗口  
//    initgraph(1280, 720);
//
//    // 定义帧图像文件路径  
//    const char* frames1[] = {
//    "./hk416_images/hk416mod_move_25_000.png",
//    "./hk416_images/hk416mod_move_25_001.png",
//    "./hk416_images/hk416mod_move_25_002.png",
//    "./hk416_images/hk416mod_move_25_003.png",
//    "./hk416_images/hk416mod_move_25_004.png",
//    "./hk416_images/hk416mod_move_25_005.png",
//    "./hk416_images/hk416mod_move_25_006.png",
//    "./hk416_images/hk416mod_move_25_007.png",
//    "./hk416_images/hk416mod_move_25_008.png",
//    "./hk416_images/hk416mod_move_25_009.png",
//    "./hk416_images/hk416mod_move_25_010.png",
//    "./hk416_images/hk416mod_move_25_011.png",
//    "./hk416_images/hk416mod_move_25_012.png",
//    "./hk416_images/hk416mod_move_25_013.png",
//    "./hk416_images/hk416mod_move_25_014.png",
//    "./hk416_images/hk416mod_move_25_015.png",
//    "./hk416_images/hk416mod_move_25_016.png",
//    "./hk416_images/hk416mod_move_25_017.png",
//    "./hk416_images/hk416mod_move_25_018.png",
//    "./hk416_images/hk416mod_move_25_019.png",
//    "./hk416_images/hk416mod_move_25_020.png",
//    "./hk416_images/hk416mod_move_25_021.png",
//    "./hk416_images/hk416mod_move_25_022.png",
//    "./hk416_images/hk416mod_move_25_023.png",
//    };
//    const char* frames2[] = {
//    "./hk416_images/hk416mod_wait_25_001.png",
//    "./hk416_images/hk416mod_wait_25_002.png",
//    "./hk416_images/hk416mod_wait_25_003.png",
//    "./hk416_images/hk416mod_wait_25_004.png",
//    "./hk416_images/hk416mod_wait_25_005.png",
//    "./hk416_images/hk416mod_wait_25_006.png",
//    "./hk416_images/hk416mod_wait_25_007.png",
//    "./hk416_images/hk416mod_wait_25_008.png",
//    "./hk416_images/hk416mod_wait_25_009.png",
//    "./hk416_images/hk416mod_wait_25_010.png",
//    "./hk416_images/hk416mod_wait_25_011.png",
//    "./hk416_images/hk416mod_wait_25_012.png",
//    "./hk416_images/hk416mod_wait_25_013.png",
//    "./hk416_images/hk416mod_wait_25_014.png",
//    "./hk416_images/hk416mod_wait_25_015.png",
//    "./hk416_images/hk416mod_wait_25_016.png",
//    "./hk416_images/hk416mod_wait_25_017.png",
//    "./hk416_images/hk416mod_wait_25_018.png",
//    "./hk416_images/hk416mod_wait_25_019.png",
//    "./hk416_images/hk416mod_wait_25_020.png",
//    "./hk416_images/hk416mod_wait_25_021.png",
//    "./hk416_images/hk416mod_wait_25_022.png",
//    "./hk416_images/hk416mod_wait_25_023.png",
//    "./hk416_images/hk416mod_wait_25_024.png",
//    "./hk416_images/hk416mod_wait_25_025.png",
//    "./hk416_images/hk416mod_wait_25_026.png",
//    "./hk416_images/hk416mod_wait_25_027.png",
//    "./hk416_images/hk416mod_wait_25_028.png",
//    "./hk416_images/hk416mod_wait_25_029.png",
//    "./hk416_images/hk416mod_wait_25_030.png",
//    "./hk416_images/hk416mod_wait_25_031.png",
//    "./hk416_images/hk416mod_wait_25_032.png",
//    "./hk416_images/hk416mod_wait_25_033.png",
//    "./hk416_images/hk416mod_wait_25_034.png",
//    "./hk416_images/hk416mod_wait_25_035.png",
//    "./hk416_images/hk416mod_wait_25_036.png",
//    "./hk416_images/hk416mod_wait_25_037.png",
//    "./hk416_images/hk416mod_wait_25_038.png",
//    "./hk416_images/hk416mod_wait_25_039.png",
//    "./hk416_images/hk416mod_wait_25_040.png",
//    "./hk416_images/hk416mod_wait_25_041.png",
//    "./hk416_images/hk416mod_wait_25_042.png",
//    "./hk416_images/hk416mod_wait_25_043.png",
//    "./hk416_images/hk416mod_wait_25_044.png",
//    "./hk416_images/hk416mod_wait_25_045.png",
//    "./hk416_images/hk416mod_wait_25_046.png",
//    "./hk416_images/hk416mod_wait_25_047.png",
//    "./hk416_images/hk416mod_wait_25_048.png",
//    "./hk416_images/hk416mod_wait_25_049.png",
//    "./hk416_images/hk416mod_wait_25_050.png",
//    "./hk416_images/hk416mod_wait_25_051.png",
//    "./hk416_images/hk416mod_wait_25_052.png",
//    "./hk416_images/hk416mod_wait_25_053.png"
//    };
//
//    int frameCount1 = sizeof(frames1) / sizeof(frames1[0]); // 计算帧数  
//    int frameCount2 = sizeof(frames2) / sizeof(frames2[0]); // 计算帧数 
// 
//    playAnimation(frames1, frameCount1, 100, 100,1);
//
//    ExMessage msg;
//    while (1)
//    {
//        if (peekmessage(&msg, EM_MOUSE))
//        {
//            switch (msg.message)
//            {
//            case WM_LBUTTONDOWN:
//                if (msg.x >= 100 && msg.x <= 100 + 340 && msg.y >= 100 && msg.y <= 100+340)//1键区域
//                {
//                    if (sss == 1)
//                    {
//                        printf("1");
//                        cleardevice();
//                        playAnimation(frames2, frameCount2, 100, 100, 2);
//                    }
//                    else if(sss==2)
//                    {
//                        printf("2");
//                        cleardevice();
//                        playAnimation(frames1, frameCount1, 100, 100, 1);
//                    }
//                    
//                    
//                    
//                }
//                if (msg.x >= 0 && msg.x <= 100 && msg.y >= 600 && msg.y <= 700)//2键区域
//                {
//                    //playAnimation(frames2, frameCount2, 100, 100);
//                }
//                break;
//            default:
//                break;
//            }
//        }
//
//    }
//
//    // 关闭图形窗口  
//    closegraph();
//    return 0;
//}