//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.cpp
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.34
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun Jul 18 15:15:48 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ghost_mode.h"
#include "ghost_mode_private.h"

// Block signals (default storage)
B_ghost_mode_T ghost_mode_B;

// Block states (default storage)
DW_ghost_mode_T ghost_mode_DW;

// Real-time model
RT_MODEL_ghost_mode_T ghost_mode_M_ = RT_MODEL_ghost_mode_T();
RT_MODEL_ghost_mode_T *const ghost_mode_M = &ghost_mode_M_;

// Forward declaration for local functions
static void ghost_mode_Unconstrained(const real_T b_Hinv[9], const real_T f[3],
  real_T x[3], int16_T n);
static real_T ghost_mode_norm(const real_T x[3]);
static void ghost_mode_abs(const real_T x[3], real_T y[3]);
static real_T ghost_mode_maximum(const real_T x[3]);
static void ghost_mode_abs_e(const real_T x[4], real_T y[4]);
static void ghost_mode_maximum2(const real_T x[4], real_T y, real_T ex[4]);
static real_T ghost_mode_xnrm2(int32_T n, const real_T x[9], int32_T ix0);
static void ghost_mode_xgemv(int32_T b_m, int32_T n, const real_T b_A[9],
  int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3]);
static void ghost_mode_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[3], real_T b_A[9], int32_T ia0);
static void ghost_mode_qr(const real_T b_A[9], real_T Q[9], real_T R[9]);
static void ghost_mode_KWIKfactor(const real_T b_Ac[12], const int16_T iC[4],
  int16_T nA, const real_T b_Linv[9], real_T D[9], real_T b_H[9], int16_T n,
  real_T RLinv[9], real_T *Status);
static real_T ghost_mode_mtimes(const real_T b_A[3], const real_T B[3]);
static void ghost_mode_DropConstraint(int16_T kDrop, int16_T iA[4], int16_T *nA,
  int16_T iC[4]);
static void ghost_mode_qpkwik(const real_T b_Linv[9], const real_T b_Hinv[9],
  const real_T f[3], const real_T b_Ac[12], const real_T b[4], int16_T iA[4],
  int16_T maxiter, real_T FeasTol, real_T x[3], real_T lambda[4], real_T *status);

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_Unconstrained(const real_T b_Hinv[9], const real_T f[3],
  real_T x[3], int16_T n)
{
  int32_T i;
  for (i = 1; i - 1 < n; i++) {
    x[static_cast<int16_T>(i) - 1] = (-b_Hinv[static_cast<int16_T>(i) - 1] * f[0]
      + -b_Hinv[static_cast<int16_T>(i) + 2] * f[1]) + -b_Hinv
      [static_cast<int16_T>(i) + 5] * f[2];
  }
}

// Function for MATLAB Function: '<S27>/optimizer'
static real_T ghost_mode_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_abs(const real_T x[3], real_T y[3])
{
  y[0] = fabs(x[0]);
  y[1] = fabs(x[1]);
  y[2] = fabs(x[2]);
}

// Function for MATLAB Function: '<S27>/optimizer'
static real_T ghost_mode_maximum(const real_T x[3])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 3) {
      if (ex < x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_abs_e(const real_T x[4], real_T y[4])
{
  y[0] = fabs(x[0]);
  y[1] = fabs(x[1]);
  y[2] = fabs(x[2]);
  y[3] = fabs(x[3]);
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_maximum2(const real_T x[4], real_T y, real_T ex[4])
{
  boolean_T tmp;
  tmp = rtIsNaN(y);
  if ((x[0] > y) || tmp) {
    ex[0] = x[0];
  } else {
    ex[0] = y;
  }

  if ((x[1] > y) || tmp) {
    ex[1] = x[1];
  } else {
    ex[1] = y;
  }

  if ((x[2] > y) || tmp) {
    ex[2] = x[2];
  } else {
    ex[2] = y;
  }

  if ((x[3] > y) || tmp) {
    ex[3] = x[3];
  } else {
    ex[3] = y;
  }
}

// Function for MATLAB Function: '<S27>/optimizer'
static real_T ghost_mode_xnrm2(int32_T n, const real_T x[9], int32_T ix0)
{
  real_T absxk;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      ghost_mode_B.scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > ghost_mode_B.scale) {
          t = ghost_mode_B.scale / absxk;
          y = y * t * t + 1.0;
          ghost_mode_B.scale = absxk;
        } else {
          t = absxk / ghost_mode_B.scale;
          y += t * t;
        }
      }

      y = ghost_mode_B.scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_xgemv(int32_T b_m, int32_T n, const real_T b_A[9],
  int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3])
{
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((b_m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 3 + ia0;
    for (iac = ia0; iac <= b; iac += 3) {
      ix = ix0;
      ghost_mode_B.c = 0.0;
      d = (iac + b_m) - 1;
      for (ia = iac; ia <= d; ia++) {
        ghost_mode_B.c += b_A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += ghost_mode_B.c;
      b_iy++;
    }
  }
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[3], real_T b_A[9], int32_T ia0)
{
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        ghost_mode_B.temp = y[jy] * alpha1;
        ix = ix0;
        b = b_m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          b_A[ijA] += b_A[ix - 1] * ghost_mode_B.temp;
          ix++;
        }
      }

      jy++;
      jA += 3;
    }
  }
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_qr(const real_T b_A[9], real_T Q[9], real_T R[9])
{
  int32_T b_coltop;
  int32_T c_lastc;
  int32_T coltop;
  int32_T exitg1;
  int32_T knt;
  boolean_T exitg2;
  ghost_mode_B.tau_idx_0 = 0.0;
  ghost_mode_B.tau_idx_1 = 0.0;
  memcpy(&ghost_mode_B.c_A[0], &b_A[0], 9U * sizeof(real_T));
  ghost_mode_B.work[0] = 0.0;
  ghost_mode_B.work[1] = 0.0;
  ghost_mode_B.work[2] = 0.0;
  ghost_mode_B.atmp = ghost_mode_B.c_A[0];
  ghost_mode_B.beta1 = ghost_mode_xnrm2(2, ghost_mode_B.c_A, 2);
  if (ghost_mode_B.beta1 != 0.0) {
    ghost_mode_B.beta1 = rt_hypotd_snf(ghost_mode_B.c_A[0], ghost_mode_B.beta1);
    if (ghost_mode_B.c_A[0] >= 0.0) {
      ghost_mode_B.beta1 = -ghost_mode_B.beta1;
    }

    if (fabs(ghost_mode_B.beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 1; c_lastc < 3; c_lastc++) {
          ghost_mode_B.c_A[c_lastc] *= 9.9792015476736E+291;
        }

        ghost_mode_B.beta1 *= 9.9792015476736E+291;
        ghost_mode_B.atmp *= 9.9792015476736E+291;
      } while (!(fabs(ghost_mode_B.beta1) >= 1.0020841800044864E-292));

      ghost_mode_B.beta1 = rt_hypotd_snf(ghost_mode_B.atmp, ghost_mode_xnrm2(2,
        ghost_mode_B.c_A, 2));
      if (ghost_mode_B.atmp >= 0.0) {
        ghost_mode_B.beta1 = -ghost_mode_B.beta1;
      }

      ghost_mode_B.tau_idx_0 = (ghost_mode_B.beta1 - ghost_mode_B.atmp) /
        ghost_mode_B.beta1;
      ghost_mode_B.atmp = 1.0 / (ghost_mode_B.atmp - ghost_mode_B.beta1);
      for (c_lastc = 1; c_lastc < 3; c_lastc++) {
        ghost_mode_B.c_A[c_lastc] *= ghost_mode_B.atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        ghost_mode_B.beta1 *= 1.0020841800044864E-292;
      }

      ghost_mode_B.atmp = ghost_mode_B.beta1;
    } else {
      ghost_mode_B.tau_idx_0 = (ghost_mode_B.beta1 - ghost_mode_B.c_A[0]) /
        ghost_mode_B.beta1;
      ghost_mode_B.atmp = 1.0 / (ghost_mode_B.c_A[0] - ghost_mode_B.beta1);
      for (knt = 1; knt < 3; knt++) {
        ghost_mode_B.c_A[knt] *= ghost_mode_B.atmp;
      }

      ghost_mode_B.atmp = ghost_mode_B.beta1;
    }
  }

  ghost_mode_B.c_A[0] = 1.0;
  if (ghost_mode_B.tau_idx_0 != 0.0) {
    knt = 3;
    c_lastc = 0;
    while ((knt > 0) && (ghost_mode_B.c_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      b_coltop = (c_lastc - 1) * 3 + 3;
      coltop = b_coltop;
      do {
        exitg1 = 0;
        if (coltop + 1 <= b_coltop + knt) {
          if (ghost_mode_B.c_A[coltop] != 0.0) {
            exitg1 = 1;
          } else {
            coltop++;
          }
        } else {
          c_lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    ghost_mode_xgemv(knt, c_lastc, ghost_mode_B.c_A, 4, ghost_mode_B.c_A, 1,
                     ghost_mode_B.work);
    ghost_mode_xgerc(knt, c_lastc, -ghost_mode_B.tau_idx_0, 1, ghost_mode_B.work,
                     ghost_mode_B.c_A, 4);
  }

  ghost_mode_B.c_A[0] = ghost_mode_B.atmp;
  ghost_mode_B.atmp = ghost_mode_B.c_A[4];
  ghost_mode_B.beta1 = ghost_mode_xnrm2(1, ghost_mode_B.c_A, 6);
  if (ghost_mode_B.beta1 != 0.0) {
    ghost_mode_B.beta1 = rt_hypotd_snf(ghost_mode_B.c_A[4], ghost_mode_B.beta1);
    if (ghost_mode_B.c_A[4] >= 0.0) {
      ghost_mode_B.beta1 = -ghost_mode_B.beta1;
    }

    if (fabs(ghost_mode_B.beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 5; c_lastc < 6; c_lastc++) {
          ghost_mode_B.c_A[c_lastc] *= 9.9792015476736E+291;
        }

        ghost_mode_B.beta1 *= 9.9792015476736E+291;
        ghost_mode_B.atmp *= 9.9792015476736E+291;
      } while (!(fabs(ghost_mode_B.beta1) >= 1.0020841800044864E-292));

      ghost_mode_B.beta1 = rt_hypotd_snf(ghost_mode_B.atmp, ghost_mode_xnrm2(1,
        ghost_mode_B.c_A, 6));
      if (ghost_mode_B.atmp >= 0.0) {
        ghost_mode_B.beta1 = -ghost_mode_B.beta1;
      }

      ghost_mode_B.tau_idx_1 = (ghost_mode_B.beta1 - ghost_mode_B.atmp) /
        ghost_mode_B.beta1;
      ghost_mode_B.atmp = 1.0 / (ghost_mode_B.atmp - ghost_mode_B.beta1);
      for (c_lastc = 5; c_lastc < 6; c_lastc++) {
        ghost_mode_B.c_A[c_lastc] *= ghost_mode_B.atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        ghost_mode_B.beta1 *= 1.0020841800044864E-292;
      }

      ghost_mode_B.atmp = ghost_mode_B.beta1;
    } else {
      ghost_mode_B.tau_idx_1 = (ghost_mode_B.beta1 - ghost_mode_B.c_A[4]) /
        ghost_mode_B.beta1;
      ghost_mode_B.atmp = 1.0 / (ghost_mode_B.c_A[4] - ghost_mode_B.beta1);
      for (knt = 5; knt < 6; knt++) {
        ghost_mode_B.c_A[knt] *= ghost_mode_B.atmp;
      }

      ghost_mode_B.atmp = ghost_mode_B.beta1;
    }
  }

  ghost_mode_B.c_A[4] = 1.0;
  if (ghost_mode_B.tau_idx_1 != 0.0) {
    knt = 2;
    c_lastc = 3;
    while ((knt > 0) && (ghost_mode_B.c_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    coltop = 7;
    do {
      exitg1 = 0;
      if (coltop + 1 <= 7 + knt) {
        if (ghost_mode_B.c_A[coltop] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    ghost_mode_xgemv(knt, c_lastc, ghost_mode_B.c_A, 8, ghost_mode_B.c_A, 5,
                     ghost_mode_B.work);
    ghost_mode_xgerc(knt, c_lastc, -ghost_mode_B.tau_idx_1, 5, ghost_mode_B.work,
                     ghost_mode_B.c_A, 8);
  }

  ghost_mode_B.c_A[4] = ghost_mode_B.atmp;
  R[0] = ghost_mode_B.c_A[0];
  for (knt = 1; knt + 1 < 4; knt++) {
    R[knt] = 0.0;
  }

  ghost_mode_B.work[0] = 0.0;
  for (knt = 0; knt < 2; knt++) {
    R[knt + 3] = ghost_mode_B.c_A[knt + 3];
  }

  for (knt = 2; knt + 1 < 4; knt++) {
    R[knt + 3] = 0.0;
  }

  ghost_mode_B.work[1] = 0.0;
  for (knt = 0; knt < 3; knt++) {
    R[knt + 6] = ghost_mode_B.c_A[knt + 6];
  }

  ghost_mode_B.work[2] = 0.0;
  ghost_mode_B.c_A[8] = 1.0;
  for (knt = 0; knt < 2; knt++) {
    ghost_mode_B.c_A[7 - knt] = 0.0;
  }

  ghost_mode_B.c_A[4] = 1.0;
  if (ghost_mode_B.tau_idx_1 != 0.0) {
    knt = 2;
    c_lastc = 7;
    while ((knt > 0) && (ghost_mode_B.c_A[c_lastc - 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    b_coltop = 8;
    do {
      exitg1 = 0;
      if (b_coltop <= knt + 7) {
        if (ghost_mode_B.c_A[b_coltop - 1] != 0.0) {
          exitg1 = 1;
        } else {
          b_coltop++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    ghost_mode_xgemv(knt, c_lastc, ghost_mode_B.c_A, 8, ghost_mode_B.c_A, 5,
                     ghost_mode_B.work);
    ghost_mode_xgerc(knt, c_lastc, -ghost_mode_B.tau_idx_1, 5, ghost_mode_B.work,
                     ghost_mode_B.c_A, 8);
  }

  for (knt = 5; knt < 6; knt++) {
    ghost_mode_B.c_A[knt] *= -ghost_mode_B.tau_idx_1;
  }

  ghost_mode_B.c_A[4] = 1.0 - ghost_mode_B.tau_idx_1;
  ghost_mode_B.c_A[3] = 0.0;
  ghost_mode_B.c_A[0] = 1.0;
  if (ghost_mode_B.tau_idx_0 != 0.0) {
    knt = 3;
    c_lastc = 4;
    while ((knt > 0) && (ghost_mode_B.c_A[c_lastc - 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      coltop = (c_lastc - 1) * 3 + 4;
      b_coltop = coltop;
      do {
        exitg1 = 0;
        if (b_coltop <= (coltop + knt) - 1) {
          if (ghost_mode_B.c_A[b_coltop - 1] != 0.0) {
            exitg1 = 1;
          } else {
            b_coltop++;
          }
        } else {
          c_lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    ghost_mode_xgemv(knt, c_lastc, ghost_mode_B.c_A, 4, ghost_mode_B.c_A, 1,
                     ghost_mode_B.work);
    ghost_mode_xgerc(knt, c_lastc, -ghost_mode_B.tau_idx_0, 1, ghost_mode_B.work,
                     ghost_mode_B.c_A, 4);
  }

  for (knt = 1; knt < 3; knt++) {
    ghost_mode_B.c_A[knt] *= -ghost_mode_B.tau_idx_0;
  }

  ghost_mode_B.c_A[0] = 1.0 - ghost_mode_B.tau_idx_0;
  for (knt = 0; knt < 3; knt++) {
    Q[3 * knt] = ghost_mode_B.c_A[3 * knt];
    c_lastc = 3 * knt + 1;
    Q[c_lastc] = ghost_mode_B.c_A[c_lastc];
    c_lastc = 3 * knt + 2;
    Q[c_lastc] = ghost_mode_B.c_A[c_lastc];
  }
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_KWIKfactor(const real_T b_Ac[12], const int16_T iC[4],
  int16_T nA, const real_T b_Linv[9], real_T D[9], real_T b_H[9], int16_T n,
  real_T RLinv[9], real_T *Status)
{
  int32_T RLinv_tmp;
  int32_T exitg1;
  int16_T b_j;
  int16_T c_k;
  *Status = 1.0;
  memset(&RLinv[0], 0, 9U * sizeof(real_T));
  ghost_mode_B.i_k = 1;
  while (ghost_mode_B.i_k - 1 <= nA - 1) {
    ghost_mode_B.f_i = iC[static_cast<int16_T>(ghost_mode_B.i_k) - 1];
    for (ghost_mode_B.b_i_c = 0; ghost_mode_B.b_i_c < 3; ghost_mode_B.b_i_c++) {
      RLinv_tmp = ghost_mode_B.b_i_c + 3 * (static_cast<int16_T>
        (ghost_mode_B.i_k) - 1);
      RLinv[RLinv_tmp] = 0.0;
      RLinv[RLinv_tmp] += b_Ac[ghost_mode_B.f_i - 1] * b_Linv[ghost_mode_B.b_i_c];
      RLinv[RLinv_tmp] += b_Linv[ghost_mode_B.b_i_c + 3] * b_Ac[ghost_mode_B.f_i
        + 3];
      RLinv[RLinv_tmp] += b_Linv[ghost_mode_B.b_i_c + 6] * b_Ac[ghost_mode_B.f_i
        + 7];
    }

    ghost_mode_B.i_k++;
  }

  ghost_mode_qr(RLinv, ghost_mode_B.QQ, ghost_mode_B.RR);
  ghost_mode_B.b_i_c = 1;
  do {
    exitg1 = 0;
    if (ghost_mode_B.b_i_c - 1 <= nA - 1) {
      if (fabs(ghost_mode_B.RR[((static_cast<int16_T>(ghost_mode_B.b_i_c) - 1) *
            3 + static_cast<int16_T>(ghost_mode_B.b_i_c)) - 1]) < 1.0E-12) {
        *Status = -2.0;
        exitg1 = 1;
      } else {
        ghost_mode_B.b_i_c++;
      }
    } else {
      ghost_mode_B.b_i_c = 1;
      while (ghost_mode_B.b_i_c - 1 <= n - 1) {
        for (RLinv_tmp = 1; RLinv_tmp - 1 < n; RLinv_tmp++) {
          ghost_mode_B.i_k = (static_cast<int16_T>(ghost_mode_B.b_i_c) - 1) * 3;
          ghost_mode_B.f_i = (static_cast<int16_T>(RLinv_tmp) - 1) * 3;
          ghost_mode_B.TL[(static_cast<int16_T>(ghost_mode_B.b_i_c) +
                           ghost_mode_B.f_i) - 1] = (b_Linv[ghost_mode_B.i_k + 1]
            * ghost_mode_B.QQ[ghost_mode_B.f_i + 1] + b_Linv[ghost_mode_B.i_k] *
            ghost_mode_B.QQ[ghost_mode_B.f_i]) + b_Linv[ghost_mode_B.i_k + 2] *
            ghost_mode_B.QQ[ghost_mode_B.f_i + 2];
        }

        ghost_mode_B.b_i_c++;
      }

      memset(&RLinv[0], 0, 9U * sizeof(real_T));
      for (b_j = nA; b_j > 0; b_j = static_cast<int16_T>(b_j - 1)) {
        ghost_mode_B.b_i_c = 3 * (b_j - 1);
        RLinv_tmp = (b_j + ghost_mode_B.b_i_c) - 1;
        RLinv[RLinv_tmp] = 1.0;
        for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
          ghost_mode_B.f_i = ((c_k - 1) * 3 + b_j) - 1;
          RLinv[ghost_mode_B.f_i] /= ghost_mode_B.RR[RLinv_tmp];
        }

        if (b_j > 1) {
          ghost_mode_B.i_k = 1;
          while (ghost_mode_B.i_k - 1 <= b_j - 2) {
            for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
              RLinv_tmp = (c_k - 1) * 3;
              ghost_mode_B.f_i = (RLinv_tmp + static_cast<int16_T>
                                  (ghost_mode_B.i_k)) - 1;
              RLinv[ghost_mode_B.f_i] -= ghost_mode_B.RR[(ghost_mode_B.b_i_c +
                static_cast<int16_T>(ghost_mode_B.i_k)) - 1] * RLinv[(RLinv_tmp
                + b_j) - 1];
            }

            ghost_mode_B.i_k++;
          }
        }
      }

      ghost_mode_B.i_k = 1;
      while (ghost_mode_B.i_k - 1 <= n - 1) {
        for (b_j = static_cast<int16_T>(ghost_mode_B.i_k); b_j <= n; b_j =
             static_cast<int16_T>(b_j + 1)) {
          ghost_mode_B.b_i_c = (static_cast<int16_T>(ghost_mode_B.i_k) + 3 *
                                (b_j - 1)) - 1;
          b_H[ghost_mode_B.b_i_c] = 0.0;
          RLinv_tmp = nA + 1;
          if (nA + 1 > 32767) {
            RLinv_tmp = 32767;
          }

          for (c_k = static_cast<int16_T>(RLinv_tmp); c_k <= n; c_k =
               static_cast<int16_T>(c_k + 1)) {
            RLinv_tmp = (c_k - 1) * 3;
            b_H[ghost_mode_B.b_i_c] -= ghost_mode_B.TL[(RLinv_tmp + static_cast<
              int16_T>(ghost_mode_B.i_k)) - 1] * ghost_mode_B.TL[(RLinv_tmp +
              b_j) - 1];
          }

          b_H[(b_j + 3 * (static_cast<int16_T>(ghost_mode_B.i_k) - 1)) - 1] =
            b_H[ghost_mode_B.b_i_c];
        }

        ghost_mode_B.i_k++;
      }

      ghost_mode_B.i_k = 1;
      while (ghost_mode_B.i_k - 1 <= nA - 1) {
        ghost_mode_B.f_i = 1;
        while (ghost_mode_B.f_i - 1 <= n - 1) {
          ghost_mode_B.b_i_c = (static_cast<int16_T>(ghost_mode_B.f_i) + 3 * (
            static_cast<int16_T>(ghost_mode_B.i_k) - 1)) - 1;
          D[ghost_mode_B.b_i_c] = 0.0;
          for (b_j = static_cast<int16_T>(ghost_mode_B.i_k); b_j <= nA; b_j =
               static_cast<int16_T>(b_j + 1)) {
            RLinv_tmp = (b_j - 1) * 3;
            D[ghost_mode_B.b_i_c] += ghost_mode_B.TL[(RLinv_tmp + static_cast<
              int16_T>(ghost_mode_B.f_i)) - 1] * RLinv[(RLinv_tmp + static_cast<
              int16_T>(ghost_mode_B.i_k)) - 1];
          }

          ghost_mode_B.f_i++;
        }

        ghost_mode_B.i_k++;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S27>/optimizer'
static real_T ghost_mode_mtimes(const real_T b_A[3], const real_T B[3])
{
  return (b_A[0] * B[0] + b_A[1] * B[1]) + b_A[2] * B[2];
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_DropConstraint(int16_T kDrop, int16_T iA[4], int16_T *nA,
  int16_T iC[4])
{
  int32_T tmp;
  int16_T i;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (*nA - 1 < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= static_cast<int16_T>(tmp); i = static_cast<int16_T>(i +
          1)) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (*nA - 1 < -32768) {
    tmp = -32768;
  }

  *nA = static_cast<int16_T>(tmp);
}

// Function for MATLAB Function: '<S27>/optimizer'
static void ghost_mode_qpkwik(const real_T b_Linv[9], const real_T b_Hinv[9],
  const real_T f[3], const real_T b_Ac[12], const real_T b[4], int16_T iA[4],
  int16_T maxiter, real_T FeasTol, real_T x[3], real_T lambda[4], real_T *status)
{
  int32_T exitg1;
  int32_T exitg3;
  int16_T kDrop;
  int16_T kNext;
  int16_T nA;
  int16_T tmp;
  int16_T tmp_0;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  lambda[0] = 0.0;
  lambda[1] = 0.0;
  lambda[2] = 0.0;
  lambda[3] = 0.0;
  x[0] = 0.0;
  ghost_mode_B.r[0] = 0.0;
  x[1] = 0.0;
  ghost_mode_B.r[1] = 0.0;
  x[2] = 0.0;
  ghost_mode_B.r[2] = 0.0;
  ghost_mode_B.rMin = 0.0;
  cTolComputed = false;
  ghost_mode_B.cTol[0] = 1.0;
  ghost_mode_B.iC[0] = 0;
  ghost_mode_B.cTol[1] = 1.0;
  ghost_mode_B.iC[1] = 0;
  ghost_mode_B.cTol[2] = 1.0;
  ghost_mode_B.iC[2] = 0;
  ghost_mode_B.cTol[3] = 1.0;
  ghost_mode_B.iC[3] = 0;
  nA = 0;
  if (iA[0] == 1) {
    nA = 1;
    ghost_mode_B.iC[0] = 1;
  }

  if (iA[1] == 1) {
    ghost_mode_B.i = nA + 1;
    nA = static_cast<int16_T>(nA + 1);
    ghost_mode_B.iC[static_cast<int16_T>(ghost_mode_B.i) - 1] = 2;
  }

  if (iA[2] == 1) {
    ghost_mode_B.i = nA + 1;
    nA = static_cast<int16_T>(nA + 1);
    ghost_mode_B.iC[static_cast<int16_T>(ghost_mode_B.i) - 1] = 3;
  }

  if (iA[3] == 1) {
    ghost_mode_B.i = nA + 1;
    nA = static_cast<int16_T>(nA + 1);
    ghost_mode_B.iC[static_cast<int16_T>(ghost_mode_B.i) - 1] = 4;
  }

  guard1 = false;
  if (nA > 0) {
    for (ghost_mode_B.i = 0; ghost_mode_B.i < 6; ghost_mode_B.i++) {
      ghost_mode_B.Opt[ghost_mode_B.i] = 0.0;
    }

    ghost_mode_B.Rhs[0] = f[0];
    ghost_mode_B.Rhs[3] = 0.0;
    ghost_mode_B.Rhs[1] = f[1];
    ghost_mode_B.Rhs[4] = 0.0;
    ghost_mode_B.Rhs[2] = f[2];
    ghost_mode_B.Rhs[5] = 0.0;
    DualFeasible = false;
    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (static_cast<int32_T>(*status) <=
           maxiter)) {
        ghost_mode_KWIKfactor(b_Ac, ghost_mode_B.iC, nA, b_Linv, ghost_mode_B.D,
                              ghost_mode_B.b_H, 3, ghost_mode_B.RLinv,
                              &ghost_mode_B.Xnorm0);
        if (ghost_mode_B.Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            iA[0] = 0;
            ghost_mode_B.iC[0] = 0;
            iA[1] = 0;
            ghost_mode_B.iC[1] = 0;
            iA[2] = 0;
            ghost_mode_B.iC[2] = 0;
            iA[3] = 0;
            ghost_mode_B.iC[3] = 0;
            ColdReset = true;
          }
        } else {
          ghost_mode_B.r_tmp = 1;
          while (ghost_mode_B.r_tmp - 1 <= nA - 1) {
            ghost_mode_B.i = static_cast<int16_T>(ghost_mode_B.r_tmp) + 3;
            if (static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 > 32767) {
              ghost_mode_B.i = 32767;
            }

            ghost_mode_B.Rhs[ghost_mode_B.i - 1] = b[ghost_mode_B.iC[
              static_cast<int16_T>(ghost_mode_B.r_tmp) - 1] - 1];
            for (kNext = static_cast<int16_T>(ghost_mode_B.r_tmp); kNext <= nA;
                 kNext = static_cast<int16_T>(kNext + 1)) {
              ghost_mode_B.i = (kNext + 3 * (static_cast<int16_T>
                (ghost_mode_B.r_tmp) - 1)) - 1;
              ghost_mode_B.U[ghost_mode_B.i] = 0.0;
              ghost_mode_B.b_k = 1;
              while (ghost_mode_B.b_k - 1 <= nA - 1) {
                ghost_mode_B.U_tmp = (static_cast<int16_T>(ghost_mode_B.b_k) - 1)
                  * 3;
                ghost_mode_B.U[ghost_mode_B.i] += ghost_mode_B.RLinv
                  [(ghost_mode_B.U_tmp + kNext) - 1] * ghost_mode_B.RLinv
                  [(ghost_mode_B.U_tmp + static_cast<int16_T>(ghost_mode_B.r_tmp))
                  - 1];
                ghost_mode_B.b_k++;
              }

              ghost_mode_B.U[(static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 *
                              (kNext - 1)) - 1] = ghost_mode_B.U[ghost_mode_B.i];
            }

            ghost_mode_B.r_tmp++;
          }

          for (ghost_mode_B.r_tmp = 0; ghost_mode_B.r_tmp < 3;
               ghost_mode_B.r_tmp++) {
            ghost_mode_B.Opt[ghost_mode_B.r_tmp] =
              (ghost_mode_B.b_H[ghost_mode_B.r_tmp] * ghost_mode_B.Rhs[0] +
               ghost_mode_B.b_H[ghost_mode_B.r_tmp + 3] * ghost_mode_B.Rhs[1]) +
              ghost_mode_B.b_H[ghost_mode_B.r_tmp + 6] * ghost_mode_B.Rhs[2];
            ghost_mode_B.b_k = 1;
            while (ghost_mode_B.b_k - 1 <= nA - 1) {
              ghost_mode_B.i = static_cast<int16_T>(ghost_mode_B.b_k) + 3;
              if (static_cast<int16_T>(ghost_mode_B.b_k) + 3 > 32767) {
                ghost_mode_B.i = 32767;
              }

              ghost_mode_B.Opt[ghost_mode_B.r_tmp] += ghost_mode_B.D[(
                static_cast<int16_T>(ghost_mode_B.b_k) - 1) * 3 +
                ghost_mode_B.r_tmp] * ghost_mode_B.Rhs[ghost_mode_B.i - 1];
              ghost_mode_B.b_k++;
            }
          }

          ghost_mode_B.r_tmp = 1;
          while (ghost_mode_B.r_tmp - 1 <= nA - 1) {
            ghost_mode_B.i = static_cast<int16_T>(ghost_mode_B.r_tmp) + 3;
            if (static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 > 32767) {
              ghost_mode_B.i = 32767;
            }

            ghost_mode_B.b_k = (static_cast<int16_T>(ghost_mode_B.r_tmp) - 1) *
              3;
            ghost_mode_B.Opt[ghost_mode_B.i - 1] =
              (ghost_mode_B.D[ghost_mode_B.b_k + 1] * ghost_mode_B.Rhs[1] +
               ghost_mode_B.D[ghost_mode_B.b_k] * ghost_mode_B.Rhs[0]) +
              ghost_mode_B.D[ghost_mode_B.b_k + 2] * ghost_mode_B.Rhs[2];
            ghost_mode_B.b_k = 1;
            while (ghost_mode_B.b_k - 1 <= nA - 1) {
              ghost_mode_B.i = static_cast<int16_T>(ghost_mode_B.r_tmp) + 3;
              if (static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 > 32767) {
                ghost_mode_B.i = 32767;
              }

              ghost_mode_B.U_tmp = static_cast<int16_T>(ghost_mode_B.r_tmp) + 3;
              if (static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 > 32767) {
                ghost_mode_B.U_tmp = 32767;
              }

              ghost_mode_B.i_c = static_cast<int16_T>(ghost_mode_B.b_k) + 3;
              if (static_cast<int16_T>(ghost_mode_B.b_k) + 3 > 32767) {
                ghost_mode_B.i_c = 32767;
              }

              ghost_mode_B.Opt[ghost_mode_B.i - 1] = ghost_mode_B.U[((
                static_cast<int16_T>(ghost_mode_B.b_k) - 1) * 3 +
                static_cast<int16_T>(ghost_mode_B.r_tmp)) - 1] *
                ghost_mode_B.Rhs[ghost_mode_B.i_c - 1] +
                ghost_mode_B.Opt[ghost_mode_B.U_tmp - 1];
              ghost_mode_B.b_k++;
            }

            ghost_mode_B.r_tmp++;
          }

          ghost_mode_B.Xnorm0 = -1.0E-12;
          kDrop = 0;
          ghost_mode_B.r_tmp = 1;
          while (ghost_mode_B.r_tmp - 1 <= nA - 1) {
            ghost_mode_B.i = static_cast<int16_T>(ghost_mode_B.r_tmp) + 3;
            if (static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 > 32767) {
              ghost_mode_B.i = 32767;
            }

            lambda[ghost_mode_B.iC[static_cast<int16_T>(ghost_mode_B.r_tmp) - 1]
              - 1] = ghost_mode_B.Opt[ghost_mode_B.i - 1];
            ghost_mode_B.i = static_cast<int16_T>(ghost_mode_B.r_tmp) + 3;
            if (static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 > 32767) {
              ghost_mode_B.i = 32767;
            }

            if ((ghost_mode_B.Opt[ghost_mode_B.i - 1] < ghost_mode_B.Xnorm0) &&
                (static_cast<int16_T>(ghost_mode_B.r_tmp) <= nA)) {
              kDrop = static_cast<int16_T>(ghost_mode_B.r_tmp);
              ghost_mode_B.i = static_cast<int16_T>(ghost_mode_B.r_tmp) + 3;
              if (static_cast<int16_T>(ghost_mode_B.r_tmp) + 3 > 32767) {
                ghost_mode_B.i = 32767;
              }

              ghost_mode_B.Xnorm0 = ghost_mode_B.Opt[ghost_mode_B.i - 1];
            }

            ghost_mode_B.r_tmp++;
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            x[0] = ghost_mode_B.Opt[0];
            x[1] = ghost_mode_B.Opt[1];
            x[2] = ghost_mode_B.Opt[2];
          } else {
            (*status)++;
            if (static_cast<int32_T>(*status) > 5) {
              nA = 0;
              iA[0] = 0;
              ghost_mode_B.iC[0] = 0;
              iA[1] = 0;
              ghost_mode_B.iC[1] = 0;
              iA[2] = 0;
              ghost_mode_B.iC[2] = 0;
              iA[3] = 0;
              ghost_mode_B.iC[3] = 0;
              ColdReset = true;
            } else {
              lambda[ghost_mode_B.iC[kDrop - 1] - 1] = 0.0;
              ghost_mode_DropConstraint(kDrop, iA, &nA, ghost_mode_B.iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          lambda[0] = 0.0;
          lambda[1] = 0.0;
          lambda[2] = 0.0;
          lambda[3] = 0.0;
          ghost_mode_Unconstrained(b_Hinv, f, x, 3);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    ghost_mode_Unconstrained(b_Hinv, f, x, 3);
    guard1 = true;
  }

  if (guard1) {
    ghost_mode_B.Xnorm0 = ghost_mode_norm(x);
    exitg2 = false;
    while ((!exitg2) && (static_cast<int32_T>(*status) <= maxiter)) {
      ghost_mode_B.cMin = -FeasTol;
      kNext = 0;
      for (ghost_mode_B.i = 0; ghost_mode_B.i < 4; ghost_mode_B.i++) {
        ghost_mode_B.t2 = ghost_mode_B.cTol[ghost_mode_B.i];
        if (!cTolComputed) {
          ghost_mode_B.b_Ac[0] = b_Ac[ghost_mode_B.i] * x[0];
          ghost_mode_B.b_Ac[1] = b_Ac[ghost_mode_B.i + 4] * x[1];
          ghost_mode_B.b_Ac[2] = b_Ac[ghost_mode_B.i + 8] * x[2];
          ghost_mode_abs(ghost_mode_B.b_Ac, ghost_mode_B.z);
          ghost_mode_B.cVal = ghost_mode_maximum(ghost_mode_B.z);
          if ((!(ghost_mode_B.t2 > ghost_mode_B.cVal)) && (!rtIsNaN
               (ghost_mode_B.cVal))) {
            ghost_mode_B.t2 = ghost_mode_B.cVal;
          }
        }

        if (iA[ghost_mode_B.i] == 0) {
          ghost_mode_B.cVal = (((b_Ac[ghost_mode_B.i] * x[0] +
            b_Ac[ghost_mode_B.i + 4] * x[1]) + b_Ac[ghost_mode_B.i + 8] * x[2])
                               - b[ghost_mode_B.i]) / ghost_mode_B.t2;
          if (ghost_mode_B.cVal < ghost_mode_B.cMin) {
            ghost_mode_B.cMin = ghost_mode_B.cVal;
            kNext = static_cast<int16_T>(ghost_mode_B.i + 1);
          }
        }

        ghost_mode_B.cTol[ghost_mode_B.i] = ghost_mode_B.t2;
      }

      cTolComputed = true;
      if (kNext <= 0) {
        exitg2 = true;
      } else if (static_cast<int32_T>(*status) == maxiter) {
        *status = 0.0;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((kNext > 0) && (static_cast<int32_T>(*status) <= maxiter)) {
            guard2 = false;
            if (nA == 0) {
              for (ghost_mode_B.i = 0; ghost_mode_B.i < 3; ghost_mode_B.i++) {
                ghost_mode_B.z[ghost_mode_B.i] = b_Hinv[ghost_mode_B.i + 6] *
                  b_Ac[kNext + 7] + (b_Hinv[ghost_mode_B.i + 3] * b_Ac[kNext + 3]
                                     + b_Ac[kNext - 1] * b_Hinv[ghost_mode_B.i]);
              }

              guard2 = true;
            } else {
              ghost_mode_KWIKfactor(b_Ac, ghost_mode_B.iC, nA, b_Linv,
                                    ghost_mode_B.D, ghost_mode_B.b_H, 3,
                                    ghost_mode_B.RLinv, &ghost_mode_B.cMin);
              if (ghost_mode_B.cMin <= 0.0) {
                *status = -2.0;
                exitg1 = 1;
              } else {
                for (ghost_mode_B.i = 0; ghost_mode_B.i < 9; ghost_mode_B.i++) {
                  ghost_mode_B.U[ghost_mode_B.i] =
                    -ghost_mode_B.b_H[ghost_mode_B.i];
                }

                for (ghost_mode_B.i = 0; ghost_mode_B.i < 3; ghost_mode_B.i++) {
                  ghost_mode_B.z[ghost_mode_B.i] = ghost_mode_B.U[ghost_mode_B.i
                    + 6] * b_Ac[kNext + 7] + (ghost_mode_B.U[ghost_mode_B.i + 3]
                    * b_Ac[kNext + 3] + b_Ac[kNext - 1] *
                    ghost_mode_B.U[ghost_mode_B.i]);
                }

                ghost_mode_B.i = 1;
                while (ghost_mode_B.i - 1 <= nA - 1) {
                  ghost_mode_B.r_tmp = (static_cast<int16_T>(ghost_mode_B.i) - 1)
                    * 3;
                  ghost_mode_B.r[static_cast<int16_T>(ghost_mode_B.i) - 1] =
                    (ghost_mode_B.D[ghost_mode_B.r_tmp + 1] * b_Ac[kNext + 3] +
                     ghost_mode_B.D[ghost_mode_B.r_tmp] * b_Ac[kNext - 1]) +
                    ghost_mode_B.D[ghost_mode_B.r_tmp + 2] * b_Ac[kNext + 7];
                  ghost_mode_B.i++;
                }

                guard2 = true;
              }
            }

            if (guard2) {
              kDrop = 0;
              ghost_mode_B.cMin = 0.0;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0) {
                ghost_mode_B.i = 0;
                exitg4 = false;
                while ((!exitg4) && (ghost_mode_B.i <= nA - 1)) {
                  if (ghost_mode_B.r[ghost_mode_B.i] >= 1.0E-12) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    ghost_mode_B.i++;
                  }
                }
              }

              if ((nA != 0) && (!ColdReset)) {
                ghost_mode_B.i = 1;
                while (ghost_mode_B.i - 1 <= nA - 1) {
                  ghost_mode_B.t2 = ghost_mode_B.r[static_cast<int16_T>
                    (ghost_mode_B.i) - 1];
                  if (ghost_mode_B.t2 > 1.0E-12) {
                    ghost_mode_B.t2 = lambda[ghost_mode_B.iC[static_cast<int16_T>
                      (ghost_mode_B.i) - 1] - 1] / ghost_mode_B.t2;
                    if ((kDrop == 0) || (ghost_mode_B.t2 < ghost_mode_B.rMin)) {
                      ghost_mode_B.rMin = ghost_mode_B.t2;
                      kDrop = static_cast<int16_T>(ghost_mode_B.i);
                    }
                  }

                  ghost_mode_B.i++;
                }

                if (kDrop > 0) {
                  ghost_mode_B.cMin = ghost_mode_B.rMin;
                  DualFeasible = false;
                }
              }

              ghost_mode_B.t2 = b_Ac[kNext - 1];
              ghost_mode_B.b_Ac[0] = ghost_mode_B.t2;
              ghost_mode_B.cVal = b_Ac[kNext + 3];
              ghost_mode_B.b_Ac[1] = ghost_mode_B.cVal;
              ghost_mode_B.b_Ac_tmp = b_Ac[kNext + 7];
              ghost_mode_B.b_Ac[2] = ghost_mode_B.b_Ac_tmp;
              ghost_mode_B.zTa = ghost_mode_mtimes(ghost_mode_B.z,
                ghost_mode_B.b_Ac);
              if (ghost_mode_B.zTa <= 0.0) {
                ghost_mode_B.t2 = 0.0;
                ColdReset = true;
              } else {
                ghost_mode_B.t2 = (b[kNext - 1] - ((ghost_mode_B.t2 * x[0] +
                  ghost_mode_B.cVal * x[1]) + ghost_mode_B.b_Ac_tmp * x[2])) /
                  ghost_mode_B.zTa;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1.0;
                exitg1 = 1;
              } else {
                if (ColdReset) {
                  ghost_mode_B.cVal = ghost_mode_B.cMin;
                } else if (DualFeasible) {
                  ghost_mode_B.cVal = ghost_mode_B.t2;
                } else if ((ghost_mode_B.cMin < ghost_mode_B.t2) || rtIsNaN
                           (ghost_mode_B.t2)) {
                  ghost_mode_B.cVal = ghost_mode_B.cMin;
                } else {
                  ghost_mode_B.cVal = ghost_mode_B.t2;
                }

                ghost_mode_B.i = 1;
                while (ghost_mode_B.i - 1 <= nA - 1) {
                  ghost_mode_B.r_tmp = ghost_mode_B.iC[static_cast<int16_T>
                    (ghost_mode_B.i) - 1];
                  lambda[ghost_mode_B.r_tmp - 1] -= ghost_mode_B.r
                    [static_cast<int16_T>(ghost_mode_B.i) - 1] *
                    ghost_mode_B.cVal;
                  if ((ghost_mode_B.r_tmp <= 4) && (lambda[ghost_mode_B.r_tmp -
                       1] < 0.0)) {
                    lambda[ghost_mode_B.r_tmp - 1] = 0.0;
                  }

                  ghost_mode_B.i++;
                }

                lambda[kNext - 1] += ghost_mode_B.cVal;
                if (ghost_mode_B.cVal == ghost_mode_B.cMin) {
                  ghost_mode_DropConstraint(kDrop, iA, &nA, ghost_mode_B.iC);
                }

                if (!ColdReset) {
                  x[0] += ghost_mode_B.cVal * ghost_mode_B.z[0];
                  x[1] += ghost_mode_B.cVal * ghost_mode_B.z[1];
                  x[2] += ghost_mode_B.cVal * ghost_mode_B.z[2];
                  if (ghost_mode_B.cVal == ghost_mode_B.t2) {
                    if (nA == 3) {
                      *status = -1.0;
                      exitg1 = 1;
                    } else {
                      ghost_mode_B.i = nA + 1;
                      if (nA + 1 > 32767) {
                        ghost_mode_B.i = 32767;
                      }

                      nA = static_cast<int16_T>(ghost_mode_B.i);
                      ghost_mode_B.iC[static_cast<int16_T>(ghost_mode_B.i) - 1] =
                        kNext;
                      kDrop = static_cast<int16_T>(ghost_mode_B.i);
                      exitg4 = false;
                      while ((!exitg4) && (kDrop > 1)) {
                        tmp = ghost_mode_B.iC[kDrop - 1];
                        tmp_0 = ghost_mode_B.iC[kDrop - 2];
                        if (tmp > tmp_0) {
                          exitg4 = true;
                        } else {
                          ghost_mode_B.iC[kDrop - 1] = tmp_0;
                          ghost_mode_B.iC[kDrop - 2] = tmp;
                          kDrop = static_cast<int16_T>(kDrop - 1);
                        }
                      }

                      iA[kNext - 1] = 1;
                      kNext = 0;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            ghost_mode_B.cMin = ghost_mode_norm(x);
            if (fabs(ghost_mode_B.cMin - ghost_mode_B.Xnorm0) > 0.001) {
              ghost_mode_B.Xnorm0 = ghost_mode_B.cMin;
              ghost_mode_abs_e(b, ghost_mode_B.dv);
              ghost_mode_maximum2(ghost_mode_B.dv, 1.0, ghost_mode_B.cTol);
              cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

// Model step function
void ghost_mode_step(void)
{
  boolean_T b_varargout_1;
  static const int8_T b_a[6] = { 1, 0, 0, 1, 0, 1 };

  static const real_T a[6] = { 0.040656906030038915, 0.01688344038931067,
    -0.016354075460776416, 0.00052936492853441824, 0.027185567501195003,
    0.045396132984354055 };

  static const real_T b_Kx[6] = { 36.220642045159124, 17.644113092622845,
    12.145419514838553, 27.285290231142255, 13.926699985160642,
    10.167146190906635 };

  static const real_T b_Kr[40] = { -0.11119189019831843, -0.27439918201972158,
    -0.43352892883251071, -0.528132532636282, -0.95110913686949916,
    -0.76275645804754355, -1.6492281613596929, -0.9797101467984477,
    -2.5142890785984142, -1.1803243977965896, -3.5337189902837371,
    -1.3658297834632702, -4.6958919010696558, -1.5373641980929802,
    -5.990057404443724, -1.695979837723125, -7.4062747394867037,
    -1.8426496543286748, -8.9353518140168653, -1.978273323931917, -0.0, -0.0,
    -0.11119189019831843, -0.27439918201972158, -0.43352892883251071,
    -0.528132532636282, -0.95110913686949916, -0.76275645804754355,
    -1.6492281613596929, -0.9797101467984477, -2.5142890785984142,
    -1.1803243977965896, -3.5337189902837371, -1.3658297834632702,
    -4.6958919010696558, -1.5373641980929802, -5.990057404443724,
    -1.695979837723125, -7.4062747394867037, -1.8426496543286748 };

  static const real_T b_Linv[9] = { 0.20381964007181325, -0.7345968158245969,
    0.0, 0.0, 0.83855182475548984, 0.0, 0.0, 0.0, 0.003162277660168379 };

  static const real_T b_Hinv[9] = { 0.58117492749864019, -0.61599750036928824,
    0.0, -0.61599750036928824, 0.70316916280076169, 0.0, 0.0, 0.0,
    9.9999999999999974E-6 };

  static const real_T b_Ac[12] = { -1.0, -1.0, 1.0, 1.0, -0.0, -1.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0 };

  static const real_T b_Mlim[4] = { 1.5, 1.5, 3.0, 3.0 };

  static const int8_T b_Mu1[4] = { -1, -1, 1, 1 };

  static const real_T c_a[9] = { 1.0, 0.0, 0.0, 0.048092606108037436,
    0.92468697883481332, 0.0, 0.0, 0.0, 1.0 };

  static const real_T d_a[3] = { 0.0021254165654372194, 0.083921597658525332,
    0.0 };

  static const real_T e_a[6] = { 0.041468874678430565, 0.015611897485929348,
    -0.016354075460776434, 0.0018367897181928404, 0.025138140280589888,
    0.045396132984354028 };

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S29>/In1'

  b_varargout_1 = Sub_ghost_mode_83.getLatestMessage(&ghost_mode_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S29>/Enable'

  if (b_varargout_1) {
    ghost_mode_B.In1_m = ghost_mode_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // SignalConversion generated from: '<Root>/Vector Concatenate'
  ghost_mode_B.VectorConcatenate[0] = ghost_mode_B.In1_m.Twist.Linear.X;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S31>/In1'

  b_varargout_1 = Sub_ghost_mode_85.getLatestMessage
    (&ghost_mode_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S31>/Enable'

  if (b_varargout_1) {
    ghost_mode_B.In1_k = ghost_mode_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // SignalConversion generated from: '<Root>/Vector Concatenate'
  ghost_mode_B.VectorConcatenate[1] = ghost_mode_B.In1_k.Accel.Linear.X;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S30>/In1'

  b_varargout_1 = Sub_ghost_mode_84.getLatestMessage(&ghost_mode_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S30>/Enable'

  if (b_varargout_1) {
    ghost_mode_B.In1 = ghost_mode_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // MATLAB Function: '<S27>/optimizer' incorporates:
  //   Constant: '<Root>/Constant'
  //   Memory: '<S7>/Memory'
  //   Memory: '<S7>/last_x'
  //   SignalConversion generated from: '<Root>/Vector Concatenate1'
  //   UnitDelay: '<S7>/last_mv'

  for (ghost_mode_B.b_i = 0; ghost_mode_B.b_i < 10; ghost_mode_B.b_i++) {
    ghost_mode_B.rseq_tmp = ghost_mode_B.b_i << 1;
    ghost_mode_B.rseq[ghost_mode_B.rseq_tmp] = ghost_mode_B.In1.Twist.Linear.X;
    ghost_mode_B.rseq[ghost_mode_B.rseq_tmp + 1] =
      ghost_mode_P.Constant_Value_mh;
  }

  ghost_mode_B.xk[0] = ghost_mode_DW.last_x_PreviousInput[0];
  ghost_mode_B.xk[1] = ghost_mode_DW.last_x_PreviousInput[1];
  ghost_mode_B.xk[2] = ghost_mode_DW.last_x_PreviousInput[2];
  for (ghost_mode_B.b_i = 0; ghost_mode_B.b_i < 2; ghost_mode_B.b_i++) {
    ghost_mode_B.VectorConcatenate1[ghost_mode_B.b_i] =
      ghost_mode_B.VectorConcatenate[ghost_mode_B.b_i] - ((static_cast<real_T>
      (b_a[ghost_mode_B.b_i + 2]) * ghost_mode_B.xk[1] + static_cast<real_T>
      (b_a[ghost_mode_B.b_i]) * ghost_mode_B.xk[0]) + static_cast<real_T>
      (b_a[ghost_mode_B.b_i + 4]) * ghost_mode_B.xk[2]);
  }

  for (ghost_mode_B.b_i = 0; ghost_mode_B.b_i < 3; ghost_mode_B.b_i++) {
    ghost_mode_B.xest[ghost_mode_B.b_i] = (a[ghost_mode_B.b_i + 3] *
      ghost_mode_B.VectorConcatenate1[1] + a[ghost_mode_B.b_i] *
      ghost_mode_B.VectorConcatenate1[0]) + ghost_mode_B.xk[ghost_mode_B.b_i];
    ghost_mode_B.f[ghost_mode_B.b_i] = 0.0;
  }

  for (ghost_mode_B.rseq_tmp = 0; ghost_mode_B.rseq_tmp < 2;
       ghost_mode_B.rseq_tmp++) {
    ghost_mode_B.b_Kr = 0.0;
    for (ghost_mode_B.b_i = 0; ghost_mode_B.b_i < 20; ghost_mode_B.b_i++) {
      ghost_mode_B.b_Kr += b_Kr[20 * ghost_mode_B.rseq_tmp + ghost_mode_B.b_i] *
        ghost_mode_B.rseq[ghost_mode_B.b_i];
    }

    ghost_mode_B.f[ghost_mode_B.rseq_tmp] = (((b_Kx[3 * ghost_mode_B.rseq_tmp +
      1] * ghost_mode_B.xest[1] + b_Kx[3 * ghost_mode_B.rseq_tmp] *
      ghost_mode_B.xest[0]) + b_Kx[3 * ghost_mode_B.rseq_tmp + 2] *
      ghost_mode_B.xest[2]) + ghost_mode_B.b_Kr) + (-2.9734171465447261 *
      static_cast<real_T>(ghost_mode_B.rseq_tmp) + 24.06101313842251) *
      ghost_mode_DW.last_mv_DSTATE;
  }

  for (ghost_mode_B.b_i = 0; ghost_mode_B.b_i < 4; ghost_mode_B.b_i++) {
    ghost_mode_B.iAnew[ghost_mode_B.b_i] =
      ghost_mode_DW.Memory_PreviousInput[ghost_mode_B.b_i];
    ghost_mode_B.b_Mlim[ghost_mode_B.b_i] = -((((0.0 * ghost_mode_B.xest[0] +
      0.0 * ghost_mode_B.xest[1]) + 0.0 * ghost_mode_B.xest[2]) +
      b_Mlim[ghost_mode_B.b_i]) + static_cast<real_T>(b_Mu1[ghost_mode_B.b_i]) *
      ghost_mode_DW.last_mv_DSTATE);
  }

  ghost_mode_qpkwik(b_Linv, b_Hinv, ghost_mode_B.f, b_Ac, ghost_mode_B.b_Mlim,
                    ghost_mode_B.iAnew, 120, 1.0E-6, ghost_mode_B.xest,
                    ghost_mode_B.a__1, &ghost_mode_B.b_Kr);
  if ((ghost_mode_B.b_Kr < 0.0) || (ghost_mode_B.b_Kr == 0.0)) {
    ghost_mode_B.xest[0] = 0.0;
  }

  ghost_mode_DW.last_mv_DSTATE += ghost_mode_B.xest[0];

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Gain: '<S7>/umin_scale1'
  //   MATLAB Function: '<S27>/optimizer'

  ghost_mode_B.BusAssignment1.Data = ghost_mode_P.umin_scale1_Gain *
    ghost_mode_DW.last_mv_DSTATE;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_ghost_mode_82.publish(&ghost_mode_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
  for (ghost_mode_B.b_i = 0; ghost_mode_B.b_i < 3; ghost_mode_B.b_i++) {
    // Update for Memory: '<S7>/last_x' incorporates:
    //   MATLAB Function: '<S27>/optimizer'

    ghost_mode_DW.last_x_PreviousInput[ghost_mode_B.b_i] =
      (((c_a[ghost_mode_B.b_i + 3] * ghost_mode_B.xk[1] + c_a[ghost_mode_B.b_i] *
         ghost_mode_B.xk[0]) + c_a[ghost_mode_B.b_i + 6] * ghost_mode_B.xk[2]) +
       d_a[ghost_mode_B.b_i] * ghost_mode_DW.last_mv_DSTATE) +
      (e_a[ghost_mode_B.b_i + 3] * ghost_mode_B.VectorConcatenate1[1] +
       e_a[ghost_mode_B.b_i] * ghost_mode_B.VectorConcatenate1[0]);
  }

  // Update for Memory: '<S7>/Memory' incorporates:
  //   MATLAB Function: '<S27>/optimizer'

  ghost_mode_DW.Memory_PreviousInput[0] = (ghost_mode_B.iAnew[0] != 0);
  ghost_mode_DW.Memory_PreviousInput[1] = (ghost_mode_B.iAnew[1] != 0);
  ghost_mode_DW.Memory_PreviousInput[2] = (ghost_mode_B.iAnew[2] != 0);
  ghost_mode_DW.Memory_PreviousInput[3] = (ghost_mode_B.iAnew[3] != 0);
}

// Model initialize function
void ghost_mode_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_1[19];
    char_T b_zeroDelimTopic_0[15];
    char_T b_zeroDelimTopic[13];
    static const char_T tmp[12] = { '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e', '/',
      'v', 'e', 'l' };

    static const char_T tmp_0[14] = { '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '/', 'a', 'c', 'c', 'e', 'l' };

    static const char_T tmp_1[18] = { '/', 'g', 'h', 'o', 's', 't', '/', 'v',
      'e', 'h', 'i', 'c', 'l', 'e', '/', 'v', 'e', 'l' };

    static const char_T tmp_2[12] = { '/', 't', 'i', 'm', 'e', 'd', '_', 'a',
      'c', 'c', 'e', 'l' };

    // InitializeConditions for Memory: '<S7>/last_x'
    ghost_mode_DW.last_x_PreviousInput[0] =
      ghost_mode_P.last_x_InitialCondition[0];
    ghost_mode_DW.last_x_PreviousInput[1] =
      ghost_mode_P.last_x_InitialCondition[1];
    ghost_mode_DW.last_x_PreviousInput[2] =
      ghost_mode_P.last_x_InitialCondition[2];

    // InitializeConditions for UnitDelay: '<S7>/last_mv'
    ghost_mode_DW.last_mv_DSTATE = ghost_mode_P.last_mv_InitialCondition;

    // InitializeConditions for Memory: '<S7>/Memory'
    ghost_mode_DW.Memory_PreviousInput[0] =
      ghost_mode_P.Memory_InitialCondition[0];
    ghost_mode_DW.Memory_PreviousInput[1] =
      ghost_mode_P.Memory_InitialCondition[1];
    ghost_mode_DW.Memory_PreviousInput[2] =
      ghost_mode_P.Memory_InitialCondition[2];
    ghost_mode_DW.Memory_PreviousInput[3] =
      ghost_mode_P.Memory_InitialCondition[3];

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S29>/Out1' incorporates:
    //   Inport: '<S29>/In1'

    ghost_mode_B.In1_m = ghost_mode_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    ghost_mode_DW.obj_k.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[12] = '\x00';
    Sub_ghost_mode_83.createSubscriber(&b_zeroDelimTopic[0], 1);
    ghost_mode_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S31>/Out1' incorporates:
    //   Inport: '<S31>/In1'

    ghost_mode_B.In1_k = ghost_mode_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    ghost_mode_DW.obj_c.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[14] = '\x00';
    Sub_ghost_mode_85.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ghost_mode_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S30>/Out1' incorporates:
    //   Inport: '<S30>/In1'

    ghost_mode_B.In1 = ghost_mode_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    ghost_mode_DW.obj_o.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[18] = '\x00';
    Sub_ghost_mode_84.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    ghost_mode_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    ghost_mode_DW.obj.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic[i] = tmp_2[i];
    }

    b_zeroDelimTopic[12] = '\x00';
    Pub_ghost_mode_82.createPublisher(&b_zeroDelimTopic[0], 1);
    ghost_mode_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void ghost_mode_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!ghost_mode_DW.obj_k.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!ghost_mode_DW.obj_c.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!ghost_mode_DW.obj_o.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!ghost_mode_DW.obj.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
