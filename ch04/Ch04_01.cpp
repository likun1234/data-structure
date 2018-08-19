#include <iostream>
#include <iomanip>
#define MAXSTACK 100		//定义堆栈的最大容量
using namespace std;
int stack[MAXSTACK];		//声明用于堆栈操作的数组
int top=-1;				//堆栈的顶端
//判断是否为空堆栈
int isEmpty() 
{
    if(top==-1) return 1;
    else return 0;
}
//将指定的数据压入堆栈
int push(int data)
{
    if(top>=MAXSTACK)
    {
       cout<<"堆栈已满,无法再压入"<<endl;
       return 0; 
    }
    else
    {
       stack[++top]=data;		//将数据压入堆栈
       return 1;
        
    }
}
//从堆栈弹出数据
int pop()
{
    if(isEmpty())			//判断堆栈是否为空,如果是则返回-1
       return -1;
    else
       return stack[top--];	//将数据弹出后,再将堆栈指针往下移
}
//主程序
int main(void)
{
    int value;
    int i;
    cout<<"请按序输入10个数据:"<<endl;
    for(i=0;i<10;i++)
    {
       cin>>value;
       push(value);
    }
    cout<<"===================="<<endl;
    while(!isEmpty())		//将数据陆续从顶端弹出
       cout<<"堆栈弹出的顺序为:"<<setw(2)<<pop()<<endl; 
    cout<<"===================="<<endl;
    system("pause");      
    return 0; 
}
