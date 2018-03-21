#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Image.h"

void Image::init(int nr, int nc){
//set properties
  num_rows = nr;
  num_cols = nc;
//allocate
  data = new float[num_rows*num_cols](0.0);  //initialize to 0
}
  
Image::Image(int nr, int nc){  init(nr,nc);  }

Image::Image(const Image & im){
  //Image(im.num_rows,im.num_cols); // would this work??
  //init(im.num_rows,im.num_cols);  // this might do desired func
  num_rows = im.num_rows;
  num_cols = im.num_cols;
  data = new float[num_rows*num_cols];
  // copy contents of im.data to this.data
  for(int i=0; i<num_rows*num_cols;++i){
    data[i]=im.data[i];
  }
}

Image::~Image(){  delete[] data;  }
