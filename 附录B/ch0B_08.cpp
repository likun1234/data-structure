/*
	范例:ch0B_08.cpp
	说明:声明数组 
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	int num[6];	//声明数组 
 	cout<<"大乐透彩选号"<<endl;
  	cout<<"请输入所选取的号码:(1~49)"<<endl;
   	for(int i=1; i<=6;i++){		//给数组赋值 
    	cout<<"号码["<<i<<"]=";
    	cin>>num[i];
 	} 
 	cout<<"你所选的号码为:"<<endl;
 	for(int i=1; i<=6; i++){	//输出数组 		
		cout<<num[i]<<"\t";
 	}
  	cout<<endl;
 	cout<<"计算机为您选的号码:"<<endl;
	srand(time(NULL));	
   	for(int j=1; j<=6; j++){
  		num[j]=1+rand()%49;
    	cout<<num[j]<<"\t";
  	}cout<<endl;
 	cout<<"祝您中奖"<<endl;
 	system("pause");
	return 0;
}
