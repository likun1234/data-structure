/*
[示范]:实现队列数据的进队和出队
*/
#include <iostream>
using namespace std;
const int MAX=20;//定义队列的大小
int main(void)
{
	int front,rear,val,queue[MAX]={0};
	char ch;
	front=rear=-1;
	while(rear<MAX-1&&ch!='E')
	{  
		cout<<"[I]存入一个数值 [G]取出一个数值 [E]结束: ";
		cin>>ch;
		switch(ch)
		{
			case 'I':
				cout<<"[请输入数值]: ";
				cin>>val;
				rear++;
				queue[rear]=val;
				break;
			case 'G':
				if(rear>front)
				{  
					front++;
					cout<<"[取出数值为]: ["<<queue[front]<<"]";
					cout<<endl;
					queue[front]=0;
				}
				else
				{  
					cout<<"[队列已经空了]"<<endl;
					exit(0);
				}
				break;
			default:
				cout<<endl;
				break;
		}
	}
	if(rear==MAX-1) cout<<"[队列已经满了]"<<endl;
	cout<<"[目前队列中的数据]:";
	if (front>=rear)
	{
		cout<<"没有"<<endl;
		cout<<"[队列已经空了]"<<endl;
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
