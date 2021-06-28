//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode.cpp
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.37
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 15:40:49 2021
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
  int_T nXc = 4;
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
  real_T rtb_IntegralGain;
  real_T rtb_SignPreIntegrator;
  real_T rtb_SignPreSat;
  real_T rtb_SignPreSat_b;
  real_T rtb_ZeroGain;
  real_T u0;
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
    // MATLABSystem: '<S5>/SourceBlock' incorporates:
    //   Inport: '<S109>/In1'

    b_varargout_1 = Sub_ghost_mode_31.getLatestMessage
      (&ghost_mode_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S109>/Enable'

    if (b_varargout_1) {
      ghost_mode_B.In1 = ghost_mode_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   Inport: '<S108>/In1'

    b_varargout_1 = Sub_ghost_mode_10.getLatestMessage
      (&ghost_mode_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S108>/Enable'

    if (b_varargout_1) {
      ghost_mode_B.In1_d = ghost_mode_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Sum: '<Root>/Sum'
    ghost_mode_B.Sum = ghost_mode_B.In1.Twist.Linear.X -
      ghost_mode_B.In1_d.Twist.Linear.X;

    // Gain: '<S96>/Proportional Gain'
    ghost_mode_B.ProportionalGain = ghost_mode_P.SpeedupsteadystateController_P *
      ghost_mode_B.Sum;

    // Gain: '<S85>/Derivative Gain'
    ghost_mode_B.DerivativeGain = ghost_mode_P.SpeedupsteadystateController_D *
      ghost_mode_B.Sum;

    // Gain: '<S46>/Proportional Gain'
    ghost_mode_B.ProportionalGain_c = ghost_mode_P.SlowdownController_P *
      ghost_mode_B.Sum;

    // Gain: '<S35>/Derivative Gain'
    ghost_mode_B.DerivativeGain_f = ghost_mode_P.SlowdownController_D *
      ghost_mode_B.Sum;
  }

  // Gain: '<S94>/Filter Coefficient' incorporates:
  //   Integrator: '<S86>/Filter'
  //   Sum: '<S86>/SumD'

  ghost_mode_B.FilterCoefficient = (ghost_mode_B.DerivativeGain -
    ghost_mode_X.Filter_CSTATE) * ghost_mode_P.SpeedupsteadystateController_N;

  // Sum: '<S100>/Sum' incorporates:
  //   Integrator: '<S91>/Integrator'

  rtb_SignPreSat = (ghost_mode_B.ProportionalGain +
                    ghost_mode_X.Integrator_CSTATE) +
    ghost_mode_B.FilterCoefficient;

  // Gain: '<S44>/Filter Coefficient' incorporates:
  //   Integrator: '<S36>/Filter'
  //   Sum: '<S36>/SumD'

  ghost_mode_B.FilterCoefficient_a = (ghost_mode_B.DerivativeGain_f -
    ghost_mode_X.Filter_CSTATE_n) * ghost_mode_P.SlowdownController_N;

  // Sum: '<S50>/Sum' incorporates:
  //   Integrator: '<S41>/Integrator'

  rtb_SignPreSat_b = (ghost_mode_B.ProportionalGain_c +
                      ghost_mode_X.Integrator_CSTATE_m) +
    ghost_mode_B.FilterCoefficient_a;

  // Switch: '<S2>/Switch' incorporates:
  //   Saturate: '<S48>/Saturation'

  if (ghost_mode_B.Sum > ghost_mode_P.Switch_Threshold) {
    // Saturate: '<S98>/Saturation'
    if (rtb_SignPreSat > ghost_mode_P.SpeedupsteadystateController_Up) {
      u0 = ghost_mode_P.SpeedupsteadystateController_Up;
    } else if (rtb_SignPreSat < ghost_mode_P.SpeedupsteadystateController_Lo) {
      u0 = ghost_mode_P.SpeedupsteadystateController_Lo;
    } else {
      u0 = rtb_SignPreSat;
    }

    // End of Saturate: '<S98>/Saturation'
  } else if (rtb_SignPreSat_b > ghost_mode_P.SlowdownController_UpperSaturat) {
    // Saturate: '<S48>/Saturation'
    u0 = ghost_mode_P.SlowdownController_UpperSaturat;
  } else if (rtb_SignPreSat_b < ghost_mode_P.SlowdownController_LowerSaturat) {
    // Saturate: '<S48>/Saturation'
    u0 = ghost_mode_P.SlowdownController_LowerSaturat;
  } else {
    // Saturate: '<S48>/Saturation'
    u0 = rtb_SignPreSat_b;
  }

  // End of Switch: '<S2>/Switch'

  // Saturate: '<Root>/Saturation'
  if (u0 > ghost_mode_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = ghost_mode_P.Saturation_UpperSat;
  } else if (u0 < ghost_mode_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = ghost_mode_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = u0;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_ghost_mode_3.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Gain: '<S32>/ZeroGain'
  rtb_ZeroGain = ghost_mode_P.ZeroGain_Gain * rtb_SignPreSat_b;

  // DeadZone: '<S34>/DeadZone'
  if (rtb_SignPreSat_b > ghost_mode_P.SlowdownController_UpperSaturat) {
    rtb_SignPreSat_b -= ghost_mode_P.SlowdownController_UpperSaturat;
  } else if (rtb_SignPreSat_b >= ghost_mode_P.SlowdownController_LowerSaturat) {
    rtb_SignPreSat_b = 0.0;
  } else {
    rtb_SignPreSat_b -= ghost_mode_P.SlowdownController_LowerSaturat;
  }

  // End of DeadZone: '<S34>/DeadZone'
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S38>/Integral Gain'
    rtb_SignPreIntegrator = ghost_mode_P.SlowdownController_I * ghost_mode_B.Sum;

    // Signum: '<S32>/SignPreIntegrator'
    if (rtb_SignPreIntegrator < 0.0) {
      rtb_IntegralGain = -1.0;
    } else if (rtb_SignPreIntegrator > 0.0) {
      rtb_IntegralGain = 1.0;
    } else if (rtb_SignPreIntegrator == 0.0) {
      rtb_IntegralGain = 0.0;
    } else {
      rtb_IntegralGain = (rtNaN);
    }

    // End of Signum: '<S32>/SignPreIntegrator'

    // DataTypeConversion: '<S32>/DataTypeConv2'
    if (rtIsNaN(rtb_IntegralGain)) {
      u0 = 0.0;
    } else {
      u0 = fmod(rtb_IntegralGain, 256.0);
    }

    // DataTypeConversion: '<S32>/DataTypeConv2'
    ghost_mode_B.DataTypeConv2 = static_cast<int8_T>(u0 < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-u0)))) : static_cast<int32_T>(static_cast<int8_T>
      (static_cast<uint8_T>(u0))));
  }

  // Signum: '<S32>/SignPreSat'
  if (rtb_SignPreSat_b < 0.0) {
    // DataTypeConversion: '<S32>/DataTypeConv1'
    u0 = -1.0;
  } else if (rtb_SignPreSat_b > 0.0) {
    // DataTypeConversion: '<S32>/DataTypeConv1'
    u0 = 1.0;
  } else if (rtb_SignPreSat_b == 0.0) {
    // DataTypeConversion: '<S32>/DataTypeConv1'
    u0 = 0.0;
  } else {
    // DataTypeConversion: '<S32>/DataTypeConv1'
    u0 = (rtNaN);
  }

  // End of Signum: '<S32>/SignPreSat'

  // DataTypeConversion: '<S32>/DataTypeConv1'
  if (rtIsNaN(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 256.0);
  }

  // Logic: '<S32>/AND3' incorporates:
  //   DataTypeConversion: '<S32>/DataTypeConv1'
  //   RelationalOperator: '<S32>/Equal1'
  //   RelationalOperator: '<S32>/NotEqual'

  ghost_mode_B.AND3 = ((rtb_ZeroGain != rtb_SignPreSat_b) && ((u0 < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-u0)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(u0)))) == ghost_mode_B.DataTypeConv2));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Switch: '<S32>/Switch' incorporates:
    //   Memory: '<S32>/Memory'

    if (ghost_mode_DW.Memory_PreviousInput) {
      // Switch: '<S32>/Switch' incorporates:
      //   Constant: '<S32>/Constant1'

      ghost_mode_B.Switch = ghost_mode_P.Constant1_Value;
    } else {
      // Switch: '<S32>/Switch'
      ghost_mode_B.Switch = rtb_SignPreIntegrator;
    }

    // End of Switch: '<S32>/Switch'
  }

  // Gain: '<S82>/ZeroGain'
  rtb_SignPreSat_b = ghost_mode_P.ZeroGain_Gain_a * rtb_SignPreSat;

  // DeadZone: '<S84>/DeadZone'
  if (rtb_SignPreSat > ghost_mode_P.SpeedupsteadystateController_Up) {
    rtb_SignPreSat -= ghost_mode_P.SpeedupsteadystateController_Up;
  } else if (rtb_SignPreSat >= ghost_mode_P.SpeedupsteadystateController_Lo) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat -= ghost_mode_P.SpeedupsteadystateController_Lo;
  }

  // End of DeadZone: '<S84>/DeadZone'
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Gain: '<S88>/Integral Gain'
    rtb_IntegralGain = ghost_mode_P.SpeedupsteadystateController_I *
      ghost_mode_B.Sum;

    // Signum: '<S82>/SignPreIntegrator'
    if (rtb_IntegralGain < 0.0) {
      // DataTypeConversion: '<S82>/DataTypeConv2'
      u0 = -1.0;
    } else if (rtb_IntegralGain > 0.0) {
      // DataTypeConversion: '<S82>/DataTypeConv2'
      u0 = 1.0;
    } else if (rtb_IntegralGain == 0.0) {
      // DataTypeConversion: '<S82>/DataTypeConv2'
      u0 = 0.0;
    } else {
      // DataTypeConversion: '<S82>/DataTypeConv2'
      u0 = (rtNaN);
    }

    // End of Signum: '<S82>/SignPreIntegrator'

    // DataTypeConversion: '<S82>/DataTypeConv2'
    if (rtIsNaN(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 256.0);
    }

    // DataTypeConversion: '<S82>/DataTypeConv2'
    ghost_mode_B.DataTypeConv2_b = static_cast<int8_T>(u0 < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-u0)))) : static_cast<int32_T>(static_cast<int8_T>
      (static_cast<uint8_T>(u0))));
  }

  // Signum: '<S82>/SignPreSat'
  if (rtb_SignPreSat < 0.0) {
    // DataTypeConversion: '<S82>/DataTypeConv1'
    u0 = -1.0;
  } else if (rtb_SignPreSat > 0.0) {
    // DataTypeConversion: '<S82>/DataTypeConv1'
    u0 = 1.0;
  } else if (rtb_SignPreSat == 0.0) {
    // DataTypeConversion: '<S82>/DataTypeConv1'
    u0 = 0.0;
  } else {
    // DataTypeConversion: '<S82>/DataTypeConv1'
    u0 = (rtNaN);
  }

  // End of Signum: '<S82>/SignPreSat'

  // DataTypeConversion: '<S82>/DataTypeConv1'
  if (rtIsNaN(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 256.0);
  }

  // Logic: '<S82>/AND3' incorporates:
  //   DataTypeConversion: '<S82>/DataTypeConv1'
  //   RelationalOperator: '<S82>/Equal1'
  //   RelationalOperator: '<S82>/NotEqual'

  ghost_mode_B.AND3_g = ((rtb_SignPreSat_b != rtb_SignPreSat) && ((u0 < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
    uint8_T>(-u0)))) : static_cast<int32_T>(static_cast<int8_T>
    (static_cast<uint8_T>(u0)))) == ghost_mode_B.DataTypeConv2_b));
  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    // Switch: '<S82>/Switch' incorporates:
    //   Memory: '<S82>/Memory'

    if (ghost_mode_DW.Memory_PreviousInput_m) {
      // Switch: '<S82>/Switch' incorporates:
      //   Constant: '<S82>/Constant1'

      ghost_mode_B.Switch_m = ghost_mode_P.Constant1_Value_c;
    } else {
      // Switch: '<S82>/Switch'
      ghost_mode_B.Switch_m = rtb_IntegralGain;
    }

    // End of Switch: '<S82>/Switch'
  }

  if (rtmIsMajorTimeStep(ghost_mode_M)) {
    if (rtmIsMajorTimeStep(ghost_mode_M)) {
      // Update for Memory: '<S32>/Memory'
      ghost_mode_DW.Memory_PreviousInput = ghost_mode_B.AND3;

      // Update for Memory: '<S82>/Memory'
      ghost_mode_DW.Memory_PreviousInput_m = ghost_mode_B.AND3_g;
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

  // Derivatives for Integrator: '<S91>/Integrator'
  _rtXdot->Integrator_CSTATE = ghost_mode_B.Switch_m;

  // Derivatives for Integrator: '<S86>/Filter'
  _rtXdot->Filter_CSTATE = ghost_mode_B.FilterCoefficient;

  // Derivatives for Integrator: '<S41>/Integrator'
  _rtXdot->Integrator_CSTATE_m = ghost_mode_B.Switch;

  // Derivatives for Integrator: '<S36>/Filter'
  _rtXdot->Filter_CSTATE_n = ghost_mode_B.FilterCoefficient_a;
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

    // InitializeConditions for Integrator: '<S91>/Integrator'
    ghost_mode_X.Integrator_CSTATE =
      ghost_mode_P.SpeedupsteadystateController__m;

    // InitializeConditions for Integrator: '<S86>/Filter'
    ghost_mode_X.Filter_CSTATE = ghost_mode_P.SpeedupsteadystateController_In;

    // InitializeConditions for Integrator: '<S41>/Integrator'
    ghost_mode_X.Integrator_CSTATE_m =
      ghost_mode_P.SlowdownController_InitialCon_p;

    // InitializeConditions for Integrator: '<S36>/Filter'
    ghost_mode_X.Filter_CSTATE_n = ghost_mode_P.SlowdownController_InitialCondi;

    // InitializeConditions for Memory: '<S32>/Memory'
    ghost_mode_DW.Memory_PreviousInput = ghost_mode_P.Memory_InitialCondition;

    // InitializeConditions for Memory: '<S82>/Memory'
    ghost_mode_DW.Memory_PreviousInput_m =
      ghost_mode_P.Memory_InitialCondition_f;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S109>/Out1' incorporates:
    //   Inport: '<S109>/In1'

    ghost_mode_B.In1 = ghost_mode_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    ghost_mode_DW.obj_g.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[18] = '\x00';
    Sub_ghost_mode_31.createSubscriber(&b_zeroDelimTopic[0], 1);
    ghost_mode_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S108>/Out1' incorporates:
    //   Inport: '<S108>/In1'

    ghost_mode_B.In1_d = ghost_mode_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    ghost_mode_DW.obj_n.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Sub_ghost_mode_10.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ghost_mode_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    ghost_mode_DW.obj.matlabCodegenIsDeleted = false;
    ghost_mode_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_1[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Pub_ghost_mode_3.createPublisher(&b_zeroDelimTopic_0[0], 1);
    ghost_mode_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void ghost_mode_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!ghost_mode_DW.obj_g.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!ghost_mode_DW.obj_n.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!ghost_mode_DW.obj.matlabCodegenIsDeleted) {
    ghost_mode_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
