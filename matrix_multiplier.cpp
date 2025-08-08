#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> mat_multiply(vector<vector<double>> m1,vector<vector<double>> m2)
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
int main() 
{

    // Declaring and initializing 2d vector
    vector<vector<double>> v1 = {{1, 2, 3}, {3, 4, 1}};
    vector<vector<double>> v2={{1},{2},{1}};
    vector<vector<double>> v3;
    
    v3=mat_multiply(v1,v2);
    show(v1);
    show(v2);
    show(v3);
   
    return 0;
}