/*
[����]:ch03_08.cpp
[ʾ��]:��������ڵ�Ĵ�������� 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h> 
#include <iomanip>
using namespace std;
class list
{   
    public:
	int num,score;
	char name[10];
	class list *next;
};
typedef struct list node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr!=NULL)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     return ptr;
}

link insertnode(link head,link after,int num,int score,char name[10])   
{  
    link InsertNode;
    InsertNode=new node;
    link CurNode=NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if(InsertNode==NULL)
    {
       cout<<"�ڴ����ʧ��"<<endl;
       return NULL;
    }
    else
    {
        if(head==NULL)	//�����ǿյ�
        {
           head=InsertNode;
           InsertNode->next=head;
           return head;
        }              
        else
        {
            if(after==NULL)	//�����ڵ㵽����ͷ����λ��
            {
               //(1)�������ڵ��ָ��ָ������ͷ��
               InsertNode->next=head;
               CurNode=head;
               while(CurNode->next!=head)
                  CurNode=CurNode->next;
               //(2)�ҵ�����β����������ָ��ָ�������ڵ�
               CurNode->next=InsertNode;
               //(3)������ͷָ���������ڵ�
               head=InsertNode;
               return head;
            }
            else //�����ڵ㵽����ͷ������ĵط�
            {
               //(1)�������ڵ��ָ��ָ��after����һ���ڵ�
               InsertNode->next=after->next;
               //(2)���ڵ�after��ָ��ָ�������ڵ�
               after->next=InsertNode;
               return head; 
            }
        } 
    }
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"}
    ,{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"}
    ,{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	srand((unsigned)time(NULL));
	cout<<"����  �ɼ�  ����  �ɼ�  ����  �ɼ�  ����  �ɼ�"<<endl;
	cout<<"=============================================="<<endl;
	for(i=0;i<12;i++)
	{  
		data[i][0]=i+1;
		data[i][1]=rand()%50+51;
	}
	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			cout<<"["<<data[j*3+i][0]<<"] ["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	head=new node;  //���������ͷָ��
	if(!head)
	{  
		cout<<"Error!! �ڴ����ʧ��!!"<<endl;
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)  //��������
	{  
		newnode=new node;
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;//��ǰһ���ڵ�ָ���´����Ľڵ�
		ptr=newnode; //�½ڵ��Ϊǰһ���ڵ�
	}
	newnode->next=head;//�����һ���ڵ�ָ��ͷ���ڵ�ͳ��˻�������
	while(1)
	{  
		cout<<"������Ҫ��������ѧ����ţ���������-1��";
		cin>>position;
		if(position==-1)    /*ѭ���ж�����*/
			break;
		else
		{  
			ptr=findnode(head,position);
		  	cout<<"�������²����ѧ����ţ�";
			cin>>new_num;
			cout<<"�������²����ѧ���ɼ���";
			cin>>new_score;
			cout<<"�������²����ѧ��������";
			cin>>new_name;
			head=insertnode(head,ptr,new_num,new_score,new_name);
		}
	}
	ptr=head;//ָ������Ŀ�ͷ
	cout<<"\n\t����\t    ����\t�ɼ�\n";      
	cout<<"\t==============================\n";
	do
	{
	    cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]\n";
		ptr=ptr->next;//ָ����һ���ڵ�
    } while(head!=ptr && head!=head->next);
    delete newnode;
	system("pause");
	return 0;
}
