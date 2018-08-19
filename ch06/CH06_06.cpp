/*
[ʾ��]:��С�ɱ�������
*/
#include <iostream>
#define VERTS	6 	//ͼ�Ķ�����
using namespace std;
class edge        //�����ߵĽṹ
{  
	public:
	int from,to;
	int find,val;
	class edge* next;
};
typedef class edge node;
typedef node* mst;
void mintree(mst head);
mst findmincost(mst head);    
int v[VERTS+1];
int main(void)
{  
	int data[10][3]={{1,2,6},{1,6,12},
                     {1,5,10},{2,3,3},//�ɱ�������
                     {2,4,5},{2,6,8},{3,4,7},{4,6,11},
					 {4,5,9},{5,6,16}};
	mst head,ptr,newnode;
	head=NULL;
	cout<<"����ͼ������"<<endl;
	for(int i=0;i<10;i++)//����ͼ������
	{  
		for(int j=1;j<=VERTS;j++)
		{  
			if(data[i][0]==j)
			{  
				newnode = new node;
				newnode->from=data[i][0];
				newnode->to=data[i][1];
				newnode->val=data[i][2];
				newnode->find=0;
				newnode->next=NULL;
				if(head==NULL)
				{  
					head=newnode;
					head->next=NULL;
					ptr=head;
				}   
				else
				{  
					ptr->next=newnode;
					ptr=ptr->next;
				}
			}
		}
	}
	ptr=head;
	while(ptr!=NULL)//��ӡͼ������
	{  
		cout<<"��ʼ���� ["<<ptr->from<<"]\t��ֹ���� ["
        <<ptr->to<<"]\t·������ ["<<ptr->val<<"]";
		cout<<endl;
		ptr=ptr->next;
	}
	cout<<"������С�ɱ���������"<<endl;
	mintree(head); //������С�ɱ�������
	delete newnode;
	system("pause");
}
mst findmincost(mst head)//�����ɱ���С�ı�
{
	int minval=100;
	mst ptr,retptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->val<minval && ptr->find==0)
		{   //����ptr->val��ֵС��minval
			minval=ptr->val; //�Ͱ�ptr->val������Сֵ
			retptr=ptr;//���Ұ�ptr��¼����
		}
		ptr=ptr->next;
	}
	retptr->find=1;    //��retptr��Ϊ���ҵ��ı�
	return retptr;     //����retptr
}
void mintree(mst head) //��С�ɱ��������ӳ���
{
	mst ptr,mceptr;
	int result=0;
	ptr=head;

	for(int i=0;i<=VERTS;i++)
		v[i]=0;

	while(ptr!=NULL)
	{
		mceptr=findmincost(head);
		v[mceptr->from]++;
		v[mceptr->to]++;
		if(v[mceptr->from]>1 && v[mceptr->to]>1)
		{
			v[mceptr->from]--;
			v[mceptr->to]--;
			result=1;
		}
		else
			result=0;
		if(result==0)
			cout<<"��ʼ���� ["<<mceptr->from
            <<"]\t��ֹ���� ["<<mceptr->to<<"]\t·������ ["
            <<mceptr->val<<"]"<<endl;
		ptr=ptr->next;
	}
}
