#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "mpc_ros";

// For Block mpc_ros/Subscribe
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_mpc_ros_geometry_msgs_TwistStamped> Sub_mpc_ros_62;

// For Block mpc_ros/Subscribe1
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_mpc_ros_geometry_msgs_TwistStamped> Sub_mpc_ros_56;

// For Block mpc_ros/Subscribe2
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_mpc_ros_geometry_msgs_TwistStamped> Sub_mpc_ros_64;

// For Block mpc_ros/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_mpc_ros_std_msgs_Float64> Pub_mpc_ros_60;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

