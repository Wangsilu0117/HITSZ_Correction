#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pdflib.h"
#include "libxl.h"
#include "iostream"
#include "fstream"

#define N 35
using namespace std;
struct Student_List//ѧ������ģ��
{
	long num[N];//ѧ��
	const char* name[N];//����
	char* path[N];//��ҵ����·��
	int memebers_num;//��������
};


int main(void)
{
	int i = 0;
	int count = 0;
	errno_t err;
	FILE* fp;
	char move;
	char c[] = "D:\\test_doc";
	int length = 9;//ѧ�ų���
	char* num[N] ;
	
	Student_List StudentList_class4; //�������ϵ�ѧ��������������
	Student_List HomeworkFinishedList_class4;//����ҵ����
	Student_List HomeworkUnfinishedList_class4;//û����ҵ����
	/*��������������������������������
	������excel����д������
	��������������������������������*/	
	/*
	BookHandle book = xlCreateBook();
	if (book)
	{
		SheetHandle sheet = xlBookAddSheet(book, "Sheet1", NULL);
		if (sheet)
		{
			xlSheetWriteStr(sheet, 2, 1, "Hello,World!", NULL);
			xlSheetWriteStr(sheet, 4, 1, "���ͣ����������!", NULL);
			xlSheetWriteNum(sheet, 3, 1, 1000, NULL);
		}
		xlBookSave(book, "example.xls");
		xlBookRelease(book);
	}
	*/
	/*��������������������������������
	����·����֪���ļ�����֪��excel������ȡ����
	��������������������������������*/
	
	BookHandle book1 = xlCreateBook();
	if (book1)
	{
		if (xlBookLoad(book1, "18���ƿ�4��.xls"))
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
	
	/*��������������������������������
	��֪ѧ�������ļ�������ȡ����
	��������������������������������*/
	
	BookHandle book1 = xlCreateBook();
	if (book1)
	{
		if (xlBookLoad(book1, "18���ƿ�4��.xls"))
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
			}//ѭ����ȡÿ��ѧ����ѧ�ź���������ȡ�ļ����ݣ�д��ṹ����
		}
		xlBookRelease(book1);
	}
	
//���Դ��룬��ɾ
/*	printf("\n\n");
	for (i = 0; i < 28; i++)
	{
		printf("%s\t", StudentList_class4.name[i]);
		printf("%ld\n", StudentList_class4.num[i]);
	}
*/
	/*��������������������������������
	system��������������ϵͳ�����У���ȡָ��Ŀ¼�µ��ļ���,���ļ������뵽ָ����TXT�ļ���
	������dir 
	/s ָ��Ŀ¼�е��ļ������ļ�
	/b ֻ��ʾ�ļ���
	����������һ���ַ�
	* ��������һ���ַ������÷�Χ*����һ�ָ���Ϊֹ
	/o:-d��ʱ���ɽ���Զ����
	/o:d��ʱ����Զ������ʾ
	/
	��������������������������������*/
	/*
	system("dir ");
	system("dir D:\\test_doc /s/b > D:\\name.txt");
	
	/*��������������������������������
	��ȡѧ��txt��
	������������������������������������*/
	err = fopen_s(&fp,"D:\\name.txt", "r");
	//fp = fopen("D:\\name.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	else
	{
	//	while (true)
		//{
			i = 0;
			fseek(fp, strlen(c), SEEK_SET);//����ѧ�ſ�ͷλ��	
			fread(&num[i], length, 1, fp);//��ȡѧ��
	//		printf("%s \n", num[i]);
			HomeworkFinishedList_class4.num[i] = atol(num[i]);//����ṹ���е�ѧ����
			printf("%ld\n", HomeworkFinishedList_class4.num[i]);//���������
			while (true)
			{
				move = fgetc(fp);
				putc(move, fp);
				if (move == '\n')//�������з���������ʱfp����һ�еĿ�ͷ
				{
					i += 1;
					break;
				}
				if (feof(fp))//ȫ�Ľ���
				{
					HomeworkFinishedList_class4.memebers_num = i;//������ҵ��������
					break;
				}
				if (feof(fp))	break;
			}
	//	}
	fclose(fp);
	}
	



	
	

	return 0;
};
