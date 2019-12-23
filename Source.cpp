#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pdflib.h"
#include "libxl.h"
#include "iostream"
#include "fstream"

#define N 35
using namespace std;
struct Student_List//学生名单模板
{
	long num[N];//学号
	const char* name[N];//姓名
	char* path[N];//作业所在路径
	int memebers_num;//名单人数
};


int main(void)
{
	int i = 0;
	int count = 0;
	errno_t err;
	FILE* fp;
	char move;
	char c[] = "D:\\test_doc";
	int length = 9;//学号长度
	char* num[N] ;
	
	Student_List StudentList_class4; //助教手上的学生名单（完整）
	Student_List HomeworkFinishedList_class4;//交作业名单
	Student_List HomeworkUnfinishedList_class4;//没交作业名单
	/*————————————————
	创建新excel表，并写入数据
	————————————————*/	
	/*
	BookHandle book = xlCreateBook();
	if (book)
	{
		SheetHandle sheet = xlBookAddSheet(book, "Sheet1", NULL);
		if (sheet)
		{
			xlSheetWriteStr(sheet, 2, 1, "Hello,World!", NULL);
			xlSheetWriteStr(sheet, 4, 1, "加油，你是最棒的!", NULL);
			xlSheetWriteNum(sheet, 3, 1, 1000, NULL);
		}
		xlBookSave(book, "example.xls");
		xlBookRelease(book);
	}
	*/
	/*————————————————
	导入路径已知，文件名已知的excel表，并读取数据
	————————————————*/
	
	BookHandle book1 = xlCreateBook();
	if (book1)
	{
		if (xlBookLoad(book1, "18级计科4班.xls"))
		{
			SheetHandle sheet1 = xlBookGetSheet(book1, 0);
			if (sheet1)
			{
				long d;
				const char* s = xlSheetReadStr(sheet1, 4, 1, NULL);
				if (s) printf("%s\n", s);
				d = (long)xlSheetReadNum(sheet1, 3, 0, NULL);
				printf("%ld\n", d);
			}
		}
		xlBookRelease(book1);
	}
	return 0;
	
	/*————————————————
	已知学生名单文件名，读取数据
	————————————————*/
	
	BookHandle book1 = xlCreateBook();
	if (book1)
	{
		if (xlBookLoad(book1, "18级计科4班.xls"))
		{
			SheetHandle sheet1 = xlBookGetSheet(book1, 0);
			if (sheet1)
			{
				for (i = 0; i < 28; i++)
				{
					StudentList_class4.name[i] = xlSheetReadStr(sheet1, i+2, 1, NULL);
//					if (StudentList_class4.name[i])
//					printf("%s\t", StudentList_class4.name[i]);
					StudentList_class4.num[i] = (long)xlSheetReadNum(sheet1, i+2, 0, NULL);
//					printf("%ld\n", StudentList_class4.num[i]);
				}
			}//循环读取每名学生的学号和姓名，读取文件数据，写入结构体中
		}
		xlBookRelease(book1);
	}
	
//测试代码，可删
/*	printf("\n\n");
	for (i = 0; i < 28; i++)
	{
		printf("%s\t", StudentList_class4.name[i]);
		printf("%ld\n", StudentList_class4.num[i]);
	}
*/
	/*————————————————
	system（）函数，调用系统命令行，读取指定目录下的文件名,将文件名导入到指定的TXT文件中
	批处理dir 
	/s 指定目录中的文件及子文件
	/b 只显示文件名
	？代表任意一个字符
	* 代表任意一串字符，作用范围*后到下一分隔符为止
	/o:-d按时间由近到远排序
	/o:d按时间由远到近显示
	/
	————————————————*/
	/*
	system("dir ");
	system("dir D:\\test_doc /s/b > D:\\name.txt");
	
	/*————————————————
	读取学号txt，
	——————————————————*/
	err = fopen_s(&fp,"D:\\name.txt", "r");
	//fp = fopen("D:\\name.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！");
		exit(0);
	}
	else
	{
	//	while (true)
		//{
			i = 0;
			fseek(fp, strlen(c), SEEK_SET);//查找学号开头位置	
			fread(&num[i], length, 1, fp);//读取学号
	//		printf("%s \n", num[i]);
			HomeworkFinishedList_class4.num[i] = atol(num[i]);//放入结构体中的学号项
			printf("%ld\n", HomeworkFinishedList_class4.num[i]);//测试用语句
			while (true)
			{
				move = fgetc(fp);
				putc(move, fp);
				if (move == '\n')//遇到换行符结束，此时fp在下一行的开头
				{
					i += 1;
					break;
				}
				if (feof(fp))//全文结束
				{
					HomeworkFinishedList_class4.memebers_num = i;//交了作业的人数。
					break;
				}
				if (feof(fp))	break;
			}
	//	}
	fclose(fp);
	}
	



	
	

	return 0;
};
