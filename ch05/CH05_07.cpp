#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node {
       public:
       int value;
       int left_Thread;
       int right_Thread;
       class Node *left_Node;
       class Node *right_Node;
};
typedef class Node ThreadNode;
typedef ThreadNode *ThreadBinaryTree;
ThreadBinaryTree rootNode;
//将指定的值加入到线索二叉树
void Add_Node_To_Tree(int value) {
     ThreadBinaryTree newnode;
     ThreadBinaryTree previous;
      newnode=new ThreadNode;     
      newnode->value=value;
      newnode->left_Thread=0;
      newnode->right_Thread=0;
      newnode->left_Node=NULL;
      newnode->right_Node=NULL;
      ThreadBinaryTree current;
      ThreadBinaryTree parent;
      previous=new ThreadNode;
      previous->value=value;
      previous->left_Thread=0;
      previous->right_Thread=0;
      previous->left_Node=NULL;
      previous->right_Node=NULL;
      int pos;
      //设置线索二叉树的开头节点
      if(rootNode==NULL) {
         rootNode=newnode;
         rootNode->left_Node=rootNode;
         rootNode->right_Node=NULL;
         rootNode->left_Thread=0;
         rootNode->right_Thread=1;
         return;
      }
      //设置开头节点所指的节点
      current=rootNode->right_Node;
      if(current==NULL){
         rootNode->right_Node=newnode;
         newnode->left_Node=rootNode;
         newnode->right_Node=rootNode;
         return ;
      }
      parent=rootNode; //父节点是开头节点
      pos=0; //设置二叉树中的行进方向
      while(current!=NULL) {
         if(current->value>value) {
            if(pos!=-1) {
               pos=-1;
               previous=parent;
            }
            parent=current;
            if(current->left_Thread==1)
               current=current->left_Node;
            else
               current=NULL;
         }
         else {
            if(pos!=1) {
               pos=1;
               previous=parent;
            }
            parent=current;
            if(current->right_Thread==1)
               current=current->right_Node;
            else
               current=NULL;
         }
      }
      if(parent->value>value) {
         parent->left_Thread=1;
         parent->left_Node=newnode;
         newnode->left_Node=previous;
         newnode->right_Node=parent;
      }
      else {
         parent->right_Thread=1;
         parent->right_Node=newnode;
         newnode->left_Node=parent;
         newnode->right_Node=previous;
      }
      return ;
   }
//线索二叉树中序遍历
   void trace() {
      ThreadBinaryTree tempNode;
      tempNode=rootNode;
      do {
         if(tempNode->right_Thread==0)
            tempNode=tempNode->right_Node;
         else
         {
            tempNode=tempNode->right_Node;
            while(tempNode->left_Thread!=0)
               tempNode=tempNode->left_Node;
         }
         if(tempNode!=rootNode)
            cout<<"["<<setw(3)<<tempNode->value<<"]"<<endl;
      } while(tempNode!=rootNode);
   } 
int main(void)
{
      int i=0;
      int array_size=11;
      cout<<"线索二叉树经建立后,以中序遍历能有排序的效果"<<endl;
      cout<<"第一个数字为线索二叉树的开头节点,不列入排序"<<endl;
      int data1[]={0,10,20,30,100,399,453,43,237,373,655};
      for(i=0;i<array_size;i++)
         Add_Node_To_Tree(data1[i]);
      cout<<"===================================="<<endl;
      cout<<"范例 1 "<<endl;
      cout<<"数字由小到大的排序顺序结果为: "<<endl;
      trace();
      int data2[]={0,101,118,87,12,765,65};
      rootNode=NULL;//将线索二叉树的树根归零
      array_size=7;//第2个范例的数组长度为7
      for(i=0;i<array_size;i++)
         Add_Node_To_Tree(data2[i]);    
      cout<<"===================================="<<endl;
      cout<<"范例 2 "<<endl;
      cout<<"数字由小到大的排序顺序结果为: "<<endl;
      trace();
      cout<<endl;
      system("pause");
	  return 0;
}
