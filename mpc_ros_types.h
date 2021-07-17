//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpc_ros_types.h
//
// Code generated for Simulink model 'mpc_ros'.
//
// Model version                  : 2.3
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Jul 16 03:03:13 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_mpc_ros_types_h_
#define RTW_HEADER_mpc_ros_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_std_msgs_Float64_

// MsgType=std_msgs/Float64
struct SL_Bus_mpc_ros_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_mpc_ros_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_mpc_ros_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_mpc_ros_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_mpc_ros_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_mpc_ros_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_mpc_ros_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_mpc_ros_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_geometry_msgs_TwistStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_mpc_ros_geometry_msgs_TwistStamped_

// MsgType=geometry_msgs/TwistStamped
struct SL_Bus_mpc_ros_geometry_msgs_TwistStamped
{
  // MsgType=std_msgs/Header
  SL_Bus_mpc_ros_std_msgs_Header Header;

  // MsgType=geometry_msgs/Twist
  SL_Bus_mpc_ros_geometry_msgs_Twist Twist;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_
#define DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_

struct struct_qYRJtcce7MM7XuQ3AAWdMD
{
  real_T MaxIterations;
  real_T ConstraintTolerance;
  boolean_T UseWarmStart;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_
#define DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_

struct struct_SmvKLCDySlKdToNTroAGyF
{
  real_T MaxIterations;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T ComplementarityTolerance;
  real_T StepTolerance;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_aH4cViuPz8aZIf26PeppuD_
#define DEFINED_TYPEDEF_FOR_struct_aH4cViuPz8aZIf26PeppuD_

struct struct_aH4cViuPz8aZIf26PeppuD
{
  real_T MaxIterations;
  real_T ConstraintTolerance;
  real_T DiscreteConstraintTolerance;
  boolean_T RoundingAtRootNode;
  real_T MaxPendingNodes;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_mpc_ros_T_ P_mpc_ros_T;

// Forward declaration for rtModel
typedef struct tag_RTM_mpc_ros_T RT_MODEL_mpc_ros_T;

#endif                                 // RTW_HEADER_mpc_ros_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
