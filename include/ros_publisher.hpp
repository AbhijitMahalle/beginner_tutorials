/**
* @file ros_publisher.hpp
* @author Abhijit Mahalle
* @brief Class to publish message 
* @version 0.1
* @date 2021-11-01
* 
* @copyright Copyright (c) 2021
* 
*/

#ifndef SRC_BEGINNER_TUTORIALS_INCLUDE_BEGINNER_TUTORIALS_ROS_PUBLISHER_HPP_
#define SRC_BEGINNER_TUTORIALS_INCLUDE_BEGINNER_TUTORIALS_ROS_PUBLISHER_HPP_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <string>

/**
 * @brief Class to publish message
 * 
 */
class ROSPublisher {
 public:
  /**
  * @brief Constructor to create a new object
  * 
  * @param ros_node_h 
  */
  explicit ROSPublisher(ros::NodeHandle ros_node_h);

  /**
   * @brief Destructor for the object
   * 
   */
  virtual ~ROSPublisher();

  /**
   * @brief Method to publish node
   * 
   */
  virtual void run_publisher();

 private:
  /**
   * Method that is the main access point in the ROS node.
   */
  ros::NodeHandle ros_node_h;
  ros::Publisher chatter_pub;
  ros::ServiceClient add_svc_client;

  /**
   * @brief method to call the service
   * 
   * @param a 
   * @param b 
   * @return std::string modified string to be published
   */
  std::string call_service(int a, int b);
};

#endif  // SRC_BEGINNER_TUTORIALS_INCLUDE_BEGINNER_TUTORIALS_ROS_PUBLISHER_HPP_
