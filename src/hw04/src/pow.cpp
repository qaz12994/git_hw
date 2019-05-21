#include <ros/ros.h>
#include "hw04/First_srv.h"

int cal_pow(int number)
{
    return number*number;
}

bool service_request(hw04::First_srv::Request &req, hw04::First_srv::Response &res)
{
    ROS_INFO("Request Num = %d",req.val);
    res.ans = cal_pow(req.val);
    ROS_INFO("Response: %d is pow ",res.ans);
    return true;
}

int main ( int argc, char** argv ) 
{
	// Initialize the ROS system and become a node .
	ros::init ( argc, argv, "pow_service" ) ;
	ros::NodeHandle n ;
	
    // Create a subscriber 
    ros::ServiceServer service = n.advertiseService("pow",service_request);
    ros::spin();
}


