/*
	范例:ch0B_16.cpp
	说明:派生类的声明与应用 
*/
#include<iostream>
// #include<string>
using namespace std;
class student{//基类 
	int num;
  	char name[20]; 
  	public :
  	void setdata(){
   		cout<<"座号:";cin>>num;
   		cout<<"姓名:";cin>>name;
    } 
    void show(){
    	cout<<name<<"的座号=\t"<<num<<endl; 
    } 
};
class s_health:public student{//s_health为派生类
	//没有定义派生类 
}; 
int main(void){
	s_health sh[5]; 
    for(int i=1; i<5; i++){
    	sh[i].setdata();//使用基类的方法 
    }cout<<endl;
    for(int j=1; j<5; j++){
    	sh[j].show();//使用基类的方法
    }
    cout<<endl;
    system("pause");
	return 0;
}
