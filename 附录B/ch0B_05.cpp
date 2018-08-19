/*
	范例:ch0B_05.cpp
	说明:以switch..case进行整数四则运算 
*/
#include<iostream>
using namespace std;
int main(void){
 	int a,b;
 	cout<<"==============="<<endl;
 	cout<<"整数四则运算"<<endl;
	cout<<"请输入两个数字:"; 
 	cin>>a>>b;
 	cout<<"请输入要进行的运算(+,-,*,/):";
 	char s;
  	cin>>s;
 	//switch语句部分 
    switch(s){
   		case '+':
			cout<<a<<"+"<<b<<"="<<a+b<<endl;
			break;
     	case '-':
     		cout<<a<<"-"<<b<<"="<<a-b<<endl;
			break;
      	case '*': 
      		cout<<a<<"*"<<b<<"="<<a*b<<endl;
			break;
    	case '/':
    		cout<<a<<"/"<<b<<"="<<a/b<<endl;
			break;
     	default:
     		cout<<"输入错误"<<endl;
			break;
   	} 
   	system("pause");
	return 0;
}
