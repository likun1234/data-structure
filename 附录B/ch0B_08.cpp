/*
	����:ch0B_08.cpp
	˵��:�������� 
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	int num[6];	//�������� 
 	cout<<"����͸��ѡ��"<<endl;
  	cout<<"��������ѡȡ�ĺ���:(1~49)"<<endl;
   	for(int i=1; i<=6;i++){		//�����鸳ֵ 
    	cout<<"����["<<i<<"]=";
    	cin>>num[i];
 	} 
 	cout<<"����ѡ�ĺ���Ϊ:"<<endl;
 	for(int i=1; i<=6; i++){	//������� 		
		cout<<num[i]<<"\t";
 	}
  	cout<<endl;
 	cout<<"�����Ϊ��ѡ�ĺ���:"<<endl;
	srand(time(NULL));	
   	for(int j=1; j<=6; j++){
  		num[j]=1+rand()%49;
    	cout<<num[j]<<"\t";
  	}cout<<endl;
 	cout<<"ף���н�"<<endl;
 	system("pause");
	return 0;
}
