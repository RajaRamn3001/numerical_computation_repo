double error_norm2(vector<vector<double>> soln)
{
  
  double sum=0;
  for(int i=0;i<soln.size();i++)
  {
    sum+=pow(soln[i][0],2);
  }
  double norm2=sqrt(sum);
  return norm2;

}