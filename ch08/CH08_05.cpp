#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX = 10;   //��ϣ������Ԫ��
const int MAXNUM = 7;    //������ݸ���
int print_data(int *,int);
int creat_table(int ,int *);

int main(void)
{  
	int i,index[INDEXBOX],data[MAXNUM];
	srand(time(NULL));     //��ʱ���ʼ�������
	cout<<"ԭʼ����ֵ��\n";
	for(i=0;i<MAXNUM;i++)      //��ʼ����ֵ
		data[i]=rand()%20+1;
	for(i=0;i<INDEXBOX;i++)     //�����ϣ��
		index[i]=-1;
	print_data(data,MAXNUM);    //��ӡ��ʼ����
	cout<<"��ϣ�����ݣ�"<<endl;
	for(i=0;i<MAXNUM;i++)       //������ϣ��
	{  
		creat_table(data[i],index);
		cout<<data[i]<<" =>";  //��ӡ��һԪ�صĹ�ϣ��λ��
		print_data(index,INDEXBOX);
	}
	cout<<"��ɹ�ϣ��"<<endl;     
	print_data(index,INDEXBOX);  //��ӡ�����ɵĽ��
	system("pause");
	return 0;
}
int print_data(int *data,int max)  //��ӡ�����ӳ���
{  
	cout<<"\t";
	for(int i=0;i<max;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
}
int creat_table(int num,int *index)  //������ϣ���ӳ���
{  
	int tmp;
	tmp=num%INDEXBOX;    //��ϣ����=����%INDEXBOX
	while(1)
	{  
		if(index[tmp]==-1)      //������ݶ�Ӧ��λ���ǿյ�
		{  
			index[tmp]=num;     //��ֱ�Ӵ�������
			break;
		}
		else
			tmp=(tmp+1)%INDEXBOX;    //����������λ�ô��
	}
}
