#include "pinv.hpp"
#include <time.h>
#include <stdio.h>

int main() {
    float a11, a12, a13, a21, a22, a23, a31, a32, a33;
    float pinv11, pinv12, pinv13, pinv21, pinv22, pinv23, pinv31, pinv32, pinv33;

    float i11, i12, i13, i21, i22, i23, i31, i32, i33;

    a11 = -0.558253f; a12 = -0.0461681f; a13 = -0.505735f;
    a21 = -0.411397f; a22 = 0.0365854f;  a23 = 0.199707f;
    a31 = 0.285389f;  a32 = -0.313789f;  a33 = 0.200189f;

    clock_t start, end;
    start = clock();
    pinv(a11, a12, a13, a21, a22, a23, a31, a32, a33,
        pinv11, pinv12, pinv13, pinv21, pinv22, pinv23, pinv31, pinv32, pinv33);
    end = clock();

    printf("Average pseudo inverse takes %f microseconds \n ", 1e6 * ((double)(end - start) / 1e6 / CLOCKS_PER_SEC));

    multAB(a11, a12, a13, a21, a22, a23, a31, a32, a33,
        pinv11, pinv12, pinv13, pinv21, pinv22, pinv23, pinv31, pinv32, pinv33,
        i11, i12, i13, i21, i22, i23, i31, i32, i33);

    return 0;
}