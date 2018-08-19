/*
[ʾ��]:Floyd�㷨(���ж�������֮�����̾���)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define INFINITE  99999 //�����
#define NUMBER 6
using namespace std;
int Graph_Matrix[SIZE][SIZE];//ͼ������
int distance[SIZE][SIZE];		//·�����ȵ�����
//����ͼ 
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;	//�ߵ����
   int End_Point; 	//�ߵ��յ� 
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if (i==j)
            Graph_Matrix[i][j] = 0; //�Խ�����Ϊ0
         else
            Graph_Matrix[i][j] = INFINITE;  
   //����ͼ�εı�
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
      cout<<"vex%d"<<i;
      for ( j = 1; j < SIZE; j++ )
         if ( Graph_Matrix[i][j] == INFINITE )
            cout<<setw(5)<<'x';
         else
            cout<<setw(5)<<Graph_Matrix[i][j];
      cout<<endl;
   }
}
//�����ȫ���������̾��� 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   extern int distance[SIZE][SIZE];		//����Ϊ�ⲿ���� 
   //ͼ�ĳ��������ʼ��
   for (i=1;i<=vertex_total;i++ )
      for (j=i;j<=vertex_total;j++ )
         {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
         }
   //����Floyd�㷨�ҳ����ж�������֮�����̾���
   for (k=1;k<=vertex_total;k++ ) 
      for (i=1;i<=vertex_total;i++ )
         for (j=1;j<=vertex_total;j++ )
            if (distance[i][k]+distance[k][j]<distance[i][j])
                distance[i][j] = distance[i][k] + distance[k][j];   
}
//������
int main(void) 
{
   extern int distance[SIZE][SIZE];		//����Ϊ�ⲿ����
   int Path_Cost[7][3] = { {1, 2, 10}, 
                      {2, 3, 20},
                      {2, 4, 25},
                      {3, 5, 18},
                      {4, 5, 22},
                      {4, 6, 95},
                      {5, 6, 77} }; 
   int i,j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   cout<<"=================================="<<endl;
   cout<<"�˷���ͼ�ε��ڽӾ�������: "<<endl;
   cout<<"=================================="<<endl;
   cout<<"���� vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
   printGraph_Matrix();  //��ʾͼ���ڽӾ���
   cout<<"=================================="<<endl;
   cout<<"���ж�������֮�����̾���: "<<endl;
   cout<<"=================================="<<endl;
   shortestPath(NUMBER); //�������ж��������·��
   //����������������·����������󣬽����ӡ����
   cout<<"���� vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
      for ( i = 1; i <= NUMBER; i++ )
      {
         cout<<"vex"<<i;
         for ( j = 1; j <= NUMBER; j++ )
         {
            cout<<setw(5)<<distance[i][j];
         }
         cout<<endl;
      }
   cout<<endl;
   system("pause");
   return 0; 
}
