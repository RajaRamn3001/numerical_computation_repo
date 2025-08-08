#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double accuracy=1e-6;
int MAX_ITER=1000;
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
double Max_in_vector(vector<vector<double>> soln)
{
  
  double Max=0;
  
  for(int i=0;i<soln.size();i++)
  {
    if(fabs(soln[i][0])>Max)
    {Max=fabs(soln[i][0]);}
    
  }
  
 return Max;

}

class EigenVect_values {        // The class
    public:          // Access specifier
    vector<vector<double>> eigen_vect;  // Attribute
      double eigen_value;  // Attribute
  

    
      
      
      
  };

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

EigenVect_values normalised_power_iteration(vector<vector<double>> A,vector<vector<double>> b,int N,double tol)
{
 EigenVect_values E;
 if(A.size()!=b.size())
 {  
    E.eigen_value=0;
    E.eigen_vect={{0}};
   return E; 
 }   
 vector<vector<double>> y;
 vector<vector<double>> x_new;
 vector<vector<double>> error;
 
 y.resize(A.size(),vector<double>(1));
 x_new.resize(A.size(),vector<double>(1));
 
 error.resize(A.size(),vector<double>(1));

 int operation_count=0;
 //Initialising by putting guess values in old soln 
 
 
 double error_norminf;
 int iteration=0;
 do
 { 

   
   y=mat_multiply(A,b,&operation_count);
   x_new=scale_mat(1/Max_in_vector(y),y,&operation_count);
   error=mat_sub(b,x_new);
   error_norminf=error_norm_inf(error);
   iteration++;
   cout<<iteration<<" ";
   for(int i=0;i<A.size();i++)
    {
      b[i][0]=x_new[i][0]; 
      cout<<b[i][0]<<" "; 
    }
    cout<<endl;
	if(error_norminf<=tol)
    {break;}
    

  }
  while(iteration<=N);
  cout<<"No. of arithmatic operation :"<<operation_count<<endl;
  E.eigen_value=Max_in_vector(y);
  E.eigen_vect=b;
  return E; 
}

EigenVect_values inverse_iteration_method(vector<vector<double>> A,vector<vector<double>> b,int N,double tol)
{
 EigenVect_values E;
 if(A.size()!=b.size())
 {  
    E.eigen_value=0;
    E.eigen_vect={{0}};
   return E; 
 }   
 vector<vector<double>> y;
 vector<vector<double>> x_new;
 vector<vector<double>> error;
 vector<vector<double>> augmat;
 
 y.resize(A.size(),vector<double>(1));
 x_new.resize(A.size(),vector<double>(1));
 
 error.resize(A.size(),vector<double>(1));

 int operation_count=0;
 
 
 
 double error_norminf;
 int iteration=0;
 do
 { 

   augmat=form_augment(A,b);
   augmat=gauss_elimination(augmat);
   y=back_substitute(augmat);
   x_new=scale_mat(1/Max_in_vector(y),y,&operation_count);
   error=mat_sub(b,x_new);
   error_norminf=error_norm_inf(error);
   iteration++;
   cout<<iteration<<" ";
   for(int i=0;i<A.size();i++)
    {
      b[i][0]=x_new[i][0];  
      cout<<b[i][0]<<" ";
    }
    cout<<endl;
	if(error_norminf<=tol)
    {break;}
    

  }
  while(iteration<=N);
  cout<<"No. of arithmatic operation :"<<operation_count<<endl;
  E.eigen_value=1/Max_in_vector(y);
  E.eigen_vect=b;
  return E; 
}


int main() {
 
	// Declaring and initializing 2d vector
	vector<vector<double>> A = {{-4,0,0.5,0.5},{0.5,-2,0,0.4},{0.5,0.5,0,0},{0,1,1,4}};
	vector<vector<double>> x= {{0},{0},{0},{1}};
	EigenVect_values eig;
    show(A);
    show(x);
	eig=inverse_iteration_method(A,x,MAX_ITER,accuracy);
    cout<<"ans:"<<endl;
    cout<<"Eigen vector:"<<endl;
	show(eig.eigen_vect);
    cout<<"Eigen value"<<endl;
    cout<<eig.eigen_value<<endl;

	
	

	return 0;
}