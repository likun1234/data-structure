/*
	����:ch0B_06.cpp
	˵��: do whileѭ����ϰ 
*/
#include<iostream>
using namespace std;
int main(){
   	
   	cout<<"\tdo while����\t"<<endl;
   	cout<<"================================="<<endl;
    int number,sum2=0;
   	do{
        sum2=0;
    	cout<<"����0Ϊ��������,����������: ";
    	cin>>number;
    	if (number==0){
     		cout<<"�������"<<endl;
     		break;
    	}
     	for(int k=1;k<=number;k++){
    		cout<<k;
      		if(k<number)cout<<"+";
     		sum2+=k;
      	}
    	cout<<"\n1~"<<number<<"���ۼ�����="<<sum2<<endl;
    }while(number!=0);/*do whileѭ������*/
    system("pause");
	return 0;
}
