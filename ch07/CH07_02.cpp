#include <iostream>
#include <iomanip>
using namespace std;
void bubble (int *);   //����ð�������ӳ���
void showdata (int *); //������ӡ�����ӳ���
int main(void)
{
	int data[6]={4,6,2,7,8,9};	  //ԭʼ����
	cout<<"�Ľ�ð������\nԭʼ����Ϊ��\t";
	showdata(data);
	bubble(data);
	system("pause");
	return 0;
}
void showdata (int data[])     //����ѭ����ӡ����
{
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void bubble (int data[])
{
	for(int i=5;i>=0;i--)
	{
		int flag=0;           //flag�����ж��Ƿ�ִ���˻����Ĳ���
		for (int j=0;j<i;j++)
		{
			if (data[j+1]<data[j])
			{
				int tmp;
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;    //���ִ�й���������flag��Ϊ0
			}
		}
		if (flag==0)
			break;
		/*
		��ִ����һ��ɨ����ж��Ƿ�ִ�й������Ĳ��������û�л��������ݣ�
        ���ʾ��ʱ������������򣬹ʿ�ֱ������ѭ��
		*/
		cout<<"�� "<<6-i<<" ������\t";
		for (int j=0;j<6;j++)
			cout<<setw(3)<<data[j];
		cout<<endl;		    
	}
	cout<<"�������Ϊ��\t";
	showdata (data);
}
