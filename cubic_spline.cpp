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

double solve_poly(vector<double> coeff,double x)
{
  int n=coeff.size();
  double sum=0;
  for(int i=0;i<n;i++)
  {
   sum+=coeff[i]*pow(x,(double) n-1-i);

  }
 return sum;
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
              AB[i][j]=B[i][j-A[i].size()];  
            }
        }
        
    }
    return AB;
    
  }

}

vector<vector<double>> make_augment(vector<double> x,vector<double> y)
{
    vector<vector<double>> AB;
    int n=x.size();
    AB.resize(n-2,vector<double>(n-1));
    for(int i = 0; i < n - 2; i ++) 
    { for(int j = 0; j <= n - 2; j ++) 
        if (j != n - 2) 
        { if (j == i) 
            AB[i][j] = 2.0 * (x[i + 2] - x[i]); 
            else if (j == i + 1) 
            AB[i][j] = x[i + 2] - x[i + 1]; 
            else if (j == i - 1) 
            AB[i][j] = x[i + 1] - x[i];
             else 
             AB[i][j] = 0.0; 
        } 
        else 
        AB[i][j] = 6.0 / (x[i + 2] - x[i + 1]) * (y[i + 2] - y[i + 1]) + 6.0 / (x[i + 1] - x[i]) * (y[i] - y[i + 1]); 
         } 

return AB;
}

int main()
{
 vector<double> x_pt;
 vector<double> y_pt;
 
 vector<double>  f_doubledash;
 vector<vector<double>> augmat;
 vector<vector<double>> solution;
 int n_datapts;
 double x,y;
 char fileName[50];
 cout << "Enter file name: ";
 cin.getline(fileName, 50);
 ifstream input(fileName); 
 
 if(input.fail()==true)
 {
  cout<<"File did not open correctly"<<endl;
 }
 else
 { 
    while (input >> x >> y) 
    {
        x_pt.push_back(x);
        y_pt.push_back(y);
    }

    

 }

 input.close();
n_datapts=x_pt.size();
f_doubledash.assign(n_datapts,0);
augmat=make_augment(x_pt,y_pt);
augmat=gauss_elimination(augmat);
solution=back_substitute(augmat);
for(int i = 0; i < n_datapts - 2; i ++) 
{   f_doubledash[i + 1] = solution[i][0];
}
//  show(x_pt);
//  show(y_pt);
cout << "Enter the value of x to be determined:"; 
cin >> x; 
for (int i = 1; i <= n_datapts-1; i ++) 
         { if (x >= x_pt[i - 1] && x <= x_pt[i]) 
            { y = f_doubledash[i - 1]/(6.0*(x_pt[i]-x_pt[i - 1]))*pow(x_pt[i]-x,3) + 
                  f_doubledash[i]/(6.0*(x_pt[i]-x_pt[i-1])) * pow(x-x_pt[i-1], 3) +
                  (y_pt[i-1] / (x_pt[i]-x_pt[i-1])-
                  f_doubledash[i-1]*(x_pt[i]-x_pt[i-1])/6.0) * (x_pt[i]-x) + 
                  (y_pt[i]/(x_pt[i]-x_pt[i-1]) - 
                  f_doubledash[i] * (x_pt[i]-x_pt[i-1]) / 6.0)*(x - x_pt[i-1]); 
            } 
         } 
         cout << "Calculated value is " << y<< endl; 

 return 0;
}