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
* @file ros_publisher.cpp
* @author Abhijit Mahalle (abhimah@umd.edu)
* @brief Definitions of the methods of ROSPublisher class
* @version 0.1
* @date 2021-11-01
* @copyright Copyright(c) 2021
* 
*/

#include <beginner_tutorials/ros_publisher.hpp>
#include <beginner_tutorials/AddTwoInts.h>
#include <beginner_tutorials/position.hpp>

ROSPublisher::ROSPublisher(ros::NodeHandle ros_node_h) {
  this->ros_node_h = ros_node_h;
  this->chatter_pub = this->ros_node_h.advertise<std_msgs::String>(
  "chatter", 1000);
  this->add_svc_client = this->ros_node_h.serviceClient<
                        beginner_tutorials::AddTwoInts>("add_two_ints");
}
std::string ROSPublisher::call_service(int num1, int num2) {
  std::string publisher_msg = "Hello. The sum from the service is:: ";

  beginner_tutorials::AddTwoInts srv;
  srv.request.a = num1;
  srv.request.b = num2;
  ROS_DEBUG_STREAM("Calling the service..");
  if (this->add_svc_client.call(srv)) {
    ROS_DEBUG_STREAM("Response for adding the numbers:: " << srv.response.sum);
    publisher_msg = publisher_msg + std::to_string(srv.response.sum);
  } else {
    ROS_ERROR_STREAM("Failed to call service add_two_ints");
    publisher_msg = publisher_msg + "ERROR";
  }
  return publisher_msg;
}

void ROSPublisher::run_publisher() {
  ros::Rate loop_rate(10);
  int count = 0;
  int prime = 5;
  TfBroadcaster tf_broadcaster;

  while (ros::ok()) {
    std_msgs::String msg;

    std::stringstream ss;
    int num1 = static_cast<int>(count / prime);
    int num2 = static_cast<int>(count % prime);
    ss << "I am talking:: " << this->call_service(num1, num2);
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    this->chatter_pub.publish(msg);

    Position pos(1, 2, 3, 1.54, 1.54, 1.54);
    tf_broadcaster.broadcast(pos, "world", "talk");

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
}

ROSPublisher::~ROSPublisher() {
}
