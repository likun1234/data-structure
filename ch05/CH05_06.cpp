#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node//�������ڵ������
{
    public:
    int value;//�ڵ�����
    class Node *left_Node;//ָ����������ָ��
    class Node *right_Node;//ָ����������ָ��
};
typedef class Node TreeNode;//�����µĶ������ڵ���������
typedef TreeNode *BinaryTree;//�����µĶ�����������������
BinaryTree rootNode;//���������ڵ��ָ�� 
BinaryTree rootNode2;
//��ָ����ֵ���뵽���������ʵ��Ľڵ�
void Add_Node_To_Tree(int value)
{
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag=0;//������¼�Ƿ�����µĽڵ�
    newnode=(BinaryTree) new TreeNode;
    //�����ڵ�����
    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    //���Ϊ�յĶ�����,�㽫�µĽڵ��趨Ϊ���ڵ�
    if(rootNode==NULL)
        rootNode=newnode;
    else 
    {
        currentNode=rootNode;//ָ��һ��ָ��ָ����ڵ�
        while(!flag)
          if (value<currentNode->value) 
          { //��������
             if(currentNode->left_Node==NULL)
             {
                currentNode->left_Node=newnode;
                flag=1;
             }
             else
                currentNode=currentNode->left_Node;
          }
          else
          { //��������
             if(currentNode->right_Node==NULL) 
             {
                currentNode->right_Node=newnode;
                flag=1;
             }
             else
                currentNode=currentNode->right_Node;
          }
     }
}
BinaryTree create(char sequence[100],int index,int ArraySize)
{
      BinaryTree tempNode;            
      if ( sequence[index]==0 ||index >= ArraySize )//��Ϊ��������
         return NULL;
      else  { 
         tempNode=(BinaryTree) new TreeNode;
         tempNode->value=(int)sequence[index];
         tempNode->left_Node=NULL;
         tempNode->right_Node=NULL;
         //����������
         tempNode->left_Node = create(sequence, 2*index,ArraySize);
         //����������
         tempNode->right_Node = create(sequence, 2*index+1,ArraySize);
         return tempNode;
      }
}
//preOrder(ǰ�����)�����ĳ�������
void preOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         cout<<setw(1)<<(char)node->value;
         preOrder(node->left_Node);  
         preOrder(node->right_Node); 
      }
}
//inOrder(�������)�����ĳ�������
void inOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         inOrder(node->left_Node);  
         cout<<setw(1)<<(char)node->value;
         inOrder(node->right_Node); 
      }
}
//postOrder(�������)�����ĳ�������
void postOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         postOrder(node->left_Node);  
         postOrder(node->right_Node); 
         cout<<setw(1)<<(char)node->value;
      }
}
//�жϱ��ʽ�������ķ���
int condition(char oprator, int num1, int num2)
{
      switch ( oprator ) {
         case '*': return ( num1 * num2 ); //�˷��뷵��num1 * num2
         case '/': return ( num1 / num2 ); //�����뷵��num1 / num2
         case '+': return ( num1 + num2 ); //�ӷ��뷵��num1 + num2
         case '-': return ( num1 - num2 ); //�����뷵��num1 - num2
         case '%': return ( num1 % num2 ); //ȡ�������뷵��num1 % num2
      }
      return -1;
}
//������ڵ�,��������˶�����������ֵ
int answer(BinaryTree node) 
{
      int firstnumber = 0;       
      int secondnumber = 0;      
      //�ݹ���õĳ�������
      if ( node->left_Node == NULL && node->right_Node == NULL )
        //���ڵ��ֵת������ֵ�󴫻�
        return node->value-48;
      else {
        firstnumber = answer(node->left_Node);//�������������ʽ��ֵ
        secondnumber = answer(node->right_Node); //�������������ʽ��ֵ
        return condition((char)node->value, firstnumber, secondnumber);
      }
   }
int main(void)
{
    //��һ�����ʽ 
    char information1[] = {' ','+','*','%','6','3','9','5' };
    //�ڶ������ʽ 
    char information2[] = {' ','+','+','+','*','%','/','*',
                          '1','2','3','2','6','3','2','2' }; 
    rootNode=(BinaryTree)new TreeNode;                      
    rootNode2=(BinaryTree)new TreeNode;                     
    //create�������Խ��������������ʾ��ת���������ʾ��
    rootNode = create(information1,1,8);
    cout<<"====������������ֵ���㷶�� 1: ===="<<endl;
    cout<<"================================="<<endl;
    cout<<"===ת����������ʽ===:  ";
    inOrder(rootNode);     
    cout<<endl<<"===ת����ǰ����ʽ===:  ";
    preOrder(rootNode);    
    cout<<endl<<"===ת���ɺ�����ʽ===:  ";
    postOrder(rootNode);   
    //������������ʽ��������
    cout<<endl<<"�˶���������,������������õ��Ľ��ֵ: ";
    cout<<setw(1)<<answer(rootNode);
    //�����ڶ��ö������������
    rootNode2 = create(information2,1,16);
    cout<<endl;
    cout<<endl;
    cout<<"====������������ֵ���㷶�� 2: ===="<<endl;
    cout<<"================================="<<endl;
    cout<<"===ת����������ʽ===:  ";
    inOrder(rootNode2);     
    cout<<endl<<"===ת����ǰ����ʽ===:  ";
    preOrder(rootNode2);    
    cout<<endl<<"===ת���ɺ�����ʽ===:  ";
    postOrder(rootNode2);   
    //������������ʽ��������
    cout<<endl<<"�˶���������,������������õ��Ľ��ֵ: ";
    cout<<setw(1)<<answer(rootNode2); 
    cout<<endl;
    delete rootNode;
    delete rootNode2;
    system("pause");
	return 0;
}
