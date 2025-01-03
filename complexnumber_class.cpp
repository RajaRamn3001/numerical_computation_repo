#include <iostream>
#include <cfloat>
#include <cmath>
using namespace std;

class Complex_num {        // The class
  public:          // Access specifier
    float real;  // Attribute
    float img;  // Attribute

    Complex_num(float x,float y) { // Constructor with parameters
      real = x;
      img = y;
      
    }
    void disp()
    { if(img<0)
       {cout<<real<<"-i"<<-img<<endl;}
      else
       {cout<<real<<"+i"<<img<<endl;}
      
     }
    
    
};

Complex_num add_complex_num(Complex_num s1,Complex_num s2)
{ Complex_num s3(0,0);
  s3.real=s1.real+s2.real;
  s3.img=s1.img + s2.img;
  return s3;
}

Complex_num sub_complex_num(Complex_num s1,Complex_num s2)
{ Complex_num s3(0,0);
  s3.real=s1.real-s2.real;
  s3.img=s1.img - s2.img;
  return s3;
}

Complex_num multiply_complex_num(Complex_num s1,Complex_num s2)
{ Complex_num s3(0,0);
  s3.real=s1.real*s2.real-s1.img*s2.img;
  s3.img=s1.real*s2.img+s2.real*s1.img;
  
  return s3;
}

Complex_num conjugate_num(Complex_num s1)
{ 
  s1.real=s1.real;
  s1.img=-s1.img;
  return s1;
}
int main() {
  // Create Car objects and call the constructor with different values
  Complex_num z1(1.2,2.5);
  Complex_num z2(1.5,2.1);
  Complex_num z3(0,0);
  Complex_num z4(0,0);
  z3=sub_complex_num(z1,z2);
  z4=multiply_complex_num(z1,z2);
  // Print values
  cout <<"z1 ";
  z1.disp(); 
  cout <<"z2 ";
  z2.disp();
  cout <<"z1-z2=z3 ";
  z3.disp();
  cout <<"z1*z2=z4 ";
  z4.disp();
  z1=conjugate_num(z1);
  z2=conjugate_num(z2);
  z3=conjugate_num(z3);
  
  z1.disp();
  z2.disp();
  return 0;
}