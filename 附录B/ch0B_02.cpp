/*
	范例:ch0B_02.cpp
	说明:说明全局常数 
*/
#include<iostream>
using namespace std;
const double PI=3.14159; //说明全局常数PI 
int main(void){
	cout<<"请输入圆的半径(厘米):";
	int r;
 	cin>>r;
  	cout<<"半径="<<r<<"的圆面积为:"<<r*r*PI<<"平方厘米"<<endl; 
  	system("pause");
	return 0;
}
