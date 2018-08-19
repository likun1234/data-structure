/*
[示范]:使用邻接表来表示图形(a)和(b)
*/
#include <iostream>
using namespace std;
class list
{
	public:
	int val;
	class list *next;
};
class list head[6];//声明一个节点类型的数组
int main(void)
{  
	list *ptr,*newnode;
 	int data[14][2]={{1,2},{2,1},{1,5},{5,1},//声明存储图的数组
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	cout<<"图(a)的邻接表内容："<<endl;
	for (int i=1;i<6;i++)
	{  
		head[i].val=i; //链表头head
		head[i].next=NULL;
		cout<<"顶点 "<<i<<" =>";	//把顶点值打印出来
		ptr=&(head[i]);          	//暂存节点ptr
		for (int j=0;j<14;j++)      //遍历图数组
		{  
			if (data[j][0]==i)    	//如果节点值=i，加入节点到链表头
			{  
				newnode = new list;
    			newnode->val=data[j][1];//声明新节点，值为终点值
				newnode->next=NULL;
				while(ptr!=NULL)        //判断是否为链表的末尾
					ptr=ptr->next;
				ptr=newnode;            //加入新节点
				cout<<"["<<newnode->val<<"] ";//打印相邻顶点
			}
		}   
		cout<<endl;
	}
	system("pause");
}
