/*
[示范]:将数学表达式由中序表示法转为后序表示法 
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define MAX 50
char infix_q[MAX]; //用来存放中序表示法的队列  
//运算符优先级的比较，若输入运算符的优先级小于堆栈中运算符的优先级，
//则返回值为1，否则为0                          
int compare(char stack_o, char infix_o)
{
//在中序表示法队列和暂存堆栈中，运算符的优先级表，
//其优先级值为INDEX/2                               
    char infix_priority[9] ; 
	char stack_priority[8] ;
	int index_s=0, index_i=0;
	infix_priority[0]='q';infix_priority[1]=')';
	infix_priority[2]='+';infix_priority[3]='-';
	infix_priority[4]='*';infix_priority[5]='/';
	infix_priority[6]='^';infix_priority[7]=' ';
	infix_priority[8]='(';      
	stack_priority[0]='q';stack_priority[1]='(';
	stack_priority[2]='+';stack_priority[3]='-';
	stack_priority[4]='*';stack_priority[5]='/';
	stack_priority[6]='^';stack_priority[7]=' ';
	while (stack_priority[index_s] != stack_o)
		index_s++;
	while (infix_priority[index_i] != infix_o)
		index_i++;
	return ((int)(index_s/2) >= (int)(index_i/2) ? 1 : 0);
}
//中序转前序的方法
void infix_to_postfix()
{
	int rear=0, top=0, flag=0,i=0;
	char stack_t[MAX];  
	for (i=0; i<MAX; i++)
			stack_t[i]='\0';
	    gets(infix_q);
	    i=0;
	    while(infix_q[i]!='\0') 
	    {
          i++;
          rear++;
        }
		infix_q[rear] = 'q';  //在队列加入q为结束符号
		cout<<"\t"<<"后序表示法 : ";
		stack_t[top]  = 'q';  //在堆栈加入q为结束符号
		for (flag = 0; flag <= rear; flag++)\
        {		
			switch (infix_q[flag]) 
            {
				//输入为)时，则输出堆栈内的运算符，直到堆栈内为(
				case ')':
					while(stack_t[top]!='(') 			      
						cout<<setw(1)<<stack_t[top--];				   
					top--;
					break;
				//输入为q，则将堆栈内还未输出的运算符输出
				case 'q':
					while(stack_t[top]!='q')
						cout<<setw(1)<<stack_t[top--];
					break;
				//输入为运算符，若其优先级小于TOP在堆栈中所指运算符的优先级，
                //则将堆栈所指运算符输出，若优先级大于等于TOP在堆栈中所指运算符
                //的优先级，则将输入的运算符压入堆栈。 
				case '(':
				case '^':
				case '*':
				case '/':
				case '+':
				case '-': 
					while (compare(stack_t[top], infix_q[flag])==1)                       
						cout<<setw(1)<<stack_t[top--];			
					stack_t[++top] = infix_q[flag];
					break;
				//输入为操作数，则直接输出
				default :
					cout<<setw(1)<<infix_q[flag];
					break;
			}
		}
}
//主函数声明
int main (void) 		
{ 
    int i=0;
    for (i=0; i<MAX; i++)
	infix_q[i]='\0';	
	cout<<"\t=========================================="<<endl;
	cout<<"\t本程序会将其转成后序法表达式"<<endl;
    cout<<"\t请输入中序法表达式"<<endl;
    cout<<"\t例如:(9+3)*8+7*6-8/4 "<<endl;
    cout<<"\t可以使用的运算符包括:^,*,+,-,/,(,)等 "<<endl;
    cout<<"\t=========================================="<<endl;
    cout<<"\t请开始输入中序法表达式: ";
    infix_to_postfix();
    cout<<endl;
    cout<<"\t=========================================="<<endl;
    system("pause");      
    return 0; 
}
