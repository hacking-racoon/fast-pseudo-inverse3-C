#include "svd3.h"
#ifndef PINV_H
#define PINV_H

void pinv(float a11, float a12, float a13,
    float a21, float a22, float a23,
    float a31, float a32, float a33,
    // output P
    float* p11, float* p12, float* p13,
    float* p21, float* p22, float* p23,
    float* p31, float* p32, float* p33) {

    float u11, u12, u13, u21, u22, u23, u31, u32, u33;
    float s11, s12, s13, s21, s22, s23, s31, s32, s33;
    float v11, v12, v13, v21, v22, v23, v31, v32, v33;


    float vsp11, vsp12, vsp13, vsp21, vsp22, vsp23, vsp31, vsp32, vsp33;

    svd(a11, a12, a13, a21, a22, a23, a31, a32, a33,
        &u11, &u12, &u13, &u21, &u22, &u23, &u31, &u32, &u33,
        &s11, &s12, &s13, &s21, &s22, &s23, &s31, &s32, &s33,
        &v11, &v12, &v13, &v21, &v22, &v23, &v31, &v32, &v33);

    s11 = (s11 == 0 ? 0 : (1 / s11));
    s22 = (s22 == 0 ? 0 : (1 / s22));
    s33 = (s33 == 0 ? 0 : (1 / s33));

    multAB(v11, v12, v13, v21, v22, v23, v31, v32, v33,
        s11, s12, s13, s21, s22, s23, s31, s32, s33,
        &vsp11, &vsp12, &vsp13, &vsp21, &vsp22, &vsp23, &vsp31, &vsp32, &vsp33);

    swapf(&u12, &u21);
    swapf(&u13, &u31);
    swapf(&u23, &u32);

    multAB(vsp11, vsp12, vsp13, vsp21, vsp22, vsp23, vsp31, vsp32, vsp33,
        u11, u12, u13, u21, u22, u23, u31, u32, u33,
        p11, p12, p13, p21, p22, p23, p31, p32, p33);
}
#endif