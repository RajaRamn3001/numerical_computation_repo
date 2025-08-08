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


double f(double k, double y) {
    if(y<0)
    {return 0;}
    else
    {return -k * sqrt(y);
    }
}

double Ea_euler(double h,double t)
{
 double ea;
 double f_dash;
 f_dash=-0.06*0.03*(((57.73-t-h)-(57.73-t+h)))/(2*h) ;
 ea=f_dash*pow(h,2)/2;
 return ea;
}

double Ea_heun(double h,double t)
{
 double ea;
 double f_double_dash;
 f_double_dash=-0.06*0.03*(((57.73-t-h)-(57.73-t))/h -((57.73-t)-(57.73-t+h))/h)/h ;
 ea=f_double_dash*pow(h,3)/12;
 return ea;
}

void exact_soln(double k, double y0, double t0, double h, double y_end,
    vector<double>& t_vals, vector<double>& y_vals)
{   double y = y0;
    double t = t0;
    t_vals.push_back(t);
    y_vals.push_back(y);
    int i=0;
    while (fabs(y-y_end)>1e-4)
     {
        t += h;
        y = pow(((57.73-t)*0.03),2);
        t_vals.push_back(t);
        y_vals.push_back(y);
        i++;
    }
  

}

void eulerMethod(double k, double y0, double t0, double h, double y_end,
                 vector<double>& t_vals, vector<double>& y_vals,vector<double>& Tr_err,int *count) 
{
    double y = y0;
    double t = t0;
    double Ea=0;
    *count=0;
    t_vals.push_back(t);
    y_vals.push_back(y);
    Tr_err.push_back(Ea);

     do{
        y = y + h * f(k, y);
        t += h;
        Ea=Ea_euler(h,t);
        Tr_err.push_back(Ea);
        t_vals.push_back(t);
        y_vals.push_back(y);
        *count=*count+3;
    }while (y > y_end);
}

void heunMethod(double k, double y0, double t0, double h, double y_end,
                vector<double>& t_vals, vector<double>& y_vals,vector<double>& Tr_err,int *count) 
{
    double y = y0;
    double t = t0;
    double Ea=0;
    t_vals.push_back(t);
    y_vals.push_back(y);
    Tr_err.push_back(Ea);
    *count=0;
    double dummy;
    double yn;
    double y_predict;
     do
     {
        y_predict = y + h * f(k, y); 
        *count=*count+3;
        do
        {dummy=y_predict;
         double f_avg = (f(k, y) + f(k, y_predict)) / 2.0;
         yn = y + h * f_avg;
         y_predict =yn; 
         *count=*count+6;
        } while (fabs((dummy-yn)/yn)>1e-6 && y_predict > 0 );
        y=yn;
        t += h;
        Ea=Ea_heun(h,t);
        Tr_err.push_back(Ea);
        t_vals.push_back(t);
        y_vals.push_back(y);
        
        
    }while (y > y_end);
}

void print_terminal(vector<double>& t_vals,vector<double>& y_vals,vector<double>& y_exact,vector<double>& Tr) {
    
    for (size_t i = 0; i < t_vals.size(); ++i) {
        cout << t_vals[i] << "  " << y_vals[i]<<"  "<<y_exact[i]<<"  " <<Tr[i] <<"  "<<fabs(y_exact[i]-y_vals[i])/y_exact[i]*100<<endl;
    }
    cout << endl;
}



int main() {
    double k = 0.06;
    double y0 = 3.0;
    double t0 = 0.0;
    double h = 0.1;
    double y_end = 0.0;

    vector<double> t_euler, y_euler;
    vector<double> t_heun, y_heun;
    vector<double> t_exact, y_exact;
    vector<double> euler_tr, heun_tr;
    int f_eval_euler;
    int f_eval_heun;
    eulerMethod(k, y0, t0, h, y_end, t_euler, y_euler,euler_tr,&f_eval_euler);
    heunMethod(k, y0, t0, h, y_end, t_heun, y_heun,heun_tr,&f_eval_heun);
    exact_soln(k, y0, t0, h, y_end, t_exact, y_exact);
    //print_terminal (t_euler, y_euler, y_exact,euler_tr);
    print_terminal( t_heun, y_heun,y_exact,heun_tr);
    cout<<"h= "<<h<<"Function eval "<<"Euler: "<<f_eval_euler<<"Heun: "<<f_eval_heun<<endl;
    //show(y_exact);
    return 0;
}
