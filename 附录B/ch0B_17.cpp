/*
	范例:ch0B_17.cpp
	说明:模板声明 
*/ 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
template <class T>//模板声明 
void Swap(T* a,T* b);//将原本数据类型改为模板的T类型 
template <class T>	//模板声明
void push(T stack[],int MAX,int val);
template <class T>  //模板声明
T pop(T stack[]);
int top=-1;

int main(void)
{  
	int card[52],stack[52]={0};
	char suit[4][10]={"草花","方块","红桃","黑桃"};
	int style, ascVal;
	srand(time(NULL));
	for (int i=0;i<52;i++)
		card[i]=i+1;
	cout<<"[洗牌中...请稍后!]"<<endl;
	int k=0; 
 	while(k<30)
	{
		for(int i=0;i<51;i++)
			for(int j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);//洗牌
		k++;
	}
	int m=0;
	while(m!=52)
	{
		push(stack,52,card[m]);//将52张牌压入堆栈
		m++;
	}
	cout<<"[逆时针发牌]"<<endl;
	cout<<"[显示各家的牌]"<<endl;
 	cout<<" 东家\t 北家\t 西家\t 南家"<<endl;
	cout<<"================================="<<endl;
	while (top >=0)
	{  
		style = stack[top]/13;	//计算牌的花色
		switch(style)			//牌子花色对应
		{
			case 0:				//梅花
				ascVal=0;
				break;
			case 1:				//方块
				ascVal=1;
				break;
			case 2:				//红心
				ascVal=2;
				break;
			case 3:				//黑桃
				ascVal=3;
				break;
		}
		cout<<"["<<suit[ascVal]<<setw(3)<<stack[top]%13+1<<"]\t";
		if(top%4==0)
			cout<<endl;
		top--;
	}
	system("pause");
	return 0;
}
template <class T>
void push(T stack[],int MAX,int val)
{
	if(top>=MAX-1)
		cout<<"[堆栈已经满了]"<<endl;
	else
	{
		top++;
		stack[top]=val;
	}
}
template <class T>
T pop(T stack[])
{
	if(top<0)
		cout<<"[堆栈已经空了]"<<endl;
	else
		top--;
	return stack[top];
}
template <class T>
void Swap(T* a,T* b)
{
	T temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
