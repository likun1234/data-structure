/*
	����:ch0B_12.cpp
	˵��:��̬�����ڴ� 
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(void){
	int num;
    srand(time(NULL));
    cout<<"����������Ĵ�С:";	 
    cin>>num;
   	int *a=new int[num];	//����ָ�����,ָ��̬������ڴ�
    for(int i=0;i<num;i++){	//�����������������ĳ�ʼֵ 
    	a[i]=rand()%101;
    }
	for(int i=0;i<num;i++){
    	cout<<a[i]<<" ";
    }
    cout<<endl;
    delete []a; 			//�ͷ�ָ��ָ����ڴ�
    system("pause");
	return 0;
}
