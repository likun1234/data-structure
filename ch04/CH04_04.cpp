#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>	 // ���������еĽڵ�
struct Node
{
  Type data;	// ��¼����
  Node* next;// ��¼��һ�ʽڵ�ĵ�ַ
};
template <class Type>
class LinkedList	// ��������
{
  private:
   Node<Type>* first;	    // ָ����һ���ڵ��ָ��
   public:
     LinkedList()			    // ���캯��
     {
       first = NULL;
     }
   void addNode(Type data);	// ����ڵ�
   void display();			    // ��ʾ���еĽڵ�
};
   template<class Type>
   void LinkedList<Type>::addNode(Type data)
   {
    Node<Type>* newNode = new Node<Type>;	// ����һ���ڵ�
    newNode->data = data;			// ��¼����
    newNode->next = first;		// ָ��ǰһ���ڵ�
    first = newNode;			// ָ���µĽڵ�
   }
   template<class Type>
   void LinkedList<Type>::display()
   {
     Node<Type>* currentNode = first;    // �ӵ�һ���ڵ㿪ʼ��ʾ
     while( currentNode != NULL )
     {
     cout << currentNode->data << " -> ";
	 currentNode = currentNode->next;
     }
  }

int main()
{
    LinkedList<double> dblList;	    // ����һ���洢double�������ݵ�����
    double num;					// ��¼���������
    char ch;						// ��¼�û���ѡ��
    	do{
           cout << endl <<"������һ������ : ";
           cin >> num;
           dblList.addNode( num );
           cout << "��������(y / n)?";
           cin >> ch;
         }while( ch != 'n' );
      cout << endl;
      dblList.display();				// ��ʾ���е�����
      cout << endl << endl;
      
      system("pause");
      return 0;
}
