#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
	int data[6]={6,5,9,7,2,8};	// ԭʼ���� 
	cout<<"ð�����򷨣�\nԭʼ����Ϊ��";
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;

	for (int i=5;i>0;i--)// ɨ����� 
	{
		for (int j=0;j<i;j++)//�Ƚϡ���������
		{
			if (data[j]>data[j+1])// �Ƚ��������������һ�����ϴ��򻥻� 
			{
				int tmp;
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
		cout<<"�� "<<6-i<<" �������Ľ���ǣ�"; //�Ѹ���ɨ���Ľ����ӡ����
		for (int j=0;j<6;j++)
			cout<<setw(3)<<data[j];
		cout<<endl;
	}
	cout<<"�������Ϊ��";
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
	system("pause");
	return 0;
}
