#include <iostream>
#include <iomanip>
using namespace std;
class tree //�ڵ�����ṹ������
{  
	public :
	int data; //�ڵ�����
	class tree *left,*right; //�ڵ���ָ�����ָ�� 
};
typedef class tree node;
typedef node *btree;
btree creat_tree(btree,int);
void pre(btree);
void in(btree);
void post(btree);
int main(void)
{  
	int arr[]={7,4,1,5,16,8,11,12,15,9,2};//ԭʼ�������� 
	btree ptr=NULL; //�������� 
	cout<<"[ԭʼ��������]"<<endl;
	for (int i=0;i<11;i++)//�������������������������ݴ�ӡ���� 
	{  
		ptr=creat_tree(ptr,arr[i]);
		cout<<"["<<setw(2)<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"[������������]"<<endl;
	cout<<"ǰ����������"<<endl;//��ӡǰ���С����������� 
	pre(ptr);
	cout<<endl;
	cout<<"������������"<<endl;
	in(ptr);
	cout<<endl;
	cout<<"������������"<<endl;
	post(ptr);
	cout<<endl;
	system("pause");
	return 0;
}
btree creat_tree(btree root,int val)//�������������ӳ��� 
{  
	btree newnode,current,backup;   //����һ���½ڵ�newnode����������� 
	newnode = new node; //current��backup����ݴ�ָ�� 
	newnode->data=val;  //ָ���½ڵ�����ݺ�����ָ�� 
	newnode->left=NULL;
	newnode->right=NULL;
	if (root==NULL)//���rootΪ��ֵ�����½ڵ㷵�ص������� 
	{  
		root=newnode;
		return root;
	}
	else //��root�������������������� 
	{  
		for(current=root;current!=NULL;) //current����root���Ա�����ǰ������ֵ 
		{  
			backup=current; //�������ڵ� 
			if(current->data > val)//�Ƚ������ڵ���½ڵ����� 
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)//���½ڵ�������������� 
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root; //������ָ�� 
}
void pre(btree ptr) //ǰ����� 
{  
	if (ptr != NULL)
	{  
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		pre(ptr->left);
		pre(ptr->right);
	}
}
void in(btree ptr) //������� 
{  
	if (ptr != NULL)
	{  
		in(ptr->left);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		in(ptr->right);
	}
}
void post(btree ptr)//�������
{  
	if (ptr != NULL)
	{  
		post(ptr->left);
		post(ptr->right);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
	}
}
