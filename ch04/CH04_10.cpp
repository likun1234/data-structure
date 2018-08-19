/*
[示范]:以链表来实现队列
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
//方法enqueue:数据的加入队列
void enqueue(int value) {
   QueueByLinkedList node; //建立节点
   node=new QueueNode;
   node->data=value;
   node->next=NULL;
  //检查是否为空队列
   if (rear==NULL)
      front=node; //新建立的节点成为第1个节点
   else
      rear->next=node; //将节点加入到队列的末尾
   rear=node; //将队列的末尾指针指向新加入的节点
}
//方法dequeue:从队列取出数据
int dequeue() 
{
   int value;
//检查队列是否为空队列
   if (!(front==NULL)) 
   {
     if(front==rear) rear=NULL;
     value=front->data; //从队列取出数据
     front=front->next; //将队列的前端指针指向下一个
     return value;
   }
   else return -1;
}
int main(void)
{
   int temp;
   cout<<"         以链表来实现队列"<<endl;
   cout<<"===================================="<<endl;
   cout<<"在队列前端加入第1个数据，此数据值为1"<<endl;
   enqueue(1);
   cout<<"在队列前端加入第2个数据，此数据值为3"<<endl;
   enqueue(3);
   cout<<"在队列前端加入第3个数据，此数据值为5"<<endl;
   enqueue(5);
   cout<<"在队列前端加入第4个数据，此数据值为7"<<endl;
   enqueue(7);
   cout<<"在队列前端加入第5个数据，此数据值为9"<<endl;
   enqueue(9);
   cout<<"===================================="<<endl;
   while (1) 
   {
      if (!(front==NULL)) 
      {
         temp=dequeue();
         cout<<"从队列前端按序取出的元素数据值为："<<setw(1)<<temp<<endl;
      }
      else
         break;
   }
   cout<<endl;
   system("pause");
   return 0;
}
