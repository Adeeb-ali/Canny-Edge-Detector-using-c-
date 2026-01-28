#include "nms.h"
using namespace std;

namespace img {

vector<vector<float>> nonMaximumSuppression(
    const vector<vector<float>>& G,
    const vector<vector<float>>& theta
) {
    int H = G.size();
    int W = G[0].size();

    vector<vector<float>> nms(H, vector<float>(W, 0.0f));

    
    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {

            float angle = theta[i][j];
            float q = 0.0f, r = 0.0f;

            
            if ((angle >= 0.0f && angle < 22.5f) ||
                (angle >= 157.5f && angle < 180.0f)) {

                q = G[i][j + 1];
                r = G[i][j - 1];
            }
            
            else if (angle >= 22.5f && angle < 67.5f) {

                q = G[i + 1][j - 1];
                r = G[i - 1][j + 1];
            }
            
else if (angle >= 67.5f && angle < 112.5f) {

                q = G[i + 1][j];
                r = G[i - 1][j];
            }
            
            else {

                q = G[i - 1][j - 1];
                r = G[i + 1][j + 1];
            }
if (G[i][j] >= q && G[i][j] >= r) {
                nms[i][j] = G[i][j];
            } else {
                nms[i][j] = 0.0f;
            }
        }
    }

    return nms;
}

} 
