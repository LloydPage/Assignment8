/*Lloyd Page*/
/*reads floats from float1.txt, calculates meand and stand dev of all read in values*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float avg(float[],int);
float stddev(float[],float,int);
int main()
{
	int x;
	char handler[100];
	FILE *f=fopen("float1.txt","r");
	fgets(handler,sizeof(handler),f);
	x=atoi(handler);
	float num[x];
	for(int i=0;i<x;i++)
	{
		float a;
		fgets(handler,sizeof(handler),f);
		a=atof(handler);
		num[i]=a;
	}
	float a=avg(num,x);
	printf("%g\n",a);
	float stdev=stddev(num,a,x);
	printf("%g\n",stdev);
	return 0;
}
float avg(float num[],int size)
{
	float sum=0;
	for(int i=0;i<size;i++)
		sum+=num[i];
	return sum/((float)size);
}
float stddev(float num[],float avg,int size)
{
	float sum=0;
	for(int i=0;i<size;i++)
	{
		sum=sum+(num[i]-avg)*(num[i]-avg);
	}
	sum=sum/((float)(size-1));
	return sqrt(sum);
}
