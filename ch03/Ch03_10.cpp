/*
[����]:ch03_10.cpp
[ʾ��]:������ѧ���ɼ��Ļ�����������������
       Ȼ���ӡ�����Ӻ����������
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
class list
{
	public:
 	int num,score;
	char name[10];
	class list *next;
};
typedef class list node;
typedef node *link;
link creat_link(int data[10][2],int num);
void print_link(link head);
link concat(link ptr1,link ptr2);
int main()
{  
	link ptr1,ptr2,ptr;
	int i,data1[6][2],data2[6][2];
	srand(time(NULL));
	for (i=1;i<=6;i++)
	{  
		data1[i-1][0]=i*2-1;
		data1[i-1][1]=rand()%49+52;
		data2[i-1][0]=i*2;
		data2[i-1][1]=rand()%49+52;
	}
	ptr1=creat_link(data1,6);//��������1
	ptr2=creat_link(data2,6);//��������2
	i=0;
	cout<<"\t\t       ԭ �� �� �� �ݣ�"<<endl;
	cout<<"\t    ���� �ɼ�   ���� �ɼ�   ���� �ɼ�"<<endl;
	cout<<"\t    =================================="<<endl;
	cout<<"��������1 ��";
	print_link(ptr1);
	cout<<"��������2 ��";
	print_link(ptr2);
	cout<<"\t    =================================="<<endl;
	cout<<"���Ӻ������";
	ptr=concat(ptr1,ptr2);			//���ӻ�������
	print_link(ptr);
	system("pause");
}
link creat_link(int data[10][2],int num) //���������ӳ���
{  
	link head,ptr,newnode;
	for(int i=0;i<num;i++)
	{  
		newnode=new node;
		if(!newnode)
		{  
			cout<<"Error!! �ڴ����ʧ��!!"<<endl;
			exit(i);
		}
		if(i==0)//��������ͷ��
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else //�������������ڵ�
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
		newnode->next=head;
	}
	return ptr;//��������
}
void print_link(link head)//��ӡ�����ӳ���
{  
	link ptr;
	int i=0;
	ptr=head->next;
	do 
	{  
		cout<<"["<<setw(2)<<ptr->num<<"-"<<setw(3)
            <<ptr->score<<"] -> ";
		i++;
		if(i>=3)//ÿ�д�ӡ����Ԫ��
		{  
			cout<<"\n\t    ";
			i=0;
		}
		ptr=ptr->next;
	}while(ptr!=head->next);
	cout<<endl;
}
link concat(link ptr1,link ptr2)		//���������ӳ���
{  
	link head;
	head=ptr1->next;		//��ptr1��ptr2�У���������һ���ڵ�
	ptr1->next=ptr2->next;	//�������ڵ��next�Ե�����
	ptr2->next=head;
	return ptr2;
}
