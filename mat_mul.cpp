#include <bits/stdc++.h>
using namespace std;
void mat_multiply(double m1[][100],int m,int n,double m2[][100],int s,int r,double m3[][100])
 {   if(n==s)
     {
     for(int i=0;i<m;i++)
       { for(int j=0;j<r;j++)
          {
            m3[i][j]=0;
            for(int k=0;k<n;k++)
            {
             m3[i][j]+=m1[i][k]*m2[k][j];
             
            }
            
          }

       }
      
     }
    else
    {
     cout<<"Vectors/Matrix are not compatible for multiplication"<<endl;
     
    }
    
}
void display(double v[][100],int m,int n)
{for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{

    
    double v1[100][100] = {{10, 15, 30}, {22, 12, 13}};
    double v2[100][100]={{1},{2},{4}};
    double v3[100][100];

    mat_multiply(v1,2,3,v2,3,1,v3);
    display(v1,2,3);
    display(v2,3,1);
    display(v3,2,1);
   
    return 0;
}