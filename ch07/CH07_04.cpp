/*
[ʾ��]:��������
*/
#include <iostream>
#include <iomanip>
#define SIZE 6  //���������С
using namespace std;

void inser (int *);		//�������������ӳ���
void showdata (int *);	//������ӡ�����ӳ���
void inputarr (int *,int);	//�������������ӳ���
int  main(void)
{ 
	int data[SIZE];
	inputarr(data,SIZE);	//���������������С�����ӳ���
	cout<<"�������ԭʼ�����ǣ�";
	showdata (data);
	inser(data);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)	//����ѭ��������������
	{ 
		cout<<"������� "<<i+1<<" ��Ԫ�أ�";
		cin>>data[i];
	}
}
void showdata(int data[])
{  
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];	//��ӡ��������
	cout<<endl;
}
void inser(int data[])
{  
	int i;     //iΪɨ�����
	int j;     //��j����λ�Ƚϵ�Ԫ��
	for (i=1;i<SIZE;i++)  //ɨ��ѭ������ΪSIZE-1
	{  
 		int tmp;   //tmp�����ݴ�����
		tmp=data[i];
        j=i-1;
	    while (j>=0 && tmp<data[j])  //����ڶ�Ԫ��С�ڵ�һԪ��
		{							 
			data[j+1]=data[j];		//�Ͱ�����Ԫ��������һ��λ��		
			j--;
		}
		data[j+1]=tmp;              //��С��Ԫ�طŵ���һ��Ԫ��	
		cout<<"�� "<<i<<" ��ɨ�裺";
		showdata(data);
	}
}
