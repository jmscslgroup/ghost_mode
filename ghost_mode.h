//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.h
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.46
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Jun 30 11:54:40 2021
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
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1;// '<S109>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1_d;// '<S108>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped b_varargout_2;
  SL_Bus_ghost_mode_geometry_msgs_AccelStamped b_varargout_2_m;
  real_T ProportionalGain;             // '<S96>/Proportional Gain'
  real_T DerivativeGain;               // '<S85>/Derivative Gain'
  real_T FilterCoefficient;            // '<S94>/Filter Coefficient'
  real_T Switch;                       // '<S82>/Switch'
  real_T IntegralGain;                 // '<S38>/Integral Gain'
  real_T ProportionalGain_b;           // '<S46>/Proportional Gain'
  real_T DerivativeGain_d;             // '<S35>/Derivative Gain'
  real_T FilterCoefficient_i;          // '<S44>/Filter Coefficient'
  real_T Switch_g;                     // '<S32>/Switch'
  int8_T DataTypeConv2;                // '<S82>/DataTypeConv2'
  boolean_T AND3;                      // '<S82>/AND3'
  boolean_T Memory;                    // '<S32>/Memory'
  boolean_T AND3_m;                    // '<S32>/AND3'
};

// Block states (default storage) for system '<Root>'
struct DW_ghost_mode_T {
  ros_slroscpp_internal_block_P_T obj; // '<S4>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S6>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S5>/SourceBlock'
  boolean_T Memory_PreviousInput;      // '<S82>/Memory'
  boolean_T Memory_PreviousInput_n;    // '<S32>/Memory'
};

// Continuous states (default storage)
struct X_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S91>/Integrator'
  real_T Filter_CSTATE;                // '<S86>/Filter'
  real_T Integrator_CSTATE_c;          // '<S41>/Integrator'
  real_T Filter_CSTATE_h;              // '<S36>/Filter'
};

// State derivatives (default storage)
struct XDot_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S91>/Integrator'
  real_T Filter_CSTATE;                // '<S86>/Filter'
  real_T Integrator_CSTATE_c;          // '<S41>/Integrator'
  real_T Filter_CSTATE_h;              // '<S36>/Filter'
};

// State disabled
struct XDis_ghost_mode_T {
  boolean_T Integrator_CSTATE;         // '<S91>/Integrator'
  boolean_T Filter_CSTATE;             // '<S86>/Filter'
  boolean_T Integrator_CSTATE_c;       // '<S41>/Integrator'
  boolean_T Filter_CSTATE_h;           // '<S36>/Filter'
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
  real_T PIDJMS2_D;                    // Mask Parameter: PIDJMS2_D
                                          //  Referenced by: '<S85>/Derivative Gain'

  real_T PIDJMS1_D;                    // Mask Parameter: PIDJMS1_D
                                          //  Referenced by: '<S35>/Derivative Gain'

  real_T PIDJMS2_I;                    // Mask Parameter: PIDJMS2_I
                                          //  Referenced by: '<S88>/Integral Gain'

  real_T PIDJMS1_I;                    // Mask Parameter: PIDJMS1_I
                                          //  Referenced by: '<S38>/Integral Gain'

  real_T PIDJMS2_InitialConditionForFilt;
                              // Mask Parameter: PIDJMS2_InitialConditionForFilt
                                 //  Referenced by: '<S86>/Filter'

  real_T PIDJMS1_InitialConditionForFilt;
                              // Mask Parameter: PIDJMS1_InitialConditionForFilt
                                 //  Referenced by: '<S36>/Filter'

  real_T PIDJMS2_InitialConditionForInte;
                              // Mask Parameter: PIDJMS2_InitialConditionForInte
                                 //  Referenced by: '<S91>/Integrator'

  real_T PIDJMS1_InitialConditionForInte;
                              // Mask Parameter: PIDJMS1_InitialConditionForInte
                                 //  Referenced by: '<S41>/Integrator'

  real_T PIDJMS1_Kt;                   // Mask Parameter: PIDJMS1_Kt
                                          //  Referenced by: '<S52>/Kt'

  real_T PIDJMS2_LowerSaturationLimit;
                                 // Mask Parameter: PIDJMS2_LowerSaturationLimit
                                    //  Referenced by:
                                    //    '<S98>/Saturation'
                                    //    '<S84>/DeadZone'

  real_T PIDJMS1_LowerSaturationLimit;
                                 // Mask Parameter: PIDJMS1_LowerSaturationLimit
                                    //  Referenced by:
                                    //    '<S48>/Saturation'
                                    //    '<S34>/DeadZone'

  real_T PIDJMS2_N;                    // Mask Parameter: PIDJMS2_N
                                          //  Referenced by: '<S94>/Filter Coefficient'

  real_T PIDJMS1_N;                    // Mask Parameter: PIDJMS1_N
                                          //  Referenced by: '<S44>/Filter Coefficient'

  real_T PIDJMS2_P;                    // Mask Parameter: PIDJMS2_P
                                          //  Referenced by: '<S96>/Proportional Gain'

  real_T PIDJMS1_P;                    // Mask Parameter: PIDJMS1_P
                                          //  Referenced by: '<S46>/Proportional Gain'

  real_T PIDJMS2_UpperSaturationLimit;
                                 // Mask Parameter: PIDJMS2_UpperSaturationLimit
                                    //  Referenced by:
                                    //    '<S98>/Saturation'
                                    //    '<S84>/DeadZone'

  real_T PIDJMS1_UpperSaturationLimit;
                                 // Mask Parameter: PIDJMS1_UpperSaturationLimit
                                    //  Referenced by:
                                    //    '<S48>/Saturation'
                                    //    '<S34>/DeadZone'

  SL_Bus_ghost_mode_geometry_msgs_AccelStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S110>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_AccelStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S7>/Constant'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                            //  Referenced by: '<S108>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                                   //  Referenced by: '<S5>/Constant'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                            //  Referenced by: '<S109>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                   //  Referenced by: '<S6>/Constant'

  SL_Bus_ghost_mode_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                         //  Referenced by: '<S1>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S82>/Constant1'

  real_T Constant1_Value_h;            // Expression: 0
                                          //  Referenced by: '<S32>/Constant1'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S82>/ZeroGain'

  real_T ZeroGain_Gain_d;              // Expression: 0
                                          //  Referenced by: '<S32>/ZeroGain'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S82>/Memory'

  boolean_T Memory_InitialCondition_o;
                                // Computed Parameter: Memory_InitialCondition_o
                                   //  Referenced by: '<S32>/Memory'

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
  real_T odeY[4];
  real_T odeF[3][4];
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
//  '<S2>'   : 'ghost_mode/PID JMS 1'
//  '<S3>'   : 'ghost_mode/PID JMS 2'
//  '<S4>'   : 'ghost_mode/Publish'
//  '<S5>'   : 'ghost_mode/Subscribe'
//  '<S6>'   : 'ghost_mode/Subscribe1'
//  '<S7>'   : 'ghost_mode/Subscribe2'
//  '<S8>'   : 'ghost_mode/PID JMS 1/Anti-windup'
//  '<S9>'   : 'ghost_mode/PID JMS 1/D Gain'
//  '<S10>'  : 'ghost_mode/PID JMS 1/Filter'
//  '<S11>'  : 'ghost_mode/PID JMS 1/Filter ICs'
//  '<S12>'  : 'ghost_mode/PID JMS 1/I Gain'
//  '<S13>'  : 'ghost_mode/PID JMS 1/Ideal P Gain'
//  '<S14>'  : 'ghost_mode/PID JMS 1/Ideal P Gain Fdbk'
//  '<S15>'  : 'ghost_mode/PID JMS 1/Integrator'
//  '<S16>'  : 'ghost_mode/PID JMS 1/Integrator ICs'
//  '<S17>'  : 'ghost_mode/PID JMS 1/N Copy'
//  '<S18>'  : 'ghost_mode/PID JMS 1/N Gain'
//  '<S19>'  : 'ghost_mode/PID JMS 1/P Copy'
//  '<S20>'  : 'ghost_mode/PID JMS 1/Parallel P Gain'
//  '<S21>'  : 'ghost_mode/PID JMS 1/Reset Signal'
//  '<S22>'  : 'ghost_mode/PID JMS 1/Saturation'
//  '<S23>'  : 'ghost_mode/PID JMS 1/Saturation Fdbk'
//  '<S24>'  : 'ghost_mode/PID JMS 1/Sum'
//  '<S25>'  : 'ghost_mode/PID JMS 1/Sum Fdbk'
//  '<S26>'  : 'ghost_mode/PID JMS 1/Tracking Mode'
//  '<S27>'  : 'ghost_mode/PID JMS 1/Tracking Mode Sum'
//  '<S28>'  : 'ghost_mode/PID JMS 1/Tsamp - Integral'
//  '<S29>'  : 'ghost_mode/PID JMS 1/Tsamp - Ngain'
//  '<S30>'  : 'ghost_mode/PID JMS 1/postSat Signal'
//  '<S31>'  : 'ghost_mode/PID JMS 1/preSat Signal'
//  '<S32>'  : 'ghost_mode/PID JMS 1/Anti-windup/Cont. Clamping Parallel'
//  '<S33>'  : 'ghost_mode/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S34>'  : 'ghost_mode/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S35>'  : 'ghost_mode/PID JMS 1/D Gain/Internal Parameters'
//  '<S36>'  : 'ghost_mode/PID JMS 1/Filter/Cont. Filter'
//  '<S37>'  : 'ghost_mode/PID JMS 1/Filter ICs/Internal IC - Filter'
//  '<S38>'  : 'ghost_mode/PID JMS 1/I Gain/Internal Parameters'
//  '<S39>'  : 'ghost_mode/PID JMS 1/Ideal P Gain/Passthrough'
//  '<S40>'  : 'ghost_mode/PID JMS 1/Ideal P Gain Fdbk/Disabled'
//  '<S41>'  : 'ghost_mode/PID JMS 1/Integrator/Continuous'
//  '<S42>'  : 'ghost_mode/PID JMS 1/Integrator ICs/Internal IC'
//  '<S43>'  : 'ghost_mode/PID JMS 1/N Copy/Disabled'
//  '<S44>'  : 'ghost_mode/PID JMS 1/N Gain/Internal Parameters'
//  '<S45>'  : 'ghost_mode/PID JMS 1/P Copy/Disabled'
//  '<S46>'  : 'ghost_mode/PID JMS 1/Parallel P Gain/Internal Parameters'
//  '<S47>'  : 'ghost_mode/PID JMS 1/Reset Signal/Disabled'
//  '<S48>'  : 'ghost_mode/PID JMS 1/Saturation/Enabled'
//  '<S49>'  : 'ghost_mode/PID JMS 1/Saturation Fdbk/Disabled'
//  '<S50>'  : 'ghost_mode/PID JMS 1/Sum/Sum_PID'
//  '<S51>'  : 'ghost_mode/PID JMS 1/Sum Fdbk/Disabled'
//  '<S52>'  : 'ghost_mode/PID JMS 1/Tracking Mode/Enabled'
//  '<S53>'  : 'ghost_mode/PID JMS 1/Tracking Mode Sum/Tracking Mode'
//  '<S54>'  : 'ghost_mode/PID JMS 1/Tsamp - Integral/Passthrough'
//  '<S55>'  : 'ghost_mode/PID JMS 1/Tsamp - Ngain/Passthrough'
//  '<S56>'  : 'ghost_mode/PID JMS 1/postSat Signal/Forward_Path'
//  '<S57>'  : 'ghost_mode/PID JMS 1/preSat Signal/Forward_Path'
//  '<S58>'  : 'ghost_mode/PID JMS 2/Anti-windup'
//  '<S59>'  : 'ghost_mode/PID JMS 2/D Gain'
//  '<S60>'  : 'ghost_mode/PID JMS 2/Filter'
//  '<S61>'  : 'ghost_mode/PID JMS 2/Filter ICs'
//  '<S62>'  : 'ghost_mode/PID JMS 2/I Gain'
//  '<S63>'  : 'ghost_mode/PID JMS 2/Ideal P Gain'
//  '<S64>'  : 'ghost_mode/PID JMS 2/Ideal P Gain Fdbk'
//  '<S65>'  : 'ghost_mode/PID JMS 2/Integrator'
//  '<S66>'  : 'ghost_mode/PID JMS 2/Integrator ICs'
//  '<S67>'  : 'ghost_mode/PID JMS 2/N Copy'
//  '<S68>'  : 'ghost_mode/PID JMS 2/N Gain'
//  '<S69>'  : 'ghost_mode/PID JMS 2/P Copy'
//  '<S70>'  : 'ghost_mode/PID JMS 2/Parallel P Gain'
//  '<S71>'  : 'ghost_mode/PID JMS 2/Reset Signal'
//  '<S72>'  : 'ghost_mode/PID JMS 2/Saturation'
//  '<S73>'  : 'ghost_mode/PID JMS 2/Saturation Fdbk'
//  '<S74>'  : 'ghost_mode/PID JMS 2/Sum'
//  '<S75>'  : 'ghost_mode/PID JMS 2/Sum Fdbk'
//  '<S76>'  : 'ghost_mode/PID JMS 2/Tracking Mode'
//  '<S77>'  : 'ghost_mode/PID JMS 2/Tracking Mode Sum'
//  '<S78>'  : 'ghost_mode/PID JMS 2/Tsamp - Integral'
//  '<S79>'  : 'ghost_mode/PID JMS 2/Tsamp - Ngain'
//  '<S80>'  : 'ghost_mode/PID JMS 2/postSat Signal'
//  '<S81>'  : 'ghost_mode/PID JMS 2/preSat Signal'
//  '<S82>'  : 'ghost_mode/PID JMS 2/Anti-windup/Cont. Clamping Parallel'
//  '<S83>'  : 'ghost_mode/PID JMS 2/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S84>'  : 'ghost_mode/PID JMS 2/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S85>'  : 'ghost_mode/PID JMS 2/D Gain/Internal Parameters'
//  '<S86>'  : 'ghost_mode/PID JMS 2/Filter/Cont. Filter'
//  '<S87>'  : 'ghost_mode/PID JMS 2/Filter ICs/Internal IC - Filter'
//  '<S88>'  : 'ghost_mode/PID JMS 2/I Gain/Internal Parameters'
//  '<S89>'  : 'ghost_mode/PID JMS 2/Ideal P Gain/Passthrough'
//  '<S90>'  : 'ghost_mode/PID JMS 2/Ideal P Gain Fdbk/Disabled'
//  '<S91>'  : 'ghost_mode/PID JMS 2/Integrator/Continuous'
//  '<S92>'  : 'ghost_mode/PID JMS 2/Integrator ICs/Internal IC'
//  '<S93>'  : 'ghost_mode/PID JMS 2/N Copy/Disabled'
//  '<S94>'  : 'ghost_mode/PID JMS 2/N Gain/Internal Parameters'
//  '<S95>'  : 'ghost_mode/PID JMS 2/P Copy/Disabled'
//  '<S96>'  : 'ghost_mode/PID JMS 2/Parallel P Gain/Internal Parameters'
//  '<S97>'  : 'ghost_mode/PID JMS 2/Reset Signal/Disabled'
//  '<S98>'  : 'ghost_mode/PID JMS 2/Saturation/Enabled'
//  '<S99>'  : 'ghost_mode/PID JMS 2/Saturation Fdbk/Disabled'
//  '<S100>' : 'ghost_mode/PID JMS 2/Sum/Sum_PID'
//  '<S101>' : 'ghost_mode/PID JMS 2/Sum Fdbk/Disabled'
//  '<S102>' : 'ghost_mode/PID JMS 2/Tracking Mode/Disabled'
//  '<S103>' : 'ghost_mode/PID JMS 2/Tracking Mode Sum/Passthrough'
//  '<S104>' : 'ghost_mode/PID JMS 2/Tsamp - Integral/Passthrough'
//  '<S105>' : 'ghost_mode/PID JMS 2/Tsamp - Ngain/Passthrough'
//  '<S106>' : 'ghost_mode/PID JMS 2/postSat Signal/Forward_Path'
//  '<S107>' : 'ghost_mode/PID JMS 2/preSat Signal/Forward_Path'
//  '<S108>' : 'ghost_mode/Subscribe/Enabled Subsystem'
//  '<S109>' : 'ghost_mode/Subscribe1/Enabled Subsystem'
//  '<S110>' : 'ghost_mode/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_ghost_mode_h_

//
// File trailer for generated code.
//
// [EOF]
//
