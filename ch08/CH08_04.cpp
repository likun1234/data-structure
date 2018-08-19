#include <iostream>
#include <cstdlib>
#include <iomanip>
#define MAX 20
using namespace std;
int fib(int n)
{
    if(n==1 || n==0)
        return n;
    else
        return fib(n-1)+fib(n-2);
}
int fib_search(int data[MAX],int SearchKey)
{
    int index=2; 
    //쳲��������еĲ���
    while(fib(index)<=MAX)
        index++;
    index--;
    //index >=2
    //��ʼ��쳲�������
    int RootNode=fib(index);
    //��һ��쳲�������
    int diff1=fib(index-1); 
    //������쳲���������diff2=fib(index-2)
    int diff2=RootNode-diff1;
    RootNode--;	//������ʽ�����������±��Ǵ�0��ʼ��������
    while(1)
    {
       if(SearchKey==data[RootNode])
       {
          return RootNode;
       }
       else
       {
           if(index==2) return MAX; //û���ҵ�
           if(SearchKey<data[RootNode])
           {
              RootNode=RootNode-diff2;//����������쳲�������
              int temp=diff1;
              diff1=diff2;//��һ��쳲�������
              diff2=temp-diff2;//������쳲�������
              index=index-1;
           }
           else
           {
              if(index==3) return MAX;
              RootNode=RootNode+diff2;//����������쳲������� 
              diff1=diff1-diff2;//��һ��쳲�������
              diff2=diff2-diff1;//������쳲�������
              index=index-2;
           }         
       }
    }
}
int main(void)
{  
	int data[]={5,7,12,23,25,37,48,54,68,77,
                91,99,102,110,118,120,130,135,136,150};
    int val;
    int i=0;
    int j=0;
	while(1)
	{  
		cout<<"��������Ҽ�ֵ(1-150)������-1������";
		cin>>val;//������ҵ���ֵ
		if(val==-1)//����ֵΪ-1������ѭ��
			break;
		int RootNode=fib_search(data,val);//ʹ��쳲������Ѳ��ҷ���������
		if(RootNode==MAX)
			cout<<"##### û���ҵ�["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"�ڵ� "<<setw(2)<<RootNode+1
            <<"��λ���ҵ� ["<<setw(3)<<data[RootNode]<<"]"<<endl;
	}
	cout<<"�������ݣ�"<<endl;
	for(i=0;i<2;i++)
	{ 
		for(j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	system("pause");
	return 0;
}
