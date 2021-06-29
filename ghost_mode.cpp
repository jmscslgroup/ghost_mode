//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.cpp
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
#include "ghost_mode.h"
#include "ghost_mode_private.h"

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
  int_T nXc = 6;
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
  real_T rtb_DeadZone;
  real_T rtb_Saturation;
  real_T rtb_SignPreSat;
  real_T rtb_Sum_c;
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
    // MATLABSystem: '<S6>/SourceBlock' incorporates:
    //   Inport: '<S160>/In1'

    b_varargout_1 = Sub_ghost_mode_31.getLatestMessage
      (&ghost_mode_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S160>/Enable'

    if (b_varargout_1) {
      ghost_mode_B.In1 = ghost_mode_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S5>/SourceBlock' incorporates:
    //   Inport: '<S159>/In1'

    b_varargout_1 = Sub_ghost_mode_10.getLatestMessage
      (&ghost_mode_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S159>/Enable'

    if (b_varargout_1) {
      ghost_mode_B.In1_d = ghost_mode_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Sum: '<Root>/Sum'
    ghost_mode_B.Sum = ghost_mode_B.In1.Twist.Linear.X -
      ghost_mode_B.In1_d.Twist.Linear.X;

    // Gain: '<S47>/Proportional Gain'
    ghost_mode_B.ProportionalGain = ghost_mode_P.PIDJMS0628_P * ghost_mode_B.Sum;

    // Gain: '<S36>/Derivative Gain'
    ghost_mode_B.DerivativeGain = ghost_mode_P.PIDJMS0628_D * ghost_mode_B.Sum;
  }

  // Gain: '<S45>/Filter Coefficient' incorporates:
  //   Integrator: '<S37>/Filter'
  //   Sum: '<S37>/SumD'

  ghost_mode_B.FilterCoefficient = (ghost_mode_B.DerivativeGain -
    ghost_mode_X.Filter_CSTATE) * ghost_mode_P.PIDJMS0628_N;

  // Sum: '<S51>/Sum' incorporates:
  //   Integrator: '<S42>/Integrator'

  ghost_mode_B.Sum_m = (ghost_mode_B.ProportionalGain +
                        ghost_mode_X.Integrator_CSTATE) +
    ghost_mode_B.FilterCoefficient;

  // Saturate: '<S49>/Saturation'
  if (ghost_mode_B.Sum_m > ghost_mode_P.PIDJMS0628_UpperSaturationLimit) {
    // Sum: '<S54>/SumI1'
    ghost_mode_B.Switch = ghost_mode_P.PIDJMS0628_UpperSaturationLimit;
  } else if (ghost_mode_B.Sum_m < ghost_mode_P.PIDJMS0628_LowerSaturationLimit)
  {
    // Sum: '<S54>/SumI1'
    ghost_mode_B.Switch = ghost_mode_P.PIDJMS0628_LowerSaturationLimit;
  } else {
    // Sum: '<S54>/SumI1'
    ghost_mode_B.Switch = ghost_mode_B.Sum_m;
  }

  // End of Saturate: '<S49>/Saturation'
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S97>/Proportional Gain'
    ghost_mode_B.ProportionalGain_e = ghost_mode_P.PIDJMS1_P * ghost_mode_B.Sum;

    // Gain: '<S86>/Derivative Gain'
    ghost_mode_B.DerivativeGain_b = ghost_mode_P.PIDJMS1_D * ghost_mode_B.Sum;
  }

  // Gain: '<S95>/Filter Coefficient' incorporates:
  //   Integrator: '<S87>/Filter'
  //   Sum: '<S87>/SumD'

  ghost_mode_B.FilterCoefficient_c = (ghost_mode_B.DerivativeGain_b -
    ghost_mode_X.Filter_CSTATE_f) * ghost_mode_P.PIDJMS1_N;

  // Sum: '<S101>/Sum' incorporates:
  //   Integrator: '<S92>/Integrator'

  rtb_Sum_c = (ghost_mode_B.ProportionalGain_e +
               ghost_mode_X.Integrator_CSTATE_i) +
    ghost_mode_B.FilterCoefficient_c;

  // Saturate: '<S99>/Saturation'
  if (rtb_Sum_c > ghost_mode_P.PIDJMS1_UpperSaturationLimit) {
    rtb_Saturation = ghost_mode_P.PIDJMS1_UpperSaturationLimit;
  } else if (rtb_Sum_c < ghost_mode_P.PIDJMS1_LowerSaturationLimit) {
    rtb_Saturation = ghost_mode_P.PIDJMS1_LowerSaturationLimit;
  } else {
    rtb_Saturation = rtb_Sum_c;
  }

  // End of Saturate: '<S99>/Saturation'

  // Switch: '<S2>/Switch'
  if (ghost_mode_B.Sum > ghost_mode_P.Switch_Threshold) {
    rtb_SignPreSat = ghost_mode_B.Switch;
  } else {
    rtb_SignPreSat = rtb_Saturation;
  }

  // End of Switch: '<S2>/Switch'

  // Saturate: '<Root>/Saturation'
  if (rtb_SignPreSat > ghost_mode_P.Saturation_UpperSat) {
    rtb_SignPreSat = ghost_mode_P.Saturation_UpperSat;
  } else if (rtb_SignPreSat < ghost_mode_P.Saturation_LowerSat) {
    rtb_SignPreSat = ghost_mode_P.Saturation_LowerSat;
  }

  // End of Saturate: '<Root>/Saturation'

  // BusAssignment: '<Root>/Bus Assignment'
  rtb_BusAssignment.Data = rtb_SignPreSat;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_ghost_mode_3.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S39>/Integral Gain'
    ghost_mode_B.IntegralGain = ghost_mode_P.PIDJMS0628_I * ghost_mode_B.Sum;
  }

  // Sum: '<S54>/SumI1' incorporates:
  //   Gain: '<S53>/Kt'
  //   Sum: '<S53>/SumI3'

  ghost_mode_B.Switch = (rtb_SignPreSat - ghost_mode_B.Switch) *
    ghost_mode_P.PIDJMS0628_Kt + ghost_mode_B.IntegralGain;

  // DeadZone: '<S35>/DeadZone'
  if (ghost_mode_B.Sum_m > ghost_mode_P.PIDJMS0628_UpperSaturationLimit) {
    rtb_DeadZone = ghost_mode_B.Sum_m -
      ghost_mode_P.PIDJMS0628_UpperSaturationLimit;
  } else if (ghost_mode_B.Sum_m >= ghost_mode_P.PIDJMS0628_LowerSaturationLimit)
  {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone = ghost_mode_B.Sum_m -
      ghost_mode_P.PIDJMS0628_LowerSaturationLimit;
  }

  // End of DeadZone: '<S35>/DeadZone'

  // Signum: '<S33>/SignPreSat'
  if (rtb_DeadZone < 0.0) {
    // DataTypeConversion: '<S33>/DataTypeConv1'
    tmp = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    // DataTypeConversion: '<S33>/DataTypeConv1'
    tmp = 1.0;
  } else if (rtb_DeadZone == 0.0) {
    // DataTypeConversion: '<S33>/DataTypeConv1'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S33>/DataTypeConv1'
    tmp = (rtNaN);
  }

  // End of Signum: '<S33>/SignPreSat'

  // DataTypeConversion: '<S33>/DataTypeConv1'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // Signum: '<S33>/SignPreIntegrator'
  if (ghost_mode_B.Switch < 0.0) {
    // DataTypeConversion: '<S33>/DataTypeConv2'
    tmp_0 = -1.0;
  } else if (ghost_mode_B.Switch > 0.0) {
    // DataTypeConversion: '<S33>/DataTypeConv2'
    tmp_0 = 1.0;
  } else if (ghost_mode_B.Switch == 0.0) {
    // DataTypeConversion: '<S33>/DataTypeConv2'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S33>/DataTypeConv2'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S33>/SignPreIntegrator'

  // DataTypeConversion: '<S33>/DataTypeConv2'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S33>/AND3' incorporates:
  //   DataTypeConversion: '<S33>/DataTypeConv1'
  //   DataTypeConversion: '<S33>/DataTypeConv2'
  //   Gain: '<S33>/ZeroGain'
  //   RelationalOperator: '<S33>/Equal1'
  //   RelationalOperator: '<S33>/NotEqual'

  ghost_mode_B.AND3 = ((ghost_mode_P.ZeroGain_Gain * ghost_mode_B.Sum_m !=
                        rtb_DeadZone) && ((tmp < 0.0 ? static_cast<int32_T>(
    static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
    static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp)))) ==
    (tmp_0 < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp_0)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp_0))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S33>/Memory'
    ghost_mode_B.Memory = ghost_mode_DW.Memory_PreviousInput;

    // Gain: '<S89>/Integral Gain'
    ghost_mode_B.IntegralGain_p = ghost_mode_P.PIDJMS1_I * ghost_mode_B.Sum;
  }

  // Switch: '<S33>/Switch'
  if (ghost_mode_B.Memory) {
    // Sum: '<S54>/SumI1' incorporates:
    //   Constant: '<S33>/Constant1'
    //   Switch: '<S33>/Switch'

    ghost_mode_B.Switch = ghost_mode_P.Constant1_Value;
  }

  // End of Switch: '<S33>/Switch'

  // Sum: '<S104>/SumI1' incorporates:
  //   Gain: '<S103>/Kt'
  //   Sum: '<S103>/SumI3'

  ghost_mode_B.Sum_m = (rtb_SignPreSat - rtb_Saturation) *
    ghost_mode_P.PIDJMS1_Kt + ghost_mode_B.IntegralGain_p;

  // DeadZone: '<S85>/DeadZone'
  if (rtb_Sum_c > ghost_mode_P.PIDJMS1_UpperSaturationLimit) {
    rtb_DeadZone = rtb_Sum_c - ghost_mode_P.PIDJMS1_UpperSaturationLimit;
  } else if (rtb_Sum_c >= ghost_mode_P.PIDJMS1_LowerSaturationLimit) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone = rtb_Sum_c - ghost_mode_P.PIDJMS1_LowerSaturationLimit;
  }

  // End of DeadZone: '<S85>/DeadZone'

  // Signum: '<S83>/SignPreSat'
  if (rtb_DeadZone < 0.0) {
    // DataTypeConversion: '<S83>/DataTypeConv1'
    tmp = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    // DataTypeConversion: '<S83>/DataTypeConv1'
    tmp = 1.0;
  } else if (rtb_DeadZone == 0.0) {
    // DataTypeConversion: '<S83>/DataTypeConv1'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S83>/DataTypeConv1'
    tmp = (rtNaN);
  }

  // End of Signum: '<S83>/SignPreSat'

  // DataTypeConversion: '<S83>/DataTypeConv1'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // Signum: '<S83>/SignPreIntegrator'
  if (ghost_mode_B.Sum_m < 0.0) {
    // DataTypeConversion: '<S83>/DataTypeConv2'
    tmp_0 = -1.0;
  } else if (ghost_mode_B.Sum_m > 0.0) {
    // DataTypeConversion: '<S83>/DataTypeConv2'
    tmp_0 = 1.0;
  } else if (ghost_mode_B.Sum_m == 0.0) {
    // DataTypeConversion: '<S83>/DataTypeConv2'
    tmp_0 = 0.0;
  } else {
    // DataTypeConversion: '<S83>/DataTypeConv2'
    tmp_0 = (rtNaN);
  }

  // End of Signum: '<S83>/SignPreIntegrator'

  // DataTypeConversion: '<S83>/DataTypeConv2'
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  // Logic: '<S83>/AND3' incorporates:
  //   DataTypeConversion: '<S83>/DataTypeConv1'
  //   DataTypeConversion: '<S83>/DataTypeConv2'
  //   Gain: '<S83>/ZeroGain'
  //   RelationalOperator: '<S83>/Equal1'
  //   RelationalOperator: '<S83>/NotEqual'

  ghost_mode_B.AND3_h = ((ghost_mode_P.ZeroGain_Gain_i * rtb_Sum_c !=
    rtb_DeadZone) && ((tmp < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-
    static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(
    static_cast<int8_T>(static_cast<uint8_T>(tmp)))) == (tmp_0 < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
    uint8_T>(-tmp_0)))) : static_cast<int32_T>(static_cast<int8_T>
    (static_cast<uint8_T>(tmp_0))))));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Memory: '<S83>/Memory'
    ghost_mode_B.Memory_g = ghost_mode_DW.Memory_PreviousInput_j;

    // Switch: '<S133>/Switch' incorporates:
    //   Memory: '<S133>/Memory'

    if (ghost_mode_DW.Memory_PreviousInput_n) {
      // Switch: '<S133>/Switch' incorporates:
      //   Constant: '<S133>/Constant1'

      ghost_mode_B.Switch_j = ghost_mode_P.Constant1_Value_p;
    } else {
      // Switch: '<S133>/Switch' incorporates:
      //   Gain: '<S139>/Integral Gain'

      ghost_mode_B.Switch_j = ghost_mode_P.PIDJMS0628_I_m * 0.0;
    }

    // End of Switch: '<S133>/Switch'

    // DataTypeConversion: '<S133>/DataTypeConv2'
    ghost_mode_B.DataTypeConv2 = 0;

    // Gain: '<S147>/Proportional Gain'
    ghost_mode_B.ProportionalGain_f = ghost_mode_P.PIDJMS0628_P_a * 0.0;

    // Gain: '<S136>/Derivative Gain'
    ghost_mode_B.DerivativeGain_e = ghost_mode_P.PIDJMS0628_D_e * 0.0;
  }

  // Switch: '<S83>/Switch'
  if (ghost_mode_B.Memory_g) {
    // Switch: '<S83>/Switch' incorporates:
    //   Constant: '<S83>/Constant1'

    ghost_mode_B.Switch_l = ghost_mode_P.Constant1_Value_a;
  } else {
    // Switch: '<S83>/Switch'
    ghost_mode_B.Switch_l = ghost_mode_B.Sum_m;
  }

  // End of Switch: '<S83>/Switch'

  // Gain: '<S145>/Filter Coefficient' incorporates:
  //   Integrator: '<S137>/Filter'
  //   Sum: '<S137>/SumD'

  ghost_mode_B.FilterCoefficient_p = (ghost_mode_B.DerivativeGain_e -
    ghost_mode_X.Filter_CSTATE_d) * ghost_mode_P.PIDJMS0628_N_f;

  // Sum: '<S151>/Sum' incorporates:
  //   Integrator: '<S142>/Integrator'

  ghost_mode_B.Sum_m = (ghost_mode_B.ProportionalGain_f +
                        ghost_mode_X.Integrator_CSTATE_f) +
    ghost_mode_B.FilterCoefficient_p;

  // DeadZone: '<S135>/DeadZone'
  if (ghost_mode_B.Sum_m > ghost_mode_P.PIDJMS0628_UpperSaturationLim_p) {
    rtb_DeadZone = ghost_mode_B.Sum_m -
      ghost_mode_P.PIDJMS0628_UpperSaturationLim_p;
  } else if (ghost_mode_B.Sum_m >= ghost_mode_P.PIDJMS0628_LowerSaturationLim_l)
  {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone = ghost_mode_B.Sum_m -
      ghost_mode_P.PIDJMS0628_LowerSaturationLim_l;
  }

  // End of DeadZone: '<S135>/DeadZone'

  // Signum: '<S133>/SignPreSat'
  if (rtb_DeadZone < 0.0) {
    // DataTypeConversion: '<S133>/DataTypeConv1'
    tmp = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    // DataTypeConversion: '<S133>/DataTypeConv1'
    tmp = 1.0;
  } else if (rtb_DeadZone == 0.0) {
    // DataTypeConversion: '<S133>/DataTypeConv1'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S133>/DataTypeConv1'
    tmp = (rtNaN);
  }

  // End of Signum: '<S133>/SignPreSat'

  // DataTypeConversion: '<S133>/DataTypeConv1'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // Logic: '<S133>/AND3' incorporates:
  //   DataTypeConversion: '<S133>/DataTypeConv1'
  //   Gain: '<S133>/ZeroGain'
  //   RelationalOperator: '<S133>/Equal1'
  //   RelationalOperator: '<S133>/NotEqual'

  ghost_mode_B.AND3_e = ((ghost_mode_P.ZeroGain_Gain_j * ghost_mode_B.Sum_m !=
    rtb_DeadZone) && ((tmp < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-
    static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(
    static_cast<int8_T>(static_cast<uint8_T>(tmp)))) ==
                      ghost_mode_B.DataTypeConv2));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    if (rtmIsMajorTimeStep(ghost_mode_M)) {
      // Update for Memory: '<S33>/Memory'
      ghost_mode_DW.Memory_PreviousInput = ghost_mode_B.AND3;

      // Update for Memory: '<S83>/Memory'
      ghost_mode_DW.Memory_PreviousInput_j = ghost_mode_B.AND3_h;

      // Update for Memory: '<S133>/Memory'
      ghost_mode_DW.Memory_PreviousInput_n = ghost_mode_B.AND3_e;
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

  // Derivatives for Integrator: '<S42>/Integrator'
  _rtXdot->Integrator_CSTATE = ghost_mode_B.Switch;

  // Derivatives for Integrator: '<S37>/Filter'
  _rtXdot->Filter_CSTATE = ghost_mode_B.FilterCoefficient;

  // Derivatives for Integrator: '<S92>/Integrator'
  _rtXdot->Integrator_CSTATE_i = ghost_mode_B.Switch_l;

  // Derivatives for Integrator: '<S87>/Filter'
  _rtXdot->Filter_CSTATE_f = ghost_mode_B.FilterCoefficient_c;

  // Derivatives for Integrator: '<S142>/Integrator'
  _rtXdot->Integrator_CSTATE_f = ghost_mode_B.Switch_j;

  // Derivatives for Integrator: '<S137>/Filter'
  _rtXdot->Filter_CSTATE_d = ghost_mode_B.FilterCoefficient_p;
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
    char_T b_zeroDelimTopic_0[13];
    static const char_T tmp[18] = { '/', 'g', 'h', 'o', 's', 't', '/', 'v', 'e',
      'h', 'i', 'c', 'l', 'e', '/', 'v', 'e', 'l' };

    static const char_T tmp_0[12] = { '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_1[12] = { '/', 't', 'i', 'm', 'e', 'd', '_', 'a',
      'c', 'c', 'e', 'l' };

    // InitializeConditions for Integrator: '<S42>/Integrator'
    ghost_mode_X.Integrator_CSTATE =
      ghost_mode_P.PIDJMS0628_InitialConditionForI;

    // InitializeConditions for Integrator: '<S37>/Filter'
    ghost_mode_X.Filter_CSTATE = ghost_mode_P.PIDJMS0628_InitialConditionForF;

    // InitializeConditions for Integrator: '<S92>/Integrator'
    ghost_mode_X.Integrator_CSTATE_i =
      ghost_mode_P.PIDJMS1_InitialConditionForInte;

    // InitializeConditions for Integrator: '<S87>/Filter'
    ghost_mode_X.Filter_CSTATE_f = ghost_mode_P.PIDJMS1_InitialConditionForFilt;

    // InitializeConditions for Memory: '<S33>/Memory'
    ghost_mode_DW.Memory_PreviousInput = ghost_mode_P.Memory_InitialCondition;

    // InitializeConditions for Memory: '<S83>/Memory'
    ghost_mode_DW.Memory_PreviousInput_j =
      ghost_mode_P.Memory_InitialCondition_c;

    // InitializeConditions for Memory: '<S133>/Memory'
    ghost_mode_DW.Memory_PreviousInput_n =
      ghost_mode_P.Memory_InitialCondition_p;

    // InitializeConditions for Integrator: '<S142>/Integrator'
    ghost_mode_X.Integrator_CSTATE_f =
      ghost_mode_P.PIDJMS0628_InitialConditionFo_l;

    // InitializeConditions for Integrator: '<S137>/Filter'
    ghost_mode_X.Filter_CSTATE_d = ghost_mode_P.PIDJMS0628_InitialConditionFo_d;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S160>/Out1' incorporates:
    //   Inport: '<S160>/In1'

    ghost_mode_B.In1 = ghost_mode_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    ghost_mode_DW.obj_g.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[18] = '\x00';
    Sub_ghost_mode_31.createSubscriber(&b_zeroDelimTopic[0], 1);
    ghost_mode_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S159>/Out1' incorporates:
    //   Inport: '<S159>/In1'

    ghost_mode_B.In1_d = ghost_mode_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    ghost_mode_DW.obj_n.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Sub_ghost_mode_10.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ghost_mode_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    ghost_mode_DW.obj.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_1[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Pub_ghost_mode_3.createPublisher(&b_zeroDelimTopic_0[0], 1);
    ghost_mode_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void ghost_mode_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!ghost_mode_DW.obj_g.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!ghost_mode_DW.obj_n.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!ghost_mode_DW.obj.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
