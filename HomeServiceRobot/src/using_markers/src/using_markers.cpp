// %Tag(INCLUDES)%
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "tf/tf.h"
#include "nav_msgs/Odometry.h"
#include <math.h>
// %EndTag(INCLUDES)%

// %Tag(INIT)%
int main( int argc, char** argv )
{
  ros::init(argc, argv, "using_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
// %EndTag(INIT)%

// Set our initial shape type to be a cube
// %Tag(SHAPE_INIT)%
uint32_t shape = visualization_msgs::Marker::CUBE;
// %EndTag(SHAPE_INIT)%
  float target[2][3] = {{4,4,0.70707},
                        {-4,-4,-1.57079}
                        }; 
// %Tag(MARKER_INIT)%

  visualization_msgs::Marker marker;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();
// %EndTag(MARKER_INIT)%

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
// %Tag(NS_ID)%
  marker.ns = "using_markers";
  marker.id = 0;
// %EndTag(NS_ID)%

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
// %Tag(TYPE)%
  marker.type = shape;
// %EndTag(TYPE)%

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
// %Tag(ACTION)%
  marker.action = visualization_msgs::Marker::ADD;
// %EndTag(ACTION)%

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
// %Tag(POSE)%
  // int idx = 0;
  // marker.pose.position.x = target[idx][0];
  // marker.pose.position.y = target[idx][1];
  // marker.pose.position.z = 0.2;
  // marker.pose.orientation= tf::createQuaternionMsgFromYaw(target[idx][2]);
// %EndTag(POSE)%

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
// %Tag(SCALE)%
  marker.scale.x = 0.2;
  marker.scale.y = 0.2;
  marker.scale.z = 0.2;
// %EndTag(SCALE)%

  // Set the color -- be sure to set alpha to something non-zero!
// %Tag(COLOR)%
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;
// %EndTag(COLOR)%

// %Tag(LIFETIME)%
  marker.lifetime = ros::Duration();
// %EndTag(LIFETIME)%
/*
Publish the marker at the pickup zone
Pause 5 seconds
Hide the marker
Pause 5 seconds
Publish the marker at the drop off zone
*/
int idx = 0;
// int num_points = 2;
marker.action = visualization_msgs::Marker::ADD;
marker.pose.position.x = target[idx][0];
marker.pose.position.y = target[idx][1];
marker.pose.position.z = 0.2;
marker.pose.orientation= tf::createQuaternionMsgFromYaw(target[idx][2]); 
ROS_INFO("PICKUP!");
marker_pub.publish(marker);// Publish the marker
ros::Duration(5.0).sleep();
marker.action = visualization_msgs::Marker::DELETE;
marker_pub.publish(marker);// Publish the marker
ros::Duration(5.0).sleep();
marker.action = visualization_msgs::Marker::ADD;
idx++;
marker.pose.position.x = target[idx][0];
marker.pose.position.y = target[idx][1];
marker.pose.position.z = 0.2;
marker.pose.orientation= tf::createQuaternionMsgFromYaw(target[idx][2]); 
ROS_INFO("DROPOFF!");
marker_pub.publish(marker);// Publish the marker

// while (ros::ok() && idx < num_points){
//     ROS_INFO("LOOPING!");
//   marker.pose.position.x = target[idx][0];
//   marker.pose.position.y = target[idx][1];
//   marker.pose.position.z = 0.2;
//   marker.pose.orientation= tf::createQuaternionMsgFromYaw(target[idx][2]); 
//   if(idx%2 == 0){
//     marker.action = visualization_msgs::Marker::ADD;
//     idx++;
//   }
//   else
//     marker.action = visualization_msgs::Marker::DELETE;
  
//   marker_pub.publish(marker);// Publish the marker
//   ros::Duration(5.0).sleep();
// // %Tag(SLEEP_END)%
//     r.sleep();
//   }
// %EndTag(SLEEP_END)%
}
// %EndTag(FULLTEXT)%
