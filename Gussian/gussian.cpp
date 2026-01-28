#include "gussian.h"
#include <cmath>
#include<vector>
#include <algorithm>

using namespace std;

namespace img {

vector<vector<float>> gaussianBlur(
    const vector<vector<float>>& image,
    int kernelSize
) {
    int height = image.size();
    int width  = image[0].size();
    int k = kernelSize / 2;

    std::vector<vector<float>> output(
        height, vector<float>(width, 0.0f)
    );

    vector<vector<float>> kernel(
        kernelSize, vector<float>(kernelSize)
    );

    float sigma = kernelSize / 2.0f;
    float sum = 0.0f;

    for (int y = -k; y <= k; y++) {
        for (int x = -k; x <= k; x++) {
            float val = exp(-(x*x + y*y) / (2 * sigma * sigma));
            kernel[y + k][x + k] = val;
            sum += val;
        }
    }

  
    for (int y = 0; y < kernelSize; y++)
        for (int x = 0; x < kernelSize; x++)
            kernel[y][x] /= sum;

  
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            float acc = 0.0f;

            for (int ky = -k; ky <= k; ky++) {
                for (int kx = -k; kx <= k; kx++) {

                    int iy = y + ky;
                    int ix = x + kx;

                    if (iy >= 0 && iy < height &&
                        ix >= 0 && ix < width) {

                        acc += image[iy][ix] *
                               kernel[ky + k][kx + k];
                    }
                }
            }

            output[y][x] = acc;
        }
    }

    return output;
}

}
