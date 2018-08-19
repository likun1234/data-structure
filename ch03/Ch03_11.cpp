/*
[����]:ch03_11.cpp
[ʾ��]:˫������ڵ�Ľ�������� 
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
	class list *llink;
	class list *rlink;
};
typedef class list node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr!=NULL)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->rlink;
     }
     return ptr;
}

link insertnode(link head,link ptr,int num,int score,char name[10])   
{  
    link newnode=(link)malloc(sizeof(node));
    link newhead=(link)malloc(sizeof(node));
    newnode=new node;
    //memset(newnode,0,sizeof(node));
    newnode->num=num;
    newnode->score=score;
    strcpy(newnode->name,name);
    if(head==NULL) /*˫�������ǿյ�*/
    {
       newnode=new node;
      // memset(newhead,0,sizeof(node));       
       newhead->num=num;
       newhead->score=score;
       strcpy(newhead->name,name);
       return newhead;
    }
    else
    {
        if(ptr==NULL)
        {
           cout<<"[����:���������еĽڵ�]"<<endl;
        }
        if(ptr==head) //��������ͷ����λ��
        {
           head->llink=newnode;
           newnode->rlink=head;
           head=newnode;
        }
        else
        {
            if(ptr->rlink==NULL) //��������ĩβ��λ��
            {
               ptr->rlink=newnode;
               newnode->llink=ptr;
               newnode->rlink=NULL;
            }
            else //�����м�ڵ��λ��
            {
                newnode->rlink=ptr->rlink;
                ptr->rlink->llink=newnode;
                ptr->rlink=newnode;
                newnode->llink=ptr;
            }
            
        }
    }
    return head;
}
int main(void)
{  
	link head,ptr;
	link llinknode=NULL;
	link newnode=NULL;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"}
    ,{"John"},{"Mark"},{"Ricky"},{"Lisa"}
    ,{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
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
			cout<<"["<<setw(2)<<data[j*3+i][0]<<"] ["
                <<setw(3)<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	head=new node;//��������ͷָ��
	if(head==NULL)
	{  
		cout<<"Error!! �ڴ����ʧ��!!"<<endl;
		exit(1);
	}
	else
	{
        head=new node;
	    head->num=data[0][0];
	    for (j=0;j<10;j++)
		   head->name[j]=namedata[0][j];
	    head->score=data[0][1];
	    llinknode=head;
	    for(i=1;i<12;i++) //��������
	    {  
		   newnode=new node;
		   newnode->llink = NULL;
		   newnode->rlink = NULL;
		   newnode->num=data[i][0];
		   for (j=0;j<10;j++)
			   newnode->name[j]=namedata[i][j];
		   newnode->score=data[i][1];
		   llinknode->rlink=newnode;
		   newnode->llink=llinknode;
		   llinknode=newnode;
	   }
	}
	
	while(1)
	{  
		cout<<"������Ҫ��������ѧ����ţ���������-1��";
		cin>>position;
		if(position==-1)//ѭ���ж�����
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
	cout<<endl<<"\t����\t    ����\t�ɼ�"<<endl;         
	cout<<"\t=============================="<<endl;
	ptr=head;
	while(ptr!=NULL)
	{
       cout<<"\t["<<setw(2)<<ptr->num<<"]\t[ "
       <<setiosflags(ios::left)<<setw(10)
       <<ptr->name<<"]\t["<<setw(3)
       <<ptr->score<<"]"<<endl;
       ptr=ptr->rlink;   
    }
    free(head);
    free(newnode);
	system("pause");
	return 0;
}
