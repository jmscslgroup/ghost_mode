//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.cpp
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.45
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Jun 30 11:14:22 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ghost_mode.h"
#include "ghost_mode_private.h"

// Named constants for Chart: '<S4>/Chart'
const uint8_T ghost_mode_IN_ChatterDown = 1U;
const uint8_T ghost_mode_IN_ChatterUp = 2U;
const uint8_T ghost_mode_IN_SlowDown = 3U;
const uint8_T ghost_mode_IN_SpeedUp = 4U;

// Block signals (default storage)
B_ghost_mode_T ghost_mode_B;

// Continuous states
X_ghost_mode_T ghost_mode_X;

// Block states (default storage)
DW_ghost_mode_T ghost_mode_DW;

// Real-time model
RT_MODEL_ghost_mode_T ghost_mode_M_ = RT_MODEL_ghost_mode_T();
RT_MODEL_ghost_mode_T *const ghost_mode_M = &ghost_mode_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  ghost_mode_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ghost_mode_step();
  ghost_mode_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ghost_mode_step();
  ghost_mode_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void ghost_mode_step(void)
{
  SL_Bus_ghost_mode_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_SignPreSat;
  real_T rtb_Sum;
  real_T rtb_Sum_n;
  real_T tmp;
  real_T tmp_0;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&ghost_mode_M->solverInfo,
                          ((ghost_mode_M->Timing.clockTick0+1)*
      ghost_mode_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(ghost_mode_M)) {
    ghost_mode_M->Timing.t[0] = rtsiGetT(&ghost_mode_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S8>/SourceBlock' incorporates:
    //   Inport: '<S368>/In1'

    b_varargout_1 = Sub_ghost_mode_31.getLatestMessage
      (&ghost_mode_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S368>/Enable'

    if (b_varargout_1) {
      ghost_mode_B.In1 = ghost_mode_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S8>/SourceBlock'
    // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S7>/SourceBlock' incorporates:
    //   Inport: '<S367>/In1'

    b_varargout_1 = Sub_ghost_mode_10.getLatestMessage
      (&ghost_mode_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S367>/Enable'

    if (b_varargout_1) {
      ghost_mode_B.In1_d = ghost_mode_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Sum: '<Root>/Sum'
    rtb_Sum = ghost_mode_B.In1.Twist.Linear.X -
      ghost_mode_B.In1_d.Twist.Linear.X;

    // Gain: '<S355>/Proportional Gain'
    ghost_mode_B.ProportionalGain = ghost_mode_P.PIDJMS1_P * rtb_Sum;

    // Gain: '<S344>/Derivative Gain'
    ghost_mode_B.DerivativeGain = ghost_mode_P.PIDJMS1_D * rtb_Sum;
  }

  // Gain: '<S353>/Filter Coefficient' incorporates:
  //   Integrator: '<S345>/Filter'
  //   Sum: '<S345>/SumD'

  ghost_mode_B.FilterCoefficient = (ghost_mode_B.DerivativeGain -
    ghost_mode_X.Filter_CSTATE) * ghost_mode_P.PIDJMS1_N;

  // Sum: '<S359>/Sum' incorporates:
  //   Integrator: '<S350>/Integrator'

  rtb_Sum_n = (ghost_mode_B.ProportionalGain + ghost_mode_X.Integrator_CSTATE) +
    ghost_mode_B.FilterCoefficient;

  // Saturate: '<S357>/Saturation'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit) {
    rtb_SignPreSat = ghost_mode_P.PIDJMS1_UpperSaturationLimit;
  } else if (rtb_Sum_n < ghost_mode_P.PIDJMS1_LowerSaturationLimit) {
    rtb_SignPreSat = ghost_mode_P.PIDJMS1_LowerSaturationLimit;
  } else {
    rtb_SignPreSat = rtb_Sum_n;
  }

  // End of Saturate: '<S357>/Saturation'

  // Saturate: '<Root>/Saturation'
  if (rtb_SignPreSat > ghost_mode_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = ghost_mode_P.Saturation_UpperSat;
  } else if (rtb_SignPreSat < ghost_mode_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = ghost_mode_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = rtb_SignPreSat;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_ghost_mode_3.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S9>/SourceBlock' incorporates:
    //   Inport: '<S369>/In1'

    b_varargout_1 = Sub_ghost_mode_99.getLatestMessage
      (&ghost_mode_B.b_varargout_2_m);

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S369>/Enable'

    if (b_varargout_1) {
      ghost_mode_B.In1_e = ghost_mode_B.b_varargout_2_m;
    }

    // End of MATLABSystem: '<S9>/SourceBlock'
    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Gain: '<S347>/Integral Gain'
    ghost_mode_B.IntegralGain = ghost_mode_P.PIDJMS1_I * rtb_Sum;
  }

  // Sum: '<S362>/SumI1' incorporates:
  //   Gain: '<S361>/Kt'
  //   Sum: '<S361>/SumI3'

  rtb_Sum = (ghost_mode_B.In1_e.Accel.Linear.X - rtb_SignPreSat) *
    ghost_mode_P.PIDJMS1_Kt + ghost_mode_B.IntegralGain;

  // DeadZone: '<S343>/DeadZone'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit) {
    rtb_SignPreSat = rtb_Sum_n - ghost_mode_P.PIDJMS1_UpperSaturationLimit;
  } else if (rtb_Sum_n >= ghost_mode_P.PIDJMS1_LowerSaturationLimit) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat = rtb_Sum_n - ghost_mode_P.PIDJMS1_LowerSaturationLimit;
  }

  // End of DeadZone: '<S343>/DeadZone'

  // Signum: '<S341>/SignPreSat'
  if (rtb_SignPreSat < 0.0) {
    // DataTypeConversion: '<S341>/DataTypeConv1'
    tmp = -1.0;
  } else if (rtb_SignPreSat > 0.0) {
    // DataTypeConversion: '<S341>/DataTypeConv1'
    tmp = 1.0;
  } else if (rtb_SignPreSat == 0.0) {
    // DataTypeConversion: '<S341>/DataTypeConv1'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S341>/DataTypeConv1'
    tmp = (rtNaN);
  }

  // End of Signum: '<S341>/SignPreSat'

  // DataTypeConversion: '<S341>/DataTypeConv1'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // Signum: '<S341>/SignPreIntegrator'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S341>/DataTypeConv2'
    tmp_0 = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S341>/DataTypeConv2'
    tmp_0 = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S341>/DataTypeConv2'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S341>/DataTypeConv2'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S341>/SignPreIntegrator'

  // DataTypeConversion: '<S341>/DataTypeConv2'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S341>/AND3' incorporates:
  //   DataTypeConversion: '<S341>/DataTypeConv1'
  //   DataTypeConversion: '<S341>/DataTypeConv2'
  //   Gain: '<S341>/ZeroGain'
  //   RelationalOperator: '<S341>/Equal1'
  //   RelationalOperator: '<S341>/NotEqual'

  ghost_mode_B.AND3 = ((ghost_mode_P.ZeroGain_Gain * rtb_Sum_n != rtb_SignPreSat)
                       && ((tmp < 0.0 ? static_cast<int32_T>(static_cast<int8_T>
    (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(
    static_cast<int8_T>(static_cast<uint8_T>(tmp)))) == (tmp_0 < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp_0))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S341>/Memory'
    ghost_mode_B.Memory = ghost_mode_DW.Memory_PreviousInput;

    // Gain: '<S42>/Integral Gain'
    ghost_mode_B.IntegralGain_l = ghost_mode_P.PIDJMS0628_I * 0.0;

    // Gain: '<S50>/Proportional Gain'
    ghost_mode_B.ProportionalGain_f = ghost_mode_P.PIDJMS0628_P * 0.0;

    // Gain: '<S39>/Derivative Gain'
    ghost_mode_B.DerivativeGain_j = ghost_mode_P.PIDJMS0628_D * 0.0;
  }

  // Switch: '<S341>/Switch'
  if (ghost_mode_B.Memory) {
    // Switch: '<S341>/Switch' incorporates:
    //   Constant: '<S341>/Constant1'

    ghost_mode_B.Switch = ghost_mode_P.Constant1_Value;
  } else {
    // Switch: '<S341>/Switch'
    ghost_mode_B.Switch = rtb_Sum;
  }

  // End of Switch: '<S341>/Switch'

  // Gain: '<S48>/Filter Coefficient' incorporates:
  //   Integrator: '<S40>/Filter'
  //   Sum: '<S40>/SumD'

  ghost_mode_B.FilterCoefficient_c = (ghost_mode_B.DerivativeGain_j -
    ghost_mode_X.Filter_CSTATE_i) * ghost_mode_P.PIDJMS0628_N;

  // Sum: '<S54>/Sum' incorporates:
  //   Integrator: '<S45>/Integrator'

  rtb_Sum_n = (ghost_mode_B.ProportionalGain_f +
               ghost_mode_X.Integrator_CSTATE_f) +
    ghost_mode_B.FilterCoefficient_c;

  // Saturate: '<S52>/Saturation'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS0628_UpperSaturationLimit) {
    rtb_Sum = ghost_mode_P.PIDJMS0628_UpperSaturationLimit;
  } else if (rtb_Sum_n < ghost_mode_P.PIDJMS0628_LowerSaturationLimit) {
    rtb_Sum = ghost_mode_P.PIDJMS0628_LowerSaturationLimit;
  } else {
    rtb_Sum = rtb_Sum_n;
  }

  // End of Saturate: '<S52>/Saturation'

  // Sum: '<S57>/SumI1' incorporates:
  //   Gain: '<S56>/Kt'
  //   Sum: '<S56>/SumI3'

  rtb_Sum = (0.0 - rtb_Sum) * ghost_mode_P.PIDJMS0628_Kt +
    ghost_mode_B.IntegralGain_l;
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S36>/Memory'
    ghost_mode_B.Memory_d = ghost_mode_DW.Memory_PreviousInput_p;
  }

  // Switch: '<S36>/Switch'
  if (ghost_mode_B.Memory_d) {
    // Switch: '<S36>/Switch' incorporates:
    //   Constant: '<S36>/Constant1'

    ghost_mode_B.Switch_k = ghost_mode_P.Constant1_Value_o;
  } else {
    // Switch: '<S36>/Switch'
    ghost_mode_B.Switch_k = rtb_Sum;
  }

  // End of Switch: '<S36>/Switch'

  // Signum: '<S36>/SignPreIntegrator'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S36>/DataTypeConv2'
    tmp = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S36>/DataTypeConv2'
    tmp = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S36>/DataTypeConv2'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S36>/DataTypeConv2'
    tmp = (rtNaN);
  }

  // End of Signum: '<S36>/SignPreIntegrator'

  // DataTypeConversion: '<S36>/DataTypeConv2'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // DeadZone: '<S38>/DeadZone'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS0628_UpperSaturationLimit) {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS0628_UpperSaturationLimit;
  } else if (rtb_Sum_n >= ghost_mode_P.PIDJMS0628_LowerSaturationLimit) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS0628_LowerSaturationLimit;
  }

  // End of DeadZone: '<S38>/DeadZone'

  // Signum: '<S36>/SignPreSat'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S36>/DataTypeConv1'
    tmp_0 = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S36>/DataTypeConv1'
    tmp_0 = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S36>/DataTypeConv1'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S36>/DataTypeConv1'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S36>/SignPreSat'

  // DataTypeConversion: '<S36>/DataTypeConv1'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S36>/AND3' incorporates:
  //   DataTypeConversion: '<S36>/DataTypeConv1'
  //   DataTypeConversion: '<S36>/DataTypeConv2'
  //   Gain: '<S36>/ZeroGain'
  //   RelationalOperator: '<S36>/Equal1'
  //   RelationalOperator: '<S36>/NotEqual'

  ghost_mode_B.AND3_c = ((ghost_mode_P.ZeroGain_Gain_g * rtb_Sum_n != rtb_Sum) &&
    ((tmp_0 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp_0)))) == static_cast<int8_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S92>/Integral Gain'
    ghost_mode_B.IntegralGain_f = ghost_mode_P.PIDJMS1_I_g * 0.0;

    // Gain: '<S100>/Proportional Gain'
    ghost_mode_B.ProportionalGain_l = ghost_mode_P.PIDJMS1_P_l * 0.0;

    // Gain: '<S89>/Derivative Gain'
    ghost_mode_B.DerivativeGain_n = ghost_mode_P.PIDJMS1_D_e * 0.0;
  }

  // Gain: '<S98>/Filter Coefficient' incorporates:
  //   Integrator: '<S90>/Filter'
  //   Sum: '<S90>/SumD'

  ghost_mode_B.FilterCoefficient_g = (ghost_mode_B.DerivativeGain_n -
    ghost_mode_X.Filter_CSTATE_l) * ghost_mode_P.PIDJMS1_N_n;

  // Sum: '<S104>/Sum' incorporates:
  //   Integrator: '<S95>/Integrator'

  rtb_Sum_n = (ghost_mode_B.ProportionalGain_l +
               ghost_mode_X.Integrator_CSTATE_p) +
    ghost_mode_B.FilterCoefficient_g;

  // Saturate: '<S102>/Saturation'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit_e) {
    rtb_Sum = ghost_mode_P.PIDJMS1_UpperSaturationLimit_e;
  } else if (rtb_Sum_n < ghost_mode_P.PIDJMS1_LowerSaturationLimit_k) {
    rtb_Sum = ghost_mode_P.PIDJMS1_LowerSaturationLimit_k;
  } else {
    rtb_Sum = rtb_Sum_n;
  }

  // End of Saturate: '<S102>/Saturation'

  // Sum: '<S107>/SumI1' incorporates:
  //   Gain: '<S106>/Kt'
  //   Sum: '<S106>/SumI3'

  rtb_Sum = (0.0 - rtb_Sum) * ghost_mode_P.PIDJMS1_Kt_d +
    ghost_mode_B.IntegralGain_f;
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S86>/Memory'
    ghost_mode_B.Memory_m = ghost_mode_DW.Memory_PreviousInput_k;
  }

  // Switch: '<S86>/Switch'
  if (ghost_mode_B.Memory_m) {
    // Switch: '<S86>/Switch' incorporates:
    //   Constant: '<S86>/Constant1'

    ghost_mode_B.Switch_d = ghost_mode_P.Constant1_Value_c;
  } else {
    // Switch: '<S86>/Switch'
    ghost_mode_B.Switch_d = rtb_Sum;
  }

  // End of Switch: '<S86>/Switch'

  // Signum: '<S86>/SignPreIntegrator'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S86>/DataTypeConv2'
    tmp = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S86>/DataTypeConv2'
    tmp = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S86>/DataTypeConv2'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S86>/DataTypeConv2'
    tmp = (rtNaN);
  }

  // End of Signum: '<S86>/SignPreIntegrator'

  // DataTypeConversion: '<S86>/DataTypeConv2'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // DeadZone: '<S88>/DeadZone'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit_e) {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS1_UpperSaturationLimit_e;
  } else if (rtb_Sum_n >= ghost_mode_P.PIDJMS1_LowerSaturationLimit_k) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS1_LowerSaturationLimit_k;
  }

  // End of DeadZone: '<S88>/DeadZone'

  // Signum: '<S86>/SignPreSat'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S86>/DataTypeConv1'
    tmp_0 = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S86>/DataTypeConv1'
    tmp_0 = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S86>/DataTypeConv1'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S86>/DataTypeConv1'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S86>/SignPreSat'

  // DataTypeConversion: '<S86>/DataTypeConv1'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S86>/AND3' incorporates:
  //   DataTypeConversion: '<S86>/DataTypeConv1'
  //   DataTypeConversion: '<S86>/DataTypeConv2'
  //   Gain: '<S86>/ZeroGain'
  //   RelationalOperator: '<S86>/Equal1'
  //   RelationalOperator: '<S86>/NotEqual'

  ghost_mode_B.AND3_h = ((ghost_mode_P.ZeroGain_Gain_i * rtb_Sum_n != rtb_Sum) &&
    ((tmp_0 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp_0)))) == static_cast<int8_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S144>/Integral Gain'
    ghost_mode_B.IntegralGain_f0 = ghost_mode_P.PIDJMS0628_I_n * 0.0;

    // Gain: '<S152>/Proportional Gain'
    ghost_mode_B.ProportionalGain_k = ghost_mode_P.PIDJMS0628_P_b * 0.0;

    // Gain: '<S141>/Derivative Gain'
    ghost_mode_B.DerivativeGain_g = ghost_mode_P.PIDJMS0628_D_l * 0.0;
  }

  // Gain: '<S150>/Filter Coefficient' incorporates:
  //   Integrator: '<S142>/Filter'
  //   Sum: '<S142>/SumD'

  ghost_mode_B.FilterCoefficient_d = (ghost_mode_B.DerivativeGain_g -
    ghost_mode_X.Filter_CSTATE_f) * ghost_mode_P.PIDJMS0628_N_j;

  // Sum: '<S156>/Sum' incorporates:
  //   Integrator: '<S147>/Integrator'

  rtb_Sum_n = (ghost_mode_B.ProportionalGain_k +
               ghost_mode_X.Integrator_CSTATE_h) +
    ghost_mode_B.FilterCoefficient_d;

  // Saturate: '<S154>/Saturation'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS0628_UpperSaturationLim_p) {
    rtb_Sum = ghost_mode_P.PIDJMS0628_UpperSaturationLim_p;
  } else if (rtb_Sum_n < ghost_mode_P.PIDJMS0628_LowerSaturationLim_k) {
    rtb_Sum = ghost_mode_P.PIDJMS0628_LowerSaturationLim_k;
  } else {
    rtb_Sum = rtb_Sum_n;
  }

  // End of Saturate: '<S154>/Saturation'

  // Sum: '<S159>/SumI1' incorporates:
  //   Gain: '<S158>/Kt'
  //   Sum: '<S158>/SumI3'

  rtb_Sum = (0.0 - rtb_Sum) * ghost_mode_P.PIDJMS0628_Kt_b +
    ghost_mode_B.IntegralGain_f0;
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S138>/Memory'
    ghost_mode_B.Memory_n = ghost_mode_DW.Memory_PreviousInput_i;
  }

  // Switch: '<S138>/Switch'
  if (ghost_mode_B.Memory_n) {
    // Switch: '<S138>/Switch' incorporates:
    //   Constant: '<S138>/Constant1'

    ghost_mode_B.Switch_m = ghost_mode_P.Constant1_Value_l;
  } else {
    // Switch: '<S138>/Switch'
    ghost_mode_B.Switch_m = rtb_Sum;
  }

  // End of Switch: '<S138>/Switch'

  // Signum: '<S138>/SignPreIntegrator'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S138>/DataTypeConv2'
    tmp = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S138>/DataTypeConv2'
    tmp = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S138>/DataTypeConv2'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S138>/DataTypeConv2'
    tmp = (rtNaN);
  }

  // End of Signum: '<S138>/SignPreIntegrator'

  // DataTypeConversion: '<S138>/DataTypeConv2'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // DeadZone: '<S140>/DeadZone'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS0628_UpperSaturationLim_p) {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS0628_UpperSaturationLim_p;
  } else if (rtb_Sum_n >= ghost_mode_P.PIDJMS0628_LowerSaturationLim_k) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS0628_LowerSaturationLim_k;
  }

  // End of DeadZone: '<S140>/DeadZone'

  // Signum: '<S138>/SignPreSat'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S138>/DataTypeConv1'
    tmp_0 = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S138>/DataTypeConv1'
    tmp_0 = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S138>/DataTypeConv1'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S138>/DataTypeConv1'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S138>/SignPreSat'

  // DataTypeConversion: '<S138>/DataTypeConv1'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S138>/AND3' incorporates:
  //   DataTypeConversion: '<S138>/DataTypeConv1'
  //   DataTypeConversion: '<S138>/DataTypeConv2'
  //   Gain: '<S138>/ZeroGain'
  //   RelationalOperator: '<S138>/Equal1'
  //   RelationalOperator: '<S138>/NotEqual'

  ghost_mode_B.AND3_k = ((ghost_mode_P.ZeroGain_Gain_j * rtb_Sum_n != rtb_Sum) &&
    ((tmp_0 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp_0)))) == static_cast<int8_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S194>/Integral Gain'
    ghost_mode_B.IntegralGain_lk = ghost_mode_P.PIDJMS1_I_h * 0.0;

    // Gain: '<S202>/Proportional Gain'
    ghost_mode_B.ProportionalGain_m = ghost_mode_P.PIDJMS1_P_a * 0.0;

    // Gain: '<S191>/Derivative Gain'
    ghost_mode_B.DerivativeGain_c = ghost_mode_P.PIDJMS1_D_c * 0.0;
  }

  // Gain: '<S200>/Filter Coefficient' incorporates:
  //   Integrator: '<S192>/Filter'
  //   Sum: '<S192>/SumD'

  ghost_mode_B.FilterCoefficient_j = (ghost_mode_B.DerivativeGain_c -
    ghost_mode_X.Filter_CSTATE_o) * ghost_mode_P.PIDJMS1_N_nk;

  // Sum: '<S206>/Sum' incorporates:
  //   Integrator: '<S197>/Integrator'

  rtb_Sum_n = (ghost_mode_B.ProportionalGain_m +
               ghost_mode_X.Integrator_CSTATE_p5) +
    ghost_mode_B.FilterCoefficient_j;

  // Saturate: '<S204>/Saturation'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit_n) {
    rtb_Sum = ghost_mode_P.PIDJMS1_UpperSaturationLimit_n;
  } else if (rtb_Sum_n < ghost_mode_P.PIDJMS1_LowerSaturationLimit_l) {
    rtb_Sum = ghost_mode_P.PIDJMS1_LowerSaturationLimit_l;
  } else {
    rtb_Sum = rtb_Sum_n;
  }

  // End of Saturate: '<S204>/Saturation'

  // Sum: '<S209>/SumI1' incorporates:
  //   Gain: '<S208>/Kt'
  //   Sum: '<S208>/SumI3'

  rtb_Sum = (0.0 - rtb_Sum) * ghost_mode_P.PIDJMS1_Kt_dq +
    ghost_mode_B.IntegralGain_lk;
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S188>/Memory'
    ghost_mode_B.Memory_a = ghost_mode_DW.Memory_PreviousInput_pv;
  }

  // Switch: '<S188>/Switch'
  if (ghost_mode_B.Memory_a) {
    // Switch: '<S188>/Switch' incorporates:
    //   Constant: '<S188>/Constant1'

    ghost_mode_B.Switch_a = ghost_mode_P.Constant1_Value_k;
  } else {
    // Switch: '<S188>/Switch'
    ghost_mode_B.Switch_a = rtb_Sum;
  }

  // End of Switch: '<S188>/Switch'

  // Signum: '<S188>/SignPreIntegrator'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S188>/DataTypeConv2'
    tmp = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S188>/DataTypeConv2'
    tmp = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S188>/DataTypeConv2'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S188>/DataTypeConv2'
    tmp = (rtNaN);
  }

  // End of Signum: '<S188>/SignPreIntegrator'

  // DataTypeConversion: '<S188>/DataTypeConv2'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // DeadZone: '<S190>/DeadZone'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit_n) {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS1_UpperSaturationLimit_n;
  } else if (rtb_Sum_n >= ghost_mode_P.PIDJMS1_LowerSaturationLimit_l) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS1_LowerSaturationLimit_l;
  }

  // End of DeadZone: '<S190>/DeadZone'

  // Signum: '<S188>/SignPreSat'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S188>/DataTypeConv1'
    tmp_0 = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S188>/DataTypeConv1'
    tmp_0 = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S188>/DataTypeConv1'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S188>/DataTypeConv1'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S188>/SignPreSat'

  // DataTypeConversion: '<S188>/DataTypeConv1'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S188>/AND3' incorporates:
  //   DataTypeConversion: '<S188>/DataTypeConv1'
  //   DataTypeConversion: '<S188>/DataTypeConv2'
  //   Gain: '<S188>/ZeroGain'
  //   RelationalOperator: '<S188>/Equal1'
  //   RelationalOperator: '<S188>/NotEqual'

  ghost_mode_B.AND3_ha = ((ghost_mode_P.ZeroGain_Gain_l * rtb_Sum_n != rtb_Sum) &&
    ((tmp_0 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp_0)))) == static_cast<int8_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S247>/Integral Gain'
    ghost_mode_B.IntegralGain_p = ghost_mode_P.PIDJMS0628_I_c * 0.0;

    // Gain: '<S255>/Proportional Gain'
    ghost_mode_B.ProportionalGain_m4 = ghost_mode_P.PIDJMS0628_P_bi * 0.0;

    // Gain: '<S244>/Derivative Gain'
    ghost_mode_B.DerivativeGain_b = ghost_mode_P.PIDJMS0628_D_g * 0.0;
  }

  // Gain: '<S253>/Filter Coefficient' incorporates:
  //   Integrator: '<S245>/Filter'
  //   Sum: '<S245>/SumD'

  ghost_mode_B.FilterCoefficient_i = (ghost_mode_B.DerivativeGain_b -
    ghost_mode_X.Filter_CSTATE_e) * ghost_mode_P.PIDJMS0628_N_f;

  // Sum: '<S259>/Sum' incorporates:
  //   Integrator: '<S250>/Integrator'

  rtb_Sum_n = (ghost_mode_B.ProportionalGain_m4 +
               ghost_mode_X.Integrator_CSTATE_m) +
    ghost_mode_B.FilterCoefficient_i;

  // Saturate: '<S257>/Saturation'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS0628_UpperSaturationLim_l) {
    rtb_Sum = ghost_mode_P.PIDJMS0628_UpperSaturationLim_l;
  } else if (rtb_Sum_n < ghost_mode_P.PIDJMS0628_LowerSaturationLi_km) {
    rtb_Sum = ghost_mode_P.PIDJMS0628_LowerSaturationLi_km;
  } else {
    rtb_Sum = rtb_Sum_n;
  }

  // End of Saturate: '<S257>/Saturation'

  // Sum: '<S262>/SumI1' incorporates:
  //   Gain: '<S261>/Kt'
  //   Sum: '<S261>/SumI3'

  rtb_Sum = (0.0 - rtb_Sum) * ghost_mode_P.PIDJMS0628_Kt_j +
    ghost_mode_B.IntegralGain_p;
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S241>/Memory'
    ghost_mode_B.Memory_dp = ghost_mode_DW.Memory_PreviousInput_f;
  }

  // Switch: '<S241>/Switch'
  if (ghost_mode_B.Memory_dp) {
    // Switch: '<S241>/Switch' incorporates:
    //   Constant: '<S241>/Constant1'

    ghost_mode_B.Switch_ab = ghost_mode_P.Constant1_Value_n;
  } else {
    // Switch: '<S241>/Switch'
    ghost_mode_B.Switch_ab = rtb_Sum;
  }

  // End of Switch: '<S241>/Switch'

  // Signum: '<S241>/SignPreIntegrator'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S241>/DataTypeConv2'
    tmp = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S241>/DataTypeConv2'
    tmp = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S241>/DataTypeConv2'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S241>/DataTypeConv2'
    tmp = (rtNaN);
  }

  // End of Signum: '<S241>/SignPreIntegrator'

  // DataTypeConversion: '<S241>/DataTypeConv2'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // DeadZone: '<S243>/DeadZone'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS0628_UpperSaturationLim_l) {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS0628_UpperSaturationLim_l;
  } else if (rtb_Sum_n >= ghost_mode_P.PIDJMS0628_LowerSaturationLi_km) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS0628_LowerSaturationLi_km;
  }

  // End of DeadZone: '<S243>/DeadZone'

  // Signum: '<S241>/SignPreSat'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S241>/DataTypeConv1'
    tmp_0 = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S241>/DataTypeConv1'
    tmp_0 = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S241>/DataTypeConv1'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S241>/DataTypeConv1'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S241>/SignPreSat'

  // DataTypeConversion: '<S241>/DataTypeConv1'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S241>/AND3' incorporates:
  //   DataTypeConversion: '<S241>/DataTypeConv1'
  //   DataTypeConversion: '<S241>/DataTypeConv2'
  //   Gain: '<S241>/ZeroGain'
  //   RelationalOperator: '<S241>/Equal1'
  //   RelationalOperator: '<S241>/NotEqual'

  ghost_mode_B.AND3_cz = ((ghost_mode_P.ZeroGain_Gain_li * rtb_Sum_n != rtb_Sum)
    && ((tmp_0 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>
    (-static_cast<int8_T>(static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>
         (static_cast<int8_T>(static_cast<uint8_T>(tmp_0)))) ==
        static_cast<int8_T>(tmp < 0.0 ? static_cast<int32_T>(static_cast<int8_T>
    (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(
    static_cast<int8_T>(static_cast<uint8_T>(tmp))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S297>/Integral Gain'
    ghost_mode_B.IntegralGain_pq = ghost_mode_P.PIDJMS1_I_hb * 0.0;

    // Gain: '<S305>/Proportional Gain'
    ghost_mode_B.ProportionalGain_e = ghost_mode_P.PIDJMS1_P_f * 0.0;

    // Gain: '<S294>/Derivative Gain'
    ghost_mode_B.DerivativeGain_bz = ghost_mode_P.PIDJMS1_D_cd * 0.0;
  }

  // Gain: '<S303>/Filter Coefficient' incorporates:
  //   Integrator: '<S295>/Filter'
  //   Sum: '<S295>/SumD'

  ghost_mode_B.FilterCoefficient_cc = (ghost_mode_B.DerivativeGain_bz -
    ghost_mode_X.Filter_CSTATE_fu) * ghost_mode_P.PIDJMS1_N_m;

  // Sum: '<S309>/Sum' incorporates:
  //   Integrator: '<S300>/Integrator'

  rtb_Sum_n = (ghost_mode_B.ProportionalGain_e +
               ghost_mode_X.Integrator_CSTATE_i) +
    ghost_mode_B.FilterCoefficient_cc;

  // Saturate: '<S307>/Saturation'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit_b) {
    rtb_Sum = ghost_mode_P.PIDJMS1_UpperSaturationLimit_b;
  } else if (rtb_Sum_n < ghost_mode_P.PIDJMS1_LowerSaturationLimit_f) {
    rtb_Sum = ghost_mode_P.PIDJMS1_LowerSaturationLimit_f;
  } else {
    rtb_Sum = rtb_Sum_n;
  }

  // End of Saturate: '<S307>/Saturation'

  // Sum: '<S312>/SumI1' incorporates:
  //   Gain: '<S311>/Kt'
  //   Sum: '<S311>/SumI3'

  rtb_Sum = (0.0 - rtb_Sum) * ghost_mode_P.PIDJMS1_Kt_i +
    ghost_mode_B.IntegralGain_pq;
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S291>/Memory'
    ghost_mode_B.Memory_g = ghost_mode_DW.Memory_PreviousInput_j;
  }

  // Switch: '<S291>/Switch'
  if (ghost_mode_B.Memory_g) {
    // Switch: '<S291>/Switch' incorporates:
    //   Constant: '<S291>/Constant1'

    ghost_mode_B.Switch_l = ghost_mode_P.Constant1_Value_a;
  } else {
    // Switch: '<S291>/Switch'
    ghost_mode_B.Switch_l = rtb_Sum;
  }

  // End of Switch: '<S291>/Switch'

  // Signum: '<S291>/SignPreIntegrator'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S291>/DataTypeConv2'
    tmp = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S291>/DataTypeConv2'
    tmp = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S291>/DataTypeConv2'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S291>/DataTypeConv2'
    tmp = (rtNaN);
  }

  // End of Signum: '<S291>/SignPreIntegrator'

  // DataTypeConversion: '<S291>/DataTypeConv2'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // DeadZone: '<S293>/DeadZone'
  if (rtb_Sum_n > ghost_mode_P.PIDJMS1_UpperSaturationLimit_b) {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS1_UpperSaturationLimit_b;
  } else if (rtb_Sum_n >= ghost_mode_P.PIDJMS1_LowerSaturationLimit_f) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = rtb_Sum_n - ghost_mode_P.PIDJMS1_LowerSaturationLimit_f;
  }

  // End of DeadZone: '<S293>/DeadZone'

  // Signum: '<S291>/SignPreSat'
  if (rtb_Sum < 0.0) {
    // DataTypeConversion: '<S291>/DataTypeConv1'
    tmp_0 = -1.0;
  } else if (rtb_Sum > 0.0) {
    // DataTypeConversion: '<S291>/DataTypeConv1'
    tmp_0 = 1.0;
  } else if (rtb_Sum == 0.0) {
    // DataTypeConversion: '<S291>/DataTypeConv1'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S291>/DataTypeConv1'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S291>/SignPreSat'

  // DataTypeConversion: '<S291>/DataTypeConv1'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S291>/AND3' incorporates:
  //   DataTypeConversion: '<S291>/DataTypeConv1'
  //   DataTypeConversion: '<S291>/DataTypeConv2'
  //   Gain: '<S291>/ZeroGain'
  //   RelationalOperator: '<S291>/Equal1'
  //   RelationalOperator: '<S291>/NotEqual'

  ghost_mode_B.AND3_h0 = ((ghost_mode_P.ZeroGain_Gain_i1 * rtb_Sum_n != rtb_Sum)
    && ((tmp_0 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>
    (-static_cast<int8_T>(static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>
         (static_cast<int8_T>(static_cast<uint8_T>(tmp_0)))) ==
        static_cast<int8_T>(tmp < 0.0 ? static_cast<int32_T>(static_cast<int8_T>
    (-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(
    static_cast<int8_T>(static_cast<uint8_T>(tmp))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Chart: '<S4>/Chart'
    if (ghost_mode_DW.temporalCounter_i1 < 7U) {
      ghost_mode_DW.temporalCounter_i1 = static_cast<uint8_T>
        (ghost_mode_DW.temporalCounter_i1 + 1U);
    }

    if (ghost_mode_DW.is_active_c3_ghost_mode == 0U) {
      ghost_mode_DW.is_active_c3_ghost_mode = 1U;
      ghost_mode_DW.is_c3_ghost_mode = ghost_mode_IN_SpeedUp;
    } else {
      switch (ghost_mode_DW.is_c3_ghost_mode) {
       case ghost_mode_IN_ChatterDown:
        if (ghost_mode_DW.temporalCounter_i1 >= 6U) {
          ghost_mode_DW.is_c3_ghost_mode = ghost_mode_IN_SlowDown;
        }
        break;

       case ghost_mode_IN_ChatterUp:
        if (ghost_mode_DW.temporalCounter_i1 >= 6U) {
          ghost_mode_DW.is_c3_ghost_mode = ghost_mode_IN_SpeedUp;
        }
        break;

       case ghost_mode_IN_SlowDown:
        ghost_mode_DW.is_c3_ghost_mode = ghost_mode_IN_ChatterUp;
        ghost_mode_DW.temporalCounter_i1 = 0U;
        break;

       default:
        // case IN_SpeedUp:
        ghost_mode_DW.is_c3_ghost_mode = ghost_mode_IN_ChatterDown;
        ghost_mode_DW.temporalCounter_i1 = 0U;
        break;
      }
    }

    // End of Chart: '<S4>/Chart'
  }

  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    if (rtmIsMajorTimeStep(ghost_mode_M)) {
      // Update for Memory: '<S341>/Memory'
      ghost_mode_DW.Memory_PreviousInput = ghost_mode_B.AND3;

      // Update for Memory: '<S36>/Memory'
      ghost_mode_DW.Memory_PreviousInput_p = ghost_mode_B.AND3_c;

      // Update for Memory: '<S86>/Memory'
      ghost_mode_DW.Memory_PreviousInput_k = ghost_mode_B.AND3_h;

      // Update for Memory: '<S138>/Memory'
      ghost_mode_DW.Memory_PreviousInput_i = ghost_mode_B.AND3_k;

      // Update for Memory: '<S188>/Memory'
      ghost_mode_DW.Memory_PreviousInput_pv = ghost_mode_B.AND3_ha;

      // Update for Memory: '<S241>/Memory'
      ghost_mode_DW.Memory_PreviousInput_f = ghost_mode_B.AND3_cz;

      // Update for Memory: '<S291>/Memory'
      ghost_mode_DW.Memory_PreviousInput_j = ghost_mode_B.AND3_h0;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    rt_ertODEUpdateContinuousStates(&ghost_mode_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++ghost_mode_M->Timing.clockTick0;
    ghost_mode_M->Timing.t[0] = rtsiGetSolverStopTime(&ghost_mode_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.036s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.036, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      ghost_mode_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void ghost_mode_derivatives(void)
{
  XDot_ghost_mode_T *_rtXdot;
  _rtXdot = ((XDot_ghost_mode_T *) ghost_mode_M->derivs);

  // Derivatives for Integrator: '<S350>/Integrator'
  _rtXdot->Integrator_CSTATE = ghost_mode_B.Switch;

  // Derivatives for Integrator: '<S345>/Filter'
  _rtXdot->Filter_CSTATE = ghost_mode_B.FilterCoefficient;

  // Derivatives for Integrator: '<S45>/Integrator'
  _rtXdot->Integrator_CSTATE_f = ghost_mode_B.Switch_k;

  // Derivatives for Integrator: '<S40>/Filter'
  _rtXdot->Filter_CSTATE_i = ghost_mode_B.FilterCoefficient_c;

  // Derivatives for Integrator: '<S95>/Integrator'
  _rtXdot->Integrator_CSTATE_p = ghost_mode_B.Switch_d;

  // Derivatives for Integrator: '<S90>/Filter'
  _rtXdot->Filter_CSTATE_l = ghost_mode_B.FilterCoefficient_g;

  // Derivatives for Integrator: '<S147>/Integrator'
  _rtXdot->Integrator_CSTATE_h = ghost_mode_B.Switch_m;

  // Derivatives for Integrator: '<S142>/Filter'
  _rtXdot->Filter_CSTATE_f = ghost_mode_B.FilterCoefficient_d;

  // Derivatives for Integrator: '<S197>/Integrator'
  _rtXdot->Integrator_CSTATE_p5 = ghost_mode_B.Switch_a;

  // Derivatives for Integrator: '<S192>/Filter'
  _rtXdot->Filter_CSTATE_o = ghost_mode_B.FilterCoefficient_j;

  // Derivatives for Integrator: '<S250>/Integrator'
  _rtXdot->Integrator_CSTATE_m = ghost_mode_B.Switch_ab;

  // Derivatives for Integrator: '<S245>/Filter'
  _rtXdot->Filter_CSTATE_e = ghost_mode_B.FilterCoefficient_i;

  // Derivatives for Integrator: '<S300>/Integrator'
  _rtXdot->Integrator_CSTATE_i = ghost_mode_B.Switch_l;

  // Derivatives for Integrator: '<S295>/Filter'
  _rtXdot->Filter_CSTATE_fu = ghost_mode_B.FilterCoefficient_cc;
}

// Model initialize function
void ghost_mode_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&ghost_mode_M->solverInfo,
                          &ghost_mode_M->Timing.simTimeStep);
    rtsiSetTPtr(&ghost_mode_M->solverInfo, &rtmGetTPtr(ghost_mode_M));
    rtsiSetStepSizePtr(&ghost_mode_M->solverInfo,
                       &ghost_mode_M->Timing.stepSize0);
    rtsiSetdXPtr(&ghost_mode_M->solverInfo, &ghost_mode_M->derivs);
    rtsiSetContStatesPtr(&ghost_mode_M->solverInfo, (real_T **)
                         &ghost_mode_M->contStates);
    rtsiSetNumContStatesPtr(&ghost_mode_M->solverInfo,
      &ghost_mode_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ghost_mode_M->solverInfo,
      &ghost_mode_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ghost_mode_M->solverInfo,
      &ghost_mode_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ghost_mode_M->solverInfo,
      &ghost_mode_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ghost_mode_M->solverInfo, (&rtmGetErrorStatus
      (ghost_mode_M)));
    rtsiSetRTModelPtr(&ghost_mode_M->solverInfo, ghost_mode_M);
  }

  rtsiSetSimTimeStep(&ghost_mode_M->solverInfo, MAJOR_TIME_STEP);
  ghost_mode_M->intgData.y = ghost_mode_M->odeY;
  ghost_mode_M->intgData.f[0] = ghost_mode_M->odeF[0];
  ghost_mode_M->intgData.f[1] = ghost_mode_M->odeF[1];
  ghost_mode_M->intgData.f[2] = ghost_mode_M->odeF[2];
  ghost_mode_M->contStates = ((X_ghost_mode_T *) &ghost_mode_X);
  rtsiSetSolverData(&ghost_mode_M->solverInfo, static_cast<void *>
                    (&ghost_mode_M->intgData));
  rtsiSetSolverName(&ghost_mode_M->solverInfo,"ode3");
  rtmSetTPtr(ghost_mode_M, &ghost_mode_M->Timing.tArray[0]);
  ghost_mode_M->Timing.stepSize0 = 0.036;

  {
    int32_T i;
    char_T b_zeroDelimTopic[19];
    char_T b_zeroDelimTopic_1[15];
    char_T b_zeroDelimTopic_0[13];
    static const char_T tmp[18] = { '/', 'g', 'h', 'o', 's', 't', '/', 'v', 'e',
      'h', 'i', 'c', 'l', 'e', '/', 'v', 'e', 'l' };

    static const char_T tmp_0[12] = { '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_1[12] = { '/', 't', 'i', 'm', 'e', 'd', '_', 'a',
      'c', 'c', 'e', 'l' };

    static const char_T tmp_2[14] = { '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '/', 'a', 'c', 'c', 'e', 'l' };

    // InitializeConditions for Integrator: '<S350>/Integrator'
    ghost_mode_X.Integrator_CSTATE =
      ghost_mode_P.PIDJMS1_InitialConditionForInte;

    // InitializeConditions for Integrator: '<S345>/Filter'
    ghost_mode_X.Filter_CSTATE = ghost_mode_P.PIDJMS1_InitialConditionForFilt;

    // InitializeConditions for Memory: '<S341>/Memory'
    ghost_mode_DW.Memory_PreviousInput = ghost_mode_P.Memory_InitialCondition;

    // InitializeConditions for Integrator: '<S45>/Integrator'
    ghost_mode_X.Integrator_CSTATE_f =
      ghost_mode_P.PIDJMS0628_InitialConditionForI;

    // InitializeConditions for Integrator: '<S40>/Filter'
    ghost_mode_X.Filter_CSTATE_i = ghost_mode_P.PIDJMS0628_InitialConditionForF;

    // InitializeConditions for Memory: '<S36>/Memory'
    ghost_mode_DW.Memory_PreviousInput_p =
      ghost_mode_P.Memory_InitialCondition_p;

    // InitializeConditions for Integrator: '<S95>/Integrator'
    ghost_mode_X.Integrator_CSTATE_p =
      ghost_mode_P.PIDJMS1_InitialConditionForIn_k;

    // InitializeConditions for Integrator: '<S90>/Filter'
    ghost_mode_X.Filter_CSTATE_l = ghost_mode_P.PIDJMS1_InitialConditionForFi_m;

    // InitializeConditions for Memory: '<S86>/Memory'
    ghost_mode_DW.Memory_PreviousInput_k =
      ghost_mode_P.Memory_InitialCondition_j;

    // InitializeConditions for Integrator: '<S147>/Integrator'
    ghost_mode_X.Integrator_CSTATE_h =
      ghost_mode_P.PIDJMS0628_InitialConditionFo_f;

    // InitializeConditions for Integrator: '<S142>/Filter'
    ghost_mode_X.Filter_CSTATE_f = ghost_mode_P.PIDJMS0628_InitialConditionFo_g;

    // InitializeConditions for Memory: '<S138>/Memory'
    ghost_mode_DW.Memory_PreviousInput_i =
      ghost_mode_P.Memory_InitialCondition_g;

    // InitializeConditions for Integrator: '<S197>/Integrator'
    ghost_mode_X.Integrator_CSTATE_p5 =
      ghost_mode_P.PIDJMS1_InitialConditionForIn_m;

    // InitializeConditions for Integrator: '<S192>/Filter'
    ghost_mode_X.Filter_CSTATE_o = ghost_mode_P.PIDJMS1_InitialConditionForFi_e;

    // InitializeConditions for Memory: '<S188>/Memory'
    ghost_mode_DW.Memory_PreviousInput_pv =
      ghost_mode_P.Memory_InitialCondition_d;

    // InitializeConditions for Integrator: '<S250>/Integrator'
    ghost_mode_X.Integrator_CSTATE_m =
      ghost_mode_P.PIDJMS0628_InitialConditionFo_d;

    // InitializeConditions for Integrator: '<S245>/Filter'
    ghost_mode_X.Filter_CSTATE_e = ghost_mode_P.PIDJMS0628_InitialConditionFo_l;

    // InitializeConditions for Memory: '<S241>/Memory'
    ghost_mode_DW.Memory_PreviousInput_f =
      ghost_mode_P.Memory_InitialCondition_gk;

    // InitializeConditions for Integrator: '<S300>/Integrator'
    ghost_mode_X.Integrator_CSTATE_i =
      ghost_mode_P.PIDJMS1_InitialConditionForIn_g;

    // InitializeConditions for Integrator: '<S295>/Filter'
    ghost_mode_X.Filter_CSTATE_fu = ghost_mode_P.PIDJMS1_InitialConditionForFi_n;

    // InitializeConditions for Memory: '<S291>/Memory'
    ghost_mode_DW.Memory_PreviousInput_j =
      ghost_mode_P.Memory_InitialCondition_c;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S368>/Out1' incorporates:
    //   Inport: '<S368>/In1'

    ghost_mode_B.In1 = ghost_mode_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    ghost_mode_DW.obj_g.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[18] = '\x00';
    Sub_ghost_mode_31.createSubscriber(&b_zeroDelimTopic[0], 1);
    ghost_mode_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S367>/Out1' incorporates:
    //   Inport: '<S367>/In1'

    ghost_mode_B.In1_d = ghost_mode_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    ghost_mode_DW.obj_n.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Sub_ghost_mode_10.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ghost_mode_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    ghost_mode_DW.obj.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_1[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Pub_ghost_mode_3.createPublisher(&b_zeroDelimTopic_0[0], 1);
    ghost_mode_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S369>/Out1' incorporates:
    //   Inport: '<S369>/In1'

    ghost_mode_B.In1_e = ghost_mode_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    ghost_mode_DW.obj_f.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      b_zeroDelimTopic_1[i] = tmp_2[i];
    }

    b_zeroDelimTopic_1[14] = '\x00';
    Sub_ghost_mode_99.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    ghost_mode_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'
  }
}

// Model terminate function
void ghost_mode_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!ghost_mode_DW.obj_g.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!ghost_mode_DW.obj_n.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!ghost_mode_DW.obj.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!ghost_mode_DW.obj_f.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'
}

//
// File trailer for generated code.
//
// [EOF]
//
