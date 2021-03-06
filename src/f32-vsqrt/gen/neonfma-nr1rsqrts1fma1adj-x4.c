// Auto-generated file. Do not edit!
//   Template: src/f32-vsqrt/neonfma-nr1rsqrts1fma1adj.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <math.h>

#include <arm_neon.h>

#include <xnnpack/common.h>
#include <xnnpack/vunary.h>


void xnn_f32_vsqrt_ukernel__neonfma_nr1rsqrts1fma1adj_x4(
    size_t n,
    const float* x,
    float* y,
    const union xnn_f32_sqrt_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);

  if XNN_UNLIKELY(n != 0) {
    do {
      const float vx = *x++;
      const float vy = sqrtf(vx);
      *y++ = vy;
      n -= sizeof(float);
    } while (n != 0);
  }
}
