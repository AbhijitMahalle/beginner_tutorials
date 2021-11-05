/**
 * @file ros_subscriber.hpp
 * @author Abhijit Mahalle
 * @brief Class to subscribe to a message
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SRC_BEGINNER_TUTORIALS_INCLUDE_BEGINNER_TUTORIALS_ROS_SUBSCRIBER_HPP_
#define SRC_BEGINNER_TUTORIALS_INCLUDE_BEGINNER_TUTORIALS_ROS_SUBSCRIBER_HPP_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <string>

/**
 * @brief Class to publish message
 */
class ROSSubscriber {
 public:
  /**
  * @brief Constructor to create a new object
  * 
  * @param ros_node_h 
  */
  explicit ROSSubscriber(ros::NodeHandle ros_node_h);

  /**
   * @brief Destructor for the class object
   * 
   */
  virtual ~ROSSubscriber();

  /**
   * @brief Method to run the publisher node
   * 
   */
  virtual void run_subscriber();

 private:
  /**
   * Method that is the main access point in the ROS node.
   */
  ros::NodeHandle ros_node_h;
  ros::Subscriber chatter_sub;

  /**
   * @brief callback method for the subscriber
   * 
   * @param msg message read by the subsriber
   */
  void chatter_call_back(const std_msgs::String::ConstPtr& msg);
};

#endif  // SRC_BEGINNER_TUTORIALS_INCLUDE_BEGINNER_TUTORIALS_ROS_SUBSCRIBER_HPP_