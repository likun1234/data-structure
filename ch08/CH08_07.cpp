#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX=7;      //哈希表元素个数
const int MAXNUM=13;     //数据个数
void creat_table(int);       //声明建立哈希表子程序
void print_data(int);       //声明打印哈希表子程序
int findnum(int);          //声明哈希查找子程序
class list				   //声明链表类
{
	public:
	int val;
	list *next;
};
typedef class list node;
typedef node *link;
node indextable[INDEXBOX];	//声明动态数组
int main(void)
{  
	int i,num,data[MAXNUM];
	srand(time(NULL));
	for(i=0;i<INDEXBOX;i++)//清除哈希表
	{  
		indextable[i].val=i;
		indextable[i].next=NULL;
	}
	cout<<"原始数据：\n\t";
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1;	//随机数建立原始数据
		cout<<"["<<setw(2)<<data[i]<<"] ";//并打印出来
		
		if (i%8==7)
			cout<<"\n\t";
	}
	cout<<endl;
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]);//建立哈希表
	while(1)
	{  
		cout<<"请输入要查找的数据(1-30)，结束请输入-1：";
		cin>>num;
		if(num==-1)
			break;
		i=findnum(num);
		if(i==0)
			cout<<"#####没有找到 "<<num<<" #####"<<endl;
		else
			cout<<"找到 "<<num<<"，共找了 "<<i<<" 次!"<<endl;
	}
	cout<<"\n哈希表："<<endl;
	for(i=0;i<INDEXBOX;i++)
		print_data(i);//打印哈希表
	cout<<endl;
	system("pause");
	return 0;
}
void creat_table(int val)//建立哈希表子程序
{  
	link newnode;
	int hash;
	hash=val%7; //哈希函数除以7取余数
	newnode=(link)malloc(sizeof(node));
	if(!newnode)
	{  
		cout<<"ERROR!! 内存分配失败!!"<<endl;
		exit(1);
	}
	newnode->val=val;
	newnode->next=NULL;
	newnode->next=indextable[hash].next;//加入节点
	indextable[hash].next=newnode;
}
void print_data(int val)//打印哈希表子程序
{  
	link head;
	int i=0;
	head=indextable[val].next;//起始指针
	cout<<setw(2)<<val<<"：\t";//索引地址
	while(head!=NULL)
	{  
		cout<<"["<<setw(2)<<head->val<<"]-";
		i++;
		if(i%8==7)//控制长度
			cout<<"\n\t";
		head=head->next;
	}
	cout<<"\b "<<endl;//清除最后一个"-"符号
}
int findnum(int num)  //哈希查找子程序
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
