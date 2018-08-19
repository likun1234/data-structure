/*
	����:ch0B_17.cpp
	˵��:ģ������ 
*/ 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
template <class T>//ģ������ 
void Swap(T* a,T* b);//��ԭ���������͸�Ϊģ���T���� 
template <class T>	//ģ������
void push(T stack[],int MAX,int val);
template <class T>  //ģ������
T pop(T stack[]);
int top=-1;

int main(void)
{  
	int card[52],stack[52]={0};
	char suit[4][10]={"�ݻ�","����","����","����"};
	int style, ascVal;
	srand(time(NULL));
	for (int i=0;i<52;i++)
		card[i]=i+1;
	cout<<"[ϴ����...���Ժ�!]"<<endl;
	int k=0; 
 	while(k<30)
	{
		for(int i=0;i<51;i++)
			for(int j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);//ϴ��
		k++;
	}
	int m=0;
	while(m!=52)
	{
		push(stack,52,card[m]);//��52����ѹ���ջ
		m++;
	}
	cout<<"[��ʱ�뷢��]"<<endl;
	cout<<"[��ʾ���ҵ���]"<<endl;
 	cout<<" ����\t ����\t ����\t �ϼ�"<<endl;
	cout<<"================================="<<endl;
	while (top >=0)
	{  
		style = stack[top]/13;	//�����ƵĻ�ɫ
		switch(style)			//���ӻ�ɫ��Ӧ
		{
			case 0:				//÷��
				ascVal=0;
				break;
			case 1:				//����
				ascVal=1;
				break;
			case 2:				//����
				ascVal=2;
				break;
			case 3:				//����
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
		cout<<"[��ջ�Ѿ�����]"<<endl;
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
		cout<<"[��ջ�Ѿ�����]"<<endl;
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
