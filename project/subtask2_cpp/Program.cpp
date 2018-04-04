#include <cstring>
#include <iostream>
#include "Image.h"
#include "Filter.h"
#include "EdgeDetection.h"

#define HOOD_N 3
#define HOOD_M 3

int main(void){
  char iFile[50]="lab5_spatial_image.bin";
  //char iFile[50]="lab5_noise_image.bin";
  char oFile[50]="edgeDetection_spatial_output_3_3.bin";
  //char oFile[50] = "edgeDetection_noise_output_3_3.bin";
  Image im(256,256);
  //read in image
  im.readImage(iFile);
    
  //process image
  Image kernel(HOOD_M,HOOD_N);
  kernel.setVal(0,0,0);
  kernel.setVal(0,1,-1);
  kernel.setVal(0,2,0);
  kernel.setVal(1,0,-1);
  kernel.setVal(1,1,5);
  kernel.setVal(1,2,-1);
  kernel.setVal(2,0,0);
  kernel.setVal(2,1,-1);
  kernel.setVal(2,2,0);

  EdgeDetection filter(kernel);
  Image out=filter.process(im,HOOD_M,HOOD_N);

  //write image to file
  out.writeImage(oFile);

  return 0;
}
