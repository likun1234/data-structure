#include <iostream> 
#include <cstdlib>  
using namespace std;
                                        
int main()
{
 int *intptr = new int(50);
 //����һָ��������ָ��,�ڸ��ڴ��д�������ֵ50
 float *floatptr = new float;
 //����һָ�򸡵�����ָ��,��δָ���ڴ��д洢������ֵ
 cout << "intptr ָ�������ֵ��" << *intptr << "\n\n";
 *floatptr = 0.5;
 cout << "floatptr ָ�������ֵ��" << *floatptr << "\n\n";

	delete intptr;
	delete floatptr;
  
  system("pause");
  return 0;
}
