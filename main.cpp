#include <iostream>
#include "clipp.h"
#include "Halide.h"
#include "libraw/libraw.h"

int main(int argc, char* argv[]) {
  std::cout << "Hello, world" << std::endl;

  Halide::Func gradient;

  LibRaw iProcessor;
  iProcessor.open_file("/Volumes/01/Photos/2019/2019-01-01/DSC04741.ARW");
  printf(
    "Image size: %d x %d\n",
    iProcessor.imgdata.sizes.width,
    iProcessor.imgdata.sizes.height
  );

  iProcessor.unpack();
  iProcessor.raw2image();

  iProcessor.recycle();
  return 0;
}
