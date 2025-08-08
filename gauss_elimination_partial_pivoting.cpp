#include <bits/stdc++.h>
using namespace std;
void show(vector<vector<double>> v)
{for (int i = 0; i < v.size(); i++) 
    {
        for (int j = 0; j < v[i].size(); j++) 
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

double Significant_digit(double N, int n) 
{ 
    int nonzero_count = 0;
    int leadzero_count = 0; 
    int dec; 
    int r; 
    
    double f = fabs(N); 
  
    // Counting the no. of significant digits to the left of decimal point in the given no. 
    if (floor(f) != 0)
    {
        while (f >= 1)
        {
            f = f / 10;
            nonzero_count++;
        }
    }
        
    // Counting the leading zeroes to right of decimal point if there are no significant digits to the left 
    while (floor(f) == 0)
    {
        f = f * 10;
        leadzero_count++;
    }
    dec = n - nonzero_count; // No. of significant digits to the right of decimal
    double h = N * pow(10, dec + leadzero_count - 1); // Shifting the significant digits to the left of decimal for rounding
    double g = h + 0.5; 
    
    // Handling banker's rounding
    if ((float)g == (float)ceil(h))
    { 
        double d = (ceil(h)); 
        r = d - 2; 
        if (r % 2 != 0) 
        { 
            g = g - 1; 
        } 
    }
    // Restoring decimal place
    double e = floor(g); 
    e = e / pow(10, dec + leadzero_count - 1) ;
    
    
    cout<<"No of function evaluations for xi is " << nonzero_count + leadzero_count + 2 * (dec + leadzero_count - 1) << endl; 
    return e; 
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

vector<vector<double>> gauss_elimination(vector<vector<double>> Augmat)
{
  for(int i=0;i<Augmat.size();i++)
   { int g;//g=stores row index of greatest element in ith column
     double max_ele;//stores the greatest element in ith column
     g=i;//default row index
     max_ele=Augmat[i][i];//default largest element in ith column
     //This loop will search for greatest element in ith column
     for(int j=0;j<Augmat.size();j++)
      {if(fabs(max_ele)<fabs(Augmat[j][i])&&j>i)
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
      cout<<"Partial pivoting of "<<i+1<<"th column"<<endl;
      show(Augmat);
    
    
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
     cout<<"Elimination of "<<i+1<<"th column"<<endl;
     show(Augmat);
     
    
   }


 return Augmat;
}

vector<vector<double>> back_substitute(vector<vector<double>> Augmat,int d)
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
   soln[i][0]=Significant_digit(soln[i][0],d);
    
  }

 return soln;
}

vector<vector<double>>  hilbert_matrix(int m,int n)
{
 vector<vector<double>> Hb;
 Hb.resize(m, vector<double>(n+1));
 for (int i = 0; i < Hb.size(); i++) 
    {   double b=0;
        for (int j = 0; j < Hb[i].size(); j++) 
        {  if(j!=(Hb[i].size()-1))
           {double h=i+j+1;
            Hb[i][j]=1/h;
            b+=Hb[i][j];
             
           }
           else
           {
            Hb[i][j]=b;
           }

        }
        
    }
    
  return Hb;


}

void find_norm2(vector<vector<double>> soln,vector<vector<double>> soln_star,int d)
{
  vector<vector<double>> error;
  error.resize(soln.size(), vector<double>(soln[0].size()));
  double sum=0;
  for(int i=0;i<soln.size();i++)
  {
    error[i][0]=soln[i][0]-soln_star[i][0];
    sum+=pow(error[i][0],2);
  }
  double norm2=sqrt(sum);
 cout<<d<<" "<<norm2<<endl;

}

void find_norm_inf(vector<vector<double>> soln,vector<vector<double>> soln_star,int d)
{
  vector<vector<double>> error;
  error.resize(soln.size(), vector<double>(soln[0].size()));
  double Max=0;
  for(int i=0;i<soln.size();i++)
  {
    error[i][0]=fabs(soln[i][0]-soln_star[i][0]);
    
  }
  for(int i=0;i<soln.size();i++)
  {
    if(error[i][0]>Max)
    {Max=error[i][0];}
    
  }
  
 cout<<d<<" "<<Max<<endl;

}
int main() 
{

    // Declaring and initializing 2d vector
    vector<vector<double>> v1 = {{5, 6, 9}, {6, 9, 2},{11, 159, 11.001}};
    vector<vector<double>> v2 ={{29},{19},{49.002}};
    vector<vector<double>> v3;
    v3=form_augment(v1,v2);

    

    vector<vector<double>> v4=hilbert_matrix(5,5);
    vector<vector<double>> v5=gauss_elimination(v4);
    vector<vector<double>> v6=back_substitute(v5,10);
    vector<vector<double>> v7=back_substitute(v5,2);
    vector<vector<double>> v8=back_substitute(v5,3);
    vector<vector<double>> v9=back_substitute(v5,4);
    vector<vector<double>> v10=back_substitute(v5,5);
    
    show(v5);
    cout<<"ans"<<endl;
    show(v6);
    cout<<"Significant figure"<<"Norm_2"<<endl;
    find_norm2(v7,v6,2);
    find_norm2(v8,v6,3);
    find_norm2(v9,v6,4);
    find_norm2(v10,v6,5);
    cout<<"Significant figure"<<"Norm_infinity"<<endl;
    find_norm_inf(v7,v6,2);
    find_norm_inf(v8,v6,3);
    find_norm_inf(v9,v6,4);
    find_norm_inf(v10,v6,5);

}

