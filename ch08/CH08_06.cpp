#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define INDEXBOX 7       //��ϣ��Ԫ�ظ���
#define MAXNUM 13      //���ݸ���
using namespace std;
void creat_table(int);	   //����������ϣ���ӳ���
void print_data(int);      //������ӡ��ϣ���ӳ���
class list               //��������ṹ
{  
    public:
	int val;
	class list *next;
};
typedef class list node;
typedef node *link;
node indextable[INDEXBOX];  //������̬����
int main(void)
{  
	int i,data[MAXNUM];
	srand((unsigned)time(NULL));
	for(i=0;i<INDEXBOX;i++) //�����ϣ��
	{  
		indextable[i].val=-1;
		indextable[i].next=NULL;
	}
	cout<<"ԭʼ���ݣ�\n\t";
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1; //���������ԭʼ����
		cout<<"["<<setw(2)<<data[i]<<"] "; //����ӡ����
		if(i%8==7)
			cout<<"\n\t";
	}
	cout<<"\n��ϣ��\n";
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]); //������ϣ��
	for(i=0;i<INDEXBOX;i++)
		print_data(i);        //��ӡ��ϣ��
	cout<<endl;
	system("pause");
	return 0;
}
void creat_table(int val)     //������ϣ���ӳ���
{  
	link newnode;
	link current;
	int hash;
	hash=val%7;              //��ϣ��������7ȡ����
	newnode=(link)malloc(sizeof(node));
	current=(link)malloc(sizeof(node));
	newnode->val=val;
	newnode->next=NULL;
	*current=indextable[hash];
    if(current->next==NULL) 
        indextable[hash].next=newnode;
    else
        while(current->next!=NULL) current=current->next;
    current->next=newnode; //���ڵ�ӵ�������
}
void print_data(int val)   //��ӡ��ϣ���ӳ���
{  
	link head;
	int i=0;
	head=indextable[val].next;  //��ʼָ��
	cout<<"   "<<setw(2)<<val<<"��\t";//������ַ
	while(head!=NULL)
	{  
		cout<<"["<<setw(2)<<head->val<<"]-";
		i++;
		if(i%8==7)  //���Ƴ���
			cout<<"\n\t";
		head=head->next;
	}
	cout<<"\b \n";//������һ��"-"����
}
