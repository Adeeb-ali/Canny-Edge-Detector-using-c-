#include <iostream>
#include "threshold.h"
#include <algorithm>
#include<vector>

using namespace std;

namespace img {

vector<vector<int>> doubleThreshold(
    const vector<vector<float>>& nms
) {
    int H =nms.size();
    int W =nms[0].size();
    vector<float> vals;

    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (nms[i][j] > 0.0f)
                vals.push_back(nms[i][j]);
        }
    }

   
    if (vals.empty()) {
        return vector<vector<int>>(H, vector<int>(W, 0));
    }

   
    sort(vals.begin(), vals.end());

    
    int idxHigh = static_cast<int>(0.80f * (vals.size() - 1));
    int idxLow  = static_cast<int>(0.40f * (vals.size() - 1));

    float high = vals[idxHigh];
    float low  = vals[idxLow];

    vector<vector<int>> edges(H, vector<int>(W, 0));

 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            float v = nms[i][j];

            if (v >= high)
                edges[i][j] = 255;   
            else if (v >= low)
                edges[i][j] = 75;    
            else
                edges[i][j] = 0;     
        }
    }

    return edges;
}

} 
