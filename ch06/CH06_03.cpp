/*
[ʾ��]:ʹ���ڽӱ�����ʾͼ��(a)��(b)
*/
#include <iostream>
using namespace std;
class list
{
	public:
	int val;
	class list *next;
};
class list head[6];//����һ���ڵ����͵�����
int main(void)
{  
	list *ptr,*newnode;
 	int data[14][2]={{1,2},{2,1},{1,5},{5,1},//�����洢ͼ������
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	cout<<"ͼ(a)���ڽӱ����ݣ�"<<endl;
	for (int i=1;i<6;i++)
	{  
		head[i].val=i; //����ͷhead
		head[i].next=NULL;
		cout<<"���� "<<i<<" =>";	//�Ѷ���ֵ��ӡ����
		ptr=&(head[i]);          	//�ݴ�ڵ�ptr
		for (int j=0;j<14;j++)      //����ͼ����
		{  
			if (data[j][0]==i)    	//����ڵ�ֵ=i������ڵ㵽����ͷ
			{  
				newnode = new list;
    			newnode->val=data[j][1];//�����½ڵ㣬ֵΪ�յ�ֵ
				newnode->next=NULL;
				while(ptr!=NULL)        //�ж��Ƿ�Ϊ�����ĩβ
					ptr=ptr->next;
				ptr=newnode;            //�����½ڵ�
				cout<<"["<<newnode->val<<"] ";//��ӡ���ڶ���
			}
		}   
		cout<<endl;
	}
	system("pause");
}
