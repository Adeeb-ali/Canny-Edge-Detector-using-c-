#include <iostream>
#include <vector>
#include <new>   

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

namespace mat_im {

bool matrix_to_image(
    const vector<vector<int>>& matrix,
    const char* name_of_file
) {

    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int height = matrix.size();
    int width  = matrix[0].size();

    unsigned char* buffer = new (nothrow) unsigned char[width * height];
    if (!buffer) {
        return false;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            buffer[y * width + x] =
                static_cast<unsigned char>(matrix[y][x]);
        }
    }

    int result = stbi_write_png(
        name_of_file,
        width,
        height,
        1,
        buffer,
        width
    );

    delete[] buffer;

    return (result != 0);
}

}
