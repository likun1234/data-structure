#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX=7;      //��ϣ��Ԫ�ظ���
const int MAXNUM=13;     //���ݸ���
void creat_table(int);       //����������ϣ���ӳ���
void print_data(int);       //������ӡ��ϣ���ӳ���
int findnum(int);          //������ϣ�����ӳ���
class list				   //����������
{
	public:
	int val;
	list *next;
};
typedef class list node;
typedef node *link;
node indextable[INDEXBOX];	//������̬����
int main(void)
{  
	int i,num,data[MAXNUM];
	srand(time(NULL));
	for(i=0;i<INDEXBOX;i++)//�����ϣ��
	{  
		indextable[i].val=i;
		indextable[i].next=NULL;
	}
	cout<<"ԭʼ���ݣ�\n\t";
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1;	//���������ԭʼ����
		cout<<"["<<setw(2)<<data[i]<<"] ";//����ӡ����
		
		if (i%8==7)
			cout<<"\n\t";
	}
	cout<<endl;
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]);//������ϣ��
	while(1)
	{  
		cout<<"������Ҫ���ҵ�����(1-30)������������-1��";
		cin>>num;
		if(num==-1)
			break;
		i=findnum(num);
		if(i==0)
			cout<<"#####û���ҵ� "<<num<<" #####"<<endl;
		else
			cout<<"�ҵ� "<<num<<"�������� "<<i<<" ��!"<<endl;
	}
	cout<<"\n��ϣ��"<<endl;
	for(i=0;i<INDEXBOX;i++)
		print_data(i);//��ӡ��ϣ��
	cout<<endl;
	system("pause");
	return 0;
}
void creat_table(int val)//������ϣ���ӳ���
{  
	link newnode;
	int hash;
	hash=val%7; //��ϣ��������7ȡ����
	newnode=(link)malloc(sizeof(node));
	if(!newnode)
	{  
		cout<<"ERROR!! �ڴ����ʧ��!!"<<endl;
		exit(1);
	}
	newnode->val=val;
	newnode->next=NULL;
	newnode->next=indextable[hash].next;//����ڵ�
	indextable[hash].next=newnode;
}
void print_data(int val)//��ӡ��ϣ���ӳ���
{  
	link head;
	int i=0;
	head=indextable[val].next;//��ʼָ��
	cout<<setw(2)<<val<<"��\t";//������ַ
	while(head!=NULL)
	{  
		cout<<"["<<setw(2)<<head->val<<"]-";
		i++;
		if(i%8==7)//���Ƴ���
			cout<<"\n\t";
		head=head->next;
	}
	cout<<"\b "<<endl;//������һ��"-"����
}
int findnum(int num)  //��ϣ�����ӳ���
{  
	link ptr;
	int i=0,hash;
	hash=num%7;
	ptr=indextable[hash].next;
	while(ptr!=NULL)
	{  
		i++;
		if(ptr->val==num)
			return i;
		else
			ptr=ptr->next;
	}
	return 0;
}
