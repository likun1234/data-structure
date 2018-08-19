/*
	范例:ch0B_04.cpp
	说明:使用条件运算符判断奇偶数 
*/
#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"请输入一个数字:";
    cin>>num;
    //条件运算符
    num%2==0 ? cout<<num<<"为偶数"<<endl:cout<<num<<"为奇数"<<endl;
    system("pause");
	return 0;
}
