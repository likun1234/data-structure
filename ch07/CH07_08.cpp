/*
[示范]:基数排序法
*/
// 基数排序法 从小到大排序 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void radix (int *,int);		// 基数排序法子程序 
void showdata (int *,int);
void inputarr (int *,int);
int main(void)
{ 
	int size,data[100]={0};
	cout<<"请输入数组大小(100以下)：";
	cin>>size;
	cout<<"生成的随机数据是："<<endl;
	inputarr (data,size);
	showdata (data,size);
	radix (data,size);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	srand(time(NULL));
	for (int i=0;i<size;i++)
		data[i]=(rand()%999)+1;		// 设置data 值最大为 3 位数 
}
void showdata(int data[],int size)
{  
	for (int i=0;i<size;i++)
		cout<<setw(5)<<data[i];
	cout<<endl;
}
void radix(int data[],int size)
{  
	for (int n=1;n<=100;n=n*10)	// n为基数，从个位数开始排序 
	{  
		int tmp[10][100]={0};	// 设置暂存数组，[0~9位数][数据个数]，所有内容均为0 
		for (int i=0;i<size;i++)	// 对比所有数据 
		{  
			int m=(data[i]/n)%10;	// m为n位数的值，如 36取十位数 (36/10)%10=3 
			tmp[m][i]=data[i];		// 把data[i]的值暂存于tmp 里 
		}
		int k=0;
		for (int i=0;i<10;i++)
		{  
			for(int j=0;j<size;j++)
			{  
				if(tmp[i][j] != 0)		// 因一开始设置 tmp ={0}，故不为0者即为 
				{  
					data[k]=tmp[i][j];	// data暂存在 tmp 里的值，把tmp 里的值放
					k++;		        // 回data[ ]里 
				}
			}
		}
		cout<<"经过"<<setw(3)<<n<<"位数排序后：";
		showdata(data,size);
	} 
}
