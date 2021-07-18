#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ghost_mode";

// For Block ghost_mode/Subscribe2
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_83;

// For Block ghost_mode/Subscribe3
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_84;

// For Block ghost_mode/Subscribe4
SimulinkSubscriber<geometry_msgs::AccelStamped, SL_Bus_ghost_mode_geometry_msgs_AccelStamped> Sub_ghost_mode_85;

// For Block ghost_mode/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_ghost_mode_std_msgs_Float64> Pub_ghost_mode_82;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

