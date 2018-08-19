#include <iostream>        
#include <cstdlib> 

using namespace std;

int main(){
    int no,count=0, Total=0;   // 定义整数变量 count 与 Total
    cout<<"要输入计算的个数为:";
    cin>>no; 
    int *ptr=new int[no]; // 动态分配数组为n个元素 
    cout<<endl;	
    for (count=0; count < no; count++)	 
    {	 cout << "输入ptr[" << count << "]:";
   		 cin >> ptr[count];            // 采用数组下标来输入数组元素
    }
    for (count=0; count < no; count++)
         Total+=*(ptr+count);       // 采用指针变量运算来存取数组的元素值
    cout<<"---------------------------------------"<<endl;
    cout << no<<"个数的总和=" << Total;    // 显示结果
    cout << endl; 
    delete [] ptr;                // 释放分配给 ptr 的内存空间
    ptr=NULL;	     
    system("pause");
    return 0; 
 }

