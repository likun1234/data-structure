/*
	范例:ch0B_09.cpp
	说明:C++语言的字符串格式 
*/
#include<iostream>
#include<string>
using namespace std;
int main(void){
	string str1="C++语言的字符串格式"; 
	char str2[]={"C语言的字符串格式"};
 	string str;
  	str=str1+"+"+str2;//直接利用+运算符进行字符串连接的操作 
   	cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str<<endl; 
    system("pause");
	return 0;
}
