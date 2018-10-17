#include<stdio.h>//io输入输出头文件
#include<stdlib.h>//系统库头文件
#include<graphics.h>//绘制图形api
#include<conio.h>
#include<time.h>
#include<mmsystem.h>
#include<string>
using namespace std;
#pragma warning(disable:4996)
#pragma comment(lib,"winmm.lib")
/***********************************
函数名： welcome
函数功能：欢迎界面
函数返回值：空
函数参数：int*easyscore, int*generalscore, int*hardscore
***********************************/
void start(int*easyscore, int*generalscore, int*hardscore);//欢迎界面声明
/***********************************
函数名： game
函数功能：游戏界面
函数返回值：空
函数参数：int rank, int* easyscore, int*generalscore, int*hardscore
***********************************/
void game(int rank, int* easyscore, int*generalscore, int*hardscore);
/***********************************
函数名：bye
函数功能：结束界面
函数返回值：空
函数参数：int rank,int score int* easyscore, int*generalscore, int*hardscore
***********************************/
void bye(int rank, int score, int*easyscore, int*generalscore, int*hardscore);//结束界面
/***********************************
函数名： writefile
函数功能：分数写入函数
函数返回值：空
函数参数：char *fillname, char s[6]
***********************************/
void writefile(char *fillname, char s[6]);
/***********************************
函数名： writefile1
函数功能：分数读取并输出到画布指定位置
函数返回值：空
函数参数：char *filename, int x, int y
***********************************/
void writefile1(char *filename, int x, int y);
/***********************************
函数名： jiami
函数功能：将分数加密
函数返回值：char*
函数参数：char*s
***********************************/
char*jiami(char*s);
/***********************************
函数名： jiemi
函数功能：将分数解密
函数返回值：char*
函数参数：char*s
***********************************/
char*jiemi(char*cryptograph);
/***********************************
函数名： keybroad
函数功能：输出一个键盘
函数返回值：void
函数参数：无
***********************************/
void keybroad();
/***********************************
函数名： highlight
函数功能：用户点击相应的健，代码高亮
函数返回值：void
函数参数：char c
***********************************/
void highlight(char c);



