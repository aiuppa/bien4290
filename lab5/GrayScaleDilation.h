#ifndef GRAY_SCALE_DILATION_H
#define GRAY_SCALE_DILATION_H
  #include "Image.h"
  #include "Filter.h"
  class GrayScaleDilation : Filter {
      Image kernel;
    protected:
      virtual float updatePixel(Image& hood);;
    public:
      GrayScaleDilation(const Image & k) : kernel(k){};
  }
#endif