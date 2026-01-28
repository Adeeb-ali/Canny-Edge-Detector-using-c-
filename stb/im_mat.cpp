#include <iostream>
#include <vector>
#include "im_mat.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

namespace im_mat {
    vector<vector<int>> get_matrix(const char* path) {
        int width, height, channels;

        
        unsigned char* data = stbi_load(path, &width, &height, &channels, 1);

        if (!data) {
            cout << "Error: Could not load image at " << path << endl;
            return {}; 
        }

        vector<vector<int>> matrix(height, vector<int>(width));

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                matrix[y][x] = data[y * width + x];
            }
        }

        stbi_image_free(data);
        return matrix;
    }
}