/*
[ʾ��]��ʵ�ֻ�״�������ݵĽ��Ӻͳ���
*/
#include <iostream>
using namespace std;
int main(void)
{  
	int front,rear,val=0,queue[5]={0};
	front=rear=-1;
	while(rear<5&&val!=-1)
	{  
	    cout<<"������һ��ֵ�Դ�����У���ȡ��ֵ������-2��(��������-1)��";
		cin>>val;
		if(val==-2)
		{  
			if(front==rear)
			{  
				cout<<"[�����Ѿ�����]"<<endl;
				break;
			}
			front++;
			if (front==5)
				front=0;
			cout<<"ȡ������ֵ ["<<queue[front]<<"]"<<endl;
			queue[front]=0;
		}
		else if(val!=-1 && rear<5)
		{  
			if(rear+1==front || rear==4 && front<=0)
			{  
				cout<<"[�����Ѿ�����]"<<endl;
				break;
			}
			rear++;
			if(rear==5)
				rear=0;
			queue[rear]=val;
		}
	}
	cout<<"\n����ʣ�����ݣ�"<<endl;
	if (front==rear)
		cout<<"�����ѿ�!!"<<endl;
	else 
	{ 
		while(front!=rear)
		{  
			front++;
			if (front==5)
				front=0;
			cout<<"["<<queue[front]<<"]";
			queue[front]=0;
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}
