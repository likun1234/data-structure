#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main(void)
{  
	int i,j,val=0,data[80]={0};
	for (i=0;i<80;i++)
		data[i]=(rand()%150+1);
	while (val!=-1)
	{  
		int find=0;
		cout<<"��������Ҽ�ֵ(1-150)������-1�뿪��";
		cin>>val;
		for (i=0;i<80;i++)
		{  
			if(data[i]==val)
			{  
				cout<<"�ڵ� "<<setw(3)<<i+1<<"��λ���ҵ���ֵ ["<<data[i]<<"]"<<endl;
				find++;
			}
		}
		if(find==0 && val !=-1)
			cout<<"######û���ҵ� ["<<val<<"]######"<<endl;
	}
	cout<<"�������ݣ�"<<endl;
	for(i=0;i<10;i++)
	{ 
		for(j=0;j<8;j++)
			cout<<setw(2)<<i*8+j+1<<"["<<setw(3)<<data[i*8+j]<<"]  ";
		cout<<endl;
	}
	system("pause");
	return 0;
}
