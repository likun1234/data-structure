/*
[ʾ��]:Dijkstra�㷨(�����ȫ����������·��)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define NUMBER 6
#define INFINITE  99999		//�����
using namespace std;
int Graph_Matrix[SIZE][SIZE];		//���ͼ������
int distance[SIZE];				//·���ĳ���
//����ͼ 
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;		//�ߵ���� 
   int End_Point;		//�ߵ��յ�
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if ( i == j )
            Graph_Matrix[i][j] = 0;	//�Խ�����Ϊ0
         else
            Graph_Matrix[i][j] = INFINITE;  
   //����ͼ�ı� 
   i=0;
   while(i<SIZE)
   {
      Start_Point = Path_Cost[i*3]; 
      End_Point = Path_Cost[i*3+1]; 
      Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
      i++;
   }
}
//��ӡ��ͼ
void printGraph_Matrix()
{
   int i, j;
   for ( i = 1; i < SIZE; i++ )
   {
   cout<<"vex"<<i;
      for ( j = 1; j < SIZE; j++ )
         if ( Graph_Matrix[i][j] == INFINITE )
            cout<<setw(5)<<'x';
         else
            cout<<setw(5)<<Graph_Matrix[i][j];
      cout<<endl;
   }
}
//�����ȫ���������̾��� 
void shortestPath(int vertex1, int vertex_total)
{       
   extern int distance[SIZE];		//����Ϊ�ⲿ���� 
   int shortest_vertex = 1; 		//��¼��̾���Ķ���
   int shortest_distance;   		//��¼��̾���
   int goal[SIZE]; 				//������¼�ö����Ƿ�ѡȡ
   int i,j;
   for ( i = 1; i <= vertex_total; i++ )
   { 
      goal[i] = 0;    
      distance[i] = Graph_Matrix[vertex1][i]; 
   }
   goal[vertex1] = 1;  
   distance[vertex1] = 0;  
   cout<<endl;   
   for (i=1; i<=vertex_total-1; i++ ) 
   {      
      shortest_distance = INFINITE;      
      //�ҳ���̾���Ķ���
      for (j=1;j<=vertex_total;j++ )
         if (goal[j]==0&&shortest_distance>distance[j])
         {
            shortest_distance=distance[j];                                              
            shortest_vertex=j;              
         }
      goal[shortest_vertex] = 1;   
      //���㿪ʼ���㵽���������̾���
      for (j=1;j<=vertex_total;j++ )
      {
         if ( goal[j] == 0 && 
         distance[shortest_vertex]+Graph_Matrix[shortest_vertex][j]
         <distance[j])
         {
           distance[j]=distance[shortest_vertex]
           +Graph_Matrix[shortest_vertex][j];
         }       
      }
   }
}
//������
int main(void) 
{
   extern int distance[SIZE];		//����Ϊ�ⲿ����
   int Path_Cost[7][3] = { {1, 2, 10}, 
                      {2, 3, 20},
                      {2, 4, 25},
                      {3, 5, 18},
                      {4, 5, 22},
                      {4, 6, 95},
                      {5, 6, 77} }; 
   int j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   cout<<"=================================="<<endl;
   cout<<"�˷���ͼ���ڽӾ�������: "<<endl;
   cout<<"=================================="<<endl;
   cout<<"���� vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
   printGraph_Matrix();  //��ʾͼ
   shortestPath(1,NUMBER); //�������·��
   cout<<"=================================="<<endl;
   cout<<"����1����������̾�������ս��"<<endl;
   cout<<"=================================="<<endl;
   for (j=1;j<SIZE;j++) 
      cout<<"���� 1������"<<setw(2)<<j<<"����̾���="
      <<setw(3)<<distance[j]<<endl;
   cout<<endl;
   system("pause");
   return 0; 
}
