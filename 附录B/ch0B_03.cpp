/*
	范例:ch0B_03.cpp
	说明:示范从外部键盘输入数值 
*/ 
#include<iostream>
using namespace std;
int main(void){
	int score;
	cout<<"请输入成绩:";		//输出 
	cin>>score;				//输入 
	cout<<"你输入的分数为:\t"<<score<<endl; 
	system("pause");
	return 0;
}
