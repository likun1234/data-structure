/*
[ʾ��]:ʵ�ֶ������ݵĽ��Ӻͳ���
*/
#include <iostream>
using namespace std;
const int MAX=20;//������еĴ�С
int main(void)
{
	int front,rear,val,queue[MAX]={0};
	char ch;
	front=rear=-1;
	while(rear<MAX-1&&ch!='E')
	{  
		cout<<"[I]����һ����ֵ [G]ȡ��һ����ֵ [E]����: ";
		cin>>ch;
		switch(ch)
		{
			case 'I':
				cout<<"[��������ֵ]: ";
				cin>>val;
				rear++;
				queue[rear]=val;
				break;
			case 'G':
				if(rear>front)
				{  
					front++;
					cout<<"[ȡ����ֵΪ]: ["<<queue[front]<<"]";
					cout<<endl;
					queue[front]=0;
				}
				else
				{  
					cout<<"[�����Ѿ�����]"<<endl;
					exit(0);
				}
				break;
			default:
				cout<<endl;
				break;
		}
	}
	if(rear==MAX-1) cout<<"[�����Ѿ�����]"<<endl;
	cout<<"[Ŀǰ�����е�����]:";
	if (front>=rear)
	{
		cout<<"û��"<<endl;
		cout<<"[�����Ѿ�����]"<<endl;
	}
	else
	{
		while (rear>front)
		{  
			front++;
			cout<<"["<<queue[front]<<"]\t";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
