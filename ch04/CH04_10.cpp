/*
[ʾ��]:��������ʵ�ֶ���
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
//����enqueue:���ݵļ������
void enqueue(int value) {
   QueueByLinkedList node; //�����ڵ�
   node=new QueueNode;
   node->data=value;
   node->next=NULL;
  //����Ƿ�Ϊ�ն���
   if (rear==NULL)
      front=node; //�½����Ľڵ��Ϊ��1���ڵ�
   else
      rear->next=node; //���ڵ���뵽���е�ĩβ
   rear=node; //�����е�ĩβָ��ָ���¼���Ľڵ�
}
//����dequeue:�Ӷ���ȡ������
int dequeue() 
{
   int value;
//�������Ƿ�Ϊ�ն���
   if (!(front==NULL)) 
   {
     if(front==rear) rear=NULL;
     value=front->data; //�Ӷ���ȡ������
     front=front->next; //�����е�ǰ��ָ��ָ����һ��
     return value;
   }
   else return -1;
}
int main(void)
{
   int temp;
   cout<<"         ��������ʵ�ֶ���"<<endl;
   cout<<"===================================="<<endl;
   cout<<"�ڶ���ǰ�˼����1�����ݣ�������ֵΪ1"<<endl;
   enqueue(1);
   cout<<"�ڶ���ǰ�˼����2�����ݣ�������ֵΪ3"<<endl;
   enqueue(3);
   cout<<"�ڶ���ǰ�˼����3�����ݣ�������ֵΪ5"<<endl;
   enqueue(5);
   cout<<"�ڶ���ǰ�˼����4�����ݣ�������ֵΪ7"<<endl;
   enqueue(7);
   cout<<"�ڶ���ǰ�˼����5�����ݣ�������ֵΪ9"<<endl;
   enqueue(9);
   cout<<"===================================="<<endl;
   while (1) 
   {
      if (!(front==NULL)) 
      {
         temp=dequeue();
         cout<<"�Ӷ���ǰ�˰���ȡ����Ԫ������ֵΪ��"<<setw(1)<<temp<<endl;
      }
      else
         break;
   }
   cout<<endl;
   system("pause");
   return 0;
}
