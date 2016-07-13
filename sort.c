/*Lloyd Page*/
/*3 arrays allocated using malloc(), fill one with randum numbers, and sort one ascendingly, and the other descendingly, and print all three arrays*/
/**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void insertUp(int*,int);
void insertDn(int*,int);
int main()
{
	srand(time(NULL));
	int size;
	while(1)
	{
		int N=3;
		char *line=malloc(N);
		printf("Enter the size of the array\n");
		fgets(line,N,stdin);
		size_t last=strlen(line);
		while(line[last-1]!='\n')
		{
			N*=2;
			line=realloc(line,N);
			fgets(line+last,N/2,stdin);
			last=strlen(line);
		}
		if(sscanf(line,"%d",&size))
			break;
	}
	int *a=(int*)malloc(size*4);
	for(int i=0;i<size;i++)
	{
		*(a+i)=rand();
	}
	printf("Elements in Array a\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\n",*(a+i));
	}
	int *b=(int*)malloc(size*4);
	for(int i=0;i<size;i++)
	{
		*(b+i)=*(a+i);
	}
	insertUp(b,size);
	printf("Elements in Array b\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\n",*(b+i));
	}
	int *c=(int*)malloc(size*4);
	printf("Elements in Array c\n");
	for(int i=0;i<size;i++)
	{
		*(c+i)=*(a+i);
	}
	insertDn(c,size);
	for(int i=0;i<size;i++)
	{
		printf("%d\n",*(c+i));
	}
	free(a);
	free(b);
	free(c);
	return 0;
}
void insertDn(int*n,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(*(n+i)<*(n+j))
			{
				int temp=*(n+i);
				*(n+i)=*(n+j);
				*(n+j)=temp;
			}
		}
	}
}
void insertUp(int*n,int size)
{
	for(int i=size-1;i>-1;i--)
	{
		for(int j=i;j>-1;j--)
		{
			if(*(n+i)<*(n+j))
			{
				int temp=*(n+i);
				*(n+i)=*(n+j);
				*(n+j)=temp;
			}
		}
	}
}
