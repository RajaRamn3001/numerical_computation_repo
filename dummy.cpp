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
 
vector<vector<double>> mat_multiply(vector<vector<double>> m1,vector<vector<double>> m2,int *count)
 {   if(m1[0].size()==m2.size())
     {vector<vector<double>> m3;
     m3.resize(m1.size(), vector<double>(m2[0].size()));
     for(int i=0;i<m1.size();i++)
       { for(int j=0;j<m2[0].size();j++)
          {
            m3[i][j]=0;
            for(int k=0;k<m2.size();k++)
            {
             m3[i][j]+=m1[i][k]*m2[k][j];
             *count=*count+1;
            }
            
          }

       }
      return m3;
     }
    else
    {
     cout<<"Vectors/Matrix are not compatible for multiplication"<<endl;
     vector<vector<double>> m3={{0}}; 
     return m3;  
    }
    
}

vector<vector<double>> mat_add(vector<vector<double>> m1,vector<vector<double>> m2)
 {   if(m1.size()==m2.size()&&m1[0].size()==m2[0].size())
     {vector<vector<double>> m3;
     m3.resize(m1.size(), vector<double>(m1[0].size()));
     for(int i=0;i<m1.size();i++)
       { for(int j=0;j<m2[0].size();j++)
          {
            m3[i][j]=m1[i][j]+m2[i][j];
            
          }

       }
      return m3;
     }
    else
    {
     cout<<"Vectors/Matrix are not compatible for addition"<<endl;
     vector<vector<double>> m3={{0}}; 
     return m3;  
    }
    
}

vector<vector<double>> mat_sub(vector<vector<double>> m1,vector<vector<double>> m2)
 {   if(m1.size()==m2.size()&&m1[0].size()==m2[0].size())
     {vector<vector<double>> m3;
     m3.resize(m1.size(), vector<double>(m1[0].size()));
     for(int i=0;i<m1.size();i++)
       { for(int j=0;j<m2[0].size();j++)
          {
            m3[i][j]=m1[i][j]-m2[i][j];
            
          }

       }
      return m3;
     }
    else
    {
     cout<<"Vectors/Matrix are not compatible for addition"<<endl;
     vector<vector<double>> m3={{0}}; 
     return m3;  
    }
    
}

vector<vector<double>> transpose(vector<vector<double>> m1)
 {   
     vector<vector<double>> m3;
     m3.resize(m1[0].size(), vector<double>(m1.size()));
     for(int i=0;i<m3.size();i++)
       { for(int j=0;j<m3[0].size();j++)
          {
            m3[i][j]=m1[j][i];
            
          }

       }
      return m3;
    
}

vector<vector<double>> scale_mat(double a,vector<vector<double>> m1,int *count)
 {   
     
     for(int i=0;i<m1.size();i++)
       { for(int j=0;j<m1[0].size();j++)
          {
            m1[i][j]=a*m1[i][j];
            *count=*count+1;
          }

       }
      return m1;
    
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
double error_norm_inf(vector<vector<double>> soln)
{
  
  double Max=0;
  
  for(int i=0;i<soln.size();i++)
  {
    if(fabs(soln[i][0])>Max)
    {Max=fabs(soln[i][0]);}
    
  }
  
 return Max;

}
vector<vector<double>> conjugate_grad(vector<vector<double>> A,vector<vector<double>> b,int N,double tol)
{
 if(A.size()!=b.size())
 {
   return {{0}}; 
 }   
 vector<vector<double>> old_soln;
 vector<vector<double>> r;//residual 
 vector<vector<double>> s;//search direction  
 vector<vector<double>> error;
 double alpha;
 double beta;
 vector<vector<double>> a;
 vector<vector<double>> d;
 vector<vector<double>> c;
 old_soln.resize(A.size(),vector<double>(1));
 r.resize(A.size(),vector<double>(1));
 s.resize(A.size(),vector<double>(1));
 error.resize(A.size(),vector<double>(1));
 double saved_value;
 int operation_count=0;
 //Initialising by putting guess values in old soln 
 for(int i=0;i<A.size();i++)
 {
   old_soln[i][0]=0;  
 }
 r=mat_sub(b,mat_multiply(A,old_soln,&operation_count));//initialising r
 for(int i=0;i<A.size();i++)//initialising s
 {
   s[i][0]=r[i][0];  
 }
 double error_norm_2;
 int iteration=0;
 do
 { 

   a=mat_multiply(transpose(r),r,&operation_count);
   d=mat_multiply(transpose(s),mat_multiply(A,s,&operation_count),&operation_count);
   alpha=a[0][0]/d[0][0];
   operation_count++;
   old_soln=mat_add(old_soln,scale_mat(alpha,s,&operation_count));
   error_norm_2=error_norm_inf(r);
   r=mat_sub(r,scale_mat(alpha,mat_multiply(A,s,&operation_count),&operation_count));
   c=mat_multiply(transpose(r),r,&operation_count);
   beta=c[0][0]/a[0][0];
   operation_count++;
   s=mat_add(r,scale_mat(beta,s,&operation_count));
   iteration++;
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

vector<vector<double>>  hilbert_matrix_H(int m,int n)
{
 vector<vector<double>> H;
 H.resize(m, vector<double>(n));
 for (int i = 0; i < H.size(); i++) 
    {   
        for (int j = 0; j < H[i].size(); j++) 
        {  
           double h=i+j+1;
            H[i][j]=1/h;


        }
        
    }
    
  return H;


}

vector<vector<double>>  hilbert_matrix_b(vector<vector<double>> H)
{double sum;
 vector<vector<double>> b;
 b.resize(H.size(), vector<double>(1));
 for (int i = 0; i < H.size(); i++) 
    {   sum=0;
        for (int j = 0; j < H[i].size(); j++) 
        {  
           
            sum+=H[i][j];
            b[i][0]=sum;

        }
        
    }
    
  return b;


}
int main() {
 
	// Declaring and initializing 2d vector
	vector<vector<double>> A =hilbert_matrix_H(6,6);
	vector<vector<double>> b= hilbert_matrix_b(A);
	vector<vector<double>> soln;
	soln=conjugate_grad(A,b,MAX_ITER,accuracy);
	show(A);
	show(b);
	cout<<"ans:"<<endl;
	show(soln);
	return 0;
}