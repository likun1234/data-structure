/*
[ʾ��]:ϣ������
*/
#include <iostream>
#include <iomanip>
#define SIZE 8		//��������С
using namespace std;

void shell (int *,int);  	//���������ӳ���
void showdata (int *);  //������ӡ�����ӳ���
void inputarr (int *,int);	//�������������ӳ���
int main(void)
{ 
	int data[SIZE];
	inputarr(data,SIZE);
	cout<<"�������ԭʼ�����ǣ�";
	showdata(data);
	shell(data,SIZE);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)
	{ 
		cout<<"������� "<<i+1<<" ��Ԫ�أ�";
		cin>>data[i];
	}
}
void showdata(int data[])
{  	
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void shell(int data[],int size)
{  
	int i;        //iΪɨ�����
	int j;        //��j����λ�Ƚϵ�Ԫ��
	int k=1;      //k��ӡ����
	int tmp;      //tmp�����ݴ�����
	int jmp;      //�趨���λ����
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  //��������
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		cout<<"�� "<<k++<<" ������";
		showdata (data);
		jmp=jmp/2;    //����ѭ����
	}
}
