/*
	范例:ch0B_06.cpp
	说明: do while循环练习 
*/
#include<iostream>
using namespace std;
int main(){
   	
   	cout<<"\tdo while部分\t"<<endl;
   	cout<<"================================="<<endl;
    int number,sum2=0;
   	do{
        sum2=0;
    	cout<<"数字0为结束程序,请输入数字: ";
    	cin>>number;
    	if (number==0){
     		cout<<"程序结束"<<endl;
     		break;
    	}
     	for(int k=1;k<=number;k++){
    		cout<<k;
      		if(k<number)cout<<"+";
     		sum2+=k;
      	}
    	cout<<"\n1~"<<number<<"的累加总数="<<sum2<<endl;
    }while(number!=0);/*do while循环结束*/
    system("pause");
	return 0;
}
