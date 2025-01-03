#include <iostream>
#include <cfloat>
using namespace std;

void fibonacci_print(int z)
{ int a,b,c;
  a=0;
  b=1;
  cout<<"The required terms of Fibonacci series :"<<endl;
  cout<<a<<" "<<b<<" ";
  for(int i=0;i<z-2;i++)
  { c=a+b;
    cout<<c<<" ";
    a=b;
    b=c;
  }

}

int main()
{int num;
 cout<<"Enter no. o terms"<<endl;
 cin>>num;
 fibonacci_print(num);


}