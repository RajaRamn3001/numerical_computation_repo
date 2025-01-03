#include <iostream>
#include <cfloat>
using namespace std;

void machine_epsilon(float eps)
{  
    float prev_epsilon;
    while((1+eps)!=1)
    {
       prev_epsilon=eps;
       eps/=2;

    }
    cout<<"The machine epsilon is "<<prev_epsilon<<endl;


}
int main() {
  machine_epsilon(1);
  return 0;
}