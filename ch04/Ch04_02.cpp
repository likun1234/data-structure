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
	char suit[4][10]={"�ݻ�","����","����","����"};
	int style;
	srand((unsigned)time(NULL));
	for (i=0;i<52;i++)
		card[i]=i+1;
	cout<<"[ϴ����...���Ժ�!]"<<endl;
	while(k<30)
	{
		for(i=0;i<51;i++)
			for(j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);//ϴ��
		k++;
	}
	i=0;
	while(i!=52)
	{
		push(stack,52,card[i]);//��52����ѹ���ջ
		i++;
	}
	cout<<"[��ʱ�뷢��]"<<endl;
	cout<<"[��ʾ�����õ�����]"<<endl;
 	cout<<"\t\t����\t ����\t ����\t �ϼ�"<<endl;
	cout<<"========================================================="<<endl;
	while (top >=0)
	{  
		style = stack[top]/13;	//�����˿��ƵĻ�ɫ
		switch(style)			//�˿��ƻ�ɫ��Ӧ��ͼ��
		{
			case 0:			//÷��
				ascVal=0;
				break;
			case 1:			//����
				ascVal=1;
				break;
			case 2:			//����
				ascVal=2;
				break;
			case 3:			//����
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
		cout<<"[��ջ�Ѿ�����]"<<endl;
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	if(top<0)
		cout<<"[��ջ�Ѿ�����]"<<endl;
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
