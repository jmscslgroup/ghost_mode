//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.h
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.43
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Jun 30 10:16:19 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ghost_mode_h_
#define RTW_HEADER_ghost_mode_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ghost_mode_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_ghost_mode_T {
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1;// '<S368>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1_d;// '<S367>/In1'
  SL_Bus_ghost_mode_geometry_msgs_AccelStamped In1_e;// '<S369>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped b_varargout_2;
  SL_Bus_ghost_mode_geometry_msgs_AccelStamped b_varargout_2_m;
  real_T Sum;                          // '<Root>/Sum'
  real_T ProportionalGain;             // '<S50>/Proportional Gain'
  real_T DerivativeGain;               // '<S39>/Derivative Gain'
  real_T FilterCoefficient;            // '<S48>/Filter Coefficient'
  real_T ProportionalGain_l;           // '<S100>/Proportional Gain'
  real_T DerivativeGain_n;             // '<S89>/Derivative Gain'
  real_T FilterCoefficient_g;          // '<S98>/Filter Coefficient'
  real_T IntegralGain;                 // '<S92>/Integral Gain'
  real_T Switch;                       // '<S86>/Switch'
  real_T IntegralGain_l;               // '<S42>/Integral Gain'
  real_T Switch_k;                     // '<S36>/Switch'
  real_T IntegralGain_f;               // '<S144>/Integral Gain'
  real_T ProportionalGain_k;           // '<S152>/Proportional Gain'
  real_T DerivativeGain_g;             // '<S141>/Derivative Gain'
  real_T FilterCoefficient_d;          // '<S150>/Filter Coefficient'
  real_T Switch_m;                     // '<S138>/Switch'
  real_T IntegralGain_lk;              // '<S194>/Integral Gain'
  real_T ProportionalGain_m;           // '<S202>/Proportional Gain'
  real_T DerivativeGain_c;             // '<S191>/Derivative Gain'
  real_T FilterCoefficient_j;          // '<S200>/Filter Coefficient'
  real_T Switch_a;                     // '<S188>/Switch'
  real_T IntegralGain_p;               // '<S247>/Integral Gain'
  real_T ProportionalGain_m4;          // '<S255>/Proportional Gain'
  real_T DerivativeGain_b;             // '<S244>/Derivative Gain'
  real_T FilterCoefficient_i;          // '<S253>/Filter Coefficient'
  real_T Switch_ab;                    // '<S241>/Switch'
  real_T IntegralGain_pq;              // '<S297>/Integral Gain'
  real_T ProportionalGain_e;           // '<S305>/Proportional Gain'
  real_T DerivativeGain_bz;            // '<S294>/Derivative Gain'
  real_T FilterCoefficient_c;          // '<S303>/Filter Coefficient'
  real_T Switch_l;                     // '<S291>/Switch'
  real_T Switch_j;                     // '<S341>/Switch'
  real_T ProportionalGain_f;           // '<S355>/Proportional Gain'
  real_T DerivativeGain_e;             // '<S344>/Derivative Gain'
  real_T FilterCoefficient_p;          // '<S353>/Filter Coefficient'
  real_T Sum_c;                        // '<S54>/Sum'
  int8_T DataTypeConv2;                // '<S341>/DataTypeConv2'
  boolean_T AND3;                      // '<S86>/AND3'
  boolean_T Memory;                    // '<S86>/Memory'
  boolean_T AND3_c;                    // '<S36>/AND3'
  boolean_T Memory_d;                  // '<S36>/Memory'
  boolean_T Memory_n;                  // '<S138>/Memory'
  boolean_T AND3_k;                    // '<S138>/AND3'
  boolean_T Memory_a;                  // '<S188>/Memory'
  boolean_T AND3_h;                    // '<S188>/AND3'
  boolean_T Memory_dp;                 // '<S241>/Memory'
  boolean_T AND3_cz;                   // '<S241>/AND3'
  boolean_T Memory_g;                  // '<S291>/Memory'
  boolean_T AND3_h0;                   // '<S291>/AND3'
  boolean_T AND3_e;                    // '<S341>/AND3'
};

// Block states (default storage) for system '<Root>'
struct DW_ghost_mode_T {
  ros_slroscpp_internal_block_P_T obj; // '<S6>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S7>/SourceBlock'
  uint8_T is_active_c3_ghost_mode;     // '<S4>/Chart'
  uint8_T is_c3_ghost_mode;            // '<S4>/Chart'
  uint8_T temporalCounter_i1;          // '<S4>/Chart'
  boolean_T Memory_PreviousInput;      // '<S86>/Memory'
  boolean_T Memory_PreviousInput_p;    // '<S36>/Memory'
  boolean_T Memory_PreviousInput_i;    // '<S138>/Memory'
  boolean_T Memory_PreviousInput_pv;   // '<S188>/Memory'
  boolean_T Memory_PreviousInput_f;    // '<S241>/Memory'
  boolean_T Memory_PreviousInput_j;    // '<S291>/Memory'
  boolean_T Memory_PreviousInput_n;    // '<S341>/Memory'
};

// Continuous states (default storage)
struct X_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S45>/Integrator'
  real_T Filter_CSTATE;                // '<S40>/Filter'
  real_T Integrator_CSTATE_p;          // '<S95>/Integrator'
  real_T Filter_CSTATE_l;              // '<S90>/Filter'
  real_T Integrator_CSTATE_h;          // '<S147>/Integrator'
  real_T Filter_CSTATE_f;              // '<S142>/Filter'
  real_T Integrator_CSTATE_p5;         // '<S197>/Integrator'
  real_T Filter_CSTATE_o;              // '<S192>/Filter'
  real_T Integrator_CSTATE_m;          // '<S250>/Integrator'
  real_T Filter_CSTATE_e;              // '<S245>/Filter'
  real_T Integrator_CSTATE_i;          // '<S300>/Integrator'
  real_T Filter_CSTATE_fu;             // '<S295>/Filter'
  real_T Integrator_CSTATE_f;          // '<S350>/Integrator'
  real_T Filter_CSTATE_d;              // '<S345>/Filter'
};

// State derivatives (default storage)
struct XDot_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S45>/Integrator'
  real_T Filter_CSTATE;                // '<S40>/Filter'
  real_T Integrator_CSTATE_p;          // '<S95>/Integrator'
  real_T Filter_CSTATE_l;              // '<S90>/Filter'
  real_T Integrator_CSTATE_h;          // '<S147>/Integrator'
  real_T Filter_CSTATE_f;              // '<S142>/Filter'
  real_T Integrator_CSTATE_p5;         // '<S197>/Integrator'
  real_T Filter_CSTATE_o;              // '<S192>/Filter'
  real_T Integrator_CSTATE_m;          // '<S250>/Integrator'
  real_T Filter_CSTATE_e;              // '<S245>/Filter'
  real_T Integrator_CSTATE_i;          // '<S300>/Integrator'
  real_T Filter_CSTATE_fu;             // '<S295>/Filter'
  real_T Integrator_CSTATE_f;          // '<S350>/Integrator'
  real_T Filter_CSTATE_d;              // '<S345>/Filter'
};

// State disabled
struct XDis_ghost_mode_T {
  boolean_T Integrator_CSTATE;         // '<S45>/Integrator'
  boolean_T Filter_CSTATE;             // '<S40>/Filter'
  boolean_T Integrator_CSTATE_p;       // '<S95>/Integrator'
  boolean_T Filter_CSTATE_l;           // '<S90>/Filter'
  boolean_T Integrator_CSTATE_h;       // '<S147>/Integrator'
  boolean_T Filter_CSTATE_f;           // '<S142>/Filter'
  boolean_T Integrator_CSTATE_p5;      // '<S197>/Integrator'
  boolean_T Filter_CSTATE_o;           // '<S192>/Filter'
  boolean_T Integrator_CSTATE_m;       // '<S250>/Integrator'
  boolean_T Filter_CSTATE_e;           // '<S245>/Filter'
  boolean_T Integrator_CSTATE_i;       // '<S300>/Integrator'
  boolean_T Filter_CSTATE_fu;          // '<S295>/Filter'
  boolean_T Integrator_CSTATE_f;       // '<S350>/Integrator'
  boolean_T Filter_CSTATE_d;           // '<S345>/Filter'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_ghost_mode_T_ {
  real_T PIDJMS0628_D;                 // Mask Parameter: PIDJMS0628_D
                                          //  Referenced by: '<S39>/Derivative Gain'

  real_T PIDJMS1_D;                    // Mask Parameter: PIDJMS1_D
                                          //  Referenced by: '<S89>/Derivative Gain'

  real_T PIDJMS0628_D_l;               // Mask Parameter: PIDJMS0628_D_l
                                          //  Referenced by: '<S141>/Derivative Gain'

  real_T PIDJMS1_D_c;                  // Mask Parameter: PIDJMS1_D_c
                                          //  Referenced by: '<S191>/Derivative Gain'

  real_T PIDJMS0628_D_g;               // Mask Parameter: PIDJMS0628_D_g
                                          //  Referenced by: '<S244>/Derivative Gain'

  real_T PIDJMS1_D_cd;                 // Mask Parameter: PIDJMS1_D_cd
                                          //  Referenced by: '<S294>/Derivative Gain'

  real_T PIDJMS0628_D_e;               // Mask Parameter: PIDJMS0628_D_e
                                          //  Referenced by: '<S344>/Derivative Gain'

  real_T PIDJMS1_I;                    // Mask Parameter: PIDJMS1_I
                                          //  Referenced by: '<S92>/Integral Gain'

  real_T PIDJMS0628_I;                 // Mask Parameter: PIDJMS0628_I
                                          //  Referenced by: '<S42>/Integral Gain'

  real_T PIDJMS0628_I_n;               // Mask Parameter: PIDJMS0628_I_n
                                          //  Referenced by: '<S144>/Integral Gain'

  real_T PIDJMS1_I_h;                  // Mask Parameter: PIDJMS1_I_h
                                          //  Referenced by: '<S194>/Integral Gain'

  real_T PIDJMS0628_I_c;               // Mask Parameter: PIDJMS0628_I_c
                                          //  Referenced by: '<S247>/Integral Gain'

  real_T PIDJMS1_I_hb;                 // Mask Parameter: PIDJMS1_I_hb
                                          //  Referenced by: '<S297>/Integral Gain'

  real_T PIDJMS0628_I_m;               // Mask Parameter: PIDJMS0628_I_m
                                          //  Referenced by: '<S347>/Integral Gain'

  real_T PIDJMS0628_InitialConditionForF;
                              // Mask Parameter: PIDJMS0628_InitialConditionForF
                                 //  Referenced by: '<S40>/Filter'

  real_T PIDJMS1_InitialConditionForFilt;
                              // Mask Parameter: PIDJMS1_InitialConditionForFilt
                                 //  Referenced by: '<S90>/Filter'

  real_T PIDJMS0628_InitialConditionFo_g;
                              // Mask Parameter: PIDJMS0628_InitialConditionFo_g
                                 //  Referenced by: '<S142>/Filter'

  real_T PIDJMS1_InitialConditionForFi_e;
                              // Mask Parameter: PIDJMS1_InitialConditionForFi_e
                                 //  Referenced by: '<S192>/Filter'

  real_T PIDJMS0628_InitialConditionFo_l;
                              // Mask Parameter: PIDJMS0628_InitialConditionFo_l
                                 //  Referenced by: '<S245>/Filter'

  real_T PIDJMS1_InitialConditionForFi_n;
                              // Mask Parameter: PIDJMS1_InitialConditionForFi_n
                                 //  Referenced by: '<S295>/Filter'

  real_T PIDJMS0628_InitialConditionFo_d;
                              // Mask Parameter: PIDJMS0628_InitialConditionFo_d
                                 //  Referenced by: '<S345>/Filter'

  real_T PIDJMS0628_InitialConditionForI;
                              // Mask Parameter: PIDJMS0628_InitialConditionForI
                                 //  Referenced by: '<S45>/Integrator'

  real_T PIDJMS1_InitialConditionForInte;
                              // Mask Parameter: PIDJMS1_InitialConditionForInte
                                 //  Referenced by: '<S95>/Integrator'

  real_T PIDJMS0628_InitialConditionFo_f;
                              // Mask Parameter: PIDJMS0628_InitialConditionFo_f
                                 //  Referenced by: '<S147>/Integrator'

  real_T PIDJMS1_InitialConditionForIn_m;
                              // Mask Parameter: PIDJMS1_InitialConditionForIn_m
                                 //  Referenced by: '<S197>/Integrator'

  real_T PIDJMS0628_InitialConditionF_d4;
                              // Mask Parameter: PIDJMS0628_InitialConditionF_d4
                                 //  Referenced by: '<S250>/Integrator'

  real_T PIDJMS1_InitialConditionForIn_g;
                              // Mask Parameter: PIDJMS1_InitialConditionForIn_g
                                 //  Referenced by: '<S300>/Integrator'

  real_T PIDJMS0628_InitialConditionF_la;
                              // Mask Parameter: PIDJMS0628_InitialConditionF_la
                                 //  Referenced by: '<S350>/Integrator'

  real_T PIDJMS1_Kt;                   // Mask Parameter: PIDJMS1_Kt
                                          //  Referenced by: '<S106>/Kt'

  real_T PIDJMS0628_Kt;                // Mask Parameter: PIDJMS0628_Kt
                                          //  Referenced by: '<S56>/Kt'

  real_T PIDJMS0628_Kt_b;              // Mask Parameter: PIDJMS0628_Kt_b
                                          //  Referenced by: '<S158>/Kt'

  real_T PIDJMS1_Kt_d;                 // Mask Parameter: PIDJMS1_Kt_d
                                          //  Referenced by: '<S208>/Kt'

  real_T PIDJMS0628_Kt_j;              // Mask Parameter: PIDJMS0628_Kt_j
                                          //  Referenced by: '<S261>/Kt'

  real_T PIDJMS1_Kt_i;                 // Mask Parameter: PIDJMS1_Kt_i
                                          //  Referenced by: '<S311>/Kt'

  real_T PIDJMS0628_LowerSaturationLimit;
                              // Mask Parameter: PIDJMS0628_LowerSaturationLimit
                                 //  Referenced by:
                                 //    '<S52>/Saturation'
                                 //    '<S38>/DeadZone'

  real_T PIDJMS1_LowerSaturationLimit;
                                 // Mask Parameter: PIDJMS1_LowerSaturationLimit
                                    //  Referenced by:
                                    //    '<S102>/Saturation'
                                    //    '<S88>/DeadZone'

  real_T PIDJMS0628_LowerSaturationLim_k;
                              // Mask Parameter: PIDJMS0628_LowerSaturationLim_k
                                 //  Referenced by:
                                 //    '<S154>/Saturation'
                                 //    '<S140>/DeadZone'

  real_T PIDJMS1_LowerSaturationLimit_l;
                               // Mask Parameter: PIDJMS1_LowerSaturationLimit_l
                                  //  Referenced by:
                                  //    '<S204>/Saturation'
                                  //    '<S190>/DeadZone'

  real_T PIDJMS0628_LowerSaturationLi_km;
                              // Mask Parameter: PIDJMS0628_LowerSaturationLi_km
                                 //  Referenced by:
                                 //    '<S257>/Saturation'
                                 //    '<S243>/DeadZone'

  real_T PIDJMS1_LowerSaturationLimit_f;
                               // Mask Parameter: PIDJMS1_LowerSaturationLimit_f
                                  //  Referenced by:
                                  //    '<S307>/Saturation'
                                  //    '<S293>/DeadZone'

  real_T PIDJMS0628_LowerSaturationLim_l;
                              // Mask Parameter: PIDJMS0628_LowerSaturationLim_l
                                 //  Referenced by: '<S343>/DeadZone'

  real_T PIDJMS0628_N;                 // Mask Parameter: PIDJMS0628_N
                                          //  Referenced by: '<S48>/Filter Coefficient'

  real_T PIDJMS1_N;                    // Mask Parameter: PIDJMS1_N
                                          //  Referenced by: '<S98>/Filter Coefficient'

  real_T PIDJMS0628_N_j;               // Mask Parameter: PIDJMS0628_N_j
                                          //  Referenced by: '<S150>/Filter Coefficient'

  real_T PIDJMS1_N_n;                  // Mask Parameter: PIDJMS1_N_n
                                          //  Referenced by: '<S200>/Filter Coefficient'

  real_T PIDJMS0628_N_f;               // Mask Parameter: PIDJMS0628_N_f
                                          //  Referenced by: '<S253>/Filter Coefficient'

  real_T PIDJMS1_N_m;                  // Mask Parameter: PIDJMS1_N_m
                                          //  Referenced by: '<S303>/Filter Coefficient'

  real_T PIDJMS0628_N_fj;              // Mask Parameter: PIDJMS0628_N_fj
                                          //  Referenced by: '<S353>/Filter Coefficient'

  real_T PIDJMS0628_P;                 // Mask Parameter: PIDJMS0628_P
                                          //  Referenced by: '<S50>/Proportional Gain'

  real_T PIDJMS1_P;                    // Mask Parameter: PIDJMS1_P
                                          //  Referenced by: '<S100>/Proportional Gain'

  real_T PIDJMS0628_P_b;               // Mask Parameter: PIDJMS0628_P_b
                                          //  Referenced by: '<S152>/Proportional Gain'

  real_T PIDJMS1_P_a;                  // Mask Parameter: PIDJMS1_P_a
                                          //  Referenced by: '<S202>/Proportional Gain'

  real_T PIDJMS0628_P_bi;              // Mask Parameter: PIDJMS0628_P_bi
                                          //  Referenced by: '<S255>/Proportional Gain'

  real_T PIDJMS1_P_f;                  // Mask Parameter: PIDJMS1_P_f
                                          //  Referenced by: '<S305>/Proportional Gain'

  real_T PIDJMS0628_P_a;               // Mask Parameter: PIDJMS0628_P_a
                                          //  Referenced by: '<S355>/Proportional Gain'

  real_T PIDJMS0628_UpperSaturationLimit;
                              // Mask Parameter: PIDJMS0628_UpperSaturationLimit
                                 //  Referenced by:
                                 //    '<S52>/Saturation'
                                 //    '<S38>/DeadZone'

  real_T PIDJMS1_UpperSaturationLimit;
                                 // Mask Parameter: PIDJMS1_UpperSaturationLimit
                                    //  Referenced by:
                                    //    '<S102>/Saturation'
                                    //    '<S88>/DeadZone'

  real_T PIDJMS0628_UpperSaturationLim_p;
                              // Mask Parameter: PIDJMS0628_UpperSaturationLim_p
                                 //  Referenced by:
                                 //    '<S154>/Saturation'
                                 //    '<S140>/DeadZone'

  real_T PIDJMS1_UpperSaturationLimit_n;
                               // Mask Parameter: PIDJMS1_UpperSaturationLimit_n
                                  //  Referenced by:
                                  //    '<S204>/Saturation'
                                  //    '<S190>/DeadZone'

  real_T PIDJMS0628_UpperSaturationLim_l;
                              // Mask Parameter: PIDJMS0628_UpperSaturationLim_l
                                 //  Referenced by:
                                 //    '<S257>/Saturation'
                                 //    '<S243>/DeadZone'

  real_T PIDJMS1_UpperSaturationLimit_b;
                               // Mask Parameter: PIDJMS1_UpperSaturationLimit_b
                                  //  Referenced by:
                                  //    '<S307>/Saturation'
                                  //    '<S293>/DeadZone'

  real_T PIDJMS0628_UpperSaturationLi_py;
                              // Mask Parameter: PIDJMS0628_UpperSaturationLi_py
                                 //  Referenced by: '<S343>/DeadZone'

  SL_Bus_ghost_mode_geometry_msgs_AccelStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S369>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_AccelStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S9>/Constant'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                            //  Referenced by: '<S367>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                                   //  Referenced by: '<S7>/Constant'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                            //  Referenced by: '<S368>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                   //  Referenced by: '<S8>/Constant'

  SL_Bus_ghost_mode_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                         //  Referenced by: '<S1>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S36>/Constant1'

  real_T Constant1_Value_c;            // Expression: 0
                                          //  Referenced by: '<S86>/Constant1'

  real_T Constant1_Value_l;            // Expression: 0
                                          //  Referenced by: '<S138>/Constant1'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S188>/Constant1'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S241>/Constant1'

  real_T Constant1_Value_a;            // Expression: 0
                                          //  Referenced by: '<S291>/Constant1'

  real_T Constant1_Value_p;            // Expression: 0
                                          //  Referenced by: '<S341>/Constant1'

  real_T Switch_Threshold;             // Expression: -0.25
                                          //  Referenced by: '<S2>/Switch'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S86>/ZeroGain'

  real_T ZeroGain_Gain_g;              // Expression: 0
                                          //  Referenced by: '<S36>/ZeroGain'

  real_T ZeroGain_Gain_j;              // Expression: 0
                                          //  Referenced by: '<S138>/ZeroGain'

  real_T ZeroGain_Gain_l;              // Expression: 0
                                          //  Referenced by: '<S188>/ZeroGain'

  real_T ZeroGain_Gain_li;             // Expression: 0
                                          //  Referenced by: '<S241>/ZeroGain'

  real_T ZeroGain_Gain_i;              // Expression: 0
                                          //  Referenced by: '<S291>/ZeroGain'

  real_T ZeroGain_Gain_jm;             // Expression: 0
                                          //  Referenced by: '<S341>/ZeroGain'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S86>/Memory'

  boolean_T Memory_InitialCondition_p;
                                // Computed Parameter: Memory_InitialCondition_p
                                   //  Referenced by: '<S36>/Memory'

  boolean_T Memory_InitialCondition_g;
                                // Computed Parameter: Memory_InitialCondition_g
                                   //  Referenced by: '<S138>/Memory'

  boolean_T Memory_InitialCondition_d;
                                // Computed Parameter: Memory_InitialCondition_d
                                   //  Referenced by: '<S188>/Memory'

  boolean_T Memory_InitialCondition_gk;
                               // Computed Parameter: Memory_InitialCondition_gk
                                  //  Referenced by: '<S241>/Memory'

  boolean_T Memory_InitialCondition_c;
                                // Computed Parameter: Memory_InitialCondition_c
                                   //  Referenced by: '<S291>/Memory'

  boolean_T Memory_InitialCondition_ps;
                               // Computed Parameter: Memory_InitialCondition_ps
                                  //  Referenced by: '<S341>/Memory'

};

// Real-time Model Data Structure
struct tag_RTM_ghost_mode_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ghost_mode_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[14];
  real_T odeF[3][14];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ghost_mode_T ghost_mode_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_ghost_mode_T ghost_mode_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_ghost_mode_T ghost_mode_X;

// Block states (default storage)
extern struct DW_ghost_mode_T ghost_mode_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ghost_mode_initialize(void);
  extern void ghost_mode_step(void);
  extern void ghost_mode_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ghost_mode_T *const ghost_mode_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Switch' : Unused code path elimination
//  Block '<S4>/Switch' : Unused code path elimination
//  Block '<S357>/Saturation' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ghost_mode'
//  '<S1>'   : 'ghost_mode/Blank Message'
//  '<S2>'   : 'ghost_mode/Controller1'
//  '<S3>'   : 'ghost_mode/Controller2'
//  '<S4>'   : 'ghost_mode/HybridController'
//  '<S5>'   : 'ghost_mode/PID JMS 0628'
//  '<S6>'   : 'ghost_mode/Publish'
//  '<S7>'   : 'ghost_mode/Subscribe'
//  '<S8>'   : 'ghost_mode/Subscribe1'
//  '<S9>'   : 'ghost_mode/Subscribe2'
//  '<S10>'  : 'ghost_mode/Controller1/PID JMS 0628'
//  '<S11>'  : 'ghost_mode/Controller1/PID JMS 1'
//  '<S12>'  : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup'
//  '<S13>'  : 'ghost_mode/Controller1/PID JMS 0628/D Gain'
//  '<S14>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter'
//  '<S15>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter ICs'
//  '<S16>'  : 'ghost_mode/Controller1/PID JMS 0628/I Gain'
//  '<S17>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain'
//  '<S18>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain Fdbk'
//  '<S19>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator'
//  '<S20>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator ICs'
//  '<S21>'  : 'ghost_mode/Controller1/PID JMS 0628/N Copy'
//  '<S22>'  : 'ghost_mode/Controller1/PID JMS 0628/N Gain'
//  '<S23>'  : 'ghost_mode/Controller1/PID JMS 0628/P Copy'
//  '<S24>'  : 'ghost_mode/Controller1/PID JMS 0628/Parallel P Gain'
//  '<S25>'  : 'ghost_mode/Controller1/PID JMS 0628/Reset Signal'
//  '<S26>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation'
//  '<S27>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation Fdbk'
//  '<S28>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum'
//  '<S29>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum Fdbk'
//  '<S30>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode'
//  '<S31>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode Sum'
//  '<S32>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Integral'
//  '<S33>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Ngain'
//  '<S34>'  : 'ghost_mode/Controller1/PID JMS 0628/postSat Signal'
//  '<S35>'  : 'ghost_mode/Controller1/PID JMS 0628/preSat Signal'
//  '<S36>'  : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup/Cont. Clamping Parallel'
//  '<S37>'  : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S38>'  : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S39>'  : 'ghost_mode/Controller1/PID JMS 0628/D Gain/Internal Parameters'
//  '<S40>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter/Cont. Filter'
//  '<S41>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter ICs/Internal IC - Filter'
//  '<S42>'  : 'ghost_mode/Controller1/PID JMS 0628/I Gain/Internal Parameters'
//  '<S43>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain/Passthrough'
//  '<S44>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain Fdbk/Disabled'
//  '<S45>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator/Continuous'
//  '<S46>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator ICs/Internal IC'
//  '<S47>'  : 'ghost_mode/Controller1/PID JMS 0628/N Copy/Disabled'
//  '<S48>'  : 'ghost_mode/Controller1/PID JMS 0628/N Gain/Internal Parameters'
//  '<S49>'  : 'ghost_mode/Controller1/PID JMS 0628/P Copy/Disabled'
//  '<S50>'  : 'ghost_mode/Controller1/PID JMS 0628/Parallel P Gain/Internal Parameters'
//  '<S51>'  : 'ghost_mode/Controller1/PID JMS 0628/Reset Signal/Disabled'
//  '<S52>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation/Enabled'
//  '<S53>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation Fdbk/Disabled'
//  '<S54>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum/Sum_PID'
//  '<S55>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum Fdbk/Disabled'
//  '<S56>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode/Enabled'
//  '<S57>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode Sum/Tracking Mode'
//  '<S58>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Integral/Passthrough'
//  '<S59>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Ngain/Passthrough'
//  '<S60>'  : 'ghost_mode/Controller1/PID JMS 0628/postSat Signal/Forward_Path'
//  '<S61>'  : 'ghost_mode/Controller1/PID JMS 0628/preSat Signal/Forward_Path'
//  '<S62>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup'
//  '<S63>'  : 'ghost_mode/Controller1/PID JMS 1/D Gain'
//  '<S64>'  : 'ghost_mode/Controller1/PID JMS 1/Filter'
//  '<S65>'  : 'ghost_mode/Controller1/PID JMS 1/Filter ICs'
//  '<S66>'  : 'ghost_mode/Controller1/PID JMS 1/I Gain'
//  '<S67>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain'
//  '<S68>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain Fdbk'
//  '<S69>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator'
//  '<S70>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator ICs'
//  '<S71>'  : 'ghost_mode/Controller1/PID JMS 1/N Copy'
//  '<S72>'  : 'ghost_mode/Controller1/PID JMS 1/N Gain'
//  '<S73>'  : 'ghost_mode/Controller1/PID JMS 1/P Copy'
//  '<S74>'  : 'ghost_mode/Controller1/PID JMS 1/Parallel P Gain'
//  '<S75>'  : 'ghost_mode/Controller1/PID JMS 1/Reset Signal'
//  '<S76>'  : 'ghost_mode/Controller1/PID JMS 1/Saturation'
//  '<S77>'  : 'ghost_mode/Controller1/PID JMS 1/Saturation Fdbk'
//  '<S78>'  : 'ghost_mode/Controller1/PID JMS 1/Sum'
//  '<S79>'  : 'ghost_mode/Controller1/PID JMS 1/Sum Fdbk'
//  '<S80>'  : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode'
//  '<S81>'  : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode Sum'
//  '<S82>'  : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Integral'
//  '<S83>'  : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Ngain'
//  '<S84>'  : 'ghost_mode/Controller1/PID JMS 1/postSat Signal'
//  '<S85>'  : 'ghost_mode/Controller1/PID JMS 1/preSat Signal'
//  '<S86>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup/Cont. Clamping Parallel'
//  '<S87>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S88>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S89>'  : 'ghost_mode/Controller1/PID JMS 1/D Gain/Internal Parameters'
//  '<S90>'  : 'ghost_mode/Controller1/PID JMS 1/Filter/Cont. Filter'
//  '<S91>'  : 'ghost_mode/Controller1/PID JMS 1/Filter ICs/Internal IC - Filter'
//  '<S92>'  : 'ghost_mode/Controller1/PID JMS 1/I Gain/Internal Parameters'
//  '<S93>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain/Passthrough'
//  '<S94>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain Fdbk/Disabled'
//  '<S95>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator/Continuous'
//  '<S96>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator ICs/Internal IC'
//  '<S97>'  : 'ghost_mode/Controller1/PID JMS 1/N Copy/Disabled'
//  '<S98>'  : 'ghost_mode/Controller1/PID JMS 1/N Gain/Internal Parameters'
//  '<S99>'  : 'ghost_mode/Controller1/PID JMS 1/P Copy/Disabled'
//  '<S100>' : 'ghost_mode/Controller1/PID JMS 1/Parallel P Gain/Internal Parameters'
//  '<S101>' : 'ghost_mode/Controller1/PID JMS 1/Reset Signal/Disabled'
//  '<S102>' : 'ghost_mode/Controller1/PID JMS 1/Saturation/Enabled'
//  '<S103>' : 'ghost_mode/Controller1/PID JMS 1/Saturation Fdbk/Disabled'
//  '<S104>' : 'ghost_mode/Controller1/PID JMS 1/Sum/Sum_PID'
//  '<S105>' : 'ghost_mode/Controller1/PID JMS 1/Sum Fdbk/Disabled'
//  '<S106>' : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode/Enabled'
//  '<S107>' : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode Sum/Tracking Mode'
//  '<S108>' : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Integral/Passthrough'
//  '<S109>' : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Ngain/Passthrough'
//  '<S110>' : 'ghost_mode/Controller1/PID JMS 1/postSat Signal/Forward_Path'
//  '<S111>' : 'ghost_mode/Controller1/PID JMS 1/preSat Signal/Forward_Path'
//  '<S112>' : 'ghost_mode/Controller2/PID JMS 0628'
//  '<S113>' : 'ghost_mode/Controller2/PID JMS 1'
//  '<S114>' : 'ghost_mode/Controller2/PID JMS 0628/Anti-windup'
//  '<S115>' : 'ghost_mode/Controller2/PID JMS 0628/D Gain'
//  '<S116>' : 'ghost_mode/Controller2/PID JMS 0628/Filter'
//  '<S117>' : 'ghost_mode/Controller2/PID JMS 0628/Filter ICs'
//  '<S118>' : 'ghost_mode/Controller2/PID JMS 0628/I Gain'
//  '<S119>' : 'ghost_mode/Controller2/PID JMS 0628/Ideal P Gain'
//  '<S120>' : 'ghost_mode/Controller2/PID JMS 0628/Ideal P Gain Fdbk'
//  '<S121>' : 'ghost_mode/Controller2/PID JMS 0628/Integrator'
//  '<S122>' : 'ghost_mode/Controller2/PID JMS 0628/Integrator ICs'
//  '<S123>' : 'ghost_mode/Controller2/PID JMS 0628/N Copy'
//  '<S124>' : 'ghost_mode/Controller2/PID JMS 0628/N Gain'
//  '<S125>' : 'ghost_mode/Controller2/PID JMS 0628/P Copy'
//  '<S126>' : 'ghost_mode/Controller2/PID JMS 0628/Parallel P Gain'
//  '<S127>' : 'ghost_mode/Controller2/PID JMS 0628/Reset Signal'
//  '<S128>' : 'ghost_mode/Controller2/PID JMS 0628/Saturation'
//  '<S129>' : 'ghost_mode/Controller2/PID JMS 0628/Saturation Fdbk'
//  '<S130>' : 'ghost_mode/Controller2/PID JMS 0628/Sum'
//  '<S131>' : 'ghost_mode/Controller2/PID JMS 0628/Sum Fdbk'
//  '<S132>' : 'ghost_mode/Controller2/PID JMS 0628/Tracking Mode'
//  '<S133>' : 'ghost_mode/Controller2/PID JMS 0628/Tracking Mode Sum'
//  '<S134>' : 'ghost_mode/Controller2/PID JMS 0628/Tsamp - Integral'
//  '<S135>' : 'ghost_mode/Controller2/PID JMS 0628/Tsamp - Ngain'
//  '<S136>' : 'ghost_mode/Controller2/PID JMS 0628/postSat Signal'
//  '<S137>' : 'ghost_mode/Controller2/PID JMS 0628/preSat Signal'
//  '<S138>' : 'ghost_mode/Controller2/PID JMS 0628/Anti-windup/Cont. Clamping Parallel'
//  '<S139>' : 'ghost_mode/Controller2/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S140>' : 'ghost_mode/Controller2/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S141>' : 'ghost_mode/Controller2/PID JMS 0628/D Gain/Internal Parameters'
//  '<S142>' : 'ghost_mode/Controller2/PID JMS 0628/Filter/Cont. Filter'
//  '<S143>' : 'ghost_mode/Controller2/PID JMS 0628/Filter ICs/Internal IC - Filter'
//  '<S144>' : 'ghost_mode/Controller2/PID JMS 0628/I Gain/Internal Parameters'
//  '<S145>' : 'ghost_mode/Controller2/PID JMS 0628/Ideal P Gain/Passthrough'
//  '<S146>' : 'ghost_mode/Controller2/PID JMS 0628/Ideal P Gain Fdbk/Disabled'
//  '<S147>' : 'ghost_mode/Controller2/PID JMS 0628/Integrator/Continuous'
//  '<S148>' : 'ghost_mode/Controller2/PID JMS 0628/Integrator ICs/Internal IC'
//  '<S149>' : 'ghost_mode/Controller2/PID JMS 0628/N Copy/Disabled'
//  '<S150>' : 'ghost_mode/Controller2/PID JMS 0628/N Gain/Internal Parameters'
//  '<S151>' : 'ghost_mode/Controller2/PID JMS 0628/P Copy/Disabled'
//  '<S152>' : 'ghost_mode/Controller2/PID JMS 0628/Parallel P Gain/Internal Parameters'
//  '<S153>' : 'ghost_mode/Controller2/PID JMS 0628/Reset Signal/Disabled'
//  '<S154>' : 'ghost_mode/Controller2/PID JMS 0628/Saturation/Enabled'
//  '<S155>' : 'ghost_mode/Controller2/PID JMS 0628/Saturation Fdbk/Disabled'
//  '<S156>' : 'ghost_mode/Controller2/PID JMS 0628/Sum/Sum_PID'
//  '<S157>' : 'ghost_mode/Controller2/PID JMS 0628/Sum Fdbk/Disabled'
//  '<S158>' : 'ghost_mode/Controller2/PID JMS 0628/Tracking Mode/Enabled'
//  '<S159>' : 'ghost_mode/Controller2/PID JMS 0628/Tracking Mode Sum/Tracking Mode'
//  '<S160>' : 'ghost_mode/Controller2/PID JMS 0628/Tsamp - Integral/Passthrough'
//  '<S161>' : 'ghost_mode/Controller2/PID JMS 0628/Tsamp - Ngain/Passthrough'
//  '<S162>' : 'ghost_mode/Controller2/PID JMS 0628/postSat Signal/Forward_Path'
//  '<S163>' : 'ghost_mode/Controller2/PID JMS 0628/preSat Signal/Forward_Path'
//  '<S164>' : 'ghost_mode/Controller2/PID JMS 1/Anti-windup'
//  '<S165>' : 'ghost_mode/Controller2/PID JMS 1/D Gain'
//  '<S166>' : 'ghost_mode/Controller2/PID JMS 1/Filter'
//  '<S167>' : 'ghost_mode/Controller2/PID JMS 1/Filter ICs'
//  '<S168>' : 'ghost_mode/Controller2/PID JMS 1/I Gain'
//  '<S169>' : 'ghost_mode/Controller2/PID JMS 1/Ideal P Gain'
//  '<S170>' : 'ghost_mode/Controller2/PID JMS 1/Ideal P Gain Fdbk'
//  '<S171>' : 'ghost_mode/Controller2/PID JMS 1/Integrator'
//  '<S172>' : 'ghost_mode/Controller2/PID JMS 1/Integrator ICs'
//  '<S173>' : 'ghost_mode/Controller2/PID JMS 1/N Copy'
//  '<S174>' : 'ghost_mode/Controller2/PID JMS 1/N Gain'
//  '<S175>' : 'ghost_mode/Controller2/PID JMS 1/P Copy'
//  '<S176>' : 'ghost_mode/Controller2/PID JMS 1/Parallel P Gain'
//  '<S177>' : 'ghost_mode/Controller2/PID JMS 1/Reset Signal'
//  '<S178>' : 'ghost_mode/Controller2/PID JMS 1/Saturation'
//  '<S179>' : 'ghost_mode/Controller2/PID JMS 1/Saturation Fdbk'
//  '<S180>' : 'ghost_mode/Controller2/PID JMS 1/Sum'
//  '<S181>' : 'ghost_mode/Controller2/PID JMS 1/Sum Fdbk'
//  '<S182>' : 'ghost_mode/Controller2/PID JMS 1/Tracking Mode'
//  '<S183>' : 'ghost_mode/Controller2/PID JMS 1/Tracking Mode Sum'
//  '<S184>' : 'ghost_mode/Controller2/PID JMS 1/Tsamp - Integral'
//  '<S185>' : 'ghost_mode/Controller2/PID JMS 1/Tsamp - Ngain'
//  '<S186>' : 'ghost_mode/Controller2/PID JMS 1/postSat Signal'
//  '<S187>' : 'ghost_mode/Controller2/PID JMS 1/preSat Signal'
//  '<S188>' : 'ghost_mode/Controller2/PID JMS 1/Anti-windup/Cont. Clamping Parallel'
//  '<S189>' : 'ghost_mode/Controller2/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S190>' : 'ghost_mode/Controller2/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S191>' : 'ghost_mode/Controller2/PID JMS 1/D Gain/Internal Parameters'
//  '<S192>' : 'ghost_mode/Controller2/PID JMS 1/Filter/Cont. Filter'
//  '<S193>' : 'ghost_mode/Controller2/PID JMS 1/Filter ICs/Internal IC - Filter'
//  '<S194>' : 'ghost_mode/Controller2/PID JMS 1/I Gain/Internal Parameters'
//  '<S195>' : 'ghost_mode/Controller2/PID JMS 1/Ideal P Gain/Passthrough'
//  '<S196>' : 'ghost_mode/Controller2/PID JMS 1/Ideal P Gain Fdbk/Disabled'
//  '<S197>' : 'ghost_mode/Controller2/PID JMS 1/Integrator/Continuous'
//  '<S198>' : 'ghost_mode/Controller2/PID JMS 1/Integrator ICs/Internal IC'
//  '<S199>' : 'ghost_mode/Controller2/PID JMS 1/N Copy/Disabled'
//  '<S200>' : 'ghost_mode/Controller2/PID JMS 1/N Gain/Internal Parameters'
//  '<S201>' : 'ghost_mode/Controller2/PID JMS 1/P Copy/Disabled'
//  '<S202>' : 'ghost_mode/Controller2/PID JMS 1/Parallel P Gain/Internal Parameters'
//  '<S203>' : 'ghost_mode/Controller2/PID JMS 1/Reset Signal/Disabled'
//  '<S204>' : 'ghost_mode/Controller2/PID JMS 1/Saturation/Enabled'
//  '<S205>' : 'ghost_mode/Controller2/PID JMS 1/Saturation Fdbk/Disabled'
//  '<S206>' : 'ghost_mode/Controller2/PID JMS 1/Sum/Sum_PID'
//  '<S207>' : 'ghost_mode/Controller2/PID JMS 1/Sum Fdbk/Disabled'
//  '<S208>' : 'ghost_mode/Controller2/PID JMS 1/Tracking Mode/Enabled'
//  '<S209>' : 'ghost_mode/Controller2/PID JMS 1/Tracking Mode Sum/Tracking Mode'
//  '<S210>' : 'ghost_mode/Controller2/PID JMS 1/Tsamp - Integral/Passthrough'
//  '<S211>' : 'ghost_mode/Controller2/PID JMS 1/Tsamp - Ngain/Passthrough'
//  '<S212>' : 'ghost_mode/Controller2/PID JMS 1/postSat Signal/Forward_Path'
//  '<S213>' : 'ghost_mode/Controller2/PID JMS 1/preSat Signal/Forward_Path'
//  '<S214>' : 'ghost_mode/HybridController/Chart'
//  '<S215>' : 'ghost_mode/HybridController/PID JMS 0628'
//  '<S216>' : 'ghost_mode/HybridController/PID JMS 1'
//  '<S217>' : 'ghost_mode/HybridController/PID JMS 0628/Anti-windup'
//  '<S218>' : 'ghost_mode/HybridController/PID JMS 0628/D Gain'
//  '<S219>' : 'ghost_mode/HybridController/PID JMS 0628/Filter'
//  '<S220>' : 'ghost_mode/HybridController/PID JMS 0628/Filter ICs'
//  '<S221>' : 'ghost_mode/HybridController/PID JMS 0628/I Gain'
//  '<S222>' : 'ghost_mode/HybridController/PID JMS 0628/Ideal P Gain'
//  '<S223>' : 'ghost_mode/HybridController/PID JMS 0628/Ideal P Gain Fdbk'
//  '<S224>' : 'ghost_mode/HybridController/PID JMS 0628/Integrator'
//  '<S225>' : 'ghost_mode/HybridController/PID JMS 0628/Integrator ICs'
//  '<S226>' : 'ghost_mode/HybridController/PID JMS 0628/N Copy'
//  '<S227>' : 'ghost_mode/HybridController/PID JMS 0628/N Gain'
//  '<S228>' : 'ghost_mode/HybridController/PID JMS 0628/P Copy'
//  '<S229>' : 'ghost_mode/HybridController/PID JMS 0628/Parallel P Gain'
//  '<S230>' : 'ghost_mode/HybridController/PID JMS 0628/Reset Signal'
//  '<S231>' : 'ghost_mode/HybridController/PID JMS 0628/Saturation'
//  '<S232>' : 'ghost_mode/HybridController/PID JMS 0628/Saturation Fdbk'
//  '<S233>' : 'ghost_mode/HybridController/PID JMS 0628/Sum'
//  '<S234>' : 'ghost_mode/HybridController/PID JMS 0628/Sum Fdbk'
//  '<S235>' : 'ghost_mode/HybridController/PID JMS 0628/Tracking Mode'
//  '<S236>' : 'ghost_mode/HybridController/PID JMS 0628/Tracking Mode Sum'
//  '<S237>' : 'ghost_mode/HybridController/PID JMS 0628/Tsamp - Integral'
//  '<S238>' : 'ghost_mode/HybridController/PID JMS 0628/Tsamp - Ngain'
//  '<S239>' : 'ghost_mode/HybridController/PID JMS 0628/postSat Signal'
//  '<S240>' : 'ghost_mode/HybridController/PID JMS 0628/preSat Signal'
//  '<S241>' : 'ghost_mode/HybridController/PID JMS 0628/Anti-windup/Cont. Clamping Parallel'
//  '<S242>' : 'ghost_mode/HybridController/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S243>' : 'ghost_mode/HybridController/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S244>' : 'ghost_mode/HybridController/PID JMS 0628/D Gain/Internal Parameters'
//  '<S245>' : 'ghost_mode/HybridController/PID JMS 0628/Filter/Cont. Filter'
//  '<S246>' : 'ghost_mode/HybridController/PID JMS 0628/Filter ICs/Internal IC - Filter'
//  '<S247>' : 'ghost_mode/HybridController/PID JMS 0628/I Gain/Internal Parameters'
//  '<S248>' : 'ghost_mode/HybridController/PID JMS 0628/Ideal P Gain/Passthrough'
//  '<S249>' : 'ghost_mode/HybridController/PID JMS 0628/Ideal P Gain Fdbk/Disabled'
//  '<S250>' : 'ghost_mode/HybridController/PID JMS 0628/Integrator/Continuous'
//  '<S251>' : 'ghost_mode/HybridController/PID JMS 0628/Integrator ICs/Internal IC'
//  '<S252>' : 'ghost_mode/HybridController/PID JMS 0628/N Copy/Disabled'
//  '<S253>' : 'ghost_mode/HybridController/PID JMS 0628/N Gain/Internal Parameters'
//  '<S254>' : 'ghost_mode/HybridController/PID JMS 0628/P Copy/Disabled'
//  '<S255>' : 'ghost_mode/HybridController/PID JMS 0628/Parallel P Gain/Internal Parameters'
//  '<S256>' : 'ghost_mode/HybridController/PID JMS 0628/Reset Signal/Disabled'
//  '<S257>' : 'ghost_mode/HybridController/PID JMS 0628/Saturation/Enabled'
//  '<S258>' : 'ghost_mode/HybridController/PID JMS 0628/Saturation Fdbk/Disabled'
//  '<S259>' : 'ghost_mode/HybridController/PID JMS 0628/Sum/Sum_PID'
//  '<S260>' : 'ghost_mode/HybridController/PID JMS 0628/Sum Fdbk/Disabled'
//  '<S261>' : 'ghost_mode/HybridController/PID JMS 0628/Tracking Mode/Enabled'
//  '<S262>' : 'ghost_mode/HybridController/PID JMS 0628/Tracking Mode Sum/Tracking Mode'
//  '<S263>' : 'ghost_mode/HybridController/PID JMS 0628/Tsamp - Integral/Passthrough'
//  '<S264>' : 'ghost_mode/HybridController/PID JMS 0628/Tsamp - Ngain/Passthrough'
//  '<S265>' : 'ghost_mode/HybridController/PID JMS 0628/postSat Signal/Forward_Path'
//  '<S266>' : 'ghost_mode/HybridController/PID JMS 0628/preSat Signal/Forward_Path'
//  '<S267>' : 'ghost_mode/HybridController/PID JMS 1/Anti-windup'
//  '<S268>' : 'ghost_mode/HybridController/PID JMS 1/D Gain'
//  '<S269>' : 'ghost_mode/HybridController/PID JMS 1/Filter'
//  '<S270>' : 'ghost_mode/HybridController/PID JMS 1/Filter ICs'
//  '<S271>' : 'ghost_mode/HybridController/PID JMS 1/I Gain'
//  '<S272>' : 'ghost_mode/HybridController/PID JMS 1/Ideal P Gain'
//  '<S273>' : 'ghost_mode/HybridController/PID JMS 1/Ideal P Gain Fdbk'
//  '<S274>' : 'ghost_mode/HybridController/PID JMS 1/Integrator'
//  '<S275>' : 'ghost_mode/HybridController/PID JMS 1/Integrator ICs'
//  '<S276>' : 'ghost_mode/HybridController/PID JMS 1/N Copy'
//  '<S277>' : 'ghost_mode/HybridController/PID JMS 1/N Gain'
//  '<S278>' : 'ghost_mode/HybridController/PID JMS 1/P Copy'
//  '<S279>' : 'ghost_mode/HybridController/PID JMS 1/Parallel P Gain'
//  '<S280>' : 'ghost_mode/HybridController/PID JMS 1/Reset Signal'
//  '<S281>' : 'ghost_mode/HybridController/PID JMS 1/Saturation'
//  '<S282>' : 'ghost_mode/HybridController/PID JMS 1/Saturation Fdbk'
//  '<S283>' : 'ghost_mode/HybridController/PID JMS 1/Sum'
//  '<S284>' : 'ghost_mode/HybridController/PID JMS 1/Sum Fdbk'
//  '<S285>' : 'ghost_mode/HybridController/PID JMS 1/Tracking Mode'
//  '<S286>' : 'ghost_mode/HybridController/PID JMS 1/Tracking Mode Sum'
//  '<S287>' : 'ghost_mode/HybridController/PID JMS 1/Tsamp - Integral'
//  '<S288>' : 'ghost_mode/HybridController/PID JMS 1/Tsamp - Ngain'
//  '<S289>' : 'ghost_mode/HybridController/PID JMS 1/postSat Signal'
//  '<S290>' : 'ghost_mode/HybridController/PID JMS 1/preSat Signal'
//  '<S291>' : 'ghost_mode/HybridController/PID JMS 1/Anti-windup/Cont. Clamping Parallel'
//  '<S292>' : 'ghost_mode/HybridController/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S293>' : 'ghost_mode/HybridController/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S294>' : 'ghost_mode/HybridController/PID JMS 1/D Gain/Internal Parameters'
//  '<S295>' : 'ghost_mode/HybridController/PID JMS 1/Filter/Cont. Filter'
//  '<S296>' : 'ghost_mode/HybridController/PID JMS 1/Filter ICs/Internal IC - Filter'
//  '<S297>' : 'ghost_mode/HybridController/PID JMS 1/I Gain/Internal Parameters'
//  '<S298>' : 'ghost_mode/HybridController/PID JMS 1/Ideal P Gain/Passthrough'
//  '<S299>' : 'ghost_mode/HybridController/PID JMS 1/Ideal P Gain Fdbk/Disabled'
//  '<S300>' : 'ghost_mode/HybridController/PID JMS 1/Integrator/Continuous'
//  '<S301>' : 'ghost_mode/HybridController/PID JMS 1/Integrator ICs/Internal IC'
//  '<S302>' : 'ghost_mode/HybridController/PID JMS 1/N Copy/Disabled'
//  '<S303>' : 'ghost_mode/HybridController/PID JMS 1/N Gain/Internal Parameters'
//  '<S304>' : 'ghost_mode/HybridController/PID JMS 1/P Copy/Disabled'
//  '<S305>' : 'ghost_mode/HybridController/PID JMS 1/Parallel P Gain/Internal Parameters'
//  '<S306>' : 'ghost_mode/HybridController/PID JMS 1/Reset Signal/Disabled'
//  '<S307>' : 'ghost_mode/HybridController/PID JMS 1/Saturation/Enabled'
//  '<S308>' : 'ghost_mode/HybridController/PID JMS 1/Saturation Fdbk/Disabled'
//  '<S309>' : 'ghost_mode/HybridController/PID JMS 1/Sum/Sum_PID'
//  '<S310>' : 'ghost_mode/HybridController/PID JMS 1/Sum Fdbk/Disabled'
//  '<S311>' : 'ghost_mode/HybridController/PID JMS 1/Tracking Mode/Enabled'
//  '<S312>' : 'ghost_mode/HybridController/PID JMS 1/Tracking Mode Sum/Tracking Mode'
//  '<S313>' : 'ghost_mode/HybridController/PID JMS 1/Tsamp - Integral/Passthrough'
//  '<S314>' : 'ghost_mode/HybridController/PID JMS 1/Tsamp - Ngain/Passthrough'
//  '<S315>' : 'ghost_mode/HybridController/PID JMS 1/postSat Signal/Forward_Path'
//  '<S316>' : 'ghost_mode/HybridController/PID JMS 1/preSat Signal/Forward_Path'
//  '<S317>' : 'ghost_mode/PID JMS 0628/Anti-windup'
//  '<S318>' : 'ghost_mode/PID JMS 0628/D Gain'
//  '<S319>' : 'ghost_mode/PID JMS 0628/Filter'
//  '<S320>' : 'ghost_mode/PID JMS 0628/Filter ICs'
//  '<S321>' : 'ghost_mode/PID JMS 0628/I Gain'
//  '<S322>' : 'ghost_mode/PID JMS 0628/Ideal P Gain'
//  '<S323>' : 'ghost_mode/PID JMS 0628/Ideal P Gain Fdbk'
//  '<S324>' : 'ghost_mode/PID JMS 0628/Integrator'
//  '<S325>' : 'ghost_mode/PID JMS 0628/Integrator ICs'
//  '<S326>' : 'ghost_mode/PID JMS 0628/N Copy'
//  '<S327>' : 'ghost_mode/PID JMS 0628/N Gain'
//  '<S328>' : 'ghost_mode/PID JMS 0628/P Copy'
//  '<S329>' : 'ghost_mode/PID JMS 0628/Parallel P Gain'
//  '<S330>' : 'ghost_mode/PID JMS 0628/Reset Signal'
//  '<S331>' : 'ghost_mode/PID JMS 0628/Saturation'
//  '<S332>' : 'ghost_mode/PID JMS 0628/Saturation Fdbk'
//  '<S333>' : 'ghost_mode/PID JMS 0628/Sum'
//  '<S334>' : 'ghost_mode/PID JMS 0628/Sum Fdbk'
//  '<S335>' : 'ghost_mode/PID JMS 0628/Tracking Mode'
//  '<S336>' : 'ghost_mode/PID JMS 0628/Tracking Mode Sum'
//  '<S337>' : 'ghost_mode/PID JMS 0628/Tsamp - Integral'
//  '<S338>' : 'ghost_mode/PID JMS 0628/Tsamp - Ngain'
//  '<S339>' : 'ghost_mode/PID JMS 0628/postSat Signal'
//  '<S340>' : 'ghost_mode/PID JMS 0628/preSat Signal'
//  '<S341>' : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel'
//  '<S342>' : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S343>' : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S344>' : 'ghost_mode/PID JMS 0628/D Gain/Internal Parameters'
//  '<S345>' : 'ghost_mode/PID JMS 0628/Filter/Cont. Filter'
//  '<S346>' : 'ghost_mode/PID JMS 0628/Filter ICs/Internal IC - Filter'
//  '<S347>' : 'ghost_mode/PID JMS 0628/I Gain/Internal Parameters'
//  '<S348>' : 'ghost_mode/PID JMS 0628/Ideal P Gain/Passthrough'
//  '<S349>' : 'ghost_mode/PID JMS 0628/Ideal P Gain Fdbk/Disabled'
//  '<S350>' : 'ghost_mode/PID JMS 0628/Integrator/Continuous'
//  '<S351>' : 'ghost_mode/PID JMS 0628/Integrator ICs/Internal IC'
//  '<S352>' : 'ghost_mode/PID JMS 0628/N Copy/Disabled'
//  '<S353>' : 'ghost_mode/PID JMS 0628/N Gain/Internal Parameters'
//  '<S354>' : 'ghost_mode/PID JMS 0628/P Copy/Disabled'
//  '<S355>' : 'ghost_mode/PID JMS 0628/Parallel P Gain/Internal Parameters'
//  '<S356>' : 'ghost_mode/PID JMS 0628/Reset Signal/Disabled'
//  '<S357>' : 'ghost_mode/PID JMS 0628/Saturation/Enabled'
//  '<S358>' : 'ghost_mode/PID JMS 0628/Saturation Fdbk/Disabled'
//  '<S359>' : 'ghost_mode/PID JMS 0628/Sum/Sum_PID'
//  '<S360>' : 'ghost_mode/PID JMS 0628/Sum Fdbk/Disabled'
//  '<S361>' : 'ghost_mode/PID JMS 0628/Tracking Mode/Disabled'
//  '<S362>' : 'ghost_mode/PID JMS 0628/Tracking Mode Sum/Passthrough'
//  '<S363>' : 'ghost_mode/PID JMS 0628/Tsamp - Integral/Passthrough'
//  '<S364>' : 'ghost_mode/PID JMS 0628/Tsamp - Ngain/Passthrough'
//  '<S365>' : 'ghost_mode/PID JMS 0628/postSat Signal/Forward_Path'
//  '<S366>' : 'ghost_mode/PID JMS 0628/preSat Signal/Forward_Path'
//  '<S367>' : 'ghost_mode/Subscribe/Enabled Subsystem'
//  '<S368>' : 'ghost_mode/Subscribe1/Enabled Subsystem'
//  '<S369>' : 'ghost_mode/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_ghost_mode_h_

//
// File trailer for generated code.
//
// [EOF]
//
