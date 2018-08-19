#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Node	//������ջ����ڵ�
{
   public:
   int data;	//������Ŷ�ջ���ݵı���
   class Node *next;	//��ջ������ָ����һ���ڵ��ָ��
};
typedef class Node Stack_Node;		//�����ջ�нڵ��������
typedef Stack_Node *Linked_Stack;	//���������ջ��������
Linked_Stack top=NULL;				//ָ���ջ���˵�ָ��

//�ж��Ƿ�Ϊ�ն�ջ
int isEmpty()
{
    if(top==NULL) return 1;
    else return 0;
}
//��ָ��������ѹ���ջ
void push(int data)
{
    Linked_Stack new_add_node;	//�¼���ڵ��ָ��
    //�����ڴ���½ڵ�
    new_add_node=new Stack_Node;
    new_add_node->data=data;		//�������ֵ��ֵ���ڵ�����ݱ���
    new_add_node->next=top;		//���½ڵ�ָ���ջ�Ķ���
    top=new_add_node;			//�½ڵ��Ϊ��ջ�Ķ���
}
//�Ӷ�ջ��������
int pop()
{
    Linked_Stack ptr;		//ָ���ջ���˵�ָ��
    int temp;
    if(isEmpty())			//�ж϶�ջ�Ƿ�Ϊ��,������򷵻�-1
    {
       cout<<"===ĿǰΪ�ն�ջ==="<<endl;
       return -1;
    }
    else
    {
        ptr=top;		//ָ���ջ�Ķ���
        top=top->next;	//����ջ���˵�ָ��ָ����һ���ڵ�
        temp=ptr->data;	//ȡ����ջ������
        free(ptr);			//���ڵ�ռ�õ��ڴ��ͷ�
        return temp;		//���Ӷ�ջȡ�������ݷ��ظ�������
    }
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
    while(!isEmpty()) //������½���Ӷ��˵���
       cout<<"��ջ������˳��Ϊ:"<<setw(2)<<pop()<<endl; 
    cout<<"===================="<<endl;
    system("pause");      
    return 0; 
}
