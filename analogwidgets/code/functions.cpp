#include "functions.h"



double minimalStep(double scaleSize, int steps)
{
  double ms = scaleSize/steps; 
  double fractions[]={5,2,1}; 
  double multiply = 10; 
  if (static_cast<int>(ms)<=5) multiply = 0.1 ; 

  while (true)
  {
     for (int i=0;i<3;i++)
     {
       //cout<<"Fractions:"<<fractions[i]<<endl; 
       if (fractions[i]<ms) return fractions[i]; 
       
         fractions[i]*=multiply; 
     }
  }
  return 1.0; 
}
