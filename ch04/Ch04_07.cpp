
#include <iostream>
#include <iomanip>
#include <cmath>
#define EIGHT 8	//定义堆栈的最大容量
#define TRUE 1
#define FALSE 0
using namespace std;
int queen[EIGHT];	//存放8个皇后的行位置
int number=0;		//计算总共有几组解
//决定皇后存放的位置
//输出所需要的结果
int attack(int ,int);
void print_table()
{
     int x=0,y=0;
     number+=1;
     cout<<endl;
     cout<<"八皇后问题的第"<<setw(2)<<number<<"组解"<<endl<<"\t";
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
   //是否受到攻击的判断语句
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
//测试在(row, col)上的皇后是否遭受攻击
//若遭受攻击则返回值为1,否则返回0
int attack(int row,int col)
{
    int i=0,atk=FALSE;
    int offset_row=0,offset_col=0;
    while((atk!=1)&&i<col)
    {
       offset_col=abs(i-col);
       offset_row=abs(queen[i]-row);
       //判断两皇后是否在同一行或在同一对角线
       if((queen[i]==row)||(offset_row==offset_col))
          atk=TRUE;
       i++;
    }
    return atk;
}
//主程序
int main(void)
{
    decide_position(0);      
    return 0; 
}
