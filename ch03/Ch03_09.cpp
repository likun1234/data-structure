/*
[����]:ch03_09.cpp
[ʾ��]:��������ڵ��ɾ�� 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

link deletenode(link head,link del)   
{
     link CurNode=NULL;  
     link PreNode=NULL;
     link TailNode=NULL;
     if(head==NULL)
     {
        cout<<"[���������Ѿ�����]";
        return NULL;
     }
     else
     {
         if(del==head) //ɾ���Ľڵ�������ͷ��
         {
            CurNode=head;
            while(CurNode->next!=head)
               CurNode=CurNode->next;
               //�ҵ����һ���ڵ㲢��¼����
               TailNode=CurNode;
               //(1)������ͷָ���Ƶ���һ���ڵ�
               head=head->next;
               //(2)���������һ���ڵ��ָ��ָ���µ�����ͷ��
               TailNode->next=head;
               return head;
         } 
         else //Ҫɾ���Ľڵ㲻������ͷ��
         {
              CurNode=head;
              while(CurNode->next!=del)
                 CurNode=CurNode->next;
              //(1)�ҵ�Ҫɾ���ڵ��ǰһ���ڵ㲢��¼����
              PreNode=CurNode;
              //Ҫɾ���Ľڵ�
              CurNode=CurNode->next;
              //(2)��Ҫɾ���ڵ��ǰһ��ָ��ָ��Ҫɾ���ڵ����һ���ڵ�
              PreNode->next=CurNode->next;
              free(CurNode);
              return head;
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
			cout<<"["<<data[j*3+i][0]<<"]"<<setw(4)<<"["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	head=new node;   //��������ͷָ��
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
	for(i=1;i<12;i++) //��������
	{  
		newnode=new node;
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;	//��ǰһ���ڵ�ָ���½����Ľڵ�
		ptr=newnode;			//�½ڵ��Ϊǰһ���ڵ�
	}
	newnode->next=head;		//�����һ���ڵ�ָ��ͷ���ڵ�ͳ��˻�������
	while(1)
	{  
		cout<<"������Ҫɾ����ѧ����ţ���������-1��";
		cin>>position;
		if(position==-1) //ѭ���ж�����
			break;
		else
		{  
			ptr=findnode(head,position);
			head=deletenode(head,ptr);
		}
	}
	ptr=head;//ָ������Ŀ�ͷ
	cout<<"\n\t����\t    ����\t�ɼ�\n";         
	cout<<"\t==============================\n";
	do
	{
	    cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]"<<endl;
		ptr=ptr->next;//ָ����һ���ڵ�
    } while(head!=ptr && head!=head->next);
    free(head);
	system("pause");
	return 0;
}
