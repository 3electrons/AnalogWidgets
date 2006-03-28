#include "functions.h"

#include <iostream>
using namespace std; 

double minimalStep(double scaleSize, int steps)
{
  double ms = scaleSize/steps; 
  double fractions[]={5,2,1}; 
  double multiply = 10; 
  double fraction = 1.0; 
  if (static_cast<int>(ms)<=5) multiply = 0.1 ; 

  while (true)
  {
     for (int i=0;i<3;i++)
     {
       //cout<<"Fractions:"<<fractions[i]<<" scaleSize:"<<scaleSize<<" steps:"<<steps<<" steps*farction:"<<steps*fractions[i]<<endl; 
       if (fractions[i]<ms)
          { 
           fraction =fractions[i]; 
          }
       
         fractions[i]*=multiply; 
         if (steps * fractions[i] < scaleSize ) return fraction; 
     }
  }
  return fraction; 
}
