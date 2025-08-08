//finding solution of non-linear system of equations
// f(x)=0
//F={f1,f2,f3....fn},X={x1,x2,x3....xn} i.e X,F are n-dim vectors
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> gauss_elimination(vector<vector<double>> Augmat)
{
  for(int i=0;i<Augmat.size();i++)
   { int g;//g=stores row index of greatest element in ith column
     double max_ele;//stores the greatest element in ith column
     g=i;//default row index
     max_ele=Augmat[i][i];//default largest element in ith column
     //This loop will search for greatest element in ith column
     for(int j=0;j<Augmat.size();j++)
      {if(max_ele<Augmat[j][i]&&j>i)
        {
           g=j;
           max_ele=Augmat[j][i]; 
        }
      }
      //This loop will exchange rows of gth and ith row 
      for(int k=0;k<Augmat[i].size();k++)
      {double dummy;
       dummy=Augmat[i][k];
       Augmat[i][k]=Augmat[g][k];
       Augmat[g][k]=dummy;

      }
    //   cout<<"Partial pivoting of "<<i+1<<"th column"<<endl;
    //   show(Augmat);
    
    
    for(int j=0;j<Augmat.size();j++)
     {
      if(j>i)
      {
        
        double ratio=Augmat[j][i]/Augmat[i][i];
        
          for(int k=0;k<Augmat[i].size();k++)
          {
            Augmat[j][k]=Augmat[j][k]-Augmat[i][k]*ratio;
          }
      }
   
     }
    //  cout<<"Elimination of "<<i+1<<"th column"<<endl;
    //  show(Augmat);
     
    
   }


 return Augmat;
}

vector<vector<double>> back_substitute(vector<vector<double>> Augmat)
{
  vector<vector<double>> soln;
  int m=Augmat.size();
  int n=Augmat[0].size();
  soln.resize(Augmat.size(), vector<double>(1));
  
  for(int i=m-1;i>=0;i--)
  { 
  soln[i][0]=Augmat[i][n-1]/Augmat[i][i];
  
  for(int j=n-2;j>i;j--)
  { 
    soln[i][0]-=Augmat[i][j]/Augmat[i][i]*soln[j][0];
    
  
  }
   
    
  }

 return soln;
}

vector<vector<double>> form_augment(vector<vector<double>> A,vector<vector<double>> B)
{ 
  vector<vector<double>> AB;
  if(A.size()==B.size())
  { 
    AB.resize(A.size(), vector<double>(A[0].size()+B[0].size()));
    for (int i = 0; i < AB.size(); i++) 
    {
        for (int j = 0; j < AB[i].size(); j++) 
        {
            AB[i][j]=A[i][j];
            if(j>=A[i].size())
            {
              AB[i][j]=B[i][j-A[i].size()];  
            }
        }
        
    }
    return AB;
    
  }

}
//2 variables x,y and 2 eqns f1=x+xy+4 and f2=x+y-3 

vector<vector<double>> f1(double x,double y,double z,int i)
{ ff.resize(3, vector<double>(1));;
  ff[0][0]= exp(x)-8*x*sin(y);
  ff[1][0]=x+y-1;
  ff[2][0]= pow(z-1,3);
  return ff[i];
}


vector<vector<double>> make_jacobi(vector<vector<double>> J,vector<double> x,vector<double> dx)
{int a,b,c;
 for(int i=0;i<J.size();i++)
 {for(int j=0;j<J.size();j++)
  {a=0,b=0,c=0;
   switch (j)
   {
   case 0:
    a=1;
    break;
   case 1:
    b=1;
    break;
   case 2:
    c=1;
    break;
  
   default:
    a=0,b=0,c=0;
    break;
   }
  J[i][j]=(f1(x[0]+a*dx[j],x[1]+b*dx[j],x[2]+c*dx[j],i)-f1(x[0]-a*dx[j],x[1]-b*dx[j],x[2]-c*dx[j],i))/(2*dx[j]);
  //printf("%d %d %d \n",a,b,c);
  }
 }
  
  

}


vector<double> dX={0.0001 , 0.0001, 0.00001};
vector<double> X={0.1,0.5,0.5};
int N=1000;
int main()
{FILE *fp=fopen("Output_problem_4.txt","w");
 int m=3;
 int iter=1;
 
 double F[m];
 
 vector<vector<double>> jacobi;
 double aug_mat[m][m+1];
 double error_sqrsm;
 double tolerance;
 
 F[0]=f1(X[0],X[1],X[2],0);
 F[1]=f1(X[0],X[1],X[2],1);
 F[2]=f1(X[0],X[1],X[2],2);
 //printf("%lf %lf %lf \n",F[0],F[1],F[2]);
 tolerance=10e-10;
 do
 { double delX[m];
   error_sqrsm=0;
   make_jacobi(jacobi,X,dX,m);
   /*for (int i = 0; i < m; i++)
   {for(int j=0;j<m;j++)
     {printf("%lf ",jacobi[i][j]);}
     printf("\n");
   }*/
    
   make_aug_mat(aug_mat,jacobi,F,m,m);
   //2.020000 1.980000 7.999600 
   //1.000000 1.000000 0.000000 
   gauss_elim(aug_mat,m,m);
   for(int i=0;i<m;i++)
   //2.020000 1.980000 7.999600 
   //-0.000000 0.019802 -3.960198 
   backsubstitute(delX,aug_mat,m,m);
   
   //-------------------------print jacobi
   
   //----------------------------------
   for (int i=0;i<m;i++)
   {
    error_sqrsm+=pow(delX[i],2);
   }
   
   if(sqrt(error_sqrsm)<tolerance)
   { 
    printf("successful");
    
    fprintf(fp,"%d %lf %lf %lf %lf \n",iter,X[0],X[1],X[2],sqrt(error_sqrsm));
    break;
   }
   for (int i=0;i<m;i++)
   {
    X[i]=delX[i]+X[i];
   }
  fprintf(fp,"%d %lf %lf %lf %lf \n",iter,X[0],X[1],X[2],sqrt(error_sqrsm)); 
  F[0]=f1(X[0],X[1],X[2],0);
  F[1]=f1(X[0],X[1],X[2],1);
  F[2]=f1(X[0],X[1],X[2],2);
   
   iter++; 
 } while (iter<N);
 
 


}

