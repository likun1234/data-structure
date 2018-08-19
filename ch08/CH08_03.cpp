#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int bin_search(int*,int);
int main(void)
{  
	int i,j,val=1,num,data[50]={0};
	for (i=0;i<50;i++)
	{  
		data[i]=val;
		val+=(rand()%5+1);
	}
	while(1)
	{  
		num=0;
		cout<<"请输入查找键值(1-150)，输入-1结束：";
		cin>>val;
		if(val==-1)
			break;
		num=bin_search(data,val);
		if(num==-1)
			cout<<"##### 没有找到["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"在第"<<setw(2)<<num+1<<"个位置找到 ["<<setw(3)<<data[num]<<"]"<<endl;
	}
	cout<<"数据内容："<<endl;
	for(i=0;i<5;i++)
	{ 
		for(j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	system("pause");
	return 0;
}
int bin_search(int data[50],int val)
{  
	int low,mid,high;
	low=0;
	high=49;
	cout<<"查找过程中......"<<endl;
	while(low<= high && val !=-1)
	{  
		mid=low+((val-data[low])*(high-low)/(data[high]-data[low])); /*插值法公式*/
		if (val==data[mid])
			return mid;
		else if (val < data[mid])
		{  
			cout<<val<<" 介于位置 "<<low+1<<"["<<setw(3)<<data[low]<<"]和中间值 "<<mid+1<<"["<<setw(3)<<data[mid]<<"]，找左半边"<<endl;
			high=mid-1;	     
		}
		else if(val > data[mid])
		{  
			cout<<val<<" 介于中间值位置 "<<mid+1<<"["<<setw(3)<<data[mid]<<"]和"<<high+1<<"["<<setw(3)<<data[high]<<"]，找右半边"<<endl;
			low=mid+1;   	     
		}
	}
	return -1;
}
