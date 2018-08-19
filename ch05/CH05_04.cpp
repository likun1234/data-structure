#include <iostream>
#include<stdlib.h>
using namespace std;

struct tree
{  int data;
   struct tree *left,*right;
};

typedef struct tree node;
typedef node *btree;

btree creat_tree(btree root,int val)
{  
	btree newnode,current,backup;
	newnode=(btree)malloc(sizeof(node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{  
		root=newnode;
		return root;
	}
	else
	{  
		for(current=root;current!=NULL;)
		{  
			backup=current;
			if(current->data > val)
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}
btree search(btree ptr,int val)     //查找二叉树子程序
{  
	int i=1;                     //判断执行次数的变量
	while(1)
	{  
		if(ptr==NULL)            //没找到就返回NULL
			return NULL;
		if(ptr->data==val)       //节点值等于查找值
		{  
			cout<<"共查找 "<<i<<"次"<<endl;
			return ptr;
		}
		else if(ptr->data > val)  //节点值大于查找值
			ptr=ptr->left;
		else
			ptr=ptr->right;
		i++;
	}   
}

int main()
{  
	int i,data,arr[]={7,1,4,2,8,13,12,11,15,9,5};
	btree ptr=NULL;
	cout<<"[原始数组内容]"<<endl;
	for (i=0;i<11;i++)              
	{  
		ptr=creat_tree(ptr,arr[i]);  //建立二叉树
		cout<<"["<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"请输入查找值："<<endl;
	cin>>data;
	if((search(ptr,data)) !=NULL)        //查找二叉树
		cout<<"你要找的值 ["<<data<<" ] 有找到!!"<<endl;
	else
		cout<<"您要找的值没找到!!"<<endl;
	
    system("pause");
	return 0;
}
