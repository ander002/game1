#include<stdio.h>//io�������ͷ�ļ�
#include<stdlib.h>//ϵͳ��ͷ�ļ�
#include<graphics.h>//����ͼ��api
#include<conio.h>
#include<time.h>
#include<mmsystem.h>
#include<string>
using namespace std;
#pragma warning(disable:4996)
#pragma comment(lib,"winmm.lib")
/***********************************
�������� welcome
�������ܣ���ӭ����
��������ֵ����
����������int*easyscore, int*generalscore, int*hardscore
***********************************/
void start(int*easyscore, int*generalscore, int*hardscore);//��ӭ��������
/***********************************
�������� game
�������ܣ���Ϸ����
��������ֵ����
����������int rank, int* easyscore, int*generalscore, int*hardscore
***********************************/
void game(int rank, int* easyscore, int*generalscore, int*hardscore);
/***********************************
��������bye
�������ܣ���������
��������ֵ����
����������int rank,int score int* easyscore, int*generalscore, int*hardscore
***********************************/
void bye(int rank, int score, int*easyscore, int*generalscore, int*hardscore);//��������
/***********************************
�������� writefile
�������ܣ�����д�뺯��
��������ֵ����
����������char *fillname, char s[6]
***********************************/
void writefile(char *fillname, char s[6]);
/***********************************
�������� writefile1
�������ܣ�������ȡ�����������ָ��λ��
��������ֵ����
����������char *filename, int x, int y
***********************************/
void writefile1(char *filename, int x, int y);
/***********************************
�������� jiami
�������ܣ�����������
��������ֵ��char*
����������char*s
***********************************/
char*jiami(char*s);
/***********************************
�������� jiemi
�������ܣ�����������
��������ֵ��char*
����������char*s
***********************************/
char*jiemi(char*cryptograph);
/***********************************
�������� keybroad
�������ܣ����һ������
��������ֵ��void
������������
***********************************/
void keybroad();
/***********************************
�������� highlight
�������ܣ��û������Ӧ�Ľ����������
��������ֵ��void
����������char c
***********************************/
void highlight(char c);



