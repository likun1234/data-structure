
#include <iostream>
#include <iomanip>
#include <cmath>
#define EIGHT 8	//�����ջ���������
#define TRUE 1
#define FALSE 0
using namespace std;
int queen[EIGHT];	//���8���ʺ����λ��
int number=0;		//�����ܹ��м����
//�����ʺ��ŵ�λ��
//�������Ҫ�Ľ��
int attack(int ,int);
void print_table()
{
     int x=0,y=0;
     number+=1;
     cout<<endl;
     cout<<"�˻ʺ�����ĵ�"<<setw(2)<<number<<"���"<<endl<<"\t";
     for(x=0;x<EIGHT;x++)
     {
        for(y=0;y<EIGHT;y++)
           if(x==queen[y])
              cout<<"<q>";
           else
              cout<<"<->";
        cout<<endl<<"\t";
     } 
     system("pause"); 
}
void decide_position(int value) 
{
   int i=0;
   while(i<EIGHT)
   {
   //�Ƿ��ܵ��������ж����
      if(attack(i,value)!=1)
      {
         queen[value]=i;
         if(value==7)
            print_table();
         else
            decide_position(value+1);
      }
      i++;
   }    
}
//������(row, col)�ϵĻʺ��Ƿ����ܹ���
//�����ܹ����򷵻�ֵΪ1,���򷵻�0
int attack(int row,int col)
{
    int i=0,atk=FALSE;
    int offset_row=0,offset_col=0;
    while((atk!=1)&&i<col)
    {
       offset_col=abs(i-col);
       offset_row=abs(queen[i]-row);
       //�ж����ʺ��Ƿ���ͬһ�л���ͬһ�Խ���
       if((queen[i]==row)||(offset_row==offset_col))
          atk=TRUE;
       i++;
    }
    return atk;
}
//������
int main(void)
{
    decide_position(0);      
    return 0; 
}
