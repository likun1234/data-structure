#include <iostream>
#include <cstdlib>
using namespace std;

// �趨����������Ͳ���Type��Ĭ��ֵΪ����int,�����Ͳ���������Ϊ����int,Ĭ��ֵΪ5
template <class Type = int, int size = 5>		// ����������
class Stack
{
      private:
        Type st[size];	// ����һ������Ϊ��ջ�Ĵ洢�ռ�
        int top;		// ��ջ���ݶ��˵�����
      public:
        Stack()
         {
          top = -1;
          }
       void push(Type data);	// ������ѹ���ջ
       Type pop();			// �����ݴӶ�ջ�е���
   };
   template < class Type, int size >
   void Stack< Type, size > :: push ( Type data )
   {
    st[ ++top ] = data;
  	}
   template < class Type, int size >
   Type Stack<Type, size> :: pop()
   {
        return st[ top-- ];
    }
   int main()
   {
    Stack<> stk_1;			// ����һ����ջ����, ��ʹ����Ĭ��ֵ
    Stack<char*, 4> stk_2;	// ������ջ����, ������Ϊ�ַ���, ��СΪ4
    stk_1.push( 11 );
    stk_1.push( 22 );
    stk_1.push( 33 );
    cout << "stack_1 [1] = " << stk_1.pop() << endl;
    cout << "stack_1 [2] = " << stk_1.pop() << endl;
    cout << "stack_1 [3] = " << stk_1.pop() << endl;
    cout << endl;
    stk_2.push( "��һ��" );
    stk_2.push( "�ڶ���" );
    stk_2.push( "������" );
    cout << "stack_2 [1] = " << stk_2.pop() << endl;
    cout << "stack_2 [2] = " << stk_2.pop() << endl;  
    cout << "stack_2 [3] = " << stk_2.pop() << endl;
    cout << endl;
    
    system("pause");
    return 0;
    	
    }
