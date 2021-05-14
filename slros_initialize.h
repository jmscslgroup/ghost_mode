#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ghost_mode/Subscribe
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_10;

// For Block ghost_mode/Subscribe1
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_31;

// For Block ghost_mode/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ghost_mode_std_msgs_Float64> Pub_ghost_mode_3;

void slros_node_init(int argc, char** argv);

#endif
