#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//ODE :(1+y)y'=x^2
double a=0;
double b=1;
double dx=0.05;
double yo[5]={0,1,2,0,1};

double f_xy(double x,double y,int i)
{ double f[5];
  f[0]=pow(x,2)/(1+pow(y,2));
  f[1]=-y;
  f[2]=y-x;
  f[3]=1+pow(y,2);
  f[4]=(6*x+1)/2;
  return f[i];
}


void eulermethod(double y[],double a,double del_x,int n,int v)
{ 
  for(int i=1;i<n;i++)
  {
    y[i]=y[i-1]+del_x*f_xy(a+(i-1)*del_x,y[i-1],v);
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
eulermethod(y,a,dx,n,0);
printf("y(x=1)=%lf",y[n-1]);

}
