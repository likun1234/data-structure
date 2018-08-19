/*
[示范]:直接合并排序法
       数据文件名：data1.txt,data2.txt，合并后的文件：data.txt
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void merge(ofstream& fp, ifstream& fp1, ifstream& fp2)
{  
    char n1,n2;
    char txt1[40];
    char txt2[40];
	fp1>>n1;
	fp2>>n2;
	while(fp1.eof()==0 && fp2.eof()==0)
	{  
		if (n1 <= n2)
		{  
            fp.put(n1);   
			fp1>>n1;	/*接着读下一项 n1 的数据*/
		}
		else
		{  
            fp.put(n2);/*如果n2比较小，则把n2存到fp里*/
			fp2>>n2;  /*接着读下一项 n2的数据*/
		}
	}
	if(fp1.eof())	/*如果其中一个数据文件已读取完毕，经判断后*/
	{ 
       /*把另一个数据文件内的数据全部放到fp里*/
		while (!fp2.eof())
		{  
            fp2>>n2;
			fp.put(n2);
		}
	}
	else if (fp2.eof())
	{ 
		while(!fp1.eof())
		{             
            fp1>>n1;
			fp.put(n1);
		}
	}	 
}
int main(void)
{  
	char txt[40];;
	ofstream fp;
	ifstream fp1,fp2;
	ifstream f,f1,f2;
	fp.open("data.txt",ios::out);
	fp1.open("data1.txt",ios::in);
	fp2.open("data2.txt",ios::in);
	if(!fp.is_open())
		cout<<"打开主文件失败"<<endl;
	else if(!fp1.is_open())
		cout<<"打开数据文件 1 失败"<<endl;
	else if(!fp2.is_open())
		cout<<"打开数据文件 2 失败"<<endl;
	else
	{  
		cout<<"数据排序中......"<<endl;
        merge(fp,fp1,fp2);
		cout<<"数据处理完成!!"<<endl;
	}
	fp.close();
	fp1.close();
	fp2.close();
	cout<<"data1.txt数据内容为："<<endl;
	f1.open("data1.txt",ios::in);
	while(!f1.eof()) 
	{  
		f1>>txt;
		cout<<txt<<endl;
	}
	cout<<"data2.txt数据内容为："<<endl;
	f2.open("data2.txt",ios::in);
	while(!f2.eof())
	{  
		f2>>txt;
		cout<<txt<<endl;
	}
	cout<<"排序后data.txt数据内容为："<<endl;
	f.open("data.txt",ios::in);
	while(!f.eof())
	{  
		f>>txt;
		cout<<txt<<endl;
	}
	cout<<endl;
	f.close();
	f1.close();
	f2.close();
	system("pause");
	return 0;
}
