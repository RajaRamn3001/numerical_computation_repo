#include <iostream>
#include <bits/stdc++.h>
#include <string>
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


double integrate(vector<double> x,vector<double> y)
{
 int n=x.size();
 vector<double> h;
 h.assign(n,0);
 for(int i=0;i<n-1;i++)
 {
   h[i]=x[i+1]-x[i];  
 }
show(h);
 int count=0; 
 double sum=0;
 double sum_1_3rd=0;
 for(int j=0;j<n-1;j++)
 {  
     if(fabs(h[j]-h[j+1])<1e-6)
     { count++;
        
      if(count==1)
        {sum_1_3rd=h[j]*(y[j]+4*y[j+1]+y[j+2])/3;
        sum=sum+sum_1_3rd;
       
        }
      else if((count+1)%3==0)
        {
         sum=sum-sum_1_3rd;
         sum=sum+3*h[j]*(y[j-1]+3*y[j]+3*y[j+1]+y[j+2])/8;
         sum_1_3rd=0;
         
        }
      else
      {
        count=0;
      }  
     


    //******************** */
         
     }
    else 
    {
        if(count==0)
        {
        sum=sum+h[j]*(y[j]+y[j+1])/2;
        
        }
        else
        {
         count=0;
        
        }
          }

 }

return sum;
}
double Trapezoidal(vector<double> x,vector<double> y)
{
 int n=x.size();
 vector<double> h;
 h.assign(n,0);
 for(int i=0;i<n-1;i++)
 {
   h[i]=x[i+1]-x[i];  
 }
show(h);
int count=0;
double sum=0; 
for(int j=0;j<n-1;j++)
{
 sum=sum+h[j]*(y[j]+y[j+1])/2;
}

return sum;
}

int main()

{

vector<double> x_pt;
vector<double> y_pt;



int n_datapts;
double x,y;

// char fileName[50];
// int f;
// cout << "Enter file name: ";

// cin.getline(fileName, 50);

ifstream input("q1_input.txt"); 

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
show(x_pt);
show(y_pt);
double I_trapeze=Trapezoidal(x_pt,y_pt);
double I=integrate(x_pt,y_pt);
cout<<"Integrated value by only trapezoidal is "<<I_trapeze<<endl;
cout<<"Integrated value by combination of trapezoidal,simpsons "<<I<<endl;

}
