/*
	范例:ch0B_14.cpp
	说明:自定义数据类型 
*/
#include<iostream>
#include<string>
using namespace std;
typedef double weight,tall; //自定义数据类型
//结构内容
struct student{				 
	int number;
 	int score;
	string name; 
	weight w;	//声明自定义数据类型
	tall t;
};
int main(void){
	student s[4]={{1,100,"李奕诗"},	//声明结构数组并初始化 
    			  {2,98,"李奕萱"},
	              {3,95,"罗谦"},
   			      {4,92,"谢懿柔"}}; 
 	cout<<"身体检查表:"<<endl;
 	for(int j=0; j<4; j++){
  		cout<<s[j].name<<"\t["<<j+1<<"]号 身高=";
    	cin>>s[j].t;
    	cout<<"\t      体重=";
    	cin>>s[j].w;
   	}
    system("pause");
	return 0;
}
