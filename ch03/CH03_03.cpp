#include <iostream>
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
int main()
{  
	link newnode,ptr,delptr; //������������ṹ��ָ��
	cout<<"������ 5 λѧ�������ݣ�"<<endl;
	delptr=new node;   //delptr�ݵ�����ͷָ��
	if (!delptr)
	{  
		cout<<"[Error!!�ڴ����ʧ��!]"<<endl;
		exit(1);
	}
	cout<<"���������ţ�";
	cin>>delptr->num;
	cout<<"������������";
	cin>>delptr->name;
	cout<<"������ɼ���";
	cin>>delptr->score;
	ptr=delptr;   //��������ͷָ�룬��ptrΪָ��ǰ�ڵ��ָ��
	for (int i=1;i<5;i++)
	{  
		newnode=new node;  //�����½ڵ�
		if(!newnode)
		{  
			cout<<"[Error!!�ڴ����ʧ��!"<<endl;
			exit(1);
		}
		cout<<"���������ţ�";
		cin>>newnode->num;
		cout<<"������������";
		cin>>newnode->name;
		cout<<"������ɼ���";
		cin>>newnode->score;
		newnode->next=NULL;
		ptr->next=newnode; //���½ڵ�����������
		ptr=ptr->next;     //��ptr����������������
	}
    cout<<"\n  ѧ  ��  ��  ��"<<endl;
    cout<<" ����\t����\t�ɼ�\n====================="<<endl;
	ptr=delptr;            //��ptr�ص�����ͷ
	while(ptr!=NULL)
	{  
		cout<<ptr->num<<"\t"<<ptr->name<<"\t"<<ptr->score<<endl;
	    delptr=ptr;
		ptr=ptr->next;     //ptr�������������������
        delete delptr;     //�ͷ��ڴ�ռ�
	}
	system("pause");
}
