//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_mode_data.cpp
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

// Block parameters (default storage)
P_ghost_mode_T ghost_mode_P = {
  // Mask Parameter: PIDJMS1_D
  //  Referenced by: '<S344>/Derivative Gain'

  3.14341534728212,

  // Mask Parameter: PIDJMS0628_D
  //  Referenced by: '<S39>/Derivative Gain'

  3.14341534728212,

  // Mask Parameter: PIDJMS1_D_e
  //  Referenced by: '<S89>/Derivative Gain'

  1.88738640383327,

  // Mask Parameter: PIDJMS0628_D_l
  //  Referenced by: '<S141>/Derivative Gain'

  1.2886782091662,

  // Mask Parameter: PIDJMS1_D_c
  //  Referenced by: '<S191>/Derivative Gain'

  1.57587015982106,

  // Mask Parameter: PIDJMS0628_D_g
  //  Referenced by: '<S244>/Derivative Gain'

  1.2886782091662,

  // Mask Parameter: PIDJMS1_D_cd
  //  Referenced by: '<S294>/Derivative Gain'

  1.57587015982106,

  // Mask Parameter: PIDJMS1_I
  //  Referenced by: '<S347>/Integral Gain'

  2.84227057543051,

  // Mask Parameter: PIDJMS0628_I
  //  Referenced by: '<S42>/Integral Gain'

  2.84227057543051,

  // Mask Parameter: PIDJMS1_I_g
  //  Referenced by: '<S92>/Integral Gain'

  0.312565419373226,

  // Mask Parameter: PIDJMS0628_I_n
  //  Referenced by: '<S144>/Integral Gain'

  0.561856950087048,

  // Mask Parameter: PIDJMS1_I_h
  //  Referenced by: '<S194>/Integral Gain'

  0.207355055407799,

  // Mask Parameter: PIDJMS0628_I_c
  //  Referenced by: '<S247>/Integral Gain'

  0.561856950087048,

  // Mask Parameter: PIDJMS1_I_hb
  //  Referenced by: '<S297>/Integral Gain'

  0.207355055407799,

  // Mask Parameter: PIDJMS1_InitialConditionForFilt
  //  Referenced by: '<S345>/Filter'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionForF
  //  Referenced by: '<S40>/Filter'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForFi_m
  //  Referenced by: '<S90>/Filter'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionFo_g
  //  Referenced by: '<S142>/Filter'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForFi_e
  //  Referenced by: '<S192>/Filter'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionFo_l
  //  Referenced by: '<S245>/Filter'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForFi_n
  //  Referenced by: '<S295>/Filter'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForInte
  //  Referenced by: '<S350>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionForI
  //  Referenced by: '<S45>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForIn_k
  //  Referenced by: '<S95>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionFo_f
  //  Referenced by: '<S147>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForIn_m
  //  Referenced by: '<S197>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS0628_InitialConditionFo_d
  //  Referenced by: '<S250>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS1_InitialConditionForIn_g
  //  Referenced by: '<S300>/Integrator'

  0.0,

  // Mask Parameter: PIDJMS1_Kt
  //  Referenced by: '<S361>/Kt'

  1.0,

  // Mask Parameter: PIDJMS0628_Kt
  //  Referenced by: '<S56>/Kt'

  1.0,

  // Mask Parameter: PIDJMS1_Kt_d
  //  Referenced by: '<S106>/Kt'

  1.0,

  // Mask Parameter: PIDJMS0628_Kt_b
  //  Referenced by: '<S158>/Kt'

  1.0,

  // Mask Parameter: PIDJMS1_Kt_dq
  //  Referenced by: '<S208>/Kt'

  1.0,

  // Mask Parameter: PIDJMS0628_Kt_j
  //  Referenced by: '<S261>/Kt'

  1.0,

  // Mask Parameter: PIDJMS1_Kt_i
  //  Referenced by: '<S311>/Kt'

  1.0,

  // Mask Parameter: PIDJMS1_LowerSaturationLimit
  //  Referenced by:
  //    '<S357>/Saturation'
  //    '<S343>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS0628_LowerSaturationLimit
  //  Referenced by:
  //    '<S52>/Saturation'
  //    '<S38>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS1_LowerSaturationLimit_k
  //  Referenced by:
  //    '<S102>/Saturation'
  //    '<S88>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS0628_LowerSaturationLim_k
  //  Referenced by:
  //    '<S154>/Saturation'
  //    '<S140>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS1_LowerSaturationLimit_l
  //  Referenced by:
  //    '<S204>/Saturation'
  //    '<S190>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS0628_LowerSaturationLi_km
  //  Referenced by:
  //    '<S257>/Saturation'
  //    '<S243>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS1_LowerSaturationLimit_f
  //  Referenced by:
  //    '<S307>/Saturation'
  //    '<S293>/DeadZone'

  -3.0,

  // Mask Parameter: PIDJMS1_N
  //  Referenced by: '<S353>/Filter Coefficient'

  635.975413708926,

  // Mask Parameter: PIDJMS0628_N
  //  Referenced by: '<S48>/Filter Coefficient'

  635.975413708926,

  // Mask Parameter: PIDJMS1_N_n
  //  Referenced by: '<S98>/Filter Coefficient'

  2.74868113749563,

  // Mask Parameter: PIDJMS0628_N_j
  //  Referenced by: '<S150>/Filter Coefficient'

  24.3345419624922,

  // Mask Parameter: PIDJMS1_N_nk
  //  Referenced by: '<S200>/Filter Coefficient'

  229.860845567849,

  // Mask Parameter: PIDJMS0628_N_f
  //  Referenced by: '<S253>/Filter Coefficient'

  24.3345419624922,

  // Mask Parameter: PIDJMS1_N_m
  //  Referenced by: '<S303>/Filter Coefficient'

  229.860845567849,

  // Mask Parameter: PIDJMS1_P
  //  Referenced by: '<S355>/Proportional Gain'

  7.02660625936992,

  // Mask Parameter: PIDJMS0628_P
  //  Referenced by: '<S50>/Proportional Gain'

  7.02660625936992,

  // Mask Parameter: PIDJMS1_P_l
  //  Referenced by: '<S100>/Proportional Gain'

  1.68584510007809,

  // Mask Parameter: PIDJMS0628_P_b
  //  Referenced by: '<S152>/Proportional Gain'

  2.25627287381491,

  // Mask Parameter: PIDJMS1_P_a
  //  Referenced by: '<S202>/Proportional Gain'

  1.38383448768805,

  // Mask Parameter: PIDJMS0628_P_bi
  //  Referenced by: '<S255>/Proportional Gain'

  2.25627287381491,

  // Mask Parameter: PIDJMS1_P_f
  //  Referenced by: '<S305>/Proportional Gain'

  1.38383448768805,

  // Mask Parameter: PIDJMS1_UpperSaturationLimit
  //  Referenced by:
  //    '<S357>/Saturation'
  //    '<S343>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS0628_UpperSaturationLimit
  //  Referenced by:
  //    '<S52>/Saturation'
  //    '<S38>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS1_UpperSaturationLimit_e
  //  Referenced by:
  //    '<S102>/Saturation'
  //    '<S88>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS0628_UpperSaturationLim_p
  //  Referenced by:
  //    '<S154>/Saturation'
  //    '<S140>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS1_UpperSaturationLimit_n
  //  Referenced by:
  //    '<S204>/Saturation'
  //    '<S190>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS0628_UpperSaturationLim_l
  //  Referenced by:
  //    '<S257>/Saturation'
  //    '<S243>/DeadZone'

  1.5,

  // Mask Parameter: PIDJMS1_UpperSaturationLimit_b
  //  Referenced by:
  //    '<S307>/Saturation'
  //    '<S293>/DeadZone'

  1.5,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S369>/Out1'

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
    }                                  // Accel
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S9>/Constant'

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
    }                                  // Accel
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S367>/Out1'

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

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S7>/Constant'

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
  //  Referenced by: '<S368>/Out1'

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
  //  Referenced by: '<S8>/Constant'

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
  //  Referenced by: '<S341>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S36>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S86>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S138>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S188>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S241>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S291>/Constant1'

  0.0,

  // Expression: 1.5
  //  Referenced by: '<Root>/Saturation'

  1.5,

  // Expression: -3
  //  Referenced by: '<Root>/Saturation'

  -3.0,

  // Expression: 0
  //  Referenced by: '<S341>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S36>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S86>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S138>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S188>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S241>/ZeroGain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S291>/ZeroGain'

  0.0,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S341>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_p
  //  Referenced by: '<S36>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_j
  //  Referenced by: '<S86>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_g
  //  Referenced by: '<S138>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_d
  //  Referenced by: '<S188>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_gk
  //  Referenced by: '<S241>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_c
  //  Referenced by: '<S291>/Memory'

  0
};

//
// File trailer for generated code.
//
// [EOF]
//
