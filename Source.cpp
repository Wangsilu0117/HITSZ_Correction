#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"
#include "pdflib.h"
#include "libxl.h"
#include "iostream"

#define N 35

struct Student_List//�������ϵ�ѧ��������������
{
	long num[N];
	const char* name[N];
	const char* path[N];
}; 

int main(void)
{
	int i;
	Student_List StudentList_class4;
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
	/*
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
	*/
	/*��������������������������������
	��֪ѧ�������ļ�������ȡ����
	��������������������������������*/
	/*
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
*/
//���Դ��룬��ɾ
/*	printf("\n\n");
	for (i = 0; i < 28; i++)
	{
		printf("%s\t", StudentList_class4.name[i]);
		printf("%ld\n", StudentList_class4.num[i]);
	}
*/
	/*��������������������������������
	system��������������ϵͳ�����У���ȡָ��Ŀ¼�µ��ļ���
	��������������������������������*/
	
	return 0;
};
