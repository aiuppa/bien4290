#include "EdgeDetection.h"

float EdgeDetection::updatePixel(Image & hood){
  unsigned int i=0, j=0;
  float sum=0.0;
  for(i=0; i<hood.getNumRows(); ++i){
    for(j=0; j<hood.getNumCols(); ++j){
      sum = sum + (kernel.getVal(i,j)*hood.getVal(i,j));
    }
  }
  return sum;
}
