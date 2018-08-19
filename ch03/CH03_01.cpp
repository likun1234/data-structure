#include <iostream> 
#include <cstdlib>  
using namespace std;
                                        
int main()
{
 int *intptr = new int(50);
 //声明一指向整数的指针,在该内存中存入整数值50
 float *floatptr = new float;
 //声明一指向浮点数的指针,但未指定内存中存储的数据值
 cout << "intptr 指向的数据值：" << *intptr << "\n\n";
 *floatptr = 0.5;
 cout << "floatptr 指向的数据值：" << *floatptr << "\n\n";

	delete intptr;
	delete floatptr;
  
  system("pause");
  return 0;
}
