/*
[示范]:希尔排序法
*/
#include <iostream>
#include <iomanip>
#define SIZE 8		//定义矩阵大小
using namespace std;

void shell (int *,int);  	//声明排序法子程序
void showdata (int *);  //声明打印数组子程序
void inputarr (int *,int);	//声明输入数组子程序
int main(void)
{ 
	int data[SIZE];
	inputarr(data,SIZE);
	cout<<"您输入的原始数组是：";
	showdata(data);
	shell(data,SIZE);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)
	{ 
		cout<<"请输入第 "<<i+1<<" 个元素：";
		cin>>data[i];
	}
}
void showdata(int data[])
{  	
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void shell(int data[],int size)
{  
	int i;        //i为扫描次数
	int j;        //以j来定位比较的元素
	int k=1;      //k打印计数
	int tmp;      //tmp用来暂存数据
	int jmp;      //设定间距位移量
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  //插入排序法
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		cout<<"第 "<<k++<<" 次排序：";
		showdata (data);
		jmp=jmp/2;    //控制循环数
	}
}
