//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.h
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.38
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 15:47:38 2021
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
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1;// '<S57>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1_d;// '<S56>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped b_varargout_2;
  real_T ProportionalGain;             // '<S44>/Proportional Gain'
  real_T DerivativeGain;               // '<S33>/Derivative Gain'
  real_T FilterCoefficient;            // '<S42>/Filter Coefficient'
  real_T Switch;                       // '<S30>/Switch'
  int8_T DataTypeConv2;                // '<S30>/DataTypeConv2'
  boolean_T AND3;                      // '<S30>/AND3'
};

// Block states (default storage) for system '<Root>'
struct DW_ghost_mode_T {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S5>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S4>/SourceBlock'
  boolean_T Memory_PreviousInput;      // '<S30>/Memory'
};

// Continuous states (default storage)
struct X_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S39>/Integrator'
  real_T Filter_CSTATE;                // '<S34>/Filter'
};

// State derivatives (default storage)
struct XDot_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S39>/Integrator'
  real_T Filter_CSTATE;                // '<S34>/Filter'
};

// State disabled
struct XDis_ghost_mode_T {
  boolean_T Integrator_CSTATE;         // '<S39>/Integrator'
  boolean_T Filter_CSTATE;             // '<S34>/Filter'
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
                                          //  Referenced by: '<S33>/Derivative Gain'

  real_T PIDJMS0628_I;                 // Mask Parameter: PIDJMS0628_I
                                          //  Referenced by: '<S36>/Integral Gain'

  real_T PIDJMS0628_InitialConditionForF;
                              // Mask Parameter: PIDJMS0628_InitialConditionForF
                                 //  Referenced by: '<S34>/Filter'

  real_T PIDJMS0628_InitialConditionForI;
                              // Mask Parameter: PIDJMS0628_InitialConditionForI
                                 //  Referenced by: '<S39>/Integrator'

  real_T PIDJMS0628_LowerSaturationLimit;
                              // Mask Parameter: PIDJMS0628_LowerSaturationLimit
                                 //  Referenced by:
                                 //    '<S46>/Saturation'
                                 //    '<S32>/DeadZone'

  real_T PIDJMS0628_N;                 // Mask Parameter: PIDJMS0628_N
                                          //  Referenced by: '<S42>/Filter Coefficient'

  real_T PIDJMS0628_P;                 // Mask Parameter: PIDJMS0628_P
                                          //  Referenced by: '<S44>/Proportional Gain'

  real_T PIDJMS0628_UpperSaturationLimit;
                              // Mask Parameter: PIDJMS0628_UpperSaturationLimit
                                 //  Referenced by:
                                 //    '<S46>/Saturation'
                                 //    '<S32>/DeadZone'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S56>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S4>/Constant'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                            //  Referenced by: '<S57>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                   //  Referenced by: '<S5>/Constant'

  SL_Bus_ghost_mode_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                         //  Referenced by: '<S1>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S30>/Constant1'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S30>/ZeroGain'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S30>/Memory'

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
  real_T odeY[2];
  real_T odeF[3][2];
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
//  '<S2>'   : 'ghost_mode/PID JMS 0628'
//  '<S3>'   : 'ghost_mode/Publish'
//  '<S4>'   : 'ghost_mode/Subscribe'
//  '<S5>'   : 'ghost_mode/Subscribe1'
//  '<S6>'   : 'ghost_mode/PID JMS 0628/Anti-windup'
//  '<S7>'   : 'ghost_mode/PID JMS 0628/D Gain'
//  '<S8>'   : 'ghost_mode/PID JMS 0628/Filter'
//  '<S9>'   : 'ghost_mode/PID JMS 0628/Filter ICs'
//  '<S10>'  : 'ghost_mode/PID JMS 0628/I Gain'
//  '<S11>'  : 'ghost_mode/PID JMS 0628/Ideal P Gain'
//  '<S12>'  : 'ghost_mode/PID JMS 0628/Ideal P Gain Fdbk'
//  '<S13>'  : 'ghost_mode/PID JMS 0628/Integrator'
//  '<S14>'  : 'ghost_mode/PID JMS 0628/Integrator ICs'
//  '<S15>'  : 'ghost_mode/PID JMS 0628/N Copy'
//  '<S16>'  : 'ghost_mode/PID JMS 0628/N Gain'
//  '<S17>'  : 'ghost_mode/PID JMS 0628/P Copy'
//  '<S18>'  : 'ghost_mode/PID JMS 0628/Parallel P Gain'
//  '<S19>'  : 'ghost_mode/PID JMS 0628/Reset Signal'
//  '<S20>'  : 'ghost_mode/PID JMS 0628/Saturation'
//  '<S21>'  : 'ghost_mode/PID JMS 0628/Saturation Fdbk'
//  '<S22>'  : 'ghost_mode/PID JMS 0628/Sum'
//  '<S23>'  : 'ghost_mode/PID JMS 0628/Sum Fdbk'
//  '<S24>'  : 'ghost_mode/PID JMS 0628/Tracking Mode'
//  '<S25>'  : 'ghost_mode/PID JMS 0628/Tracking Mode Sum'
//  '<S26>'  : 'ghost_mode/PID JMS 0628/Tsamp - Integral'
//  '<S27>'  : 'ghost_mode/PID JMS 0628/Tsamp - Ngain'
//  '<S28>'  : 'ghost_mode/PID JMS 0628/postSat Signal'
//  '<S29>'  : 'ghost_mode/PID JMS 0628/preSat Signal'
//  '<S30>'  : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel'
//  '<S31>'  : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S32>'  : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S33>'  : 'ghost_mode/PID JMS 0628/D Gain/Internal Parameters'
//  '<S34>'  : 'ghost_mode/PID JMS 0628/Filter/Cont. Filter'
//  '<S35>'  : 'ghost_mode/PID JMS 0628/Filter ICs/Internal IC - Filter'
//  '<S36>'  : 'ghost_mode/PID JMS 0628/I Gain/Internal Parameters'
//  '<S37>'  : 'ghost_mode/PID JMS 0628/Ideal P Gain/Passthrough'
//  '<S38>'  : 'ghost_mode/PID JMS 0628/Ideal P Gain Fdbk/Disabled'
//  '<S39>'  : 'ghost_mode/PID JMS 0628/Integrator/Continuous'
//  '<S40>'  : 'ghost_mode/PID JMS 0628/Integrator ICs/Internal IC'
//  '<S41>'  : 'ghost_mode/PID JMS 0628/N Copy/Disabled'
//  '<S42>'  : 'ghost_mode/PID JMS 0628/N Gain/Internal Parameters'
//  '<S43>'  : 'ghost_mode/PID JMS 0628/P Copy/Disabled'
//  '<S44>'  : 'ghost_mode/PID JMS 0628/Parallel P Gain/Internal Parameters'
//  '<S45>'  : 'ghost_mode/PID JMS 0628/Reset Signal/Disabled'
//  '<S46>'  : 'ghost_mode/PID JMS 0628/Saturation/Enabled'
//  '<S47>'  : 'ghost_mode/PID JMS 0628/Saturation Fdbk/Disabled'
//  '<S48>'  : 'ghost_mode/PID JMS 0628/Sum/Sum_PID'
//  '<S49>'  : 'ghost_mode/PID JMS 0628/Sum Fdbk/Disabled'
//  '<S50>'  : 'ghost_mode/PID JMS 0628/Tracking Mode/Disabled'
//  '<S51>'  : 'ghost_mode/PID JMS 0628/Tracking Mode Sum/Passthrough'
//  '<S52>'  : 'ghost_mode/PID JMS 0628/Tsamp - Integral/Passthrough'
//  '<S53>'  : 'ghost_mode/PID JMS 0628/Tsamp - Ngain/Passthrough'
//  '<S54>'  : 'ghost_mode/PID JMS 0628/postSat Signal/Forward_Path'
//  '<S55>'  : 'ghost_mode/PID JMS 0628/preSat Signal/Forward_Path'
//  '<S56>'  : 'ghost_mode/Subscribe/Enabled Subsystem'
//  '<S57>'  : 'ghost_mode/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_ghost_mode_h_

//
// File trailer for generated code.
//
// [EOF]
//
