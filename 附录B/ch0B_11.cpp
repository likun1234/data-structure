/*
	����:ch0B_11.cpp
	˵��:���ָ������ĵ�ַ��ȡֵ 
*/
#include<iostream>
using namespace std;
int main(void){
	int x=100;
 	int* y;
  	y=&x;	//��x�ĵ�ַ��ֵ��ָ�����y 
  	cout<<"x="<<x<<endl;;
    cout<<"x�ĵ�ַ="<<&x<<endl;			//����&���x�ĵ�ַ 
   	cout<<"y����¼�ĵ�ַ="<<y<<endl;		 
    cout<<"y��ָ���ַ��ֵ="<<*y<<endl;	//�����*������Ŵ�������ֵ
    system("pause");
	return 0;
}
