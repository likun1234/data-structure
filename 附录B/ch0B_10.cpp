/*
	����:ch0B_10.cpp
	˵��:��ַ���� 
*/
#include<iostream>
using namespace std;
int sum(int &,int&);//��ַ���� 
int main(void){
	int main_a,main_b;
	cout<<"��������������:";
 	cin>>main_a>>main_b; 
 	cout<<"����ǰ:"<<endl;
 	cout<<"main_a="<<main_a<<"\t"<<"main_b="<<main_b<<endl;
 	cout<<main_a<<"+"<<main_b<<"="<<sum(main_a,main_b)<<endl;	//���ú��� 
 	cout<<"���ú�:"<<endl;
 	cout<<"main_a="<<main_a<<"\t"<<"main_b="<<main_b<<endl;
 	system("pause");
	return 0;
}
int sum(int &a,int &b){
	int sum = a+b;
	int temp; 
	//����a��bֵ 
 	temp=a;
 	a=b;
	b=temp;
	cout<<"������\na="<<a<<"\t"<<"b="<<b<<endl;
	return sum; 
}
