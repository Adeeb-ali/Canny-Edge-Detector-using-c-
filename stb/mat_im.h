#ifndef MAT_IM_H
#define MAT_IM_H

#include <vector>

namespace mat_im {

    bool matrix_to_image(
        const std::vector<std::vector<int>>& matrix,
        const char* name_of_file
    );

}

#endif
