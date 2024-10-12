#include<stdio.h>
#include<math.h>
int main(){
FILE *fp;
fp=fopen("matrix_input.txt","r");
int m,n;
fscanf(fp,"%d %d",&m,&n);
float aug_mat[m][n+1];
float soln[n];
//---------------------------
for(int i=0;i<m;i++)
{ for(int j=0;j<n+1;j++)
  {
    fscanf(fp,"%f",&aug_mat[i][j]);
   
  }
}
//----------------------------
fclose(fp);
fp=fopen("output.txt","w");
//-----------------------------
for(int i=0;i<m;i++)
{ for(int j=0;j<n+1;j++)
  {
    fprintf(fp,"%.2f ",aug_mat[i][j]);
   
  }
    fprintf(fp,"\n");
}
//----------------------------gauss elimination
 for(int i=0;i<m;i++)
   { for(int j=0;j<m;j++)
     {if(j>i)
      {float ratio=aug_mat[j][i]/aug_mat[i][i];
        
       for(int k=0;k<n+1;k++)
         {
         aug_mat[j][k]=aug_mat[j][k]-aug_mat[i][k]*ratio;}
      }
   
     }
    
   }

//----------------------------------------backsubstitution
for(int i=m-1;i>=0;i--)
{ 
  soln[i]=aug_mat[i][n]/aug_mat[i][i];
 for(int j=n-1;j>i;j--)
  {soln[i]-=aug_mat[i][j]/aug_mat[i][i]*soln[j];
  
   
   
  }
    
}



//----------------------------------------
fprintf(fp,"\n");
for(int i=0;i<m;i++)
{ 

 for(int j=0;j<n+1;j++)
  {
    fprintf(fp,"%.2f ",aug_mat[i][j]);
   
  }
    fprintf(fp,"\n");
}
for(int i=0;i<m;i++)
{fprintf(fp,"%f \n",soln[i]);}



fclose(fp);



}
