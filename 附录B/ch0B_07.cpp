/*
	范例:ch0B_07.cpp
	说明:goto指令 
*/
#include<iostream>
using namespace std;
int main(void){
	
	for(int i=1;i<10; i++){
		for(int j=1; j<10; j++){
  			cout<<j<<"*"<<i<<"="<<i*j<<"\t";
     		if(i==5)goto down; //goto到down处 
  		}cout<<endl;
  	} 
	down: 
	cout<<"结束"<<endl;
	system("pause");
	return 0;
}
