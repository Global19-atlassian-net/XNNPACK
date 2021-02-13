// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/MRxNRc4-scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/gemm.h>

#include <xnnpack/scalar-utils.h>

// This kernel is a scalar model for a kernel using ARMv8.2 dot-product
// instructions.
//
// XNN_DISABLE_TSAN is used because this kernel reads up to 3 bytes past the
// bounds of the `a` matrix region, which may be a race condition with
// another thread. We deem this acceptable because the values that are
// read out of bounds do not affect the result, and the the compiler can't know
// about this undefined behavior.

void xnn_qs8_igemm_minmax_ukernel_8x8c4__scalar(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(mr != 0);
  assert(mr <= 8);
  assert(nc != 0);
  assert(kc != 0);
  assert(ks != 0);
  assert(ks % (8 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  int8_t* c0 = c;
  int8_t* c1 = (int8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    c1 = c0;
  }
  int8_t* c2 = (int8_t*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    c2 = c1;
  }
  int8_t* c3 = (int8_t*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 4) {
    c3 = c2;
  }
  int8_t* c4 = (int8_t*) ((uintptr_t) c3 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 4) {
    c4 = c3;
  }
  int8_t* c5 = (int8_t*) ((uintptr_t) c4 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 6) {
    c5 = c4;
  }
  int8_t* c6 = (int8_t*) ((uintptr_t) c5 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 6) {
    c6 = c5;
  }
  int8_t* c7 = (int8_t*) ((uintptr_t) c6 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 8) {
    c7 = c6;
  }

  // Loop over groups of 8 columns.
  do {
    int32_t vacc00 = ((const int32_t*) w)[0];
    int32_t vacc01 = ((const int32_t*) w)[1];
    int32_t vacc02 = ((const int32_t*) w)[2];
    int32_t vacc03 = ((const int32_t*) w)[3];
    int32_t vacc04 = ((const int32_t*) w)[4];
    int32_t vacc05 = ((const int32_t*) w)[5];
    int32_t vacc06 = ((const int32_t*) w)[6];
    int32_t vacc07 = ((const int32_t*) w)[7];
    int32_t vacc10 = vacc00;
    int32_t vacc11 = vacc01;
    int32_t vacc12 = vacc02;
    int32_t vacc13 = vacc03;
    int32_t vacc14 = vacc04;
    int32_t vacc15 = vacc05;
    int32_t vacc16 = vacc06;
    int32_t vacc17 = vacc07;
    int32_t vacc20 = vacc00;
    int32_t vacc21 = vacc01;
    int32_t vacc22 = vacc02;
    int32_t vacc23 = vacc03;
    int32_t vacc24 = vacc04;
    int32_t vacc25 = vacc05;
    int32_t vacc26 = vacc06;
    int32_t vacc27 = vacc07;
    int32_t vacc30 = vacc00;
    int32_t vacc31 = vacc01;
    int32_t vacc32 = vacc02;
    int32_t vacc33 = vacc03;
    int32_t vacc34 = vacc04;
    int32_t vacc35 = vacc05;
    int32_t vacc36 = vacc06;
    int32_t vacc37 = vacc07;
    int32_t vacc40 = vacc00;
    int32_t vacc41 = vacc01;
    int32_t vacc42 = vacc02;
    int32_t vacc43 = vacc03;
    int32_t vacc44 = vacc04;
    int32_t vacc45 = vacc05;
    int32_t vacc46 = vacc06;
    int32_t vacc47 = vacc07;
    int32_t vacc50 = vacc00;
    int32_t vacc51 = vacc01;
    int32_t vacc52 = vacc02;
    int32_t vacc53 = vacc03;
    int32_t vacc54 = vacc04;
    int32_t vacc55 = vacc05;
    int32_t vacc56 = vacc06;
    int32_t vacc57 = vacc07;
    int32_t vacc60 = vacc00;
    int32_t vacc61 = vacc01;
    int32_t vacc62 = vacc02;
    int32_t vacc63 = vacc03;
    int32_t vacc64 = vacc04;
    int32_t vacc65 = vacc05;
    int32_t vacc66 = vacc06;
    int32_t vacc67 = vacc07;
    int32_t vacc70 = vacc00;
    int32_t vacc71 = vacc01;
    int32_t vacc72 = vacc02;
    int32_t vacc73 = vacc03;
    int32_t vacc74 = vacc04;
    int32_t vacc75 = vacc05;
    int32_t vacc76 = vacc06;
    int32_t vacc77 = vacc07;

    w = (const void*)((uintptr_t) w + 8 * sizeof(int32_t));

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      }
      const int8_t* restrict a1 = a[1];
      if XNN_UNPREDICTABLE(a1 != zero) {
        a1 = (const int8_t*) ((uintptr_t) a1 + a_offset);
      }
      const int8_t* restrict a2 = a[2];
      if XNN_UNPREDICTABLE(a2 != zero) {
        a2 = (const int8_t*) ((uintptr_t) a2 + a_offset);
      }
      const int8_t* restrict a3 = a[3];
      if XNN_UNPREDICTABLE(a3 != zero) {
        a3 = (const int8_t*) ((uintptr_t) a3 + a_offset);
      }
      const int8_t* restrict a4 = a[4];
      if XNN_UNPREDICTABLE(a4 != zero) {
        a4 = (const int8_t*) ((uintptr_t) a4 + a_offset);
      }
      const int8_t* restrict a5 = a[5];
      if XNN_UNPREDICTABLE(a5 != zero) {
        a5 = (const int8_t*) ((uintptr_t) a5 + a_offset);
      }
      const int8_t* restrict a6 = a[6];
      if XNN_UNPREDICTABLE(a6 != zero) {
        a6 = (const int8_t*) ((uintptr_t) a6 + a_offset);
      }
      const int8_t* restrict a7 = a[7];
      if XNN_UNPREDICTABLE(a7 != zero) {
        a7 = (const int8_t*) ((uintptr_t) a7 + a_offset);
      }
      a += 8;

      // Inner accumulation loop along the 8 columns.
      // Handle 4 rows at each iteration: this is key to modelling what an
      // actual kernel using ARMv8.2 dot-product instructions would look like.
      size_t k = 0;
      while (k < kc) {
        // Load a 8x4 block of activations.
        int32_t va00 = *a0++;
        int32_t va01 = *a0++;
        int32_t va02 = *a0++;
        int32_t va03 = *a0++;
        int32_t va10 = *a1++;
        int32_t va11 = *a1++;
        int32_t va12 = *a1++;
        int32_t va13 = *a1++;
        int32_t va20 = *a2++;
        int32_t va21 = *a2++;
        int32_t va22 = *a2++;
        int32_t va23 = *a2++;
        int32_t va30 = *a3++;
        int32_t va31 = *a3++;
        int32_t va32 = *a3++;
        int32_t va33 = *a3++;
        int32_t va40 = *a4++;
        int32_t va41 = *a4++;
        int32_t va42 = *a4++;
        int32_t va43 = *a4++;
        int32_t va50 = *a5++;
        int32_t va51 = *a5++;
        int32_t va52 = *a5++;
        int32_t va53 = *a5++;
        int32_t va60 = *a6++;
        int32_t va61 = *a6++;
        int32_t va62 = *a6++;
        int32_t va63 = *a6++;
        int32_t va70 = *a7++;
        int32_t va71 = *a7++;
        int32_t va72 = *a7++;
        int32_t va73 = *a7++;

        // Load a 4x8 block of weights.
        int32_t vb00 = ((const int8_t*)w)[0];
        int32_t vb10 = ((const int8_t*)w)[1];
        int32_t vb20 = ((const int8_t*)w)[2];
        int32_t vb30 = ((const int8_t*)w)[3];
        int32_t vb01 = ((const int8_t*)w)[0];
        int32_t vb11 = ((const int8_t*)w)[1];
        int32_t vb21 = ((const int8_t*)w)[2];
        int32_t vb31 = ((const int8_t*)w)[3];
        int32_t vb02 = ((const int8_t*)w)[0];
        int32_t vb12 = ((const int8_t*)w)[1];
        int32_t vb22 = ((const int8_t*)w)[2];
        int32_t vb32 = ((const int8_t*)w)[3];
        int32_t vb03 = ((const int8_t*)w)[0];
        int32_t vb13 = ((const int8_t*)w)[1];
        int32_t vb23 = ((const int8_t*)w)[2];
        int32_t vb33 = ((const int8_t*)w)[3];
        int32_t vb04 = ((const int8_t*)w)[0];
        int32_t vb14 = ((const int8_t*)w)[1];
        int32_t vb24 = ((const int8_t*)w)[2];
        int32_t vb34 = ((const int8_t*)w)[3];
        int32_t vb05 = ((const int8_t*)w)[0];
        int32_t vb15 = ((const int8_t*)w)[1];
        int32_t vb25 = ((const int8_t*)w)[2];
        int32_t vb35 = ((const int8_t*)w)[3];
        int32_t vb06 = ((const int8_t*)w)[0];
        int32_t vb16 = ((const int8_t*)w)[1];
        int32_t vb26 = ((const int8_t*)w)[2];
        int32_t vb36 = ((const int8_t*)w)[3];
        int32_t vb07 = ((const int8_t*)w)[0];
        int32_t vb17 = ((const int8_t*)w)[1];
        int32_t vb27 = ((const int8_t*)w)[2];
        int32_t vb37 = ((const int8_t*)w)[3];

        w = (const void*)((uintptr_t)w + 4 * sizeof(int8_t));

        // Multiply-accumulate: 8x4 * 4x8 --> 8x8. The inner size 4 here means
        // we're computing 4D dot-products, which makes this a model for
        // a ARMv8.2 dot-product kernel.
        vacc00 += va00 * vb00;
        vacc00 += va01 * vb10;
        vacc00 += va02 * vb20;
        vacc00 += va03 * vb30;
        vacc01 += va00 * vb01;
        vacc01 += va01 * vb11;
        vacc01 += va02 * vb21;
        vacc01 += va03 * vb31;
        vacc02 += va00 * vb02;
        vacc02 += va01 * vb12;
        vacc02 += va02 * vb22;
        vacc02 += va03 * vb32;
        vacc03 += va00 * vb03;
        vacc03 += va01 * vb13;
        vacc03 += va02 * vb23;
        vacc03 += va03 * vb33;
        vacc04 += va00 * vb04;
        vacc04 += va01 * vb14;
        vacc04 += va02 * vb24;
        vacc04 += va03 * vb34;
        vacc05 += va00 * vb05;
        vacc05 += va01 * vb15;
        vacc05 += va02 * vb25;
        vacc05 += va03 * vb35;
        vacc06 += va00 * vb06;
        vacc06 += va01 * vb16;
        vacc06 += va02 * vb26;
        vacc06 += va03 * vb36;
        vacc07 += va00 * vb07;
        vacc07 += va01 * vb17;
        vacc07 += va02 * vb27;
        vacc07 += va03 * vb37;
        vacc10 += va10 * vb00;
        vacc10 += va11 * vb10;
        vacc10 += va12 * vb20;
        vacc10 += va13 * vb30;
        vacc11 += va10 * vb01;
        vacc11 += va11 * vb11;
        vacc11 += va12 * vb21;
        vacc11 += va13 * vb31;
        vacc12 += va10 * vb02;
        vacc12 += va11 * vb12;
        vacc12 += va12 * vb22;
        vacc12 += va13 * vb32;
        vacc13 += va10 * vb03;
        vacc13 += va11 * vb13;
        vacc13 += va12 * vb23;
        vacc13 += va13 * vb33;
        vacc14 += va10 * vb04;
        vacc14 += va11 * vb14;
        vacc14 += va12 * vb24;
        vacc14 += va13 * vb34;
        vacc15 += va10 * vb05;
        vacc15 += va11 * vb15;
        vacc15 += va12 * vb25;
        vacc15 += va13 * vb35;
        vacc16 += va10 * vb06;
        vacc16 += va11 * vb16;
        vacc16 += va12 * vb26;
        vacc16 += va13 * vb36;
        vacc17 += va10 * vb07;
        vacc17 += va11 * vb17;
        vacc17 += va12 * vb27;
        vacc17 += va13 * vb37;
        vacc20 += va20 * vb00;
        vacc20 += va21 * vb10;
        vacc20 += va22 * vb20;
        vacc20 += va23 * vb30;
        vacc21 += va20 * vb01;
        vacc21 += va21 * vb11;
        vacc21 += va22 * vb21;
        vacc21 += va23 * vb31;
        vacc22 += va20 * vb02;
        vacc22 += va21 * vb12;
        vacc22 += va22 * vb22;
        vacc22 += va23 * vb32;
        vacc23 += va20 * vb03;
        vacc23 += va21 * vb13;
        vacc23 += va22 * vb23;
        vacc23 += va23 * vb33;
        vacc24 += va20 * vb04;
        vacc24 += va21 * vb14;
        vacc24 += va22 * vb24;
        vacc24 += va23 * vb34;
        vacc25 += va20 * vb05;
        vacc25 += va21 * vb15;
        vacc25 += va22 * vb25;
        vacc25 += va23 * vb35;
        vacc26 += va20 * vb06;
        vacc26 += va21 * vb16;
        vacc26 += va22 * vb26;
        vacc26 += va23 * vb36;
        vacc27 += va20 * vb07;
        vacc27 += va21 * vb17;
        vacc27 += va22 * vb27;
        vacc27 += va23 * vb37;
        vacc30 += va30 * vb00;
        vacc30 += va31 * vb10;
        vacc30 += va32 * vb20;
        vacc30 += va33 * vb30;
        vacc31 += va30 * vb01;
        vacc31 += va31 * vb11;
        vacc31 += va32 * vb21;
        vacc31 += va33 * vb31;
        vacc32 += va30 * vb02;
        vacc32 += va31 * vb12;
        vacc32 += va32 * vb22;
        vacc32 += va33 * vb32;
        vacc33 += va30 * vb03;
        vacc33 += va31 * vb13;
        vacc33 += va32 * vb23;
        vacc33 += va33 * vb33;
        vacc34 += va30 * vb04;
        vacc34 += va31 * vb14;
        vacc34 += va32 * vb24;
        vacc34 += va33 * vb34;
        vacc35 += va30 * vb05;
        vacc35 += va31 * vb15;
        vacc35 += va32 * vb25;
        vacc35 += va33 * vb35;
        vacc36 += va30 * vb06;
        vacc36 += va31 * vb16;
        vacc36 += va32 * vb26;
        vacc36 += va33 * vb36;
        vacc37 += va30 * vb07;
        vacc37 += va31 * vb17;
        vacc37 += va32 * vb27;
        vacc37 += va33 * vb37;
        vacc40 += va40 * vb00;
        vacc40 += va41 * vb10;
        vacc40 += va42 * vb20;
        vacc40 += va43 * vb30;
        vacc41 += va40 * vb01;
        vacc41 += va41 * vb11;
        vacc41 += va42 * vb21;
        vacc41 += va43 * vb31;
        vacc42 += va40 * vb02;
        vacc42 += va41 * vb12;
        vacc42 += va42 * vb22;
        vacc42 += va43 * vb32;
        vacc43 += va40 * vb03;
        vacc43 += va41 * vb13;
        vacc43 += va42 * vb23;
        vacc43 += va43 * vb33;
        vacc44 += va40 * vb04;
        vacc44 += va41 * vb14;
        vacc44 += va42 * vb24;
        vacc44 += va43 * vb34;
        vacc45 += va40 * vb05;
        vacc45 += va41 * vb15;
        vacc45 += va42 * vb25;
        vacc45 += va43 * vb35;
        vacc46 += va40 * vb06;
        vacc46 += va41 * vb16;
        vacc46 += va42 * vb26;
        vacc46 += va43 * vb36;
        vacc47 += va40 * vb07;
        vacc47 += va41 * vb17;
        vacc47 += va42 * vb27;
        vacc47 += va43 * vb37;
        vacc50 += va50 * vb00;
        vacc50 += va51 * vb10;
        vacc50 += va52 * vb20;
        vacc50 += va53 * vb30;
        vacc51 += va50 * vb01;
        vacc51 += va51 * vb11;
        vacc51 += va52 * vb21;
        vacc51 += va53 * vb31;
        vacc52 += va50 * vb02;
        vacc52 += va51 * vb12;
        vacc52 += va52 * vb22;
        vacc52 += va53 * vb32;
        vacc53 += va50 * vb03;
        vacc53 += va51 * vb13;
        vacc53 += va52 * vb23;
        vacc53 += va53 * vb33;
        vacc54 += va50 * vb04;
        vacc54 += va51 * vb14;
        vacc54 += va52 * vb24;
        vacc54 += va53 * vb34;
        vacc55 += va50 * vb05;
        vacc55 += va51 * vb15;
        vacc55 += va52 * vb25;
        vacc55 += va53 * vb35;
        vacc56 += va50 * vb06;
        vacc56 += va51 * vb16;
        vacc56 += va52 * vb26;
        vacc56 += va53 * vb36;
        vacc57 += va50 * vb07;
        vacc57 += va51 * vb17;
        vacc57 += va52 * vb27;
        vacc57 += va53 * vb37;
        vacc60 += va60 * vb00;
        vacc60 += va61 * vb10;
        vacc60 += va62 * vb20;
        vacc60 += va63 * vb30;
        vacc61 += va60 * vb01;
        vacc61 += va61 * vb11;
        vacc61 += va62 * vb21;
        vacc61 += va63 * vb31;
        vacc62 += va60 * vb02;
        vacc62 += va61 * vb12;
        vacc62 += va62 * vb22;
        vacc62 += va63 * vb32;
        vacc63 += va60 * vb03;
        vacc63 += va61 * vb13;
        vacc63 += va62 * vb23;
        vacc63 += va63 * vb33;
        vacc64 += va60 * vb04;
        vacc64 += va61 * vb14;
        vacc64 += va62 * vb24;
        vacc64 += va63 * vb34;
        vacc65 += va60 * vb05;
        vacc65 += va61 * vb15;
        vacc65 += va62 * vb25;
        vacc65 += va63 * vb35;
        vacc66 += va60 * vb06;
        vacc66 += va61 * vb16;
        vacc66 += va62 * vb26;
        vacc66 += va63 * vb36;
        vacc67 += va60 * vb07;
        vacc67 += va61 * vb17;
        vacc67 += va62 * vb27;
        vacc67 += va63 * vb37;
        vacc70 += va70 * vb00;
        vacc70 += va71 * vb10;
        vacc70 += va72 * vb20;
        vacc70 += va73 * vb30;
        vacc71 += va70 * vb01;
        vacc71 += va71 * vb11;
        vacc71 += va72 * vb21;
        vacc71 += va73 * vb31;
        vacc72 += va70 * vb02;
        vacc72 += va71 * vb12;
        vacc72 += va72 * vb22;
        vacc72 += va73 * vb32;
        vacc73 += va70 * vb03;
        vacc73 += va71 * vb13;
        vacc73 += va72 * vb23;
        vacc73 += va73 * vb33;
        vacc74 += va70 * vb04;
        vacc74 += va71 * vb14;
        vacc74 += va72 * vb24;
        vacc74 += va73 * vb34;
        vacc75 += va70 * vb05;
        vacc75 += va71 * vb15;
        vacc75 += va72 * vb25;
        vacc75 += va73 * vb35;
        vacc76 += va70 * vb06;
        vacc76 += va71 * vb16;
        vacc76 += va72 * vb26;
        vacc76 += va73 * vb36;
        vacc77 += va70 * vb07;
        vacc77 += va71 * vb17;
        vacc77 += va72 * vb27;
        vacc77 += va73 * vb37;

        k += 4 * sizeof(int8_t);
      }

      p -= 8 * sizeof(void*);
    } while (p != 0);

    // Post-accumulation work

    const int32_t vmultiplier = params->scalar.multiplier;
    const int64_t vq31rounding = INT64_C(0x40000000);
    const int32_t vremainder_mask = params->scalar.remainder_mask;
    const uint32_t vshift = params->scalar.shift;
    const int32_t vremainder_threshold = params->scalar.remainder_threshold;
    const int32_t voutput_min = params->scalar.output_min_less_zero_point;
    const int32_t voutput_max = params->scalar.output_max_less_zero_point;
    const int32_t voutput_zero_point = params->scalar.output_zero_point;

    const int64_t vproduct00 = (int64_t)vacc00 * (int64_t)vmultiplier;
    const int64_t vproduct01 = (int64_t)vacc01 * (int64_t)vmultiplier;
    const int64_t vproduct02 = (int64_t)vacc02 * (int64_t)vmultiplier;
    const int64_t vproduct03 = (int64_t)vacc03 * (int64_t)vmultiplier;
    const int64_t vproduct04 = (int64_t)vacc04 * (int64_t)vmultiplier;
    const int64_t vproduct05 = (int64_t)vacc05 * (int64_t)vmultiplier;
    const int64_t vproduct06 = (int64_t)vacc06 * (int64_t)vmultiplier;
    const int64_t vproduct07 = (int64_t)vacc07 * (int64_t)vmultiplier;
    const int64_t vproduct10 = (int64_t)vacc10 * (int64_t)vmultiplier;
    const int64_t vproduct11 = (int64_t)vacc11 * (int64_t)vmultiplier;
    const int64_t vproduct12 = (int64_t)vacc12 * (int64_t)vmultiplier;
    const int64_t vproduct13 = (int64_t)vacc13 * (int64_t)vmultiplier;
    const int64_t vproduct14 = (int64_t)vacc14 * (int64_t)vmultiplier;
    const int64_t vproduct15 = (int64_t)vacc15 * (int64_t)vmultiplier;
    const int64_t vproduct16 = (int64_t)vacc16 * (int64_t)vmultiplier;
    const int64_t vproduct17 = (int64_t)vacc17 * (int64_t)vmultiplier;
    const int64_t vproduct20 = (int64_t)vacc20 * (int64_t)vmultiplier;
    const int64_t vproduct21 = (int64_t)vacc21 * (int64_t)vmultiplier;
    const int64_t vproduct22 = (int64_t)vacc22 * (int64_t)vmultiplier;
    const int64_t vproduct23 = (int64_t)vacc23 * (int64_t)vmultiplier;
    const int64_t vproduct24 = (int64_t)vacc24 * (int64_t)vmultiplier;
    const int64_t vproduct25 = (int64_t)vacc25 * (int64_t)vmultiplier;
    const int64_t vproduct26 = (int64_t)vacc26 * (int64_t)vmultiplier;
    const int64_t vproduct27 = (int64_t)vacc27 * (int64_t)vmultiplier;
    const int64_t vproduct30 = (int64_t)vacc30 * (int64_t)vmultiplier;
    const int64_t vproduct31 = (int64_t)vacc31 * (int64_t)vmultiplier;
    const int64_t vproduct32 = (int64_t)vacc32 * (int64_t)vmultiplier;
    const int64_t vproduct33 = (int64_t)vacc33 * (int64_t)vmultiplier;
    const int64_t vproduct34 = (int64_t)vacc34 * (int64_t)vmultiplier;
    const int64_t vproduct35 = (int64_t)vacc35 * (int64_t)vmultiplier;
    const int64_t vproduct36 = (int64_t)vacc36 * (int64_t)vmultiplier;
    const int64_t vproduct37 = (int64_t)vacc37 * (int64_t)vmultiplier;
    const int64_t vproduct40 = (int64_t)vacc40 * (int64_t)vmultiplier;
    const int64_t vproduct41 = (int64_t)vacc41 * (int64_t)vmultiplier;
    const int64_t vproduct42 = (int64_t)vacc42 * (int64_t)vmultiplier;
    const int64_t vproduct43 = (int64_t)vacc43 * (int64_t)vmultiplier;
    const int64_t vproduct44 = (int64_t)vacc44 * (int64_t)vmultiplier;
    const int64_t vproduct45 = (int64_t)vacc45 * (int64_t)vmultiplier;
    const int64_t vproduct46 = (int64_t)vacc46 * (int64_t)vmultiplier;
    const int64_t vproduct47 = (int64_t)vacc47 * (int64_t)vmultiplier;
    const int64_t vproduct50 = (int64_t)vacc50 * (int64_t)vmultiplier;
    const int64_t vproduct51 = (int64_t)vacc51 * (int64_t)vmultiplier;
    const int64_t vproduct52 = (int64_t)vacc52 * (int64_t)vmultiplier;
    const int64_t vproduct53 = (int64_t)vacc53 * (int64_t)vmultiplier;
    const int64_t vproduct54 = (int64_t)vacc54 * (int64_t)vmultiplier;
    const int64_t vproduct55 = (int64_t)vacc55 * (int64_t)vmultiplier;
    const int64_t vproduct56 = (int64_t)vacc56 * (int64_t)vmultiplier;
    const int64_t vproduct57 = (int64_t)vacc57 * (int64_t)vmultiplier;
    const int64_t vproduct60 = (int64_t)vacc60 * (int64_t)vmultiplier;
    const int64_t vproduct61 = (int64_t)vacc61 * (int64_t)vmultiplier;
    const int64_t vproduct62 = (int64_t)vacc62 * (int64_t)vmultiplier;
    const int64_t vproduct63 = (int64_t)vacc63 * (int64_t)vmultiplier;
    const int64_t vproduct64 = (int64_t)vacc64 * (int64_t)vmultiplier;
    const int64_t vproduct65 = (int64_t)vacc65 * (int64_t)vmultiplier;
    const int64_t vproduct66 = (int64_t)vacc66 * (int64_t)vmultiplier;
    const int64_t vproduct67 = (int64_t)vacc67 * (int64_t)vmultiplier;
    const int64_t vproduct70 = (int64_t)vacc70 * (int64_t)vmultiplier;
    const int64_t vproduct71 = (int64_t)vacc71 * (int64_t)vmultiplier;
    const int64_t vproduct72 = (int64_t)vacc72 * (int64_t)vmultiplier;
    const int64_t vproduct73 = (int64_t)vacc73 * (int64_t)vmultiplier;
    const int64_t vproduct74 = (int64_t)vacc74 * (int64_t)vmultiplier;
    const int64_t vproduct75 = (int64_t)vacc75 * (int64_t)vmultiplier;
    const int64_t vproduct76 = (int64_t)vacc76 * (int64_t)vmultiplier;
    const int64_t vproduct77 = (int64_t)vacc77 * (int64_t)vmultiplier;

    const int32_t vq31product00 = (int32_t)(uint32_t)((uint64_t)(vproduct00 + vq31rounding) >> 31);
    const int32_t vq31product01 = (int32_t)(uint32_t)((uint64_t)(vproduct01 + vq31rounding) >> 31);
    const int32_t vq31product02 = (int32_t)(uint32_t)((uint64_t)(vproduct02 + vq31rounding) >> 31);
    const int32_t vq31product03 = (int32_t)(uint32_t)((uint64_t)(vproduct03 + vq31rounding) >> 31);
    const int32_t vq31product04 = (int32_t)(uint32_t)((uint64_t)(vproduct04 + vq31rounding) >> 31);
    const int32_t vq31product05 = (int32_t)(uint32_t)((uint64_t)(vproduct05 + vq31rounding) >> 31);
    const int32_t vq31product06 = (int32_t)(uint32_t)((uint64_t)(vproduct06 + vq31rounding) >> 31);
    const int32_t vq31product07 = (int32_t)(uint32_t)((uint64_t)(vproduct07 + vq31rounding) >> 31);
    const int32_t vq31product10 = (int32_t)(uint32_t)((uint64_t)(vproduct10 + vq31rounding) >> 31);
    const int32_t vq31product11 = (int32_t)(uint32_t)((uint64_t)(vproduct11 + vq31rounding) >> 31);
    const int32_t vq31product12 = (int32_t)(uint32_t)((uint64_t)(vproduct12 + vq31rounding) >> 31);
    const int32_t vq31product13 = (int32_t)(uint32_t)((uint64_t)(vproduct13 + vq31rounding) >> 31);
    const int32_t vq31product14 = (int32_t)(uint32_t)((uint64_t)(vproduct14 + vq31rounding) >> 31);
    const int32_t vq31product15 = (int32_t)(uint32_t)((uint64_t)(vproduct15 + vq31rounding) >> 31);
    const int32_t vq31product16 = (int32_t)(uint32_t)((uint64_t)(vproduct16 + vq31rounding) >> 31);
    const int32_t vq31product17 = (int32_t)(uint32_t)((uint64_t)(vproduct17 + vq31rounding) >> 31);
    const int32_t vq31product20 = (int32_t)(uint32_t)((uint64_t)(vproduct20 + vq31rounding) >> 31);
    const int32_t vq31product21 = (int32_t)(uint32_t)((uint64_t)(vproduct21 + vq31rounding) >> 31);
    const int32_t vq31product22 = (int32_t)(uint32_t)((uint64_t)(vproduct22 + vq31rounding) >> 31);
    const int32_t vq31product23 = (int32_t)(uint32_t)((uint64_t)(vproduct23 + vq31rounding) >> 31);
    const int32_t vq31product24 = (int32_t)(uint32_t)((uint64_t)(vproduct24 + vq31rounding) >> 31);
    const int32_t vq31product25 = (int32_t)(uint32_t)((uint64_t)(vproduct25 + vq31rounding) >> 31);
    const int32_t vq31product26 = (int32_t)(uint32_t)((uint64_t)(vproduct26 + vq31rounding) >> 31);
    const int32_t vq31product27 = (int32_t)(uint32_t)((uint64_t)(vproduct27 + vq31rounding) >> 31);
    const int32_t vq31product30 = (int32_t)(uint32_t)((uint64_t)(vproduct30 + vq31rounding) >> 31);
    const int32_t vq31product31 = (int32_t)(uint32_t)((uint64_t)(vproduct31 + vq31rounding) >> 31);
    const int32_t vq31product32 = (int32_t)(uint32_t)((uint64_t)(vproduct32 + vq31rounding) >> 31);
    const int32_t vq31product33 = (int32_t)(uint32_t)((uint64_t)(vproduct33 + vq31rounding) >> 31);
    const int32_t vq31product34 = (int32_t)(uint32_t)((uint64_t)(vproduct34 + vq31rounding) >> 31);
    const int32_t vq31product35 = (int32_t)(uint32_t)((uint64_t)(vproduct35 + vq31rounding) >> 31);
    const int32_t vq31product36 = (int32_t)(uint32_t)((uint64_t)(vproduct36 + vq31rounding) >> 31);
    const int32_t vq31product37 = (int32_t)(uint32_t)((uint64_t)(vproduct37 + vq31rounding) >> 31);
    const int32_t vq31product40 = (int32_t)(uint32_t)((uint64_t)(vproduct40 + vq31rounding) >> 31);
    const int32_t vq31product41 = (int32_t)(uint32_t)((uint64_t)(vproduct41 + vq31rounding) >> 31);
    const int32_t vq31product42 = (int32_t)(uint32_t)((uint64_t)(vproduct42 + vq31rounding) >> 31);
    const int32_t vq31product43 = (int32_t)(uint32_t)((uint64_t)(vproduct43 + vq31rounding) >> 31);
    const int32_t vq31product44 = (int32_t)(uint32_t)((uint64_t)(vproduct44 + vq31rounding) >> 31);
    const int32_t vq31product45 = (int32_t)(uint32_t)((uint64_t)(vproduct45 + vq31rounding) >> 31);
    const int32_t vq31product46 = (int32_t)(uint32_t)((uint64_t)(vproduct46 + vq31rounding) >> 31);
    const int32_t vq31product47 = (int32_t)(uint32_t)((uint64_t)(vproduct47 + vq31rounding) >> 31);
    const int32_t vq31product50 = (int32_t)(uint32_t)((uint64_t)(vproduct50 + vq31rounding) >> 31);
    const int32_t vq31product51 = (int32_t)(uint32_t)((uint64_t)(vproduct51 + vq31rounding) >> 31);
    const int32_t vq31product52 = (int32_t)(uint32_t)((uint64_t)(vproduct52 + vq31rounding) >> 31);
    const int32_t vq31product53 = (int32_t)(uint32_t)((uint64_t)(vproduct53 + vq31rounding) >> 31);
    const int32_t vq31product54 = (int32_t)(uint32_t)((uint64_t)(vproduct54 + vq31rounding) >> 31);
    const int32_t vq31product55 = (int32_t)(uint32_t)((uint64_t)(vproduct55 + vq31rounding) >> 31);
    const int32_t vq31product56 = (int32_t)(uint32_t)((uint64_t)(vproduct56 + vq31rounding) >> 31);
    const int32_t vq31product57 = (int32_t)(uint32_t)((uint64_t)(vproduct57 + vq31rounding) >> 31);
    const int32_t vq31product60 = (int32_t)(uint32_t)((uint64_t)(vproduct60 + vq31rounding) >> 31);
    const int32_t vq31product61 = (int32_t)(uint32_t)((uint64_t)(vproduct61 + vq31rounding) >> 31);
    const int32_t vq31product62 = (int32_t)(uint32_t)((uint64_t)(vproduct62 + vq31rounding) >> 31);
    const int32_t vq31product63 = (int32_t)(uint32_t)((uint64_t)(vproduct63 + vq31rounding) >> 31);
    const int32_t vq31product64 = (int32_t)(uint32_t)((uint64_t)(vproduct64 + vq31rounding) >> 31);
    const int32_t vq31product65 = (int32_t)(uint32_t)((uint64_t)(vproduct65 + vq31rounding) >> 31);
    const int32_t vq31product66 = (int32_t)(uint32_t)((uint64_t)(vproduct66 + vq31rounding) >> 31);
    const int32_t vq31product67 = (int32_t)(uint32_t)((uint64_t)(vproduct67 + vq31rounding) >> 31);
    const int32_t vq31product70 = (int32_t)(uint32_t)((uint64_t)(vproduct70 + vq31rounding) >> 31);
    const int32_t vq31product71 = (int32_t)(uint32_t)((uint64_t)(vproduct71 + vq31rounding) >> 31);
    const int32_t vq31product72 = (int32_t)(uint32_t)((uint64_t)(vproduct72 + vq31rounding) >> 31);
    const int32_t vq31product73 = (int32_t)(uint32_t)((uint64_t)(vproduct73 + vq31rounding) >> 31);
    const int32_t vq31product74 = (int32_t)(uint32_t)((uint64_t)(vproduct74 + vq31rounding) >> 31);
    const int32_t vq31product75 = (int32_t)(uint32_t)((uint64_t)(vproduct75 + vq31rounding) >> 31);
    const int32_t vq31product76 = (int32_t)(uint32_t)((uint64_t)(vproduct76 + vq31rounding) >> 31);
    const int32_t vq31product77 = (int32_t)(uint32_t)((uint64_t)(vproduct77 + vq31rounding) >> 31);

    const int32_t vremainder00 = (vq31product00 & vremainder_mask) - (int32_t)(vq31product00 < 0);
    const int32_t vremainder01 = (vq31product01 & vremainder_mask) - (int32_t)(vq31product01 < 0);
    const int32_t vremainder02 = (vq31product02 & vremainder_mask) - (int32_t)(vq31product02 < 0);
    const int32_t vremainder03 = (vq31product03 & vremainder_mask) - (int32_t)(vq31product03 < 0);
    const int32_t vremainder04 = (vq31product04 & vremainder_mask) - (int32_t)(vq31product04 < 0);
    const int32_t vremainder05 = (vq31product05 & vremainder_mask) - (int32_t)(vq31product05 < 0);
    const int32_t vremainder06 = (vq31product06 & vremainder_mask) - (int32_t)(vq31product06 < 0);
    const int32_t vremainder07 = (vq31product07 & vremainder_mask) - (int32_t)(vq31product07 < 0);
    const int32_t vremainder10 = (vq31product10 & vremainder_mask) - (int32_t)(vq31product10 < 0);
    const int32_t vremainder11 = (vq31product11 & vremainder_mask) - (int32_t)(vq31product11 < 0);
    const int32_t vremainder12 = (vq31product12 & vremainder_mask) - (int32_t)(vq31product12 < 0);
    const int32_t vremainder13 = (vq31product13 & vremainder_mask) - (int32_t)(vq31product13 < 0);
    const int32_t vremainder14 = (vq31product14 & vremainder_mask) - (int32_t)(vq31product14 < 0);
    const int32_t vremainder15 = (vq31product15 & vremainder_mask) - (int32_t)(vq31product15 < 0);
    const int32_t vremainder16 = (vq31product16 & vremainder_mask) - (int32_t)(vq31product16 < 0);
    const int32_t vremainder17 = (vq31product17 & vremainder_mask) - (int32_t)(vq31product17 < 0);
    const int32_t vremainder20 = (vq31product20 & vremainder_mask) - (int32_t)(vq31product20 < 0);
    const int32_t vremainder21 = (vq31product21 & vremainder_mask) - (int32_t)(vq31product21 < 0);
    const int32_t vremainder22 = (vq31product22 & vremainder_mask) - (int32_t)(vq31product22 < 0);
    const int32_t vremainder23 = (vq31product23 & vremainder_mask) - (int32_t)(vq31product23 < 0);
    const int32_t vremainder24 = (vq31product24 & vremainder_mask) - (int32_t)(vq31product24 < 0);
    const int32_t vremainder25 = (vq31product25 & vremainder_mask) - (int32_t)(vq31product25 < 0);
    const int32_t vremainder26 = (vq31product26 & vremainder_mask) - (int32_t)(vq31product26 < 0);
    const int32_t vremainder27 = (vq31product27 & vremainder_mask) - (int32_t)(vq31product27 < 0);
    const int32_t vremainder30 = (vq31product30 & vremainder_mask) - (int32_t)(vq31product30 < 0);
    const int32_t vremainder31 = (vq31product31 & vremainder_mask) - (int32_t)(vq31product31 < 0);
    const int32_t vremainder32 = (vq31product32 & vremainder_mask) - (int32_t)(vq31product32 < 0);
    const int32_t vremainder33 = (vq31product33 & vremainder_mask) - (int32_t)(vq31product33 < 0);
    const int32_t vremainder34 = (vq31product34 & vremainder_mask) - (int32_t)(vq31product34 < 0);
    const int32_t vremainder35 = (vq31product35 & vremainder_mask) - (int32_t)(vq31product35 < 0);
    const int32_t vremainder36 = (vq31product36 & vremainder_mask) - (int32_t)(vq31product36 < 0);
    const int32_t vremainder37 = (vq31product37 & vremainder_mask) - (int32_t)(vq31product37 < 0);
    const int32_t vremainder40 = (vq31product40 & vremainder_mask) - (int32_t)(vq31product40 < 0);
    const int32_t vremainder41 = (vq31product41 & vremainder_mask) - (int32_t)(vq31product41 < 0);
    const int32_t vremainder42 = (vq31product42 & vremainder_mask) - (int32_t)(vq31product42 < 0);
    const int32_t vremainder43 = (vq31product43 & vremainder_mask) - (int32_t)(vq31product43 < 0);
    const int32_t vremainder44 = (vq31product44 & vremainder_mask) - (int32_t)(vq31product44 < 0);
    const int32_t vremainder45 = (vq31product45 & vremainder_mask) - (int32_t)(vq31product45 < 0);
    const int32_t vremainder46 = (vq31product46 & vremainder_mask) - (int32_t)(vq31product46 < 0);
    const int32_t vremainder47 = (vq31product47 & vremainder_mask) - (int32_t)(vq31product47 < 0);
    const int32_t vremainder50 = (vq31product50 & vremainder_mask) - (int32_t)(vq31product50 < 0);
    const int32_t vremainder51 = (vq31product51 & vremainder_mask) - (int32_t)(vq31product51 < 0);
    const int32_t vremainder52 = (vq31product52 & vremainder_mask) - (int32_t)(vq31product52 < 0);
    const int32_t vremainder53 = (vq31product53 & vremainder_mask) - (int32_t)(vq31product53 < 0);
    const int32_t vremainder54 = (vq31product54 & vremainder_mask) - (int32_t)(vq31product54 < 0);
    const int32_t vremainder55 = (vq31product55 & vremainder_mask) - (int32_t)(vq31product55 < 0);
    const int32_t vremainder56 = (vq31product56 & vremainder_mask) - (int32_t)(vq31product56 < 0);
    const int32_t vremainder57 = (vq31product57 & vremainder_mask) - (int32_t)(vq31product57 < 0);
    const int32_t vremainder60 = (vq31product60 & vremainder_mask) - (int32_t)(vq31product60 < 0);
    const int32_t vremainder61 = (vq31product61 & vremainder_mask) - (int32_t)(vq31product61 < 0);
    const int32_t vremainder62 = (vq31product62 & vremainder_mask) - (int32_t)(vq31product62 < 0);
    const int32_t vremainder63 = (vq31product63 & vremainder_mask) - (int32_t)(vq31product63 < 0);
    const int32_t vremainder64 = (vq31product64 & vremainder_mask) - (int32_t)(vq31product64 < 0);
    const int32_t vremainder65 = (vq31product65 & vremainder_mask) - (int32_t)(vq31product65 < 0);
    const int32_t vremainder66 = (vq31product66 & vremainder_mask) - (int32_t)(vq31product66 < 0);
    const int32_t vremainder67 = (vq31product67 & vremainder_mask) - (int32_t)(vq31product67 < 0);
    const int32_t vremainder70 = (vq31product70 & vremainder_mask) - (int32_t)(vq31product70 < 0);
    const int32_t vremainder71 = (vq31product71 & vremainder_mask) - (int32_t)(vq31product71 < 0);
    const int32_t vremainder72 = (vq31product72 & vremainder_mask) - (int32_t)(vq31product72 < 0);
    const int32_t vremainder73 = (vq31product73 & vremainder_mask) - (int32_t)(vq31product73 < 0);
    const int32_t vremainder74 = (vq31product74 & vremainder_mask) - (int32_t)(vq31product74 < 0);
    const int32_t vremainder75 = (vq31product75 & vremainder_mask) - (int32_t)(vq31product75 < 0);
    const int32_t vremainder76 = (vq31product76 & vremainder_mask) - (int32_t)(vq31product76 < 0);
    const int32_t vremainder77 = (vq31product77 & vremainder_mask) - (int32_t)(vq31product77 < 0);

    int32_t vout00 = asr_s32(vq31product00, vshift) + (int32_t)(vremainder00 > vremainder_threshold);
    int32_t vout01 = asr_s32(vq31product01, vshift) + (int32_t)(vremainder01 > vremainder_threshold);
    int32_t vout02 = asr_s32(vq31product02, vshift) + (int32_t)(vremainder02 > vremainder_threshold);
    int32_t vout03 = asr_s32(vq31product03, vshift) + (int32_t)(vremainder03 > vremainder_threshold);
    int32_t vout04 = asr_s32(vq31product04, vshift) + (int32_t)(vremainder04 > vremainder_threshold);
    int32_t vout05 = asr_s32(vq31product05, vshift) + (int32_t)(vremainder05 > vremainder_threshold);
    int32_t vout06 = asr_s32(vq31product06, vshift) + (int32_t)(vremainder06 > vremainder_threshold);
    int32_t vout07 = asr_s32(vq31product07, vshift) + (int32_t)(vremainder07 > vremainder_threshold);
    int32_t vout10 = asr_s32(vq31product10, vshift) + (int32_t)(vremainder10 > vremainder_threshold);
    int32_t vout11 = asr_s32(vq31product11, vshift) + (int32_t)(vremainder11 > vremainder_threshold);
    int32_t vout12 = asr_s32(vq31product12, vshift) + (int32_t)(vremainder12 > vremainder_threshold);
    int32_t vout13 = asr_s32(vq31product13, vshift) + (int32_t)(vremainder13 > vremainder_threshold);
    int32_t vout14 = asr_s32(vq31product14, vshift) + (int32_t)(vremainder14 > vremainder_threshold);
    int32_t vout15 = asr_s32(vq31product15, vshift) + (int32_t)(vremainder15 > vremainder_threshold);
    int32_t vout16 = asr_s32(vq31product16, vshift) + (int32_t)(vremainder16 > vremainder_threshold);
    int32_t vout17 = asr_s32(vq31product17, vshift) + (int32_t)(vremainder17 > vremainder_threshold);
    int32_t vout20 = asr_s32(vq31product20, vshift) + (int32_t)(vremainder20 > vremainder_threshold);
    int32_t vout21 = asr_s32(vq31product21, vshift) + (int32_t)(vremainder21 > vremainder_threshold);
    int32_t vout22 = asr_s32(vq31product22, vshift) + (int32_t)(vremainder22 > vremainder_threshold);
    int32_t vout23 = asr_s32(vq31product23, vshift) + (int32_t)(vremainder23 > vremainder_threshold);
    int32_t vout24 = asr_s32(vq31product24, vshift) + (int32_t)(vremainder24 > vremainder_threshold);
    int32_t vout25 = asr_s32(vq31product25, vshift) + (int32_t)(vremainder25 > vremainder_threshold);
    int32_t vout26 = asr_s32(vq31product26, vshift) + (int32_t)(vremainder26 > vremainder_threshold);
    int32_t vout27 = asr_s32(vq31product27, vshift) + (int32_t)(vremainder27 > vremainder_threshold);
    int32_t vout30 = asr_s32(vq31product30, vshift) + (int32_t)(vremainder30 > vremainder_threshold);
    int32_t vout31 = asr_s32(vq31product31, vshift) + (int32_t)(vremainder31 > vremainder_threshold);
    int32_t vout32 = asr_s32(vq31product32, vshift) + (int32_t)(vremainder32 > vremainder_threshold);
    int32_t vout33 = asr_s32(vq31product33, vshift) + (int32_t)(vremainder33 > vremainder_threshold);
    int32_t vout34 = asr_s32(vq31product34, vshift) + (int32_t)(vremainder34 > vremainder_threshold);
    int32_t vout35 = asr_s32(vq31product35, vshift) + (int32_t)(vremainder35 > vremainder_threshold);
    int32_t vout36 = asr_s32(vq31product36, vshift) + (int32_t)(vremainder36 > vremainder_threshold);
    int32_t vout37 = asr_s32(vq31product37, vshift) + (int32_t)(vremainder37 > vremainder_threshold);
    int32_t vout40 = asr_s32(vq31product40, vshift) + (int32_t)(vremainder40 > vremainder_threshold);
    int32_t vout41 = asr_s32(vq31product41, vshift) + (int32_t)(vremainder41 > vremainder_threshold);
    int32_t vout42 = asr_s32(vq31product42, vshift) + (int32_t)(vremainder42 > vremainder_threshold);
    int32_t vout43 = asr_s32(vq31product43, vshift) + (int32_t)(vremainder43 > vremainder_threshold);
    int32_t vout44 = asr_s32(vq31product44, vshift) + (int32_t)(vremainder44 > vremainder_threshold);
    int32_t vout45 = asr_s32(vq31product45, vshift) + (int32_t)(vremainder45 > vremainder_threshold);
    int32_t vout46 = asr_s32(vq31product46, vshift) + (int32_t)(vremainder46 > vremainder_threshold);
    int32_t vout47 = asr_s32(vq31product47, vshift) + (int32_t)(vremainder47 > vremainder_threshold);
    int32_t vout50 = asr_s32(vq31product50, vshift) + (int32_t)(vremainder50 > vremainder_threshold);
    int32_t vout51 = asr_s32(vq31product51, vshift) + (int32_t)(vremainder51 > vremainder_threshold);
    int32_t vout52 = asr_s32(vq31product52, vshift) + (int32_t)(vremainder52 > vremainder_threshold);
    int32_t vout53 = asr_s32(vq31product53, vshift) + (int32_t)(vremainder53 > vremainder_threshold);
    int32_t vout54 = asr_s32(vq31product54, vshift) + (int32_t)(vremainder54 > vremainder_threshold);
    int32_t vout55 = asr_s32(vq31product55, vshift) + (int32_t)(vremainder55 > vremainder_threshold);
    int32_t vout56 = asr_s32(vq31product56, vshift) + (int32_t)(vremainder56 > vremainder_threshold);
    int32_t vout57 = asr_s32(vq31product57, vshift) + (int32_t)(vremainder57 > vremainder_threshold);
    int32_t vout60 = asr_s32(vq31product60, vshift) + (int32_t)(vremainder60 > vremainder_threshold);
    int32_t vout61 = asr_s32(vq31product61, vshift) + (int32_t)(vremainder61 > vremainder_threshold);
    int32_t vout62 = asr_s32(vq31product62, vshift) + (int32_t)(vremainder62 > vremainder_threshold);
    int32_t vout63 = asr_s32(vq31product63, vshift) + (int32_t)(vremainder63 > vremainder_threshold);
    int32_t vout64 = asr_s32(vq31product64, vshift) + (int32_t)(vremainder64 > vremainder_threshold);
    int32_t vout65 = asr_s32(vq31product65, vshift) + (int32_t)(vremainder65 > vremainder_threshold);
    int32_t vout66 = asr_s32(vq31product66, vshift) + (int32_t)(vremainder66 > vremainder_threshold);
    int32_t vout67 = asr_s32(vq31product67, vshift) + (int32_t)(vremainder67 > vremainder_threshold);
    int32_t vout70 = asr_s32(vq31product70, vshift) + (int32_t)(vremainder70 > vremainder_threshold);
    int32_t vout71 = asr_s32(vq31product71, vshift) + (int32_t)(vremainder71 > vremainder_threshold);
    int32_t vout72 = asr_s32(vq31product72, vshift) + (int32_t)(vremainder72 > vremainder_threshold);
    int32_t vout73 = asr_s32(vq31product73, vshift) + (int32_t)(vremainder73 > vremainder_threshold);
    int32_t vout74 = asr_s32(vq31product74, vshift) + (int32_t)(vremainder74 > vremainder_threshold);
    int32_t vout75 = asr_s32(vq31product75, vshift) + (int32_t)(vremainder75 > vremainder_threshold);
    int32_t vout76 = asr_s32(vq31product76, vshift) + (int32_t)(vremainder76 > vremainder_threshold);
    int32_t vout77 = asr_s32(vq31product77, vshift) + (int32_t)(vremainder77 > vremainder_threshold);

    vout00 = vout00 < voutput_min ? voutput_min : vout00;
    vout01 = vout01 < voutput_min ? voutput_min : vout01;
    vout02 = vout02 < voutput_min ? voutput_min : vout02;
    vout03 = vout03 < voutput_min ? voutput_min : vout03;
    vout04 = vout04 < voutput_min ? voutput_min : vout04;
    vout05 = vout05 < voutput_min ? voutput_min : vout05;
    vout06 = vout06 < voutput_min ? voutput_min : vout06;
    vout07 = vout07 < voutput_min ? voutput_min : vout07;
    vout10 = vout10 < voutput_min ? voutput_min : vout10;
    vout11 = vout11 < voutput_min ? voutput_min : vout11;
    vout12 = vout12 < voutput_min ? voutput_min : vout12;
    vout13 = vout13 < voutput_min ? voutput_min : vout13;
    vout14 = vout14 < voutput_min ? voutput_min : vout14;
    vout15 = vout15 < voutput_min ? voutput_min : vout15;
    vout16 = vout16 < voutput_min ? voutput_min : vout16;
    vout17 = vout17 < voutput_min ? voutput_min : vout17;
    vout20 = vout20 < voutput_min ? voutput_min : vout20;
    vout21 = vout21 < voutput_min ? voutput_min : vout21;
    vout22 = vout22 < voutput_min ? voutput_min : vout22;
    vout23 = vout23 < voutput_min ? voutput_min : vout23;
    vout24 = vout24 < voutput_min ? voutput_min : vout24;
    vout25 = vout25 < voutput_min ? voutput_min : vout25;
    vout26 = vout26 < voutput_min ? voutput_min : vout26;
    vout27 = vout27 < voutput_min ? voutput_min : vout27;
    vout30 = vout30 < voutput_min ? voutput_min : vout30;
    vout31 = vout31 < voutput_min ? voutput_min : vout31;
    vout32 = vout32 < voutput_min ? voutput_min : vout32;
    vout33 = vout33 < voutput_min ? voutput_min : vout33;
    vout34 = vout34 < voutput_min ? voutput_min : vout34;
    vout35 = vout35 < voutput_min ? voutput_min : vout35;
    vout36 = vout36 < voutput_min ? voutput_min : vout36;
    vout37 = vout37 < voutput_min ? voutput_min : vout37;
    vout40 = vout40 < voutput_min ? voutput_min : vout40;
    vout41 = vout41 < voutput_min ? voutput_min : vout41;
    vout42 = vout42 < voutput_min ? voutput_min : vout42;
    vout43 = vout43 < voutput_min ? voutput_min : vout43;
    vout44 = vout44 < voutput_min ? voutput_min : vout44;
    vout45 = vout45 < voutput_min ? voutput_min : vout45;
    vout46 = vout46 < voutput_min ? voutput_min : vout46;
    vout47 = vout47 < voutput_min ? voutput_min : vout47;
    vout50 = vout50 < voutput_min ? voutput_min : vout50;
    vout51 = vout51 < voutput_min ? voutput_min : vout51;
    vout52 = vout52 < voutput_min ? voutput_min : vout52;
    vout53 = vout53 < voutput_min ? voutput_min : vout53;
    vout54 = vout54 < voutput_min ? voutput_min : vout54;
    vout55 = vout55 < voutput_min ? voutput_min : vout55;
    vout56 = vout56 < voutput_min ? voutput_min : vout56;
    vout57 = vout57 < voutput_min ? voutput_min : vout57;
    vout60 = vout60 < voutput_min ? voutput_min : vout60;
    vout61 = vout61 < voutput_min ? voutput_min : vout61;
    vout62 = vout62 < voutput_min ? voutput_min : vout62;
    vout63 = vout63 < voutput_min ? voutput_min : vout63;
    vout64 = vout64 < voutput_min ? voutput_min : vout64;
    vout65 = vout65 < voutput_min ? voutput_min : vout65;
    vout66 = vout66 < voutput_min ? voutput_min : vout66;
    vout67 = vout67 < voutput_min ? voutput_min : vout67;
    vout70 = vout70 < voutput_min ? voutput_min : vout70;
    vout71 = vout71 < voutput_min ? voutput_min : vout71;
    vout72 = vout72 < voutput_min ? voutput_min : vout72;
    vout73 = vout73 < voutput_min ? voutput_min : vout73;
    vout74 = vout74 < voutput_min ? voutput_min : vout74;
    vout75 = vout75 < voutput_min ? voutput_min : vout75;
    vout76 = vout76 < voutput_min ? voutput_min : vout76;
    vout77 = vout77 < voutput_min ? voutput_min : vout77;

    vout00 = vout00 > voutput_max ? voutput_max : vout00;
    vout01 = vout01 > voutput_max ? voutput_max : vout01;
    vout02 = vout02 > voutput_max ? voutput_max : vout02;
    vout03 = vout03 > voutput_max ? voutput_max : vout03;
    vout04 = vout04 > voutput_max ? voutput_max : vout04;
    vout05 = vout05 > voutput_max ? voutput_max : vout05;
    vout06 = vout06 > voutput_max ? voutput_max : vout06;
    vout07 = vout07 > voutput_max ? voutput_max : vout07;
    vout10 = vout10 > voutput_max ? voutput_max : vout10;
    vout11 = vout11 > voutput_max ? voutput_max : vout11;
    vout12 = vout12 > voutput_max ? voutput_max : vout12;
    vout13 = vout13 > voutput_max ? voutput_max : vout13;
    vout14 = vout14 > voutput_max ? voutput_max : vout14;
    vout15 = vout15 > voutput_max ? voutput_max : vout15;
    vout16 = vout16 > voutput_max ? voutput_max : vout16;
    vout17 = vout17 > voutput_max ? voutput_max : vout17;
    vout20 = vout20 > voutput_max ? voutput_max : vout20;
    vout21 = vout21 > voutput_max ? voutput_max : vout21;
    vout22 = vout22 > voutput_max ? voutput_max : vout22;
    vout23 = vout23 > voutput_max ? voutput_max : vout23;
    vout24 = vout24 > voutput_max ? voutput_max : vout24;
    vout25 = vout25 > voutput_max ? voutput_max : vout25;
    vout26 = vout26 > voutput_max ? voutput_max : vout26;
    vout27 = vout27 > voutput_max ? voutput_max : vout27;
    vout30 = vout30 > voutput_max ? voutput_max : vout30;
    vout31 = vout31 > voutput_max ? voutput_max : vout31;
    vout32 = vout32 > voutput_max ? voutput_max : vout32;
    vout33 = vout33 > voutput_max ? voutput_max : vout33;
    vout34 = vout34 > voutput_max ? voutput_max : vout34;
    vout35 = vout35 > voutput_max ? voutput_max : vout35;
    vout36 = vout36 > voutput_max ? voutput_max : vout36;
    vout37 = vout37 > voutput_max ? voutput_max : vout37;
    vout40 = vout40 > voutput_max ? voutput_max : vout40;
    vout41 = vout41 > voutput_max ? voutput_max : vout41;
    vout42 = vout42 > voutput_max ? voutput_max : vout42;
    vout43 = vout43 > voutput_max ? voutput_max : vout43;
    vout44 = vout44 > voutput_max ? voutput_max : vout44;
    vout45 = vout45 > voutput_max ? voutput_max : vout45;
    vout46 = vout46 > voutput_max ? voutput_max : vout46;
    vout47 = vout47 > voutput_max ? voutput_max : vout47;
    vout50 = vout50 > voutput_max ? voutput_max : vout50;
    vout51 = vout51 > voutput_max ? voutput_max : vout51;
    vout52 = vout52 > voutput_max ? voutput_max : vout52;
    vout53 = vout53 > voutput_max ? voutput_max : vout53;
    vout54 = vout54 > voutput_max ? voutput_max : vout54;
    vout55 = vout55 > voutput_max ? voutput_max : vout55;
    vout56 = vout56 > voutput_max ? voutput_max : vout56;
    vout57 = vout57 > voutput_max ? voutput_max : vout57;
    vout60 = vout60 > voutput_max ? voutput_max : vout60;
    vout61 = vout61 > voutput_max ? voutput_max : vout61;
    vout62 = vout62 > voutput_max ? voutput_max : vout62;
    vout63 = vout63 > voutput_max ? voutput_max : vout63;
    vout64 = vout64 > voutput_max ? voutput_max : vout64;
    vout65 = vout65 > voutput_max ? voutput_max : vout65;
    vout66 = vout66 > voutput_max ? voutput_max : vout66;
    vout67 = vout67 > voutput_max ? voutput_max : vout67;
    vout70 = vout70 > voutput_max ? voutput_max : vout70;
    vout71 = vout71 > voutput_max ? voutput_max : vout71;
    vout72 = vout72 > voutput_max ? voutput_max : vout72;
    vout73 = vout73 > voutput_max ? voutput_max : vout73;
    vout74 = vout74 > voutput_max ? voutput_max : vout74;
    vout75 = vout75 > voutput_max ? voutput_max : vout75;
    vout76 = vout76 > voutput_max ? voutput_max : vout76;
    vout77 = vout77 > voutput_max ? voutput_max : vout77;

    vout00 += voutput_zero_point;
    vout01 += voutput_zero_point;
    vout02 += voutput_zero_point;
    vout03 += voutput_zero_point;
    vout04 += voutput_zero_point;
    vout05 += voutput_zero_point;
    vout06 += voutput_zero_point;
    vout07 += voutput_zero_point;
    vout10 += voutput_zero_point;
    vout11 += voutput_zero_point;
    vout12 += voutput_zero_point;
    vout13 += voutput_zero_point;
    vout14 += voutput_zero_point;
    vout15 += voutput_zero_point;
    vout16 += voutput_zero_point;
    vout17 += voutput_zero_point;
    vout20 += voutput_zero_point;
    vout21 += voutput_zero_point;
    vout22 += voutput_zero_point;
    vout23 += voutput_zero_point;
    vout24 += voutput_zero_point;
    vout25 += voutput_zero_point;
    vout26 += voutput_zero_point;
    vout27 += voutput_zero_point;
    vout30 += voutput_zero_point;
    vout31 += voutput_zero_point;
    vout32 += voutput_zero_point;
    vout33 += voutput_zero_point;
    vout34 += voutput_zero_point;
    vout35 += voutput_zero_point;
    vout36 += voutput_zero_point;
    vout37 += voutput_zero_point;
    vout40 += voutput_zero_point;
    vout41 += voutput_zero_point;
    vout42 += voutput_zero_point;
    vout43 += voutput_zero_point;
    vout44 += voutput_zero_point;
    vout45 += voutput_zero_point;
    vout46 += voutput_zero_point;
    vout47 += voutput_zero_point;
    vout50 += voutput_zero_point;
    vout51 += voutput_zero_point;
    vout52 += voutput_zero_point;
    vout53 += voutput_zero_point;
    vout54 += voutput_zero_point;
    vout55 += voutput_zero_point;
    vout56 += voutput_zero_point;
    vout57 += voutput_zero_point;
    vout60 += voutput_zero_point;
    vout61 += voutput_zero_point;
    vout62 += voutput_zero_point;
    vout63 += voutput_zero_point;
    vout64 += voutput_zero_point;
    vout65 += voutput_zero_point;
    vout66 += voutput_zero_point;
    vout67 += voutput_zero_point;
    vout70 += voutput_zero_point;
    vout71 += voutput_zero_point;
    vout72 += voutput_zero_point;
    vout73 += voutput_zero_point;
    vout74 += voutput_zero_point;
    vout75 += voutput_zero_point;
    vout76 += voutput_zero_point;
    vout77 += voutput_zero_point;

    if XNN_LIKELY (nc >= 8) {
      // Main case where there the 8 columns fit in the destination.
      c7[0] = (int8_t) vout70;
      c7[1] = (int8_t) vout71;
      c7[2] = (int8_t) vout72;
      c7[3] = (int8_t) vout73;
      c7[4] = (int8_t) vout74;
      c7[5] = (int8_t) vout75;
      c7[6] = (int8_t) vout76;
      c7[7] = (int8_t) vout77;
      c6[0] = (int8_t) vout60;
      c6[1] = (int8_t) vout61;
      c6[2] = (int8_t) vout62;
      c6[3] = (int8_t) vout63;
      c6[4] = (int8_t) vout64;
      c6[5] = (int8_t) vout65;
      c6[6] = (int8_t) vout66;
      c6[7] = (int8_t) vout67;
      c5[0] = (int8_t) vout50;
      c5[1] = (int8_t) vout51;
      c5[2] = (int8_t) vout52;
      c5[3] = (int8_t) vout53;
      c5[4] = (int8_t) vout54;
      c5[5] = (int8_t) vout55;
      c5[6] = (int8_t) vout56;
      c5[7] = (int8_t) vout57;
      c4[0] = (int8_t) vout40;
      c4[1] = (int8_t) vout41;
      c4[2] = (int8_t) vout42;
      c4[3] = (int8_t) vout43;
      c4[4] = (int8_t) vout44;
      c4[5] = (int8_t) vout45;
      c4[6] = (int8_t) vout46;
      c4[7] = (int8_t) vout47;
      c3[0] = (int8_t) vout30;
      c3[1] = (int8_t) vout31;
      c3[2] = (int8_t) vout32;
      c3[3] = (int8_t) vout33;
      c3[4] = (int8_t) vout34;
      c3[5] = (int8_t) vout35;
      c3[6] = (int8_t) vout36;
      c3[7] = (int8_t) vout37;
      c2[0] = (int8_t) vout20;
      c2[1] = (int8_t) vout21;
      c2[2] = (int8_t) vout22;
      c2[3] = (int8_t) vout23;
      c2[4] = (int8_t) vout24;
      c2[5] = (int8_t) vout25;
      c2[6] = (int8_t) vout26;
      c2[7] = (int8_t) vout27;
      c1[0] = (int8_t) vout10;
      c1[1] = (int8_t) vout11;
      c1[2] = (int8_t) vout12;
      c1[3] = (int8_t) vout13;
      c1[4] = (int8_t) vout14;
      c1[5] = (int8_t) vout15;
      c1[6] = (int8_t) vout16;
      c1[7] = (int8_t) vout17;
      c0[0] = (int8_t) vout00;
      c0[1] = (int8_t) vout01;
      c0[2] = (int8_t) vout02;
      c0[3] = (int8_t) vout03;
      c0[4] = (int8_t) vout04;
      c0[5] = (int8_t) vout05;
      c0[6] = (int8_t) vout06;
      c0[7] = (int8_t) vout07;

      c7 = (int8_t*)((uintptr_t)c7 + cn_stride);
      c6 = (int8_t*)((uintptr_t)c6 + cn_stride);
      c5 = (int8_t*)((uintptr_t)c5 + cn_stride);
      c4 = (int8_t*)((uintptr_t)c4 + cn_stride);
      c3 = (int8_t*)((uintptr_t)c3 + cn_stride);
      c2 = (int8_t*)((uintptr_t)c2 + cn_stride);
      c1 = (int8_t*)((uintptr_t)c1 + cn_stride);
      c0 = (int8_t*)((uintptr_t)c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);

      nc -= 8;
    } else {
      // Final case where not all of the 8 columns fit in the destination.
      if (nc > 0) {
        c7[0] = vout70;
        c6[0] = vout60;
        c5[0] = vout50;
        c4[0] = vout40;
        c3[0] = vout30;
        c2[0] = vout20;
        c1[0] = vout10;
        c0[0] = vout00;
      }
      if (nc > 1) {
        c7[1] = vout71;
        c6[1] = vout61;
        c5[1] = vout51;
        c4[1] = vout41;
        c3[1] = vout31;
        c2[1] = vout21;
        c1[1] = vout11;
        c0[1] = vout01;
      }
      if (nc > 2) {
        c7[2] = vout72;
        c6[2] = vout62;
        c5[2] = vout52;
        c4[2] = vout42;
        c3[2] = vout32;
        c2[2] = vout22;
        c1[2] = vout12;
        c0[2] = vout02;
      }
      if (nc > 3) {
        c7[3] = vout73;
        c6[3] = vout63;
        c5[3] = vout53;
        c4[3] = vout43;
        c3[3] = vout33;
        c2[3] = vout23;
        c1[3] = vout13;
        c0[3] = vout03;
      }
      if (nc > 4) {
        c7[4] = vout74;
        c6[4] = vout64;
        c5[4] = vout54;
        c4[4] = vout44;
        c3[4] = vout34;
        c2[4] = vout24;
        c1[4] = vout14;
        c0[4] = vout04;
      }
      if (nc > 5) {
        c7[5] = vout75;
        c6[5] = vout65;
        c5[5] = vout55;
        c4[5] = vout45;
        c3[5] = vout35;
        c2[5] = vout25;
        c1[5] = vout15;
        c0[5] = vout05;
      }
      if (nc > 6) {
        c7[6] = vout76;
        c6[6] = vout66;
        c5[6] = vout56;
        c4[6] = vout46;
        c3[6] = vout36;
        c2[6] = vout26;
        c1[6] = vout16;
        c0[6] = vout06;
      }
      if (nc > 7) {
        c7[7] = vout77;
        c6[7] = vout67;
        c5[7] = vout57;
        c4[7] = vout47;
        c3[7] = vout37;
        c2[7] = vout27;
        c1[7] = vout17;
        c0[7] = vout07;
      }

      nc = 0;
    }
  } while (nc != 0);
}
