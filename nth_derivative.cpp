double nthderive(double (*f)(double),double x0,double h,int n)
{      
   
   double x1=x0 - h;
   double x2=x0 + h;
   if(n==0) {
       return f(x0);
   }   
   else 
   {
       return (nthderive(f,x2,h,n-1)-nthderive(f,x1,h,n-1))/(2*h);
   }
}