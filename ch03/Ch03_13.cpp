/*
[����]:ch03_13.cpp
[ʾ��]:����ʽ���
*/
#include <iostream>
using namespace std;
class list //��������ṹ
{  
	public :
	int coef,exp;
	class list *next;
};
typedef class list node;
typedef node *link;
link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a,link b);
int main()
{  
	link a,b,c;
	int data1[4]={3,0,4,2}; //����ʽA��ϵ��
	int data2[4]={6,8,6,9}; //����ʽB��ϵ��
	cout<<"ԭʼ����ʽ��"<<endl<<"A=";
	a=creat_link(data1);    //��������ʽA
	b=creat_link(data2);    //��������ʽB
	print_link(a);          //��ӡ����ʽA
	cout<<"B=";
	print_link(b);          //��ӡ����ʽB
	cout<<"����ʽ��ӵĽ����\nC=";
	c=sum_link(a,b);        //CΪA��B����ʽ��ӵĽ��
	print_link(c);          //��ӡ����ʽC
	system("pause");
}
link creat_link(int data[4])//��������ʽ�ӳ���
{
	link head,newnode,ptr;
	for(int i=0;i<4;i++)
	{  
		newnode = new node;
		if(!newnode)
		{  
			cout<<"Error!! �ڴ����ʧ��!!"<<endl;
			exit(1);
		}
		if(i==0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else if(data[i]!=0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
	}
	return head;
}
void print_link(link head) //��ӡ����ʽ�ӳ���
{  
	while(head!=NULL) 
	{  
		if(head->exp==1 && head->coef!=0)	//X^1ʱ����ʾָ��
			cout<<head->coef<<"X + ";
		else if(head->exp!=0 && head->coef!=0)
			cout<<head->coef<<"X^"<<head->exp<<" + ";
		else if(head->coef!=0)           	//X^0ʱ����ʾ����
			cout<<head->coef;
		head=head->next;
	}
	cout<<endl;
}
link sum_link(link a,link b) //����ʽ����ӳ���
{  
	int sum[4],i=0;
	link ptr;
	ptr=b;
	while(a!=NULL) //�ж϶���ʽ1
	{  
		b=ptr; 	//�ظ��Ƚ�A��B��ָ��
		while(b!=NULL)
		{  
			if(a->exp==b->exp)	//ָ����ȣ�ϵ�����
			{  
				sum[i]=a->coef+b->coef;
				a=a->next;
				b=b->next;
				i++;
			}
			else if(b->exp > a->exp)	//Bָ���ϴ�ָ��ϵ����C
			{  
				sum[i]=b->coef;
				b=b->next;
				i++;
			}
			else if(a->exp > b->exp)	//Aָ���ϴ�ָ��ϵ����C
			{  
				sum[i]=a->coef;
				a=a->next;
				i++;
			}
		}
	}
	return creat_link(sum);	//������ӽ��������C
}
