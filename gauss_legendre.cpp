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

double func(double x)
{
 double y;
 y=exp(x)*sin(x)/(1+pow(x,2));
 return y;
}
double gaussLegendre(int n,double a,double b) {
    vector<double> points;
    vector<double> weights;

    switch (n) {
        case 2:
            points = {-0.5773502691896257, 0.5773502691896257};
            weights = {1.0000000000000000, 1.0000000000000000};
            break;

        case 3:
            points = {0.0000000000000000, -0.7745966692414834, 0.7745966692414834};
            weights = {0.8888888888888888, 0.5555555555555556, 0.5555555555555556};
            break;

        case 4:
            points = {-0.8611363115940526, -0.3399810435848563, 
                      0.3399810435848563,  0.8611363115940526};
            weights = {0.3478548451374538, 0.6521451548625461, 
                       0.6521451548625461, 0.3478548451374538};
            break;

        default:
            cout << "Invalid input! Only 2, 3, or 4 points are supported." << endl;
            
    }
    double ao=(b+a)/2;
    double a1=(b-a)/2;
    double x;
    double sum=0;
    for(int i=0;i<n;i++)
    {
     sum+=weights[i]*func(ao+a1*points[i]);  
    }
    

 return sum;   
}
int main()
{
 double a=0;
 double b=2;
 int n=4;
 double I=gaussLegendre(n,a,b);
 cout<<"For n="<<n<<" Integrated value is "<<I<<endl;

}