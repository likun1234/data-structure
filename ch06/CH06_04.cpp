#include <iostream>
using namespace std;
class list
{  
	public:
	int val;
    class list *next;
};
typedef class list node;
typedef node *link;
class list* head[9];
void dfs(int);
int run[9];
int main(void)
{  
	link ptr,newnode;
	int data[20][2]={{1,2},{2,1},{1,3},{3,1},//声明存放图的边的数组
					{2,4},{4,2},{2,5},{5,2},
					{3,6},{6,3},{3,7},{7,3},
					{4,5},{5,4},{6,7},{7,6},
					{5,8},{8,5},{6,8},{8,6}};
	for (int i=1;i<=8;i++)//共有八个顶点
	{  
		run[i]=0;         //设置所有顶点成尚未遍历过
		head[i]= new node;   
		head[i]->val=i;    //设置各个链表头的初值
		head[i]->next=NULL;
		ptr=head[i];      //设置指针为链表头
		for(int j=0;j<20;j++) //二十条边
		{  
			if(data[j][0]==i) //如果起点和链表头相等，则把顶点加入链表
			{  
				newnode =new node;
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;//加入新节点
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		} 
	}
	cout<<"图的邻接表内容："<<endl;//打印图的邻接表内容
	for(int i=1;i<=8;i++)
	{
		ptr=head[i];
		cout<<"顶点 "<<i<<"=> ";
		ptr = ptr->next;
		while(ptr!=NULL)
		{
			cout<<"["<<ptr->val<<"] ";
			ptr=ptr->next;
		}
		cout<<endl;
	}

	cout<<"深度优先遍历顶点："<<endl;//打印深度优先遍历的顶点
	dfs(1);
	cout<<endl;
	system("pause");
}
void dfs(int current) //深度优先遍历子程序
{  
	link ptr;
	run[current]=1;
	cout<<"["<<current<<"] ";
	ptr=head[current]->next;
	while(ptr!=NULL)
	{		
		if (run[ptr->val]==0) //如果顶点尚未遍历，
			dfs(ptr->val);   //就进行dfs的递归调用
		ptr=ptr->next;
	}
}
