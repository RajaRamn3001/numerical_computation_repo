//finding solution of non-linear system of equations
// f(x)=0
//F={f1,f2,f3....fn},X={x1,x2,x3....xn} i.e X,F are n-dim vectors
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void gauss_elim(double array[][3],int m,int n)
{
    for(int i=0;i<m;i++)
   { for(int j=0;j<m;j++)
     {if(j>i)
      {float ratio=array[j][i]/array[i][i];
        
       for(int k=0;k<n+1;k++)
         {
         array[j][k]=array[j][k]-array[i][k]*ratio;
         }
      }
   
     }
    
   }

}

void backsubstitute(double array[],double aug_mat[][3],int m,int n)
{
for(int i=m-1;i>=0;i--)
{ 
  array[i]=aug_mat[i][n]/aug_mat[i][i];
 for(int j=n-1;j>i;j--)
  {array[i]-=aug_mat[i][j]/aug_mat[i][i]*array[j];
  
   
   
  }
    
}

}
void make_aug_mat(double aug_mat[][3],double J[][2],double F[],int m,int n)
{for(int i=0;i<m;i++)
  {for(int j=0;j<n+1;j++)
   {
    aug_mat[i][j]=J[i][j];
    if(j==n)
    {aug_mat[i][j]=-F[i];}

   }


  }
 

}

//2 variables x,y and 2 eqns f1=x+xy+4 and f2=x+y-3 

double f1(double x,double y)
{
  return x+x*y-4;
  
}
double f2(double x,double y)
{
  return x+y-3;
}


void make_jacobi(double J[][2],double x[],double dx[])
{ 
  J[0][0]=(f1(x[0]+dx[0],x[1])-f1(x[0],x[1]))/dx[0];
  J[0][1]=(f1(x[0],x[1]+dx[1])-f1(x[0],x[1]))/dx[1];
  J[1][0]=(f2(x[0]+dx[0],x[1])-f2(x[0],x[1]))/dx[0];
  J[1][1]=(f2(x[0],x[1]+dx[1])-f2(x[0],x[1]))/dx[1];
  

}




int main()
{
 int m=2;
 int iter=0;
 double X[]={1.98 , 1.02};
 double F[m];
 double dX[]={0.001 , 0.001};
 double jacobi[m][m];
 double aug_mat[m][m+1];
 double error_sqrsm;
 double tolerance;
 
 F[0]=f1(X[0],X[1]);
 F[1]=f2(X[0],X[1]);
 tolerance=10e-8;
 do
 { double delX[m];
   error_sqrsm=0;
   make_jacobi(jacobi,X,dX);
   //2.020000 1.980000 
   //1.000000 1.000000 
   make_aug_mat(aug_mat,jacobi,F,m,m);
   //2.020000 1.980000 7.999600 
   //1.000000 1.000000 0.000000 
   gauss_elim(aug_mat,m,m);
   for(int i=0;i<m;i++)
   //2.020000 1.980000 7.999600 
   //-0.000000 0.019802 -3.960198 
   backsubstitute(delX,aug_mat,m,m);
   printf("%lf %lf",delX[0]+X[0],delX[1]+X[1]);
   //-------------------------print jacobi
   
   //----------------------------------
   for (int i=0;i<m;i++)
   {
    error_sqrsm+=pow(delX[i],2);
   }
   printf("\n");
   if(sqrt(error_sqrsm)<tolerance)
   { 
    printf("successful");
    printf("%lf %lf",delX[0]+X[0],delX[1]+X[1]);
    break;
   }
   for (int i=0;i<m;i++)
   {
    X[i]=delX[i]+X[i];
   }
   F[0]=f1(X[0],X[1]);
   F[1]=f2(X[0],X[1]);
   iter++; 
 } while (iter<100);
 
 


}

