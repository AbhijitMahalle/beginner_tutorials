/**
* MIT License
*
* Copyright (c) 2021 Abhijit Mahalle
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
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
* @file ros_publisher.test
* @author Abhijit Mahalle (abhimah@umd.edu)
* @brief Test for ros_publisher
* @version 0.1
* @date 2021-11-15
* 
* @copyright Copyright (c) 2021
* 
*/

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_listener.h>
#include <gtest/gtest.h>
#include <memory>

#include <beginner_tutorials/ros_publisher.hpp>
#include <beginner_tutorials/ros_subscriber.hpp>



TEST(TestPublisher, test_publish_msg) {
    ros::NodeHandle n;
    ROSSubscriber ros_sub(n);

    ros::Subscriber sub = n.subscribe("chatter", 1000,
                                        &ROSSubscriber::chatter_call_back,
                                        &ros_sub);
    ros::WallDuration(1.0).sleep();
    ros::spinOnce();

    std::string message = ros_sub.get_message();
    std::string expected_string = "I am talking";

    EXPECT_TRUE(message.find(expected_string) != std::string::npos);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "talker_test");
  testing::InitGoogleTest(&argc, argv);

  auto res = RUN_ALL_TESTS();

  ros::shutdown();
  return res;
}
