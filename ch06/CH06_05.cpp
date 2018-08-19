/*
[示范]:广度优先遍历法(BFS)
*/
#include <iostream>
#include <cstdlib>
#define MAXSIZE 10	//定义队列的最大容量
using namespace std;
int front=-1;	//指向队列的前端
int rear=-1;	//指向队列的后端
struct list		//声明图顶点的结构
{
   int x;		//顶点数据
   struct list *next;	//指向下一个顶点的指针
};
typedef struct list node;
typedef node *link;
struct GraphLink
{
   link first;
   link last;       
};
int run[9];	//用来记录各顶点是否遍历过
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
//队列数据的加入
void enqueue(int value)
{
   if(rear>=MAXSIZE) return;
   rear++;
   queue[rear]=value;
}
//队列数据的取出
int dequeue() 
{
   if(front==rear) return -1;
   front++;
   return queue[front];
}
//广度优先遍历法
void bfs(int current)
{
   link tempnode;		//临时的节点指针
   enqueue(current);	//将第一个顶点加入队列
   run[current]=1;		//将遍历过的顶点设置为1
   cout<<"["<<current<<"]";		//打印出该遍历过的顶点
   while(front!=rear) {	 		//判断当前是否为空队列
      current=dequeue();		//将顶点从队列中取出
      tempnode=Head[current].first; //先记录当前顶点的位置
      while(tempnode!=NULL)
      {
         if(run[tempnode->x]==0)
         {
            enqueue(tempnode->x);
            run[tempnode->x]=1; //记录已遍历过
            cout<<"["<<tempnode->x<<"]";
         }
         tempnode=tempnode->next;
      }
   }
} 
int main(void)
{
//声明存放图的边的数组
   int Data[20][2] =  
   { {1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},
   {3,7},{7,3},{4,5},{5,4},{6,7},{7,6},{5,8},{8,5},{6,8},{8,6} };
   int DataNum;			
   int i,j;				
   cout<<"图的邻接表内容："<<endl; //打印图的邻接表内容
   for( i=1 ; i<9 ; i++ )
   { //共有八个顶点
      run[i]=0;	//设置所有顶点成尚未遍历过
      cout<<"顶点"<<i<<"=>";
      Head[i].first=NULL;
      Head[i].last=NULL;                 
	  for( j=0 ; j<20 ;j++)
      {
	     if(Data[j][0]==i)
         { //如果起点和链表头相等，则把顶点加入链表
	        DataNum = Data[j][1];          
	        insert(&Head[i],DataNum);
	     }
	   }
	      print(Head[i]);//打印图的邻接表内容
    } 	
    cout<<"广度优先遍历顶点："<<endl;//打印广度优先遍历的顶点
    bfs(1);
    cout<<endl;
	system("pause");
	return 0;
}
