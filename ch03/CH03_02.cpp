#include <iostream>        
#include <cstdlib> 

using namespace std;

int main(){
    int no,count=0, Total=0;   // ������������ count �� Total
    cout<<"Ҫ�������ĸ���Ϊ:";
    cin>>no; 
    int *ptr=new int[no]; // ��̬��������Ϊn��Ԫ�� 
    cout<<endl;	
    for (count=0; count < no; count++)	 
    {	 cout << "����ptr[" << count << "]:";
   		 cin >> ptr[count];            // ���������±�����������Ԫ��
    }
    for (count=0; count < no; count++)
         Total+=*(ptr+count);       // ����ָ�������������ȡ�����Ԫ��ֵ
    cout<<"---------------------------------------"<<endl;
    cout << no<<"�������ܺ�=" << Total;    // ��ʾ���
    cout << endl; 
    delete [] ptr;                // �ͷŷ���� ptr ���ڴ�ռ�
    ptr=NULL;	     
    system("pause");
    return 0; 
 }

