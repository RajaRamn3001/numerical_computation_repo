#include <bits/stdc++.h>
using namespace std;
double func_tion(double value,int *func_eval)
{ *func_eval=*func_eval+3;
  return pow(value,3)-2*value-5;
 
}
 
 
double newton_rhapson(double initial_guess,double tolerance,int max_iter)
{  double root,dx=0.001,f,fx;
   int function_eval=0;
   for(int i=0;i<max_iter;i++)
   {  
      f=func_tion(initial_guess,&function_eval);
      fx=(func_tion(initial_guess+dx,&function_eval)-func_tion(initial_guess-dx,&function_eval))/(2*dx);
      root=initial_guess-f/fx;
      function_eval+=1;
      cout<<i<<" "<<initial_guess<<" "<<fabs(f/fx)<<endl;
      if(fabs(root-initial_guess)<tolerance)
      {  
         cout<<"No. of arithmatic operation is "<<function_eval<<endl;
         return root;
         break;
      }
 
      initial_guess=root;
   }
 
   
return 0;
 
}
 
int main()
{
double root,X0,tolerance,N;
X0=10;
tolerance=10e-8;
N=1000;
cout<<"Initial guess"<<" "<<X0<<endl;
cout<<"Tolerance"<<" "<<tolerance<<endl;
cout<<"Maximum iteration"<<" "<<N<<endl;
 
root=newton_rhapson(X0,tolerance,N);
if(root==0)
{printf("unsuccessfull:max iteration exceeded");}
else
{printf("successfull:converged to root %lf",root);}
 
 
}