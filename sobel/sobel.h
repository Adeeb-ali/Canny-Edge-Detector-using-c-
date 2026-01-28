#ifndef SOBEL_H
#define SOBEL_H

#include <vector>

namespace img {

struct EdgeResult {
    std::vector<std::vector<float>> Gx;
    std::vector<std::vector<float>> Gy;
    std::vector<std::vector<float>> Mag;
    std::vector<std::vector<float>> Angle;
};


EdgeResult scharrEdge(
    const std::vector<std::vector<float>>& img
);

}

#endif 
