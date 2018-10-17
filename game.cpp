#include"game.h"
int main()
{

	initgraph(1200, 800);//����
	int easy = 0, general = 0, hard = 0, *easyscore = &easy, *generalscore = &general, *hardscore = &hard;
	start(easyscore, generalscore, hardscore);
	system("pause");
	return 0;
}
long long col[] = { 0x55FFFF,0xAA0000,0x00FF00,0x0000FF,0xFF5555 ,0x55FF55,0xFFFF55 ,0x5555FF,0xAAAAAA ,0xFFFFFF };//���ɫ��

void start(int*easyscore, int*generalscore, int*hardscore)
{
	//char s[5];
	cleardevice();//����
	mciSendString("open welcome.mp3 alias music", 0, 0, 0);
	mciSendString("play music repeat", 0, 0, 0);
	IMAGE welimg;
	loadimage(&welimg, _T("bg.jpg"),1200,800);
	putimage(0, 0, &welimg);
	setcolor(0x7fecad);//����������ɫ
	setbkmode(TRANSPARENT);//�������ֱ���Ϊ͸��
		settextstyle(64, 0, _T("����"));//���������Լ���С
		outtextxy(480, 50, _T("����������"));//�����������
		settextstyle(32, 0, _T("����"));
		outtextxy(400, 200, _T("��Ӣ��״̬�°���Ӧ��ĸ������Ϸ"));
		settextstyle(27, 0, _T("����"));
		outtextxy(500, 350, _T("1����"));
		outtextxy(500, 450, _T("2��һ��"));
		outtextxy(500, 550, _T("3������"));
		settextstyle(20, 0, _T("����"));
		outtextxy(660, 350, _T("��߷֣�"));
		outtextxy(660, 450, _T("��߷֣�"));
		outtextxy(660, 550, _T("��߷֣�"));
		writefile1(("easyscore.txt"), 750, 350);
		writefile1(("generalscore.txt"), 750, 450);
		writefile1(("hardscore.txt"), 750, 550);
	goto again;
	char choose;
	
again:
	choose = _getch();

		switch (choose)
	{
	case 49: game(1, easyscore, generalscore, hardscore);
		break;
	case 50:game(2, easyscore, generalscore, hardscore);
		break;
	case 51:game(3, easyscore, generalscore, hardscore);
		break;
	case 27: exit(1);
	default:
		goto again;
	}


	return;
}
void bye(int rank, int score, int*easyscore, int*generalscore, int*hardscore)
{
	cleardevice();
	char s[5],key,s1[5],s2[5],s3[5];
	IMAGE welimg;
	loadimage(&welimg, _T("bg.jpg"), 1200, 800);
	putimage(0, 0, &welimg);
	setcolor(LIGHTGRAY);//����������ɫ
	setbkmode(TRANSPARENT);//�������ֱ���Ϊ͸��
	_itoa_s(score, s, 10);
	int c = 255;
	while (!_kbhit())
	{
		setcolor(RGB(c, c, c));
		settextstyle(64, 0, _T("����"));//���������Լ���С
		outtextxy(500, 100, _T("��Ϸ����"));
		settextstyle(40, 0, _T("����"));//���������Լ���С
		outtextxy(530, 250, _T("������"));
		_itoa_s(score, s, 10);
		outtextxy(700, 250, s);
		outtextxy(530, 350, _T("��߷֣�"));
		switch (rank)
		{
		case 1:
			*easyscore = score > *easyscore ? score : *easyscore;
			_itoa_s(*easyscore, s1, 10);
			writefile("easyscore.txt", jiami(s1));
			writefile1(("easyscore.txt"), 700, 350); break;
		case 2:
			*generalscore = score > *generalscore ? score : *generalscore;
			_itoa_s(*generalscore, s2, 10);
			writefile("generalscore.txt", jiami(s2));
			writefile1(("generalscore.txt"), 700, 350); break;
		case 3:
			*hardscore = score > *hardscore ? score : *hardscore;
			_itoa_s(*hardscore, s3, 10);
			writefile("hardscore.txt", jiami(s3));
			writefile1(("hardscore.txt"), 700, 350); break;
		}
		settextstyle(20, 0, _T("����"));
		outtextxy(500, 475, _T("�ʵ���Ϸ��ǿ���壡"));
		outtextxy(460, 600, _T("���س����¿�ʼ��Ϸ����esc�˳���Ϸ"));
		c -= 8;
		if (c<0)
		{
			c = 255;
		}
		Sleep(30);
		setfillstyle(BS_SOLID);//����ͼƬ
		setfillcolor(RGB(255, 215, 0));
		fillcircle(100, 100, 50);
		setcolor(WHITE);
		for (int y1 = 85; y1 < 95; y1++)
			for (int y2 = 95; y2 <105; y2++)
			{
				arc(60, y1, 95, y2, 0.623, 2.7175);
			}
		for (int y3 = 85; y3 < 95; y3++)
			for (int y4 = 95; y4 <105; y4++)
			{
				arc(105, y3, 140, y4, 0.623, 2.7175);
			}
		setfillcolor(BLACK);
		fillcircle(69, 92, 4);
		fillcircle(114, 92, 4);
		setcolor(RGB(176, 23, 31));
		arc(65, 65, 135, 135, 3.24, -0.1);
	}
	key=_getch();
	if (key == 13)
		start(easyscore, generalscore, hardscore);

}
void game(int rank, int*easyscore, int*generalscore, int*hardscore)
{
	
	char target, key, s[5];//Ŀ����ĸ����ֵ,����,�ȼ�
	int x, y, addspeed = 0, score = 0, speed = 2 * rank / 2;//����,
	
	string str = "��Ϸ�гɳ���";//��Ϸ��������
	LPCSTR str1 = str.c_str();//��strת��ΪLPCSTR����
	cleardevice();
	keybroad();
	srand(time(NULL));//����������
	settextstyle(16, 0, _T("Arial"));//�������
									 
	setfillstyle(BS_SOLID);
	setfillcolor(BLACK);//���������ĸ�����������ɫ
	while (true)
	{
		target = 65 + rand() % 26;//���������д��ĸ
		x = rand() % 870;//x����
		setcolor(BLACK);
		line(x, 475, x, 0);
		clearrectangle(1000, 0, 1200,475);//������������0
		clearrectangle(900, 475, 1200, 500);
		_itoa_s(score, s, 10);
		if (score < 0)
		{
			score = 0;//��ֹ���ָ�����
			bye(rank, score, easyscore, generalscore, hardscore);
			return;
		}
	again:
		for (y = 0; y <= 475; y += speed)
		{
			setcolor(BLACK);
			if ((y + speed) >= 475)
			{
				clearrectangle(x, y-speed, x + 16, y + 16);
				//outtextxy(x, y - speed, target);//ֱ��������Ӱ
				y = 475;
				score -= 10;

			}
			setcolor(BLACK);
			outtextxy(x, y - speed,target);
			setcolor(col[rand() % 10]);//���ûò�����
			line(0, 475, 1200, 475);
			outtextxy(x, y, target);
			setcolor(col[rand() % 9]);
			outtextxy(1000,100, s);
			outtextxy(1000, 250, str1);//�������
			outtextxy(900, 475, "<---ĸ�ֵ��д���û��");
			line(890, 0, 890, 475);
			outtextxy(1000, 70, _T("������"));
			outtextxy(1000, 20, _T("�ȼ���"));
			outtextxy(1000, 40, rank+48);
			if (_kbhit())
			{
				key = _getch();//��ȡ����ֵ
				highlight(key);
				keybroad();
				if (key == '\0')  //�û��������ȷ�룬��ֹy++��
				{
					goto again;
				}
				else if (key == 27)
				{
					bye(rank, score, easyscore, generalscore, hardscore);
					return;
				}
				else if ((key == target) || (key == target + 32))//������ȷ����ĸ����outtext����
				{
					setcolor(col[rand() % 9]);//����Ч��
					setfillcolor(col[rand() % 9]);
					clearrectangle(x, y, x + 16, y + 16);
					line(x+8, 450, x+8, y);
					fillrectangle(x, y, x + 16, y + 16);
					fillrectangle(x, 450, x + 16, 466);
					settextstyle(20, 0, _T("Arial"));
					outtextxy(x+3, 450, key);
					Sleep(500);
					setcolor(BLACK);
					setfillcolor(BLACK);
					line(x+8, 450, x+8, y);
					fillrectangle(x, y, x + 16, y + 16);
					fillrectangle(x, 450, x + 16, 467);
					//outtextxy(x, y, target);//������ĸ��
					addspeed++;   //ÿ����һ�μ��٣�
					switch (rank)//���ȼ��ӷ�
					{
					case 1:
						score += 10;
						if (addspeed % 10 == 0)
						{
							speed++;
							//addspeed = 0;
						}break;
					case 2:
						score += 20;
						if (addspeed % 5 == 0)
						{
							speed++;
							//addspeed = 0;
						}break;

					case 3:
						score += 30;
						if (addspeed % 3 == 0)
						{
							speed++;
							//addspeed = 0;
						}break;
					}
					break;
					
				}

				else
				{
					bye(rank, score, easyscore, generalscore, hardscore);
					return;

				}
				
			}
			
			Sleep(20);
		}
	}
}

void writefile(char *fillname, char s[6])//������д���ļ�
{

	//����һ��fp�ļ�ָ��
	FILE *fp=NULL;
	int i = 0;
	//�жϴ򿪲������ɹ�
	if ((fp = fopen(fillname, "w")) == NULL)
	{
		printf("The file can not be opened.\n");
		//���������ִ��
		exit(1);
	}
	while (s[i] == '\0')
	{
		fputc(s[i], fp);
		i++;
	}
	fputs(s, fp);
	fclose(fp);
}
void writefile1(char *filename, int x, int y)
{
	FILE *fp = NULL;
	char s[1024];
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("The file can not be opened.\n");
		//���������ִ��
		exit(1);
	}
	fgets(s, 1024, fp);
	outtextxy(x, y, jiemi(s));
}
void keybroad()
{

	int i, k, j, m;
	char one[] = { 'q','w','e','r','t','y','u','i','o','p' };
	char two[] = { 'a','s','d','f','g','h','j','k','l' };
	char three[] = { 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
	char four[] = { '~','!','@','#','$','%','^','&','*','(',')','_','+' };
	char five[] = { '`','1','2','3','4','5','6','7','8','9','0','-','=' };
	char oneend[] = { '{', '}', '|' };                             //800 start
	char oneend1[] = { '[', ']', '\\' };
	char three1[] = { ':','"' };
	char three2[] = { ';','\'' };
	char h1[] = { '<','>','?' };
	char h2[] = { ',','.','/' };
	setcolor(col[rand() % 6]);
	rectangle(220, 600, 290, 640);  //Tab   (220,600),(290,640)
	line(220, 600, 220 - 3, 603);
	line(220 - 3, 603, 220 - 3, 643);
	line(220, 640, 220 - 3, 643);
	line(290, 640, 293, 643);
	line(220 - 3, 643, 293, 643);
	line(290, 600, 293, 603);
	line(293, 603, 293, 643);
	TCHAR ch[] = _T("Arial");
	settextstyle(20, 0, ch);
	TCHAR tab[] = _T("Tab");
	outtextxy(230, 610, tab);


	rectangle(220, 650, 300, 690);  //CapsLock   (220,650),(300,690)
	line(220, 650, 220 - 3, 653);
	line(220 - 3, 653, 220 - 3, 693);
	line(220, 690, 220 - 3, 693);
	line(300, 690, 303, 693);
	line(220 - 3, 693, 303, 693);
	line(300, 650, 303, 653);
	line(303, 653, 303, 693);
	settextstyle(17, 0, ch);
	TCHAR CapsLock[] = _T("CapsLock");
	outtextxy(230, 660, CapsLock);

	rectangle(870, 550, 940, 590);  //Backspace   (870,550),(940,590)
	line(870, 550, 870 - 3, 553);
	line(870 - 3, 553, 870 - 3, 593);
	line(870, 590, 870 - 3, 593);
	line(940, 590, 943, 593);
	line(870 - 3, 593, 943, 593);
	line(940, 550, 943, 553);
	line(943, 553, 943, 593);
	settextstyle(16, 0, ch);
	TCHAR Backspace[] = _T("Backspace");
	outtextxy(875, 560, Backspace);






	rectangle(220, 700, 330, 740);  //Shift   (220,700),(330,740)
	line(220, 700, 220 - 3, 703);
	line(220 - 3, 703, 220 - 3, 743);
	line(220, 740, 220 - 3, 743);
	line(330, 740, 333, 743);
	line(220 - 3, 743, 333, 743);
	line(330, 700, 333, 703);
	line(333, 703, 333, 743);
	settextstyle(20, 0, ch);
	TCHAR Shift[] = _T("Shift");
	outtextxy(230, 710, Shift);


	for (i = 220; i < 860; i = i + 50)      //  ���̵�����13����
	{
		rectangle(i, 550, i + 40, 590);    //���̵�һ����ĸ���꣨220,550������260,590��
		line(i, 550, i - 3, 553);
		line(i - 3, 553, i - 3, 593);
		line(i, 590, i - 3, 593);
		line(i + 40, 590, i + 43, 593);
		line(i - 3, 593, i + 43, 593);
		line(i + 40, 550, i + 43, 553);
		line(i + 43, 553, i + 43, 593);
		settextstyle(10, 0, ch);
		k = (i - 220) / 50;
		outtextxy(i + 5, 555, four[k]);
		settextstyle(16, 0, ch);
		outtextxy(i + 20, 570, five[k]);
	}


	for (i = 300; i < 800; i = i + 50)      //  ���̵�һ��10����
	{
		rectangle(i, 600, i + 40, 640);    //���̵�һ����ĸ���꣨300,600������340,640��
		line(i, 600, i - 3, 603);
		line(i - 3, 603, i - 3, 643);
		line(i, 640, i - 3, 643);
		line(i + 40, 640, i + 43, 643);
		line(i - 3, 643, i + 43, 643);
		line(i + 40, 600, i + 43, 603);
		line(i + 43, 603, i + 43, 643);
		TCHAR ch[] = _T("Arial");
		settextstyle(20, 0, ch);
		k = (i - 300) / 50;
		outtextxy(i + 10, 610, one[k]);
	}


	for (i = 800; i < 940; i = i + 50)
	{
		rectangle(i, 600, i + 40, 640);    //���̵�һ����ĸ���꣨800,600������850,640��
		line(i, 600, i - 3, 603);
		line(i - 3, 603, i - 3, 643);
		line(i, 640, i - 3, 643);
		line(i + 40, 640, i + 43, 643);
		line(i - 3, 643, i + 43, 643);
		line(i + 40, 600, i + 43, 603);
		line(i + 43, 603, i + 43, 643);
		settextstyle(15, 0, ch);
		k = (i - 800) / 50;
		outtextxy(i + 5, 605, oneend[k]);
		outtextxy(i + 20, 620, oneend1[k]);
	}


	for (j = 310; j < 760; j = j + 50)
	{
		rectangle(j, 650, j + 40, 690);    //���̵�һ����ĸ���꣨310,650������350,690��
		line(j, 650, j - 3, 653);
		line(j - 3, 653, j - 3, 693);
		line(j, 690, j - 3, 693);
		line(j + 40, 690, j + 43, 693);
		line(j - 3, 693, j + 43, 693);
		line(j + 40, 650, j + 43, 653);
		line(j + 43, 653, j + 43, 693);
		TCHAR ch[] = _T("Arial");
		settextstyle(20, 0, ch);
		k = (j - 310) / 50;
		outtextxy(j + 10, 660, two[k]);
	}

	for (j = 760; j < 850; j = j + 50)
	{                                                  //       310,650    350,690
		rectangle(j, 650, j + 40, 690);    //���̵�һ����ĸ���꣨760,650������800,690��
		line(j, 650, j - 3, 653);
		line(j - 3, 653, j - 3, 693);
		line(j, 690, j - 3, 693);
		line(j + 40, 690, j + 43, 693);
		line(j - 3, 693, j + 43, 693);
		line(j + 40, 650, j + 43, 653);
		line(j + 43, 653, j + 43, 693);
		settextstyle(20, 0, ch);
		k = (j - 760) / 50;
		outtextxy(j + 7, 655, three1[k]);
		outtextxy(j + 20, 669, three2[k]);
	}


	rectangle(860, 650, 940, 690);    //Enter(860,650������940,690��
	line(860, 650, 860 - 3, 653);
	line(860 - 3, 653, 860 - 3, 693);
	line(860, 690, 860 - 3, 693);
	line(940, 690, 943, 693);
	line(860 - 3, 693, 943, 693);
	line(940, 650, 943, 653);
	line(943, 653, 943, 693);
	settextstyle(20, 0, ch);
	TCHAR Enter[] = _T("Enter");
	settextstyle(20, 0, ch);
	outtextxy(870, 660, Enter);


	for (m = 340; m < 690; m = m + 50)
	{
		rectangle(m, 700, m + 40, 740);    //���̵�һ����ĸ���꣨340,700������380,740��
		line(m, 700, m - 3, 703);
		line(m - 3, 703, m - 3, 743);
		line(m, 740, m - 3, 743);
		line(m + 40, 740, m + 43, 743);
		line(m - 3, 743, m + 43, 743);
		line(m + 40, 700, m + 43, 703);
		line(m + 43, 703, m + 43, 743);
		TCHAR ch[] = _T("Arial");
		settextstyle(20, 0, ch);
		k = (m - 310) / 50;
		outtextxy(m + 10, 710, three[k]);
	}


	for (m = 690; m < 830; m = m + 50)
	{
		rectangle(m, 700, m + 40, 740);    //��690,700������830,740��
		line(m, 700, m - 3, 703);
		line(m - 3, 703, m - 3, 743);
		line(m, 740, m - 3, 743);
		line(m + 40, 740, m + 43, 743);
		line(m - 3, 743, m + 43, 743);
		line(m + 40, 700, m + 43, 703);
		line(m + 43, 703, m + 43, 743);
		settextstyle(20, 0, ch);
		k = (m - 690) / 50;
		outtextxy(m + 5, 706, h1[k]);
		outtextxy(m + 23, 717, h2[k]);
	}


	rectangle(840, 700, 940, 740);    // Shift��840,700������940,740��
	line(840, 700, 840 - 3, 703);
	line(840 - 3, 703, 840 - 3, 743);
	line(840, 740, 840 - 3, 743);
	line(940, 740, 943, 743);
	line(840 - 3, 743, 943, 743);
	line(940, 700, 943, 703);
	line(943, 703, 943, 743);
	settextstyle(20, 0, ch);
	outtextxy(850, 710, Shift);
}


//����
void highlight(char c)
{
	int x, y;
	if (c >= 'A'&&c <= 'Z')
		c = c + 32;
	if (c >= 'a'&&c <= 'z')          //��ΪСд
	{
		switch (c)
		{
		case 'q':
			x = 300; y = 600; break;
		case 'w':
			x = 350; y = 600; break;
		case 'e':
			x = 400; y = 600; break;
		case 'r':
			x = 450; y = 600; break;
		case 't':
			x = 500; y = 600; break;
		case 'y':
			x = 550; y = 600; break;
		case 'u':
			x = 600; y = 600; break;
		case 'i':
			x = 650; y = 600; break;
		case 'o':
			x = 700; y = 600; break;
		case 'p':
			x = 750; y = 600; break;
		case 'a':
			x = 310; y = 650; break;
		case 's':
			x = 360; y = 650; break;
		case 'd':
			x = 410; y = 650; break;
		case 'f':
			x = 460; y = 650; break;
		case 'g':
			x = 510; y = 650; break;
		case 'h':
			x = 560; y = 650; break;
		case 'j':
			x = 610; y = 650; break;
		case 'k':
			x = 660; y = 650; break;
		case 'l':
			x = 710; y = 650; break;
		case 'z':
			x = 340; y = 700; break;
		case 'x':
			x = 390; y = 700; break;
		case 'c':
			x = 440; y = 700; break;
		case 'v':
			x = 490; y = 700; break;
		case 'b':
			x = 540; y = 700; break;
		case 'n':
			x = 590; y = 700; break;
		case 'm':
			x = 640; y = 700; break;


		}




		fillrectangle(x, y, x + 40, y + 40);
		Sleep(20);
		clearrectangle(x, y, x + 40, y + 40);


	}
}
char*jiami(char*s)
{
	char miwen[1024] = { '\0' };
	int i;
	for (i = 0; i<6; i++)                       /*��������*/

	{

		miwen[i] = s[i] + i + 5;        /*���ü����ַ�*/

	}

	//miwen[i] = '\0';
	char *p = new char[strlen(miwen) + 1];
	strcpy(p, miwen);
	return p;
}
char*jiemi(char*cryptograph)
{
	char s[1024];
	int i;
	for (i = 0; i<6; i++)                       /*���������ַ���*/

	{

		s[i] = cryptograph[i] - i - 5;        /*���ý����ַ�*/

	}
	char *p = new char[strlen(s) + 1];
	strcpy(p, s);
	return p;
}
