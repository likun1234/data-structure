#include <iostream>
#include <iomanip>
using namespace std;

void select (int *); //���������ӳ���
void showdata (int *);//������ӡ�����ӳ���
int main(void)
{
	int data[6]={9,7,5,3,4,6};
	cout<<"ԭʼ����Ϊ��";
	showdata(data);
	select(data);
	system("pause");
	return 0;
}
void showdata (int data[])
{
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}

void select (int data[])
{
	for(int i=0;i<5;i++)    //ɨ��5��
	{   
		for(int j=i+1;j<6;j++)  //��i+1�Ƚ��𣬱Ƚ�5��
		{	
			if(data[i]>data[j])  //�Ƚϵ�i�͵�j��Ԫ��
			{	
				int tmp;
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;	
			}
		}
		cout<<"�� "<<i+1<<" ����������";
	    for (int k=0;k<6;k++)
			cout<<setw(3)<<data[k];    //��ӡ������
	    cout<<endl;
	}
	cout<<endl;
}
