/*
[ʾ��]��ʵ��˫�����
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node
{
   public:
   int data;
   class Node *next;
};
typedef class Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;
//����enqueue: ���ݼ������
void enqueue(int value) 
{
   QueueByLinkedList node; //�����ڵ�
   node=new QueueNode;
   node->data=value;
   node->next=NULL;
   //����Ƿ�Ϊ�ն���
   if (rear==NULL)
      front=node;//�½����Ľڵ��Ϊ��1���ڵ�
   else
      rear->next=node;//���ڵ���뵽���е�ĩβ
   rear=node;//�����еĶ�βָ��ָ���¼���Ľڵ�
}
//����dequeue:�Ӷ���ȡ������
int dequeue(int action)
{
   int value;
   QueueByLinkedList tempNode,startNode;
   //�Ӷ���ȡ������
   if (!(front==NULL) && action==1) 
   {
     if(front==rear) rear=NULL;
     value=front->data;//���������ݴӶ���ȡ��
     front=front->next;//�����еĶ���ָ��ָ����һ��
     return value;
   }
   //�Ӷ�βȡ������
   else if(!(rear==NULL) && action==2) 
   {
     startNode=front;//�ȼ��¶��׵�ָ��ֵ
     value=rear->data;//ȡ����ǰ��β������
     //Ѱ����ĩβ�ڵ��ǰһ���ڵ�
     tempNode=front;
     while (front->next!=rear && front->next!=NULL) 
     { 
           front=front->next;
           tempNode=front;
     }
     front=startNode;//��¼�Ӷ�βȡ�����ݺ�Ķ��ж���ָ��
     rear=tempNode;//��¼�Ӷ�βȡ�����ݺ�Ķ��ж�βָ��
     //��һ�г�����ָ�������н�ʣ�����һ���ڵ�ʱ,
     //ȡ�����ݺ�㽫front��rearָ��NULL
     if ((front->next==NULL) || (rear->next==NULL)) 
     { 
         front=NULL;
         rear=NULL;
     }
     return value; 
   }
   else return -1;
}
int main(void)
{
   int temp;
   cout<<"��������ʵ��˫�����"<<endl;
   cout<<"===================================="<<endl;
   cout<<"��˫����ж��׼����1�����ݣ�������ֵΪ1"<<endl;
   enqueue(1);
   cout<<"��˫����ж��׼����2�����ݣ�������ֵΪ3"<<endl;
   enqueue(3);
   cout<<"��˫����ж��׼����3�����ݣ�������ֵΪ5"<<endl;
   enqueue(5);
   cout<<"��˫����ж��׼����4�����ݣ�������ֵΪ7"<<endl;
   enqueue(7);
   cout<<"��˫����ж��׼����5�����ݣ�������ֵΪ9"<<endl;
   enqueue(9);
   cout<<"===================================="<<endl;
   temp=dequeue(1);
   cout<<"��˫����ж��װ���ȡ����Ԫ������ֵΪ��"<<setw(1)<<temp<<endl;
   temp=dequeue(2);
   cout<<"��˫����ж�β����ȡ����Ԫ������ֵΪ��"<<setw(1)<<temp<<endl;
   temp=dequeue(1);
   cout<<"��˫����ж��װ���ȡ����Ԫ������ֵΪ��"<<setw(1)<<temp<<endl;
   temp=dequeue(2);
   cout<<"��˫����ж�β����ȡ����Ԫ������ֵΪ��"<<setw(1)<<temp<<endl;
   temp=dequeue(1);
   cout<<"��˫����ж��װ���ȡ����Ԫ������ֵΪ��"<<setw(1)<<temp<<endl;
   cout<<endl;
   system("pause");
   return 0;
}
