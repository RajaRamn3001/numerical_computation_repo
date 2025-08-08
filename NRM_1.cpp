//finding solution of non-linear system of equations
// f(x)=0
//F={f1,f2,f3....fn},X={x1,x2,x3....xn} i.e X,F are n-dim vectors
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void show(vector<vector<double>> v)
{	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
 
 
}
void show(vector<double> v)
{	for (int i = 0; i < v.size(); i++) {
	
			cout << v[i] << " ";
		
	}
    cout <<endl;
 
}
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
  soln[i][0]=Augmat[i][n-1];
  
  for(int j=n-2;j>i;j--)
  { 
    soln[i][0]-=Augmat[i][j]*soln[j][0];
    
  
  }
  soln[i][0]=soln[i][0]/Augmat[i][i]; 
    
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
              AB[i][j]=-B[i][j-A[i].size()];  
            }
        }
        
    }
    return AB;
    
  }

}


double f1(double x,double y,double z,int i,int *func_eval)
{ vector<vector<double>> ff;
  ff.resize(3, vector<double>(1));
  
   switch (i)
   {
   case 0:
    *func_eval=*func_eval+11;
    return 16*pow(x,4)+16*pow(y,4)+pow(z,4)-16;
    break;
   case 1:
    *func_eval=*func_eval+3;
    return pow(x,2)+pow(y,2)+pow(z,2)-3;
    break;
   case 2:
    *func_eval=*func_eval+2;
    return pow(x,3)-y;
    break;
  
   default:
   return 0;
   break;
   }
  
  
}


vector<vector<double>> make_jacobi(vector<vector<double>> J,vector<double> x,vector<double> dx,int *func_eval)
{
 int k=0;
 for(int i=0;i<J.size();i++)
 {for(int j=0;j<J.size();j++)
  {double fplus;
   double fminus;
   switch (j)
   {
   case 0:
   fplus=f1(x[0]+dx[j],x[1],x[2],i,&k);
   fminus=f1(x[0]-dx[j],x[1],x[2],i,&k);
   J[i][j]=(fplus-fminus)/(2*dx[j]);
   *func_eval=*func_eval+3;
    break;
   case 1:
   fplus=f1(x[0],x[1]+dx[j],x[2],i,&k);
   fminus=f1(x[0],x[1]-dx[j],x[2],i,&k);
   J[i][j]=(fplus-fminus)/(2*dx[j]);
   *func_eval=*func_eval+3;
    break;
   case 2:
   fplus=f1(x[0],x[1],x[2]+dx[j],i,&k);
   fminus=f1(x[0],x[1],x[2]-dx[j],i,&k);
   J[i][j]=(fplus-fminus)/(2*dx[j]);
   *func_eval=*func_eval+3;
    break;
  
   default:
   *func_eval=*func_eval+0;
    break;
   }
  
  *func_eval=*func_eval+k;
  //printf("%d %d %d \n",a,b,c);
  }
 }
  
 return J; 

}
double error_norm2(vector<vector<double>> soln)
{
  
  double sum=0;
  for(int i=0;i<soln.size();i++)
  {
    sum+=pow(soln[i][0],2);
  }
  double norm2=sqrt(sum);
  return norm2;

}



int main()
{vector<double> dX={0.0001 , 0.0001, 0.0001};
 vector<double> X={1,1,1};
 int N=1000;
 int no_of_variable=3;
 int iter=1;
 int function_eval=0;
 vector<vector<double>> F;
 vector<vector<double>> jacobi;
 vector<vector<double>> aug_mat;
 F.resize(no_of_variable,vector<double>(1));
 jacobi.resize(no_of_variable,vector<double>(no_of_variable));
 vector<vector<double>> delX;
 double error_norm_2;
 delX.resize(no_of_variable,vector<double>(1));
 double error_sqrsm;
 double tolerance;
 for(int i=0;i<no_of_variable;i++)
 {
    F[i][0]=f1(X[0],X[1],X[2],i,&function_eval);
 }
 show(F);
 tolerance=10e-6;
 do
 { 
  
   error_sqrsm=0;
   jacobi=make_jacobi(jacobi,X,dX,&function_eval);
   aug_mat=form_augment(jacobi,F);
   aug_mat=gauss_elimination(aug_mat);
   delX=back_substitute(aug_mat);
   
   error_norm_2=error_norm2(delX);
   for (int i=0;i<no_of_variable;i++)
   {
    error_sqrsm+=pow(delX[i][0],2);
   }
   cout<<iter<<" ";
   for(int i=0;i<jacobi.size();i++)
    {
      cout<<X[i]<<" ";  
    }
    cout<<error_norm_2;
    cout<<endl;
   
   if(sqrt(error_sqrsm)<tolerance)
   { 
    cout<<"Successfully converged to"<<endl;
    show(X);
    break;
   }
   
   for (int i=0;i<no_of_variable;i++)
   {
    X[i]=delX[i][0]+X[i];
   }
  for(int i=0;i<no_of_variable;i++)
  {
    F[i][0]=f1(X[0],X[1],X[2],i,&function_eval);
  }
   

   
   iter++; 
 } while (iter<N);
 
 


}

