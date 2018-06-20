// /**
//  * @file offb_node.cpp
//  * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
//  * Stack and tested in Gazebo SITLg
//  */

// #include <ros/ros.h>
// #include <geometry_msgs/PoseStamped.h>
// #include <geometry_msgs/TwistStamped.h>
// #include <mavros_msgs/CommandBool.h>
// #include <mavros_msgs/SetMode.h>
// #include <mavros_msgs/State.h>
// #include <std_msgs/Float32MultiArray.h>
// #include "std_msgs/MultiArrayLayout.h"
// #include "std_msgs/MultiArrayDimension.h"

// mavros_msgs::State current_state;
// //std_msgs::Float32MultiArray t_vec;

// void state_cb(const mavros_msgs::State::ConstPtr& msg){
//     current_state = *msg;
// }

// // void t_callback(const std_msgs::Float32MultiArray::ConstPtr& arr_msg) {
// //     float x_err = (arr_msg->data)[0];
// //     if (x_err > 0) {
// //        // msg_vel.twist.linear.x = 0.3;
// //     }
// // }

// int main(int argc, char **argv)
// {
//     ros::init(argc, argv, "offb_node");
//     ros::NodeHandle nh;

//     ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
//             ("mavros/state", 10, state_cb);
//     ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
//             ("mavros/setpoint_position/local", 10);
//     ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
//             ("mavros/cmd/arming");
//     ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
//             ("mavros/set_mode");

//     //ros::Subscriber t_sub = nh.subscribe<std_msgs::Float32MultiArray>("array", 10, t_callback);
//     //ros::Publisher vel_pub = nh.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_attitude/cmd_vel",100);

//     //the setpoint publishing rate MUST be faster than 2Hz
//     ros::Rate rate(20.0);

//     // wait for FCU connection
//     while(ros::ok() && !current_state.connected){
//         ros::spinOnce();
//         rate.sleep();
//     }

//     geometry_msgs::PoseStamped pose;
//     pose.pose.position.x = 0;
//     pose.pose.position.y = 0;
//     pose.pose.position.z = 2;

//     //send a few setpoints before starting
//     for(int i = 100; ros::ok() && i > 0; --i){
//         local_pos_pub.publish(pose);
//         ros::spinOnce();
//         rate.sleep();
//     }

//     geometry_msgs::TwistStamped msg_vel;

//     mavros_msgs::SetMode offb_set_mode;
//     offb_set_mode.request.custom_mode = "OFFBOARD";

//     mavros_msgs::CommandBool arm_cmd;
//     arm_cmd.request.value = true;

//     ros::Time last_request = ros::Time::now();

//     while(ros::ok()){
//         if( current_state.mode != "OFFBOARD" &&
//             (ros::Time::now() - last_request > ros::Duration(5.0))){
//             if( set_mode_client.call(offb_set_mode) &&
//                 offb_set_mode.response.mode_sent){
//                 ROS_INFO("Offboard enabled");
//             }
//             last_request = ros::Time::now();
//         } else {
//             if( !current_state.armed &&
//                 (ros::Time::now() - last_request > ros::Duration(5.0))){
//                 if( arming_client.call(arm_cmd) &&
//                     arm_cmd.response.success){
//                     ROS_INFO("Vehicle armed");
//                 }
//                 last_request = ros::Time::now();
//             }
//         }

//         local_pos_pub.publish(pose);
//         //vel_pub.publish(msg_vel);

//         ros::spinOnce();
//         rate.sleep();
//     }

//     return 0;
// }

/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

// #include <ros/ros.h>
// #include <geometry_msgs/PoseStamped.h>
// #include <geometry_msgs/TwistStamped.h>
// #include <mavros_msgs/CommandBool.h>
// #include <mavros_msgs/SetMode.h>
// #include <mavros_msgs/State.h>
// #include <std_msgs/Float32MultiArray.h>
// #include "std_msgs/MultiArrayLayout.h"
// #include "std_msgs/MultiArrayDimension.h"
// #include <std_msgs/Float32.h>

// mavros_msgs::State current_state;
// void state_cb(const mavros_msgs::State::ConstPtr& msg){
//     current_state = *msg;
// }

// int main(int argc, char **argv)
// {
//     ros::init(argc, argv, "offb_node");
//     ros::NodeHandle nh;

//     ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
//             ("mavros/state", 10, state_cb);
//     ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
//             ("mavros/setpoint_position/local", 10);
//     ros::Publisher alt_pub = nh.advertise<std_msgs::Float32>("mavros/altitude", 10);
//     ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
//             ("mavros/cmd/arming");
//     ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
//             ("mavros/set_mode");

//     //the setpoint publishing rate MUST be faster than 2Hz
//     ros::Rate rate(20.0);

//     // wait for FCU connection
//     while(ros::ok() && !current_state.connected){
//         ros::spinOnce();
//         rate.sleep();
//     }

//     geometry_msgs::PoseStamped pose;
//     //pose.pose.position.x = 0;
//     //pose.pose.position.y = 0;
//     pose.pose.position.z = 3.5;

//     std_msgs::Float32 alt_msg;
//     alt_msg.data = 3.50;

//     //send a few setpoints before starting
//     for(int i = 100; ros::ok() && i > 0; --i){
//         local_pos_pub.publish(pose);
//         //alt_pub.publish(alt_msg);
//         ros::spinOnce();
//         rate.sleep();
//     }

//     mavros_msgs::SetMode offb_set_mode;
//     offb_set_mode.request.custom_mode = "OFFBOARD";

//     mavros_msgs::CommandBool arm_cmd;
//     arm_cmd.request.value = true;

//     ros::Time last_request = ros::Time::now();

//     while(ros::ok()){
//         if( current_state.mode != "OFFBOARD" &&
//             (ros::Time::now() - last_request > ros::Duration(5.0))){
//             if( set_mode_client.call(offb_set_mode) &&
//                 offb_set_mode.response.mode_sent){
//                 ROS_INFO("Offboard enabled");
//             }
//             last_request = ros::Time::now();
//         } else {
//             if( !current_state.armed &&
//                 (ros::Time::now() - last_request > ros::Duration(5.0))){
//                 if( arming_client.call(arm_cmd) &&
//                     arm_cmd.response.success){
//                     ROS_INFO("Vehicle armed");
//                 }
//                 last_request = ros::Time::now();
//             }
//         }

//         alt_pub.publish(alt_msg);

//         ros::spinOnce();
//         rate.sleep();
//     }

//     return 0;
// }

#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"

using namespace std;

geometry_msgs::TwistStamped vel_msg;

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

// Callback to tvec array from ARUCO marker
void ar_callback(const std_msgs::Float32MultiArray::ConstPtr& array) {
    if (array->data.size() != 0) {  // Check if any marker detected.
        if ((array->data)[0] > 0) {
            vel_msg.twist.linear.x = -1;  // Rudimentary x,y control system.
        } else if (array->data[0] < 0) {
            vel_msg.twist.linear.x = 1;
        }
        if ((array->data)[1] > 0) {
            vel_msg.twist.linear.y = -1;
        } else if (array->data[1] < 0) {
            vel_msg.twist.linear.y = 1;
        }
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/cmd_vel", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");
    ros::Subscriber arr_sub = nh.subscribe<std_msgs::Float32MultiArray>("array", 1, ar_callback);

    //the setpoint publishing rate MUST be faster than 2Hz to not drop out of OFFBOARD mode.
    ros::Rate rate(20.0);

    vel_msg.twist.linear.x = 0;  // Set all initial velocities to zero.
    vel_msg.twist.linear.y = 0;
    vel_msg.twist.linear.z = 0;

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 1.8;

    std_msgs::Float32 alt_msg;
    alt_msg.data = 3.5;

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){
        if( current_state.mode != "OFFBOARD" && (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
            //continue;
        } else {
            if( !current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                
                last_request = ros::Time::now();
            }
            //continue;
            }
          }
        //if (current_state.armed && ros::Time::now() - last_request < ros::Duration(15.0)) {
        if ((ros::Time::now() - last_request < ros::Duration(10))) {
            local_pos_pub.publish(pose);
            cout << ros::Time::now() - last_request << "\n";
        } else {
            vel_pub.publish(vel_msg);
            // Reset vel_msg to null.
            vel_msg.twist.linear.x = 0;
            vel_msg.twist.linear.y = 0;
            vel_msg.twist.linear.z = 0;
        }
        //    local_pos_pub.publish(pose);
        
        
        //} else {
          //  vel_pub.publish(vel_msg);  // After 5 seconds, switch to publish velocity message.
        //}
       // local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}