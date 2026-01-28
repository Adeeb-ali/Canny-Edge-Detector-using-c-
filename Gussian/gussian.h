#ifndef GAUSSIAN_BLUR_H
#define GAUSSIAN_BLUR_H

#include <vector>

namespace img {


std::vector<std::vector<float>> gaussianBlur(
    const std::vector<std::vector<float>>& image,
    int kernelSize
);

}

#endif
