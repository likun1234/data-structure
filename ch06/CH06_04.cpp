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
	int data[20][2]={{1,2},{2,1},{1,3},{3,1},//�������ͼ�ıߵ�����
					{2,4},{4,2},{2,5},{5,2},
					{3,6},{6,3},{3,7},{7,3},
					{4,5},{5,4},{6,7},{7,6},
					{5,8},{8,5},{6,8},{8,6}};
	for (int i=1;i<=8;i++)//���а˸�����
	{  
		run[i]=0;         //�������ж������δ������
		head[i]= new node;   
		head[i]->val=i;    //���ø�������ͷ�ĳ�ֵ
		head[i]->next=NULL;
		ptr=head[i];      //����ָ��Ϊ����ͷ
		for(int j=0;j<20;j++) //��ʮ����
		{  
			if(data[j][0]==i) //�����������ͷ��ȣ���Ѷ����������
			{  
				newnode =new node;
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;//�����½ڵ�
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		} 
	}
	cout<<"ͼ���ڽӱ����ݣ�"<<endl;//��ӡͼ���ڽӱ�����
	for(int i=1;i<=8;i++)
	{
		ptr=head[i];
		cout<<"���� "<<i<<"=> ";
		ptr = ptr->next;
		while(ptr!=NULL)
		{
			cout<<"["<<ptr->val<<"] ";
			ptr=ptr->next;
		}
		cout<<endl;
	}

	cout<<"������ȱ������㣺"<<endl;//��ӡ������ȱ����Ķ���
	dfs(1);
	cout<<endl;
	system("pause");
}
void dfs(int current) //������ȱ����ӳ���
{  
	link ptr;
	run[current]=1;
	cout<<"["<<current<<"] ";
	ptr=head[current]->next;
	while(ptr!=NULL)
	{		
		if (run[ptr->val]==0) //���������δ������
			dfs(ptr->val);   //�ͽ���dfs�ĵݹ����
		ptr=ptr->next;
	}
}
