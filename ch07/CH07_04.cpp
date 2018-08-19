/*
[示范]:插入排序法
*/
#include <iostream>
#include <iomanip>
#define SIZE 6  //定义数组大小
using namespace std;

void inser (int *);		//声明插入排序法子程序
void showdata (int *);	//声明打印数组子程序
void inputarr (int *,int);	//声明输入数组子程序
int  main(void)
{ 
	int data[SIZE];
	inputarr(data,SIZE);	//把数组名和数组大小传给子程序
	cout<<"您输入的原始数组是：";
	showdata (data);
	inser(data);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)	//利用循环输入数组数据
	{ 
		cout<<"请输入第 "<<i+1<<" 个元素：";
		cin>>data[i];
	}
}
void showdata(int data[])
{  
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];	//打印数组数据
	cout<<endl;
}
void inser(int data[])
{  
	int i;     //i为扫描次数
	int j;     //以j来定位比较的元素
	for (i=1;i<SIZE;i++)  //扫描循环次数为SIZE-1
	{  
 		int tmp;   //tmp用来暂存数据
		tmp=data[i];
        j=i-1;
	    while (j>=0 && tmp<data[j])  //如果第二元素小于第一元素
		{							 
			data[j+1]=data[j];		//就把所有元素往后推一个位置		
			j--;
		}
		data[j+1]=tmp;              //最小的元素放到第一个元素	
		cout<<"第 "<<i<<" 次扫描：";
		showdata(data);
	}
}
