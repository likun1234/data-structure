/*
[ʾ��]:������ȱ�����(BFS)
*/
#include <iostream>
#include <cstdlib>
#define MAXSIZE 10	//������е��������
using namespace std;
int front=-1;	//ָ����е�ǰ��
int rear=-1;	//ָ����еĺ��
struct list		//����ͼ����Ľṹ
{
   int x;		//��������
   struct list *next;	//ָ����һ�������ָ��
};
typedef struct list node;
typedef node *link;
struct GraphLink
{
   link first;
   link last;       
};
int run[9];	//������¼�������Ƿ������
int queue[MAXSIZE];
struct GraphLink Head[9];
void print(struct GraphLink temp)
{
   link current=temp.first;
   while(current!=NULL)
   {
      cout<<"["<<current->x<<"]";
      current=current->next;
   }
   cout<<endl;
}
void insert(struct GraphLink *temp,int x)
{
   link newNode;
   newNode=new node;
   newNode->x=x;
   newNode->next=NULL;  
   if(temp->first==NULL)
   { 
      temp->first=newNode;
      temp->last=newNode;
   }
   else 
   {
	 temp->last->next=newNode;
	 temp->last=newNode;
   }
}
//�������ݵļ���
void enqueue(int value)
{
   if(rear>=MAXSIZE) return;
   rear++;
   queue[rear]=value;
}
//�������ݵ�ȡ��
int dequeue() 
{
   if(front==rear) return -1;
   front++;
   return queue[front];
}
//������ȱ�����
void bfs(int current)
{
   link tempnode;		//��ʱ�Ľڵ�ָ��
   enqueue(current);	//����һ������������
   run[current]=1;		//���������Ķ�������Ϊ1
   cout<<"["<<current<<"]";		//��ӡ���ñ������Ķ���
   while(front!=rear) {	 		//�жϵ�ǰ�Ƿ�Ϊ�ն���
      current=dequeue();		//������Ӷ�����ȡ��
      tempnode=Head[current].first; //�ȼ�¼��ǰ�����λ��
      while(tempnode!=NULL)
      {
         if(run[tempnode->x]==0)
         {
            enqueue(tempnode->x);
            run[tempnode->x]=1; //��¼�ѱ�����
            cout<<"["<<tempnode->x<<"]";
         }
         tempnode=tempnode->next;
      }
   }
} 
int main(void)
{
//�������ͼ�ıߵ�����
   int Data[20][2] =  
   { {1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},
   {3,7},{7,3},{4,5},{5,4},{6,7},{7,6},{5,8},{8,5},{6,8},{8,6} };
   int DataNum;			
   int i,j;				
   cout<<"ͼ���ڽӱ����ݣ�"<<endl; //��ӡͼ���ڽӱ�����
   for( i=1 ; i<9 ; i++ )
   { //���а˸�����
      run[i]=0;	//�������ж������δ������
      cout<<"����"<<i<<"=>";
      Head[i].first=NULL;
      Head[i].last=NULL;                 
	  for( j=0 ; j<20 ;j++)
      {
	     if(Data[j][0]==i)
         { //�����������ͷ��ȣ���Ѷ����������
	        DataNum = Data[j][1];          
	        insert(&Head[i],DataNum);
	     }
	   }
	      print(Head[i]);//��ӡͼ���ڽӱ�����
    } 	
    cout<<"������ȱ������㣺"<<endl;//��ӡ������ȱ����Ķ���
    bfs(1);
    cout<<endl;
	system("pause");
	return 0;
}
