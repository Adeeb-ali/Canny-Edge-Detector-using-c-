#include "hy.h"
#include <queue>
#include <utility>

using namespace std;

namespace img {

vector<vector<int>> hysteresis(
    const vector<vector<int>>& edges
) {
    int H = edges.size();
    int W = edges[0].size();

    const int STRONG = 255;
    const int WEAK   = 75;

    vector<vector<int>> finalEdges = edges;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    queue<pair<int, int>> q;

    int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (finalEdges[i][j] == STRONG) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    // BFS
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < H &&
                ny >= 0 && ny < W) {

                if (!visited[nx][ny] &&
                    finalEdges[nx][ny] == WEAK) {

                    finalEdges[nx][ny] = STRONG;
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

   
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (finalEdges[i][j] != STRONG)
                finalEdges[i][j] = 0;
        }
    }

    return finalEdges;
}

} 
