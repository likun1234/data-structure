#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node//二叉树节点的声明
{
    public:
    int value;//节点数据
    class Node *left_Node;//指向左子树的指针
    class Node *right_Node;//指向右子树的指针
};
typedef class Node TreeNode;//定义新的二叉树节点数据类型
typedef TreeNode *BinaryTree;//定义新的二叉树链接数据类型
BinaryTree rootNode;//二叉树根节点的指针 
BinaryTree rootNode2;
//将指定的值加入到二叉树中适当的节点
void Add_Node_To_Tree(int value)
{
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag=0;//用来记录是否插入新的节点
    newnode=(BinaryTree) new TreeNode;
    //建立节点内容
    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    //如果为空的二叉树,便将新的节点设定为根节点
    if(rootNode==NULL)
        rootNode=newnode;
    else 
    {
        currentNode=rootNode;//指定一个指针指向根节点
        while(!flag)
          if (value<currentNode->value) 
          { //在左子树
             if(currentNode->left_Node==NULL)
             {
                currentNode->left_Node=newnode;
                flag=1;
             }
             else
                currentNode=currentNode->left_Node;
          }
          else
          { //在右子树
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
      if ( sequence[index]==0 ||index >= ArraySize )//作为出口条件
         return NULL;
      else  { 
         tempNode=(BinaryTree) new TreeNode;
         tempNode->value=(int)sequence[index];
         tempNode->left_Node=NULL;
         tempNode->right_Node=NULL;
         //建立左子树
         tempNode->left_Node = create(sequence, 2*index,ArraySize);
         //建立右子树
         tempNode->right_Node = create(sequence, 2*index+1,ArraySize);
         return tempNode;
      }
}
//preOrder(前序遍历)方法的程序内容
void preOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         cout<<setw(1)<<(char)node->value;
         preOrder(node->left_Node);  
         preOrder(node->right_Node); 
      }
}
//inOrder(中序遍历)方法的程序内容
void inOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         inOrder(node->left_Node);  
         cout<<setw(1)<<(char)node->value;
         inOrder(node->right_Node); 
      }
}
//postOrder(后序遍历)方法的程序内容
void postOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         postOrder(node->left_Node);  
         postOrder(node->right_Node); 
         cout<<setw(1)<<(char)node->value;
      }
}
//判断表达式如何运算的方法
int condition(char oprator, int num1, int num2)
{
      switch ( oprator ) {
         case '*': return ( num1 * num2 ); //乘法请返回num1 * num2
         case '/': return ( num1 / num2 ); //除法请返回num1 / num2
         case '+': return ( num1 + num2 ); //加法请返回num1 + num2
         case '-': return ( num1 - num2 ); //减法请返回num1 - num2
         case '%': return ( num1 % num2 ); //取余数法请返回num1 % num2
      }
      return -1;
}
//传入根节点,用来计算此二叉运算树的值
int answer(BinaryTree node) 
{
      int firstnumber = 0;       
      int secondnumber = 0;      
      //递归调用的出口条件
      if ( node->left_Node == NULL && node->right_Node == NULL )
        //将节点的值转换成数值后传回
        return node->value-48;
      else {
        firstnumber = answer(node->left_Node);//计算左子树表达式的值
        secondnumber = answer(node->right_Node); //计算右子树表达式的值
        return condition((char)node->value, firstnumber, secondnumber);
      }
   }
int main(void)
{
    //第一个表达式 
    char information1[] = {' ','+','*','%','6','3','9','5' };
    //第二个表达式 
    char information2[] = {' ','+','+','+','*','%','/','*',
                          '1','2','3','2','6','3','2','2' }; 
    rootNode=(BinaryTree)new TreeNode;                      
    rootNode2=(BinaryTree)new TreeNode;                     
    //create方法可以将二叉树的数组表示法转换成链表表示法
    rootNode = create(information1,1,8);
    cout<<"====二叉运算树数值运算范例 1: ===="<<endl;
    cout<<"================================="<<endl;
    cout<<"===转换成中序表达式===:  ";
    inOrder(rootNode);     
    cout<<endl<<"===转换成前序表达式===:  ";
    preOrder(rootNode);    
    cout<<endl<<"===转换成后序表达式===:  ";
    postOrder(rootNode);   
    //计算二叉树表达式的运算结果
    cout<<endl<<"此二叉运算树,经过计算后所得到的结果值: ";
    cout<<setw(1)<<answer(rootNode);
    //建立第二棵二叉查找树对象
    rootNode2 = create(information2,1,16);
    cout<<endl;
    cout<<endl;
    cout<<"====二叉运算树数值运算范例 2: ===="<<endl;
    cout<<"================================="<<endl;
    cout<<"===转换成中序表达式===:  ";
    inOrder(rootNode2);     
    cout<<endl<<"===转换成前序表达式===:  ";
    preOrder(rootNode2);    
    cout<<endl<<"===转换成后序表达式===:  ";
    postOrder(rootNode2);   
    //计算二叉树表达式的运算结果
    cout<<endl<<"此二叉运算树,经过计算后所得到的结果值: ";
    cout<<setw(1)<<answer(rootNode2); 
    cout<<endl;
    delete rootNode;
    delete rootNode2;
    system("pause");
	return 0;
}
