/*
[ʾ��]:ʹ�����ھ�������ʾ����ͼ
*/
#include <iostream>
using namespace std;
int  main(void)
{  
	int arr[5][5],i,j; //��������arr
	int data[5][2]={{1,2},{2,1},{2,3},{2,4},{4,3}};//ͼ�θ��ߵ����ֵ���յ�ֵ
	for (i=0;i<5;i++)//�Ѿ�����Ϊ0
		for (j=0;j<5;j++)
			arr[i][j]=0;
	for (i=0;i<5;i++) //��ȡͼ������
		for (j=0;j<5;j++) //����arr����
		{  
			int tmpi,tmpj;
			tmpi=data[i][0];//tmpiΪ��ʼ����
			tmpj=data[i][1];//tmpjΪ��ֹ����
			arr[tmpi][tmpj]=1;//�бߵĵ�����1
		}
	cout<<"����ͼ����"<<endl;
	for (i=1;i<5;i++)
	{  
		for (j=1;j<5;j++)
	    cout<<"["<<arr[i][j]<<"] ";//��ӡ��������
		cout<<endl;
	}
	system("pause");
}
