// This program publishes randomly−generated velocity
// messages for turtlesim .
#include <ros/ros.h>
#include <hw04/turtle_cmd.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist
#include <stdlib.h> // For rand() and RAND_MAX
#include <std_srvs/Empty.h>
int main ( int argc, char** argv ) 
{
	// Initialize the ROS system and become a node .
	ros::init ( argc, argv, "random_run_msg" ) ;
	ros::NodeHandle nh;
	
	// Create a publisher obj ect .
	ros::Publisher pub = nh.advertise <geometry_msgs::Twist >("turtle1/cmd_vel", 1000) ;
	
	// Seed the random number generator .
	srand (time(0));

	//ros::service::waitForService("clear");
	//int freq1;
	//system("rosparam load /home/p/0325_ws/src/test_config/config/data2.yaml");
	//nh.getParam("freq", freq1);
	// nh.setParam("freq", freq1);
	
	// Loop at 2Hz until the node is shut down.
	ros::Rate loop_rate(2);
	while ( ros::ok () ) 
	{
		// Create and fill in the message . The other four
		// fields , which are ignored by turtl esim , default to 0.
		geometry_msgs::Twist msg ;
		hw04::turtle_cmd msg1;
		msg1.x = double ( rand()) / double(RAND_MAX);
		msg1.z = 2 * double ( rand() )/double(RAND_MAX)-1 ;

		msg.linear.x = msg1.x;
		msg.angular.z = msg1.z;

		// Publish the message .
		pub.publish ( msg ) ;

		// Send a message to rosout with the details .
		ROS_INFO_STREAM( "Sending random velocity command : "
		<< " linear=" << msg1.x
		<< " angular=" << msg1.z) ;

		// Wait untilit's time for another iteration .
		loop_rate.sleep();
	}
}