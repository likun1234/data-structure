#include <iostream>
#include <stdlib.h>
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

	while(1)
	{  
		if(ptr==NULL)			//没找到就返回NULL               
			return NULL;
		if(ptr->data==val)		//节点值等于查找值
			return ptr;
		else if(ptr->data > val)	//节点值大于查找值
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}   
}
void inorder(btree ptr)			//中序遍历子程序
{  
  if(ptr!=NULL)
     {  
      inorder(ptr->left);
      cout<<"["<<ptr->data<<"]";
      inorder(ptr->right);
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
	cout<<"请输入查找键值："<<endl;
	cin>>data;
	if((search(ptr,data))!=NULL)        //查找二叉树
		cout<<"二叉树中有此节点了!-"<<data<<endl;
	else
     {
      ptr=creat_tree(ptr,data);  
      inorder(ptr);
      }
	
    system("pause");
	return 0;
}
