/*
	����:ch0B_14.cpp
	˵��:�Զ����������� 
*/
#include<iostream>
#include<string>
using namespace std;
typedef double weight,tall; //�Զ�����������
//�ṹ����
struct student{				 
	int number;
 	int score;
	string name; 
	weight w;	//�����Զ�����������
	tall t;
};
int main(void){
	student s[4]={{1,100,"����ʫ"},	//�����ṹ���鲢��ʼ�� 
    			  {2,98,"������"},
	              {3,95,"��ǫ"},
   			      {4,92,"лܲ��"}}; 
 	cout<<"�������:"<<endl;
 	for(int j=0; j<4; j++){
  		cout<<s[j].name<<"\t["<<j+1<<"]�� ���=";
    	cin>>s[j].t;
    	cout<<"\t      ����=";
    	cin>>s[j].w;
   	}
    system("pause");
	return 0;
}
