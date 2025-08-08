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
vector<double> lagrange_coeff(vector<double> x,vector<double> y)
{   int n=x.size();
    vector<double> lagrange;
    lagrange.resize(n);
    double coeff;  
    for (int i = 0; i <n; i ++) 
    { coeff = 1.0; 
        for (int j = 0; j <n; j ++) 
        { if (j != i)
             { coeff = coeff/ (x[i] - x[j]);
             } 
        } 
        lagrange[i]= coeff * y[i]; 
    } 
    return lagrange;
}
double interpolate(vector<double> coeff,vector<double> x,double x0)
{
    int n=coeff.size();
    double c, y0=0.0;
    for (int i = 0; i <n; i ++) 
    {   c=1;
        for (int j = 0; j <n; j ++) 
        { if (j != i)
             { 
                c = c * (x0 - x[j]);
             } 
        } 
          y0=y0 + c * coeff[i]; 
    } 

 return y0;

}


int main()
{
 vector<double> x_pt;
 vector<double> y_pt;
 vector<double> coeffs;
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
coeffs=lagrange_coeff(x_pt,y_pt);

//  show(x_pt);
//  show(y_pt);
cout << "Enter the value of x to be determined:"; 
cin >> x; 
y=interpolate(coeffs,x_pt,x);
cout << "Calculated value is " << y<< endl;
 return 0;
}