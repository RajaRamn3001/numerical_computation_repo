#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double accuracy=1e-6;
int MAX_ITER=200;
void show(vector<vector<double>> v)
{	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
 
 
}
 
vector<vector<double>> jacobi(vector<vector<double>> A,vector<vector<double>> b,int N,double tol)
{vector<vector<double>> old_soln;
vector<vector<double>> new_soln;
vector<vector<double>> error;
old_soln.resize(A.size(),vector<double>(1));
new_soln.resize(A.size(),vector<double>(1));
error.resize(A.size(),vector<double>(1));
int operation_count=0;
//Initialising by putting guess values in old soln 
for(int i=0;i<A.size();i++)
{
   old_soln[i][0]=0;  
}
double error_sqr_sum;
double error_norm_2;
int iteration=0;
do
{ 
   error_sqr_sum=0;  
   for (int i = 0; i < A.size(); i++) 
   {      new_soln[i][0]=b[i][0]/A[i][i];
          operation_count++;
		for (int j = 0; j < A[i].size(); j++)
		{
		  if(i!=j)
		  {
		    new_soln[i][0]-=A[i][j]/A[i][i]*old_soln[j][0];
		    operation_count+=2;
		  }
		}
		
   }
   iteration++;
   for(int i=0;i<A.size();i++)
   {
     error[i][0]=old_soln[i][0]-new_soln[i][0];  
     error_sqr_sum+=pow(error[i][0],2);
   }
   for(int i=0;i<A.size();i++)
   {
    old_soln[i][0]=new_soln[i][0];  
   }
   cout<<iteration<<" ";
   for(int i=0;i<A.size();i++)
   {
    cout<<old_soln[i][0]<<" ";  
   }
   cout<<endl;
   error_norm_2=sqrt(error_sqr_sum);
   if(error_norm_2<=tol)
   {break;}
   
  }
  while(iteration<=N);
  cout<<"No. of arithmatic operation "<<operation_count<<endl;
  return old_soln; 
}
 
vector<vector<double>> gauss_seidel(vector<vector<double>> A,vector<vector<double>> b,int N,double tol)
{vector<vector<double>> old_soln;
 vector<vector<double>> error;
 old_soln.resize(A.size(),vector<double>(1));
 error.resize(A.size(),vector<double>(1));
 double saved_value;
 int operation_count=0;
 //Initialising by putting guess values in old soln 
 for(int i=0;i<A.size();i++)
 {
   old_soln[i][0]=0;  
 }
 double error_sqr_sum;
 double error_norm_2;
 int iteration=0;
 do
 { 
   error_sqr_sum=0;  
   for (int i = 0; i < A.size(); i++) 
   {      saved_value=old_soln[i][0];
          old_soln[i][0]=b[i][0]/A[i][i];
          operation_count++;
		for (int j = 0; j < A[i].size(); j++)
		{
		  if(i!=j)
		  {
		    old_soln[i][0]-=A[i][j]/A[i][i]*old_soln[j][0];
		    operation_count+=2;
		  }
		}
	  error[i][0]=old_soln[i][0]-saved_value;	
	  error_sqr_sum+=pow(error[i][0],2);	
   }
    iteration++;
    error_norm_2=sqrt(error_sqr_sum);
	cout<<iteration<<" ";
    for(int i=0;i<A.size();i++)
    {
      cout<<old_soln[i][0]<<" ";  
    }
    cout<<endl;
	if(error_norm_2<=tol)
    {break;}
    

  }
  while(iteration<=N);
  cout<<"No. of arithmatic operation :"<<operation_count<<endl;
  return old_soln; 
}
int main() {
 
	// Declaring and initializing 2d vector
	vector<vector<double>> A = {{0.2,0.1,1,1,0},{0.1,4,-1,1,-1},{1,-1,60,0,-2},{1,1,0,8,5},{0,-1,-2,4,700}};
	vector<vector<double>> b= {{1},{2},{3},{4},{5}};
	vector<vector<double>> soln;
	soln=gauss_seidel(A,b,MAX_ITER,accuracy);
	show(A);
	show(b);
	cout<<"ans:"<<endl;
	show(soln);
	return 0;
}