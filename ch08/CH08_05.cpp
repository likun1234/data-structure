#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX = 10;   //哈希表的最大元素
const int MAXNUM = 7;    //最大数据个数
int print_data(int *,int);
int creat_table(int ,int *);

int main(void)
{  
	int i,index[INDEXBOX],data[MAXNUM];
	srand(time(NULL));     //按时间初始化随机数
	cout<<"原始数组值：\n";
	for(i=0;i<MAXNUM;i++)      //起始数据值
		data[i]=rand()%20+1;
	for(i=0;i<INDEXBOX;i++)     //清除哈希表
		index[i]=-1;
	print_data(data,MAXNUM);    //打印起始数据
	cout<<"哈希表内容："<<endl;
	for(i=0;i<MAXNUM;i++)       //建立哈希表
	{  
		creat_table(data[i],index);
		cout<<data[i]<<" =>";  //打印单一元素的哈希表位置
		print_data(index,INDEXBOX);
	}
	cout<<"完成哈希表："<<endl;     
	print_data(index,INDEXBOX);  //打印最后完成的结果
	system("pause");
	return 0;
}
int print_data(int *data,int max)  //打印数组子程序
{  
	cout<<"\t";
	for(int i=0;i<max;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
}
int creat_table(int num,int *index)  //建立哈希表子程序
{  
	int tmp;
	tmp=num%INDEXBOX;    //哈希函数=数据%INDEXBOX
	while(1)
	{  
		if(index[tmp]==-1)      //如果数据对应的位置是空的
		{  
			index[tmp]=num;     //则直接存入数据
			break;
		}
		else
			tmp=(tmp+1)%INDEXBOX;    //否则往后找位置存放
	}
}
