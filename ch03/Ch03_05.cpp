#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  //ʹ���������ͷ�ļ�
using namespace std;
class list
{
	public:
 	int num,score;
	char name[10];
	class list *next;
};
list del_ptr(list *head,list *ptr);
int main()
{  
	list *ptr;
	int findword=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Moko"},
    {"Lean"},{"Melissa"},{"Angel"},{"Sabrina"},
    {"Joyce"},{"Jasica"},{"Hanson"},{"Amy"},
    {"Bob"},{"Jack"}};
	srand((unsigned)time(NULL));//��ʱ��Ϊ�����������
	cout<<"���� �ɼ�  ���� �ɼ�  ���� �ɼ�  ����  �ɼ�"<<endl;
	cout<<"=============================================="<<endl;
	for(int i=0;i<12;i++)
	{  
		data[i][0]=i+1;
		data[i][1]=rand()%50+51;
	}
	for(int i=0;i<3;i++)
	{  
		for (int j=0;j<4;j++)
			cout<<"["<<data[j*3+i][0]<<"]  ["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	list *head=new list;//��������ͷָ��
 	if(!head)
	{  
		cout<<"Error!! �ڴ����ʧ��!!"<<endl;
		exit(1);
	}
	head->num=data[0][0];
	for (int j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(int i=1;i<12;i++)                   
	{  
		list *newnode=new list;//��������
  		newnode->num=data[i][0];
		for (int j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	while(1)
	{  
		cout<<"������Ҫɾ���ĳɼ�����������-1��";
		cin>>findword;
		if(findword==-1)//ѭ���ж�����
			break;
		else
		{  
			ptr=head;
			find=0;
			while (ptr!=NULL)
			{  
				if(ptr->score==findword)     
				{  
					*ptr=del_ptr(head,ptr);//ɾ������
     				find++;
				}
				ptr=ptr->next;
			}
			if(find==0)
			cout<<"######û���ҵ�######"<<endl;
		}
	}
	ptr=head;
	cout<<"\n\t����\t    ����\t�ɼ�"<<endl; //���ʣ�������е�����
	cout<<"\t=============================="<<endl;
	while(ptr!=NULL)
	{  
		cout<<"\t["<<ptr->num<<"]\t["<<setw(10)<<ptr->name
            <<"]\t["<<ptr->score<<"]"<<endl;
		ptr=ptr->next;
	}
	system("pause");
}
list del_ptr(list *head,list *ptr)//ɾ���ڵ��ӳ���
{  
	list *top;
 	top=head;
	if(ptr==head)//[����1]:ɾ���ڵ�������ͷ��
	{  
		head=head->next;
		cout<<"��ɾ���� "<<ptr->num<<" ��ѧ��!!������ "
            <<ptr->name<<endl;
	}
	else
	{  
		while(top->next!=ptr)//�ҵ�ɾ���ڵ��ǰһ��λ��
			top=top->next;
		if(ptr->next==NULL)  //[����2]:ɾ���ڵ�������β��
		{  
			top->next=NULL;
	 		cout<<"��ɾ���� "<<ptr->num<<" ��ѧ��!!������ "
                <<ptr->name<<endl;
		}
		else  //[����3]:ɾ���ڵ��������м����һ�ڵ�
		{  
			top->next=ptr->next;
			cout<<"��ɾ���� "<<ptr->num<<" ��ѧ��!!������ "
                <<ptr->name<<endl;
		}
	}
	delete []ptr;  //�ͷ��ڴ�ռ�
	return *head;  //��������
}
