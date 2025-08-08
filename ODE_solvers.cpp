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


double f(double k,double x, double y) {
    if(y<0)
    {return 0;}
    else
    {return -k * sqrt(y);
    }
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
    while (t<=57.73502)
     {
        t += h;
        y = pow(((57.73502-t)*0.03),2);
        t_vals.push_back(t);
        y_vals.push_back(y);
        i++;
    }
  

}

void RK4_Method(double k, double y0, double t0, double h, double y_end,
                 vector<double>& t_vals, vector<double>& y_vals,int *count) 
{
    double y = y0;
    double t = t0;
    double K1,K2,K3,K4;
    *count=0;
    t_vals.push_back(t);
    y_vals.push_back(y);

     do{
        K1=f(k,t,y);
        K2=f(k,t+0.5*h,y+0.5*h*K1);
        K3=f(k,t+0.5*h,y+0.5*h*K2);
        K4=f(k,t+h,y+h*K3);
        y = y + h * (K1+2*K2+2*K3+K4)/6;
        t += h;
        if(y<0)
        {break;}
        t_vals.push_back(t);
        y_vals.push_back(y);
        *count=*count+19;
    }while (y > y_end);
}

void heunMethod(double k, double y0, double t0, double h, double y_end,
                vector<double>& t_vals, vector<double>& y_vals,int *count) 
{
    double y = y0;
    double t = t0;
    t_vals.push_back(t);
    y_vals.push_back(y);
    *count=0;
    double dummy;
    double yn;
    double y_predict;
     do
     {
        y_predict = y + h * f(k,t, y); 
        *count=*count+3;
        do
        {dummy=y_predict;
         double f_avg = (f(k,t,y) + f(k,t, y_predict)) / 2.0;
         yn = y + h * f_avg;
         if(yn<0)
         {break;}
         y_predict =yn; 
         *count=*count+6;
        } while (fabs((dummy-yn)/yn)>1e-6 );
        y=yn;
        t += h;
        if(y<0)
        {break;}
        t_vals.push_back(t);
        y_vals.push_back(y);
        
        
    }while (y > y_end);
}

void print_terminal(vector<double>& t_vals,vector<double>& y_vals,vector<double>& y_vals2,vector<double>& y_exact) {
    
    for (size_t i = 0; i < t_vals.size(); ++i) {
        cout << t_vals[i] << "  " << y_vals[i]<<"  "<< y_vals2[i]<<"  "<<y_exact[i]<<"  "<<fabs(y_exact[i]-y_vals[i])/y_exact[i]*100<<"  "<<fabs(y_exact[i]-y_vals2[i])/y_exact[i]*100<<endl;
    }
    cout << endl;
}



int main() {
    double k = 0.06;
    double y0 = 3.0;
    double t0 = 0.0;
    double h = 0.8;
    double y_end = 0.0;

    vector<double> t_RK4, y_RK4;
    vector<double> t_heun, y_heun;
    vector<double> t_exact, y_exact;
    vector<double> RK4_tr, heun_tr;
    int f_eval_RK4;
    int f_eval_heun;
    heunMethod(k, y0, t0, h, y_end, t_heun, y_heun,&f_eval_heun);
    RK4_Method(k, y0, t0, h, y_end, t_RK4, y_RK4,&f_eval_RK4);
    exact_soln(k, y0, t0, h, y_end, t_exact, y_exact);
     print_terminal (t_exact, y_RK4,y_heun, y_exact);
    //print_terminal( t_heun, y_heun,y_exact);
    cout<<"h= "<<h<<" Function eval "<<"RK4: "<<f_eval_RK4<<" Heun: "<<f_eval_heun<<endl;
    
    
    return 0;
}
