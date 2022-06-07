#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*�õ���time����������Ҫ�����ͷ�ļ�*/

int nandu;                 //ȫ�ֱ���
int COUNT;                  //����
int row, col;           //����
char mine[50][50] = { 0 };//���׵����飨���̣�
char show[50][50] = { 0 };//չʾ�����飨���̣�
double  starttime, finishtime;
//���У��ѶȲ�ͬ�ı�row��col����ֵ��
//	�����������ȸ�����2��

/*�Ƿ�ʼ��Ϸ*/
void start()
{
	void chengdu();
	int input = 0;
	printf("***************************************\n");
	printf("****       ��ӭ����ɨ�׽���        ****\n");
	printf("\n");
	printf("****       ���Ƿ�Ҫ��ʼ��Ϸ��      ****\n");
	do
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf(" --����������������������������������-\n");
		printf("|     1:  (��ʼ)                      |\n");
		printf("| û���ĥߴ���Ҿ���Ҫ�����laji��Ϸ! |\n");
		printf("|                                     |\n");
		printf("|     0:  (�뿪)                      |\n");
		printf("| ������Ϸ��һ���ǵ��Ž����İݰ�����|");
		printf("\n");
		printf(" --����������������������������������-\n");


		printf("��ѡ��>\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			chengdu();               //��Ϸ����
			break;
		case 0:

			printf("�������� * �˳���Ϸ * ��������\n");
			printf("������������������������������\n");
			break;
		default:
			printf("*  ���벻��ȷ ��������ѡ�� *\n");
			break;
		}
	} while (input);
}

/*ѡ��ˮƽ����*/
void chengdu()
{
	void game();
	system("CLS");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("***************************************\n");
	printf("*****       �롤ѡ����Ϸ�ȼ���   ******\n");
	printf("\n");
	printf("*****          1����           ******\n");
	printf("     ���׶�԰��ˮƽ����������?��     \n");
	printf("*****          2: һ��           ******\n");
	printf("     ����������ˮƽ��˭��˭֪��!��     \n");
	printf("*****          3������           ******\n");
	printf("     ��ȫ��ֻ��5%������ͨ�ص���Ϸ��    \n");

	printf("***************************************\n");
	scanf_s("%d", &nandu);    //ɨ���Ѷ�
	switch (nandu)
	{
	case 1:
		row = 11, col = 11;
		COUNT = 10;
		game();

		break;
	case 2:
		row = 18, col = 18;
		COUNT = 40;
		game();
		break;
	case 3:
		row = 18, col = 32;
		COUNT = 99;
		game();
		break;
	default:
		printf("*  ���벻��ȷ ��������ѡ�� *\n");
	}
}

/*��ʼ�����̲���ӡ*/
void setchess()//��ʼ������
{

	int i = 0;
	int j = 0;
	for (int i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{

			show[i][j] = 'o';
		}
	}
}

/*��ӡ����*/
void printboard(char board[50][50])         //���д���ʮ֮����޸�
{
	system("CLS");//ÿ�δ�ӡ����֮ǰ����һ��
	int i = 0;
	int j = 0;
	printf("\n"); 
	printf("\n");
	printf("\n");
	printf("����:\n");
	printf("   ");//Ϊ�˴�ӡ������ʱ����
	if (row <= 12)
	{
		for (i = 1; i < col - 1; i++)
			printf("%d ", i);//��ӡ������1 2 3 4 5 6 7 8 ����
		printf("\n");
		for (i = 1; i < row - 1; i++)
		{
			printf("%d  ", i);//��ӡ������1 2 3 4 5 6 7 8 9 ����
			for (j = 1; j < col - 1; j++)
			{
				printf("%c ", board[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		for (i = 1; i < 10; i++)
			printf("%d  ", i);//��ӡ������1 2 3 4 5 6 7 8 ����
		for (i = 10; i < col - 1; i++)
			printf("%d ", i);
		printf("\n");
		for (i = 1; i < 10; i++)
		{
			printf("%d  ", i);//��ӡ������1 2 3 4 5 6 7 8 9 ����
			for (j = 1; j < col - 1; j++)
			{
				printf("%c  ", board[i][j]);
			}
			printf("\n");
		}
		for (i = 10; i < row - 1; i++)
		{
			printf("%d ", i);//��ӡ������1 2 3 4 5 6 7 8 9 ����
			for (j = 1; j < col - 1; j++)
			{
				printf("%c  ", board[i][j]);
			}
			printf("\n");
		}
	}

}
/*����*/
void setboard(char board[50][50], int COUNT)   //��mine����
{
	int count = 0;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));//����ʱ�亯��������ͬ����������������ͬ���������
	count = COUNT;//����
	while (count>0)
	{
		x = rand() % (row - 2) + 1;   //��֤��������1��row-2֮��  ps: row=��+2
		y = rand() % (col - 2) + 1; //��֤��������1��col_2֮��
		if (board[x][y] == 0)//
		{
			board[x][y] = '*';//��1����������
			count--;//��һ���ף�������һ
		}//���ϵͳ�ṩ������û�б仯��ÿ�ε���rand�������ɵ�α��������ж���һ����!!
	}
}

/*ͳ������*/
int sumCOUNT(char board[50][50], int x, int y)//ͳ������
{
	int num = 0;
	if (board[x - 1][y - 1] == '*')
		num++;
	if (board[x - 1][y] == '*')
		num++;
	if (board[x - 1][y + 1] == '*')
		num++;
	if (board[x][y - 1] == '*')
		num++;
	if (board[x][y + 1] == '*')
		num++;
	if (board[x + 1][y - 1] == '*')
		num++;
	if (board[x + 1][y] == '*')
		num++;
	if (board[x + 1][y + 1] == '*')
		num++;

	return num;
}

void expend(char board1[50][50], char board2[50][50], int x, int y, int *num)//��չʽ���ף��ݹ飩
{
	int i = 0;                      //1��mine  2��show
	int j = 0;
	if (board2[x][y] == 'o')//�����λ���ַ�Ϊ'o'�����λ����δ�Ź��ģ���������
	{
		(*num)++;//���״�����һ
		int count = sumCOUNT(board1, x, y);//ͳ�Ƹ�λ����Χ������
		if (count != 0)//�����λ����Χ��������Ϊ0
		{
			board2[x][y] = count + '0';//��ʾ���� �б�Ϊ�ַ���ʽ
		}
		else//�����λ�õ�����Ϊ0����������Χ�˸�λ����չ����
		{
			board2[x][y] = '0';//��λ�õ��ַ���ʾΪ��0��

			for (j = -1; j <= 1; j++)
			{
				for (i = -1; i <= 1; i++)
				{
					if ((x + i >= 1) && (x + i<row - 1) && (y + j >= 1) && (y + j<col - 1))//ȷ����Խ��?
					{
						if (i != 0 || j != 0)//�����ظ��ŵ��Լ�
							expend(board1, board2, x + i, y + j, num);
					}
				}
			}
		}
	}
	else
		printf("������������Ѿ������˲�������ѡ����������������롣");
	return;
}

/*�׵ı��*/
void sign(char board[50][50], int x, int y)   //�á�F'�������
{
	if (board[x][y] == 'o')
	{
		board[x][y] = 'F';
	}
}

void unsign(char board[50][50], int x, int y)//ȡ�����
{
	if (board[x][y] == 'F')
	{
		board[x][y] = 'o';
	}
}

/*��ʼ��Ϸ*/
void game()
{
	void unsign(char board[50][50], int x, int y);
	void sign(char board[50][50], int x, int y);
	int sumCOUNT(char board[50][50], int x, int y);
	void expend(char board1[50][50], char board2[50][50], int x, int y, int *num);
	void setboard(char board[50][50], int COUNT);
	void printboard(char board[50][50]);
	void setchess();//��ʼ������
	int x = 0;
	int y = 0;
	int win = 0;//�ж���Ӯ�����״���
	int select = 0;//������Ϸ���ܵı���
	starttime = clock();

	setchess();           //��ʼ������
	printboard(show);//��ӡ����
	setboard(mine, COUNT);//����

	while (win < ((row - 2)*(col - 2) - COUNT))//�����׵Ĵ������������׸��������̸��� �� ������ʱ��ֹͣ����
	{
		printf("��ѡ���ܣ�\n1: ����  2: ���(F)  3: ȡ�����  4: ����һ��\n");
		scanf_s("%d", &select);
		fflush(stdin);//������뻺���������������ɵ�Ӱ��*/
		if (select == 1)//1 for ����
		{
			printf("���������꣺\n");
			scanf_s("%d %d", &x, &y);
			fflush(stdin);//������뻺���������������ɵ�Ӱ��
			if (x >= 1 && x <= row - 1 && y >= 1 && y <= col - 1)//���������Ƿ�Ϸ�
			{
				if (mine[x][y] == '*')//�����ѡλ������
				{
					if (win == 0)
					{
						printboard(mine);//����ʧ�ܺ��ӡһ���׵ķֲ�
						system("mspaint C:\\Users\\master\\Desktop\\ps\\naozi.JPG");
						printf(" --����������������������������������-\n");
						printf("***************************************\n");
						printf("*      Game over! ��Ϸʧ�ܣ�          *\n");
						printf("������������˵�������ƷҲ̫���˰ɣ�����\n");
						finishtime = clock();//ȡ����ʱ��
						printf("          *   ��ʱ: %d ��   *          \n", (int)(finishtime - starttime) / CLOCKS_PER_SEC);
						printf("***************************************\n");
						printf("\n");
						printf("Sorry for your stupid����Ҫ��������һ�֣�\n");
						return;
					}
					else
					{

						printboard(mine);//����ʧ�ܺ��ӡһ���׵ķֲ�
						printf(" --����������������������������������-\n");
						printf("***************************************\n");
						printf("*      Game over! ��Ϸʧ�ܣ�          *\n");
						printf("*     You should improve your IQ...   *\n");
						finishtime = clock();//ȡ����ʱ��
						printf("          *   ��ʱ: %d ��   *          \n", (int)(finishtime - starttime) / CLOCKS_PER_SEC);
						printf("***************************************\n");
						system("mspaint C:\\Users\\master\\Desktop\\ps\\naozi.JPG");

						printf("Sorry for your stupid����Ҫ��������һ�֣�\n");
						return;
					}

				}
				else//�����ѡλ��û���ף�������չʽ����
				{
					expend(mine, show, x, y, &win);
				}
				printboard(show);//��ӡ���׺������
			}
			else
			{
				printf("�������꣺\n");
			}
		}
		else if (select == 2)//2 for ���
		{
			printf("���������꣺\n");
			scanf_s("%d %d", &x, &y);
			fflush(stdin);//������뻺���������������ɵ�Ӱ��*/
			sign(show, x, y);
			printboard(show);
		}
		else if (select == 3)//3 for ȡ�����
		{
			printf("���������꣺\n");
			scanf_s("%d %d", &x, &y);
			fflush(stdin);//������뻺���������������ɵ�Ӱ��*/
			unsign(show, x, y);
			printboard(show);
		}
		else if (select == 4)//4 for ������Ϸ
		{
			game();
		}
	}
	printf("******************************\n");
	printf("           ����������!        \n");
	printf("*      *   ɨ�׳ɹ���  *     *\n");
	finishtime = clock();
	printf("      *   ��ʱ: %d ��   *     \n", (int)(finishtime - starttime) / CLOCKS_PER_SEC);
	printf("       Congratulations!       \n");
	printf("******************************\n");
	system("mspaint C:\\Users\\master\\Desktop\\ps\\timg.JPG");
}

/*������*/
int main()
{
	start();//��ʼ
	system("pause");
	return 0;
}


/*d    ����     ����   p.s. ����ɨ���Ѷ� ע���˱�����
9*9		10          //�˴�û���� ��Χû������ôչ����
16*16		40
16*30		99
*/