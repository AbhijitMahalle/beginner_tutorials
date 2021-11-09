/**
 * @file ros_publisher.cpp
 * @author Abhijit Mahalle
 * @brief Definitions of the methods of ROSPublisher class
 * @version 0.1
 * @date 2021-11-01
 * @copyright Copyright (c) 2021
 * 
 */

#include <beginner_tutorials/ros_publisher.hpp>
#include <beginner_tutorials/AddTwoInts.h>

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
  while (ros::ok()) {
    std_msgs::String msg;

    std::stringstream ss;
    int num1 = static_cast<int>(count / prime);
    int num2 = static_cast<int>(count % prime);
    ss << "I am talking:: " << this->call_service(num1, num2);
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    this->chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
}

ROSPublisher::~ROSPublisher() {
}
