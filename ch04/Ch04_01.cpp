#include <iostream>
#include <iomanip>
#define MAXSTACK 100		//�����ջ���������
using namespace std;
int stack[MAXSTACK];		//�������ڶ�ջ����������
int top=-1;				//��ջ�Ķ���
//�ж��Ƿ�Ϊ�ն�ջ
int isEmpty() 
{
    if(top==-1) return 1;
    else return 0;
}
//��ָ��������ѹ���ջ
int push(int data)
{
    if(top>=MAXSTACK)
    {
       cout<<"��ջ����,�޷���ѹ��"<<endl;
       return 0; 
    }
    else
    {
       stack[++top]=data;		//������ѹ���ջ
       return 1;
        
    }
}
//�Ӷ�ջ��������
int pop()
{
    if(isEmpty())			//�ж϶�ջ�Ƿ�Ϊ��,������򷵻�-1
       return -1;
    else
       return stack[top--];	//�����ݵ�����,�ٽ���ջָ��������
}
//������
int main(void)
{
    int value;
    int i;
    cout<<"�밴������10������:"<<endl;
    for(i=0;i<10;i++)
    {
       cin>>value;
       push(value);
    }
    cout<<"===================="<<endl;
    while(!isEmpty())		//������½���Ӷ��˵���
       cout<<"��ջ������˳��Ϊ:"<<setw(2)<<pop()<<endl; 
    cout<<"===================="<<endl;
    system("pause");      
    return 0; 
}
