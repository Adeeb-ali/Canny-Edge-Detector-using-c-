#ifndef NMS_H
#define NMS_H

#include <vector>   

namespace img {

std::vector<std::vector<float>> nonMaximumSuppression(
    const std::vector<std::vector<float>>& Mag,
    const std::vector<std::vector<float>>& Angle
);

}

#endif
