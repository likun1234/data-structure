/*
	����:ch0B_07.cpp
	˵��:gotoָ�� 
*/
#include<iostream>
using namespace std;
int main(void){
	
	for(int i=1;i<10; i++){
		for(int j=1; j<10; j++){
  			cout<<j<<"*"<<i<<"="<<i*j<<"\t";
     		if(i==5)goto down; //goto��down�� 
  		}cout<<endl;
  	} 
	down: 
	cout<<"����"<<endl;
	system("pause");
	return 0;
}
