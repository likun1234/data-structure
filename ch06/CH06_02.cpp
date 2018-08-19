/*
[示范]:使用相邻矩阵来表示有向图
*/
#include <iostream>
using namespace std;
int  main(void)
{  
	int arr[5][5],i,j; //声明矩阵arr
	int data[5][2]={{1,2},{2,1},{2,3},{2,4},{4,3}};//图形各边的起点值和终点值
	for (i=0;i<5;i++)//把矩阵清为0
		for (j=0;j<5;j++)
			arr[i][j]=0;
	for (i=0;i<5;i++) //读取图形数据
		for (j=0;j<5;j++) //填入arr矩阵
		{  
			int tmpi,tmpj;
			tmpi=data[i][0];//tmpi为起始顶点
			tmpj=data[i][1];//tmpj为终止顶点
			arr[tmpi][tmpj]=1;//有边的点填入1
		}
	cout<<"有向图矩阵："<<endl;
	for (i=1;i<5;i++)
	{  
		for (j=1;j<5;j++)
	    cout<<"["<<arr[i][j]<<"] ";//打印矩阵内容
		cout<<endl;
	}
	system("pause");
}
