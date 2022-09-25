#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;

    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;
    client.call(srv);
    //if (!client.call(srv))
    //{ROS_ERROR("Failed to call service command_robot");}
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int ball = 255;
    int i = 0;
    int intensity = 0; // measure of how close you are to the ball 
    int location = 0; // image quadrant for \dot{theta} computation
    float direction = 0;
    
    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    for(i = 0; i < img.data.size(); i = i + 1)
    {
    	if(img.data[i] == ball)
    	{
    		intensity++;
    		//location += (int) (img.data.size() % i / (0.01 * img.width)); // size % index / (0.01*width)
    		location += (int) (i % img.width / (0.01 * img.width));
    	}	
    }
    // Request a stop when there's no white ball seen by the camera
    if(intensity == 0)
            drive_robot(0, 0);
    else
    {
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
	    /*
	    float v=0, w=0;
	    w = 0.01 * location / img.data.size();
	    w = - 1.0 * (w - 0.5);
	    v = 100.0 * intensity / (img.data.size());
	    drive_robot(v, w);
	    */
	    direction = 0.01*location/intensity;
	    if(direction<.3){
		drive_robot(0.025, 0.5);}
	    else if(direction>.7){
		drive_robot(0.025, -0.5);}
	    else{
		drive_robot(0.1, 0.0);}
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
