#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*用到了time函数，所以要有这个头文件*/

int nandu;                 //全局变量
int COUNT;                  //雷数
int row, col;           //行列
char mine[50][50] = { 0 };//存雷的数组（雷盘）
char show[50][50] = { 0 };//展示的数组（雷盘）
double  starttime, finishtime;
//行列（难度不同改变row和col的数值）
//	而且行列数比格数多2；

/*是否开始游戏*/
void start()
{
	void chengdu();
	int input = 0;
	printf("***************************************\n");
	printf("****       欢迎进入扫雷界面        ****\n");
	printf("\n");
	printf("****       您是否要开始游戏？      ****\n");
	do
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf(" --—————————————————-\n");
		printf("|     1:  (开始)                      |\n");
		printf("| 没错别磨叽了我就是要玩这个laji游戏! |\n");
		printf("|                                     |\n");
		printf("|     0:  (离开)                      |\n");
		printf("| 垃圾游戏我一定是点错才进来的拜拜了您|");
		printf("\n");
		printf(" --—————————————————-\n");


		printf("请选择>\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			chengdu();               //游戏程序
			break;
		case 0:

			printf("———— * 退出游戏 * ————\n");
			printf("———————————————\n");
			break;
		default:
			printf("*  输入不正确 ，请重新选择！ *\n");
			break;
		}
	} while (input);
}

/*选择水平跳入*/
void chengdu()
{
	void game();
	system("CLS");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("***************************************\n");
	printf("*****       请·选择游戏等级：   ******\n");
	printf("\n");
	printf("*****          1：简单           ******\n");
	printf("     （幼儿园の水平，你敢玩儿吗?）     \n");
	printf("*****          2: 一般           ******\n");
	printf("     （初等智力水平，谁试谁知道!）     \n");
	printf("*****          3：困难           ******\n");
	printf("     （全球只有5%的人能通关的游戏）    \n");

	printf("***************************************\n");
	scanf_s("%d", &nandu);    //扫雷难度
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
		printf("*  输入不正确 ，请重新选择！ *\n");
	}
}

/*初始化棋盘并打印*/
void setchess()//初始化棋盘
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

/*打印棋盘*/
void printboard(char board[50][50])         //行列大于十之后的修改
{
	system("CLS");//每次打印雷盘之前清屏一次
	int i = 0;
	int j = 0;
	printf("\n"); 
	printf("\n");
	printf("\n");
	printf("棋盘:\n");
	printf("   ");//为了打印列坐标时对齐
	if (row <= 12)
	{
		for (i = 1; i < col - 1; i++)
			printf("%d ", i);//打印列坐标1 2 3 4 5 6 7 8 ……
		printf("\n");
		for (i = 1; i < row - 1; i++)
		{
			printf("%d  ", i);//打印行坐标1 2 3 4 5 6 7 8 9 ……
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
			printf("%d  ", i);//打印列坐标1 2 3 4 5 6 7 8 ……
		for (i = 10; i < col - 1; i++)
			printf("%d ", i);
		printf("\n");
		for (i = 1; i < 10; i++)
		{
			printf("%d  ", i);//打印行坐标1 2 3 4 5 6 7 8 9 ……
			for (j = 1; j < col - 1; j++)
			{
				printf("%c  ", board[i][j]);
			}
			printf("\n");
		}
		for (i = 10; i < row - 1; i++)
		{
			printf("%d ", i);//打印行坐标1 2 3 4 5 6 7 8 9 ……
			for (j = 1; j < col - 1; j++)
			{
				printf("%c  ", board[i][j]);
			}
			printf("\n");
		}
	}

}
/*布雷*/
void setboard(char board[50][50], int COUNT)   //给mine布雷
{
	int count = 0;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));//根据时间函数产生不同的种子数→产生不同的随机数组
	count = COUNT;//雷数
	while (count>0)
	{
		x = rand() % (row - 2) + 1;   //保证行坐标在1到row-2之间  ps: row=行+2
		y = rand() % (col - 2) + 1; //保证列坐标在1到col_2之间
		if (board[x][y] == 0)//
		{
			board[x][y] = '*';//‘1’代表有雷
			count--;//布一次雷，雷数减一
		}//如果系统提供的种子没有变化，每次调用rand函数生成的伪随机数序列都是一样的!!
	}
}

/*统计雷数*/
int sumCOUNT(char board[50][50], int x, int y)//统计雷数
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

void expend(char board1[50][50], char board2[50][50], int x, int y, int *num)//扩展式排雷（递归）
{
	int i = 0;                      //1是mine  2是show
	int j = 0;
	if (board2[x][y] == 'o')//如果该位置字符为'o'，则该位置是未排过的，进行排雷
	{
		(*num)++;//排雷次数加一
		int count = sumCOUNT(board1, x, y);//统计该位置周围的雷数
		if (count != 0)//如果该位置周围的雷数不为0
		{
			board2[x][y] = count + '0';//显示雷数 切变为字符格式
		}
		else//如果该位置的雷数为0，则向它周围八个位置扩展排雷
		{
			board2[x][y] = '0';//该位置的字符显示为‘0’

			for (j = -1; j <= 1; j++)
			{
				for (i = -1; i <= 1; i++)
				{
					if ((x + i >= 1) && (x + i<row - 1) && (y + j >= 1) && (y + j<col - 1))//确保不越界?
					{
						if (i != 0 || j != 0)//避免重复排到自己
							expend(board1, board2, x + i, y + j, num);
					}
				}
			}
		}
	}
	else
		printf("你输入的坐标已经进行了操作，请选择其他坐标进行输入。");
	return;
}

/*雷的标记*/
void sign(char board[50][50], int x, int y)   //用‘F'代表插旗
{
	if (board[x][y] == 'o')
	{
		board[x][y] = 'F';
	}
}

void unsign(char board[50][50], int x, int y)//取消标记
{
	if (board[x][y] == 'F')
	{
		board[x][y] = 'o';
	}
}

/*开始游戏*/
void game()
{
	void unsign(char board[50][50], int x, int y);
	void sign(char board[50][50], int x, int y);
	int sumCOUNT(char board[50][50], int x, int y);
	void expend(char board1[50][50], char board2[50][50], int x, int y, int *num);
	void setboard(char board[50][50], int COUNT);
	void printboard(char board[50][50]);
	void setchess();//初始化棋盘
	int x = 0;
	int y = 0;
	int win = 0;//判定输赢的排雷次数
	int select = 0;//决定游戏功能的变量
	starttime = clock();

	setchess();           //初始化棋盘
	printboard(show);//打印雷盘
	setboard(mine, COUNT);//布雷

	while (win < ((row - 2)*(col - 2) - COUNT))//当排雷的次数不少于无雷格数（雷盘格数 减 雷数）时，停止排雷
	{
		printf("请选择功能：\n1: 排雷  2: 标记(F)  3: 取消标记  4: 再来一局\n");
		scanf_s("%d", &select);
		fflush(stdin);//清空输入缓冲区，避免多输造成的影响*/
		if (select == 1)//1 for 排雷
		{
			printf("请输入坐标：\n");
			scanf_s("%d %d", &x, &y);
			fflush(stdin);//清空输入缓冲区，避免多输造成的影响
			if (x >= 1 && x <= row - 1 && y >= 1 && y <= col - 1)//检验坐标是否合法
			{
				if (mine[x][y] == '*')//如果所选位置有雷
				{
					if (win == 0)
					{
						printboard(mine);//排雷失败后打印一下雷的分布
						system("mspaint C:\\Users\\master\\Desktop\\ps\\naozi.JPG");
						printf(" --—————————————————-\n");
						printf("***************************************\n");
						printf("*      Game over! 游戏失败！          *\n");
						printf("？？？不是我说，你的人品也太差了吧？？？\n");
						finishtime = clock();//取结束时间
						printf("          *   用时: %d 秒   *          \n", (int)(finishtime - starttime) / CLOCKS_PER_SEC);
						printf("***************************************\n");
						printf("\n");
						printf("Sorry for your stupid……要不你再来一局？\n");
						return;
					}
					else
					{

						printboard(mine);//排雷失败后打印一下雷的分布
						printf(" --—————————————————-\n");
						printf("***************************************\n");
						printf("*      Game over! 游戏失败！          *\n");
						printf("*     You should improve your IQ...   *\n");
						finishtime = clock();//取结束时间
						printf("          *   用时: %d 秒   *          \n", (int)(finishtime - starttime) / CLOCKS_PER_SEC);
						printf("***************************************\n");
						system("mspaint C:\\Users\\master\\Desktop\\ps\\naozi.JPG");

						printf("Sorry for your stupid……要不你再来一局？\n");
						return;
					}

				}
				else//如果所选位置没有雷，进行扩展式排雷
				{
					expend(mine, show, x, y, &win);
				}
				printboard(show);//打印排雷后的雷盘
			}
			else
			{
				printf("错误坐标：\n");
			}
		}
		else if (select == 2)//2 for 标记
		{
			printf("请输入坐标：\n");
			scanf_s("%d %d", &x, &y);
			fflush(stdin);//清空输入缓冲区，避免多输造成的影响*/
			sign(show, x, y);
			printboard(show);
		}
		else if (select == 3)//3 for 取消标记
		{
			printf("请输入坐标：\n");
			scanf_s("%d %d", &x, &y);
			fflush(stdin);//清空输入缓冲区，避免多输造成的影响*/
			unsign(show, x, y);
			printboard(show);
		}
		else if (select == 4)//4 for 结束游戏
		{
			game();
		}
	}
	printf("******************************\n");
	printf("           哈哈哈哈哈!        \n");
	printf("*      *   扫雷成功！  *     *\n");
	finishtime = clock();
	printf("      *   用时: %d 秒   *     \n", (int)(finishtime - starttime) / CLOCKS_PER_SEC);
	printf("       Congratulations!       \n");
	printf("******************************\n");
	system("mspaint C:\\Users\\master\\Desktop\\ps\\timg.JPG");
}

/*主函数*/
int main()
{
	start();//开始
	system("pause");
	return 0;
}


/*d    行列     雷数   p.s. 常规扫雷难度 注意了别总忘
9*9		10          //此处没有雷 周围没有雷怎么展开？
16*16		40
16*30		99
*/