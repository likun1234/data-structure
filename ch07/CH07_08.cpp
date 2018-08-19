/*
[ʾ��]:��������
*/
// �������� ��С�������� 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void radix (int *,int);		// ���������ӳ��� 
void showdata (int *,int);
void inputarr (int *,int);
int main(void)
{ 
	int size,data[100]={0};
	cout<<"�����������С(100����)��";
	cin>>size;
	cout<<"���ɵ���������ǣ�"<<endl;
	inputarr (data,size);
	showdata (data,size);
	radix (data,size);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	srand(time(NULL));
	for (int i=0;i<size;i++)
		data[i]=(rand()%999)+1;		// ����data ֵ���Ϊ 3 λ�� 
}
void showdata(int data[],int size)
{  
	for (int i=0;i<size;i++)
		cout<<setw(5)<<data[i];
	cout<<endl;
}
void radix(int data[],int size)
{  
	for (int n=1;n<=100;n=n*10)	// nΪ�������Ӹ�λ����ʼ���� 
	{  
		int tmp[10][100]={0};	// �����ݴ����飬[0~9λ��][���ݸ���]���������ݾ�Ϊ0 
		for (int i=0;i<size;i++)	// �Ա��������� 
		{  
			int m=(data[i]/n)%10;	// mΪnλ����ֵ���� 36ȡʮλ�� (36/10)%10=3 
			tmp[m][i]=data[i];		// ��data[i]��ֵ�ݴ���tmp �� 
		}
		int k=0;
		for (int i=0;i<10;i++)
		{  
			for(int j=0;j<size;j++)
			{  
				if(tmp[i][j] != 0)		// ��һ��ʼ���� tmp ={0}���ʲ�Ϊ0�߼�Ϊ 
				{  
					data[k]=tmp[i][j];	// data�ݴ��� tmp ���ֵ����tmp ���ֵ��
					k++;		        // ��data[ ]�� 
				}
			}
		}
		cout<<"����"<<setw(3)<<n<<"λ�������";
		showdata(data,size);
	} 
}
