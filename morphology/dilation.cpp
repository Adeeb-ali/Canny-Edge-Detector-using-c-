#include "dilation.h"

using namespace std;

namespace img {

vector<vector<int>> dilation(
    const vector<vector<int>>& finalImg
) {
    int H =finalImg.size();
    int W=finalImg[0].size();

    vector<vector<int>> output(H, vector<int>(W, 0));

   
    int dx[9] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
    int dy[9] = {-1, 0, 1,-1, 0, 1,-1, 0, 1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            bool hasEdge = false;

           
            for (int k = 0; k < 9; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < H &&
                    nj >= 0 && nj < W) {

                    if (finalImg[ni][nj] == 255) {
                        hasEdge = true;
                        break;
                    }
                }
            }

            
            output[i][j] = hasEdge ? 255 : 0;
        }
    }

    return output;
}

} 
