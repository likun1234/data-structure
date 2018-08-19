/*
[示范]：实现双向队列
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
//方法enqueue: 数据加入队列
void enqueue(int value) 
{
   QueueByLinkedList node; //建立节点
   node=new QueueNode;
   node->data=value;
   node->next=NULL;
   //检查是否为空队列
   if (rear==NULL)
      front=node;//新建立的节点成为第1个节点
   else
      rear->next=node;//将节点加入到队列的末尾
   rear=node;//将队列的队尾指针指向新加入的节点
}
//方法dequeue:从队列取出数据
int dequeue(int action)
{
   int value;
   QueueByLinkedList tempNode,startNode;
   //从队首取出数据
   if (!(front==NULL) && action==1) 
   {
     if(front==rear) rear=NULL;
     value=front->data;//将队列数据从队首取出
     front=front->next;//将队列的队首指针指向下一个
     return value;
   }
   //从队尾取出数据
   else if(!(rear==NULL) && action==2) 
   {
     startNode=front;//先记下队首的指标值
     value=rear->data;//取出当前队尾的数据
     //寻找最末尾节点的前一个节点
     tempNode=front;
     while (front->next!=rear && front->next!=NULL) 
     { 
           front=front->next;
           tempNode=front;
     }
     front=startNode;//记录从队尾取出数据后的队列队首指针
     rear=tempNode;//记录从队尾取出数据后的队列队尾指针
     //下一行程序是指当队列中仅剩下最后一个节点时,
     //取出数据后便将front和rear指向NULL
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
   cout<<"以链表来实现双向队列"<<endl;
   cout<<"===================================="<<endl;
   cout<<"在双向队列队首加入第1笔数据，此数据值为1"<<endl;
   enqueue(1);
   cout<<"在双向队列队首加入第2笔数据，此数据值为3"<<endl;
   enqueue(3);
   cout<<"在双向队列队首加入第3笔数据，此数据值为5"<<endl;
   enqueue(5);
   cout<<"在双向队列队首加入第4笔数据，此数据值为7"<<endl;
   enqueue(7);
   cout<<"在双向队列队首加入第5笔数据，此数据值为9"<<endl;
   enqueue(9);
   cout<<"===================================="<<endl;
   temp=dequeue(1);
   cout<<"从双向队列队首按序取出的元素数据值为："<<setw(1)<<temp<<endl;
   temp=dequeue(2);
   cout<<"从双向队列队尾按序取出的元素数据值为："<<setw(1)<<temp<<endl;
   temp=dequeue(1);
   cout<<"从双向队列队首按序取出的元素数据值为："<<setw(1)<<temp<<endl;
   temp=dequeue(2);
   cout<<"从双向队列队尾按序取出的元素数据值为："<<setw(1)<<temp<<endl;
   temp=dequeue(1);
   cout<<"从双向队列队首按序取出的元素数据值为："<<setw(1)<<temp<<endl;
   cout<<endl;
   system("pause");
   return 0;
}
