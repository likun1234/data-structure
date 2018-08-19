#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>	 // 定义链表中的节点
struct Node
{
  Type data;	// 记录数据
  Node* next;// 记录下一笔节点的地址
};
template <class Type>
class LinkedList	// 链表类型
{
  private:
   Node<Type>* first;	    // 指到第一个节点的指针
   public:
     LinkedList()			    // 构造函数
     {
       first = NULL;
     }
   void addNode(Type data);	// 加入节点
   void display();			    // 显示所有的节点
};
   template<class Type>
   void LinkedList<Type>::addNode(Type data)
   {
    Node<Type>* newNode = new Node<Type>;	// 新增一个节点
    newNode->data = data;			// 记录数据
    newNode->next = first;		// 指向前一个节点
    first = newNode;			// 指向新的节点
   }
   template<class Type>
   void LinkedList<Type>::display()
   {
     Node<Type>* currentNode = first;    // 从第一个节点开始显示
     while( currentNode != NULL )
     {
     cout << currentNode->data << " -> ";
	 currentNode = currentNode->next;
     }
  }

int main()
{
    LinkedList<double> dblList;	    // 建立一个存储double类型数据的链表
    double num;					// 记录输入的数据
    char ch;						// 记录用户的选择
    	do{
           cout << endl <<"请输入一个数字 : ";
           cin >> num;
           dblList.addNode( num );
           cout << "继续输入(y / n)?";
           cin >> ch;
         }while( ch != 'n' );
      cout << endl;
      dblList.display();				// 显示所有的数据
      cout << endl << endl;
      
      system("pause");
      return 0;
}
