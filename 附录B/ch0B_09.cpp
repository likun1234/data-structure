/*
	����:ch0B_09.cpp
	˵��:C++���Ե��ַ�����ʽ 
*/
#include<iostream>
#include<string>
using namespace std;
int main(void){
	string str1="C++���Ե��ַ�����ʽ"; 
	char str2[]={"C���Ե��ַ�����ʽ"};
 	string str;
  	str=str1+"+"+str2;//ֱ������+����������ַ������ӵĲ��� 
   	cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str<<endl; 
    system("pause");
	return 0;
}
