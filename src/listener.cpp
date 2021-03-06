/**
* @file listener.cpp
* @author Abhijit mahalle (abhimah@umd.edu)
* @brief Node to listen to the given topic
* @version 0.1
* @date 2021-11-01
* @copyright Copyright (c) 2021
* 
*/

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <memory>
#include <beginner_tutorials/ros_subscriber.hpp>

int main(int argc, char** argv) {
  ros::init(argc, argv, "listener");
  ros::NodeHandle ros_node_h;
  ROS_WARN_STREAM("Hellooooo");
  std::unique_ptr<ROSSubscriber> ros_sub(new ROSSubscriber(ros_node_h));
  ros_sub->run_subscriber();
  return 0;
}
