#include "math.h"
#include "mat.h"
#include "plane.h"
#include "space.h"
#include "three.h"
#include "eight.h"
#include "twenty.h"
#include "rope.h"
#include<string>
void (*pfun[10])() = {NULL,math,mat,plane,space,three,eight,twenty,rope };

void menu()
{
	cout << "\n                        ��ӭ������*** V �ռ�***";
	printf("\n\n\t****************    0    �˳�	                ***************\n");
	printf("\n\t****************    1    ��ѧ����	        ***************\n");
	printf("\n\t****************    2    ��������	        ***************\n");
	printf("\n\t****************    3    ƽ���ϵ�ṹ����	***************\n");
	printf("\n\t****************    4    �ռ��ϵ�ṹ����	***************\n");
	printf("\n\t****************    5    ����Ԫ���ڵ����	***************\n");
	printf("\n\t****************    6    ����Ԫ�˽ڵ����	***************\n");
	printf("\n\t****************    7    ����Ԫ��ʮ�ڵ����	***************\n");
	printf("\n\t****************    8    ������������������	***************\n\n\n\t\t\t");
}

void main()///V�ռ���������
{
	/*FILE* pf = fopen("data.txt", "rb");
	if (pf != NULL)
	{
		fread(&count, sizeof(int), 1, pf);
		cps = (CPS*)malloc(count * sizeof(CPS));
		fread(cps, sizeof(CPS), count, pf);
		fclose(pf);
		pf = NULL;
	}*/
	while (1)
	{
		system("cls");
		menu();
		printf("����������ѡ�� ");
		int n = -1;
		scanf("%d",&n);
		while(n < 0 || n>8)
		{
			cout << "\n\t\t�������\n\n\t\t������0-8������:";
			while (getchar() != 10) {}
			scanf("%d", &n);
		}
		while(getchar()!=10){}
		if (n == 0)
			break;
		pfun[n]();
	}
	/*pf = fopen("data.txt", "wb");
	fwrite(&count, sizeof(int), 1, pf);
	fwrite(cps, sizeof(CPS), count, pf);
	fclose(pf);
	pf = NULL;
	free(cps);*/
}

