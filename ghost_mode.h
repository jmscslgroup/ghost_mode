//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.h
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.41
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 18:00:54 2021
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
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1;// '<S160>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped In1_d;// '<S159>/In1'
  SL_Bus_ghost_mode_geometry_msgs_TwistStamped b_varargout_2;
  real_T Sum;                          // '<Root>/Sum'
  real_T ProportionalGain;             // '<S47>/Proportional Gain'
  real_T DerivativeGain;               // '<S36>/Derivative Gain'
  real_T FilterCoefficient;            // '<S45>/Filter Coefficient'
  real_T ProportionalGain_e;           // '<S97>/Proportional Gain'
  real_T DerivativeGain_b;             // '<S86>/Derivative Gain'
  real_T FilterCoefficient_c;          // '<S95>/Filter Coefficient'
  real_T IntegralGain;                 // '<S39>/Integral Gain'
  real_T Switch;                       // '<S33>/Switch'
  real_T IntegralGain_p;               // '<S89>/Integral Gain'
  real_T Switch_l;                     // '<S83>/Switch'
  real_T Switch_j;                     // '<S133>/Switch'
  real_T ProportionalGain_f;           // '<S147>/Proportional Gain'
  real_T DerivativeGain_e;             // '<S136>/Derivative Gain'
  real_T FilterCoefficient_p;          // '<S145>/Filter Coefficient'
  real_T Sum_m;                        // '<S51>/Sum'
  int8_T DataTypeConv2;                // '<S133>/DataTypeConv2'
  boolean_T AND3;                      // '<S33>/AND3'
  boolean_T Memory;                    // '<S33>/Memory'
  boolean_T AND3_h;                    // '<S83>/AND3'
  boolean_T Memory_g;                  // '<S83>/Memory'
  boolean_T AND3_e;                    // '<S133>/AND3'
};

// Block states (default storage) for system '<Root>'
struct DW_ghost_mode_T {
  ros_slroscpp_internal_block_P_T obj; // '<S4>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S6>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S5>/SourceBlock'
  boolean_T Memory_PreviousInput;      // '<S33>/Memory'
  boolean_T Memory_PreviousInput_j;    // '<S83>/Memory'
  boolean_T Memory_PreviousInput_n;    // '<S133>/Memory'
};

// Continuous states (default storage)
struct X_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S42>/Integrator'
  real_T Filter_CSTATE;                // '<S37>/Filter'
  real_T Integrator_CSTATE_i;          // '<S92>/Integrator'
  real_T Filter_CSTATE_f;              // '<S87>/Filter'
  real_T Integrator_CSTATE_f;          // '<S142>/Integrator'
  real_T Filter_CSTATE_d;              // '<S137>/Filter'
};

// State derivatives (default storage)
struct XDot_ghost_mode_T {
  real_T Integrator_CSTATE;            // '<S42>/Integrator'
  real_T Filter_CSTATE;                // '<S37>/Filter'
  real_T Integrator_CSTATE_i;          // '<S92>/Integrator'
  real_T Filter_CSTATE_f;              // '<S87>/Filter'
  real_T Integrator_CSTATE_f;          // '<S142>/Integrator'
  real_T Filter_CSTATE_d;              // '<S137>/Filter'
};

// State disabled
struct XDis_ghost_mode_T {
  boolean_T Integrator_CSTATE;         // '<S42>/Integrator'
  boolean_T Filter_CSTATE;             // '<S37>/Filter'
  boolean_T Integrator_CSTATE_i;       // '<S92>/Integrator'
  boolean_T Filter_CSTATE_f;           // '<S87>/Filter'
  boolean_T Integrator_CSTATE_f;       // '<S142>/Integrator'
  boolean_T Filter_CSTATE_d;           // '<S137>/Filter'
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
                                          //  Referenced by: '<S36>/Derivative Gain'

  real_T PIDJMS1_D;                    // Mask Parameter: PIDJMS1_D
                                          //  Referenced by: '<S86>/Derivative Gain'

  real_T PIDJMS0628_D_e;               // Mask Parameter: PIDJMS0628_D_e
                                          //  Referenced by: '<S136>/Derivative Gain'

  real_T PIDJMS0628_I;                 // Mask Parameter: PIDJMS0628_I
                                          //  Referenced by: '<S39>/Integral Gain'

  real_T PIDJMS1_I;                    // Mask Parameter: PIDJMS1_I
                                          //  Referenced by: '<S89>/Integral Gain'

  real_T PIDJMS0628_I_m;               // Mask Parameter: PIDJMS0628_I_m
                                          //  Referenced by: '<S139>/Integral Gain'

  real_T PIDJMS0628_InitialConditionForF;
                              // Mask Parameter: PIDJMS0628_InitialConditionForF
                                 //  Referenced by: '<S37>/Filter'

  real_T PIDJMS1_InitialConditionForFilt;
                              // Mask Parameter: PIDJMS1_InitialConditionForFilt
                                 //  Referenced by: '<S87>/Filter'

  real_T PIDJMS0628_InitialConditionFo_d;
                              // Mask Parameter: PIDJMS0628_InitialConditionFo_d
                                 //  Referenced by: '<S137>/Filter'

  real_T PIDJMS0628_InitialConditionForI;
                              // Mask Parameter: PIDJMS0628_InitialConditionForI
                                 //  Referenced by: '<S42>/Integrator'

  real_T PIDJMS1_InitialConditionForInte;
                              // Mask Parameter: PIDJMS1_InitialConditionForInte
                                 //  Referenced by: '<S92>/Integrator'

  real_T PIDJMS0628_InitialConditionFo_l;
                              // Mask Parameter: PIDJMS0628_InitialConditionFo_l
                                 //  Referenced by: '<S142>/Integrator'

  real_T PIDJMS0628_Kt;                // Mask Parameter: PIDJMS0628_Kt
                                          //  Referenced by: '<S53>/Kt'

  real_T PIDJMS1_Kt;                   // Mask Parameter: PIDJMS1_Kt
                                          //  Referenced by: '<S103>/Kt'

  real_T PIDJMS0628_LowerSaturationLimit;
                              // Mask Parameter: PIDJMS0628_LowerSaturationLimit
                                 //  Referenced by:
                                 //    '<S49>/Saturation'
                                 //    '<S35>/DeadZone'

  real_T PIDJMS1_LowerSaturationLimit;
                                 // Mask Parameter: PIDJMS1_LowerSaturationLimit
                                    //  Referenced by:
                                    //    '<S99>/Saturation'
                                    //    '<S85>/DeadZone'

  real_T PIDJMS0628_LowerSaturationLim_l;
                              // Mask Parameter: PIDJMS0628_LowerSaturationLim_l
                                 //  Referenced by: '<S135>/DeadZone'

  real_T PIDJMS0628_N;                 // Mask Parameter: PIDJMS0628_N
                                          //  Referenced by: '<S45>/Filter Coefficient'

  real_T PIDJMS1_N;                    // Mask Parameter: PIDJMS1_N
                                          //  Referenced by: '<S95>/Filter Coefficient'

  real_T PIDJMS0628_N_f;               // Mask Parameter: PIDJMS0628_N_f
                                          //  Referenced by: '<S145>/Filter Coefficient'

  real_T PIDJMS0628_P;                 // Mask Parameter: PIDJMS0628_P
                                          //  Referenced by: '<S47>/Proportional Gain'

  real_T PIDJMS1_P;                    // Mask Parameter: PIDJMS1_P
                                          //  Referenced by: '<S97>/Proportional Gain'

  real_T PIDJMS0628_P_a;               // Mask Parameter: PIDJMS0628_P_a
                                          //  Referenced by: '<S147>/Proportional Gain'

  real_T PIDJMS0628_UpperSaturationLimit;
                              // Mask Parameter: PIDJMS0628_UpperSaturationLimit
                                 //  Referenced by:
                                 //    '<S49>/Saturation'
                                 //    '<S35>/DeadZone'

  real_T PIDJMS1_UpperSaturationLimit;
                                 // Mask Parameter: PIDJMS1_UpperSaturationLimit
                                    //  Referenced by:
                                    //    '<S99>/Saturation'
                                    //    '<S85>/DeadZone'

  real_T PIDJMS0628_UpperSaturationLim_p;
                              // Mask Parameter: PIDJMS0628_UpperSaturationLim_p
                                 //  Referenced by: '<S135>/DeadZone'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S159>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S5>/Constant'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                            //  Referenced by: '<S160>/Out1'

  SL_Bus_ghost_mode_geometry_msgs_TwistStamped Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                   //  Referenced by: '<S6>/Constant'

  SL_Bus_ghost_mode_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                         //  Referenced by: '<S1>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S33>/Constant1'

  real_T Constant1_Value_a;            // Expression: 0
                                          //  Referenced by: '<S83>/Constant1'

  real_T Constant1_Value_p;            // Expression: 0
                                          //  Referenced by: '<S133>/Constant1'

  real_T Switch_Threshold;             // Expression: -0.25
                                          //  Referenced by: '<S2>/Switch'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S33>/ZeroGain'

  real_T ZeroGain_Gain_i;              // Expression: 0
                                          //  Referenced by: '<S83>/ZeroGain'

  real_T ZeroGain_Gain_j;              // Expression: 0
                                          //  Referenced by: '<S133>/ZeroGain'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S33>/Memory'

  boolean_T Memory_InitialCondition_c;
                                // Computed Parameter: Memory_InitialCondition_c
                                   //  Referenced by: '<S83>/Memory'

  boolean_T Memory_InitialCondition_p;
                                // Computed Parameter: Memory_InitialCondition_p
                                   //  Referenced by: '<S133>/Memory'

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
  real_T odeY[6];
  real_T odeF[3][6];
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
//  Block '<S149>/Saturation' : Unused code path elimination


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
//  '<S3>'   : 'ghost_mode/PID JMS 0628'
//  '<S4>'   : 'ghost_mode/Publish'
//  '<S5>'   : 'ghost_mode/Subscribe'
//  '<S6>'   : 'ghost_mode/Subscribe1'
//  '<S7>'   : 'ghost_mode/Controller1/PID JMS 0628'
//  '<S8>'   : 'ghost_mode/Controller1/PID JMS 1'
//  '<S9>'   : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup'
//  '<S10>'  : 'ghost_mode/Controller1/PID JMS 0628/D Gain'
//  '<S11>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter'
//  '<S12>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter ICs'
//  '<S13>'  : 'ghost_mode/Controller1/PID JMS 0628/I Gain'
//  '<S14>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain'
//  '<S15>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain Fdbk'
//  '<S16>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator'
//  '<S17>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator ICs'
//  '<S18>'  : 'ghost_mode/Controller1/PID JMS 0628/N Copy'
//  '<S19>'  : 'ghost_mode/Controller1/PID JMS 0628/N Gain'
//  '<S20>'  : 'ghost_mode/Controller1/PID JMS 0628/P Copy'
//  '<S21>'  : 'ghost_mode/Controller1/PID JMS 0628/Parallel P Gain'
//  '<S22>'  : 'ghost_mode/Controller1/PID JMS 0628/Reset Signal'
//  '<S23>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation'
//  '<S24>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation Fdbk'
//  '<S25>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum'
//  '<S26>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum Fdbk'
//  '<S27>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode'
//  '<S28>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode Sum'
//  '<S29>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Integral'
//  '<S30>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Ngain'
//  '<S31>'  : 'ghost_mode/Controller1/PID JMS 0628/postSat Signal'
//  '<S32>'  : 'ghost_mode/Controller1/PID JMS 0628/preSat Signal'
//  '<S33>'  : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup/Cont. Clamping Parallel'
//  '<S34>'  : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S35>'  : 'ghost_mode/Controller1/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S36>'  : 'ghost_mode/Controller1/PID JMS 0628/D Gain/Internal Parameters'
//  '<S37>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter/Cont. Filter'
//  '<S38>'  : 'ghost_mode/Controller1/PID JMS 0628/Filter ICs/Internal IC - Filter'
//  '<S39>'  : 'ghost_mode/Controller1/PID JMS 0628/I Gain/Internal Parameters'
//  '<S40>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain/Passthrough'
//  '<S41>'  : 'ghost_mode/Controller1/PID JMS 0628/Ideal P Gain Fdbk/Disabled'
//  '<S42>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator/Continuous'
//  '<S43>'  : 'ghost_mode/Controller1/PID JMS 0628/Integrator ICs/Internal IC'
//  '<S44>'  : 'ghost_mode/Controller1/PID JMS 0628/N Copy/Disabled'
//  '<S45>'  : 'ghost_mode/Controller1/PID JMS 0628/N Gain/Internal Parameters'
//  '<S46>'  : 'ghost_mode/Controller1/PID JMS 0628/P Copy/Disabled'
//  '<S47>'  : 'ghost_mode/Controller1/PID JMS 0628/Parallel P Gain/Internal Parameters'
//  '<S48>'  : 'ghost_mode/Controller1/PID JMS 0628/Reset Signal/Disabled'
//  '<S49>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation/Enabled'
//  '<S50>'  : 'ghost_mode/Controller1/PID JMS 0628/Saturation Fdbk/Disabled'
//  '<S51>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum/Sum_PID'
//  '<S52>'  : 'ghost_mode/Controller1/PID JMS 0628/Sum Fdbk/Disabled'
//  '<S53>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode/Enabled'
//  '<S54>'  : 'ghost_mode/Controller1/PID JMS 0628/Tracking Mode Sum/Tracking Mode'
//  '<S55>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Integral/Passthrough'
//  '<S56>'  : 'ghost_mode/Controller1/PID JMS 0628/Tsamp - Ngain/Passthrough'
//  '<S57>'  : 'ghost_mode/Controller1/PID JMS 0628/postSat Signal/Forward_Path'
//  '<S58>'  : 'ghost_mode/Controller1/PID JMS 0628/preSat Signal/Forward_Path'
//  '<S59>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup'
//  '<S60>'  : 'ghost_mode/Controller1/PID JMS 1/D Gain'
//  '<S61>'  : 'ghost_mode/Controller1/PID JMS 1/Filter'
//  '<S62>'  : 'ghost_mode/Controller1/PID JMS 1/Filter ICs'
//  '<S63>'  : 'ghost_mode/Controller1/PID JMS 1/I Gain'
//  '<S64>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain'
//  '<S65>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain Fdbk'
//  '<S66>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator'
//  '<S67>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator ICs'
//  '<S68>'  : 'ghost_mode/Controller1/PID JMS 1/N Copy'
//  '<S69>'  : 'ghost_mode/Controller1/PID JMS 1/N Gain'
//  '<S70>'  : 'ghost_mode/Controller1/PID JMS 1/P Copy'
//  '<S71>'  : 'ghost_mode/Controller1/PID JMS 1/Parallel P Gain'
//  '<S72>'  : 'ghost_mode/Controller1/PID JMS 1/Reset Signal'
//  '<S73>'  : 'ghost_mode/Controller1/PID JMS 1/Saturation'
//  '<S74>'  : 'ghost_mode/Controller1/PID JMS 1/Saturation Fdbk'
//  '<S75>'  : 'ghost_mode/Controller1/PID JMS 1/Sum'
//  '<S76>'  : 'ghost_mode/Controller1/PID JMS 1/Sum Fdbk'
//  '<S77>'  : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode'
//  '<S78>'  : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode Sum'
//  '<S79>'  : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Integral'
//  '<S80>'  : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Ngain'
//  '<S81>'  : 'ghost_mode/Controller1/PID JMS 1/postSat Signal'
//  '<S82>'  : 'ghost_mode/Controller1/PID JMS 1/preSat Signal'
//  '<S83>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup/Cont. Clamping Parallel'
//  '<S84>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S85>'  : 'ghost_mode/Controller1/PID JMS 1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S86>'  : 'ghost_mode/Controller1/PID JMS 1/D Gain/Internal Parameters'
//  '<S87>'  : 'ghost_mode/Controller1/PID JMS 1/Filter/Cont. Filter'
//  '<S88>'  : 'ghost_mode/Controller1/PID JMS 1/Filter ICs/Internal IC - Filter'
//  '<S89>'  : 'ghost_mode/Controller1/PID JMS 1/I Gain/Internal Parameters'
//  '<S90>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain/Passthrough'
//  '<S91>'  : 'ghost_mode/Controller1/PID JMS 1/Ideal P Gain Fdbk/Disabled'
//  '<S92>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator/Continuous'
//  '<S93>'  : 'ghost_mode/Controller1/PID JMS 1/Integrator ICs/Internal IC'
//  '<S94>'  : 'ghost_mode/Controller1/PID JMS 1/N Copy/Disabled'
//  '<S95>'  : 'ghost_mode/Controller1/PID JMS 1/N Gain/Internal Parameters'
//  '<S96>'  : 'ghost_mode/Controller1/PID JMS 1/P Copy/Disabled'
//  '<S97>'  : 'ghost_mode/Controller1/PID JMS 1/Parallel P Gain/Internal Parameters'
//  '<S98>'  : 'ghost_mode/Controller1/PID JMS 1/Reset Signal/Disabled'
//  '<S99>'  : 'ghost_mode/Controller1/PID JMS 1/Saturation/Enabled'
//  '<S100>' : 'ghost_mode/Controller1/PID JMS 1/Saturation Fdbk/Disabled'
//  '<S101>' : 'ghost_mode/Controller1/PID JMS 1/Sum/Sum_PID'
//  '<S102>' : 'ghost_mode/Controller1/PID JMS 1/Sum Fdbk/Disabled'
//  '<S103>' : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode/Enabled'
//  '<S104>' : 'ghost_mode/Controller1/PID JMS 1/Tracking Mode Sum/Tracking Mode'
//  '<S105>' : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Integral/Passthrough'
//  '<S106>' : 'ghost_mode/Controller1/PID JMS 1/Tsamp - Ngain/Passthrough'
//  '<S107>' : 'ghost_mode/Controller1/PID JMS 1/postSat Signal/Forward_Path'
//  '<S108>' : 'ghost_mode/Controller1/PID JMS 1/preSat Signal/Forward_Path'
//  '<S109>' : 'ghost_mode/PID JMS 0628/Anti-windup'
//  '<S110>' : 'ghost_mode/PID JMS 0628/D Gain'
//  '<S111>' : 'ghost_mode/PID JMS 0628/Filter'
//  '<S112>' : 'ghost_mode/PID JMS 0628/Filter ICs'
//  '<S113>' : 'ghost_mode/PID JMS 0628/I Gain'
//  '<S114>' : 'ghost_mode/PID JMS 0628/Ideal P Gain'
//  '<S115>' : 'ghost_mode/PID JMS 0628/Ideal P Gain Fdbk'
//  '<S116>' : 'ghost_mode/PID JMS 0628/Integrator'
//  '<S117>' : 'ghost_mode/PID JMS 0628/Integrator ICs'
//  '<S118>' : 'ghost_mode/PID JMS 0628/N Copy'
//  '<S119>' : 'ghost_mode/PID JMS 0628/N Gain'
//  '<S120>' : 'ghost_mode/PID JMS 0628/P Copy'
//  '<S121>' : 'ghost_mode/PID JMS 0628/Parallel P Gain'
//  '<S122>' : 'ghost_mode/PID JMS 0628/Reset Signal'
//  '<S123>' : 'ghost_mode/PID JMS 0628/Saturation'
//  '<S124>' : 'ghost_mode/PID JMS 0628/Saturation Fdbk'
//  '<S125>' : 'ghost_mode/PID JMS 0628/Sum'
//  '<S126>' : 'ghost_mode/PID JMS 0628/Sum Fdbk'
//  '<S127>' : 'ghost_mode/PID JMS 0628/Tracking Mode'
//  '<S128>' : 'ghost_mode/PID JMS 0628/Tracking Mode Sum'
//  '<S129>' : 'ghost_mode/PID JMS 0628/Tsamp - Integral'
//  '<S130>' : 'ghost_mode/PID JMS 0628/Tsamp - Ngain'
//  '<S131>' : 'ghost_mode/PID JMS 0628/postSat Signal'
//  '<S132>' : 'ghost_mode/PID JMS 0628/preSat Signal'
//  '<S133>' : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel'
//  '<S134>' : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S135>' : 'ghost_mode/PID JMS 0628/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S136>' : 'ghost_mode/PID JMS 0628/D Gain/Internal Parameters'
//  '<S137>' : 'ghost_mode/PID JMS 0628/Filter/Cont. Filter'
//  '<S138>' : 'ghost_mode/PID JMS 0628/Filter ICs/Internal IC - Filter'
//  '<S139>' : 'ghost_mode/PID JMS 0628/I Gain/Internal Parameters'
//  '<S140>' : 'ghost_mode/PID JMS 0628/Ideal P Gain/Passthrough'
//  '<S141>' : 'ghost_mode/PID JMS 0628/Ideal P Gain Fdbk/Disabled'
//  '<S142>' : 'ghost_mode/PID JMS 0628/Integrator/Continuous'
//  '<S143>' : 'ghost_mode/PID JMS 0628/Integrator ICs/Internal IC'
//  '<S144>' : 'ghost_mode/PID JMS 0628/N Copy/Disabled'
//  '<S145>' : 'ghost_mode/PID JMS 0628/N Gain/Internal Parameters'
//  '<S146>' : 'ghost_mode/PID JMS 0628/P Copy/Disabled'
//  '<S147>' : 'ghost_mode/PID JMS 0628/Parallel P Gain/Internal Parameters'
//  '<S148>' : 'ghost_mode/PID JMS 0628/Reset Signal/Disabled'
//  '<S149>' : 'ghost_mode/PID JMS 0628/Saturation/Enabled'
//  '<S150>' : 'ghost_mode/PID JMS 0628/Saturation Fdbk/Disabled'
//  '<S151>' : 'ghost_mode/PID JMS 0628/Sum/Sum_PID'
//  '<S152>' : 'ghost_mode/PID JMS 0628/Sum Fdbk/Disabled'
//  '<S153>' : 'ghost_mode/PID JMS 0628/Tracking Mode/Disabled'
//  '<S154>' : 'ghost_mode/PID JMS 0628/Tracking Mode Sum/Passthrough'
//  '<S155>' : 'ghost_mode/PID JMS 0628/Tsamp - Integral/Passthrough'
//  '<S156>' : 'ghost_mode/PID JMS 0628/Tsamp - Ngain/Passthrough'
//  '<S157>' : 'ghost_mode/PID JMS 0628/postSat Signal/Forward_Path'
//  '<S158>' : 'ghost_mode/PID JMS 0628/preSat Signal/Forward_Path'
//  '<S159>' : 'ghost_mode/Subscribe/Enabled Subsystem'
//  '<S160>' : 'ghost_mode/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_ghost_mode_h_

//
// File trailer for generated code.
//
// [EOF]
//
