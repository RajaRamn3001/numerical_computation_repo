#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//ODE :(1+y)y'=x^2
double a=0;
double b=1;
double dx=0.01;
double yo[5]={0,1,2,0,1};
double initial_guess=0;
double tolerance=1e-6;

double f_xy(double x,double y,int i)
{ double f[5];
  f[0]=pow(x,2)/(1+pow(y,2));
  f[1]=-y;
  f[2]=y-x;
  f[3]=1+pow(y,2);
  f[4]=(6*x+1)/2;
  return f[i];
}

void heun(double *w1,double *w2,double *alpha,double *beta)
{*w1=0.5,*w2=0.5,*alpha=1,*beta=1;
}

void midpoint(double *w1,double *w2,double *alpha,double *beta)
{*w1=0,*w2=1,*alpha=0.5,*beta=0.5;
}
void ralston(double *w1,double *w2,double *alpha,double *beta)
{*w1=0.33,*w2=0.66,*alpha=0.75,*beta=0.75;
}

void rk2(double y[],double a,double del_x,int n,int v)
{ double error;
  double w1=0,w2=0,alpha=0,beta=0,k1,k2;
  ralston(&w1,&w2,&alpha,&beta);
  printf("%lf %lf %lf %lf \n",w1,w2,alpha,beta); 
  for(int i=1;i<n;i++)
  { 
     k1=f_xy(a+(i-1)*del_x,y[i-1],v);
     k2=f_xy(a+(i-1)*del_x +del_x*alpha,y[i-1]+del_x*beta*k1,v);
     y[i]=y[i-1]+del_x*(w1*k1+w2*k2);
    
    
  }
 
 
}

void putboundary(double y[],double y_0[],int i)
{
  y[0]=y_0[i];

}

int main(){
FILE *fp;
int n=fabs(a-b)/dx +1;
double y[n];
putboundary(y,yo,0);
rk2(y,a,dx,n,0);
printf("y(x=1)=%lf",y[n-1]);


}