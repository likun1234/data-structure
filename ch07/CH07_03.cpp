#include <iostream>
#include <iomanip>
using namespace std;

void select (int *); //声明排序法子程序
void showdata (int *);//声明打印数组子程序
int main(void)
{
	int data[6]={9,7,5,3,4,6};
	cout<<"原始数据为：";
	showdata(data);
	select(data);
	system("pause");
	return 0;
}
void showdata (int data[])
{
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}

void select (int data[])
{
	for(int i=0;i<5;i++)    //扫描5次
	{   
		for(int j=i+1;j<6;j++)  //从i+1比较起，比较5次
		{	
			if(data[i]>data[j])  //比较第i和第j个元素
			{	
				int tmp;
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;	
			}
		}
		cout<<"第 "<<i+1<<" 次排序结果：";
	    for (int k=0;k<6;k++)
			cout<<setw(3)<<data[k];    //打印排序结果
	    cout<<endl;
	}
	cout<<endl;
}
