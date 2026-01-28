#include "sobel.h"
#include <cmath>

namespace img {

EdgeResult scharrEdge(
    const std::vector<std::vector<float>>& img
) {
    int H = img.size();
    int W = img[0].size();

    EdgeResult res;
    res.Gx.assign(H, std::vector<float>(W, 0.0f));
    res.Gy.assign(H, std::vector<float>(W, 0.0f));
    res.Mag.assign(H, std::vector<float>(W, 0.0f));
    res.Angle.assign(H, std::vector<float>(W, 0.0f));

    
    float Kx[3][3] = {
        {-3,  0,  3},
        {-10, 0, 10},
        {-3,  0,  3}
    };

    float Ky[3][3] = {
        {-3, -10, -3},
        { 0,   0,  0},
        { 3,  10,  3}
    };

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {

            float gx = 0.0f;
            float gy = 0.0f;

            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {

                    int iy = y + ky;
                    int ix = x + kx;

                    if (iy >= 0 && iy < H &&
                        ix >= 0 && ix < W) {

                        float p = img[iy][ix];
                        gx += p * Kx[ky + 1][kx + 1];
                        gy += p * Ky[ky + 1][kx + 1];
                    }
                }
            }

            res.Gx[y][x] = gx;
            res.Gy[y][x] = gy;
            res.Mag[y][x] = std::sqrt(gx * gx + gy * gy);

            
            float angle = std::atan2(gy, gx) * 180.0f / M_PI;

            if (angle < 0.0f)
                angle += 180.0f;

            if (angle >= 180.0f)
                angle -= 180.0f;

            res.Angle[y][x] = angle;
        }
    }

    return res;
}

} 
