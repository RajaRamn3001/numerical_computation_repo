#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double function(double value)
{
  return pow(value,2)-3*value+2;

}


double newton_rhapson(double initial_guess,double tolerance,double max_iter)
{  double root,dx=0.001,f,fx;
   for(int i=0;i<max_iter;i++)
   {  f=function(initial_guess);
      fx=(function(initial_guess+dx)-function(initial_guess))/dx;
      root=initial_guess-f/fx;
      if(fabs(root-initial_guess)<tolerance)
      {  return root;
         break;
      }

      initial_guess=root;
   }


return ;

}

int main()
{
double root,X0,tolerance,N;
X0=-50;
tolerance=10e-8;
N=1000;
root=newton_rhapson(X0,tolerance,N);
if(root==0)
{printf("unsuccessfull:max iteration exceeded");}
else
{printf("successfull:converged to root %lf",root);}


}