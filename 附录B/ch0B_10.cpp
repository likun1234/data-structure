/*
	范例:ch0B_10.cpp
	说明:传址函数 
*/
#include<iostream>
using namespace std;
int sum(int &,int&);//传址函数 
int main(void){
	int main_a,main_b;
	cout<<"请输入两个数字:";
 	cin>>main_a>>main_b; 
 	cout<<"调用前:"<<endl;
 	cout<<"main_a="<<main_a<<"\t"<<"main_b="<<main_b<<endl;
 	cout<<main_a<<"+"<<main_b<<"="<<sum(main_a,main_b)<<endl;	//调用函数 
 	cout<<"调用后:"<<endl;
 	cout<<"main_a="<<main_a<<"\t"<<"main_b="<<main_b<<endl;
 	system("pause");
	return 0;
}
int sum(int &a,int &b){
	int sum = a+b;
	int temp; 
	//调换a与b值 
 	temp=a;
 	a=b;
	b=temp;
	cout<<"函数内\na="<<a<<"\t"<<"b="<<b<<endl;
	return sum; 
}
