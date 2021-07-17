#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block mpc_ros/Subscribe
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_mpc_ros_geometry_msgs_TwistStamped> Sub_mpc_ros_62;

// For Block mpc_ros/Subscribe1
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_mpc_ros_geometry_msgs_TwistStamped> Sub_mpc_ros_56;

// For Block mpc_ros/Subscribe2
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_mpc_ros_geometry_msgs_TwistStamped> Sub_mpc_ros_64;

// For Block mpc_ros/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_mpc_ros_std_msgs_Float64> Pub_mpc_ros_60;

void slros_node_init(int argc, char** argv);

#endif
