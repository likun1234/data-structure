#include <iostream>
#include <iomanip>
using namespace std;
void bubble (int *);   //声明冒泡排序子程序
void showdata (int *); //声明打印数组子程序
int main(void)
{
	int data[6]={4,6,2,7,8,9};	  //原始数据
	cout<<"改进冒泡排序法\n原始数据为：\t";
	showdata(data);
	bubble(data);
	system("pause");
	return 0;
}
void showdata (int data[])     //利用循环打印数据
{
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void bubble (int data[])
{
	for(int i=5;i>=0;i--)
	{
		int flag=0;           //flag用来判断是否执行了互换的操作
		for (int j=0;j<i;j++)
		{
			if (data[j+1]<data[j])
			{
				int tmp;
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;    //如果执行过互换，则flag不为0
			}
		}
		if (flag==0)
			break;
		/*
		当执行完一次扫描就判断是否执行过互换的操作，如果没有互换过数据，
        则表示此时数组已完成排序，故可直接跳出循环
		*/
		cout<<"第 "<<6-i<<" 次排序：\t";
		for (int j=0;j<6;j++)
			cout<<setw(3)<<data[j];
		cout<<endl;		    
	}
	cout<<"排序后结果为：\t";
	showdata (data);
}
