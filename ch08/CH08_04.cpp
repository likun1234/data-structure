#include <iostream>
#include <cstdlib>
#include <iomanip>
#define MAX 20
using namespace std;
int fib(int n)
{
    if(n==1 || n==0)
        return n;
    else
        return fib(n-1)+fib(n-2);
}
int fib_search(int data[MAX],int SearchKey)
{
    int index=2; 
    //斐波拉契数列的查找
    while(fib(index)<=MAX)
        index++;
    index--;
    //index >=2
    //起始的斐波拉契数
    int RootNode=fib(index);
    //上一个斐波拉契数
    int diff1=fib(index-1); 
    //上两个斐波拉契数即diff2=fib(index-2)
    int diff2=RootNode-diff1;
    RootNode--;	//这个表达式是配合数组的下标是从0开始储存数据
    while(1)
    {
       if(SearchKey==data[RootNode])
       {
          return RootNode;
       }
       else
       {
           if(index==2) return MAX; //没有找到
           if(SearchKey<data[RootNode])
           {
              RootNode=RootNode-diff2;//左子树的新斐波拉契数
              int temp=diff1;
              diff1=diff2;//上一个斐波拉契数
              diff2=temp-diff2;//上两个斐波拉契数
              index=index-1;
           }
           else
           {
              if(index==3) return MAX;
              RootNode=RootNode+diff2;//右子树的新斐波拉契数 
              diff1=diff1-diff2;//上一个斐波拉契数
              diff2=diff2-diff1;//上两个斐波拉契数
              index=index-2;
           }         
       }
    }
}
int main(void)
{  
	int data[]={5,7,12,23,25,37,48,54,68,77,
                91,99,102,110,118,120,130,135,136,150};
    int val;
    int i=0;
    int j=0;
	while(1)
	{  
		cout<<"请输入查找键值(1-150)，输入-1结束：";
		cin>>val;//输入查找的数值
		if(val==-1)//输入值为-1就跳离循环
			break;
		int RootNode=fib_search(data,val);//使用斐波拉契搜查找法查找数据
		if(RootNode==MAX)
			cout<<"##### 没有找到["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"在第 "<<setw(2)<<RootNode+1
            <<"个位置找到 ["<<setw(3)<<data[RootNode]<<"]"<<endl;
	}
	cout<<"数据内容："<<endl;
	for(i=0;i<2;i++)
	{ 
		for(j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	system("pause");
	return 0;
}
