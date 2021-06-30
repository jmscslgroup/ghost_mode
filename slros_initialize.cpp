#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ghost_mode";

// For Block ghost_mode/Subscribe
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_10;

// For Block ghost_mode/Subscribe1
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_mode_geometry_msgs_TwistStamped> Sub_ghost_mode_31;

// For Block ghost_mode/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_ghost_mode_std_msgs_Float64> Pub_ghost_mode_3;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

