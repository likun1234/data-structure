#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int bin_search(int data[50],int val);
int main(void)
{  
	int num,val=1,data[50]={0};
	for (int i=0;i<50;i++)
	{  
		data[i]=val;
		val+=(rand()%5+1);
	}
	while (1)
	{  
		num=0;
		cout<<"��������Ҽ�ֵ(1-150)������-1������";
		cin>>val;
		if(val==-1)
			break;
		num=bin_search(data,val);
		if(num==-1)
			cout<<"##### û���ҵ�["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"�ڵ� "<<setw(2)<<num+1<<"��λ���ҵ� ["<<setw(3)<<data[num]<<"]"<<endl;
	}
	cout<<"�������ݣ�"<<endl;
	for(int i=0;i<5;i++)
	{ 
		for(int j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}
int bin_search(int data[50],int val)
{  
	int low,mid,high;
	low=0;
	high=49;
	cout<<"���ҹ�����......"<<endl;
	while(low <= high && val !=-1)
	{  
		mid=(low+high)/2;
		if(val<data[mid])
		{  
			cout<<val<<" ����λ�� "<<low+1<<"["<<setw(3)<<data[low]<<"]���м�ֵ "<<mid+1<<"["<<setw(3)<<data[mid]<<"]��������"<<endl;
			high=mid-1;	     
		}
		else if(val>data[mid])
		{  
			cout<<val<<" �����м�ֵλ�� "<<mid+1<<"["<<setw(3)<<data[mid]<<"]��"<<high+1<<"["<<setw(3)<<data[high]<<"]�����Ұ��"<<endl;			
   			low=mid+1;   	     
		}
		else
			return mid;
	}
	return -1;
}
