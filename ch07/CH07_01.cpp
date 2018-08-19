#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
	int data[6]={6,5,9,7,2,8};	// 原始数据 
	cout<<"冒泡排序法：\n原始数据为：";
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;

	for (int i=5;i>0;i--)// 扫描次数 
	{
		for (int j=0;j<i;j++)//比较、互换次数
		{
			if (data[j]>data[j+1])// 比较相邻两数，如第一个数较大则互换 
			{
				int tmp;
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
		cout<<"第 "<<6-i<<" 次排序后的结果是："; //把各次扫描后的结果打印出来
		for (int j=0;j<6;j++)
			cout<<setw(3)<<data[j];
		cout<<endl;
	}
	cout<<"排序后结果为：";
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
	system("pause");
	return 0;
}
