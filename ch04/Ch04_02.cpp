#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
void Swap(int*,int*);
void push(int statck[],int MAX,int val);
int pop(int stack[]);
int top=-1;
int main(void)
{  
	int card[52],stack[52]={0};
	int i,j,k=0, ascVal;
	char suit[4][10]={"草花","方块","红桃","黑桃"};
	int style;
	srand((unsigned)time(NULL));
	for (i=0;i<52;i++)
		card[i]=i+1;
	cout<<"[洗牌中...请稍后!]"<<endl;
	while(k<30)
	{
		for(i=0;i<51;i++)
			for(j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);//洗牌
		k++;
	}
	i=0;
	while(i!=52)
	{
		push(stack,52,card[i]);//将52张牌压入堆栈
		i++;
	}
	cout<<"[逆时针发牌]"<<endl;
	cout<<"[显示各家拿到的牌]"<<endl;
 	cout<<"\t\t东家\t 北家\t 西家\t 南家"<<endl;
	cout<<"========================================================="<<endl;
	while (top >=0)
	{  
		style = stack[top]/13;	//计算扑克牌的花色
		switch(style)			//扑克牌花色对应的图标
		{
			case 0:			//梅花
				ascVal=0;
				break;
			case 1:			//方块
				ascVal=1;
				break;
			case 2:			//红心
				ascVal=2;
				break;
			case 3:			//黑桃
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
void push(int stack[],int MAX,int val)
{
	if(top>=MAX-1)
		cout<<"[堆栈已经满了]"<<endl;
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	if(top<0)
		cout<<"[堆栈已经空了]"<<endl;
	else
		top--;
	return stack[top];
}
void Swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
