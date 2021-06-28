//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode_data.cpp
//
// Code generated for Simulink model 'ghost_mode'.
//
// Model version                  : 1.40
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Jun 28 16:03:32 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ghost_mode.h"
#include "ghost_mode_private.h"

// Block parameters (default storage)
P_ghost_mode_T ghost_mode_P = {
  // Mask Parameter: PIDJMS0628_D
  //  Referenced by: '<S36>/Derivative Gain'

  1.2886782091662,

  // Mask Parameter: PIDJMS1_D
  //  Referenced by: '<S86>/Derivative Gain'

  1.57587015982106,

  // Mask Parameter: PIDJMS0628_D_e
  //  Referenced by: '<S136>/Derivative Gain'

  1.2886782091662,

  // Mask Parameter: PIDJMS1_I
  //  Referenced by: '<S89>/Integral Gain'

  0.207355055407799,

  // Mask Parameter: PIDJMS0628_I
  //  Referenced by: '<S39>/Integral Gain'

  0.561856950087048,

  // Mask Parameter: PIDJMS0628_I_m
  //  Referenced by: '<S139>/Integral Gain'

  0.561856950087048,

  // Mask Parameter: PIDJMS0628_InitialConditionForF
  //  Referenced by: '<S37>/Filter'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForFilt
  //  Referenced by: '<S87>/Filter'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionFo_d
  //  Referenced by: '<S137>/Filter'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionForI
  //  Referenced by: '<S42>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForInte
  //  Referenced by: '<S92>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionFo_l
  //  Referenced by: '<S142>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS0628_LowerSaturationLimit
  //  Referenced by:
  //    '<S49>/Saturation'
  //    '<S35>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS1_LowerSaturationLimit
  //  Referenced by:
  //    '<S99>/Saturation'
  //    '<S85>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS0628_LowerSaturationLim_l
  //  Referenced by: '<S135>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS0628_N
  //  Referenced by: '<S45>/Filter Coefficient'

  24.3345419624922,

  // Mask Parameter: PIDJMS1_N
  //  Referenced by: '<S95>/Filter Coefficient'

  229.860845567849,

  // Mask Parameter: PIDJMS0628_N_f
  //  Referenced by: '<S145>/Filter Coefficient'

  24.3345419624922,

  // Mask Parameter: PIDJMS0628_P
  //  Referenced by: '<S47>/Proportional Gain'

  2.25627287381491,

  // Mask Parameter: PIDJMS1_P
  //  Referenced by: '<S97>/Proportional Gain'

  1.38383448768805,

  // Mask Parameter: PIDJMS0628_P_a
  //  Referenced by: '<S147>/Proportional Gain'

  2.25627287381491,

  // Mask Parameter: PIDJMS0628_UpperSaturationLimit
  //  Referenced by:
  //    '<S49>/Saturation'
  //    '<S35>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS1_UpperSaturationLimit
  //  Referenced by:
  //    '<S99>/Saturation'
  //    '<S85>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS0628_UpperSaturationLim_p
  //  Referenced by: '<S135>/DeadZone'

  1.5,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S159>/Out1'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    }                                  // Twist
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S5>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    }                                  // Twist
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S160>/Out1'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    }                                  // Twist
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S6>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    }                                  // Twist
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 0
  //  Referenced by: '<S33>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S83>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S133>/Constant1'

  0.0,

  // Expression: -0.25
  //  Referenced by: '<S2>/Switch'

  -0.25,

  // Expression: 1.5
  //  Referenced by: '<Root>/Saturation'

  1.5,

  // Expression: -3
  //  Referenced by: '<Root>/Saturation'

  -3.0,

  // Expression: 0
  //  Referenced by: '<S83>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S133>/ZeroGain'

  0.0,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S83>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_g
  //  Referenced by: '<S33>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_p
  //  Referenced by: '<S133>/Memory'

  0
};

//
// File trailer for generated code.
//
// [EOF]
//
