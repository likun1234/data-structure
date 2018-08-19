#include <iostream>
#include <cstdlib>
using namespace std;

// 设定类样版的类型参数Type的默认值为整数int,非类型参数的类型为整数int,默认值为5
template <class Type = int, int size = 5>		// 声明类样板
class Stack
{
      private:
        Type st[size];	// 声明一数组作为堆栈的存储空间
        int top;		// 堆栈数据顶端的索引
      public:
        Stack()
         {
          top = -1;
          }
       void push(Type data);	// 将数据压入堆栈
       Type pop();			// 将数据从堆栈中弹出
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
    Stack<> stk_1;			// 声明一个堆栈对象, 并使用其默认值
    Stack<char*, 4> stk_2;	// 声明堆栈对象, 其类型为字符串, 大小为4
    stk_1.push( 11 );
    stk_1.push( 22 );
    stk_1.push( 33 );
    cout << "stack_1 [1] = " << stk_1.pop() << endl;
    cout << "stack_1 [2] = " << stk_1.pop() << endl;
    cout << "stack_1 [3] = " << stk_1.pop() << endl;
    cout << endl;
    stk_2.push( "第一名" );
    stk_2.push( "第二名" );
    stk_2.push( "第三名" );
    cout << "stack_2 [1] = " << stk_2.pop() << endl;
    cout << "stack_2 [2] = " << stk_2.pop() << endl;  
    cout << "stack_2 [3] = " << stk_2.pop() << endl;
    cout << endl;
    
    system("pause");
    return 0;
    	
    }
