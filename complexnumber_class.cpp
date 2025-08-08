#include <iostream>
#include <cfloat>
#include <cmath>
using namespace std;

class Complex_num {        // The class
  public:          // Access specifier
    float real;  // Attribute
    float img;  // Attribute

    void assign(float x,float y) 
    { // Constructor with parameters
      real = x;
      img = y;
      
    }
    void disp()
    { if(img<0)
       {cout<<real<<"-i"<<-img<<endl;}
      else
       {cout<<real<<"+i"<<img<<endl;}
    }

    void conjugate()
    {
     real=real;
     img=-img; 
    }
    
    
};

Complex_num add_complex_num(Complex_num s1,Complex_num s2)
{ Complex_num s3;
  s3.real=s1.real+s2.real;
  s3.img=s1.img + s2.img;
  return s3;
}

Complex_num sub_complex_num(Complex_num s1,Complex_num s2)
{ Complex_num s3;
  s3.real=s1.real-s2.real;
  s3.img=s1.img - s2.img;
  return s3;
}

Complex_num multiply_complex_num(Complex_num s1,Complex_num s2)
{ Complex_num s3;
  s3.real=s1.real*s2.real-s1.img*s2.img;
  s3.img=s1.real*s2.img+s2.real*s1.img;
  
  return s3;
}

Complex_num div_complex_num(Complex_num s1,Complex_num s2)
{ Complex_num s3;
  float s4=pow(s2.real,2)+pow(s2.img,2);
  s2.conjugate();
  s3=multiply_complex_num(s1,s2);
  s3.real=s3.real/s4;
  s3.img=s3.img/s4;
  
  return s3;
}



int main() {
  // Create Car objects and call the constructor with different values
  Complex_num z1;
  Complex_num z2;
  z1.assign(1.2,1.0);
  z2.assign(2.4,1.3);
  Complex_num z3;
  Complex_num z4;
  Complex_num z5;

  z3=sub_complex_num(z1,z2);
  z4=multiply_complex_num(z1,z2);
  z5=div_complex_num(z1,z2);
  // Print values
  cout <<"z1 ";
  z1.disp(); 
  cout <<"z2 ";
  z2.disp();
  cout <<"z1-z2=z3 ";
  z3.disp();
  cout <<"z1*z2=z4 ";
  z4.disp();
   cout <<"z1/z2=z5 ";
  z5.disp();
  z1.conjugate();
  z2.conjugate();
  z3.conjugate();
  
  z1.disp();
  z2.disp();
  return 0;
}