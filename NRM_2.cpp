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


double f1(double x1,double x2,double x3,double x4,int i,int *func_eval)
{ vector<vector<double>> ff;
  ff.resize(3, vector<double>(1));
  
   switch (i)
   {
   case 0:
    *func_eval=*func_eval+1;
    return x1+10*x2;;
    break;
   case 1:
    *func_eval=*func_eval+2;
    return sqrt(5)*(x3-x4);
    break;
   case 2:
    *func_eval=*func_eval+1;
    return pow(x2-x3,2);
    break;
   case 3:
    *func_eval=*func_eval+1;
    return sqrt(10)*pow(x1-x4,2);
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
  {
   switch (j)
   {
   case 0:
   J[i][j]=(f1(x[0]+dx[j],x[1],x[2],x[3],i,&k)-f1(x[0]-dx[j],x[1],x[2],x[3],i,&k))/(2*dx[j]);
   *func_eval=*func_eval+3;
    break;
   case 1:
   J[i][j]=(f1(x[0],x[1]+dx[j],x[2],x[3],i,&k)-f1(x[0],x[1]-dx[j],x[2],x[3],i,&k))/(2*dx[j]);
   *func_eval=*func_eval+3;
    break;
   case 2:
   J[i][j]=(f1(x[0],x[1],x[2]+dx[j],x[3],i,&k)-f1(x[0],x[1],x[2]-dx[j],x[3],i,&k))/(2*dx[j]);
   *func_eval=*func_eval+3;
    break;
    case 3:
    J[i][j]=(f1(x[0],x[1],x[2],x[3]+dx[j],i,&k)-f1(x[0],x[1],x[2],x[3]-dx[j],i,&k))/(2*dx[j]);
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
{vector<double> dX={0.0001 , 0.0001, 0.0001, 0.0001};
 vector<double> X={1,2,1,1};
 int N=1000;
 int no_of_variable=4;
 int iter=1;
 int function_eval=0;
 vector<vector<double>> F;
 vector<vector<double>> jacobi;
 vector<vector<double>> aug_mat;
 F.resize(no_of_variable,vector<double>(1));
 jacobi.resize(no_of_variable,vector<double>(no_of_variable));
 double error_sqrsm;
 double tolerance;
 for(int i=0;i<no_of_variable;i++)
 {
    F[i][0]=f1(X[0],X[1],X[2],X[3],i,&function_eval);
 }
 
 tolerance=10e-6;
 do
 { vector<vector<double>> delX;
   double error_norm_2=0;
   delX.resize(no_of_variable,vector<double>(1));
   error_sqrsm=0;
   make_jacobi(jacobi,X,dX,&function_eval);
   aug_mat=form_augment(jacobi,F);
   aug_mat=gauss_elimination(aug_mat);
   delX=back_substitute(aug_mat);
   error_norm_2=error_norm2(delX);
   for (int i=0;i<no_of_variable;i++)
   {
    error_sqrsm+=pow(delX[i][0],2);
   }
   
   if(sqrt(error_sqrsm)<tolerance)
   { 
    printf("successful");
    break;
   }
   cout<<iter<<" ";
   for(int i=0;i<jacobi.size();i++)
    {
      cout<<delX[i][0]<<" ";  
    }
    cout<<error_norm_2;
    cout<<endl;
   for (int i=0;i<no_of_variable;i++)
   {
    X[i]=delX[i][0]+X[i];
   }
  for(int i=0;i<no_of_variable;i++)
  {
    F[i][0]=f1(X[0],X[1],X[2],X[3],i,&function_eval);
  }
   

   
   iter++; 
 } while (iter<N);
 
 


}

