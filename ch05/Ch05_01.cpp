#include <iostream>
using namespace std;

class tree //�ڵ�����ṹ����
{  
	public:
	int data; //�ڵ�����
	class tree *left,*right; //�ڵ���ָ�����ָ��
};
typedef class tree node;
typedef node *btree;
void Inorder(btree ptr);
int main(void)
{  
	int i,level;
	int data[]={0,6,3,5,9,7,8,4,2}; //ԭʼ����
	int btree[16]={0}; //��Ŷ�����������
	cout<<"ԭʼ�������ݣ�"<<endl;
	for (i=1;i<9;i++)
		cout<<"["<<data[i]<<"] ";
	cout<<endl;
	for(i=1;i<9;i++)   //��ԭʼ�����е�ֵ��һ�Ա�
	{  
		for(level=1;btree[level]!=0;)//�Ƚ������������ڵ�ֵ
		{  
			if(data[i]>btree[level]) //��������ڵ�ֵ���������������������Ƚ�
				level=level*2+1;
			else  //��������ڵ�ֵС�ڻ���������������������Ƚ�
				level=level*2;
		}         //��������ڵ��ֵ��Ϊ0�������������ڵ�ֵ�Ƚ�һ��
		btree[level]=data[i];        //������ֵ���������
	}
	cout<<"���������ݣ�"<<endl;
	for (i=1;i<16;i++)
		cout<<"["<<btree[i]<<"] ";
	cout<<endl;
	system("pause");
	return 0;
}
void Inorder(btree ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->left); //����������
		cout<<"["<<ptr->data<<"]"; //��������ӡ����
		Inorder(ptr->right); //����������
	}
}
