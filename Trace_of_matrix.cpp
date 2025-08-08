#include <iostream>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <random>
using namespace std;

double **generate_matrix(int m,int n)
{
  double lower_bound = 0;
  double upper_bound = 100;
 
  uniform_real_distribution<double> unif(lower_bound,upper_bound);
 
  default_random_engine re;
 
// Getting a random double value
  
  double **g_matrix=(double**)malloc(sizeof(double *)*n);
  srand(4);
  for(int j=0;j<n;j++)
  {
    g_matrix[j]=(double*)malloc(sizeof(double)*m);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++) 
     {
      g_matrix[i][j]=unif(re);
     } 
  
  }
  return g_matrix;
}

void find_trace(double **matrix,int m,int n)
{
  if(m==n)
  { double trace=0;
    for(int i=0;i<n;i++)
    {
      trace+=matrix[i][i];
    }
   cout<<"Trace: "<<trace<<endl;
  }
  else
  {cout<<"Not a square matrix"<<endl;} 

}

int main()
{int m=10;
 int n=10;   
 double **random_matrix=generate_matrix(m,n);
 for(int i=0;i<10;i++)
 {for(int j=0;j<10;j++)
   {
     cout<<random_matrix[i][j]<<" ";

   }
   cout<<endl;

 }
 find_trace(random_matrix,m,n);

}

