/*
	����:ch0B_05.cpp
	˵��:��switch..case���������������� 
*/
#include<iostream>
using namespace std;
int main(void){
 	int a,b;
 	cout<<"==============="<<endl;
 	cout<<"������������"<<endl;
	cout<<"��������������:"; 
 	cin>>a>>b;
 	cout<<"������Ҫ���е�����(+,-,*,/):";
 	char s;
  	cin>>s;
 	//switch��䲿�� 
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
     		cout<<"�������"<<endl;
			break;
   	} 
   	system("pause");
	return 0;
}
