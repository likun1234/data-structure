/*
[示范]:堆积排序法
*/
#include <iostream>
#include <iomanip>
using namespace std;
void heap(int*,int);
void ad_heap(int*,int,int);
int main(void)
{  
	int data[9]={0,5,6,4,8,3,2,7,1};	//原始数组内容
	int size=9;
	cout<<"原始数组：";
	for(int i=1;i<size;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	heap(data,size);						//建立堆积树
	cout<<"\n排序结果：";
	for(int i=1;i<size;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
	system("pause");
	return 0;
}
void heap(int *data,int size)
{  
	int i,j,tmp;
	for(i=(size/2);i>0;i--)			    //建立堆积树节点	
		ad_heap(data,i,size-1);
	cout<<"\n堆积内容：";
	for(i=1;i<size;i++)					//原始堆积树内容
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
	for(i=size-2;i>0;i--)				   //堆积排序
	{  
		tmp=data[i+1];			   //头尾节点交换      
		data[i+1]=data[1];
		data[1]=tmp;
		ad_heap(data,1,i);			   //处理剩余节点
		cout<<"\n处理过程：";
		for(j=1;j<size;j++)
			cout<<"["<<setw(2)<<data[j]<<"] ";
	}
}
void ad_heap(int *data,int i,int size)
{  
	int j,tmp,post;
	j=2*i;
	tmp=data[i];
	post=0;
	while(j<=size && post==0)
	{  
		if(j<size)
		{
			if(data[j]<data[j+1])		//找出最大节点
				j++;
		}
		if(tmp>=data[j])			//若树根较大，结束比较过程
			post=1;
		else
		{  
			data[j/2]=data[j];		//若树根较小，则继续比较
			j=2*j;
		}   
   }
   data[j/2]=tmp;					//指定树根为父节点
}
