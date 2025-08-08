                                       #include <iostream>
#include <cfloat>
#include <cmath>
#include <fstream>
using namespace std;

double factt(int n)
{  if(n>1)
   {double z=n*factt(n-1); 
    return z;
   }
   else
   {
    return 1;   
   }
}
double to_radian(double angle)
{
const double pi=3.141592;
return angle*pi/180;
}
 
double any_func(double x)
{
return sin(x);    
}

double taylor_exp(double h,int terms)
{
double sum=0;
for(int i=0;i<terms;i++)
{
  sum+=pow(-1,i)*pow(h,2*i+1)/factt(2*i+1);   
}
 return sum;
}
double horner_sine( double x,int n) 
{   
    int c=n-1; 
    double result =pow(-1,c)/factt(2*n-1); // Initialize result 
    
    
    for (int i=2*n-2; i>=0; i--) 
      {   
         
         if(i%2==0)
         {
          result= result*x+0;
          
         }
         else
         { c--;
           result= result*x+pow(-1,c)/factt(i) ;
           
           
         }
        
      } 
      return result;
}  
 
int main()
{ofstream output("output.txt");
 double angle_rad=to_radian(30);
 double f_true=any_func(angle_rad);
 for(int i=1;i<8;i++)
 {
 double f_taylors_ex=taylor_exp(angle_rad,i);
 cout<<f_true<<" "<<f_taylors_ex<<" "<<fabs(f_true-f_taylors_ex)/f_true<<endl;
 }
 for(int i=1;i<8;i++)
 {
 double f_horner=horner_sine(angle_rad,i);
 cout<<f_true<<" "<<f_horner<<" "<<fabs(f_true-f_horner)/f_true<<endl;
 }

 output.close();
 
 

}