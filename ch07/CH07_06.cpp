/*
[示范]:快速排序法
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void inputarr(int*,int);
void showdata(int*,int);
void quick(int*,int,int,int);
int process = 0;
int main(void)
{
	int size,data[100]={0};
	srand(time(NULL));
	cout<<"请输入数组大小(100以下)：";
	cin>>size;
	cout<<"随机生成的原始数据是：";
	inputarr (data,size);
	showdata (data,size);
	quick(data,size,0,size-1);
	cout<<"\n排序结果：";
	showdata(data,size);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)
		data[i]=(rand()%99)+1;
}
void showdata(int data[],int size)
{  
	int i;
	for (i=0;i<size;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void quick(int d[],int size,int lf,int rg)
{
	int tmp;
	int lf_idx;
	int rg_idx;
	int t;
    //1:第一项键值为d[lf]
	if(lf<rg)
	{
	  lf_idx=lf+1;
	  rg_idx=rg;
      while(1) {
	    cout<<"[处理过程"<<process++<<"]=> ";
        for(int t=0;t<size;t++)
			cout<<"["<<setw(2)<<d[t]<<"] ";
		cout<<endl;
		for(int i=lf+1;i<=rg;i++)//2:从左向右找出一个键值大于d[lf]者
		{
			if(d[i]>=d[lf])
			{
				lf_idx=i;
				break;
			}
			lf_idx++;
		}
		for(int j=rg;j>=lf+1;j--)//3:从右向左找出一个键值小于d[lf]者
		{
			if(d[j]<=d[lf]) 
			{
				rg_idx=j;
				break;
			}
			rg_idx--;
		}
		if(lf_idx<rg_idx)        //4-1:若lf_idx<rg_idx
		{					     
			tmp = d[lf_idx];       
			d[lf_idx] = d[rg_idx];//则d[lf_idx]和d[rg_idx]互换
			d[rg_idx] = tmp;      //然后继续排序 
        } else {
			break;    //否则跳出排序过程 
		} 
      }
		if(lf_idx>=rg_idx)       //5-1:若lf_idx大于等于rg_idx
		{                    //则将d[lf]和d[rg_idx]互换
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
                            //5-2:并以rg_idx为基准点分成左右两半
			quick(d,size,lf,rg_idx-1);  //以递归方式分别为左右两半进行排序
			quick(d,size,rg_idx+1,rg);  //直至完成排序
		}
	}
}
