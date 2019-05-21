#include <ros/ros.h>
#include "hw04/First_srv.h"

int main ( int argc, char** argv ) 
{
	// Initialize the ROS system and become a node .
	ros::init ( argc, argv, "client_service" ) ;
	ros::NodeHandle n ;
	
    // Create a subscriber 
    ros::ServiceClient client = n.serviceClient<hw04::First_srv>("pow");
    hw04::First_srv srv;
    srv.request.val = atoll(argv[1]);
    client.call(srv);
}
