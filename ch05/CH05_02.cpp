#include <iostream>
#include <cstdlib>
#include <iomanip>
#define ArraySize 10
using namespace std;
class Node//�������ڵ����ݽṹ������ 
{
    public:
    int value;//�ڵ�����
    struct Node *left_Node;//ָ����������ָ��
    struct Node *right_Node;//ָ����������ָ��
};
typedef class Node TreeNode;//�����µĶ������ڵ���������
typedef TreeNode *BinaryTree;//�����µĶ�����������������
BinaryTree rootNode;//�������ĸ��ڵ��ָ�� 

//��ָ����ֵ���뵽���������ʵ��Ľڵ�
void Add_Node_To_Tree(int value)
{
      BinaryTree currentNode;
      BinaryTree newnode;
      int flag=0;//������¼�Ƿ�����µĽڵ�
      newnode=(BinaryTree) malloc(sizeof(TreeNode));
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
int main(void)
{
    int tempdata;
    int content[ArraySize];
    int i=0;
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));
    rootNode=NULL;
    cout<<"����������10������: "<<endl;
    for(i=0;i<ArraySize;i++)
    {
      cout<<"�������"<<setw(1)<<(i+1)<<"������: ";
      cin>>tempdata;       
      content[i]=tempdata;
    }
    for(i=0;i<ArraySize;i++) 
         Add_Node_To_Tree(content[i]);
    cout<<"��������ӵķ�ʽ����������";
    cout<<endl;  
	system("pause");
	return 0;
}
