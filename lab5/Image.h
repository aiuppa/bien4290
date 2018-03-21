#ifndef IMAGE_H
#define IMAGE_H
  class Image {
      int num_rows;
      int num_cols;
      float *data;
    public:
      Image(int nr, int nc);
      Image(const Image & im);
      ~Image(); //destructor
    private:
      void init(int nr, int nc);
  }
#endif
