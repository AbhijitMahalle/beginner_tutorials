/**
* MIT License
*
* Copyright(c) 2021 Abhijit Mahalle
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
* @file ros_publisher.hpp
* @author Abhijit Mahalle
* @brief Class to publish message 
* @version 0.1
* @date 2021-11-01
* 
* @copyright Copyright (c) 2021
* 
*/

#ifndef SRC_BEGINNER_TUTORIALS_INCLUDE_ROS_PUBLISHER_HPP_ //  NOLINT-CPP
#define SRC_BEGINNER_TUTORIALS_INCLUDE_ROS_PUBLISHER_HPP_ //  NOLINT-CPP

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <string>
#include <memory>

#include <beginner_tutorials/tfbroadcaster.hpp>

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

  std::string call_service(int num1, int num2);

 private:
  /**
  * Method that is the main access point in the ROS node.
  */
  ros::NodeHandle ros_node_h;
  ros::Publisher chatter_pub;
  ros::ServiceClient add_svc_client;

  /**
   * Pointer to the ROSTfBroadcaster object to broadcast poses
   * 
   */
  std::shared_ptr<TfBroadcaster> tf_broadcast;

  /**
   * @brief Method to broadcast a static frame transform
   * 
   */
  void broadcast_transformation();
};

#endif  // SRC_BEGINNER_TUTORIALS_INCLUDE_ROS_PUBLISHER_HPP_//  NOLINT-CPP
