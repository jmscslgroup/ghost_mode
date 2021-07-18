#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ghost_mode/Subscribe2
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_83;

// For Block ghost_mode/Subscribe3
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_84;

// For Block ghost_mode/Subscribe4
extern SimulinkSubscriber<geometry_msgs::AccelStamped, SL_Bus_ghost_mode_geometry_msgs_AccelStamped> Sub_ghost_mode_85;

// For Block ghost_mode/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ghost_mode_std_msgs_Float64> Pub_ghost_mode_82;

void slros_node_init(int argc, char** argv);

#endif
