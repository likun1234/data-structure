/*
	范例:ch0B_11.cpp
	说明:输出指针变量的地址与取值 
*/
#include<iostream>
using namespace std;
int main(void){
	int x=100;
 	int* y;
  	y=&x;	//将x的地址赋值给指针变量y 
  	cout<<"x="<<x<<endl;;
    cout<<"x的地址="<<&x<<endl;			//利用&输出x的地址 
   	cout<<"y所记录的地址="<<y<<endl;		 
    cout<<"y所指向地址的值="<<*y<<endl;	//须加上*运算符才代表是数值
    system("pause");
	return 0;
}
