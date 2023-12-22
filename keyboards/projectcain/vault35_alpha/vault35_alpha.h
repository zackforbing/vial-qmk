#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, \
    k20, k21, k22, k23, k24,      k26, k27, k28, k29, k2A, \
              k32, k33, k34,      k36, k37, k38 \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A }, \
    { k20, k21, k22, k23, k24, XXX, k26, k27, k28, k29, k2A }, \
    { XXX, XXX, k32, k33, k34, XXX, k36, k37, k38, XXX, XXX } \
}

