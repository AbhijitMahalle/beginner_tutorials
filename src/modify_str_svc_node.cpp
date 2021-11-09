/**
 * @file ros_publisher.cpp
 * @author Abhijit Mahalle
 * @brief Class for addTwoNums.cpp
 * @version 0.1
 * @date 2021-11-01
 * @copyright Copyright (c) 2021
 * 
 */

#include <ros/ros.h>
#include <beginner_tutorials/AddTwoInts.h>

bool add(beginner_tutorials::AddTwoInts::Request &req,  // NOLINT-CPP
         beginner_tutorials::AddTwoInts::Response &res) {  // NOLINT-CPP
    res.sum = req.a + req.b;
    ROS_INFO_STREAM("request: num1="
                    << req.a
                    << "num2="
                    << req.b);
    ROS_INFO_STREAM("sending back response: " << res.sum);
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}
